import os
import sys
import argparse
import uproot
import awkward as ak
import numpy as np
from pathlib import Path

tree_path = "events"
output_dir = "weighted"
noDecay = False

BR = {}
BR['h'] = {"bb": 0.5792, "tautau": 0.0624, "yy": 0.00227}
BR['Z'] = {"tautau": 0.033696, "bb": 0.1512}
BR['W'] = {"taunu": 0.1138}

# k-factors the same for all
kFactors = {
    "mgp8_pp_tth_5f_84TeV": 1.45,
    "mgp8_pp_ttbb_4f_84TeV": 1.41,
    "mgp8_pp_ttz_5f_84TeV": 1.52,
    "mgp8_pp_zzz_5f_84TeV": 1.70,
    "mgp8_pp_tttt_5f_84TeV": 2.10,
    "mgp8_pp_hhh_84TeV": 2.25,
    "pwp8_pp_hh_k3_1_k4_1_84TeV": 1 # is an NLO sample, kl-dependent K-factors are already applied
}
    
    
# === Cross sections and per-process BRs/k-factors ===
if noDecay:
    print("********* Running with noDecay option enabled *********")
    cross_sections = {
        "mgp8_pp_ttbb_4f_84TeV": 155.77,
        "mgp8_pp_tth_5f_84TeV": 17.5041,
        "mgp8_pp_ttz_5f_84TeV": 28.15,
        "mgp8_pp_tttt_5f_84TeV": 1.57,
        "mgp8_pp_zzz_5f_84TeV": 0.151,
        "mgp8_pp_hhh_84TeV": 0.00156,   # inclusive pb at 84 TeV (LO)
    }
    # In noDecay mode, treat all final states as 100%
    BFs = {key: 1.0 for key in cross_sections}
    BFs["mgp8_pp_hhh_84TeV"] = 3 * BR['h']['bb']**2 * BR['h']['tautau']
    
else:
    cross_sections = {
        "mgp8_pp_ttbb_4f_84TeV": 155.77,
        "mgp8_pp_tth_5f_84TeV": 17.5041,
        "mgp8_pp_ttz_5f_84TeV": 28.15,
        "mgp8_pp_tttt_5f_84TeV": 1.57,
        "mgp8_pp_zzz_5f_84TeV": 0.151,
        "mgp8_pp_hhh_84TeV": 0.00156,   # inclusive pb at 84 TeV (LO),
        "pwp8_pp_hh_k3_1_k4_1_84TeV": 0.885
    }
    
    # Build per-process BRs from particle-level BR map
    BFs = {
        "mgp8_pp_tth_5f_84TeV": (BR['h']['bb'] + BR['h']['tautau']) * BR['W']['taunu']**2,
        "mgp8_pp_ttbb_4f_84TeV": BR['W']['taunu']**2,  # Current Pythia card forces both W -> tau nu.
        "mgp8_pp_ttz_5f_84TeV": BR['W']['taunu']**2 * (BR['Z']['bb'] + BR['Z']['tautau']),
        "mgp8_pp_zzz_5f_84TeV": (BR['Z']['bb'] + BR['Z']['tautau'])**3,
        "mgp8_pp_tttt_5f_84TeV": 1,
        "mgp8_pp_hhh_84TeV": 3 * BR['h']['bb']**2 * BR['h']['tautau'],
        "pwp8_pp_hh_k3_1_k4_1_84TeV": 4 * BR['h']['bb'] * BR['h']['tautau']

    }


SIGNAL_KEY = "mgp8_pp_hhh_84TeV"

