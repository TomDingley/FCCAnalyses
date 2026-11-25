# HH -> bb gamma gamma ntuples

This ports the external `hh/bbaa/bbaa.py` analysis into this checkout. It writes
**unselected events**, with the same object definitions and observables. Missing
objects give `NaN` for observables requiring them; no dummy kinematic values or
event cuts are applied. The original mass/multiplicity preselection is left for
downstream analysis.

## Build and test

From the main repository root:

```bash
source EventProducer/init.sh
source FCCAnalyses/setup.sh
fccanalysis build -j 4
fccanalysis run FCCAnalyses/hh/bbaa/bbaa.py \
  --input /path/to/reconstructed.root --output /path/to/test_ntuples.root \
  --nevents 1000
python3 tests/test_hh_bbaa.py
```

Use fresh output files. `--input` accepts an explicit reconstructed file, so no
local production-directory setting is needed for this small test. For `--test`,
pass `-- --input-dir /path/to/fcc_v07/II`; the first ROOT file of the selected
process supplies the test input.

## Native submission

```bash
fccanalysis submit FCCAnalyses/hh/bbaa/bbaa.py -- \
  --input-dir /path/to/fcc_v07/II \
  --processes pwp8_pp_hh_k3_1_k4_1_84TeV \
  --output-dir hh_bbaa_ntuples --chunks 308 --threads 2
```

The input directory contains a subdirectory of ROOT files for each process.
Choose `--chunks` for your available files/resources; 308 is only an example.
The default is one chunk for the SM HH process. Keep the output directory
relative when using the native submission tool. Other supported processes are
`mgp8_pp_jjaa_5f_84TeV`, `mgp8_pp_h012j_5f_84TeV`,
`mgp8_pp_vbf_h01j_5f_84TeV`, `mgp8_pp_tth01j_5f_84TeV`, and
`mgp8_pp_vh012j_5f_84TeV`. Only request processes actually available in your
input directory. No new HH event-generation workflow is added here.

## Physics conventions

- Jets, medium-WP b-jets and photons: pT > 30 GeV, |eta| < 4; electrons and
  muons: pT > 10 GeV, |eta| < 4. Collections are sorted by pT.
- The leading b-jet and photon pairs define the two Higgs candidates.
- Photon directions use the external truth-associated, event-seeded angular
  smearing. Photon energy, resolution coefficients and random-seed formula are
  retained. Unmatched photons retain their reconstructed values.
- Both corrected and uncorrected photon kinematics are saved, along with the
  bb/diphoton/HH masses, angular variables and photon-b-jet distances.
- `weight` retains the original generator-weight vector (normally one entry)
  and `event_number` retains the original event-number vector. No automatic
  cross-section or luminosity normalization is applied. No coupling-reweight
  mapping is invented: the original script does not define such outputs.

**Do not use the HHH `add_weights.py` convention for this channel.** Its HH
branching factor describes bbtautau, whereas this analysis needs bb gamma gamma
normalization. The same process name is used in both channels, so use separate
output directories. Use the dedicated `add_weights_yy.py` step below.

The port adds three HH angular helpers, `get_idx_clean`, and the missing
photon-smearing mode/subset overload. The existing four-argument smearing
constructor and three-argument call remain available.


## Cross-section weights for the existing bb gamma gamma production

From the main repository root, on a flat directory of merged `<process>.root`
ntuples:

```bash
python3 FCCAnalyses/add_weights_yy.py /path/to/merged_bbyy_ntuples
# Optional: --output-dir /path/to/weighted_bbyy --processes pwp8_pp_hh_k3_1_k4_1_84TeV
```

The default output directory is `INPUT/weighted_yy`. The script adds a scalar
`weight_xsec` branch in pb/event, keeps the original branches and copies the
file-level metadata. It explicitly writes a TTree, requires a positive original
`eventsProcessed`, and refuses to overwrite existing output. It also works with
selected ntuples provided `eventsProcessed` still counts the events before cuts.
An empty selected tree retains its metadata and an empty output tree.

The normalization is deliberately simple:

```
weight_xsec[i] = weight[i] * decay_factor * k_factor / eventsProcessed
```

`weight` can be a scalar or a one-element vector. Its signed magnitude is already
in the generator cross-section convention (pb); do not replace it by its mean,
its sign alone, or a configured constant cross section. The HH signal keeps all
negative weights; so do any NLO backgrounds. Multiplication by luminosity in
pb^-1 is left to the plotting/fitting analysis. The k-factors are explicit and
currently all 1; HH is already an NLO sample.

The production was inspected under
`/data/atlas/users/dingleyt/FCChh/eventProd/EventProducer`:

- `pythiacards/pw_pp_hh_k3_1_k4_1_84TeV_bbaa.cmd` assigns each Higgs a 50% bb and
  50% gamma gamma decay probability, with the other modes disabled. The standalone
  Delphes/Pythia event loop does not filter the resulting HH decay combination.
  A truth check of the first 1,000 reconstructed events in
  `ggHH_quartic_bbaa/fcc_v07/II/pwp8_pp_hh_k3_1_k4_1_84TeV/events_0001_0000.root`
  found 485 bb gamma gamma, 248 four-b and 267 four-gamma events.
- Thus this is inclusive HH production followed by an artificial decay mixture,
  not an exclusively forced bb gamma gamma sample. The generated bb gamma gamma
  fraction is 0.5, while its physical fraction is `2*BR_BB*BR_YY`. The correction
  for the bb gamma gamma component is therefore `4*BR_BB*BR_YY = 0.005259136`,
  using BR_BB=0.5792 and BR_YY=0.00227. The factor four is intentional.
- The raw ntuple nominal weight is set from Pythia's `info.weight()` by
  `key4/k4SimDelphes/standalone/src/DelphesPythia8Common.h`, then retained in
  `EventHeader.weight` by the converter. In the inspected raw HH file it is
  approximately +/-1.15394 pb; 1,122 of its 10,000 events have negative weights.
- The `mg_pp_h012j_5f_84TeV.cmd`, `mg_pp_tth01j_5f_84TeV.cmd` and
  `mg_pp_vbf_h01j_5f_84TeV.cmd` cards force H -> gamma gamma. Their correction is
  BR_YY. The prompt `mgp8_pp_jjaa_5f_84TeV` sample has no Higgs branching factor.

These decay factors describe this production and the bb gamma gamma analysis.
The script does not truth-filter away the other HH decay combinations; the
bb gamma gamma component must be isolated downstream. The sum over the entire
unselected artificial mixture is not the physical bb gamma gamma cross section.
An exclusively forced bb gamma gamma sample would instead require a factor
`2*BR_BB*BR_YY`; a sample whose stored weights already include the physical decay
probability must not receive that factor again. Other samples, including VH,
require their own production convention to be checked before adding them to the
small `DECAY_FACTORS` table.

Validation from the main repository root:

```bash
python3 -m unittest discover -s tests -p test_add_weights_yy.py
```
