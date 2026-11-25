"""Unselected FCC-hh HH -> bb gamma gamma ntuples, ported from the external analysis."""

from argparse import ArgumentParser
from pathlib import Path

# C++ expressions used for observables with missing input objects.
NAN = "std::numeric_limits<float>::quiet_NaN()"
NULL_TLV = f"TLorentzVector({NAN}, {NAN}, {NAN}, {NAN})"

PROCESSES = (
    "pwp8_pp_hh_k3_1_k4_1_84TeV",
    "mgp8_pp_jjaa_5f_84TeV",
    "mgp8_pp_h012j_5f_84TeV",
    "mgp8_pp_vbf_h01j_5f_84TeV",
    "mgp8_pp_tth01j_5f_84TeV",
    "mgp8_pp_vh012j_5f_84TeV",
)


class Analysis:
    """Build bb gamma gamma observables without selecting events."""

    def __init__(self, cmdline_args):
        parser = ArgumentParser(description=__doc__)
        parser.add_argument("--input-dir", type=Path,
                            default=Path(__file__).resolve().parents[3] /
                            "EventProducer/DelphesEvents/fcc_v07/II")
        parser.add_argument("--output-dir", default="hh_bbaa_ntuples")
        parser.add_argument("--processes", nargs="+", choices=PROCESSES,
                            default=[PROCESSES[0]])
        parser.add_argument("--threads", type=int, default=2)
        parser.add_argument("--chunks", type=int, default=1)
        remaining = [arg for arg in cmdline_args.get("remaining", []) if arg != "--"]
        args = parser.parse_args(remaining)
        if args.threads < 1 or args.chunks < 1:
            parser.error("--threads and --chunks must be positive")

        self.input_dir = str(args.input_dir.resolve())
        self.output_dir = args.output_dir
        self.process_list = {process: {"chunks": args.chunks} for process in args.processes}
        self.analysis_name = "FCC-hh HH -> bb gamma gamma, unselected ntuples"
        self.n_threads = args.threads
        self.run_batch = False
        self.comp_group = "dingleyt"
        # Retain the generator weight; no cross-section normalization is applied here.
        self.do_weighted = False
        self.use_data_source = False
        files = sorted((Path(self.input_dir) / args.processes[0]).glob("*.root"))
        self.test_file = str(files[0]) if files else ""

    # Mandatory: analyzers function to define the analysis graph, please make
    # sure you return the dataframe, in this example it is dframe2
    def analyzers(self, dframe):
        '''
        Analysis graph.
        '''

        dframe2 = (
            dframe

            ########################################### DEFINITION OF VARIABLES ###########################################

            # generator event weight
            .Define("weight",  "EventHeader.weight")
            # event number
            .Define("event_number", "EventHeader.eventNumber")
            .Define("run_number", "EventHeader.runNumber")

            ################################## RECO TO TRUTH ASSOCIATIONS ##################################
            # reco-to-MC particle association
            .Alias("MCRecoAssociations0", "_MCRecoAssociations_from.index")
            .Alias("MCRecoAssociations1", "_MCRecoAssociations_to.index")
            .Define("RP2MC_index", "FCCAnalyses::ReconstructedParticle2MC::getRP2MC_index(MCRecoAssociations0, MCRecoAssociations1, ReconstructedParticles)")

            ########################################### JETS ###########################################

            # jets after overlap removal is performed between jets and isolated electrons, muons and photons

            #selected jets above a pT threshold of 30 GeV, eta < 4, tight ID
            .Define("selpt_jets", "FCCAnalyses::ReconstructedParticle::sel_pt(30.)(Jet)")
            .Define("sel_jets_unsort", "FCCAnalyses::ReconstructedParticle::sel_eta(4)(selpt_jets)")
            .Define("sel_jets", "AnalysisFCChh::SortParticleCollection(sel_jets_unsort)")
            .Define("njets",  "FCCAnalyses::ReconstructedParticle::get_n(sel_jets)")
            .Define("j1_e",  f"FCCAnalyses::ReconstructedParticle::get_e(sel_jets).at(0, {NAN})")
            .Define("j1_pt",  f"FCCAnalyses::ReconstructedParticle::get_pt(sel_jets).at(0, {NAN})")
            .Define("j1_eta",  f"FCCAnalyses::ReconstructedParticle::get_eta(sel_jets).at(0, {NAN})")
            .Define("j1_phi",  f"FCCAnalyses::ReconstructedParticle::get_phi(sel_jets).at(0, {NAN})")

            .Define("j2_e",  f"FCCAnalyses::ReconstructedParticle::get_e(sel_jets).at(1, {NAN})")
            .Define("j2_pt",  f"FCCAnalyses::ReconstructedParticle::get_pt(sel_jets).at(1, {NAN})")
            .Define("j2_eta",  f"FCCAnalyses::ReconstructedParticle::get_eta(sel_jets).at(1, {NAN})")
            .Define("j2_phi",  f"FCCAnalyses::ReconstructedParticle::get_phi(sel_jets).at(1, {NAN})")

            #b-tagged jets:
            .Define("bjets", "AnalysisFCChh::get_tagged_jets(Jet, Jet_HF_tags, _Jet_HF_tags_particle, _Jet_HF_tags_parameters, 1)") #bit 1 = medium WP, see: https://github.com/delphes/delphes/blob/master/cards/FCC/scenarios/FCChh_I.tcl
            .Define("selpt_bjets", "FCCAnalyses::ReconstructedParticle::sel_pt(30.)(bjets)")
            .Define("sel_bjets_unsort", "FCCAnalyses::ReconstructedParticle::sel_eta(4)(selpt_bjets)")
            .Define("sel_bjets", "AnalysisFCChh::SortParticleCollection(sel_bjets_unsort)")
            .Define("nbjets", "FCCAnalyses::ReconstructedParticle::get_n(sel_bjets)")
            .Define("b1_e",  f"FCCAnalyses::ReconstructedParticle::get_e(sel_bjets).at(0, {NAN})")
            .Define("b1_pt",  f"FCCAnalyses::ReconstructedParticle::get_pt(sel_bjets).at(0, {NAN})")
            .Define("b1_eta",  f"FCCAnalyses::ReconstructedParticle::get_eta(sel_bjets).at(0, {NAN})")
            .Define("b1_phi",  f"FCCAnalyses::ReconstructedParticle::get_phi(sel_bjets).at(0, {NAN})")
            .Define("b2_e",  f"FCCAnalyses::ReconstructedParticle::get_e(sel_bjets).at(1, {NAN})")
            .Define("b2_pt",  f"FCCAnalyses::ReconstructedParticle::get_pt(sel_bjets).at(1, {NAN})")
            .Define("b2_eta",  f"FCCAnalyses::ReconstructedParticle::get_eta(sel_bjets).at(1, {NAN})")
            .Define("b2_phi",  f"FCCAnalyses::ReconstructedParticle::get_phi(sel_bjets).at(1, {NAN})")

            # make TLVs of each b-jet
            .Define("b1_tlv", f"(sel_bjets.size() > 0 ? AnalysisFCChh::getTLV_reco(sel_bjets[0]) : {NULL_TLV})")
            .Define("b2_tlv", f"(sel_bjets.size() > 1 ? AnalysisFCChh::getTLV_reco(sel_bjets[1]) : {NULL_TLV})")
            .Define("dphi_bb", f"(nbjets >= 2 ? (ROOT::Math::VectorUtil::DeltaPhi(b1_tlv, b2_tlv)) : {NAN})")
            .Define("deta_bb", f"(nbjets >= 2 ? (b1_tlv.Eta() - b2_tlv.Eta()) : {NAN})")
            .Define("dR_bb", f"(nbjets >= 2 ? (ROOT::Math::VectorUtil::DeltaR(b1_tlv, b2_tlv)) : {NAN})")

            ########################################### ELECTRONS ###########################################

            #all isolated
            .Define("ele",  "FCCAnalyses::ReconstructedParticle::get(Electron_objIdx.index, ReconstructedParticles)")
            .Define("selpt_ele", "FCCAnalyses::ReconstructedParticle::sel_pt(10.)(ele)")
            .Define("sel_ele_unsort", "FCCAnalyses::ReconstructedParticle::sel_eta(4)(selpt_ele)")
            .Define("sel_ele", "AnalysisFCChh::SortParticleCollection(sel_ele_unsort)")
            .Define("nele",  "FCCAnalyses::ReconstructedParticle::get_n(sel_ele)")
            .Define("e1_e",  f"FCCAnalyses::ReconstructedParticle::get_e(sel_ele).at(0, {NAN})")
            .Define("e1_pt",  f"FCCAnalyses::ReconstructedParticle::get_pt(sel_ele).at(0, {NAN})")
            .Define("e1_eta",  f"FCCAnalyses::ReconstructedParticle::get_eta(sel_ele).at(0, {NAN})")
            .Define("e1_phi",  f"FCCAnalyses::ReconstructedParticle::get_phi(sel_ele).at(0, {NAN})")
            .Define("e2_e",  f"FCCAnalyses::ReconstructedParticle::get_e(sel_ele).at(1, {NAN})")
            .Define("e2_pt",  f"FCCAnalyses::ReconstructedParticle::get_pt(sel_ele).at(1, {NAN})")
            .Define("e2_eta",  f"FCCAnalyses::ReconstructedParticle::get_eta(sel_ele).at(1, {NAN})")
            .Define("e2_phi",  f"FCCAnalyses::ReconstructedParticle::get_phi(sel_ele).at(1, {NAN})")

            ########################################### MUONS ###########################################

            # all isolated
            .Define("mu",  "FCCAnalyses::ReconstructedParticle::get(Muon_objIdx.index, ReconstructedParticles)")
            .Define("selpt_mu", "FCCAnalyses::ReconstructedParticle::sel_pt(10.)(mu)")
            .Define("sel_mu_unsort", "FCCAnalyses::ReconstructedParticle::sel_eta(4)(selpt_mu)")
            .Define("sel_mu", "AnalysisFCChh::SortParticleCollection(sel_mu_unsort)")
            .Define("nmu",  "FCCAnalyses::ReconstructedParticle::get_n(sel_mu)")
            .Define("m1_e",  f"FCCAnalyses::ReconstructedParticle::get_e(sel_mu).at(0, {NAN})")
            .Define("m1_pt",  f"FCCAnalyses::ReconstructedParticle::get_pt(sel_mu).at(0, {NAN})")
            .Define("m1_eta",  f"FCCAnalyses::ReconstructedParticle::get_eta(sel_mu).at(0, {NAN})")
            .Define("m1_phi",  f"FCCAnalyses::ReconstructedParticle::get_phi(sel_mu).at(0, {NAN})")
            .Define("m2_e",  f"FCCAnalyses::ReconstructedParticle::get_e(sel_mu).at(1, {NAN})")
            .Define("m2_pt",  f"FCCAnalyses::ReconstructedParticle::get_pt(sel_mu).at(1, {NAN})")
            .Define("m2_eta",  f"FCCAnalyses::ReconstructedParticle::get_eta(sel_mu).at(1, {NAN})")
            .Define("m2_phi",  f"FCCAnalyses::ReconstructedParticle::get_phi(sel_mu).at(1, {NAN})")



            ########################################### PHOTONS ###########################################
            #Old: uncorrected versions
            .Define("gamma_uncorr",  "FCCAnalyses::ReconstructedParticle::get(Photon_objIdx.index, ReconstructedParticles)")
            .Define("selpt_gamma_uncorr", "FCCAnalyses::ReconstructedParticle::sel_pt(30.)(gamma_uncorr)")
            .Define("sel_gamma_unsort_uncorr", "FCCAnalyses::ReconstructedParticle::sel_eta(4)(selpt_gamma_uncorr)")
            .Define("sel_gamma_uncorr", "AnalysisFCChh::SortParticleCollection(sel_gamma_unsort_uncorr)") #sort by pT

            .Define("ngamma_uncorr",  "FCCAnalyses::ReconstructedParticle::get_n(sel_gamma_uncorr)")
            .Define("g1_e_uncorr",  f"FCCAnalyses::ReconstructedParticle::get_e(sel_gamma_uncorr).at(0, {NAN})")
            .Define("g1_pt_uncorr",  f"FCCAnalyses::ReconstructedParticle::get_pt(sel_gamma_uncorr).at(0, {NAN})")
            .Define("g1_eta_uncorr",  f"FCCAnalyses::ReconstructedParticle::get_eta(sel_gamma_uncorr).at(0, {NAN})")
            .Define("g1_phi_uncorr",  f"FCCAnalyses::ReconstructedParticle::get_phi(sel_gamma_uncorr).at(0, {NAN})")
            .Define("g2_e_uncorr",  f"FCCAnalyses::ReconstructedParticle::get_e(sel_gamma_uncorr).at(1, {NAN})")
            .Define("g2_pt_uncorr",  f"FCCAnalyses::ReconstructedParticle::get_pt(sel_gamma_uncorr).at(1, {NAN})")
            .Define("g2_eta_uncorr",  f"FCCAnalyses::ReconstructedParticle::get_eta(sel_gamma_uncorr).at(1, {NAN})")
            .Define("g2_phi_uncorr",  f"FCCAnalyses::ReconstructedParticle::get_phi(sel_gamma_uncorr).at(1, {NAN})")

            #now get also the corrected photons:
            # all photons passing particle ID
            .Define("photon_indices", "FCCAnalyses::ReconstructedParticle::get_idx_clean(Photon_objIdx.index)")
            .Define("gamma", "FCCAnalyses::SmearObjects::SmearedReconstructedParticle(1, 22, 2, event_number[0], false)(ReconstructedParticles, RP2MC_index, Particle, photon_indices)")
            .Define("selpt_gamma", "FCCAnalyses::ReconstructedParticle::sel_pt(30.)(gamma)")
            .Define("sel_gamma_unsort", "FCCAnalyses::ReconstructedParticle::sel_eta(4)(selpt_gamma)")
            .Define("sel_gamma", "AnalysisFCChh::SortParticleCollection(sel_gamma_unsort)") #sort by pT

            .Define("ngamma",  "FCCAnalyses::ReconstructedParticle::get_n(sel_gamma)")
            # make TLVs of each photon
            .Define("g1_tlv", f"(sel_gamma.size() > 0 ? AnalysisFCChh::getTLV_reco(sel_gamma[0]) : {NULL_TLV})")
            .Define("g2_tlv", f"(sel_gamma.size() > 1 ? AnalysisFCChh::getTLV_reco(sel_gamma[1]) : {NULL_TLV})")
            .Define("dphi_yy", f"(ngamma >= 2 ? (ROOT::Math::VectorUtil::DeltaPhi(g1_tlv, g2_tlv)) : {NAN})")
            .Define("deta_yy", f"(ngamma >= 2 ? (g1_tlv.Eta() - g2_tlv.Eta()) : {NAN})")
            .Define("dR_yy", f"(ngamma >= 2 ? (ROOT::Math::VectorUtil::DeltaR(g1_tlv, g2_tlv)) : {NAN})")

            .Define("g1_e",  f"FCCAnalyses::ReconstructedParticle::get_e(sel_gamma).at(0, {NAN})")
            .Define("g1_pt",  f"FCCAnalyses::ReconstructedParticle::get_pt(sel_gamma).at(0, {NAN})")
            .Define("g1_eta",  f"FCCAnalyses::ReconstructedParticle::get_eta(sel_gamma).at(0, {NAN})")
            .Define("g1_phi",  f"FCCAnalyses::ReconstructedParticle::get_phi(sel_gamma).at(0, {NAN})")
            .Define("g2_e",  f"FCCAnalyses::ReconstructedParticle::get_e(sel_gamma).at(1, {NAN})")
            .Define("g2_pt",  f"FCCAnalyses::ReconstructedParticle::get_pt(sel_gamma).at(1, {NAN})")
            .Define("g2_eta",  f"FCCAnalyses::ReconstructedParticle::get_eta(sel_gamma).at(1, {NAN})")
            .Define("g2_phi",  f"FCCAnalyses::ReconstructedParticle::get_phi(sel_gamma).at(1, {NAN})")

            ########################################### EVENT WIDE KINEMATIC VARIABLES###########################################

            # H(bb) from the selected medium-WP b-jets; missing pairs give NaN.
            .Define("bb_pairs_unmerged", "AnalysisFCChh::getPairs(sel_bjets)") #currently gets only leading pT pair, as a RecoParticlePair
            #then merge the bb pair into one object and get its kinematic properties
            .Define("bb_pairs", "AnalysisFCChh::merge_pairs(bb_pairs_unmerged)") #merge into one object to access inv masses etc
            .Define("m_bb", f"FCCAnalyses::ReconstructedParticle::get_mass(bb_pairs).at(0, {NAN})")


            # H(yy); missing pairs give NaN.
            #old uncorrected:
            .Define("yy_pairs_unmerged_uncorr", "AnalysisFCChh::getPairs(sel_gamma_uncorr)")
            .Define("yy_pairs_uncorr", "AnalysisFCChh::merge_pairs(yy_pairs_unmerged_uncorr)")
            .Define("m_yy_uncorr", "FCCAnalyses::ReconstructedParticle::get_mass(yy_pairs_uncorr)")

            #with the correction for m_yy through smearing of angles
            .Define("yy_pairs_unmerged", "AnalysisFCChh::getPairs(sel_gamma)")
            .Define("yy_pairs", "AnalysisFCChh::merge_pairs(yy_pairs_unmerged)")
            .Define("m_yy", f"FCCAnalyses::ReconstructedParticle::get_mass(yy_pairs).at(0, {NAN})")
            # collins-soper frame
            .Define("cos_theta_yy", f"(ngamma >= 2 ? (AnalysisFCChh::collinsSoper(g1_tlv, g2_tlv)) : {NAN})")
            .Define("cos_theta_bb", f"(nbjets >= 2 ? (AnalysisFCChh::collinsSoper(b1_tlv, b2_tlv)) : {NAN})")
            .Define("cos_theta_yy_bbyy", f"(nbjets >= 2 && ngamma >= 2 ? (AnalysisFCChh::cosThetaStar_yy_in_HH(g1_tlv, g2_tlv, b1_tlv, b2_tlv)) : {NAN})")

            # now merge the yy with bb
            .Define("yy_pair_tlv", f"(yy_pairs.size() > 0 ? AnalysisFCChh::getTLV_reco(yy_pairs[0]) : {NULL_TLV})")
            .Define("pT_hyy", f"(ngamma >= 2 ? (yy_pair_tlv.Pt()) : {NAN})")


            .Define("bb_pair_tlv", f"(bb_pairs.size() > 0 ? AnalysisFCChh::getTLV_reco(bb_pairs[0]) : {NULL_TLV})")
            .Define("pT_hbb", f"(nbjets >= 2 ? (bb_pair_tlv.Pt()) : {NAN})")

            # pair kinematics
            .Define("dphi_hh", f"(nbjets >= 2 && ngamma >= 2 ? (ROOT::Math::VectorUtil::DeltaPhi(yy_pair_tlv, bb_pair_tlv)) : {NAN})")
            .Define("dR_hh", f"(nbjets >= 2 && ngamma >= 2 ? (ROOT::Math::VectorUtil::DeltaR(yy_pair_tlv, bb_pair_tlv)) : {NAN})")
            .Define("deta_hh", f"(nbjets >= 2 && ngamma >= 2 ? (yy_pair_tlv.Eta() - bb_pair_tlv.Eta()) : {NAN})")

            # jb kinematics
            .Define("dr_yb",      f"(nbjets >= 2 && ngamma >= 2 ? AnalysisFCChh::minmax_dr(g1_tlv, g2_tlv, b1_tlv, b2_tlv) : ROOT::VecOps::RVec<float>{{{NAN}, {NAN}}})")
            .Define("min_dr_yb",  "dr_yb[0]")
            .Define("max_dr_yb",  "dr_yb[1]")



            .Define("m_hh", f"(nbjets >= 2 && ngamma >= 2 ? ((bb_pair_tlv + yy_pair_tlv).M()) : {NAN})")


        )
        return dframe2

    # Mandatory: output function, please make sure you return the branch list
    # as a python list
    def output(self):
        '''
        Output variables which will be saved to output root file.
        '''
        branch_list = [
                        "weight", "event_number",
                        # Jets:
                        "njets", "j1_e", "j1_pt", "j1_eta", "j1_phi",
                        "j2_e", "j2_pt", "j2_eta", "j2_phi",
                        # B-jets:
                        "nbjets", "b1_e", "b1_pt", "b1_eta","b1_phi",
                        "b2_e", "b2_pt", "b2_eta","b2_phi",
                        # Electrons:
                        "nele", "e1_e", "e1_pt", "e1_eta", "e1_phi",
                        "e2_e", "e2_pt", "e2_eta", "e2_phi",
                        # Muons:
                        "nmu", "m1_e", "m1_pt", "m1_eta", "m1_phi",
                        "m2_e", "m2_pt", "m2_eta", "m2_phi",
                        # Photons:
                        "ngamma", "g1_e", "g1_pt", "g1_eta", "g1_phi",
                        "g2_e", "g2_pt", "g2_eta", "g2_phi",
                        #uncorrected versions:
                        "ngamma_uncorr", "g1_e_uncorr", "g1_pt_uncorr", "g1_eta_uncorr", "g1_phi_uncorr",
                        "g2_e_uncorr", "g2_pt_uncorr", "g2_eta_uncorr", "g2_phi_uncorr",
                        # Hbb decay:
                        "m_bb", "dR_bb", "dphi_bb", "deta_bb", "cos_theta_bb",
                        #Hyy decay:
                        "m_yy", "dR_yy", "dphi_yy", "deta_yy", "cos_theta_yy","cos_theta_yy_bbyy",

                        # Higgs kinematics
                        "pT_hbb", "pT_hyy", "deta_hh", "dphi_hh", "dR_hh",
                        "max_dr_yb", "min_dr_yb",

                        # di-higgs
                        "m_hh"
        ]
        return branch_list