def process_file(input_path, output_base, output_directory=None):
    try:
        file_key = Path(input_path).stem
        if (file_key not in cross_sections) or (file_key not in BFs) or (file_key not in kFactors):
            raise ValueError(f"{file_key}: missing cross section, BF or k-factor")
        outdir = Path(output_directory) if output_directory is not None else Path(output_base) / output_dir
        output_path = outdir / f"{file_key}.root"
        if output_path.exists():
            raise FileExistsError(output_path)
        with uproot.open(input_path, handler=uproot.source.file.MemmapSource) as infile:
            if tree_path not in infile:
                raise ValueError(f"Tree '{tree_path}' not found in {input_path}")

            tree = infile[tree_path]

            # avoid non-flat, funky variables
            available = tree.keys(filter_name="*")
            wanted = [b for b in available]  # keep simple ones
            branches = tree.arrays(wanted, library="ak")
            for name in branches.fields:
                if name == "weight" or name.startswith("weight_k3"):
                    values = ak.to_numpy(branches[name])
                    if values.ndim != 1 or not np.isfinite(values).all():
                        raise ValueError(f"{file_key}: expected finite scalar values in {name}")

            file_key = Path(input_path).stem
            if (file_key not in cross_sections) or (file_key not in BFs) or (file_key not in kFactors):
                print(f" File '{file_key}' missing in xsec/BF/k-factor dicts, skipping.")
                return

            if hasattr(tree, "num_entries"):
                total_events = int(tree.num_entries)
            else:
                if not branches.fields:
                    print(f"No branches found in {file_key}, skipping.")
                    return
                total_events = len(branches[branches.fields[0]])
            
            if total_events == 0:
                raise ValueError(f"No events found in {file_key}")

            doForNow = False
            if file_key == SIGNAL_KEY or doForNow:
                w_base = np.ones(total_events, dtype=np.float64)
            else:
                if "weight" in branches.fields:
                    print("using weight from file")
                    w_base = branches["weight"]
                else:
                    raise ValueError(f"{file_key}: missing generator weight branch")

            w_base = np.asarray(ak.to_numpy(w_base), dtype=np.float64)
            if w_base.shape != (total_events,) or not np.isfinite(w_base).all():
                raise ValueError(f"{file_key}: expected one finite weight per event")

            # Per-event normalisation
            if file_key == SIGNAL_KEY or doForNow:
                # signal uses cross-section * BR * k, distributed over N events
                norm = (cross_sections[file_key] * BFs[file_key] * kFactors[file_key]) / total_events
                kind = "Signal weighting"
            else:
                # backgrounds keep previous convention: (BF * k / N) multiplied by existing generator weight
                norm = (BFs[file_key] * kFactors[file_key]) / total_events
                kind = "Background weighting"

            # Final xsec-like weight
            branches["weight_xsec"] = w_base * norm
            if not np.isfinite(ak.to_numpy(branches["weight_xsec"])).all():
                raise ValueError(f"{file_key}: non-finite weight_xsec")

            sigma_incl = cross_sections[file_key]
            sigma_eff = sigma_incl * BFs[file_key] * kFactors[file_key]  # effective cross section (pb)
            print(
                f"  [{kind}] {file_key}: "
                f"events={total_events:,}, xsec_incl={sigma_incl:.6g} pb, "
                f"BF={BFs[file_key]:.6g}, k={kFactors[file_key]:.3f}, "
                f"xsec_eff={sigma_eff:.6g} pb, norm={norm:.3e}"
            )

            # Write out
            os.makedirs(outdir, exist_ok=True)
            with uproot.recreate(output_path) as outfile:
                # Explicit TTree output works with the ROOT analysis and fitting tools.
                arrays = {name: branches[name] for name in branches.fields}
                tree_out = outfile.mktree(tree_path, {
                    name: ak.type(values).content for name, values in arrays.items()
                })
                tree_out.extend(arrays)

            print(f"Wrote weighted file: {output_path}")
            print(f"  Sum weight_xsec = {float(ak.sum(branches['weight_xsec'])):.12g} pb")

    except Exception as e:
        raise RuntimeError(f"Error processing {input_path}: {e}") from e

# === Entry Point ===
def main():
    parser = argparse.ArgumentParser(description="Add the previous analysis cross-section weights to merged, unselected ntuples.")
    parser.add_argument("input_directory", type=Path, help="Flat directory of <process>.root files")
    parser.add_argument("--output-dir", type=Path, help="Output directory (default: INPUT/weighted)")
    parser.add_argument("--processes", nargs="+", choices=sorted(cross_sections), help="Weight only these processes")
    args = parser.parse_args()
    input_dir = args.input_directory
    output_base = input_dir

    if not input_dir.is_dir():
        print(f"Input path {input_dir} is not a directory.")
        sys.exit(1)

    root_files = ([input_dir / f"{process}.root" for process in args.processes]
                  if args.processes else sorted(input_dir.glob("*.root")))
    if not root_files:
        print(f"No .root files found in {input_dir}")
        sys.exit(1)
    for input_file in root_files:
        if not input_file.is_file():
            parser.error(f"Missing input: {input_file}")
        if input_file.stem not in cross_sections:
            parser.error(f"Unknown process: {input_file.stem}")
        output_path = (args.output_dir or input_dir / output_dir) / input_file.name
        if output_path.exists():
            parser.error(f"Output already exists: {output_path}")

    print(f"Processing {len(root_files)} ROOT files from: {input_dir}")

    for input_file in root_files:
        process_file(input_file, output_base, args.output_dir)

if __name__ == "__main__":
    main()
