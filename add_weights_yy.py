#!/usr/bin/env python3
"""Add signed cross-section weights (pb/event) to merged HH -> bb gamma gamma ntuples."""
import argparse
from pathlib import Path

import awkward as ak
import numpy as np
import uproot

TREE = 'events'
BR_BB = 0.5792
BR_YY = 0.00227

# HH: each Higgs was generated with 50% bb / 50% gamma gamma, WITHOUT a
# bb gamma gamma filter. P_generated(bb gamma gamma) = 2 * 0.5 * 0.5 = 0.5.
# Correct that component by P_physical / P_generated = 4 * BR_BB * BR_YY.
# Single-H samples force H -> gamma gamma; prompt gamma gamma needs no BR.
DECAY_FACTORS = {
    'pwp8_pp_hh_k3_1_k4_1_84TeV': 4 * BR_BB * BR_YY,
    'mgp8_pp_jjaa_5f_84TeV': 1.,
    'mgp8_pp_h012j_5f_84TeV': BR_YY,
    'mgp8_pp_tth01j_5f_84TeV': BR_YY,
    'mgp8_pp_vbf_h01j_5f_84TeV': BR_YY,
}
# Additional corrections only; the HH sample is already NLO.
K_FACTORS = {process: 1. for process in DECAY_FACTORS}


def generator_weights(array):
    """Return one nominal weight per event, retaining its sign and magnitude."""
    if array.layout.purelist_depth > 1:
        if not ak.all(ak.num(array, axis=1) == 1):
            raise ValueError('weight must contain exactly one nominal weight per event')
        array = ak.firsts(array)
    if ak.any(ak.is_none(array)):
        raise ValueError('missing generator weight')
    weights = np.asarray(ak.to_numpy(array), dtype=np.float64)
    if weights.ndim != 1 or not np.isfinite(weights).all():
        raise ValueError('expected one finite generator weight per event')
    return weights


def read_events_processed(rootfile):
    """Require the original preselection count, not the selected tree size."""
    if 'eventsProcessed' not in rootfile:
        raise ValueError('missing eventsProcessed; cannot normalise a selected ntuple')
    count = int(rootfile['eventsProcessed'].member('fVal'))
    if count <= 0:
        raise ValueError('eventsProcessed must be positive')
    return count


def cross_section_weights(weights, events_processed, decay_factor, k_factor=1.):
    """The stored generator weight already carries the cross section in pb."""
    if events_processed <= 0:
        raise ValueError('eventsProcessed must be positive')
    return generator_weights(weights) * decay_factor * k_factor / events_processed


def process_file(input_path, output_dir, hh_decays='mixed'):
    process = input_path.stem
    decay_factor = DECAY_FACTORS[process]
    if process == 'pwp8_pp_hh_k3_1_k4_1_84TeV' and hh_decays == 'filtered':
        # The resonance-decay hook produces bb gamma gamma for every hard event.
        decay_factor = 2 * BR_BB * BR_YY
    k_factor = K_FACTORS[process]
    output_path = output_dir / input_path.name
    if output_path.exists():
        raise FileExistsError(f'Output already exists: {output_path}')
    with uproot.open(input_path, handler=uproot.source.file.MemmapSource) as source:
        tree = source[TREE]
        processed = read_events_processed(source)
        if tree.num_entries > processed:
            raise ValueError('tree has more entries than eventsProcessed')
        # Define an explicit TTree, including for empty samples; keep all branches.
        empty = tree.arrays(entry_stop=0, library='ak')
        if 'weight' not in empty.fields:
            raise ValueError('missing nominal generator weight branch: weight')
        if 'weight_xsec' in empty.fields:
            raise ValueError('input already contains weight_xsec')
        branch_types = {name: ak.type(empty[name]).content for name in empty.fields}
        branch_types['weight_xsec'] = np.dtype('float64')
        output_dir.mkdir(parents=True, exist_ok=True)
        sum_weight = 0.
        negatives = 0
        with uproot.create(output_path) as output:
            result = output.mktree(TREE, branch_types)
            # Copy the original file-level metadata, including TParameters.
            output.copy_from(source, filter_name=lambda name: name != TREE, require_matches=False)
            for arrays in tree.iterate(step_size='100 MB', library='ak'):
                weighted = cross_section_weights(arrays['weight'], processed, decay_factor, k_factor)
                columns = {name: arrays[name] for name in arrays.fields}
                columns['weight_xsec'] = weighted
                result.extend(columns)
                sum_weight += float(weighted.sum())
                negatives += int((weighted < 0).sum())
        print(f'{process}: {tree.num_entries:,} entries / {processed:,} processed; '
              f'decay correction={decay_factor:g}, k={k_factor:g}; '
              f'{negatives:,} negative weights; sum(weight_xsec)={sum_weight:.9g} pb')
    print(f'Wrote {output_path}')
    return output_path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('input_directory', type=Path, help='Merged <process>.root files from the bb gamma gamma analysis')
    parser.add_argument('--output-dir', type=Path, help='Default: INPUT/weighted_yy')
    parser.add_argument('--processes', nargs='+', choices=sorted(DECAY_FACTORS), help='Only process these samples')
    parser.add_argument('--hh-decays', choices=['mixed', 'filtered'], default='mixed',
                        help='HH generation: old 50/50 unfiltered decays (default), or forced bb gamma gamma')
    args = parser.parse_args()
    if not args.input_directory.is_dir():
        parser.error('input directory does not exist')
    files = ([args.input_directory / f'{p}.root' for p in args.processes] if args.processes
             else sorted(args.input_directory.glob('*.root')))
    if not files:
        parser.error('no ROOT files found')
    output_dir = args.output_dir or args.input_directory / 'weighted_yy'
    for path in files:
        if path.stem not in DECAY_FACTORS:
            parser.error(f'Unknown process: {path.stem}; add its decay convention to DECAY_FACTORS first')
        if not path.is_file():
            parser.error(f'Missing input: {path}')
        if (output_dir / path.name).exists():
            parser.error(f'Output already exists: {output_dir / path.name}')
    for path in files:
        process_file(path, output_dir, args.hh_decays)


if __name__ == '__main__':
    main()
