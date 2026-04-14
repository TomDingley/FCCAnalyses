// library with extra functions needed by custom FCC-hh analysis, such as
// HHbbZZ(llvv) analysis

#ifndef ANALYSIS_FCCHH_ANALYZERS_H
#define ANALYSIS_FCCHH_ANALYZERS_H

#include "ROOT/RVec.hxx"
#include "TLorentzVector.h"
#include "TString.h"

#include "edm4hep/MCParticleData.h"
#include "edm4hep/ParticleIDData.h"
#include "edm4hep/ReconstructedParticleData.h"
#include "podio/ObjectID.h"

#include <iostream>

namespace AnalysisFCChh {

/// TESTER: return the transverse momenta of the input ReconstructedParticles
// ROOT::VecOps::RVec<float>
// get_pt_test(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> in);

// helpers for reco particles:
TLorentzVector getTLV_reco(edm4hep::ReconstructedParticleData reco_part);
TLorentzVector getTLV_MC(edm4hep::MCParticleData MC_part);

// struct to use for a pair of two reco particles, to make sure the correct ones
// stay together
struct RecoParticlePair {
  edm4hep::ReconstructedParticleData particle_1;
  edm4hep::ReconstructedParticleData particle_2;
  TLorentzVector merged_TLV() {
    TLorentzVector tlv_1 = getTLV_reco(particle_1);
    TLorentzVector tlv_2 = getTLV_reco(particle_2);
    return tlv_1 + tlv_2;
  }
  void sort_by_pT() {
    double pT_1 = sqrt(particle_1.momentum.x * particle_1.momentum.x +
                       particle_1.momentum.y * particle_1.momentum.y);
    double pT_2 = sqrt(particle_2.momentum.x * particle_2.momentum.x +
                       particle_2.momentum.y * particle_2.momentum.y);

    if (pT_1 >= pT_2) {
      return;
    } // nothing to do if already sorted corrected
    else {
      edm4hep::ReconstructedParticleData sublead = particle_1;

      particle_1 = particle_2;
      particle_2 = sublead;
      return;
    }
  }
};

// same for MC particle
struct MCParticlePair {
  edm4hep::MCParticleData particle_1;
  edm4hep::MCParticleData particle_2;
  TLorentzVector merged_TLV() {
    TLorentzVector tlv_1 = getTLV_MC(particle_1);
    TLorentzVector tlv_2 = getTLV_MC(particle_2);
    return tlv_1 + tlv_2;
  }
  void sort_by_pT() {
    double pT_1 = sqrt(particle_1.momentum.x * particle_1.momentum.x +
                       particle_1.momentum.y * particle_1.momentum.y);
    double pT_2 = sqrt(particle_2.momentum.x * particle_2.momentum.x +
                       particle_2.momentum.y * particle_2.momentum.y);

    if (pT_1 >= pT_2) {
      return;
    } // nothing to do if already sorted corrected
    else {
      edm4hep::MCParticleData sublead = particle_1;

      particle_1 = particle_2;
      particle_2 = sublead;
      return;
    }
  }
};

// merge the particles in such a pair into one edm4hep:RecoParticle to use with
// other functions (in a vector)
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
merge_pairs(ROOT::VecOps::RVec<RecoParticlePair> pairs);
int get_n_pairs(ROOT::VecOps::RVec<RecoParticlePair> pairs);
ROOT::VecOps::RVec<RecoParticlePair>
get_first_pair(ROOT::VecOps::RVec<RecoParticlePair>
                   pairs); // can use to get leading pair if the inputs to pair
                           // finding fct were pT sorted

// functions to separate the pair again - ONLY DOES THIS FOR THE FIRST PAIR IN
// THE VECTOR
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
get_first_from_pair(ROOT::VecOps::RVec<RecoParticlePair> pairs);
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
get_second_from_pair(ROOT::VecOps::RVec<RecoParticlePair> pairs);

// truth filter used to get ZZ(llvv) events from the ZZ(llvv+4l+4v) inclusive
// signal samples
bool ZZllvvFilter(ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
                  ROOT::VecOps::RVec<podio::ObjectID> daughter_ids);
bool WWlvlvFilter(ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
                  ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
                  ROOT::VecOps::RVec<podio::ObjectID> parent_ids);

// helper functions for the ZZllv truth filter:
bool isStablePhoton(edm4hep::MCParticleData truth_part);
bool isPhoton(edm4hep::MCParticleData truth_part);
bool isLep(edm4hep::MCParticleData truth_part);
bool isLightLep(edm4hep::MCParticleData truth_part);
bool isNeutrino(edm4hep::MCParticleData truth_part);
bool isQuark(edm4hep::MCParticleData truth_part);
bool isZ(edm4hep::MCParticleData truth_part);
bool isW(edm4hep::MCParticleData truth_part);
bool isTau(edm4hep::MCParticleData truth_part);
bool isH(edm4hep::MCParticleData truth_part);
bool isb(edm4hep::MCParticleData truth_part);
bool isHadron(edm4hep::MCParticleData truth_part);
bool isTop(edm4hep::MCParticleData truth_part);
bool isGluon(edm4hep::MCParticleData truth_part);
bool isc(edm4hep::MCParticleData truth_part);
bool iss(edm4hep::MCParticleData truth_part);
bool isMuon(edm4hep::MCParticleData truth_part);
int checkZDecay(edm4hep::MCParticleData truth_Z,
                ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
                ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles);
int checkWDecay(edm4hep::MCParticleData truth_W,
                ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
                ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles);
int findTopDecayChannel(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids);
int findHiggsDecayChannel(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids);

// truth level fct to get a Z->ll truth decay
ROOT::VecOps::RVec<edm4hep::MCParticleData>
getTruthZll(ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
            ROOT::VecOps::RVec<podio::ObjectID> daughter_ids);

// find the SFOS pair of reconstructed leptons (electrons or muons)
ROOT::VecOps::RVec<RecoParticlePair>
getOSPairs(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> leptons_in);
ROOT::VecOps::RVec<RecoParticlePair> getDFOSPairs(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> electrons_in,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> muons_in);
// ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
// getOSPair(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> leptons_in);
ROOT::VecOps::RVec<RecoParticlePair> getBestOSPair(
    ROOT::VecOps::RVec<RecoParticlePair> electron_pairs,
    ROOT::VecOps::RVec<RecoParticlePair> muon_pairs); // closest to Z mass
ROOT::VecOps::RVec<RecoParticlePair>
getLeadingPair(ROOT::VecOps::RVec<RecoParticlePair> electron_pairs,
               ROOT::VecOps::RVec<RecoParticlePair>
                   muon_pairs); // pair with leading pT(pair)

// make a general pair, not caring about charges, e.g. the two b-jets
ROOT::VecOps::RVec<RecoParticlePair>
getPairs(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particles_in);
ROOT::VecOps::RVec<RecoParticlePair> getPair_sublead(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particles_in);
ROOT::VecOps::RVec<MCParticlePair>
getPairs(ROOT::VecOps::RVec<edm4hep::MCParticleData> particles_in);

// SORT OBJ COLLECTION
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> SortParticleCollection(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particles_in);

// btags
ROOT::VecOps::RVec<bool>
getJet_tag(ROOT::VecOps::RVec<int> index,
           ROOT::VecOps::RVec<edm4hep::ParticleIDData> pid,
           ROOT::VecOps::RVec<float> values, int algoIndex);
ROOT::VecOps::RVec<edm4hep::MCParticleData>
getBhadron(ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
           ROOT::VecOps::RVec<podio::ObjectID> parent_ids);
ROOT::VecOps::RVec<edm4hep::MCParticleData>
getChadron(ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
           ROOT::VecOps::RVec<podio::ObjectID> parent_ids);
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
get_tagged_jets(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> jets,
                ROOT::VecOps::RVec<edm4hep::ParticleIDData> jet_tags,
                ROOT::VecOps::RVec<podio::ObjectID> jet_tags_indices,
                ROOT::VecOps::RVec<float> jet_tags_values, int algoIndex);
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
get_untagged_jets(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> jets,
                  ROOT::VecOps::RVec<int> index,
                  ROOT::VecOps::RVec<edm4hep::ParticleIDData> pid,
                  ROOT::VecOps::RVec<float> values, int algoIndex);

// tau jets
ROOT::VecOps::RVec<edm4hep::MCParticleData> find_truth_matches(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_parts,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_particles,
    float dR_thres);
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
get_tau_jets(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> jets,
             ROOT::VecOps::RVec<int> index,
             ROOT::VecOps::RVec<edm4hep::ParticleIDData> pid,
             ROOT::VecOps::RVec<float> tag_values, int algoIndex);
ROOT::VecOps::RVec<edm4hep::MCParticleData>
getTruthTauHads(ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
                ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
                ROOT::VecOps::RVec<podio::ObjectID> parent_ids, TString type);
ROOT::VecOps::RVec<edm4hep::MCParticleData>
getTruthTau(ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
            ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
            ROOT::VecOps::RVec<podio::ObjectID> parent_ids, TString type);
ROOT::VecOps::RVec<edm4hep::MCParticleData>
getTruthTauLeps(ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
                ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
                ROOT::VecOps::RVec<podio::ObjectID> parent_ids, TString type);
// isolation: select only those particles of sel_parts that are isolated by the
// given dR from the check_parts
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
sel_isolated(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> sel_parts,
             ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> check_parts,
             float dR_thres = 0.4);

// merge two four vectors into one to create a new particle (follow vector
// structure to be able to use with other RecoParticle fcts easily like get_pt
// etc.)
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> merge_parts_TLVs(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_1,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_2);
ROOT::VecOps::RVec<edm4hep::MCParticleData>
merge_parts_TLVs(ROOT::VecOps::RVec<edm4hep::MCParticleData> particle_1,
                 ROOT::VecOps::RVec<edm4hep::MCParticleData> particle_2);

// reco level quantities
// transverse masses:
ROOT::VecOps::RVec<float>
get_mT(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_1,
       ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_2);
ROOT::VecOps::RVec<float>
get_mT_new(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_1,
           ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_2);
ROOT::VecOps::RVec<float>
get_m_pseudo(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> Z_ll_pair,
             ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET_obj);
ROOT::VecOps::RVec<float>
get_mT_pseudo(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> Z_ll_pair,
              ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET_obj);
TLorentzVector getTLV_MET(edm4hep::ReconstructedParticleData met_object);

// stransverse mass mT2 :
// https://www.hep.phy.cam.ac.uk/~lester/mt2/#Alternatives
// ROOT::VecOps::RVec<float>
// get_mT2(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_1,
// ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_2,
// ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET_obj);
// ROOT::VecOps::RVec<float>
// get_mT2_125(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
// particle_1, ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
// particle_2, ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET_obj);

// angular distances:function can return dR, dEta, dPhi for any two fully
// reconstructed particles that have a full 4 vector
ROOT::VecOps::RVec<float> get_angularDist(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_1,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_2,
    TString type = "dR");
ROOT::VecOps::RVec<float> get_angularDist_MET(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_1,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET_obj,
    TString type = "dR");

ROOT::VecOps::RVec<float>
get_angularDist_pair(ROOT::VecOps::RVec<RecoParticlePair> pairs,
                     TString type = "dR");
ROOT::VecOps::RVec<float>
get_angularDist_pair(ROOT::VecOps::RVec<MCParticlePair> pairs,
                     TString type = "dR");

// HT variables
ROOT::VecOps::RVec<float>
get_HT2(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_1,
        ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_2);
ROOT::VecOps::RVec<float>
get_HT_wInv(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET,
            ROOT::VecOps::RVec<RecoParticlePair> ll_pair,
            ROOT::VecOps::RVec<RecoParticlePair> bb_pair);
ROOT::VecOps::RVec<float>
get_HT_true(ROOT::VecOps::RVec<RecoParticlePair> ll_pair,
            ROOT::VecOps::RVec<RecoParticlePair> bb_pair);
ROOT::VecOps::RVec<float> get_HT2_ratio(ROOT::VecOps::RVec<float> HT2,
                                        ROOT::VecOps::RVec<float> HT_wInv);
ROOT::VecOps::RVec<float>
get_MET_significance(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET,
                     ROOT::VecOps::RVec<float> HT_true, bool doSqrt = true);

// reco mass of lepton+b-jet, to try suppress ttbar processes
ROOT::VecOps::RVec<RecoParticlePair>
make_lb_pairing(ROOT::VecOps::RVec<RecoParticlePair> lepton_pair,
                ROOT::VecOps::RVec<RecoParticlePair> bb_pair);
ROOT::VecOps::RVec<float>
get_mlb_reco(ROOT::VecOps::RVec<RecoParticlePair> lb_pairs);
ROOT::VecOps::RVec<float>
get_mlb_MET_reco(ROOT::VecOps::RVec<RecoParticlePair> lb_pairs,
                 ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET);

// for separating bbWW and bbtautau?
ROOT::VecOps::RVec<float>
get_pzeta_vis(ROOT::VecOps::RVec<RecoParticlePair> lepton_pair);
ROOT::VecOps::RVec<float>
get_pzeta_miss(ROOT::VecOps::RVec<RecoParticlePair> lepton_pair,
               ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET);
ROOT::VecOps::RVec<float> get_dzeta(ROOT::VecOps::RVec<float> pzeta_miss,
                                    ROOT::VecOps::RVec<float> pzeta_vis,
                                    float factor = 0.85);

// combine particles:
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
build_HZZ(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> Z_ll_pair,
          ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET_obj);

// retrieve children from a given truth particle
ROOT::VecOps::RVec<edm4hep::MCParticleData> get_immediate_children(
    edm4hep::MCParticleData truth_part,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids);

// select the truth Higgs, depending on which particles it decays to:
ROOT::VecOps::RVec<edm4hep::MCParticleData>
get_truth_Higgs(ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
                ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
                TString decay = "ZZ");
ROOT::VecOps::RVec<edm4hep::MCParticleData>
get_truth_Z_decay(ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
                  ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
                  TString decay = "ZZ");

// Filters and specifics for the bbtautau analysis:
bool isFromHadron(edm4hep::MCParticleData truth_part,
                  ROOT::VecOps::RVec<podio::ObjectID> parent_ids,
                  ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles);
bool hasHiggsParent(
    edm4hep::MCParticleData truth_part,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles);
bool isFromHiggsDirect(
    edm4hep::MCParticleData truth_part,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles);
bool isChildOfTauFromHiggs(
    edm4hep::MCParticleData truth_part,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles);
bool isChildOfWFromHiggs(
    edm4hep::MCParticleData truth_part,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles);
bool isChildOfZFromHiggs(
    edm4hep::MCParticleData truth_part,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles);
ROOT::VecOps::RVec<edm4hep::MCParticleData>
getLepsFromTau(ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
               ROOT::VecOps::RVec<podio::ObjectID> parent_ids);
ROOT::VecOps::RVec<edm4hep::MCParticleData>
getLepsFromW(ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
             ROOT::VecOps::RVec<podio::ObjectID> parent_ids);
ROOT::VecOps::RVec<edm4hep::MCParticleData>
getLepsFromZ(ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
             ROOT::VecOps::RVec<podio::ObjectID> parent_ids);
ROOT::VecOps::RVec<edm4hep::MCParticleData>
getPhotonsFromH(ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
                ROOT::VecOps::RVec<podio::ObjectID> parent_ids);
ROOT::VecOps::RVec<int> getTruthLepLepFlavour(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> leps_from_tau);
ROOT::VecOps::RVec<edm4hep::MCParticleData>
getTruthEle(ROOT::VecOps::RVec<edm4hep::MCParticleData> leps_from_tau);
ROOT::VecOps::RVec<edm4hep::MCParticleData>
getTruthMu(ROOT::VecOps::RVec<edm4hep::MCParticleData> leps_from_tau);

// tautau specific masses/variables
ROOT::VecOps::RVec<float> get_x_fraction(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> visible_particle,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET);
ROOT::VecOps::RVec<float> get_x_fraction_truth(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> visible_particle,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET);
ROOT::VecOps::RVec<float> get_mtautau_col(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> ll_pair_merged,
    ROOT::VecOps::RVec<float> x1, ROOT::VecOps::RVec<float> x2);
ROOT::VecOps::RVec<float> get_mbbtautau_col(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> bb_pair_merged,
    ROOT::VecOps::RVec<float> mtautau_col);

// truth matching:
//  old function that can match only 1 particle -> TO REMOVE?
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> find_reco_matched(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_parts_to_match,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_parts_all,
    float dR_thres = 0.1);

// isolation criterion, delphes style. flag exclude_light_leps does not check
// for isolation of test_parts vs electrons or muons (using the mass) as seems
// to be done in FCC-hh delphes sim
ROOT::VecOps::RVec<float> get_IP_delphes(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> test_parts,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_parts_all,
    float dR_min = 0.3, float pT_min = 0.5, bool exclude_light_leps = true);

ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
filter_lightLeps(ROOT::VecOps::RVec<int> recind, ROOT::VecOps::RVec<int> mcind,
                 ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco,
                 ROOT::VecOps::RVec<edm4hep::MCParticleData> mc);

// truth MET
ROOT::VecOps::RVec<edm4hep::MCParticleData>
getNusFromW(ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
            ROOT::VecOps::RVec<podio::ObjectID> parent_ids);
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
getTruthMETObj(ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
               ROOT::VecOps::RVec<podio::ObjectID> parent_ids,
               TString type = "hww_only");

// for checking signal efficiencies in delphes card validation
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> find_reco_matches(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_parts,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_particles,
    float dR_thres = 0.1);
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
find_reco_matches_no_remove(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_parts,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_particles,
    float dR_thres = 0.1);
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
find_reco_matches_exclusive(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_parts,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_parts_exc,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_particles,
    float dR_thres = 0.1);
ROOT::VecOps::RVec<int> find_reco_match_indices(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_parts,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_particles,
    float dR_thres = 0.1);
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
find_reco_matched_particle(
    edm4hep::MCParticleData truth_part_to_match,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> check_reco_parts,
    float dR_thres = 0.1);
ROOT::VecOps::RVec<edm4hep::MCParticleData> find_mc_matched_particle(
    edm4hep::ReconstructedParticleData reco_part_to_match,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> check_mc_parts,
    float dR_thres = 0.1);
ROOT::VecOps::RVec<int> find_reco_matched_index(
    edm4hep::MCParticleData truth_part_to_match,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> check_reco_parts,
    float dR_thres = 0.1);
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
find_true_signal_leps_reco_matches(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_leps_to_match,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_electrons,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_muons,
    float dR_thres = 0.1);
ROOT::VecOps::RVec<int> find_truth_to_reco_matches_indices(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_leps_to_match,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_parts,
    int pdg_ID, float dR_thres = 0.1);

// retrieving isoVar from delphes:
//  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
//  get_isoVar(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
//  reco_parts_to_check, ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
//  all_reco_parts);

// template function for getting vector via indices - needed to read e.g.
// UserDataCollections
template <typename T>
ROOT::VecOps::RVec<T> get(const ROOT::VecOps::RVec<int> &index,
                          const ROOT::VecOps::RVec<T> &in) {
  ROOT::VecOps::RVec<T> result;
  result.reserve(index.size());
  for (size_t i = 0; i < index.size(); ++i) {
    if (index[i] > -1)
      result.push_back(in[index[i]]);
  }
  return result;
}

/* functions for the HHH analysis*/

ROOT::VecOps::RVec<float> compute_sigma(
  TLorentzVector higgs_1,
  TLorentzVector higgs_2,
  TLorentzVector higgs_3
);

ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> find_reco_matches_unique(
    const ROOT::VecOps::RVec<edm4hep::MCParticleData>& truth_parts,
    const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& reco_particles,
    float dR_thres
);

ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> get_btagged_not_tau_tagged(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& jets,
  // b/HF tags
  const ROOT::VecOps::RVec<edm4hep::ParticleIDData>&  jets_HF_tags,
  const ROOT::VecOps::RVec<podio::ObjectID>&          jets_HF_tags_indices,
  const ROOT::VecOps::RVec<float>&                    jets_HF_tag_values,
  // tau tags
  const ROOT::VecOps::RVec<edm4hep::ParticleIDData>&  jets_tau_tags,
  const ROOT::VecOps::RVec<podio::ObjectID>&          jets_tau_tags_indices,
  const ROOT::VecOps::RVec<float>&                    jets_tau_tag_values,
  int btagIndex,   // bit for the chosen b WP, e.g. 1 for "medium"
  int tauIndex     // bit for the chosen tau WP, e.g. 1 for "medium"
);

ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> sel_by_iso_fail(
    const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& parts,
    const ROOT::VecOps::RVec<float>& isoVar,
    float thr
);

ROOT::VecOps::RVec<edm4hep::MCParticleData> getTruthTauLeps(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids, TString type
);

ROOT::VecOps::RVec<edm4hep::MCParticleData> getTruthTauEmu(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids, TString type
);

std::tuple<
  ROOT::VecOps::RVec<TLorentzVector>,  // p_vis
  ROOT::VecOps::RVec<TLorentzVector>,  // p_mis
  ROOT::VecOps::RVec<int>,             // n_charged
  ROOT::VecOps::RVec<int>,             // n_neutral
  ROOT::VecOps::RVec<float>,            // m_vis
  ROOT::VecOps::RVec<float>,            // m_mis
  ROOT::VecOps::RVec<int>               // n_neutrinos
> getTruthTauHadronic(
    const ROOT::VecOps::RVec<edm4hep::MCParticleData>& truth_particles,
    const ROOT::VecOps::RVec<podio::ObjectID>& daughter_ids,
    const ROOT::VecOps::RVec<podio::ObjectID>& parent_ids,
    TString type
);

// for isolation
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> select_with_mask(
    const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& objs,
    const ROOT::VecOps::RVec<char>& mask
);

std::pair<
  ROOT::VecOps::RVec<edm4hep::MCParticleData>,
  ROOT::VecOps::RVec<std::pair<edm4hep::MCParticleData, edm4hep::MCParticleData>>
> get_truth_Higgs(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
    TString decay
);

ROOT::VecOps::RVec<edm4hep::MCParticleData> SortMCByPt(
    const ROOT::VecOps::RVec<edm4hep::MCParticleData>& in
);

ROOT::VecOps::RVec<edm4hep::MCParticleData> getBhadron_final_fromH(
    const ROOT::VecOps::RVec<edm4hep::MCParticleData>& truth_particles,
    const ROOT::VecOps::RVec<podio::ObjectID>& parent_ids,
    const ROOT::VecOps::RVec<podio::ObjectID>& daughter_ids,
    float ptMin
); 

bool isSignalContaminated(
  ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_b_hadrons,
  ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_taus,
  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> selected_jets,
  float dR_truth
);

std::tuple<
  ROOT::VecOps::RVec<edm4hep::MCParticleData>,  // p_vis
  ROOT::VecOps::RVec<edm4hep::MCParticleData> // p_mis
> visible_tauhad(
    const ROOT::VecOps::RVec<edm4hep::MCParticleData>& truth_particles,
    const ROOT::VecOps::RVec<podio::ObjectID>&         daughter_ids,
    const ROOT::VecOps::RVec<podio::ObjectID>&         parent_ids,
    TString type
);

float min_dr_signal(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& target_obj,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& dR1_obj,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& dR2_obj
);

int checkWDecay_HHH(
    edm4hep::MCParticleData truth_W,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles
);

int WWlvlvFilter_HHH(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids
);

std::array<AnalysisFCChh::TauAngleRecord, 2> matchTwoTruthTwoRecoAndAngles(
    const TLorentzVector& pvis_truth_0,
    const TLorentzVector& pmiss_truth_0,
    int nprongs_truth_0,
    const TLorentzVector& pvis_truth_1,
    const TLorentzVector& pmiss_truth_1,
    int nprongs_truth_1,
    const TLorentzVector& reco0,
    const TLorentzVector& reco1,
    float drCut
);

// function to compute the perpendicular and parallel components of the MET
ROOT::VecOps::RVec<float> get_perp_para_metres(
  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> jets,
  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET_obj
);

// struct declaration for storing Higgs-pair information.
struct HiggsCandidateResult {
    ROOT::VecOps::RVec<RecoParticlePair> pairs;
    ROOT::VecOps::RVec<int> used_bjet_indices; // indices into input bjets
};

HiggsCandidateResult getHiggsCandidates(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& bjets,
  TString strategy,
  float target_mass1,
  float target_mass2
);

ROOT::VecOps::RVec<TLorentzVector> get_Htautau_vis_exclusive_TLVs(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& tauJets,
  int n_tau,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& electrons,
  int n_el,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& muons,
  int n_mu
);

std::tuple<
  edm4hep::ReconstructedParticleData, // lead constituent
  edm4hep::ReconstructedParticleData, // sublead constituent
  TLorentzVector,                      // visible H→tautau
  bool, // return if tau1 is a lepton or not
  bool // return if tau2 is a lepton or not
> get_Htautau_vis_exclusive_recoTLV(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& tauJets,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& electrons,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& muons
);


float mT_tautau(
  const TLorentzVector& tau1_vis,
  const TLorentzVector& tau2_vis,
  float MET_x,
  float MET_y
);

float ditau_mass_collinear(
    const TLorentzVector& vis1,
    const TLorentzVector& vis2,
    double METx, double METy
);

float thrust(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& bjets,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& tau_cands
);

float sphericity(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& bjets,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& tau_cands
);

float aplanarity(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& bjets,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& tau_cands
);

ROOT::VecOps::RVec<edm4hep::MCParticleData> getTruthZtautau(
    const ROOT::VecOps::RVec<edm4hep::MCParticleData> &truth_particles,
    const ROOT::VecOps::RVec<podio::ObjectID> &daughter_ids
);

float mTb_min(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& bjets,
  const edm4hep::ReconstructedParticleData& met 
);

float xwt(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& bjets,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& taujets,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& untaggedjets,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& electrons,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& muons,
  float met_px, float met_py
);

float RMS_mjj(
    const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& bjets
);

float RMS_deta(
    const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& bjets
);

float RMS_dR(
    const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& bjets
);

int find_hhh_signal_match(
  const ROOT::VecOps::RVec<edm4hep::MCParticleData>& truth_B_fromH,
  const ROOT::VecOps::RVec<edm4hep::MCParticleData>& truth_tauhad_vis_fromH,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& reco_tau_jets,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& reco_b_jets,
  float dR_thres
);

using MMCSolutionsAndWeights = std::pair<
std::vector<std::pair<float,float>>,
std::vector<std::array<float,8>>
>;


static std::vector<std::pair<float,float>> solve_ditau_MMC_METScan_para_perp_vispTAngleCalibration(
  TLorentzVector tau1,
  TLorentzVector tau2,
  bool isLep1,
  bool isLep2,
  int n_charged_tracks_1,
  int n_charged_tracks_2,
  float MET_x,
  float MET_y,
  int nsteps,
  float metres_x,
  float metres_y,
  int nMETsig,
  int nMETsteps,
  int nMass_steps,
  int n_b_jets_medium,
  int n_tau_jets_medium,
  std::vector<std::array<float,8>>* weight_components,
  bool diagnostic,
  int diag_topN,
  bool use_atlas_tf1
);

MMCSolutionsAndWeights solve_ditau_MMC_METScan_para_perp_vispTanglecalibration_weights(
  TLorentzVector tau1,
  TLorentzVector tau2,
  bool isLep1,
  bool isLep2,
  int n_charged_tracks_1,
  int n_charged_tracks_2,
  float MET_x,
  float MET_y,
  int nsteps,
  float metres_x,
  float metres_y,
  int nMETsig,
  int nMETsteps,
  int nMass_steps,
  int n_b_jets_medium,
  int n_tau_jets_medium,
  bool diagnostic,
  int diag_topN
);


std::vector<std::pair<float,float>> reweight_mditau_components(
  const std::vector<std::array<float,8>>& components,
  bool use_met,
  bool use_theta,
  bool use_ratio,
  bool use_miss
);

double weighted_mode_from_mw(
    const std::vector<std::pair<float,float>>& mw_log, // {mass, log_weight}
    int nbins, double xmin, double xmax,
    bool refine_peak,
    bool toWeight     
);

} // namespace AnalysisFCChh


#endif
