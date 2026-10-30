For the HHH analysis, please use the ntuple code found within this folder.

---

### Setting up the code
All a new user needs to do is source the scratch setup script provided, `source scratch_setup.sh`, which sources the relevant key4hep release and then compiles the ntuple code.

### A first test

To run a test job of 10000 events, run `fccanalysis run hhh_ntuples.py --test`, which runs a test job on the file configured within the ntuple code <insert link here>.

A set of plots has been included within `test/`, which can be reproduced by running `python test_HHH.py`.

This takes your 10000 event test and produces a plot dump of all variables within the code with a loose object preselection of 4b 1taulep / 1tauhad (lep-had) and 4b 2tauhad (had-had).

---

### Grid submission

Once you're happy that the code is replicating the tests, we can start submitting jobs to the grid.

These are run similarly to before, but replacing `run` by `submit`:
`fccanalysis submit HHH_ntuples.py`.

These jobs are configured within the ntuple code itself, with hard-coded input directory paths (should be a common dir for all of your EventProducer jobs) and destinations for the final ntuples to be stored.

At this stage, no event preselection is applied.
However, to save runtime the loosest object preselection is applied prior to running expensive elements of the ntuple production (mostly within MMC), so a few variables will be null prior to applying such a preselection.