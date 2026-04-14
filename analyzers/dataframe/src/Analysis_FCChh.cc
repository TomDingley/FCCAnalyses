#include "FCCAnalyses/Analysis_FCChh.h"
// #include "FCCAnalyses/lester_mt2_bisect.h"

#include <iostream>

using namespace AnalysisFCChh;

// truth filter helper functions:
bool AnalysisFCChh::isStablePhoton(edm4hep::MCParticleData truth_part) {
  auto pdg_id = truth_part.PDG;
  // std::cout << "pdg id of truth part is" << pdg_id << std::endl;
  if (abs(pdg_id) == 22 && truth_part.generatorStatus == 1) {
    return true;
  } else {
    return false;
  }
}

bool AnalysisFCChh::isPhoton(edm4hep::MCParticleData truth_part) {
  auto pdg_id = truth_part.PDG;
  // std::cout << "pdg id of truth part is" << pdg_id << std::endl;
  if (abs(pdg_id) == 22) {
    return true;
  } else {
    return false;
  }
}

bool AnalysisFCChh::isLep(edm4hep::MCParticleData truth_part) {
  auto pdg_id = truth_part.PDG;
  // std::cout << "pdg id of truth part is" << pdg_id << std::endl;
  if (abs(pdg_id) == 11 || abs(pdg_id) == 13 || abs(pdg_id) == 15) {
    return true;
  } else {
    return false;
  }
}

bool AnalysisFCChh::isLightLep(
    edm4hep::MCParticleData truth_part) // only electrons or muons, no taus
{
  auto pdg_id = truth_part.PDG;
  // std::cout << "pdg id of truth part is" << pdg_id << std::endl;
  if (abs(pdg_id) == 11 || abs(pdg_id) == 13) {
    return true;
  } else {
    return false;
  }
}

bool AnalysisFCChh::isNeutrino(edm4hep::MCParticleData truth_part) {
  auto pdg_id = truth_part.PDG;
  // std::cout << "pdg id of truth part is" << pdg_id << std::endl;
  if (abs(pdg_id) == 12 || abs(pdg_id) == 14 || abs(pdg_id) == 16) {
    return true;
  } else {
    return false;
  }
}

bool AnalysisFCChh::isQuark(edm4hep::MCParticleData truth_part) {
  auto pdg_id = truth_part.PDG;
  // std::cout << "pdg id of truth part is" << pdg_id << std::endl;
  if (abs(pdg_id) >= 1 && abs(pdg_id) <= 6) {
    return true;
  } else {
    return false;
  }
}

bool AnalysisFCChh::isZ(edm4hep::MCParticleData truth_part) {
  auto pdg_id = truth_part.PDG;
  // std::cout << "pdg id of truth part is" << pdg_id << std::endl;
  if (abs(pdg_id) == 23) {
    return true;
  } else {
    return false;
  }
}

bool AnalysisFCChh::isW(edm4hep::MCParticleData truth_part) {
  auto pdg_id = truth_part.PDG;
  // std::cout << "pdg id of truth part is" << pdg_id << std::endl;
  if (abs(pdg_id) == 24) {
    return true;
  } else {
    return false;
  }
}

bool AnalysisFCChh::isTau(edm4hep::MCParticleData truth_part) {
  auto pdg_id = truth_part.PDG;
  // std::cout << "pdg id of truth part is" << pdg_id << std::endl;
  if (abs(pdg_id) == 15) {
    return true;
  } else {
    return false;
  }
}

bool AnalysisFCChh::isH(edm4hep::MCParticleData truth_part) {
  auto pdg_id = truth_part.PDG;
  // std::cout << "pdg id of truth part is" << pdg_id << std::endl;
  if (abs(pdg_id) == 25) {
    return true;
  } else {
    return false;
  }
}

bool AnalysisFCChh::isb(edm4hep::MCParticleData truth_part) {
  auto pdg_id = truth_part.PDG;
  // std::cout << "pdg id of truth part is" << pdg_id << std::endl;
  if (abs(pdg_id) == 5) {
    return true;
  } else {
    return false;
  }
}

bool AnalysisFCChh::isHadron(edm4hep::MCParticleData truth_part) {
  auto pdg_id = truth_part.PDG;
  // std::cout << "pdg id of truth part is" << pdg_id << std::endl;
  if (abs(pdg_id) >= 100) {
    return true;
  } else {
    return false;
  }
}

bool AnalysisFCChh::isTop(edm4hep::MCParticleData truth_part) {
  auto pdg_id = truth_part.PDG;
  // std::cout << "pdg id of truth part is" << pdg_id << std::endl;
  if (abs(pdg_id) == 6) {
    return true;
  } else {
    return false;
  }
}

bool AnalysisFCChh::isGluon(edm4hep::MCParticleData truth_part) {
  auto pdg_id = truth_part.PDG;
  // std::cout << "pdg id of truth part is" << pdg_id << std::endl;
  if (abs(pdg_id) == 21) {
    return true;
  } else {
    return false;
  }
}

bool AnalysisFCChh::isc(edm4hep::MCParticleData truth_part) {
  auto pdg_id = truth_part.PDG;
  // std::cout << "pdg id of truth part is" << pdg_id << std::endl;
  if (abs(pdg_id) == 4) {
    return true;
  } else {
    return false;
  }
}

bool AnalysisFCChh::iss(edm4hep::MCParticleData truth_part) {
  auto pdg_id = truth_part.PDG;
  // std::cout << "pdg id of truth part is" << pdg_id << std::endl;
  if (abs(pdg_id) == 3) {
    return true;
  } else {
    return false;
  }
}

bool AnalysisFCChh::isMuon(edm4hep::MCParticleData truth_part) {
  auto pdg_id = truth_part.PDG;
  // std::cout << "pdg id of truth part is" << pdg_id << std::endl;
  if (abs(pdg_id) == 13) {
    return true;
  } else {
    return false;
  }
}

// check if a truth particle came from a hadron decay, needed to veto taus that
// come from b-meson decays in the bbtautau samples
bool AnalysisFCChh::isFromHadron(
    edm4hep::MCParticleData truth_part,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles) {

  // cannot use the podio getParents fct, need to implement manually:
  auto first_parent_index = truth_part.parents_begin;
  auto last_parent_index = truth_part.parents_end;

  // loop over all parents (usually onle 1, but sometimes more for reasons not
  // understood?):
  for (int parent_i = first_parent_index; parent_i < last_parent_index;
       parent_i++) {
    // first get the index from the parent
    auto parent_MC_index = parent_ids.at(parent_i).index;

    // then go back to the original vector of MCParticles
    auto parent = truth_particles.at(parent_MC_index);

    // std::cout << "Found parent of the tau as:" << parent.PDG << std::endl;
    if (abs(parent.PDG) >= 100) {
      return true;
    }
  }
  return false;
}

// check if a truth particle had a Higgs as a parent somewhere up the chain
bool AnalysisFCChh::hasHiggsParent(
    edm4hep::MCParticleData truth_part,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles) {

  // cannot use the podio getParents fct, need to implement manually:
  auto first_parent_index = truth_part.parents_begin;
  auto last_parent_index = truth_part.parents_end;

  // loop over all parents (usually onle 1, but sometimes more for reasons not
  // understood?):
  for (int parent_i = first_parent_index; parent_i < last_parent_index;
       parent_i++) {
    // first get the index from the parent
    auto parent_MC_index = parent_ids.at(parent_i).index;

    // then go back to the original vector of MCParticles
    auto parent = truth_particles.at(parent_MC_index);

    // std::cout << "Found parent of the tau as:" << parent.PDG << std::endl;
    if (isH(parent)) {
      return true;
    }
    return hasHiggsParent(parent, parent_ids, truth_particles);
  }

  return false;
}

// check if the immediate parent of a particle is a Higgs
bool AnalysisFCChh::isFromHiggsDirect(
    edm4hep::MCParticleData truth_part,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles) {

  // cannot use the podio getParents fct, need to implement manually:
  auto first_parent_index = truth_part.parents_begin;
  auto last_parent_index = truth_part.parents_end;

  // loop over all parents (usually only 1, but sometimes more for reasons not
  // understood?):
  for (int parent_i = first_parent_index; parent_i < last_parent_index;
       parent_i++) {
    // first get the index from the parent
    auto parent_MC_index = parent_ids.at(parent_i).index;

    // then go back to the original vector of MCParticles
    auto parent = truth_particles.at(parent_MC_index);

    // std::cout << "Found parent of the tau as:" << parent.PDG << std::endl;
    if (isH(parent)) {
      return true;
    }
  }

  return false;
}

// check if a particle came from a tau that itself came from a Higgs, and not
// ever from a hadron
bool AnalysisFCChh::isChildOfTauFromHiggs(
    edm4hep::MCParticleData truth_part,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles) {
  // cannot use the podio getParents fct, need to implement manually:
  auto first_parent_index = truth_part.parents_begin;
  auto last_parent_index = truth_part.parents_end;

  // loop over all parents (usually onle 1, but sometimes more for reasons not
  // understood?):
  for (int parent_i = first_parent_index; parent_i < last_parent_index;
       parent_i++) {
    // first get the index from the parent
    auto parent_MC_index = parent_ids.at(parent_i).index;

    // then go back to the original vector of MCParticles
    auto parent = truth_particles.at(parent_MC_index);

    if (isTau(parent)) {
      // veto taus from b-decays
      if (isFromHadron(parent, parent_ids, truth_particles)) {
        return false;
      }
      if (hasHiggsParent(parent, parent_ids, truth_particles)) {
        return true;
      }
    }
  }
  return false;
}

// check if a particle came from a Z that itself came from a Higgs, and not ever
// from a hadron
bool AnalysisFCChh::isChildOfZFromHiggs(
    edm4hep::MCParticleData truth_part,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles) {
  // cannot use the podio getParents fct, need to implement manually:
  auto first_parent_index = truth_part.parents_begin;
  auto last_parent_index = truth_part.parents_end;

  // loop over all parents (usually onle 1, but sometimes more for reasons not
  // understood?):
  for (int parent_i = first_parent_index; parent_i < last_parent_index;
       parent_i++) {
    // first get the index from the parent
    auto parent_MC_index = parent_ids.at(parent_i).index;

    // then go back to the original vector of MCParticles
    auto parent = truth_particles.at(parent_MC_index);

    if (isZ(parent)) {
      // veto taus from b-decays
      if (isFromHadron(parent, parent_ids, truth_particles)) {
        return false;
      }
      if (hasHiggsParent(parent, parent_ids, truth_particles)) {
        return true;
      }
    }
  }
  return false;
}

// check if a particle came from a W that itself came from a Higgs, and not ever
// from a hadron
bool AnalysisFCChh::isChildOfWFromHiggs(
    edm4hep::MCParticleData truth_part,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles) {
  // cannot use the podio getParents fct, need to implement manually:
  auto first_parent_index = truth_part.parents_begin;
  auto last_parent_index = truth_part.parents_end;

  // loop over all parents (usually only 1, but sometimes more for reasons not
  // understood?):
  for (int parent_i = first_parent_index; parent_i < last_parent_index;
       parent_i++) {
    // first get the index from the parent
    auto parent_MC_index = parent_ids.at(parent_i).index;

    // then go back to the original vector of MCParticles
    auto parent = truth_particles.at(parent_MC_index);

    if (isW(parent)) {
      // veto Ws from b-decays
      if (isFromHadron(parent, parent_ids, truth_particles)) {
        return false;
      }
      if (hasHiggsParent(parent, parent_ids, truth_particles)) {
        return true;
      }
    }
  }
  return false;
}

// check what type the Z decay is: to ll or vv
int AnalysisFCChh::checkZDecay(
    edm4hep::MCParticleData truth_Z,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles) {

  auto first_child_index = truth_Z.daughters_begin;
  auto last_child_index = truth_Z.daughters_end;

  if (last_child_index - first_child_index != 2) {
    std::cout << "Error in checkZDecay! Found more or fewer than exactly 2 "
                 "daughters of a Z boson - this is not expected by code. Need "
                 "to implement a solution still!"
              << std::endl;
    return 0;
  }

  // now get the indices in the daughters vector
  auto child_1_MC_index = daughter_ids.at(first_child_index).index;
  auto child_2_MC_index = daughter_ids.at(last_child_index - 1).index;

  // std::cout << "Daughters run from: " << child_1_MC_index << " to " <<
  // child_2_MC_index << std::endl;

  // then go back to the original vector of MCParticles
  auto child_1 = truth_particles.at(child_1_MC_index);
  auto child_2 = truth_particles.at(child_2_MC_index);

  if (isLep(child_1) && isLep(child_2)) {
    return 1;
  } else if (isNeutrino(child_1) && isNeutrino(child_2)) {
    return 2;
  } else {
    std::cout << "Found different decay of Z boson than 2 leptons (e or mu), "
                 "neutrinos or taus! Please check."
              << std::endl;
    return 0;
  }
}

// check what type the W decay is: to lv or qq
int AnalysisFCChh::checkWDecay(
    edm4hep::MCParticleData truth_W,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles) {

  auto first_child_index = truth_W.daughters_begin;
  auto last_child_index = truth_W.daughters_end;
  auto children_size = last_child_index - first_child_index;

  if (children_size < 1) {
    std::cout
        << "Error in checkWDecay! Checking W with no daughters, returning 0."
        << std::endl;
    return 0;
  }

  // have at least 1 child -> if its also a W, continue the chain -> skip the
  // intermediate Ws, and those that radiated photon
  auto child_1_index = daughter_ids.at(first_child_index).index;
  auto child_1 = truth_particles.at(child_1_index);

  // if the child of the W is also a W, use that one
  if (isW(child_1)) {
    return checkWDecay(child_1, daughter_ids, truth_particles);
  }

  if (children_size != 2) {
    std::cout << "Error in checkWDecay! Found unexpected W decay, please check."
              << std::endl;

    return 0;
  }

  // now get the indices in the daughters vector
  //  auto child_1_MC_index = daughter_ids.at(first_child_index).index;
  auto child_2_MC_index = daughter_ids.at(last_child_index - 1).index;

  // std::cout << "Daughters run from: " << child_1_MC_index << " to " <<
  // child_2_MC_index << std::endl;

  // then go back to the original vector of MCParticles
  //  auto child_1 = truth_particles.at(child_1_MC_index);
  auto child_2 = truth_particles.at(child_2_MC_index);

  // debug
  //  std::cout << "Checking W decay: PDGID 1 = " << child_1.PDG << " and PDGID
  //  2 = " <<  child_2.PDG << std::endl;

  if (isLep(child_1) && isNeutrino(child_2)) {
    return 1;
  } else if (isNeutrino(child_1) && isLep(child_2)) {
    return 1;
  } else if (isQuark(child_1) && isQuark(child_2)) {
    return 2;
  }

  else {
    std::cout << "Found different decay of W boson than lv or qq! Please check."
              << std::endl;
    std::cout << "PDGID 1 = " << child_1.PDG << " and PDGID 2 = " << child_2.PDG
              << std::endl;
    return 0;
  }
}

// check top decay: use to see fraction of dileptionic ttbar events at pre-sel
int AnalysisFCChh::findTopDecayChannel(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids) {

  // std::cout << "Checking truth ttbar decay type" << std::endl;

  // std::vector<edm4hep::MCParticleData> top_list; // do i need this?
  int ttbar_decay_type = 1;

  for (auto &truth_part : truth_particles) {
    if (isTop(truth_part)) {
      // check what children the top has:
      auto first_child_index = truth_part.daughters_begin;
      auto last_child_index = truth_part.daughters_end;

      auto children_size = last_child_index - first_child_index;

      // skip intermediate tops that just have another top as children
      if (last_child_index - first_child_index != 2) {
        continue;
      }

      // get the pdg ids of the children
      // now get the indices in the daughters vector
      auto child_1_MC_index = daughter_ids.at(first_child_index).index;
      auto child_2_MC_index = daughter_ids.at(last_child_index - 1).index;

      // then go back to the original vector of MCParticles
      auto child_1 = truth_particles.at(child_1_MC_index);
      auto child_2 = truth_particles.at(child_2_MC_index);

      // std::cout << "PDG ID of first child: " << child_1.PDG <<  std::endl;
      // std::cout << "PDG ID of second child: " << child_2.PDG <<  std::endl;

      // skip the case where a top radiated a gluon
      if (isTop(child_1) || isTop(child_2)) {
        continue;
      }

      int w_decay_type = 0;

      if (isW(child_1) && !isW(child_2)) {
        w_decay_type = checkWDecay(child_1, daughter_ids, truth_particles);
      }

      else if (isW(child_2)) {
        w_decay_type = checkWDecay(child_2, daughter_ids, truth_particles);
      }

      else {
        std::cout << "Warning! Found two or Ws from top decay. Please check. "
                     "Skipping top."
                  << std::endl;
        continue;
      }

      // std::cout << "Code for W decay is = " << w_decay_type << std::endl;

      // codes from W decays are: 1 = W->lv and 2 W->qq, 0 for error
      // ttbar code is the code W1*W2 so that its 0 in case of any error
      // ttbar codes: 1=dileptonic, 2=semileptonic, 3=hadronic
      ttbar_decay_type *= w_decay_type;

      // top_list.push_back(truth_part);
    }
  }
  // std::cout << "Number of tops in event :" << top_list.size()<< std::endl;
  // std::cout << "Code for ttbar decay is = " << ttbar_decay_type << std::endl;
  return ttbar_decay_type;
}

// check Higgs decay: use to see if can improve stats for single Higgs bkg with
// exclusive samples
int AnalysisFCChh::findHiggsDecayChannel(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids) {

  // std::cout << "Checking truth Higgs decay type" << std::endl;

  // std::vector<edm4hep::MCParticleData> higgs_list; // FOR DEBUG

  int higgs_decay_type = 0;

  for (auto &truth_part : truth_particles) {
    if (isH(truth_part)) {
      // check what children the top has:
      auto first_child_index = truth_part.daughters_begin;
      auto last_child_index = truth_part.daughters_end;

      auto children_size = last_child_index - first_child_index;

      // skip intermediate tops that just have another Higgs as children
      if (last_child_index - first_child_index != 2) {
        continue;
      }

      // higgs_list.push_back(truth_part);

      // get the pdg ids of the children
      // now get the indices in the daughters vector
      auto child_1_MC_index = daughter_ids.at(first_child_index).index;
      auto child_2_MC_index = daughter_ids.at(last_child_index - 1).index;

      // then go back to the original vector of MCParticles
      auto child_1 = truth_particles.at(child_1_MC_index);
      auto child_2 = truth_particles.at(child_2_MC_index);

      // std::cout << "Found Higgs with two children:" << std::endl;
      // std::cout << "PDG ID of first child: " << child_1.PDG <<  std::endl;
      // std::cout << "PDG ID of second child: " << child_2.PDG <<  std::endl;

      // to check
      // //skip the case where a top radiated a gluon
      // if (isTop(child_1) || isTop(child_2)){
      // 	continue;
      // }

      // Higgs decay types:
      //  1: Hbb, 2: HWW, 3: Hgg, 4: Htautau, 5: Hcc, 6:HZZ, 7:Hyy, 8:HZy,
      //  9:Hmumu, 10:Hss

      if (isb(child_1) && isb(child_2)) {
        higgs_decay_type = 1;
      }

      else if (isW(child_1) && isW(child_2)) {
        higgs_decay_type = 2;
      }

      else if (isGluon(child_1) && isGluon(child_2)) {
        higgs_decay_type = 3;
      }

      else if (isTau(child_1) && isTau(child_2)) {
        higgs_decay_type = 4;
      }

      else if (isc(child_1) && isc(child_2)) {
        higgs_decay_type = 5;
      }

      else if (isZ(child_1) && isZ(child_2)) {
        higgs_decay_type = 6;
      }

      else if (isPhoton(child_1) && isPhoton(child_2)) {
        higgs_decay_type = 7;
      }

      else if ((isZ(child_1) && isPhoton(child_2)) ||
               (isZ(child_2) && isPhoton(child_1))) {
        higgs_decay_type = 8;
      }

      else if (isMuon(child_1) && isMuon(child_2)) {
        higgs_decay_type = 9;
      }

      else if (iss(child_1) && iss(child_2)) {
        higgs_decay_type = 10;
      }

      else {
        std::cout << "Warning! Found unkown decay of Higgs!" << std::endl;
        std::cout << "Pdg ids are " << child_1.PDG << " , " << child_2.PDG
                  << std::endl;
        continue;
      }
    }
  }
  // std::cout << "Number of higgs in event :" << higgs_list.size()<< std::endl;
  // std::cout << "Code for higgs decay is = " << higgs_decay_type << std::endl;
  return higgs_decay_type;
}

// truth filter used to get ZZ(llvv) events from the ZZ(llvv+4l+4v) inclusive
// signal samples
bool AnalysisFCChh::ZZllvvFilter(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids) {
  // first scan through the truth particles to find Z bosons
  std::vector<edm4hep::MCParticleData> z_list;
  for (auto &truth_part : truth_particles) {
    if (isZ(truth_part)) {
      z_list.push_back(truth_part);
    }
    // Tau veto:
    if (isTau(truth_part)) {
      return false;
    }
  }

  // check how many Zs are in event and build the flag:
  //  std::cout << "Number of Zs" << z_list.size() << std::endl;
  if (z_list.size() == 2) {
    int z1_decay = checkZDecay(z_list.at(0), daughter_ids, truth_particles);
    int z2_decay = checkZDecay(z_list.at(1), daughter_ids, truth_particles);

    int zz_decay_flag = z1_decay + z2_decay;

    // flags are Z(ll) =1 and Z(vv) =2, so flag for llvv is =3 (4l=2, 4v=4)
    if (zz_decay_flag == 3) {
      return true;
    } else {
      return false;
    }

  } else {
    return false;
  }
}

// truth filter used to get WW(lvlv) events from the inclusive bbWW samples
bool AnalysisFCChh::WWlvlvFilter(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids) {
  // first scan through the truth particles to find Z bosons
  std::vector<edm4hep::MCParticleData> w_list;
  for (auto &truth_part : truth_particles) {
    if (isW(truth_part) &&
        isFromHiggsDirect(truth_part, parent_ids, truth_particles)) {
      w_list.push_back(truth_part);
    }
    // Tau veto: - actually probably doesnt work as intended, to revise!!
    //  if  (isTau(truth_part)){
    //  return false;
    // }
  }

  if (w_list.size() == 2) {
    int w1_decay = checkWDecay(w_list.at(0), daughter_ids, truth_particles);
    int w2_decay = checkWDecay(w_list.at(1), daughter_ids, truth_particles);

    int ww_decay_flag = w1_decay + w2_decay;

    // flags are W(lv) =1 and W(qq) =2, so flag for lvlvv is =2 (lvqq=3, 4q=4)
    if (ww_decay_flag == 2) {
      return true;
    } else {
      return false;
    }

  } else {
    return false;
  }
}

// find a Z->ll decay on truth level
ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::getTruthZll(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids) {
  // find the Zs
  ROOT::VecOps::RVec<edm4hep::MCParticleData> z_ll_list;

  for (auto &truth_part : truth_particles) {

    if (isZ(truth_part)) {
      if (checkZDecay(truth_part, daughter_ids, truth_particles) ==
          1) { // check if is Zll decay
        z_ll_list.push_back(truth_part);
      }
    }
  }

  return z_ll_list;
}

// helper functions for reco particles:
TLorentzVector
AnalysisFCChh::getTLV_reco(edm4hep::ReconstructedParticleData reco_part) {
  TLorentzVector tlv;
  tlv.SetXYZM(reco_part.momentum.x, reco_part.momentum.y, reco_part.momentum.z,
              reco_part.mass);
  return tlv;
}

// build a MET four momentum:
TLorentzVector
AnalysisFCChh::getTLV_MET(edm4hep::ReconstructedParticleData met_object) {
  TLorentzVector tlv;
  float met_pt = sqrt(met_object.momentum.x * met_object.momentum.x +
                      met_object.momentum.y * met_object.momentum.y);
  tlv.SetPxPyPzE(met_object.momentum.x, met_object.momentum.y, 0., met_pt);

  // debug:
  //  std::cout << "Set MET 4-vector with pT = " << tlv.Pt() << " px = " <<
  //  tlv.Px() << " , py = " << tlv.Py() << " , pz = " << tlv.Pz() << " , E = "
  //  << tlv.E()  << " and m = " << tlv.M() << std::endl;

  return tlv;
}

// truth particles
TLorentzVector AnalysisFCChh::getTLV_MC(edm4hep::MCParticleData MC_part) {
  TLorentzVector tlv;
  tlv.SetXYZM(MC_part.momentum.x, MC_part.momentum.y, MC_part.momentum.z,
              MC_part.mass);
  return tlv;
}

ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::merge_pairs(ROOT::VecOps::RVec<RecoParticlePair> pairs) {
  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> merged_pairs;

  for (auto &pair : pairs) {
    TLorentzVector pair_tlv = pair.merged_TLV();

    // //build a edm4hep reco particle from the  pair:
    edm4hep::ReconstructedParticleData pair_particle;
    pair_particle.momentum.x = pair_tlv.Px();
    pair_particle.momentum.y = pair_tlv.Py();
    pair_particle.momentum.z = pair_tlv.Pz();
    pair_particle.mass = pair_tlv.M();

    merged_pairs.push_back(pair_particle);
  }

  return merged_pairs;
}

// select only the first pair in a vector (and retun as vector with size 1,
// format needed for the rdf)
ROOT::VecOps::RVec<RecoParticlePair>
AnalysisFCChh::get_first_pair(ROOT::VecOps::RVec<RecoParticlePair> pairs) {
  ROOT::VecOps::RVec<RecoParticlePair> first_pair;

  if (pairs.size()) {
    first_pair.push_back(pairs.at(0));
  }

  return first_pair;
}

// split the pair again: return only the first particle or second particle in
// the pairs - needed for getting eg. pT etc of the selected DFOS pair
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::get_first_from_pair(ROOT::VecOps::RVec<RecoParticlePair> pairs) {

  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> first_particle;

  if (pairs.size()) {
    // sort by pT first:
    pairs.at(0).sort_by_pT();
    first_particle.push_back(pairs.at(0).particle_1);
  }

  return first_particle;
}

ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::get_second_from_pair(
    ROOT::VecOps::RVec<RecoParticlePair> pairs) {

  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> second_particle;

  if (pairs.size()) {
    pairs.at(0).sort_by_pT();
    second_particle.push_back(pairs.at(0).particle_2);
  }

  return second_particle;
}

// count pairs
int AnalysisFCChh::get_n_pairs(ROOT::VecOps::RVec<RecoParticlePair> pairs) {
  return pairs.size();
}

// correct function to get jets with a certain tag (can b-tag, c-tag) - check
// delphes card of sample for which taggers are used
ROOT::VecOps::RVec<bool>
AnalysisFCChh::getJet_tag(ROOT::VecOps::RVec<int> index,
                          ROOT::VecOps::RVec<edm4hep::ParticleIDData> pid,
                          ROOT::VecOps::RVec<float> values, int algoIndex) {
  ROOT::VecOps::RVec<bool> result;
  for (size_t i = 0; i < index.size(); ++i) {
    auto v =
        static_cast<unsigned>(values.at(pid.at(index.at(i)).parameters_begin));

    result.push_back((v & (1u << algoIndex)) == (1u << algoIndex));
  }
  return result;
}

// return the list of c hadrons
ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::getChadron(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids) {

  ROOT::VecOps::RVec<edm4hep::MCParticleData> c_had_list;
  for (auto &truth_part : truth_particles) {
    int num = int(abs(truth_part.PDG));
    if ((num > 400 && num < 500) || (num > 4000 && num < 5000)) {
      c_had_list.push_back(truth_part);
    }
  }
  return c_had_list;
}

// return the list of b hadrons
ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::getBhadron(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids) {

  ROOT::VecOps::RVec<edm4hep::MCParticleData> b_had_list;
  for (auto &truth_part : truth_particles) {
    int num = int(abs(truth_part.PDG));
    if ((num > 500 && num < 600) || (num > 5000 && num < 6000)) {
      //	int npos3, npos4;
      //	for(int i=0; i<3; i++){
      //		npos3 = num%10;
      //		num = num/10;
      //	}
      //        num = int(abs(truth_part.PDG));
      //        for(int i=0; i<4; i++){
      //                npos4 = num%10;
      //                num = num/10;
      //	}
      //	if (npos3==5 || npos4==5){

      // check also if from Higgs to count only from Higgs ones
      // if ( !isFromHiggsDirect(truth_part, parent_ids, truth_particles) ){
      //	continue;
      // }

      b_had_list.push_back(truth_part);
    }
  }

  return b_had_list;
}

// rewrite of functions to get tagged jets to work with updated edm4hep,
// https://github.com/key4hep/EDM4hep/pull/268

ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::get_tagged_jets(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> jets,
    ROOT::VecOps::RVec<edm4hep::ParticleIDData> jet_tags,
    ROOT::VecOps::RVec<podio::ObjectID> jet_tags_indices,
    ROOT::VecOps::RVec<float> jet_tags_values, int algoIndex) {

  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> tagged_jets;

  // make sure we have the right collections: every tag should have exactly one
  // jet index
  assert(jet_tags.size() == jet_tags_indices.size());

  for (size_t jet_tags_i = 0; jet_tags_i < jet_tags.size(); ++jet_tags_i) {

    const auto tag = static_cast<unsigned>(
        jet_tags_values[jet_tags[jet_tags_i].parameters_begin]);

    if (tag & (1 << algoIndex)) {
      tagged_jets.push_back(jets[jet_tags_indices[jet_tags_i].index]);
    }
  }
  return tagged_jets;
}

// return the full jets rather than the list of tags
//  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
//  AnalysisFCChh::get_tagged_jets(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
//  jets, ROOT::VecOps::RVec<int> index,
//  ROOT::VecOps::RVec<edm4hep::ParticleIDData> pid, ROOT::VecOps::RVec<float>
//  tag_values, int algoIndex){

// 	ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>  tagged_jets;

// 	// std::cout << "running AnalysisFCChh::get_tagged_jets() on jet
// collection of size" << jets.size() << std::endl;

// 	for (size_t iJet = 0; iJet < jets.size(); ++iJet){
// 	// for (auto & jet : jets){
// 		// std::cout << jet.particles_begin << " to " <<
// jet.particles_end << std::endl;
// 		// get the jet particle id index for the jet
// 		const auto jetIDIndex = index[jets[iJet].particles_begin];
// 		// std::cout << "jet index = " << jetIDIndex << std::endl;
// 		const auto jetID = pid[jetIDIndex];
// 		// get the tag value
// 		const auto tag =
// static_cast<unsigned>(tag_values[jetID.parameters_begin]);
// 		// std::cout << "Tag = " << tag << std::endl;
// 		// check if the tag satisfies what we want
//     	if (tag & (1 << algoIndex)) {
//       		tagged_jets.push_back(jets[iJet]);
//     	}
// 	}

// 	return tagged_jets;
// }

// same for tau tags: they are second entry in the
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::get_tau_jets(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> jets,
    ROOT::VecOps::RVec<int> index,
    ROOT::VecOps::RVec<edm4hep::ParticleIDData> pid,
    ROOT::VecOps::RVec<float> tag_values, int algoIndex) {

  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> tagged_jets;

  // std::cout << "running AnalysisFCChh::get_tagged_jets() on jet collection of
  // size" << jets.size() << std::endl;

  for (size_t iJet = 0; iJet < jets.size(); ++iJet) {
    // for (auto & jet : jets){
    // std::cout << jet.particleIDs_begin << " to " << jet.particleIDs_end <<
    // std::endl; get the jet particle id index for the jet
    const auto jetIDIndex = index[jets[iJet].particles_begin];
    // std::cout << "jet index = " << jetIDIndex << std::endl;
    const auto jetID = pid[jetIDIndex];
    // get the tag value
    const auto tag =
        static_cast<unsigned>(tag_values[jetID.parameters_end - 1]);
    // std::cout << "Tag = " << tag << std::endl;
    // check if the tag satisfies what we want
    if (tag & (1 << algoIndex)) {
      tagged_jets.push_back(jets[iJet]);
    }
  }

  return tagged_jets;
}

// complementary: return the all jets that do not have the requested tag
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::get_untagged_jets(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> jets,
    ROOT::VecOps::RVec<int> index,
    ROOT::VecOps::RVec<edm4hep::ParticleIDData> pid,
    ROOT::VecOps::RVec<float> tag_values, int algoIndex) {

  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> untagged_jets;

  // std::cout << "running AnalysisFCChh::get_tagged_jets() on jet collection of
  // size" << jets.size() << std::endl;

  for (size_t iJet = 0; iJet < jets.size(); ++iJet) {
    // for (auto & jet : jets){
    // std::cout << jet.particleIDs_begin << " to " << jet.particleIDs_end <<
    // std::endl; get the jet particle id index for the jet
    const auto jetIDIndex = index[jets[iJet].particles_begin];
    // std::cout << "jet index = " << jetIDIndex << std::endl;
    const auto jetID = pid[jetIDIndex];
    // get the tag value
    const auto tag = static_cast<unsigned>(tag_values[jetID.parameters_begin]);
    // std::cout << "Tag = " << tag << std::endl;
    // check if the tag satisfies what we want
    if (!(tag & (1 << algoIndex))) {
      untagged_jets.push_back(jets[iJet]);
    }
  }

  return untagged_jets;
}

// select objects that are isolated from the other objects with given dR
// threshold
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::sel_isolated(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> sel_parts,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> check_parts,
    float dR_thres) {

  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> isolated_parts;

  for (auto &sel_part : sel_parts) {
    bool is_isolated = true;
    TLorentzVector sel_part_tlv = getTLV_reco(sel_part);
    // std::cout << "TLV found with pT() =" << sel_part_tlv.Pt() << std::endl;

    // loop over all particles to check against and see if any are within the dR
    // threshold
    for (auto &check_part : check_parts) {
      TLorentzVector check_part_tlv = getTLV_reco(check_part);
      float dR_val = sel_part_tlv.DeltaR(check_part_tlv);

      if (dR_val <= dR_thres) {
        is_isolated = false;
      }

      check_part_tlv.Clear();
    }

    sel_part_tlv.Clear();

    if (is_isolated) {
      isolated_parts.push_back(sel_part);
    }
  }

  return isolated_parts;
}

// find the lepton pair that likely originates from a Z decay:
ROOT::VecOps::RVec<RecoParticlePair> AnalysisFCChh::getOSPairs(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> leptons_in) {

  ROOT::VecOps::RVec<RecoParticlePair> OS_pairs;

  // need at least 2 leptons in the input
  if (leptons_in.size() < 2) {
    return OS_pairs;
  }

  // separate the leptons by charges
  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> leptons_pos;
  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> leptons_neg;

  for (auto &lep : leptons_in) {
    auto charge = lep.charge;
    if (charge > 0) {
      leptons_pos.push_back(lep);
    } else if (charge < 0) {
      leptons_neg.push_back(lep);
    }

    else {
      std::cout << "Error in function  AnalysisFCChh::getOSPair() - found "
                   "neutral particle! Function is supposed to be used for "
                   "electrons or muons only."
                << std::endl;
    }
  }

  // std::cout << "Found leptons: " << leptons_pos.size() << " pos, " <<
  // leptons_neg.size() << " neg." << std::endl;

  // check charges: if don't have one of each, cannot build OS pair and if is
  // only one of each there is no ambiguity
  if (leptons_pos.size() < 1 || leptons_neg.size() < 1) {
    return OS_pairs;
  }

  // std::cout << "Have enough leptons to build pair!" << std::endl;

  // build all possible pairs
  // TLorentzVector OS_pair_tlv;

  for (auto &lep_pos : leptons_pos) {
    // sum up the momentum components to get the TLV of the OS pair: first the
    // positive one
    //  TLorentzVector lep_pos_tlv = getTLV_reco(lep_pos);

    for (auto &lep_neg : leptons_neg) {
      // TLorentzVector lep_neg_tlv = getTLV_reco(lep_neg);
      // TLorentzVector OS_pair_tlv = lep_pos_tlv+lep_neg_tlv;

      // //build a edm4hep rco particle from the os pair:
      // edm4hep::ReconstructedParticleData OS_pair;
      // OS_pair.momentum.x = OS_pair_tlv.Px();
      // OS_pair.momentum.y = OS_pair_tlv.Py();
      // OS_pair.momentum.z = OS_pair_tlv.Pz();
      // OS_pair.mass = OS_pair_tlv.M();

      // new code: do not merge the pair but store them separately
      RecoParticlePair OS_pair;
      OS_pair.particle_1 = lep_pos;
      OS_pair.particle_2 = lep_neg;

      OS_pairs.push_back(OS_pair);
    }
  }

  // FOR DEBUG?
  //  if (OS_pairs.size() > 1){
  //  	std::cout << "Number of possible OS pairs: " << OS_pairs.size() <<
  //  std::endl; 	std::cout << "Build from: " << leptons_pos.size() << "
  //  pos, "
  //  << leptons_neg.size() << " neg." << std::endl;
  //  }

  return OS_pairs;
}

// pick the pair that is closest to Z mass:
ROOT::VecOps::RVec<RecoParticlePair> AnalysisFCChh::getBestOSPair(
    ROOT::VecOps::RVec<RecoParticlePair> electron_pairs,
    ROOT::VecOps::RVec<RecoParticlePair> muon_pairs) {

  ROOT::VecOps::RVec<RecoParticlePair> best_pair;

  // std::cout << "N_elec_pairs = " << electron_pairs.size() << ", N_muon_pairs
  // = " << muon_pairs.size() << std::endl;

  // check if any pairs in input:
  if (electron_pairs.size() == 0 && muon_pairs.size() == 0) {
    return best_pair;
  }

  // if only one pair in input, return that one:
  else if (electron_pairs.size() == 1 && muon_pairs.size() == 0) {
    best_pair.push_back(electron_pairs.at(0));
    return best_pair;
  }

  else if (electron_pairs.size() == 0 && muon_pairs.size() == 1) {
    best_pair.push_back(muon_pairs.at(0));
    return best_pair;
  }

  // if there are mor options, pick the one that is closest to Z mass

  const double Z_mass = 91.1876;

  // make a vector with both electron and muons pairs in it:
  ROOT::VecOps::RVec<RecoParticlePair> all_pairs;
  for (auto &elec_pair : electron_pairs) {
    all_pairs.push_back(elec_pair);
  }
  for (auto &muon_pair : muon_pairs) {
    all_pairs.push_back(muon_pair);
  }

  // from Clement's main code: use std::sort on the mass difference
  auto resonancesort = [&](RecoParticlePair i, RecoParticlePair j) {
    return (abs(Z_mass - i.merged_TLV().M()) <
            abs(Z_mass - j.merged_TLV().M()));
  };
  // auto resonancesort = [&] (edm4hep::ReconstructedParticleData i
  // ,edm4hep::ReconstructedParticleData j) { return (abs( Z_mass
  // -i.mass)<abs(Z_mass-j.mass)); };
  std::sort(all_pairs.begin(), all_pairs.end(), resonancesort);

  // first one should be the closest one
  best_pair.push_back(all_pairs.at(0));

  return best_pair;
}

// for the bbWW SF analysis: pick the pair that is leading in pTll
ROOT::VecOps::RVec<RecoParticlePair> AnalysisFCChh::getLeadingPair(
    ROOT::VecOps::RVec<RecoParticlePair> electron_pairs,
    ROOT::VecOps::RVec<RecoParticlePair> muon_pairs) {

  ROOT::VecOps::RVec<RecoParticlePair> best_pair;

  // std::cout << "N_elec_pairs = " << electron_pairs.size() << ", N_muon_pairs
  // = " << muon_pairs.size() << std::endl;

  // check if any pairs in input:
  if (electron_pairs.size() == 0 && muon_pairs.size() == 0) {
    return best_pair;
  }

  // if only one pair in input, return that one:
  else if (electron_pairs.size() == 1 && muon_pairs.size() == 0) {
    best_pair.push_back(electron_pairs.at(0));
    return best_pair;
  }

  else if (electron_pairs.size() == 0 && muon_pairs.size() == 1) {
    best_pair.push_back(muon_pairs.at(0));
    return best_pair;
  }

  // have at least one of each
  // make a vector with both electron and muons pairs in it:
  ROOT::VecOps::RVec<RecoParticlePair> all_pairs;
  for (auto &elec_pair : electron_pairs) {
    all_pairs.push_back(elec_pair);
  }
  for (auto &muon_pair : muon_pairs) {
    all_pairs.push_back(muon_pair);
  }

  // take the combined pT to sort
  auto pTll_sort = [&](RecoParticlePair i, RecoParticlePair j) {
    return (abs(i.merged_TLV().Pt()) > abs(j.merged_TLV().Pt()));
  };
  std::sort(all_pairs.begin(), all_pairs.end(), pTll_sort);

  best_pair.push_back(all_pairs.at(0));

  return best_pair;
}

// build all possible emu OS combinations, for eg tautau and ww analysis
ROOT::VecOps::RVec<RecoParticlePair> AnalysisFCChh::getDFOSPairs(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> electrons_in,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> muons_in) {

  ROOT::VecOps::RVec<RecoParticlePair> DFOS_pairs;

  // need at least 2 leptons in the input
  if (electrons_in.size() < 1 || muons_in.size() < 1) {
    return DFOS_pairs;
  }

  // sort the vectors by size, so that the first pair is always the leading
  auto sort_by_pT = [&](edm4hep::ReconstructedParticleData part_i,
                        edm4hep::ReconstructedParticleData part_j) {
    return (getTLV_reco(part_i).Pt() > getTLV_reco(part_j).Pt());
  };
  std::sort(electrons_in.begin(), electrons_in.end(), sort_by_pT);
  std::sort(muons_in.begin(), muons_in.end(), sort_by_pT);

  // loop over the electrons and make a pair if a muons with opposite charge is
  // found

  for (auto &elec : electrons_in) {
    for (auto &muon : muons_in) {
      auto total_charge = elec.charge + muon.charge;
      if (total_charge == 0) {
        // std::cout << "found DFOS pair!" << std::endl;
        RecoParticlePair DFOS_pair;
        DFOS_pair.particle_1 = elec;
        DFOS_pair.particle_2 = muon;

        DFOS_pairs.push_back(DFOS_pair);
      }
    }
  }

  // debug
  //  if (DFOS_pairs.size() > 1){
  //  	std::cout << "Number of possible DFOS pairs: " << DFOS_pairs.size() <<
  //  std::endl; 	std::cout << "Build from: " << electrons_in.size() << "
  //  electrons, " << muons_in.size() << " muons" << std::endl;
  //  }

  return DFOS_pairs;
}

// SortParticleCollection
//
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::SortParticleCollection(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particles_in) {
  if (particles_in.size() < 2) {
    return particles_in;
  } else {
    auto sort_by_pT = [&](edm4hep::ReconstructedParticleData part_i,
                          edm4hep::ReconstructedParticleData part_j) {
      return (getTLV_reco(part_i).Pt() > getTLV_reco(part_j).Pt());
    };
    std::sort(particles_in.begin(), particles_in.end(), sort_by_pT);
    return particles_in;
  }
}
// build all pairs from the input particles -> this returns the pair made of pT
// leading particles!!!
ROOT::VecOps::RVec<RecoParticlePair> AnalysisFCChh::getPairs(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particles_in) {

  ROOT::VecOps::RVec<RecoParticlePair> pairs;

  // need at least 2 particles in the input
  if (particles_in.size() < 2) {
    return pairs;
  }

  // else sort them by pT, and take the only the leading pair
  else {
    auto sort_by_pT = [&](edm4hep::ReconstructedParticleData part_i,
                          edm4hep::ReconstructedParticleData part_j) {
      return (getTLV_reco(part_i).Pt() > getTLV_reco(part_j).Pt());
    };
    std::sort(particles_in.begin(), particles_in.end(), sort_by_pT);

    // old method
    //  TLorentzVector tlv_1 = getTLV_reco(particles_in.at(0));
    //  TLorentzVector tlv_2 = getTLV_reco(particles_in.at(1));

    // TLorentzVector tlv_pair = tlv_1+tlv_2;

    // edm4hep::ReconstructedParticleData pair;
    // pair.momentum.x = tlv_pair.Px();
    // pair.momentum.y = tlv_pair.Py();
    // pair.momentum.z = tlv_pair.Pz();
    // pair.mass = tlv_pair.M();

    // new method, dont merge the pair
    RecoParticlePair pair;
    pair.particle_1 = particles_in.at(0);
    pair.particle_2 = particles_in.at(1);

    pairs.push_back(pair);
  }

  return pairs;
}

// same for MC particle
ROOT::VecOps::RVec<MCParticlePair> AnalysisFCChh::getPairs(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> particles_in) {

  ROOT::VecOps::RVec<MCParticlePair> pairs;

  // need at least 2 particles in the input
  if (particles_in.size() < 2) {
    return pairs;
  }

  // else sort them by pT, and take the only the leading pair
  else {
    auto sort_by_pT = [&](edm4hep::MCParticleData part_i,
                          edm4hep::MCParticleData part_j) {
      return (getTLV_MC(part_i).Pt() > getTLV_MC(part_j).Pt());
    };
    std::sort(particles_in.begin(), particles_in.end(), sort_by_pT);

    // new method, dont merge the pair
    MCParticlePair pair;
    pair.particle_1 = particles_in.at(0);
    pair.particle_2 = particles_in.at(1);

    pairs.push_back(pair);
  }

  return pairs;
}

// make the subleading pair, ie. from particles 3 and 4 in pT order
ROOT::VecOps::RVec<RecoParticlePair> AnalysisFCChh::getPair_sublead(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particles_in) {

  ROOT::VecOps::RVec<RecoParticlePair> pairs;

  // need at least 2 particles in the input
  if (particles_in.size() < 4) {
    return pairs;
  }

  // else sort them by pT, and take the only the subleading pair
  else {
    auto sort_by_pT = [&](edm4hep::ReconstructedParticleData part_i,
                          edm4hep::ReconstructedParticleData part_j) {
      return (getTLV_reco(part_i).Pt() > getTLV_reco(part_j).Pt());
    };
    std::sort(particles_in.begin(), particles_in.end(), sort_by_pT);

    // new method, dont merge the pair
    RecoParticlePair pair;
    pair.particle_1 = particles_in.at(2);
    pair.particle_2 = particles_in.at(3);

    pairs.push_back(pair);
  }

  return pairs;
}

// calculate the transverse mass ob two objects: massless approximation?
ROOT::VecOps::RVec<float> AnalysisFCChh::get_mT(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> Z_ll_pair,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET_obj) {

  ROOT::VecOps::RVec<float> mT_vector;

  // if one of the input particles is empty, just fill a default value of -999
  // as mT
  if (Z_ll_pair.size() < 1 || MET_obj.size() < 1) {
    mT_vector.push_back(-999.);
    return mT_vector;
  }

  // else, for now, just take the first of each, should be the "best" one (by
  // user input) - flexibility to use all combinations is there, to be
  // implemented if needed
  auto Z_ll = Z_ll_pair.at(0);
  auto MET = MET_obj.at(0);

  // Z_ll is fully reconstructed and regular 4 vector
  TLorentzVector tlv_Zll = getTLV_reco(Z_ll);
  float pT_ll = tlv_Zll.Pt();
  TVector3 vec_pT_ll;
  vec_pT_ll.SetXYZ(Z_ll.momentum.x, Z_ll.momentum.y, 0.);

  // for MET take the components separately: absolute MET pt and the x and y
  // component in a vector:
  TLorentzVector tlv_met = getTLV_MET(MET);
  float pT_met = tlv_met.Pt();
  TVector3 vec_pT_met;
  vec_pT_met.SetXYZ(MET.momentum.x, MET.momentum.y, 0.);

  float mT = sqrt(2. * pT_ll * pT_met *
                  (1 - cos(abs(vec_pT_ll.DeltaPhi(vec_pT_met)))));

  mT_vector.push_back(mT);

  // std::cout << "Debug mT: mT with old func = " << mT << std::endl;

  return mT_vector;
}

// different definition -> in tests it agreed 100% with previous def, keep for
// reference
ROOT::VecOps::RVec<float> AnalysisFCChh::get_mT_new(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> vis_part,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET_obj) {

  ROOT::VecOps::RVec<float> mT_vector;

  // if one of the input particles is empty, just fill a default value of -999
  // as mT
  if (vis_part.size() < 1 || MET_obj.size() < 1) {
    mT_vector.push_back(-999.);
    return mT_vector;
  }

  // else, for now, just take the first of each, should be the "best" one (by
  // user input) - flexibility to use all combinations is there, to be
  // implemented if needed
  auto visible_particle = vis_part.at(0);
  auto MET = MET_obj.at(0);

  TLorentzVector tlv_vis = getTLV_reco(visible_particle);
  float pT_vis = tlv_vis.Pt();
  TVector3 vec_pT_vis;
  vec_pT_vis.SetXYZ(visible_particle.momentum.x, visible_particle.momentum.y,
                    0.);

  // for MET take the components separately: absolute MET pt and the x and y
  // component in a vector:
  TLorentzVector tlv_met = getTLV_MET(MET);
  float pT_met = tlv_met.Pt();
  TVector3 vec_pT_met;
  vec_pT_met.SetXYZ(MET.momentum.x, MET.momentum.y, 0.);

  float mt_term1 = (pT_vis + pT_met) * (pT_vis + pT_met);
  float mt_term2 = (vec_pT_vis + vec_pT_met).Mag2();

  float mT = sqrt(mt_term1 - mt_term2);

  mT_vector.push_back(mT);

  // std::cout << "Debug mT: mT with new func = " << mT << std::endl;

  return mT_vector;
}

// pseudo-invariant mass - see CMS paper, PHYS. REV. D 102, 032003 (2020)
ROOT::VecOps::RVec<float> AnalysisFCChh::get_m_pseudo(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> Z_ll_pair,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET_obj) {

  ROOT::VecOps::RVec<float> m_pseudo_vector;

  // if one of the input particles is empty, just fill a default value of -999
  // as mT
  if (Z_ll_pair.size() < 1 || MET_obj.size() < 1) {
    m_pseudo_vector.push_back(-999.);
    return m_pseudo_vector;
  }

  TLorentzVector tlv_Zll = getTLV_reco(Z_ll_pair.at(0));
  TLorentzVector tlv_MET = getTLV_MET(MET_obj.at(0));

  TLorentzVector tlv_H_pseudo = tlv_Zll + tlv_MET;

  m_pseudo_vector.push_back(tlv_H_pseudo.M());

  return m_pseudo_vector;
}

// pseudo-transverse mass - see CMS paper, PHYS. REV. D 102, 032003 (2020)
ROOT::VecOps::RVec<float> AnalysisFCChh::get_mT_pseudo(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> Z_ll_pair,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET_obj) {

  ROOT::VecOps::RVec<float> m_pseudo_vector;

  // if one of the input particles is empty, just fill a default value of -999
  // as mT
  if (Z_ll_pair.size() < 1 || MET_obj.size() < 1) {
    m_pseudo_vector.push_back(-999.);
    return m_pseudo_vector;
  }

  TLorentzVector tlv_Zll = getTLV_reco(Z_ll_pair.at(0));
  TLorentzVector tlv_MET = getTLV_MET(MET_obj.at(0));

  TLorentzVector tlv_H_pseudo = tlv_Zll + tlv_MET;

  m_pseudo_vector.push_back(sqrt(tlv_H_pseudo.E() * tlv_H_pseudo.E() -
                                 tlv_H_pseudo.Pz() * tlv_H_pseudo.Pz()));

  return m_pseudo_vector;
}

// try the stransverse mass as defined in arXiv:1411.4312
// ROOT::VecOps::RVec<float>
// AnalysisFCChh::get_mT2(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
// particle_1, ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
// particle_2, ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET_obj){

// 	asymm_mt2_lester_bisect::disableCopyrightMessage();

// 	ROOT::VecOps::RVec<float> m_strans_vector;

// 	//if one of the input particles is empty, just fill a default value of
// -999 as mT 	if (particle_1.size() < 1 || particle_2.size() < 1||
// MET_obj.size() < 1 ){ 		m_strans_vector.push_back(-999.);
// return m_strans_vector;
// 	}

// 	TLorentzVector tlv_vis1 = getTLV_reco(particle_1.at(0));
// 	TLorentzVector tlv_vis2 = getTLV_reco(particle_2.at(0));
// 	TLorentzVector tlv_met = getTLV_MET(MET_obj.at(0));

// 	// std::cout << "Part1 : Compare TLV w. direct for px:" << tlv_vis1.Px()
// << " vs " << particle_1.at(0).momentum.x << std::endl;
// 	// std::cout << "Part1 : Compare TLV w. direct for py:" << tlv_vis1.Py()
// << " vs " << particle_1.at(0).momentum.y << std::endl;

// 	// std::cout << "Part2 : Compare TLV w. direct for px:" << tlv_vis2.Px()
// << " vs " << particle_2.at(0).momentum.x << std::endl;
// 	// std::cout << "Part2 : Compare TLV w. direct for px:" << tlv_vis2.Py()
// << " vs " << particle_2.at(0).momentum.y << std::endl;

// 	// std::cout << "MET : Compare TLV w. direct for px:" << tlv_met.Px() <<
// " vs " << MET_obj.at(0).momentum.x << std::endl;
// 	// std::cout << "MET : Compare TLV w. direct for px:" << tlv_met.Py() <<
// " vs " << MET_obj.at(0).momentum.y << std::endl;

// 	double MT2 =  asymm_mt2_lester_bisect::get_mT2(
//            tlv_vis1.M(), tlv_vis1.Px(), tlv_vis1.Py(),
//            tlv_vis2.M(), tlv_vis2.Px(), tlv_vis2.Py(),
//            tlv_met.Px(), tlv_met.Py(),
//            0., 0.);

// 	// define our inputs:

// 	m_strans_vector.push_back(MT2);

// 	return m_strans_vector;
// }

// // stransverse mass but fixing the two visible to higgs masses
// ROOT::VecOps::RVec<float>
// AnalysisFCChh::get_mT2_125(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
// particle_1, ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
// particle_2, ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET_obj){

// 	asymm_mt2_lester_bisect::disableCopyrightMessage();

// 	ROOT::VecOps::RVec<float> m_strans_vector;

// 	//if one of the input particles is empty, just fill a default value of
// -999 as mT 	if (particle_1.size() < 1 || particle_2.size() < 1||
// MET_obj.size() < 1 ){ 		m_strans_vector.push_back(-999.);
// return m_strans_vector;
// 	}

// 	TLorentzVector tlv_vis1 = getTLV_reco(particle_1.at(0));
// 	TLorentzVector tlv_vis2 = getTLV_reco(particle_2.at(0));
// 	TLorentzVector tlv_met = getTLV_MET(MET_obj.at(0));

// 	double MT2 =  asymm_mt2_lester_bisect::get_mT2(
//            125., tlv_vis1.Px(), tlv_vis1.Py(),
//            125., tlv_vis2.Px(), tlv_vis2.Py(),
//            tlv_met.Px(), tlv_met.Py(),
//            0., 0.);

// 	// define our inputs:

// 	m_strans_vector.push_back(MT2);

// 	return m_strans_vector;
// }

// HT2 variable as in ATLAS bblvlv analysis
ROOT::VecOps::RVec<float> AnalysisFCChh::get_HT2(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_1,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_2) {

  ROOT::VecOps::RVec<float> HT2_vector;

  if (particle_1.size() < 1 || particle_2.size() < 1) {
    HT2_vector.push_back(-999.);
    return HT2_vector;
  }

  TLorentzVector tlv_1 = getTLV_reco(particle_1.at(0));
  TLorentzVector tlv_2 = getTLV_reco(particle_2.at(0));

  // scalar sum
  float HT2 = tlv_1.Pt() + tlv_2.Pt();
  HT2_vector.push_back(HT2);
  return HT2_vector;
}

// HT_w_inv = scalar sum of all pT from objects of a HH->bblvlv decay as used in
// ATLAS paper for the HT ratio
ROOT::VecOps::RVec<float> AnalysisFCChh::get_HT_wInv(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET,
    ROOT::VecOps::RVec<RecoParticlePair> ll_pair,
    ROOT::VecOps::RVec<RecoParticlePair> bb_pair) {

  ROOT::VecOps::RVec<float> HT_wInv_vector;

  if (MET.size() < 1 || ll_pair.size() < 1 || bb_pair.size() < 1) {
    HT_wInv_vector.push_back(-999.);
    return HT_wInv_vector;
  }

  // if all objects are there, get the first entry in vector always (should be
  // leading) and take the pTs
  float MET_pT = getTLV_MET(MET.at(0)).Pt();

  float lep1_pT = getTLV_reco(ll_pair.at(0).particle_1).Pt();
  float lep2_pT = getTLV_reco(ll_pair.at(0).particle_2).Pt();

  float b1_pT = getTLV_reco(bb_pair.at(0).particle_1).Pt();
  float b2_pT = getTLV_reco(bb_pair.at(0).particle_2).Pt();

  // and sum ..
  float HT_w_inv = MET_pT + lep1_pT + lep2_pT + b1_pT + b2_pT;
  HT_wInv_vector.push_back(HT_w_inv);
  return HT_wInv_vector;
}

// get the true HT = scalar sum of only the visible objects, here the bs and the
// leptons (true HT in contrast to the HT with the MET)
ROOT::VecOps::RVec<float>
AnalysisFCChh::get_HT_true(ROOT::VecOps::RVec<RecoParticlePair> ll_pair,
                           ROOT::VecOps::RVec<RecoParticlePair> bb_pair) {

  ROOT::VecOps::RVec<float> HT_wInv_vector;

  if (ll_pair.size() < 1 || bb_pair.size() < 1) {
    HT_wInv_vector.push_back(-999.);
    return HT_wInv_vector;
  }

  // if all objects are there, get the first entry in vector always (should be
  // leading) and take the pTs
  float lep1_pT = getTLV_reco(ll_pair.at(0).particle_1).Pt();
  float lep2_pT = getTLV_reco(ll_pair.at(0).particle_2).Pt();

  float b1_pT = getTLV_reco(bb_pair.at(0).particle_1).Pt();
  float b2_pT = getTLV_reco(bb_pair.at(0).particle_2).Pt();

  // and sum ..
  float HT_w_inv = lep1_pT + lep2_pT + b1_pT + b2_pT;
  HT_wInv_vector.push_back(HT_w_inv);
  return HT_wInv_vector;
}

// construct ratio of HT2 and HT_w_inv
ROOT::VecOps::RVec<float>
AnalysisFCChh::get_HT2_ratio(ROOT::VecOps::RVec<float> HT2,
                             ROOT::VecOps::RVec<float> HT_wInv) {

  ROOT::VecOps::RVec<float> HT2_ratio_vector;

  if (HT2.size() < 1 || HT_wInv.size() < 1) {
    HT2_ratio_vector.push_back(-999.);
    return HT2_ratio_vector;
  }

  float HT2_ratio = HT2.at(0) / HT_wInv.at(0);
  HT2_ratio_vector.push_back(HT2_ratio);
  return HT2_ratio_vector;
}

// construct met signifcance as ratio of MET pt and true HT
ROOT::VecOps::RVec<float> AnalysisFCChh::get_MET_significance(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET,
    ROOT::VecOps::RVec<float> HT_true, bool doSqrt) {

  ROOT::VecOps::RVec<float> MET_sig_vector;

  if (MET.size() < 1 || HT_true.size() < 1) {
    MET_sig_vector.push_back(-999.);
    return MET_sig_vector;
  }

  float MET_pt = getTLV_MET(MET.at(0)).Pt();

  if (doSqrt) {
    MET_sig_vector.push_back(MET_pt / sqrt(HT_true.at(0)));
  } else {
    MET_sig_vector.push_back(MET_pt / HT_true.at(0));
  }

  return MET_sig_vector;
}

// helper function which merges two particles into one using the TLVs
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::merge_parts_TLVs(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_1,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_2) {
  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> out_vector;

  // if one of the input particles is empty, return an empty vector
  if (particle_1.size() < 1 || particle_2.size() < 1) {
    // std::cout << "Warning in AnalysisFCChh::merge_parts_TLVs - one input
    // vector is empty, returning an empty vector." << std::endl;
    return out_vector;
  }

  // else, for now, just take the first of each, should be the "best" one (by
  // user input) - flexibility to use all combinations is there, to be
  // implemented if needed
  TLorentzVector tlv_1 = getTLV_reco(particle_1.at(0));
  TLorentzVector tlv_2 = getTLV_reco(particle_2.at(0));

  TLorentzVector tlv_merged = tlv_1 + tlv_2;

  edm4hep::ReconstructedParticleData particle_merged;
  particle_merged.momentum.x = tlv_merged.Px();
  particle_merged.momentum.y = tlv_merged.Py();
  particle_merged.momentum.z = tlv_merged.Pz();
  particle_merged.mass = tlv_merged.M();

  out_vector.push_back(particle_merged);

  return out_vector;
}

// same as above, overloaded for MCParticles
ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::merge_parts_TLVs(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> particle_1,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> particle_2) {
  ROOT::VecOps::RVec<edm4hep::MCParticleData> out_vector;

  // if one of the input particles is empty, return an empty vector
  if (particle_1.size() < 1 || particle_2.size() < 1) {
    // std::cout << "Warning in AnalysisFCChh::merge_parts_TLVs - one input
    // vector is empty, returning an empty vector." << std::endl;
    return out_vector;
  }

  // else, for now, just take the first of each, should be the "best" one (by
  // user input) - flexibility to use all combinations is there, to be
  // implemented if needed
  TLorentzVector tlv_1 = getTLV_MC(particle_1.at(0));
  TLorentzVector tlv_2 = getTLV_MC(particle_2.at(0));

  TLorentzVector tlv_merged = tlv_1 + tlv_2;

  edm4hep::MCParticleData particle_merged;
  particle_merged.momentum.x = tlv_merged.Px();
  particle_merged.momentum.y = tlv_merged.Py();
  particle_merged.momentum.z = tlv_merged.Pz();
  particle_merged.mass = tlv_merged.M();

  out_vector.push_back(particle_merged);

  return out_vector;
}

// combine one lepton with one b-jet each, in case of ttbar events this should
// reconstruct the visible top

// find lb pairs with smallest average
ROOT::VecOps::RVec<RecoParticlePair>
AnalysisFCChh::make_lb_pairing(ROOT::VecOps::RVec<RecoParticlePair> lepton_pair,
                               ROOT::VecOps::RVec<RecoParticlePair> bb_pair) {

  ROOT::VecOps::RVec<RecoParticlePair> out_vector;
  RecoParticlePair lb_pair_1;
  RecoParticlePair lb_pair_2;

  // if one of the input particles is empty, return an empty vector
  if (lepton_pair.size() < 1 || bb_pair.size() < 1) {
    return out_vector;
  }

  // take the separate particles
  TLorentzVector tlv_lepton_1 = getTLV_reco(lepton_pair.at(0).particle_1);
  TLorentzVector tlv_lepton_2 = getTLV_reco(lepton_pair.at(0).particle_2);

  TLorentzVector tlv_bjet_1 = getTLV_reco(bb_pair.at(0).particle_1);
  TLorentzVector tlv_bjet_2 = getTLV_reco(bb_pair.at(0).particle_2);

  // then make the two possible combinations:
  TLorentzVector tlv_l1_b1 = tlv_lepton_1 + tlv_bjet_1;
  TLorentzVector tlv_l2_b2 = tlv_lepton_2 + tlv_bjet_2;

  TLorentzVector tlv_l1_b2 = tlv_lepton_1 + tlv_bjet_2;
  TLorentzVector tlv_l2_b1 = tlv_lepton_2 + tlv_bjet_1;

  // calculate the average invariant masses for the two combinations:
  float mlb_comb1 = (tlv_l1_b1.M() + tlv_l2_b2.M()) / 2.;
  float mlb_comb2 = (tlv_l1_b2.M() + tlv_l2_b1.M()) / 2.;

  // std::cout << "Mlb_comb1: " << mlb_comb1 << std::endl;
  // std::cout << "Mlb_comb2: " << mlb_comb2 << std::endl;

  // the combination with minimum mlb is the one we pick
  if (mlb_comb1 < mlb_comb2) {
    lb_pair_1.particle_1 = lepton_pair.at(0).particle_1;
    lb_pair_1.particle_2 = bb_pair.at(0).particle_1;

    lb_pair_2.particle_1 = lepton_pair.at(0).particle_2;
    lb_pair_2.particle_2 = bb_pair.at(0).particle_2;

  }

  else {

    lb_pair_1.particle_1 = lepton_pair.at(0).particle_1;
    lb_pair_1.particle_2 = bb_pair.at(0).particle_2;

    lb_pair_2.particle_1 = lepton_pair.at(0).particle_2;
    lb_pair_2.particle_2 = bb_pair.at(0).particle_1;
  }

  out_vector.push_back(lb_pair_1);
  out_vector.push_back(lb_pair_2);

  return out_vector;
}

// rather inefficienct, but now get the actually value of mlb again
ROOT::VecOps::RVec<float>
AnalysisFCChh::get_mlb_reco(ROOT::VecOps::RVec<RecoParticlePair> lb_pairs) {

  ROOT::VecOps::RVec<float> out_vector;

  // there should be two pairs
  if (lb_pairs.size() < 2) {
    return out_vector;
  }

  TLorentzVector tlv_pair1 = lb_pairs.at(0).merged_TLV();
  TLorentzVector tlv_pair2 = lb_pairs.at(1).merged_TLV();

  float mlb_reco = (tlv_pair1.M() + tlv_pair2.M()) / 2.;

  out_vector.push_back(mlb_reco);
  // std::cout << "Mlb : " << mlb_reco << std::endl;

  return out_vector;
}

// do trhe same thing and also add met into it
ROOT::VecOps::RVec<float> AnalysisFCChh::get_mlb_MET_reco(
    ROOT::VecOps::RVec<RecoParticlePair> lb_pairs,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET) {

  ROOT::VecOps::RVec<float> out_vector;

  // there should be two pairs and one met
  if (lb_pairs.size() < 2 || MET.size() < 1) {
    return out_vector;
  }

  TLorentzVector tlv_pair1 = lb_pairs.at(0).merged_TLV();
  TLorentzVector tlv_pair2 = lb_pairs.at(1).merged_TLV();
  TLorentzVector tlv_MET = getTLV_MET(MET.at(0));

  float mlb_reco = (tlv_pair1 + tlv_pair2 + tlv_MET).M() / 2.;

  out_vector.push_back(mlb_reco);
  // std::cout << "Mlb : " << mlb_reco << std::endl;

  return out_vector;
}

// calculate the pzetas, following CMS tautau analyses:
// https://github.com/cardinia/DesyTauAnalysesUL/blob/dev/Common/interface/functions.h#L792-L841

ROOT::VecOps::RVec<float>
AnalysisFCChh::get_pzeta_vis(ROOT::VecOps::RVec<RecoParticlePair> lepton_pair) {

  ROOT::VecOps::RVec<float> out_vector;

  // there should be one lepton pair
  if (lepton_pair.size() < 1) {
    return out_vector;
  }

  // get the tlvs of the leptons:
  TLorentzVector tlv_lepton_1 = getTLV_reco(lepton_pair.at(0).particle_1);
  TLorentzVector tlv_lepton_2 = getTLV_reco(lepton_pair.at(0).particle_2);

  // normalize the pT vectors of the leptons to their magnitudes -> make unit
  // vectors, split in x and y components
  float vec_unit_lep1_x = tlv_lepton_1.Px() / tlv_lepton_1.Pt();
  float vec_unit_lep1_y = tlv_lepton_1.Py() / tlv_lepton_1.Pt();

  float vec_unit_lep2_x = tlv_lepton_2.Px() / tlv_lepton_2.Pt();
  float vec_unit_lep2_y = tlv_lepton_2.Py() / tlv_lepton_2.Pt();

  // the sum of the two unit vectors is the bisector
  float zx = vec_unit_lep1_x + vec_unit_lep2_x;
  float zy = vec_unit_lep1_y + vec_unit_lep2_y;

  // normalize with magnitude again?
  float modz = sqrt(zx * zx + zy * zy);
  zx = zx / modz;
  zy = zy / modz;

  // build the projection of pTll onto this bisector
  float vis_ll_x = tlv_lepton_1.Px() + tlv_lepton_2.Px();
  float vis_ll_y = tlv_lepton_1.Py() + tlv_lepton_2.Py();

  float pzeta_vis = zx * vis_ll_x + zy * vis_ll_y;

  out_vector.push_back(pzeta_vis);

  // std::cout << "pzeta_vis = " << pzeta_vis << std::endl;

  return out_vector;
}

// for pzeta_miss do the same for bisector, but then project etmiss onot it:
ROOT::VecOps::RVec<float> AnalysisFCChh::get_pzeta_miss(
    ROOT::VecOps::RVec<RecoParticlePair> lepton_pair,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET) {

  ROOT::VecOps::RVec<float> out_vector;

  // there should be one lepton pair and one MET
  if (lepton_pair.size() < 1 || MET.size() < 1) {
    return out_vector;
  }

  // get the tlvs of the leptons:
  TLorentzVector tlv_lepton_1 = getTLV_reco(lepton_pair.at(0).particle_1);
  TLorentzVector tlv_lepton_2 = getTLV_reco(lepton_pair.at(0).particle_2);
  TLorentzVector tlv_MET = getTLV_MET(MET.at(0));

  // normalize the pT vectors of the leptons to their magnitudes -> make unit
  // vectors, split in x and y components
  float vec_unit_lep1_x = tlv_lepton_1.Px() / tlv_lepton_1.Pt();
  float vec_unit_lep1_y = tlv_lepton_1.Py() / tlv_lepton_1.Pt();

  float vec_unit_lep2_x = tlv_lepton_2.Px() / tlv_lepton_2.Pt();
  float vec_unit_lep2_y = tlv_lepton_2.Py() / tlv_lepton_2.Pt();

  // the sum of the two unit vectors is the bisector
  float zx = vec_unit_lep1_x + vec_unit_lep2_x;
  float zy = vec_unit_lep1_y + vec_unit_lep2_y;

  // normalize with magnitude again?
  float modz = sqrt(zx * zx + zy * zy);
  zx = zx / modz;
  zy = zy / modz;

  // build the projection of MET onto this bisector
  float pzeta_miss = zx * tlv_MET.Pt() * cos(tlv_MET.Phi()) +
                     zy * tlv_MET.Pt() * sin(tlv_MET.Phi());

  out_vector.push_back(pzeta_miss);

  // std::cout << "pzeta_miss = " << pzeta_miss << std::endl;

  return out_vector;
}

// combine the two with a factor applied: CMS tautau uses 0.85
ROOT::VecOps::RVec<float>
AnalysisFCChh::get_dzeta(ROOT::VecOps::RVec<float> pzeta_miss,
                         ROOT::VecOps::RVec<float> pzeta_vis, float factor) {

  ROOT::VecOps::RVec<float> out_vector;

  // there should be one pzeta each
  if (pzeta_miss.size() < 1 || pzeta_vis.size() < 1) {
    return out_vector;
  }

  out_vector.push_back(pzeta_miss.at(0) - factor * pzeta_vis.at(0));

  // std::cout << "dzeta = " << pzeta_miss.at(0) - factor*pzeta_vis.at(0) <<
  // std::endl;

  return out_vector;
}

// combine MET with the Zll pair into the HZZ candidate
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> AnalysisFCChh::build_HZZ(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> Z_ll_pair,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET_obj) {

  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> out_vector;

  // if one of the input particles is empty, return an empty vector and a
  // warning
  if (Z_ll_pair.size() < 1 || MET_obj.size() < 1) {
    // std::cout << "Warning in AnalysisFCChh::build_HZZ - one input vector is
    // empty, returning an empty vector." << std::endl;
    return out_vector;
  }

  // else, for now, just take the first of each, should be the "best" one (by
  // user input) - flexibility to use all combinations is there, to be
  // implemented if needed
  TLorentzVector tlv_1 = getTLV_reco(Z_ll_pair.at(0));
  TLorentzVector tlv_2 = getTLV_MET(MET_obj.at(0));

  TLorentzVector tlv_merged = tlv_1 + tlv_2;

  edm4hep::ReconstructedParticleData particle_merged;
  particle_merged.momentum.x = tlv_merged.Px();
  particle_merged.momentum.y = tlv_merged.Py();
  particle_merged.momentum.z = tlv_merged.Pz();
  particle_merged.mass = tlv_merged.M();

  out_vector.push_back(particle_merged);

  return out_vector;
}

// get dR between two objects:
ROOT::VecOps::RVec<float> AnalysisFCChh::get_angularDist(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_1,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_2,
    TString type) {

  ROOT::VecOps::RVec<float> out_vector;

  // if one of the input particles is empty, fill default value
  if (particle_1.size() < 1 || particle_2.size() < 1) {
    out_vector.push_back(-999.);
    return out_vector;
  }

  // else, for now, just take the first of each, should be the "best" one (by
  // user input) - flexibility to use all combinations is there, to be
  // implemented if needed
  TLorentzVector tlv_1 = getTLV_reco(particle_1.at(0));
  TLorentzVector tlv_2 = getTLV_reco(particle_2.at(0));

  if (type.Contains("dR")) {
    out_vector.push_back(tlv_1.DeltaR(tlv_2));
  }

  else if (type.Contains("dEta")) {
    out_vector.push_back(abs(tlv_1.Eta() - tlv_2.Eta()));
  }

  else if (type.Contains("dPhi")) {
    out_vector.push_back(tlv_1.DeltaPhi(tlv_2));
  }

  else {
    std::cout
        << " Error in AnalysisFCChh::get_angularDist - requested unknown type "
        << type << "Returning default of -999." << std::endl;
    out_vector.push_back(-999.);
  }

  return out_vector;
}

// get angular distances between MET and an object:
ROOT::VecOps::RVec<float> AnalysisFCChh::get_angularDist_MET(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> particle_1,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET_obj,
    TString type) {

  ROOT::VecOps::RVec<float> out_vector;

  // if one of the input particles is empty, fill default value
  if (particle_1.size() < 1 || MET_obj.size() < 1) {
    out_vector.push_back(-999.);
    return out_vector;
  }

  // else, for now, just take the first of each, should be the "best" one (by
  // user input) - flexibility to use all combinations is there, to be
  // implemented if needed
  TLorentzVector tlv_1 = getTLV_reco(particle_1.at(0));
  TLorentzVector tlv_2 = getTLV_MET(MET_obj.at(0));

  if (type.Contains("dR")) {
    out_vector.push_back(tlv_1.DeltaR(tlv_2));
  }

  else if (type.Contains("dEta")) {
    out_vector.push_back(abs(tlv_1.Eta() - tlv_2.Eta()));
  }

  else if (type.Contains("dPhi")) {
    out_vector.push_back(tlv_1.DeltaPhi(tlv_2));
  }

  else {
    std::cout
        << " Error in AnalysisFCChh::get_angularDist - requested unknown type "
        << type << "Returning default of -999." << std::endl;
    out_vector.push_back(-999.);
  }

  return out_vector;
}

// get angular distances between the two particles in a pair:
ROOT::VecOps::RVec<float>
AnalysisFCChh::get_angularDist_pair(ROOT::VecOps::RVec<RecoParticlePair> pairs,
                                    TString type) {

  ROOT::VecOps::RVec<float> out_vector;

  // if input pairs is empty, fill default value
  if (pairs.size() < 1) {
    out_vector.push_back(-999.);
    return out_vector;
  }

  // else, for now, just take the first of each, should be the "best" one (by
  // user input) - flexibility to use all combinations is there, to be
  // implemented if needed
  TLorentzVector tlv_1 = getTLV_reco(pairs.at(0).particle_1);
  TLorentzVector tlv_2 = getTLV_reco(pairs.at(0).particle_2);

  if (type.Contains("dR")) {
    out_vector.push_back(tlv_1.DeltaR(tlv_2));
  }

  else if (type.Contains("dEta")) {
    out_vector.push_back(abs(tlv_1.Eta() - tlv_2.Eta()));
  }

  else if (type.Contains("dPhi")) {
    out_vector.push_back(tlv_1.DeltaPhi(tlv_2));
  }

  else {
    std::cout
        << " Error in AnalysisFCChh::get_angularDist - requested unknown type "
        << type << "Returning default of -999." << std::endl;
    out_vector.push_back(-999.);
  }

  return out_vector;
}

// get angular distances between the two particles in a pair: MC particles
ROOT::VecOps::RVec<float>
AnalysisFCChh::get_angularDist_pair(ROOT::VecOps::RVec<MCParticlePair> pairs,
                                    TString type) {

  ROOT::VecOps::RVec<float> out_vector;

  // if input pairs is empty, fill default value
  if (pairs.size() < 1) {
    out_vector.push_back(-999.);
    return out_vector;
  }

  // else, for now, just take the first of each, should be the "best" one (by
  // user input) - flexibility to use all combinations is there, to be
  // implemented if needed
  TLorentzVector tlv_1 = getTLV_MC(pairs.at(0).particle_1);
  TLorentzVector tlv_2 = getTLV_MC(pairs.at(0).particle_2);

  if (type.Contains("dR")) {
    out_vector.push_back(tlv_1.DeltaR(tlv_2));
  }

  else if (type.Contains("dEta")) {
    out_vector.push_back(abs(tlv_1.Eta() - tlv_2.Eta()));
  }

  else if (type.Contains("dPhi")) {
    out_vector.push_back(tlv_1.DeltaPhi(tlv_2));
  }

  else {
    std::cout
        << " Error in AnalysisFCChh::get_angularDist - requested unknown type "
        << type << "Returning default of -999." << std::endl;
    out_vector.push_back(-999.);
  }

  return out_vector;
}

// function which returns the immediate children of a truth particle
ROOT::VecOps::RVec<edm4hep::MCParticleData>
AnalysisFCChh::get_immediate_children(
    edm4hep::MCParticleData truth_part,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids) {

  ROOT::VecOps::RVec<edm4hep::MCParticleData> child_list;
  auto first_child_index = truth_part.daughters_begin;
  auto last_child_index = truth_part.daughters_end;
  auto children_size = last_child_index - first_child_index;

  // std::cout << "children size: " << children_size << std::endl;

  for (int child_i = 0; child_i < children_size; child_i++) {
    auto child_i_index = daughter_ids.at(first_child_index + child_i).index;
    auto child = truth_particles.at(child_i_index);
    // std::cout << "PDG ID of child number " << child_i << " : " << child.PDG
    // <<  std::endl;
    child_list.push_back(child);
  }

  return child_list;
}

// function which finds truth higgs in the MC particles and selects the one that
// decays according to requested type (to ZZ or bb here)
ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::get_truth_Higgs(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids, TString decay) {
  ROOT::VecOps::RVec<edm4hep::MCParticleData> higgs_list;

  // std::cout << "looking for higgs .." << std::endl;

  for (auto &truth_part : truth_particles) {
    if (isH(truth_part)) {
      // check into which particles the Higgs decays:

      auto first_child_index = truth_part.daughters_begin;
      auto last_child_index = truth_part.daughters_end;

      // std::cout << "Found higgs with children with indices " <<
      // first_child_index << " , " << last_child_index << std::endl; std::cout
      // << "number of higgs daughters:" << last_child_index - first_child_index
      // << std::endl;

      // std::cout << "number of higgs daughters:" << last_child_index -
      // first_child_index << std::endl;

      // skip the intermediate higgs that only lead to one other particle
      if (last_child_index - first_child_index != 2) {
        // std::cout << "Error in get_truth_Higgs! Found more or fewer than
        // exactly 2 daughters of a higgs boson - this is not expected by code.
        // Need to implement a solution still!"<< std::endl; return higgs_list;
        continue;
      }

      // now get the indices in the daughters vector
      auto child_1_MC_index = daughter_ids.at(first_child_index).index;
      auto child_2_MC_index = daughter_ids.at(last_child_index - 1).index;

      // then go back to the original vector of MCParticles
      auto child_1 = truth_particles.at(child_1_MC_index);
      auto child_2 = truth_particles.at(child_2_MC_index);

      // std::cout << "PDG ID of first child: " << child_1.PDG <<  std::endl;
      // std::cout << "PDG ID of second child: " << child_2.PDG <<  std::endl;

      // std::cout << "Found higgs with status = " << h_status << " and children
      // with indices " << child_1.PDG << " , " << child_2.PDG << std::endl;
      if (decay.Contains("ZZ") && isZ(child_1) && isZ(child_2)) {
        higgs_list.push_back(truth_part);
      }

      else if (decay.Contains("bb") && isb(child_1) && isb(child_2)) {
        higgs_list.push_back(truth_part);
      }

      else if ((decay.Contains("yy") || decay.Contains("aa")) &&
               isPhoton(child_1) && isPhoton(child_2)) {
        higgs_list.push_back(truth_part);
      }
    }
  }

  return higgs_list;
}

// Same for getting a truth Z (->bb)
ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::get_truth_Z_decay(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids, TString decay) {
  ROOT::VecOps::RVec<edm4hep::MCParticleData> Z_list;

  // std::cout << "looking for higgs .." << std::endl;

  for (auto &truth_part : truth_particles) {
    if (isZ(truth_part)) {
      // check into which particles the Higgs decays:

      auto first_child_index = truth_part.daughters_begin;
      auto last_child_index = truth_part.daughters_end;

      // std::cout << "Found Z with children with indices " << first_child_index
      // << " , " << last_child_index << std::endl; std::cout << "number of Z
      // daughters:" << last_child_index - first_child_index << std::endl;

      // skip the intermediate Z that only lead to another Z
      if (last_child_index - first_child_index != 2) {
        continue;
      }

      // now get the indices in the daughters vector
      auto child_1_MC_index = daughter_ids.at(first_child_index).index;
      auto child_2_MC_index = daughter_ids.at(last_child_index - 1).index;

      // then go back to the original vector of MCParticles
      auto child_1 = truth_particles.at(child_1_MC_index);
      auto child_2 = truth_particles.at(child_2_MC_index);

      // std::cout << "PDG ID of first child: " << child_1.PDG <<  std::endl;
      // std::cout << "PDG ID of second child: " << child_2.PDG <<  std::endl;

      if (decay.Contains("bb") && isb(child_1) && isb(child_2)) {
        Z_list.push_back(truth_part);
      }
    }
  }

  return Z_list;
}

// get the truth flavour of the leptons from taus
ROOT::VecOps::RVec<int> AnalysisFCChh::getTruthLepLepFlavour(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> leps_from_tau) {

  ROOT::VecOps::RVec<int> results_vec;

  if (leps_from_tau.size() != 2) {
    std::cout
        << "Error - running getTruthLepLepFlavour on event which doesn't have "
           "exactly two leptons from taus. This isnt the intended usage."
        << std::endl;
    return results_vec;
  }

  auto pdg_1 = leps_from_tau.at(0).PDG;
  auto pdg_2 = leps_from_tau.at(1).PDG;

  if (abs(pdg_1) == 11 && abs(pdg_2) == 11) {
    results_vec.push_back(0);
  }

  else if (abs(pdg_1) == 13 && abs(pdg_2) == 13) {
    results_vec.push_back(1);
  }

  else if ((abs(pdg_1) == 11 && abs(pdg_2) == 13) ||
           (abs(pdg_1) == 13 && abs(pdg_2) == 11)) {
    results_vec.push_back(2);
  }

  // option for taus, needed for checking bbWW
  else if (abs(pdg_1) == 15 || abs(pdg_2) == 15) {
    results_vec.push_back(3);
  }

  else {
    std::cout << "Error - found leptons from taus that are neither electrons "
                 "nor muons"
              << std::endl;
    results_vec.push_back(-999);
  }

  return results_vec;
}

// take the vector with truth leptons from taus  and pick out the electron or
// muon
ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::getTruthEle(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> leps_from_tau) {

  ROOT::VecOps::RVec<edm4hep::MCParticleData> results_vec;

  for (auto &truth_lep : leps_from_tau) {

    // std::cout << "PDG ID " << abs(truth_lep.PDG) << std::endl;

    // electrons
    if (abs(truth_lep.PDG) == 11) {
      results_vec.push_back(truth_lep);
    }
  }
  return results_vec;
}

ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::getTruthMu(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> leps_from_tau) {

  ROOT::VecOps::RVec<edm4hep::MCParticleData> results_vec;

  for (auto &truth_lep : leps_from_tau) {

    // muons
    if (abs(truth_lep.PDG) == 13) {
      results_vec.push_back(truth_lep);
    }
  }
  return results_vec;
}

// find the light leptons (e or mu) that originate from a tau decay (which comes
// from a higgs, and not a b-meson) using the truth info -> to use as filter for
// emu tautau evts
ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::getLepsFromTau(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids) {
  // test by simply counting first:
  //  int counter = 0;
  ROOT::VecOps::RVec<edm4hep::MCParticleData> leps_list;

  // loop over all truth particles and find light leptons from taus that came
  // from higgs (the direction tau->light lepton as child appears to be missing
  // in the tautau samples)
  for (auto &truth_part : truth_particles) {
    if (isLightLep(truth_part)) {
      bool from_tau_higgs =
          isChildOfTauFromHiggs(truth_part, parent_ids, truth_particles);
      if (from_tau_higgs) {
        // counter+=1;
        leps_list.push_back(truth_part);
      }
    }
  }
  // std::cout << "Leps from tau-higgs " << counter << std::endl;
  return leps_list;
}

ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::getTruthTau(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids, TString type) {

  ROOT::VecOps::RVec<edm4hep::MCParticleData> tau_list;
  for (auto &truth_part : truth_particles) {
    bool flagchildren = false;
    if (isTau(truth_part)) {

      // check also if from Higgs to count only from Higgs ones
      if (type.Contains("from_higgs") &&
          !isFromHiggsDirect(
              truth_part, parent_ids,
              truth_particles)) { //&& isFromHadron(truth_part, parent_ids,
                                  // truth_particles) ) {
        continue;
      }
      // select both from higgs or from hadrons
      if (type.Contains("higgshad") &&
          !isFromHiggsDirect(truth_part, parent_ids, truth_particles) &&
          !isFromHadron(truth_part, parent_ids, truth_particles)) {
        // continue;
        std::cout << " found tau neither from Higgs or from Had" << std::endl;
        auto first_parent_index = truth_part.parents_begin;
        auto last_parent_index = truth_part.parents_end;
        for (int parent_i = first_parent_index; parent_i < last_parent_index;
             parent_i++) {
          auto parent_MC_index = parent_ids.at(parent_i).index;
          auto parent = truth_particles.at(parent_MC_index);
          std::cout << "Parent PDG:" << std::endl;
          std::cout << parent.PDG << std::endl;
        }
        continue;
      }

      tau_list.push_back(truth_part);
    }
  }
  //}

  return tau_list;
}

ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::getTruthTauLeps(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids, TString type) {

  ROOT::VecOps::RVec<edm4hep::MCParticleData> tau_list;
  bool flagchildren = false;
  for (auto &truth_part : truth_particles) {
    flagchildren = false;
    if (isTau(truth_part)) {

      // check also if from Higgs to count only from Higgs ones
      if (type.Contains("from_higgs") &&
          !isFromHiggsDirect(
              truth_part, parent_ids,
              truth_particles)) { //&& isFromHadron(truth_part, parent_ids,
                                  // truth_particles) ) {
        continue;
      }
      // select both from higgs or from hadrons
      if (type.Contains("higgshad") &&
          !isFromHiggsDirect(truth_part, parent_ids, truth_particles) &&
          !isFromHadron(truth_part, parent_ids, truth_particles)) {
        // continue;
        std::cout << " found tau neither from Higgs or from Had" << std::endl;
        auto first_parent_index = truth_part.parents_begin;
        auto last_parent_index = truth_part.parents_end;
        for (int parent_i = first_parent_index; parent_i < last_parent_index;
             parent_i++) {
          auto parent_MC_index = parent_ids.at(parent_i).index;
          auto parent = truth_particles.at(parent_MC_index);
          std::cout << "Parent PDG:" << std::endl;
          std::cout << parent.PDG << std::endl;
        }
        continue;
      }
      bool isItself = true;
      while (isItself) {
        auto first_child_index = truth_part.daughters_begin;
        auto last_child_index = truth_part.daughters_end;
        // auto child_1_MC_index = daughter_ids.at(first_child_index).index;
        // auto hild_2_MC_index = daughter_ids.at(last_child_index-1).index;
        for (int child_i = first_child_index; child_i < last_child_index;
             child_i++) {
          auto child = truth_particles.at(daughter_ids.at(child_i).index);
          if (abs(child.PDG) == 15) {
            isItself = true;
            truth_part = child;
            break;
          } else {
            isItself = false;
          }
        }
      }

      // std::cout << " found tau with children" << std::endl;
      auto first_child_index = truth_part.daughters_begin;
      auto last_child_index = truth_part.daughters_end;
      for (int ch_i = first_child_index; ch_i < last_child_index; ch_i++) {
        auto ch = truth_particles.at(daughter_ids.at(ch_i).index);
        std::cout << "Child ID: " << ch.PDG << std::endl;
        if (isLep(ch)) {
          std::cout << " Is leptonic" << std::endl;
          flagchildren = true;
          break;
        }
      }
      if (flagchildren) {
        tau_list.push_back(truth_part);
      }
    }
  }

  return tau_list;
}

// find truth (hadronic) taus, to check the tau veto
ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::getTruthTauHads(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids, TString type) {

  ROOT::VecOps::RVec<edm4hep::MCParticleData> tau_list;
  bool flagchildren = false;
  for (auto &truth_part : truth_particles) {
    flagchildren = false;
    if (isTau(truth_part)) {

      // check also if from Higgs to count only from Higgs ones
      if (type.Contains("from_higgs") &&
          !isFromHiggsDirect(
              truth_part, parent_ids,
              truth_particles)) { //&& isFromHadron(truth_part, parent_ids,
                                  // truth_particles) ) {
        continue;
      }
      // select both from higgs or from hadrons
      if (type.Contains("higgshad") &&
          !isFromHiggsDirect(truth_part, parent_ids, truth_particles) &&
          !isFromHadron(truth_part, parent_ids, truth_particles)) {
        // continue;
        std::cout << " found tau neither from Higgs or from Had" << std::endl;
        auto first_parent_index = truth_part.parents_begin;
        auto last_parent_index = truth_part.parents_end;
        for (int parent_i = first_parent_index; parent_i < last_parent_index;
             parent_i++) {
          auto parent_MC_index = parent_ids.at(parent_i).index;
          auto parent = truth_particles.at(parent_MC_index);
          std::cout << "Parent PDG:" << std::endl;
          std::cout << parent.PDG << std::endl;
        }
        continue;
      }
      bool isItself = true;
      while (isItself) {
        auto first_child_index = truth_part.daughters_begin;
        auto last_child_index = truth_part.daughters_end;
        // auto child_1_MC_index = daughter_ids.at(first_child_index).index;
        // auto hild_2_MC_index = daughter_ids.at(last_child_index-1).index;
        for (int child_i = first_child_index; child_i < last_child_index;
             child_i++) {
          auto child = truth_particles.at(daughter_ids.at(child_i).index);
          if (abs(child.PDG) == 15) {
            isItself = true;
            truth_part = child;
            break;
          } else {
            isItself = false;
          }
        }
      }

      // std::cout << " found tau with children" << std::endl;
      auto first_child_index = truth_part.daughters_begin;
      auto last_child_index = truth_part.daughters_end;
      for (int ch_i = first_child_index; ch_i < last_child_index; ch_i++) {
        auto ch = truth_particles.at(daughter_ids.at(ch_i).index);
        std::cout << "Child ID: " << ch.PDG << std::endl;
        if (isHadron(ch)) {
          std::cout << " Is hadronic" << std::endl;
          flagchildren = true;
          break;
        }
      }
      if (flagchildren) {
        tau_list.push_back(truth_part);
      }
    }
  }

  return tau_list;
}

// find leptons (including taus?) that came from a H->WW decay
ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::getLepsFromW(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids) {
  // test by simply counting first:
  //  int counter = 0;
  ROOT::VecOps::RVec<edm4hep::MCParticleData> leps_list;

  // loop over all truth particles and find light leptons from taus that came
  // from higgs (the direction tau->light lepton as child appears to be missing
  // in the tautau samples)
  for (auto &truth_part : truth_particles) {
    if (isLep(truth_part)) { // switch to isLightLep for tau veto!
      bool from_W_higgs =
          isChildOfWFromHiggs(truth_part, parent_ids, truth_particles);
      if (from_W_higgs) {
        // counter+=1;
        leps_list.push_back(truth_part);
      }
    }
  }
  // std::cout << "Leps from tau-higgs " << counter << std::endl;
  return leps_list;
}

// find leptons (including taus?) that came from a H->ZZ decay
ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::getLepsFromZ(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids) {
  // test by simply counting first:
  //  int counter = 0;
  ROOT::VecOps::RVec<edm4hep::MCParticleData> leps_list;

  // loop over all truth particles and find light leptons from taus that came
  // from higgs (the direction tau->light lepton as child appears to be missing
  // in the tautau samples)
  for (auto &truth_part : truth_particles) {
    if (isLep(truth_part)) { // switch to isLightLep for tau veto!
      bool from_Z_higgs =
          isChildOfZFromHiggs(truth_part, parent_ids, truth_particles);
      if (from_Z_higgs) {
        // counter+=1;
        leps_list.push_back(truth_part);
      }
    }
  }
  // std::cout << "Leps from tau-higgs " << counter << std::endl;
  return leps_list;
}

// find photons that came from a H->yy decay
ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::getPhotonsFromH(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids) {
  ROOT::VecOps::RVec<edm4hep::MCParticleData> gamma_list;

  // loop over all truth particles and find stable photons that do not come
  // (directly) from a hadron decay
  for (auto &truth_part : truth_particles) {
    if (isStablePhoton(truth_part)) {
      bool from_higgs = hasHiggsParent(truth_part, parent_ids, truth_particles);
      if (isFromHadron(truth_part, parent_ids, truth_particles)) {
        from_higgs = false;
      }
      if (from_higgs) {
        gamma_list.push_back(truth_part);
      }
    }
  }
  // std::cout << "Leps from tau-higgs " << counter << std::endl;
  return gamma_list;
}

// momentum fraction x for tau decays
ROOT::VecOps::RVec<float> AnalysisFCChh::get_x_fraction(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> visible_particle,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET) {
  ROOT::VecOps::RVec<float> results_vec;

  if (visible_particle.size() < 1 || MET.size() < 1) {
    results_vec.push_back(-999.);
    return results_vec;
  }

  // get the components of the calculation
  TLorentzVector met_tlv = getTLV_reco(MET.at(0));
  // TLorentzVector met_tlv = getTLV_MET(MET.at(0));
  TLorentzVector vis_tlv = getTLV_reco(visible_particle.at(0));

  // float x_fraction = vis_tlv.Pt()/(vis_tlv.Pt()+met_tlv.Pt()); // try scalar
  // sum
  float x_fraction =
      vis_tlv.Pt() / (vis_tlv + met_tlv).Pt(); // vector sum makes more sense?

  // std::cout << " Debug m_col: pT_vis : " << vis_tlv.Pt() << std::endl;
  // std::cout << " Debug m_col: pT_miss : " << met_tlv.Pt() << std::endl;
  // std::cout << " Debug m_col: x with scalar sum: " << x_fraction <<
  // std::endl; std::cout << " Debug m_col: x with vector sum: " <<
  // vis_tlv.Pt()/(vis_tlv+met_tlv).Pt() << std::endl;

  results_vec.push_back(x_fraction);
  return results_vec;
}

// with truth variables
ROOT::VecOps::RVec<float> AnalysisFCChh::get_x_fraction_truth(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> visible_particle,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET) {
  ROOT::VecOps::RVec<float> results_vec;

  if (visible_particle.size() < 1 || MET.size() < 1) {
    results_vec.push_back(-999.);
    return results_vec;
  }

  // get the components of the calculation
  TLorentzVector met_tlv = getTLV_reco(MET.at(0));
  // TLorentzVector met_tlv = getTLV_MET(MET.at(0));
  TLorentzVector vis_tlv = getTLV_MC(visible_particle.at(0));

  // float x_fraction = vis_tlv.Pt()/(vis_tlv.Pt()+met_tlv.Pt()); // try scalar
  // sum
  float x_fraction =
      vis_tlv.Pt() / (vis_tlv + met_tlv).Pt(); // vector sum makes more sense?

  // std::cout << " Debug m_col: pT_vis truth : " << vis_tlv.Pt() << std::endl;
  // std::cout << " Debug m_col: pT_miss truth : " << met_tlv.Pt() << std::endl;
  // std::cout << " Debug m_col: x truth with vector sum: " << x_fraction <<
  // std::endl; std::cout << " Debug m_col: x with vector sum: " <<
  // vis_tlv.Pt()/(vis_tlv+met_tlv).Pt() << std::endl;

  results_vec.push_back(x_fraction);
  return results_vec;
}

ROOT::VecOps::RVec<float> AnalysisFCChh::get_mtautau_col(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> ll_pair_merged,
    ROOT::VecOps::RVec<float> x1, ROOT::VecOps::RVec<float> x2) {
  ROOT::VecOps::RVec<float> results_vec;

  // here there is no result if any of the arguments is actually not filled
  // (e.g. no selected pair) OR if one of the xs is 0 or negative (shouldnt
  // happen but better be on the safe side?)
  if (ll_pair_merged.size() < 1 || x1.size() < 1 || x2.size() < 1 ||
      x1.at(0) <= 0. || x2.at(0) <= 0.) {
    results_vec.push_back(-999.);
    return results_vec;
  }

  float mtautau_vis = getTLV_reco(ll_pair_merged.at(0))
                          .M(); // check against manual calculation??
  float mtautau_col = mtautau_vis / (sqrt(x1.at(0) * x2.at(0)));

  // std::cout << " Debug m_col: mtautau_vis mass = " << mtautau_vis <<
  // std::endl; std::cout << " Debug m_col: m_col mass = " << mtautau_col <<
  // std::endl;

  results_vec.push_back(mtautau_col);
  return results_vec;
}

// merge the invariant bb mass and the tautau colinear mass for the
// bbtautau(emu) analysis
ROOT::VecOps::RVec<float> AnalysisFCChh::get_mbbtautau_col(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> bb_pair_merged,
    ROOT::VecOps::RVec<float> mtautau_col) {
  ROOT::VecOps::RVec<float> results_vec;

  // here there is no result if any of the arguments is actually not filled or
  // if the mtautau col is at default value -999.
  if (bb_pair_merged.size() < 1 || mtautau_col.size() < 1 ||
      mtautau_col.at(0) <= 0.) {
    results_vec.push_back(-999.);
    return results_vec;
  }

  float mbb = getTLV_reco(bb_pair_merged.at(0)).M();

  results_vec.push_back(mbb + mtautau_col.at(0));
  return results_vec;
}

// truth matching: find a reco part that matches the truth part within cone of
// dR_thres
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::find_reco_matched(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_parts_to_match,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_parts_all,
    float dR_thres) {

  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> out_vector;

  // if no iput part, return nothing (didnt input correct event then)
  if (truth_parts_to_match.size() < 1) {
    return out_vector;
  }

  // currently only want one particle to match, to not get confused with
  // vectors:
  if (truth_parts_to_match.size() != 1) {
    std::cout << "Error! Found more than one truth part in input to "
                 "find_reco_matched() ! Not intended?"
              << std::endl;
    // return out_vector;
  }

  // take the TLV of that particle we want to match:
  TLorentzVector truth_part_tlv = getTLV_MC(truth_parts_to_match.at(0));

  // loop over all reco parts and find if there is one within the dr threshold
  // to the truth part
  for (auto &check_reco_part : reco_parts_all) {
    TLorentzVector check_reco_part_tlv = getTLV_reco(check_reco_part);
    float dR_val = truth_part_tlv.DeltaR(check_reco_part_tlv);

    if (dR_val <= dR_thres) {
      out_vector.push_back(check_reco_part);
    }

    check_reco_part_tlv.Clear();
  }

  return out_vector;
}

// manual implementation of the delphes isolation criterion
ROOT::VecOps::RVec<float> AnalysisFCChh::get_IP_delphes(
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> test_parts,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_parts_all,
    float dR_min, float pT_min, bool exclude_light_leps) {

  ROOT::VecOps::RVec<float> out_vector;

  if (test_parts.size() < 1) {
    return out_vector;
  }

  for (auto &test_part : test_parts) {
    // first get the pT of the test particle:
    TLorentzVector tlv_test_part = getTLV_reco(test_part);
    float pT_test_part = tlv_test_part.Pt();

    float sum_pT = 0;

    // loop over all other parts and sum up pTs if they are within the dR cone
    // and above min pT
    for (auto &reco_part : reco_parts_all) {

      // check type of particle first:
      //  std::cout << "PDG ID of particle:" << reco_part.m_particleIDUsed <<
      //  std::endl;

      // exclude electrons and muons

      TLorentzVector tlv_reco_part = getTLV_reco(reco_part);

      if (tlv_reco_part.Pt() > pT_min &&
          tlv_test_part.DeltaR(tlv_reco_part) < dR_min) {
        sum_pT += tlv_reco_part.Pt();
      }

      tlv_reco_part.Clear();
    }

    float IP_val = sum_pT / pT_test_part;

    out_vector.push_back(IP_val);
  }

  return out_vector;
}

// index navigation matching reco and MC particle to get pdg id of reco
// particle, following the ReconstructedParticle2MC::getRP2MC_pdg fuction in
// base FW
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::filter_lightLeps(
    ROOT::VecOps::RVec<int> recind, ROOT::VecOps::RVec<int> mcind,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> mc) {

  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> out_vector;

  for (auto &reco_index : recind) {

    std::cout << "Reco index:" << reco_index << std::endl;
    std::cout << "MC index:" << mcind.at(reco_index) << std::endl;

    // testing:
    auto pdg_id = mc.at(mcind.at(reco_index)).PDG;
    float mass = reco.at(reco_index).mass;

    std::cout << "MC PDG ID:" << pdg_id << std::endl;
    std::cout << "Reco mass:" << mass << std::endl;
  }

  return out_vector;
}

// muon mass: 0.105658
// electron mass: 0.000510999  ?

// find the neutrinos that originate from a W-decay (which comes from a higgs,
// and not a b-meson) using the truth info -> to use for truth MET
ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::getNusFromW(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids) {

  ROOT::VecOps::RVec<edm4hep::MCParticleData> nus_list;

  // loop over all truth particles and find neutrinos from Ws that came from
  // higgs (the direction tau->light lepton as child appears to be missing in
  // the tautau samples)
  for (auto &truth_part : truth_particles) {
    if (isNeutrino(truth_part)) {
      bool from_W_higgs =
          isChildOfWFromHiggs(truth_part, parent_ids, truth_particles);
      if (from_W_higgs) {
        // counter+=1;
        nus_list.push_back(truth_part);
      }
    }
  }
  // std::cout << "Leps from tau-higgs " << counter << std::endl;
  return nus_list;
}

// get truth met -> return as recoparticle so can use instead of reco met in
// other ftcs for some checks
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::getTruthMETObj(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids, TString type) {

  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> out_vector;

  ROOT::VecOps::RVec<edm4hep::MCParticleData> selected_nus;

  for (auto &truth_part : truth_particles) {
    if (isNeutrino(truth_part)) {

      // sum only the neutrinos from different higgs decays if requested
      if (type.Contains("hww_only") &&
          isChildOfWFromHiggs(truth_part, parent_ids, truth_particles)) {
        selected_nus.push_back(truth_part);
      }

      else if (type.Contains("htautau_only") &&
               isChildOfTauFromHiggs(truth_part, parent_ids, truth_particles)) {
        // std::cout << "getting truth MET from taus only" << std::endl;
        selected_nus.push_back(truth_part);
      }

      else if (type.Contains("hzz_only") &&
               isChildOfZFromHiggs(truth_part, parent_ids, truth_particles)) {
        selected_nus.push_back(truth_part);
      }

      else if (type.Contains("all_nu")) {
        selected_nus.push_back(truth_part);
      }
    }
  }

  // sum up
  TLorentzVector tlv_total;

  for (auto &nu : selected_nus) {
    TLorentzVector tlv_nu = getTLV_MC(nu);
    tlv_total += tlv_nu;
  }

  edm4hep::ReconstructedParticleData met_obj;
  met_obj.momentum.x = tlv_total.Px();
  met_obj.momentum.y = tlv_total.Py();
  met_obj.momentum.z = 0.;
  met_obj.mass = 0.;

  // std::cout << "Truth MET from building object: " <<
  // sqrt(met_obj.momentum.x*met_obj.momentum.x +
  // met_obj.momentum.y*met_obj.momentum.y) << std::endl;

  out_vector.push_back(met_obj);

  return out_vector;
}

// additonal code for validation of new delphes card:

// helper function to find dR matched mc particle for a single reco particle -
// returns vector of size 1 always, only the one that is closest in dR!
// (technically doesnt need to be vector at this stage ..)
ROOT::VecOps::RVec<edm4hep::MCParticleData>
AnalysisFCChh::find_mc_matched_particle(
    edm4hep::ReconstructedParticleData reco_part_to_match,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> check_mc_parts,
    float dR_thres) {

  ROOT::VecOps::RVec<edm4hep::MCParticleData> out_vector;

  TLorentzVector reco_part_tlv = getTLV_reco(reco_part_to_match);

  for (auto &check_mc_part : check_mc_parts) {
    TLorentzVector check_mc_part_tlv = getTLV_MC(check_mc_part);

    float dR_val = reco_part_tlv.DeltaR(check_mc_part_tlv);

    if (dR_val <= dR_thres) {

      // check if already sth in the vector - always want only exactly one
      // match!

      if (out_vector.size() > 0) {
        // check which one is closer
        float dR_val_old = reco_part_tlv.DeltaR(getTLV_MC(out_vector.at(0)));

        float pT_diff_old =
            abs(reco_part_tlv.Pt() - getTLV_MC(out_vector.at(0)).Pt());

        if (dR_val < dR_val_old) {
          out_vector.at(0) = check_mc_part;

          if (pT_diff_old < abs(reco_part_tlv.Pt() - check_mc_part_tlv.Pt())) {
            std::cout << "Found case where closest in pT is not closest in dR"
                      << std::endl;
          }
        }
      }

      else {
        out_vector.push_back(check_mc_part);
      }
    }

    check_mc_part_tlv.Clear();
  }

  return out_vector;
}

// helper function to find dR matched reco particle for a single truth particle
// - returns vector of size 1 always, only the one that is closest in dR!
// (technically doesnt need to be vector at this stage ..)
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::find_reco_matched_particle(
    edm4hep::MCParticleData truth_part_to_match,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> check_reco_parts,
    float dR_thres) {

  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> out_vector;

  TLorentzVector truth_part_tlv = getTLV_MC(truth_part_to_match);

  for (auto &check_reco_part : check_reco_parts) {
    TLorentzVector check_reco_part_tlv = getTLV_reco(check_reco_part);

    float dR_val = truth_part_tlv.DeltaR(check_reco_part_tlv);

    if (dR_val <= dR_thres) {

      // check if already sth in the vector - always want only exactly one
      // match!

      if (out_vector.size() > 0) {
        // check which one is closer
        float dR_val_old = truth_part_tlv.DeltaR(getTLV_reco(out_vector.at(0)));

        float pT_diff_old =
            abs(truth_part_tlv.Pt() - getTLV_reco(out_vector.at(0)).Pt());

        if (dR_val < dR_val_old) {
          out_vector.at(0) = check_reco_part;

          if (pT_diff_old <
              abs(truth_part_tlv.Pt() - check_reco_part_tlv.Pt())) {
            std::cout << "Found case where closest in pT is not closest in dR"
                      << std::endl;
          }
        }
      }

      else {
        out_vector.push_back(check_reco_part);
      }
    }

    check_reco_part_tlv.Clear();
  }

  return out_vector;
}

// same as above but returns the index of the matched particle instead
ROOT::VecOps::RVec<int> AnalysisFCChh::find_reco_matched_index(
    edm4hep::MCParticleData truth_part_to_match,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> check_reco_parts,
    float dR_thres) {

  ROOT::VecOps::RVec<int> out_vector;

  TLorentzVector truth_part_tlv = getTLV_MC(truth_part_to_match);

  for (int i = 0; i < check_reco_parts.size(); ++i) {

    edm4hep::ReconstructedParticleData check_reco_part = check_reco_parts[i];

    TLorentzVector check_reco_part_tlv = getTLV_reco(check_reco_part);

    float dR_val = truth_part_tlv.DeltaR(check_reco_part_tlv);

    if (dR_val <= dR_thres) {

      // check if already sth in the vector - always want only exactly one
      // match!

      if (out_vector.size() > 0) {
        // check which one is closer
        edm4hep::ReconstructedParticleData match_old =
            check_reco_parts[out_vector[0]]; // edit this to be TLV directly

        float dR_val_old = truth_part_tlv.DeltaR(getTLV_reco(match_old));

        float pT_diff_old =
            abs(truth_part_tlv.Pt() - getTLV_reco(match_old).Pt());

        if (dR_val < dR_val_old) {
          out_vector.at(0) = i;

          if (pT_diff_old <
              abs(truth_part_tlv.Pt() - check_reco_part_tlv.Pt())) {
            std::cout << "Found case where closest in pT is not closest in dR"
                      << std::endl;
          }
        }
      }

      else {
        out_vector.push_back(i);
      }
    }

    check_reco_part_tlv.Clear();
  }

  return out_vector;
}

// truth -> reco matching for a vector of generic truth particles - this doesnt
// check if the type of particles are the same! -> make sure you give the
// correct collections!
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::find_reco_matches(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_parts,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_particles,
    float dR_thres) {

  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> out_vector;

  // if no input part, return nothing
  if (truth_parts.size() < 1) {
    return out_vector;
  }

  for (auto &truth_part : truth_parts) {

    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_match_vector =
        find_reco_matched_particle(truth_part, reco_particles, dR_thres);

    if (reco_match_vector.size() > 1) {
      std::cout << "Warning in AnalysisFCChh::find_reco_matches() - Truth "
                   "particle matched to more than one reco particle."
                << std::endl;
    }

    // check that the reco particle is not already in the out_vector
    bool isAlready = false;
    for (auto &out_i : out_vector) {
      if ((getTLV_reco(reco_match_vector[0]).Pt() == getTLV_reco(out_i).Pt()) &&
          (getTLV_reco(reco_match_vector[0]).Eta() ==
           getTLV_reco(out_i).Eta())) {
        isAlready = true;
        // std::cout<<"Already in the array"<<std::endl;
      }
    }
    if (!isAlready) {
      out_vector.append(reco_match_vector.begin(), reco_match_vector.end());
    }
  }

  return out_vector;
}

// for testing: same as above, but not removing already matched reco objects,
// allowing double match
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::find_reco_matches_no_remove(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_parts,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_particles,
    float dR_thres) {

  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> out_vector;

  // if no input part, return nothing
  if (truth_parts.size() < 1) {
    return out_vector;
  }

  for (auto &truth_part : truth_parts) {

    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_match_vector =
        find_reco_matched_particle(truth_part, reco_particles, dR_thres);

    if (reco_match_vector.size() > 1) {
      std::cout << "Warning in AnalysisFCChh::find_reco_matches() - Truth "
                   "particle matched to more than one reco particle."
                << std::endl;
    }

    out_vector.append(reco_match_vector.begin(), reco_match_vector.end());
  }

  return out_vector;
}

// variation of the previous function, with the addition of a set of MC
// particles that must not match with the reco ones!
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::find_reco_matches_exclusive(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_parts,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_parts_exc,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_particles,
    float dR_thres) {

  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> out_vector;

  // if no input part, return nothing
  if (truth_parts.size() < 1) {
    return out_vector;
  }

  if (truth_parts_exc.size() < 1) {
    // std::cout<<"Use find_reco_matches!"<<std::endl;
    return out_vector;
  }

  for (auto &truth_part : truth_parts) {
    bool excludedMatch = false;
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_match_vector =
        find_reco_matched_particle(truth_part, reco_particles, dR_thres);
    ROOT::VecOps::RVec<edm4hep::MCParticleData> mc_excluded_vector =
        find_mc_matched_particle(reco_match_vector[0], truth_parts_exc, 1.0);
    if (mc_excluded_vector.size() > 0) {
      std::cout << "Excluded MC particle found matching with reco obj!"
                << std::endl;
      continue;
    }
    // if (reco_match_vector.size() > 1){
    //	std::cout << "Warning in AnalysisFCChh::find_reco_matches() - Truth
    // particle matched to more than one reco particle." << std::endl;
    // }

    // check that the reco particle is not already in the out_vector
    bool isAlready = false;
    for (auto &out_i : out_vector) {
      if ((getTLV_reco(reco_match_vector[0]).Pt() == getTLV_reco(out_i).Pt()) &&
          (getTLV_reco(reco_match_vector[0]).Eta() ==
           getTLV_reco(out_i).Eta())) {
        isAlready = true;
        // std::cout<<"Already in the array"<<std::endl;
      }
    }
    if (!isAlready) {
      out_vector.append(reco_match_vector.begin(), reco_match_vector.end());
    }
  }

  return out_vector;
}

ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::find_truth_matches(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_parts,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_particles,
    float dR_thres) {

  ROOT::VecOps::RVec<edm4hep::MCParticleData> out_vector;

  // if no input part, return nothing
  if (truth_parts.size() < 1) {
    return out_vector;
  }

  for (auto &truth_part : truth_parts) {

    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_match_vector =
        find_reco_matched_particle(truth_part, reco_particles, dR_thres);

    if (reco_match_vector.size() > 1) {
      std::cout << "Warning in AnalysisFCChh::find_reco_matches() - Truth "
                   "particle matched to more than one reco particle."
                << std::endl;
    }

    if (reco_match_vector.size() == 1) {
      out_vector.push_back(truth_part);
    }
    // out_vector.append(reco_match_vector.begin(), reco_match_vector.end());
  }

  return out_vector;
}

// same as above just with indices
ROOT::VecOps::RVec<int> AnalysisFCChh::find_reco_match_indices(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_parts,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_particles,
    float dR_thres) {

  ROOT::VecOps::RVec<int> out_vector;

  // if no input part, return nothing
  if (truth_parts.size() < 1) {
    return out_vector;
  }

  for (auto &truth_part : truth_parts) {

    ROOT::VecOps::RVec<int> reco_match_vector =
        find_reco_matched_index(truth_part, reco_particles, dR_thres);

    if (reco_match_vector.size() > 1) {
      std::cout << "Warning in AnalysisFCChh::find_reco_matches() - Truth "
                   "particle matched to more than one reco particle."
                << std::endl;
    }

    out_vector.append(reco_match_vector.begin(), reco_match_vector.end());
  }

  return out_vector;
}

// truth matching: take as input the truth leptons from e.g. HWW decay and check
// if they have a reco match within dR cone - Note: skip taus!
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::find_true_signal_leps_reco_matches(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_leps_to_match,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_electrons,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_muons,
    float dR_thres) {

  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> out_vector;

  // if no input part, return nothing
  if (truth_leps_to_match.size() < 1) {
    return out_vector;
  }

  // check the flavour of the input truth particle, if it is a tau we skip it
  for (auto &truth_lep : truth_leps_to_match) {

    if (!isLightLep(truth_lep)) {
      // std::cout << "Info: Problem in
      // AnalysisFCChh::find_true_signal_leps_reco_matches() - Found truth tau
      // (or other non light lepton) in attempt to match to reco, skipping." <<
      // std::endl;
      continue;
    }

    // TLorentzVector truth_part_tlv = getTLV_MC(truth_lep);

    // truth particle should thus be either an electron or a muon:

    // checking electrons:
    if (abs(truth_lep.PDG) == 11) {

      ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> ele_match_vector =
          find_reco_matched_particle(truth_lep, reco_electrons, dR_thres);

      // warning if match to more than one particle:
      if (ele_match_vector.size() > 1) {
        std::cout
            << "Warning in AnalysisFCChh::find_true_signal_leps_reco_matches() "
               "- Truth electron matched to more than one reco electron."
            << std::endl;
        std::cout << "Truth electron has pT = " << getTLV_MC(truth_lep).Pt()
                  << " charge = " << truth_lep.charge
                  << " pdg = " << truth_lep.PDG << std::endl;
        // check the pTs of them:
        for (auto &matched_ele : ele_match_vector) {
          std::cout << "Matched electron with pT = "
                    << getTLV_reco(matched_ele).Pt()
                    << " charge = " << matched_ele.charge
                    << " dR distance to truth = "
                    << getTLV_MC(truth_lep).DeltaR(getTLV_reco(matched_ele))
                    << std::endl;
        }
      }

      out_vector.append(ele_match_vector.begin(), ele_match_vector.end());

    }

    // checking muons:
    else if (abs(truth_lep.PDG) == 13) {

      ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> mu_match_vector =
          find_reco_matched_particle(truth_lep, reco_muons, dR_thres);

      // warning if match to more than one particle:
      if (mu_match_vector.size() > 1) {
        std::cout
            << "Warning in AnalysisFCChh::find_true_signal_leps_reco_matches() "
               "- Truth muon matched to more than one reco muon."
            << std::endl;
        std::cout << "Truth muon has pT = " << getTLV_MC(truth_lep).Pt()
                  << " charge = " << truth_lep.charge
                  << " pdg = " << truth_lep.PDG << std::endl;

        // check the pTs of them:
        for (auto &matched_mu : mu_match_vector) {
          std::cout << "Matched muon with pT = " << getTLV_reco(matched_mu).Pt()
                    << " charge = " << matched_mu.charge
                    << "dR distance to truth = "
                    << getTLV_MC(truth_lep).DeltaR(getTLV_reco(matched_mu))
                    << std::endl;
        }
      }

      out_vector.append(mu_match_vector.begin(), mu_match_vector.end());
    }
  }

  return out_vector;
}

// find the indices of reco matched particles, assume here that pdg id filtering
// of the input mc particles is already done and only the matching reco
// collection is passed
ROOT::VecOps::RVec<int> AnalysisFCChh::find_truth_to_reco_matches_indices(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_leps_to_match,
    ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> reco_parts,
    int pdg_ID, float dR_thres) {

  ROOT::VecOps::RVec<int> out_vector;

  // if no input part, return nothing
  if (truth_leps_to_match.size() < 1) {
    return out_vector;
  }

  // check the flavour of the input truth particle, if it is a tau we skip it
  for (auto &truth_lep : truth_leps_to_match) {

    // std::cout << "Matching truth particle with pdgID: " << abs(truth_lep.PDG)
    // << std::endl;

    // match only a certain requested type of particle
    if (abs(truth_lep.PDG) != pdg_ID) {
      // std::cout << "Skipping" << std::endl;
      continue;
    }

    // std::cout << "Running the match" << std::endl;

    ROOT::VecOps::RVec<int> reco_match_indices_vector =
        find_reco_matched_index(truth_lep, reco_parts, dR_thres);

    if (reco_match_indices_vector.size() > 1) {
      std::cout
          << "Warning in AnalysisFCChh::find_truth_to_reco_matches_indices() - "
             "Truth particle matched to more than one reco particle."
          << std::endl;
    }

    out_vector.append(reco_match_indices_vector.begin(),
                      reco_match_indices_vector.end());
  }

  return out_vector;
}

// try to get the isoVar when its filled as a usercollection
//  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
//  AnalysisFCChh::get_isoVar(ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
//  reco_parts_to_check, ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
//  all_reco_parts){
//  	// first check the index of the particle we want to get the iso var for

// 	ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> out_vector;

// 	for (auto & reco_check_part : reco_parts_to_check){
// 		std::cout << "index of the particle is:" <<
// reco_check_part.index << std::endl;

// 	}

// 	return out_vector;

// }


/* functions for the HHH analysis */
// now compute sigma parameters for Dalitz analysis
ROOT::VecOps::RVec<float> AnalysisFCChh::compute_sigma(
  TLorentzVector higgs_1,
  TLorentzVector higgs_2,
  TLorentzVector higgs_3
)
{
  // we have three combinations of higgs to compute sigma
  ROOT::VecOps::RVec<float> sigma;

  /*
    sigma_ij = (s_ij - 4mh^2)/(m_hhh^2 - 9m_h^2)
  */

  float s_12 = (higgs_1 + higgs_2).M2();
  float s_13 = (higgs_1 + higgs_3).M2();
  float s_23 = (higgs_2 + higgs_3).M2();

  float m_hhh2 = (higgs_1 + higgs_2 + higgs_3).M2();

  float m_h2 = 125 * 125;
  
  float sigma_12 = (s_12 - 4*m_h2)/(m_hhh2 - 9*m_h2);
  float sigma_23 = (s_23 - 4*m_h2)/(m_hhh2 - 9*m_h2);
  float sigma_13 = (s_13 - 4*m_h2)/(m_hhh2 - 9*m_h2);

  sigma.push_back(sigma_12); 
  sigma.push_back(sigma_23);
  sigma.push_back(sigma_13);

  return sigma;

}

// reco-matches

ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::find_reco_matches_unique(
    const ROOT::VecOps::RVec<edm4hep::MCParticleData>& truth_parts,
    const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& reco_particles,
    float dR_thres)
{
  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> out;
  if (truth_parts.empty() || reco_particles.empty()) return out;

  out.reserve(std::min(truth_parts.size(), reco_particles.size()));

  // Track which reco indices are already used
  std::vector<bool> reco_used(reco_particles.size(), false);

  // Precompute TLVs for speed
  std::vector<TLorentzVector> tlv_truth; tlv_truth.reserve(truth_parts.size());
  for (const auto& t : truth_parts) tlv_truth.emplace_back(getTLV_MC(t));
  std::vector<TLorentzVector> tlv_reco; tlv_reco.reserve(reco_particles.size());
  for (const auto& r : reco_particles) tlv_reco.emplace_back(getTLV_reco(r));

  // For each truth, grab the nearest available reco within dR_thres
  for (size_t it = 0; it < truth_parts.size(); ++it) {
    std::vector<TLorentzVector> tlv_truth;
    tlv_truth.reserve(truth_parts.size());
    for (const auto& t : truth_parts) {
      tlv_truth.emplace_back(getTLV_MC(t));
    }

    std::vector<TLorentzVector> tlv_reco;
    tlv_reco.reserve(reco_particles.size());
    for (const auto& r : reco_particles) {
      tlv_reco.emplace_back(getTLV_reco(r));
    }

    for (size_t it = 0; it < truth_parts.size(); ++it) {
      const auto& tv = tlv_truth[it];
      double best_dR = 999.0;
      int best_ir = -1;
      for (size_t ir = 0; ir < reco_particles.size(); ++ir) {
        if (reco_used[ir]) continue;
        double dR = tv.DeltaR(tlv_reco[ir]); 
        if (dR < best_dR) {
          best_dR = dR;
          best_ir = ir;
        }
      }
      if (best_ir >= 0 && best_dR < dR_thres) {
        reco_used[best_ir] = true;
        out.emplace_back(reco_particles[best_ir]);
      }
    }
    
  }

  return out;
}

// Return b-tagged jets that are NOT tau-tagged
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::get_btagged_not_tau_tagged(
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
) {
  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> out;
  const size_t n_jets = jets.size();
  if (n_jets == 0 || btagIndex < 0) return out;

  const unsigned bmask = 1u << btagIndex;
  const unsigned taumask = tauIndex >= 0 ? (1u << tauIndex) : 0u;

  std::vector<unsigned char> tau_veto(n_jets, 0);
  const size_t n_tau_tags = std::min(jets_tau_tags.size(),
                                     jets_tau_tags_indices.size());
  for (size_t i = 0; i < n_tau_tags; ++i) {
    const int jet_index = jets_tau_tags_indices[i].index;
    if (jet_index < 0 || static_cast<size_t>(jet_index) >= n_jets) continue;

    const int value_index = jets_tau_tags[i].parameters_begin;
    if (value_index < 0 ||
        static_cast<size_t>(value_index) >= jets_tau_tag_values.size()) continue;

    const unsigned bits =
        static_cast<unsigned>(std::lrint(jets_tau_tag_values[value_index]));
    const bool is_tau = tauIndex >= 0 ? (bits & taumask) != 0u : bits != 0u;
    if (is_tau) {
      tau_veto[static_cast<size_t>(jet_index)] = 1;
    }
  }

  std::vector<unsigned char> added(n_jets, 0);
  out.reserve(n_jets);
  const size_t n_hf_tags = std::min(jets_HF_tags.size(),
                                    jets_HF_tags_indices.size());
  for (size_t i = 0; i < n_hf_tags; ++i) {
    const int jet_index = jets_HF_tags_indices[i].index;
    if (jet_index < 0 || static_cast<size_t>(jet_index) >= n_jets) continue;

    const size_t jet_i = static_cast<size_t>(jet_index);
    if (tau_veto[jet_i] || added[jet_i]) continue;

    const int value_index = jets_HF_tags[i].parameters_begin;
    if (value_index < 0 ||
        static_cast<size_t>(value_index) >= jets_HF_tag_values.size()) continue;

    const unsigned bits =
        static_cast<unsigned>(std::lrint(jets_HF_tag_values[value_index]));
    if (bits & bmask) {
      out.push_back(jets[jet_i]);
      added[jet_i] = 1;
    }
  }

  return out;
}


// Keep particles with isoVar >= thr (i.e. "non-isolated" by isoVar)
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::sel_by_iso_fail(const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& parts,
                               const ROOT::VecOps::RVec<float>& isoVar,
                               float thr)
{
  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> out;
  const auto n = parts.size();
  if (isoVar.size() != n) return out; // size guard
  out.reserve(n);
  for (size_t i = 0; i < n; ++i)
    if (isoVar[i] >= thr) out.push_back(parts[i]);
  return out;
}

ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::getTruthTauLeps(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids, TString type) {

  ROOT::VecOps::RVec<edm4hep::MCParticleData> tau_list;
  bool flagchildren = false;
  for (auto &truth_part : truth_particles) {
    flagchildren = false;
    if (isTau(truth_part)) {

      // check also if from Higgs to count only from Higgs ones
      if (type.Contains("from_higgs") &&
          !isFromHiggsDirect(
              truth_part, parent_ids,
              truth_particles)) { //&& isFromHadron(truth_part, parent_ids,
                                  // truth_particles) ) {
        continue;
      }
      if (type.Contains("from_Z") && !hasZParent(truth_part, parent_ids, truth_particles)) {
        continue;
      }
      // select both from higgs or from hadrons
      if (type.Contains("higgshad") &&
          !isFromHiggsDirect(truth_part, parent_ids, truth_particles) &&
          !isFromHadron(truth_part, parent_ids, truth_particles)) {
        // continue;
        std::cout << " found tau neither from Higgs or from Had" << std::endl;
        auto first_parent_index = truth_part.parents_begin;
        auto last_parent_index = truth_part.parents_end;
        for (int parent_i = first_parent_index; parent_i < last_parent_index;
             parent_i++) {
          auto parent_MC_index = parent_ids.at(parent_i).index;
          auto parent = truth_particles.at(parent_MC_index);
          std::cout << "Parent PDG:" << std::endl;
          std::cout << parent.PDG << std::endl;
        }
        continue;
      }
      bool isItself = true;
      while (isItself) {
        auto first_child_index = truth_part.daughters_begin;
        auto last_child_index = truth_part.daughters_end;
        // auto child_1_MC_index = daughter_ids.at(first_child_index).index;
        // auto hild_2_MC_index = daughter_ids.at(last_child_index-1).index;
        for (int child_i = first_child_index; child_i < last_child_index;
             child_i++) {
          auto child = truth_particles.at(daughter_ids.at(child_i).index);
          if (abs(child.PDG) == 15) {
            isItself = true;
            truth_part = child;
            break;
          } else {
            isItself = false;
          }
        }
      }

      // std::cout << " found tau with children" << std::endl;
      auto first_child_index = truth_part.daughters_begin;
      auto last_child_index = truth_part.daughters_end;
      for (int ch_i = first_child_index; ch_i < last_child_index; ch_i++) {
        auto ch = truth_particles.at(daughter_ids.at(ch_i).index);
        std::cout << "Child ID: " << ch.PDG << std::endl;
        if (isLep(ch)) {
          std::cout << " Is leptonic" << std::endl;
          flagchildren = true;
          break;
        }
      }
      if (flagchildren) {
        tau_list.push_back(truth_part);
      }
    }
  }

  return tau_list;
}


ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::getTruthTauEmu(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids, TString type) {

  ROOT::VecOps::RVec<edm4hep::MCParticleData> tau_list;
  bool flagchildren = false;
  for (auto &truth_part : truth_particles) {
    flagchildren = false;
    if (isTau(truth_part)) {

      // check also if from Higgs to count only from Higgs ones
      if (type.Contains("from_higgs") &&
          !isFromHiggsDirect(
              truth_part, parent_ids,
              truth_particles)) { //&& isFromHadron(truth_part, parent_ids,
                                  // truth_particles) ) {
        continue;
      }
      // select both from higgs or from hadrons
      if (type.Contains("higgshad") &&
          !isFromHiggsDirect(truth_part, parent_ids, truth_particles) &&
          !isFromHadron(truth_part, parent_ids, truth_particles)) {
        // continue;
        std::cout << " found tau neither from Higgs or from Had" << std::endl;
        auto first_parent_index = truth_part.parents_begin;
        auto last_parent_index = truth_part.parents_end;
        for (int parent_i = first_parent_index; parent_i < last_parent_index;
             parent_i++) {
          auto parent_MC_index = parent_ids.at(parent_i).index;
          auto parent = truth_particles.at(parent_MC_index);
          std::cout << "Parent PDG:" << std::endl;
          std::cout << parent.PDG << std::endl;
        }
        continue;
      }

      // select both from higgs or from hadrons
      if (type.Contains("hadonly") &&
          !isFromHadron(truth_part, parent_ids, truth_particles)) {
        // continue;
        std::cout << " found tau neither from Higgs or from Had" << std::endl;
        auto first_parent_index = truth_part.parents_begin;
        auto last_parent_index = truth_part.parents_end;
        for (int parent_i = first_parent_index; parent_i < last_parent_index;
             parent_i++) {
          auto parent_MC_index = parent_ids.at(parent_i).index;
          auto parent = truth_particles.at(parent_MC_index);
          std::cout << "Parent PDG:" << std::endl;
          std::cout << parent.PDG << std::endl;
        }
        continue;
      }
      bool isItself = true;
      while (isItself) {
        auto first_child_index = truth_part.daughters_begin;
        auto last_child_index = truth_part.daughters_end;
        // auto child_1_MC_index = daughter_ids.at(first_child_index).index;
        // auto hild_2_MC_index = daughter_ids.at(last_child_index-1).index;
        for (int child_i = first_child_index; child_i < last_child_index;
             child_i++) {
          auto child = truth_particles.at(daughter_ids.at(child_i).index);
          if (abs(child.PDG) == 15) {
            isItself = true;
            truth_part = child;
            break;
          } else {
            isItself = false;
          }
        }
      }
      edm4hep::MCParticleData tau_child{};  // NEW

      // std::cout << " found tau with children" << std::endl;
      auto first_child_index = truth_part.daughters_begin;
      auto last_child_index = truth_part.daughters_end;
      for (int ch_i = first_child_index; ch_i < last_child_index; ch_i++) {
        auto ch = truth_particles.at(daughter_ids.at(ch_i).index);
        std::cout << "Child ID: " << ch.PDG << std::endl;
        if (type.Contains("mu") && isMuon(ch)){
          flagchildren = true;
          tau_child = ch;

          break;
        } else {
            if ((type.Contains("el") && isElectron(ch))) {
              flagchildren = true;
              tau_child = ch;
              break;
            if ((type.Contains("mu") && isMuon(ch))) {
              flagchildren = true;
              tau_child = ch;
              break;

            }
        }
      }
        
        
      }
      if (flagchildren) {
        tau_list.push_back(tau_child);
      }
    }
  }

  return tau_list;
}


// Return tuple of 5 RVecs: (pT_vis, pT_mis, n_charged, n_neutral, m_vis)
std::tuple<
  ROOT::VecOps::RVec<TLorentzVector>,  // p_vis
  ROOT::VecOps::RVec<TLorentzVector>,  // p_mis
  ROOT::VecOps::RVec<int>,             // n_charged
  ROOT::VecOps::RVec<int>,             // n_neutral
  ROOT::VecOps::RVec<float>,            // m_vis
  ROOT::VecOps::RVec<float>,            // m_mis
  ROOT::VecOps::RVec<int>               // n_neutrinos
>
AnalysisFCChh::getTruthTauHadronic(
    const ROOT::VecOps::RVec<edm4hep::MCParticleData>& truth_particles,
    const ROOT::VecOps::RVec<podio::ObjectID>& daughter_ids,
    const ROOT::VecOps::RVec<podio::ObjectID>& parent_ids,
    TString type)
{
  ROOT::VecOps::RVec<TLorentzVector> p_vis_list;
  ROOT::VecOps::RVec<TLorentzVector> p_mis_list;
  ROOT::VecOps::RVec<int> n_charged_list;
  ROOT::VecOps::RVec<int> n_neutral_list;
  ROOT::VecOps::RVec<float> m_vis_list;
  ROOT::VecOps::RVec<float> m_mis_list;
  ROOT::VecOps::RVec<float> n_neutrinos_list;

  for (auto& truth_part : truth_particles) {
    if (!isTau(truth_part)) continue;

    // Parent-type filters
    if (type.Contains("from_higgs") && !isFromHiggsDirect(truth_part, parent_ids, truth_particles))
      {
        continue;
      }

    if (type.Contains("from_Z") && !hasZParent(truth_part, parent_ids, truth_particles)) {
      continue;
    }

    if (type.Contains("higgshad") && !isFromHiggsDirect(truth_part, parent_ids, truth_particles) && !isFromHadron(truth_part, parent_ids, truth_particles)) {
      continue;
    }

    // Descend to final tau (last one in decay chain)
    auto tau = truth_part;
    bool descend = true;
    while (descend) {
      descend = false;
      for (int i = tau.daughters_begin; i < tau.daughters_end; i++) {
        auto child = truth_particles.at(daughter_ids.at(i).index);
        if (std::abs(child.PDG) == 15) {
          tau = child;
          descend = true;
          break;
        }
      }
    }

    // Build visible and invisible 4-vectors
    TLorentzVector p_vis(0, 0, 0, 0);
    TLorentzVector p_mis(0, 0, 0, 0);
    int n_charged = 0, n_neutral = 0;
    int n_neutrinos = 0;
    for (int i = tau.daughters_begin; i < tau.daughters_end; i++) {
      auto child = truth_particles.at(daughter_ids.at(i).index);
      if (isTau(child)) {
        std::cout << "skipping if we find another tau" << std::endl;
        continue;
      }
      TLorentzVector p4 = getTLV_MC(child);

      if (isNeutrino(child)) {
        p_mis += p4;
        n_neutrinos++;
      } else {
        p_vis += p4;
        if (!isLightLep(child)) {
          if (std::abs(child.charge) > 0) {
            n_charged++;
          }
          else if (child.charge == 0) {
            n_neutral++;
          }
          else {
            std::cout << "Child is non-existent?" << std::endl;
          }
        }
      }
    }

    // Store results
    p_vis_list.push_back(p_vis);
    p_mis_list.push_back(p_mis);
    n_charged_list.push_back(n_charged);
    n_neutral_list.push_back(n_neutral);
    n_neutrinos_list.push_back(n_neutrinos);
    float m_vis = p_vis.M();
    
    if (m_vis > 0) {
      m_vis_list.push_back(p_vis.M());
    } else {
      m_vis_list.push_back(-9);
    }

    // also for the lep-had cases
    float m_mis = p_mis.M();
    
    if (n_neutrinos != 1) {
      if (m_mis > 0) {
        m_mis_list.push_back(p_mis.M());
      } else {
        std::cout << " why are we having a mass less than 0? Mass: " << m_mis << std::endl;
        m_mis_list.push_back(-9);
      }
    } 
    // debugging check that we have a tau genuinely, and have obtained all decay products appropriately
    TLorentzVector tau_tlv = p_vis + p_mis;
    std::cout << "Mass of the tau " << tau_tlv.M() << " matches the tau? " << std::endl;
     
  }
  return std::make_tuple(p_vis_list, p_mis_list, n_charged_list, n_neutral_list, m_vis_list, m_mis_list, n_neutrinos_list);
}


// for isolation
ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>
AnalysisFCChh::select_with_mask(const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& objs,
                   const ROOT::VecOps::RVec<char>& mask) {
  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> out;
  out.reserve(objs.size());
  for (size_t i = 0; i < objs.size(); ++i) {
    if (mask[i]) out.push_back(objs[i]);
  }
  return out;
}

// function which finds truth higgs in the MC particles and selects the one that
// decays according to requested type (to ZZ or bb here)
std::pair<
  ROOT::VecOps::RVec<edm4hep::MCParticleData>,
  ROOT::VecOps::RVec<std::pair<edm4hep::MCParticleData, edm4hep::MCParticleData>>
>
AnalysisFCChh::get_truth_Higgs(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
    TString decay)
{
  using namespace ROOT::VecOps;

  // Helper lambdas
  auto pt = [](const edm4hep::MCParticleData& p) {
    return std::hypot(p.momentum.x, p.momentum.y);
  };

  enum class Cat { BB, TAUTAU, OTHER };

  struct HiggsCand {
    edm4hep::MCParticleData H;
    edm4hep::MCParticleData d1; // pt-ordered
    edm4hep::MCParticleData d2; // pt-ordered
    Cat cat;
  };

  RVec<HiggsCand> cands;
  cands.reserve(8);

  // ---------------------------
  // Collect all Higgs with 2 daughters (store daughter pair regardless of type)
  // ---------------------------
  for (auto &truth_part : truth_particles) {
    if (!isH(truth_part)) continue;

    const auto first_child_index = truth_part.daughters_begin;
    const auto last_child_index  = truth_part.daughters_end;
    if (last_child_index - first_child_index != 2) continue;

    const auto child_1_MC_index = daughter_ids.at(first_child_index).index;
    const auto child_2_MC_index = daughter_ids.at(last_child_index - 1).index;

    auto child_1 = truth_particles.at(child_1_MC_index);
    auto child_2 = truth_particles.at(child_2_MC_index);

    // pt-order decay products
    if (pt(child_2) > pt(child_1)) std::swap(child_1, child_2);

    Cat cat = Cat::OTHER;
    if (isb(child_1) && isb(child_2)) {
      cat = Cat::BB;
    } else if (isTau(child_1) && isTau(child_2)) {
      cat = Cat::TAUTAU;
    }

    cands.push_back({truth_part, child_1, child_2, cat});
  }

  // Sort candidates by Higgs pT (descending) via indices
  auto sort_by_Hpt = [&](const auto &a, const auto &b) { return pt(a.H) > pt(b.H); };
  auto all_idx = Argsort(cands, sort_by_Hpt);

  // Separate indices by category, already in pT order
  RVec<size_t> bb_idx, tautau_idx, other_idx;
  bb_idx.reserve(all_idx.size());
  tautau_idx.reserve(all_idx.size());
  other_idx.reserve(all_idx.size());

  for (auto i : all_idx) {
    if      (cands[i].cat == Cat::BB)     bb_idx.push_back(i);
    else if (cands[i].cat == Cat::TAUTAU) tautau_idx.push_back(i);
    else                                  other_idx.push_back(i);
  }

  // ---------------------------
  // Selection:
  //   - take up to 2 H->bb (leading pT)
  //   - take 3rd Higgs: prefer leading H->tautau, else leading remaining Higgs of any type
  // ---------------------------
  RVec<edm4hep::MCParticleData> selected_higgs;
  RVec<std::pair<edm4hep::MCParticleData, edm4hep::MCParticleData>> selected_pairs;

  selected_higgs.reserve(3);
  selected_pairs.reserve(3);

  // Track used indices to avoid duplicates
  auto used = RVec<char>(cands.size(), 0);

  for (size_t k = 0; k < std::min<size_t>(2, bb_idx.size()); ++k) {
    const auto i = bb_idx[k];
    used[i] = 1;
    selected_higgs.push_back(cands[i].H);
    selected_pairs.emplace_back(cands[i].d1, cands[i].d2);
  }

  auto push_if_unused = [&](size_t i) {
    if (i >= used.size() || used[i]) return false;
    used[i] = 1;
    selected_higgs.push_back(cands[i].H);
    selected_pairs.emplace_back(cands[i].d1, cands[i].d2);
    return true;
  };

  // Third Higgs: prefer tautau
  bool got_third = false;
  if (!tautau_idx.empty()) {
    got_third = push_if_unused(tautau_idx[0]);
  }

  // Otherwise: take highest-pT remaining Higgs of any category
  if (!got_third) {
    for (auto i : all_idx) {
      if (push_if_unused(i)) { got_third = true; break; }
    }
  }

  return {selected_higgs, selected_pairs};
}


ROOT::VecOps::RVec<edm4hep::MCParticleData>
AnalysisFCChh::SortMCByPt(const ROOT::VecOps::RVec<edm4hep::MCParticleData>& in) {
  auto out = in;
  std::stable_sort(out.begin(), out.end(),
                   [](const edm4hep::MCParticleData& a,
                      const edm4hep::MCParticleData& b){
                     return getTLV_MC(a).Pt() > getTLV_MC(b).Pt();
                   });
  return out;
}

ROOT::VecOps::RVec<edm4hep::MCParticleData>
AnalysisFCChh::getBhadron_final_fromH(
    const ROOT::VecOps::RVec<edm4hep::MCParticleData>& truth_particles,
    const ROOT::VecOps::RVec<podio::ObjectID>& parent_ids,
    const ROOT::VecOps::RVec<podio::ObjectID>& daughter_ids,
    float ptMin) {

  ROOT::VecOps::RVec<edm4hep::MCParticleData> out;
  out.reserve(truth_particles.size()/50); // heuristic

  for (const auto& p : truth_particles) {
    const int pdgabs = std::abs(p.PDG);
    if (!isBHadronPDG(pdgabs)) continue;

    // ancestor must include a Higgs (recursive)
    if (!hasHiggsParent(p, parent_ids, truth_particles)) continue;

    // keep only "final" B hadrons (no B-hadron in daughters)
    if (hasBHadronDaughter(p, daughter_ids, truth_particles)) continue;

    // optional pT threshold
    const float pt = std::hypot(p.momentum.x, p.momentum.y);
    if (pt < ptMin) continue;

    out.emplace_back(p);
  }
  return out;
}

// check if we have overlappig bs / taus
bool AnalysisFCChh::isSignalContaminated(
  ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_b_hadrons,
  ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_taus,
  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> selected_jets,
  float dR_truth
)
{
  bool isContam = false;

  for (auto jet : selected_jets) {
    TLorentzVector jet_tlv = getTLV_reco(jet);
    // now loop over both sets of truth particles, make TLVs and look at separations
    for (auto b : truth_b_hadrons) {
      TLorentzVector b_tlv = getTLV_MC(b);
      float dr_b_jet = jet_tlv.DeltaR(b_tlv);
      
      for (auto tau : truth_taus) {
        TLorentzVector tau_tlv = getTLV_MC(tau);
        float dr_tau_jet = jet_tlv.DeltaR(tau_tlv);
        if ((dr_tau_jet < dR_truth) & (dr_b_jet < dR_truth)) {
          isContam = true;
          return isContam;
        }
      }
    }
  }
  return isContam;
}

// function to get pvis and miss from a tau
std::tuple<
  ROOT::VecOps::RVec<edm4hep::MCParticleData>,  // p_vis
  ROOT::VecOps::RVec<edm4hep::MCParticleData> // p_mis
>
AnalysisFCChh::visible_tauhad(
    const ROOT::VecOps::RVec<edm4hep::MCParticleData>& truth_particles,
    const ROOT::VecOps::RVec<podio::ObjectID>&         daughter_ids,
    const ROOT::VecOps::RVec<podio::ObjectID>&         parent_ids,
    TString type)
{
  ROOT::VecOps::RVec<edm4hep::MCParticleData> out_vis;
  ROOT::VecOps::RVec<edm4hep::MCParticleData> out_mis;

  // find hadronic taus from H/Z (from_higgs, from_Z)
  auto tau_list = AnalysisFCChh::getTruthTauHads(
      truth_particles, daughter_ids, parent_ids, type);

  
  if (tau_list.size() < 1) {
    return std::make_tuple(out_vis, out_mis);
  }
    
  // For each hadronic tau: sum visible daughters
  for (const auto& tau : tau_list) {
    int n_nu = 0;
    // Walk the final tau daughters
    const int first_child = tau.daughters_begin;
    const int last_child  = tau.daughters_end;

    TLorentzVector p_vis(0,0,0,0);
    TLorentzVector p_mis(0,0,0,0);

    for (int ch_i = first_child; ch_i < last_child; ++ch_i) {
      const auto child_idx = daughter_ids.at(ch_i).index;
      if (child_idx < 0 || child_idx >= (int)truth_particles.size()) continue;

      const auto& d = truth_particles[child_idx];
      const double px = d.momentum.x;
      const double py = d.momentum.y;
      const double pz = d.momentum.z;
      const double m  = d.mass;
      const double e  = std::sqrt(px*px + py*py + pz*pz + m*m);
      TLorentzVector p4; p4.SetPxPyPzE(px, py, pz, e);
      if (isNeutrino(d)) {
        n_nu++;
        p_mis += p4;
      } else {
        p_vis += p4;
      }
    }


    if (n_nu > 1) {
      std::cout << "We're in a leptonic decay of N_nu = " << n_nu << std::endl;
    }

    if (p_vis.P() <= 0.0) continue; // nothing visible, skip

    edm4hep::MCParticleData visTau = {};
    visTau.PDG    = tau.PDG;                        
    visTau.charge = tau.charge;                     
    visTau.mass   = static_cast<float>(p_vis.M()); 
    visTau.momentum.x = static_cast<float>(p_vis.Px());
    visTau.momentum.y = static_cast<float>(p_vis.Py());
    visTau.momentum.z = static_cast<float>(p_vis.Pz());
    visTau.vertex     = tau.vertex;                 

    edm4hep::MCParticleData misTau = {};
    misTau.PDG    = tau.PDG;                        
    misTau.charge = tau.charge;                     
    misTau.mass   = static_cast<float>(p_mis.M());  
    misTau.momentum.x = static_cast<float>(p_mis.Px());
    misTau.momentum.y = static_cast<float>(p_mis.Py());
    misTau.momentum.z = static_cast<float>(p_mis.Pz());
    misTau.vertex     = tau.vertex;   

    misTau.parents_begin   = misTau.parents_end   = 0;
    misTau.daughters_begin = misTau.daughters_end = 0;

    //out.emplace_back(ROOT::VecOps::RVec<edm4hep::MCParticleData>{visTau, misTau});
    out_vis.push_back(visTau);
    out_mis.push_back(misTau);
  }

  return std::make_tuple(out_vis, out_mis);
}


// function to find the minimum distance between electron and reco-matched signal objects
float AnalysisFCChh::min_dr_signal(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& target_obj,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& dR1_obj,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& dR2_obj
)
{
  // No target: return a sentinel
  if (target_obj.empty()) {
    return 999.f;
  }

  const auto& tar_obj = target_obj[0];
  TLorentzVector tar_obj_tlv = getTLV_reco(tar_obj);

  float mindR = 999.f;

  // First collection
  for (const auto& obji : dR1_obj) {
    TLorentzVector obji_tlv = getTLV_reco(obji);
    const float dRi = obji_tlv.DeltaR(tar_obj_tlv);
    if (dRi < mindR) {
      mindR = dRi;
    }
  }

  // Second collection
  for (const auto& obji : dR2_obj) {
    TLorentzVector obji_tlv = getTLV_reco(obji);
    const float dRi = obji_tlv.DeltaR(tar_obj_tlv);
    if (dRi < mindR) {
      mindR = dRi;
    }
  }

  return mindR;
}
// check what type the W decay is: to lv or qq
int AnalysisFCChh::checkWDecay_HHH(
    edm4hep::MCParticleData truth_W,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles) {

  auto first_child_index = truth_W.daughters_begin;
  auto last_child_index = truth_W.daughters_end;
  auto children_size = last_child_index - first_child_index;

  if (children_size < 1) {
    std::cout
        << "Error in checkWDecay! Checking W with no daughters, returning 0."
        << std::endl;
    return 0;
  }

  // have at least 1 child -> if its also a W, continue the chain -> skip the
  // intermediate Ws, and those that radiated photon
  auto child_1_index = daughter_ids.at(first_child_index).index;
  auto child_1 = truth_particles.at(child_1_index);

  // if the child of the W is also a W, use that one
  if (isW(child_1)) {
    return checkWDecay(child_1, daughter_ids, truth_particles);
  }

  if (children_size != 2) {
    std::cout << "Error in checkWDecay! Found unexpected W decay, please check."
              << std::endl;

    return 0;
  }

  // now get the indices in the daughters vector
  //  auto child_1_MC_index = daughter_ids.at(first_child_index).index;
  auto child_2_MC_index = daughter_ids.at(last_child_index - 1).index;

  // std::cout << "Daughters run from: " << child_1_MC_index << " to " <<
  // child_2_MC_index << std::endl;

  // then go back to the original vector of MCParticles
  //  auto child_1 = truth_particles.at(child_1_MC_index);
  auto child_2 = truth_particles.at(child_2_MC_index);

  // debug
  //  std::cout << "Checking W decay: PDGID 1 = " << child_1.PDG << " and PDGID
  //  2 = " <<  child_2.PDG << std::endl;
  // scheme: is e/mu: 1, tau:2, had: 4
  // scheme: e/μ = 1, τ = 2, hadronic = 4
  if ((isLightLep(child_1) && isNeutrino(child_2)) ||
      (isNeutrino(child_1) && isLightLep(child_2))) {
    return 1; // W → eν or μν
  }
  else if ((isTau(child_1) && isNeutrino(child_2)) ||
          (isNeutrino(child_1) && isTau(child_2))) {
    return 2; // W → τν
  }
  else if (isQuark(child_1) && isQuark(child_2)) {
    return 4; // W → qq′
  }
  else {
    std::cout << "Found different decay of W boson than lv or qq! Please check."
              << std::endl;
    std::cout << "PDGID 1 = " << child_1.PDG << " and PDGID 2 = " << child_2.PDG
              << std::endl;
    return -9;
  }
}

// truth filter used to get WW(lvlv) events from the inclusive bbWW samples
int AnalysisFCChh::WWlvlvFilter_HHH(
    ROOT::VecOps::RVec<edm4hep::MCParticleData> truth_particles,
    ROOT::VecOps::RVec<podio::ObjectID> daughter_ids,
    ROOT::VecOps::RVec<podio::ObjectID> parent_ids) {
  // first scan through the truth particles to find Z bosons

  auto isHardProcess = [](const edm4hep::MCParticleData& p){
    const int s = std::abs(p.generatorStatus);   // Pythia8: negative if decayed
    //std::cout << "Generator status " << s;
    return (s >= 21 && s <= 29);                 // hardest subprocess
  };

  std::vector<edm4hep::MCParticleData> w_list;
  for (auto &truth_part : truth_particles) {
    if (isW(truth_part) && isHardProcess(truth_part)) {
      w_list.push_back(truth_part);
    }
    // Tau veto: - actually probably doesnt work as intended, to revise!!
    //  if  (isTau(truth_part)){
    //  return false;
    // }
  }
  //if (w_list.size() != 2) {
  //  std::cout << " found how many Ws? " << w_list.size() << std::endl; 
  //}
  if (w_list.size() == 2) {
    int w1_decay = checkWDecay_HHH(w_list.at(0), daughter_ids, truth_particles);
    int w2_decay = checkWDecay_HHH(w_list.at(1), daughter_ids, truth_particles);

    int ww_decay_flag = w1_decay + w2_decay;

    // flags are W(lv) =1 and W(qq) =2, so flag for lvlvv is =2 (lvqq=3, 4q=4)
    return ww_decay_flag;

  } else {
    return -9;
  }
}

inline float safeAngle3D(const TLorentzVector& a, const TLorentzVector& b) {
    const TVector3 av = a.Vect();
    const TVector3 bv = b.Vect();
    if (av.Mag2() <= 0.0 || bv.Mag2() <= 0.0) return -1.f;
    return static_cast<float>(av.Angle(bv)); // radians
  }


std::array<AnalysisFCChh::TauAngleRecord, 2>
AnalysisFCChh::matchTwoTruthTwoRecoAndAngles(
    const TLorentzVector& pvis_truth_0,
    const TLorentzVector& pmiss_truth_0,
    int nprongs_truth_0,
    const TLorentzVector& pvis_truth_1,
    const TLorentzVector& pmiss_truth_1,
    int nprongs_truth_1,
    const TLorentzVector& reco0,
    const TLorentzVector& reco1,
    float drCut
) {
  std::array<TauAngleRecord, 2> out = {
      makeBaseRecord(0, nprongs_truth_0, pvis_truth_0, pmiss_truth_0),
      makeBaseRecord(1, nprongs_truth_1, pvis_truth_1, pmiss_truth_1)
  };

  // dR matrix between truth visible axes and reco candidates
  const float dR00 = pvis_truth_0.DeltaR(reco0);
  const float dR01 = pvis_truth_0.DeltaR(reco1);
  const float dR10 = pvis_truth_1.DeltaR(reco0);
  const float dR11 = pvis_truth_1.DeltaR(reco1);

  // Two possible 1-1 assignments; pick the smaller total ΔR
  const float sumA = dR00 + dR11; // (0->0, 1->1)
  const float sumB = dR01 + dR10; // (0->1, 1->0)
  const bool useA = (sumA <= sumB);

  auto applyMatch = [&](int truthIdx, int recoIdx, float dR) {
    TauAngleRecord& r = out.at(truthIdx);

    const TLorentzVector& pmiss_t = (truthIdx == 0) ? pmiss_truth_0 : pmiss_truth_1;
    const TLorentzVector& reco    = (recoIdx  == 0) ? reco0        : reco1;

    r.dR_best = dR;

    if (dR >= drCut) {
      r.matched  = false;
      r.reco_idx = -1;
      r.pt_reco  = -1.f;
      r.theta_rt = -1.f;
      return;
    }

    r.matched  = true;
    r.reco_idx = recoIdx;
    r.pt_reco  = static_cast<float>(reco.Pt());
    r.theta_rt = safeAngle3D(reco, pmiss_t); // reco visible vs truth missing
  };

  if (useA) {
    applyMatch(0, 0, dR00);
    applyMatch(1, 1, dR11);
  } else {
    applyMatch(0, 1, dR01);
    applyMatch(1, 0, dR10);
  }

  return out;
}

inline double get_sigma_rel_from_map(double pt, double abs_eta)
{
  // Static so the file and hist are loaded only once.
  static bool   initialized = false;
  static TFile* f_maps      = nullptr;
  static TH2D*  h_sigma_rel = nullptr;

  if (!initialized)
  {
    initialized = true;
    // Adjust path/name to whatever you actually use
    f_maps = TFile::Open("/data/atlas/users/dingleyt/FCChh/FCCAnalyses/jet_response_maps.root", "READ");
    if (!f_maps || f_maps->IsZombie()) {
      std::cerr << "[get_sigma_rel_from_map] ERROR: cannot open jet_response_maps.root\n";
      h_sigma_rel = nullptr;
      return 0.0;
    }

    // Combined relative pT resolution map
    h_sigma_rel = dynamic_cast<TH2D*>(f_maps->Get("all_sigma_rel"));
    if (!h_sigma_rel) {
      std::cerr << "[get_sigma_rel_from_map] ERROR: histogram all_sigma_rel not found in jet_response_maps.root\n";
    }
  }

  int binx = h_sigma_rel->GetXaxis()->FindBin(pt);
  int biny = h_sigma_rel->GetYaxis()->FindBin(abs_eta);

  double sigma_rel = h_sigma_rel->GetBinContent(binx, biny);
  if (!std::isfinite(sigma_rel) || sigma_rel <= 0.0) {
    return 0.0;
  }
  return sigma_rel;
}


// function to compute the perpendicular and parallel components of the MET
ROOT::VecOps::RVec<float> AnalysisFCChh::get_perp_para_metres(
  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> jets,
  ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData> MET_obj
)
{
  ROOT::VecOps::RVec<float> out;
  out.reserve(4); 

  if (MET_obj.empty()) {
    out.push_back(0.f); // para
    out.push_back(0.f); // perp
    out.push_back(0.f); // x
    out.push_back(0.f); // y
    return out;
  }

  // MET direction for parallel / perpendicular
  TLorentzVector met_tlv = getTLV_MET(MET_obj[0]);
  const double phi_met = met_tlv.Phi();

  double sum_sigma_par2  = 0.0;
  double sum_sigma_perp2 = 0.0;
  double sum_sigma_x2    = 0.0;
  double sum_sigma_y2    = 0.0;

  for (const auto& j : jets) {
    TLorentzVector j_tlv = getTLV_reco(j);
    const double pt  = j_tlv.Pt();
    const double eta = j_tlv.Eta();
    const double phi = j_tlv.Phi();

    
    // get relative pT resolution from map
    const double abs_eta = std::fabs(eta);
    const double sigma_rel = get_sigma_rel_from_map(pt, abs_eta);
    if (sigma_rel <= 0.0)
      continue;

    // Absolute pT resolution for this jet
    const double sigma_pt = sigma_rel * pt;

    // ---- parallel / perpendicular to MET ----
    const double dphi = TVector2::Phi_mpi_pi(phi - phi_met);
    const double c_par = std::cos(dphi);
    const double s_perp = std::sin(dphi);

    const double sigma_par  = sigma_pt * c_par;
    const double sigma_perp = sigma_pt * s_perp;

    sum_sigma_par2  += sigma_par  * sigma_par;
    sum_sigma_perp2 += sigma_perp * sigma_perp;

    // ---- x / y in the lab frame ----
    const double c_x = std::cos(phi);
    const double s_y = std::sin(phi);

    const double sigma_px = sigma_pt * c_x;
    const double sigma_py = sigma_pt * s_y;

    sum_sigma_x2 += sigma_px * sigma_px;
    sum_sigma_y2 += sigma_py * sigma_py;
  }

  const double sigma_parallel = std::sqrt(sum_sigma_par2);
  const double sigma_perp     = std::sqrt(sum_sigma_perp2);
  const double sigma_x        = std::sqrt(sum_sigma_x2);
  const double sigma_y        = std::sqrt(sum_sigma_y2);

  out.push_back(static_cast<float>(sigma_parallel)); // [0]
  out.push_back(static_cast<float>(sigma_perp));     // [1]
  out.push_back(static_cast<float>(sigma_x));        // [2]
  out.push_back(static_cast<float>(sigma_y));        // [3]

  return out;
}

AnalysisFCChh::HiggsCandidateResult AnalysisFCChh::getHiggsCandidates(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& bjets,
  TString strategy,
  float target_mass1,
  float target_mass2)
{
  HiggsCandidateResult out;
  out.pairs.clear();
  out.used_bjet_indices.clear();

  RecoParticlePair bestH1, bestH2;
  std::pair<int,int> bestIdxH1{-1,-1};
  std::pair<int,int> bestIdxH2{-1,-1};
  float bestScore = std::numeric_limits<float>::max();

  // three implemented strategies: linear, square and dR-pairing
  // final results all use dR-pairing.
  auto score_mass   = [&](float m1, float m2)->float {
    if (strategy == "linearmass")
      return std::fabs(m1 - target_mass1) + std::fabs(m2 - target_mass2);
    if (strategy == "squaremass")
      return std::pow(m1 - target_mass1, 2.f) + std::pow(m2 - target_mass2, 2.f);
    return std::numeric_limits<float>::infinity();
  };
  auto score_dRmax = [&](const TLorentzVector& a1, const TLorentzVector& a2,
                         const TLorentzVector& b1, const TLorentzVector& b2)->float {
    return std::max(a1.DeltaR(a2), b1.DeltaR(b2));
  };

  if (bjets.size() == 4) {
    for (size_t i = 0; i < 4; ++i) {
      TLorentzVector tlv_i = getTLV_reco(bjets[i]);
      for (size_t j = i + 1; j < 4; ++j) {
        TLorentzVector tlv_j = getTLV_reco(bjets[j]);
        const float m_h1 = (tlv_i + tlv_j).M();

        for (size_t k = 0; k < 4; ++k) {
          if (k == i || k == j) continue;
          TLorentzVector tlv_k = getTLV_reco(bjets[k]);

          for (size_t l = k + 1; l < 4; ++l) {
            if (l == i || l == j) continue;
            TLorentzVector tlv_l = getTLV_reco(bjets[l]);
            const float m_h2 = (tlv_k + tlv_l).M();

            float score = 0.f;
            if (strategy == "dRminmax") {
              score = score_dRmax(tlv_i, tlv_j, tlv_k, tlv_l);
            } else {
              score = score_mass(m_h1, m_h2);
            }

            if (score < bestScore) {
              bestScore = score;
              bestH1 = {bjets[i], bjets[j]};
              bestH2 = {bjets[k], bjets[l]};
              bestIdxH1 = {static_cast<int>(i), static_cast<int>(j)};
              bestIdxH2 = {static_cast<int>(k), static_cast<int>(l)};
            }
          }
        }
      }
    }

    if (bestScore < std::numeric_limits<float>::max()) {
      TLorentzVector h1 = getTLV_reco(bestH1.particle_1) + getTLV_reco(bestH1.particle_2);
      TLorentzVector h2 = getTLV_reco(bestH2.particle_1) + getTLV_reco(bestH2.particle_2);

      // order by pT (first = leading)
      if (h1.Pt() >= h2.Pt()) {
        out.pairs = {bestH1, bestH2};
      } else {
        out.pairs = {bestH2, bestH1};
        std::swap(bestIdxH1, bestIdxH2);
      }
      out.used_bjet_indices = {bestIdxH1.first, bestIdxH1.second, bestIdxH2.first, bestIdxH2.second};
      return out;
    }
  }

  // 
  if (bestScore < std::numeric_limits<float>::max()) {
    TLorentzVector h1 = getTLV_reco(bestH1.particle_1) + getTLV_reco(bestH1.particle_2);
    TLorentzVector h2 = getTLV_reco(bestH2.particle_1) + getTLV_reco(bestH2.particle_2);

    if (h1.Pt() >= h2.Pt()) {
      out.pairs = {bestH1, bestH2};
    } else {
      out.pairs = {bestH2, bestH1};
      std::swap(bestIdxH1, bestIdxH2);
    }

    auto push_if_b = [&](int idxLocal){
      if (0 <= idxLocal && idxLocal <= 2) out.used_bjet_indices.push_back(idxLocal);
    };
    push_if_b(bestIdxH1.first);
    push_if_b(bestIdxH1.second);
    push_if_b(bestIdxH2.first);
    push_if_b(bestIdxH2.second);

    return out;
  }

  // Nothing found: return empty
  return out;
}

ROOT::VecOps::RVec<TLorentzVector>
AnalysisFCChh::get_Htautau_vis_exclusive_TLVs(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& tauJets,
  int n_tau,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& electrons,
  int n_el,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& muons,
  int n_mu)
{

  auto isOS = [](const edm4hep::ReconstructedParticleData& a,
                 const edm4hep::ReconstructedParticleData& b) {
    return a.charge * b.charge < 0;
  };

  auto orderByPt = [](const TLorentzVector& a, const TLorentzVector& b) {
    return (a.Pt() >= b.Pt()) ? std::make_pair(a, b) : std::make_pair(b, a);
  };

  // 1) lep–had: exactly one tau, one electron, no mu; OS(tau,e)
  if (n_tau == 1 && n_el == 1 && n_mu == 0) {
    if (isOS(tauJets[0], electrons[0])) {
      const TLorentzVector p4a = getTLV_reco(tauJets[0]);
      const TLorentzVector p4b = getTLV_reco(electrons[0]);
      //auto [lead, sub] = orderByPt(p4a, p4b);
      // no ordering here, nice to keep lepton information separate for ML training in lephad channel
      return {p4a, p4b, p4a + p4b};
    }
    return ROOT::VecOps::RVec<TLorentzVector>(3); // {0,0,0}
  }

  // 2) lep–had: exactly one tau, one mu, no e; OS(τ,μ)
  if (n_tau == 1 && n_mu == 1 && n_el == 0) {
    if (isOS(tauJets[0], muons[0])) {
      const TLorentzVector p4a = getTLV_reco(tauJets[0]);
      const TLorentzVector p4b = getTLV_reco(muons[0]);
      //auto [lead, sub] = orderByPt(p4a, p4b);
      // no ordering here, nice to keep lepton information separate for ML training in lephad channel
      return {p4a, p4b, p4a + p4b};
    }
    return ROOT::VecOps::RVec<TLorentzVector>(3);
  }

  // 3) had–had: no leptons, exactly two taus
  if (n_el == 0 && n_mu == 0 && n_tau == 2) {
    // assume exactly two taus: tauJets[0], tauJets[1]
    const auto& tau1 = tauJets[0];
    const auto& tau2 = tauJets[1];

    if (!isOS(tau1, tau2)) {
        // return empty if not opposite sign
        return ROOT::VecOps::RVec<TLorentzVector>(3);
    }

    const TLorentzVector p4a = getTLV_reco(tau1);
    const TLorentzVector p4b = getTLV_reco(tau2);

    auto [lead, sub] = orderByPt(p4a, p4b);

    return ROOT::VecOps::RVec<TLorentzVector>{lead, sub, lead + sub};
  }

  // None matched exclusively → return zeroed triplet
  return ROOT::VecOps::RVec<TLorentzVector>(3);
}

// bit of a duplicate from above, nice thing is to have isLep1/2 to be used later by MMC
std::tuple<
  edm4hep::ReconstructedParticleData, // lead constituent
  edm4hep::ReconstructedParticleData, // sublead constituent
  TLorentzVector,                      // visible H→tautau
  bool, // return if tau1 is a lepton or not
  bool // return if tau2 is a lepton or not
> AnalysisFCChh::get_Htautau_vis_exclusive_recoTLV(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& tauJets,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& electrons,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& muons)
{
  const int nTau = static_cast<int>(tauJets.size());
  const int nE   = static_cast<int>(electrons.size());
  const int nMu  = static_cast<int>(muons.size());

  auto pt = [](const edm4hep::ReconstructedParticleData& p) {
    return std::hypot(p.momentum.x, p.momentum.y);
  };
  auto isOS = [](const edm4hep::ReconstructedParticleData& a,
                 const edm4hep::ReconstructedParticleData& b) {
    return a.charge * b.charge < 0;
  };
  auto orderByPt = [&](const edm4hep::ReconstructedParticleData& a,
                       const edm4hep::ReconstructedParticleData& b) {
    return (pt(a) >= pt(b)) ? std::make_pair(a, b) : std::make_pair(b, a);
  };
  auto makeVisH = [&](const edm4hep::ReconstructedParticleData& a,
                      const edm4hep::ReconstructedParticleData& b) {
    // Prefer using your existing builder to ensure consistent calibration
    const TLorentzVector p4a = getTLV_reco(a);
    const TLorentzVector p4b = getTLV_reco(b);
    return p4a + p4b;
  };

  // 1) lep–had: exactly one tau, one electron, no mu
  if (nTau == 1 && nE == 1 && nMu == 0) {
    if (isOS(tauJets[0], electrons[0])) {
      auto lead = tauJets[0];
      auto sub = electrons[0];
      auto visH = makeVisH(lead, sub);
      
      return {lead, sub, visH, false, true};
    }
    return { {}, {}, {}, false, false };
  }

  // 2) lep–had: exactly one tau, one mu, no e
  if (nTau == 1 && nMu == 1 && nE == 0) {
    if (isOS(tauJets[0], muons[0])) {
      auto lead = tauJets[0];
      auto sub = muons[0];
      auto visH = makeVisH(lead, sub);
      
      return {lead, sub, visH, false, true};
    }
    return { {}, {}, {}, false, false };
  }

  // 3) had–had: no leptons, at least two taus
  if (nE == 0 && nMu == 0 && nTau >= 2) {
    float bestScore = -1.f;
    int   bestI = -1, bestJ = -1;
    for (int i = 0; i < nTau; ++i) {
      for (int j = i + 1; j < nTau; ++j) {
        if (!isOS(tauJets[i], tauJets[j])) continue;
        const float score = pt(tauJets[i]) + pt(tauJets[j]);
        if (score > bestScore) { bestScore = score; bestI = i; bestJ = j; }
      }
    }
    if (bestI >= 0) {
      auto [lead, sub] = orderByPt(tauJets[bestI], tauJets[bestJ]);
      auto visH = makeVisH(lead, sub);
      return {lead, sub, visH, false, false};
    }
    return { {}, {}, {}, false, false };
  }

  // None matched exclusively
  return { {}, {}, {}, false, false };
}

// tranverse mass
float AnalysisFCChh::mT_tautau(
  const TLorentzVector& tau1_vis,
  const TLorentzVector& tau2_vis,
  float MET_x,
  float MET_y
){
  const TLorentzVector v = tau1_vis + tau2_vis;
  const TVector2 pT_vis(v.Px(), v.Py());
  const TVector2 MET(MET_x, MET_y);

  const double mvis2   = std::max(0.0, v.M2());
  const double pTvis   = pT_vis.Mod();
  const double ETvis   = std::sqrt(mvis2 + pTvis*pTvis);
  const double METmag  = MET.Mod();
  const double dot     = pT_vis.X()*MET.X() + pT_vis.Y()*MET.Y();

  double mT2 = mvis2 + 2.0*(ETvis*METmag - dot);
  if (mT2 < 0.0) mT2 = 0.0;
  const double mT = std::sqrt(mT2);

  if (!std::isfinite(mT) || mT <= 0.0) return -1.f;
  return static_cast<float>(mT);
}

// function to compute collinear mass
float AnalysisFCChh::ditau_mass_collinear(
    const TLorentzVector& vis1,
    const TLorentzVector& vis2,
    double METx, double METy
)
{

  const TLorentzVector vis = vis1 + vis2;
  const double mvis = vis.M();
  const double pxv  = vis.Px();
  const double pyv  = vis.Py();
  const double ptv  = vis.Pt();

  const double met  = std::sqrt(METx*METx + METy*METy);

  const double ETvis  = std::sqrt(mvis*mvis + ptv*ptv);
  const double ETmiss = met;                        
  const double dot    = pxv*METx + pyv*METy;

  double mT2 = mvis*mvis + 2.0*(ETvis*ETmiss - dot);
  if (mT2 < 0.0) mT2 = 0.0;
  const double mT = std::sqrt(mT2);

  const double px1 = vis1.Px();
  const double py1 = vis1.Py();
  const double px2 = vis2.Px();
  const double py2 = vis2.Py();

  const double denom = px1 * py2 - py1 * px2;
  if (std::fabs(denom) < 1e-6) {
    return static_cast<float>(mT);
  }

  // Solve MET as linear combo of visible τ directions
  const double a = ( METx * py2 - METy * px2) / denom;
  const double b = (-METx * py1 + METy * px1) / denom;

  const double x1 = 1.0 / (1.0 + a);
  const double x2 = 1.0 / (1.0 + b);

  // Require 0 < x_i < 1
  if (!(x1 > 0.0 && x1 < 1.0 && x2 > 0.0 && x2 < 1.0)) {
    return static_cast<float>(-999);
  }

  const double xprod = x1 * x2;
  if (xprod <= 0.0) {
    return static_cast<float>(-999);
  }

  const double m_col = mvis / std::sqrt(xprod);

  return static_cast<float>(m_col);
}

// Thrust
float AnalysisFCChh::thrust(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& bjets,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& tau_cands
)
{
  // Collect p4s from b-jets and tau candidates
  std::vector<TLorentzVector> p4s;
  p4s.reserve(bjets.size() + tau_cands.size());

  for (const auto& obj : bjets) {
    TLorentzVector p4 = getTLV_reco(obj);
    if (p4.P() > 0.) p4s.push_back(p4);
  }
  for (const auto& obj : tau_cands) {
    TLorentzVector p4 = getTLV_reco(obj);
    if (p4.P() > 0.) p4s.push_back(p4);
  }

  if (p4s.empty()) return 0.f;

  // Denominator: sum of |p|
  double denom = 0.0;
  std::vector<double> mags;
  mags.reserve(p4s.size());
  for (const auto& p4 : p4s) {
    double m = p4.P();
    mags.push_back(m);
    denom += m;
  }
  if (denom == 0.0) return 0.f;

  // Initial axis: direction of highest-momentum object
  int iMax = 0;
  for (size_t i = 1; i < mags.size(); ++i) {
    if (mags[i] > mags[iMax]) iMax = i;
  }
  TVector3 n = p4s[iMax].Vect().Unit();

  const int    maxIter = 1000;
  const double tol     = 1e-6;

  for (int iter = 0; iter < maxIter; ++iter) {
    TVector3 v_sum(0., 0., 0.);

    for (const auto& p4 : p4s) {
      TVector3 p = p4.Vect();
      double proj = p.Dot(n);
      double s    = (proj >= 0.0) ? 1.0 : -1.0;
      v_sum += s * p;
    }

    if (v_sum.Mag2() == 0.0) break;

    TVector3 n_new = v_sum.Unit();
    if ((n_new - n).Mag() < tol) {
      n = n_new;
      break;
    }
    n = n_new;
  }

  double num = 0.0;
  for (const auto& p4 : p4s) {
    num += std::abs(p4.Vect().Dot(n));
  }

  double T = num / denom;
  return static_cast<float>(T);
}

// Sphericity
float AnalysisFCChh::sphericity(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& bjets,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& tau_cands
)
{
  std::vector<TLorentzVector> p4s;
  p4s.reserve(bjets.size() + tau_cands.size());

  for (const auto& obj : bjets) {
    TLorentzVector p4 = getTLV_reco(obj);
    if (p4.P() > 0.) p4s.push_back(p4);
  }
  for (const auto& obj : tau_cands) {
    TLorentzVector p4 = getTLV_reco(obj);
    if (p4.P() > 0.) p4s.push_back(p4);
  }

  if (p4s.empty()) return 0.f;
  
  // momentum matrix
  TMatrixDSym M(3);
  M.Zero();

  double norm = 0.0;
  for (const auto& p4 : p4s) {
    TVector3 p = p4.Vect();
    norm += p.Mag2();

    M(0,0) += p.X()*p.X();
    M(0,1) += p.X()*p.Y();
    M(0,2) += p.X()*p.Z();
    M(1,1) += p.Y()*p.Y();
    M(1,2) += p.Y()*p.Z();
    M(2,2) += p.Z()*p.Z();
  }

  if (norm == 0.0) return 0.f;

  M(1,0) = M(0,1);
  M(2,0) = M(0,2);
  M(2,1) = M(1,2);

  M *= 1.0 / norm;

  TMatrixDSymEigen eigen(M);
  TVectorD evals = eigen.GetEigenValues(); // ascending

  const double lambda1 = evals(0);
  const double lambda2 = evals(1);
  const double lambda3 = evals(2);

  // check:
  double sum = lambda1 + lambda2 + lambda3;
  

  const double S = 1.5 * (lambda2 + lambda3);
  // should not happen!!
  if (S > 1) {
    std::cout << "Eigenvalues: "
            << lambda1 << " " << lambda2 << " " << lambda3
            << "  sum = " << sum << std::endl;
  }
  return static_cast<float>(S);
}

// Aplanarity
float AnalysisFCChh::aplanarity(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& bjets,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& tau_cands
)
{
  std::vector<TLorentzVector> p4s;
  p4s.reserve(bjets.size() + tau_cands.size());

  for (const auto& obj : bjets) {
    TLorentzVector p4 = getTLV_reco(obj);
    if (p4.P() > 0.) p4s.push_back(p4);
  }
  for (const auto& obj : tau_cands) {
    TLorentzVector p4 = getTLV_reco(obj);
    if (p4.P() > 0.) p4s.push_back(p4);
  }

  if (p4s.empty()) return 0.f;

  TMatrixDSym M(3);
  M.Zero();

  double norm = 0.0;
  for (const auto& p4 : p4s) {
    TVector3 p = p4.Vect();
    norm += p.Mag2();

    M(0,0) += p.X()*p.X();
    M(0,1) += p.X()*p.Y();
    M(0,2) += p.X()*p.Z();
    M(1,1) += p.Y()*p.Y();
    M(1,2) += p.Y()*p.Z();
    M(2,2) += p.Z()*p.Z();
  }

  if (norm == 0.0) return 0.f;

  M(1,0) = M(0,1);
  M(2,0) = M(0,2);
  M(2,1) = M(1,2);

  M *= 1.0 / norm;

  TMatrixDSymEigen eigen(M);
  TVectorD evals = eigen.GetEigenValues(); // ascending
  const double lambda3 = evals(2);

  const double A = 1.5 * lambda3;
  return static_cast<float>(A);
}

// find a Z->ll decay on truth level
ROOT::VecOps::RVec<edm4hep::MCParticleData> AnalysisFCChh::getTruthZtautau(
    const ROOT::VecOps::RVec<edm4hep::MCParticleData> &truth_particles,
    const ROOT::VecOps::RVec<podio::ObjectID> &daughter_ids) {

  ROOT::VecOps::RVec<edm4hep::MCParticleData> tau_list;

  for (auto &truth_part : truth_particles) {
    if (!isZ(truth_part)) continue;

    std::vector<edm4hep::MCParticleData> daughters;
    for (int i = truth_part.daughters_begin; i < truth_part.daughters_end; ++i) {
      auto &cand = truth_particles[daughter_ids[i].index];
      daughters.push_back(cand);
    }

    if (daughters.size() == 2 &&
        std::abs(daughters[0].PDG) == 15 &&
        std::abs(daughters[1].PDG) == 15) {

      tau_list.push_back(daughters[0]);
      tau_list.push_back(daughters[1]);
    }
  }

  return tau_list;
}

using FourVec = ROOT::Math::PxPyPzEVector;

float AnalysisFCChh::mTb_min(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& bjets,
  const edm4hep::ReconstructedParticleData& met  
) {
  if (bjets.empty()) return -999.f;

  // MET components and magnitude
  const float met_px = static_cast<float>(met.momentum.x);
  const float met_py = static_cast<float>(met.momentum.y);
  const float met_pt = std::hypot(met_px, met_py);
  if (!(met_pt > 0.f)) return -999.f;

  const float met_phi = std::atan2(met_py, met_px);

  float best = std::numeric_limits<float>::infinity();

  for (const auto& b : bjets) {
    const float b_px  = static_cast<float>(b.momentum.x);
    const float b_py  = static_cast<float>(b.momentum.y);
    const float b_pt  = std::hypot(b_px, b_py);
    if (!(b_pt > 0.f)) continue;

    const float b_phi = std::atan2(b_py, b_px);
    const float dphi  = deltaPhi(b_phi, met_phi);

    const float mT2 = 2.f * b_pt * met_pt * (1.f - std::cos(dphi));
    const float mT  = (mT2 > 0.f) ? std::sqrt(mT2) : 0.f;

    if (mT < best) best = mT;
  }

  return std::isfinite(best) ? best : -999.f;
}

float AnalysisFCChh::xwt(
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& bjets,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& taujets,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& untaggedjets,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& electrons,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& muons,
  float met_px, float met_py
) {
  const int nb = (int)bjets.size();
  const int nu = (int)untaggedjets.size();
  const int nt = (int)taujets.size();
  const int ne = (int)electrons.size();
  const int nm = (int)muons.size();
  if (nb < 1) return -999.f;  // need at least one b for a top candidate

  constexpr float mW_nom       = 80.379f;  // GeV
  constexpr float mt_nom       = 172.5f;   // GeV
  constexpr float sigma_floor  = 1e-3f;

  auto p4b = [&](int ib) { return getTLV_reco(bjets[ib]); };
  auto p4j = [&](int ij) { return getTLV_reco(untaggedjets[ij]); };
  auto p4t = [&](int it) { return getTLV_reco(taujets[it]);     };
  auto p4e = [&](int ie) { return getTLV_reco(electrons[ie]);   };
  auto p4m = [&](int im) { return getTLV_reco(muons[im]);       };

  auto rel_sigma = [&](float m) {
    // simple 10% relative "mass resolution" with a small floor
    return std::max(0.1f * std::abs(m), sigma_floor);
  };
  auto add_in_quad = [](float a, float b){ return std::sqrt(a*a + b*b); };

  // Neutrino from MET (pz=0, massless)
  TLorentzVector nu4;
  if (std::isfinite(met_px) && std::isfinite(met_py)) {
    const double met = std::hypot(met_px, met_py);
    nu4.SetPxPyPzE(met_px, met_py, 0.0, met);
  }

  float best = std::numeric_limits<float>::infinity();

  // ---------------------------
  // hadronic W: W->jj
  // ---------------------------
  if (nu >= 2) {
    for (int ib = 0; ib < nb; ++ib) {
      const TLorentzVector b = p4b(ib);
      for (int i = 0; i < nu; ++i) {
        const TLorentzVector ji = p4j(i);
        for (int k = i+1; k < nu; ++k) {
          const TLorentzVector jk = p4j(k);
          const TLorentzVector Wjj   = ji + jk;
          const TLorentzVector topbj = b  + Wjj;

          const float mW = (float)Wjj.M();
          const float mt = (float)topbj.M();

          const float pullW = (mW - mW_nom) / rel_sigma(mW);
          const float pullt = (mt - mt_nom) / rel_sigma(mt);
          const float chi2  = add_in_quad(pullW, pullt);

          if (chi2 < best) best = chi2;
        }
      }
    }
  }

  // Helper for leptonic/tau W: compute chi2 with l (τ/e/μ) + MET
  auto consider_leptonicW = [&](const TLorentzVector& b, const TLorentzVector& l) {
    if (!std::isfinite(met_px) || !std::isfinite(met_py)) return;

    const float pt_l  = (float)l.Pt();
    const float pt_nu = (float)nu4.Pt();
    const float dphi  = std::abs(TVector2::Phi_mpi_pi(l.Phi() - nu4.Phi()));

    const float mT2 = 2.0f * pt_l * pt_nu * (1.0f - std::cos(dphi));
    const float mT  = std::sqrt(std::max(0.0f, mT2));

    const float mtop = (float)(b + l + nu4).M();

    const float pullW = (mT  - mW_nom) / rel_sigma(mT);
    const float pullt = (mtop - mt_nom) / rel_sigma(mtop);
    const float chi2  = add_in_quad(pullW, pullt);

    if (chi2 < best) best = chi2;
  };

  // ---------------------------
  // B) Tau W: W->τν  (use tau_h + MET)
  // ---------------------------
  if (nt >= 1 && std::isfinite(met_px) && std::isfinite(met_py)) {
    for (int ib = 0; ib < nb; ++ib) {
      const TLorentzVector b = p4b(ib);
      for (int it = 0; it < nt; ++it) {
        consider_leptonicW(b, p4t(it));
      }
    }
  }

  // ---------------------------
  // C) Leptonic W: W->eν and W->μν  (use e/μ + MET)
  // ---------------------------
  if ((ne >= 1 || nm >= 1) && std::isfinite(met_px) && std::isfinite(met_py)) {
    for (int ib = 0; ib < nb; ++ib) {
      const TLorentzVector b = p4b(ib);
      for (int ie = 0; ie < ne; ++ie) consider_leptonicW(b, p4e(ie));
      for (int im = 0; im < nm; ++im) consider_leptonicW(b, p4m(im));
    }
  }

  return std::isfinite(best) ? best : -999.f;
}

static inline FourVec toP4(const edm4hep::ReconstructedParticleData& p) {
  return FourVec(p.momentum.x, p.momentum.y, p.momentum.z, p.energy);
}

static inline float deltaPhi(float phi1, float phi2) {
  float d = phi1 - phi2;
  while (d >  M_PI) d -= 2.f * M_PI;
  while (d < -M_PI) d += 2.f * M_PI;
  return d;
}

// RMS functions
float AnalysisFCChh::RMS_mjj(const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& bjets) {
  const size_t n = bjets.size();
  if (n < 2) return -999.f;

  double sum_sq = 0.0;
  int count = 0;

  for (size_t i = 0; i < n; ++i) {
    FourVec p4i = toP4(bjets[i]);
    for (size_t j = i+1; j < n; ++j) {
      FourVec p4j = toP4(bjets[j]);
      double mjj = (p4i + p4j).M();
      sum_sq += mjj * mjj;
      ++count;
    }
  }

  return count > 0 ? std::sqrt(sum_sq / count) : -999.f;
}

float AnalysisFCChh::RMS_deta(const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& bjets) {
  const size_t n = bjets.size();
  if (n < 2) return -999.f;

  double sum_sq = 0.0;
  int count = 0;

  for (size_t i = 0; i < n; ++i) {
    FourVec p4i = toP4(bjets[i]);
    for (size_t j = i+1; j < n; ++j) {
      FourVec p4j = toP4(bjets[j]);
      double deta = p4i.Eta() - p4j.Eta();
      sum_sq += deta * deta;
      ++count;
    }
  }

  return count > 0 ? std::sqrt(sum_sq / count) : -999.f;
}

float AnalysisFCChh::RMS_dR(const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& bjets) {
  const size_t n = bjets.size();
  if (n < 2) return -999.f;

  double sum_sq = 0.0;
  int count = 0;

  for (size_t i = 0; i < n; ++i) {
    FourVec p4i = toP4(bjets[i]);
    for (size_t j = i+1; j < n; ++j) {
      FourVec p4j = toP4(bjets[j]);
      double deta = p4i.Eta() - p4j.Eta();
      double dphi = deltaPhi(p4i.Phi(), p4j.Phi());
      double dR = std::sqrt(deta*deta + dphi*dphi);
      sum_sq += dR * dR;
      ++count;
    }
  }

  return count > 0 ? std::sqrt(sum_sq / count) : -999.f;
}

// truth-matching for HHH
int AnalysisFCChh::find_hhh_signal_match(
  const ROOT::VecOps::RVec<edm4hep::MCParticleData>& truth_B_fromH,
  const ROOT::VecOps::RVec<edm4hep::MCParticleData>& truth_tauhad_vis_fromH,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& reco_tau_jets,
  const ROOT::VecOps::RVec<edm4hep::ReconstructedParticleData>& reco_b_jets,
  float dR_thres)
{
  // Need at least 4 truth Bs and 2 truth taus to even try
  if (truth_B_fromH.size() < 4 || truth_tauhad_vis_fromH.size() < 2) return false;
  if (reco_b_jets.empty() || reco_tau_jets.empty()) return false;

  // Build TLVs
  std::vector<TLorentzVector> tlv_truth_B; tlv_truth_B.reserve(truth_B_fromH.size());
  for (const auto& b : truth_B_fromH) tlv_truth_B.emplace_back(getTLV_MC(b));

  std::vector<TLorentzVector> tlv_truth_tau; tlv_truth_tau.reserve(truth_tauhad_vis_fromH.size());
  for (const auto& t : truth_tauhad_vis_fromH) tlv_truth_tau.emplace_back(getTLV_MC(t));

  std::vector<TLorentzVector> tlv_reco_b; tlv_reco_b.reserve(reco_b_jets.size());
  for (const auto& r : reco_b_jets) tlv_reco_b.emplace_back(getTLV_reco(r));

  std::vector<TLorentzVector> tlv_reco_tau; tlv_reco_tau.reserve(reco_tau_jets.size());
  for (const auto& r : reco_tau_jets) tlv_reco_tau.emplace_back(getTLV_reco(r));

  auto greedy_match_count = [dR_thres](const std::vector<TLorentzVector>& truth,
                                       const std::vector<TLorentzVector>& reco) -> int {
    if (truth.empty() || reco.empty()) return 0;

    // match in descending pT of truth to stabilize
    std::vector<int> order(truth.size());
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(), [&](int i, int j){
      return truth[i].Pt() > truth[j].Pt();
    });

    std::vector<char> used(reco.size(), 0);
    int matched = 0;

    for (int it : order) {
      double bestDR = 1e9;
      int bestJ = -1;
      for (size_t jr = 0; jr < reco.size(); ++jr) {
        if (used[jr]) continue;
        const double dR = truth[it].DeltaR(reco[jr]);
        if (dR < dR_thres && dR < bestDR) {
          bestDR = dR;
          bestJ = static_cast<int>(jr);
        }
      }
      if (bestJ >= 0) {
        used[bestJ] = 1;
        ++matched;
      }
    }
    return matched;
  };

  // Count matches
  const int nB_matched   = greedy_match_count(tlv_truth_B,   tlv_reco_b);
  const int nTau_matched = greedy_match_count(tlv_truth_tau, tlv_reco_tau);

  // Encode result
  int flag = 0;
  if (nTau_matched >= 2) flag += 2;
  if (nB_matched  >= 4) flag += 4;

  return flag;  // 0, 2, 4, or 6
}

inline double lognormal_cdf(double theta, double mu_v, double sig_v, double c_v) {
  const double x = theta + c_v;
  if (x <= 0.0) return 0.0;
  const double z = (std::log(x) - mu_v) / (sig_v * std::sqrt(2.0));
  return 0.5 * (1.0 + std::erf(z));
}

inline double lognormal_pdf_trunc(double theta, double pt, int nprongs) {
  const Params& p = params_for_nprongs(nprongs);
  const double mu_v  = mu(pt, p);
  const double sig_v = sigma(pt, p);
  const double c_v   = shift_c(pt, p);
  const double x = theta + c_v;
  if (x <= 0.0 || theta < 0.0 || theta > theta_max_lognorm) return 0.0;

  const double z = (std::log(x) - mu_v) / sig_v;
  const double logpdf = -std::log(x * sig_v * std::sqrt(2.0 * M_PI)) - 0.5 * z * z;

  const double cdf_lo = lognormal_cdf(0.0, mu_v, sig_v, c_v);
  const double cdf_hi = lognormal_cdf(theta_max_lognorm, mu_v, sig_v, c_v);
  const double norm = std::max(cdf_hi - cdf_lo, 1e-12);

  return std::exp(logpdf) / norm;
}

inline std::vector<float> solve_pz_quadratic_tau(const TLorentzVector& tau_vis,
                                                 float phi_nu,
                                                 float pT_nu,
                                                 bool isLep,
                                                 int n_charged_tracks = 1,
                                                 float m_nu_eff = 0.0)
{
  /*
    General quadratic solver for tau -> vis + missing system.

    Start with 4-vector eqn:
      (p_vis + p_missing)^2 = m_tau^2, with p_missing^2 = m_missing^2, 
      simplifies for hadronic system with a singular neutrino -> m_nu == 0

    Write dot-product of missing and visible 3-momenta as sum of pTmissing dot pTvisible + pzmissing * pzvisible
    Isolate sqrt, solve for pz
    C = (m_tau^2 - m_vis^2 - m_miss^2)/2 - pTmissing dot pTvisible

    Quadratic becomes:
    pz^2 (pzvisible^2 - E_visible^2) + pz (2Cpzvisible) + (C^2 - E_visible^2p_Tmissing^2 - Evisible^2m_missing^2xw)

    => E_v * sqrt(pT^2 + pz^2 + m_nu^2)
       = K + p_vx*px + p_vy*py + p_vz*pz,
       where K = 0.5 * (m_tau^2 - m_vis^2 - m_nu^2).

    Squaring gives:
       (E_v^2 - p_vz^2) pz^2
       - 2 p_vz (K + p_vx*px + p_vy*py) pz
       + [E_v^2 (pT^2 + m_nu^2) - (K + p_vx*px + p_vy*py)^2] = 0.

    - For hadronic τ: isLep = false, m_nu_eff = 0.
      Choose m_vis ≈ 0.8 GeV (1-prong) or 1.2 GeV (3-prong).
    - For leptonic τ: isLep = true,
      m_vis = m_lep (0.0005 or 0.105 GeV), m_nu_eff typically 0.3–0.8 GeV.
  */

  const float px = pT_nu * std::cos(phi_nu);
  const float py = pT_nu * std::sin(phi_nu);
  const float pT2 = px*px + py*py;

  const float Ev  = tau_vis.E();
  const float pvx = tau_vis.Px();
  const float pvy = tau_vis.Py();
  const float pvz = tau_vis.Pz();

  float mvis2 = tau_vis.M2();
  // check here that the code is producing taus of more or less the correct mass
  //std::cout << "Checking mass of tau " << std::sqrt(mvis2) << std::endl; 

  
  const float mtau2 = M_TAU * M_TAU;
  // Override visible mass where appropriate
  if (!isLep) {
    if (n_charged_tracks <= 2) {
      mvis2 = 0.8f * 0.8f;   // 1-prong
    } else {
      mvis2 = 1.2f * 1.2f;   // 3-prong
    }
    // also hard-code that the missing mass here as zero:
    m_nu_eff = 0.0;
  }
  const float mnu2  = m_nu_eff * m_nu_eff;

  const float K = 0.5f * (mtau2 - mvis2 - mnu2);
  const float B_T = pvx*px + pvy*py;
  // adapting to my own solution set
  const float C = 0.5 * (mtau2 - mvis2 - mnu2) + pvx*px + pvy*py;

  // Quadratic coefficients
  const float a = Ev*Ev - pvz*pvz;
  const float b = -2.0f * pvz * C; 
  const float c = Ev*Ev * (pT2 + mnu2) - C*C;

  std::vector<float> out;

  const float eps_a = 1e-12f;
  if (std::abs(a) < eps_a) {
    // if a == 0 and b == 0, no solutions
    if (std::abs(b) < 1e-18f) return out;
    // if a close to zero, is a linear system and soln:
    const float pz = -c / b;
    std::cout << " Are we ever solving a linear system?" << std::endl;
    if (std::isfinite(pz)) out.push_back(pz);
    return out;
  }

  const float disc = b*b - 4.0f*a*c;
  if (disc < 0) return out; // no physical solution

  const float sqrt_disc = std::sqrt(disc);
  const float denom = 2.0f * a;

  const float pz1 = (-b + sqrt_disc) / denom;
  const float pz2 = (-b - sqrt_disc) / denom;

  // if pz1 finite, store in solution set
  if (std::isfinite(pz1)) out.push_back(pz1);
  // if pz2 finite and distinct from pz1, store in solution set alongside pz1
  if (std::isfinite(pz2) && std::fabs(pz2 - pz1) > 1e-12f) out.push_back(pz2);

  return out;
}


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
)
{
  std::vector<std::pair<float,float>> mditau_solutions;
  struct DiagEntry {
    float w_event, mditau;
    float theta1, theta2;
    float denom1, denom2;
    float nuP1, nuP2;
    float pTau1, pTau2;
    float w_theta1, w_theta2;
    float w_ratio1, w_ratio2;
    float w_met, w_miss;
  };
  std::vector<DiagEntry> diag_entries;
  if (diagnostic) diag_entries.reserve(4096);

  // ------------------------------------------------------------
  // Debug counters
  struct MMCScanStats {
    uint64_t n_phi_pairs         = 0;
    uint64_t n_sin12_small       = 0;
    uint64_t n_met_points        = 0;
    uint64_t n_pt_negative       = 0;
    uint64_t n_hadhad_nodes      = 0;
    uint64_t n_lephad_nodes      = 0;
    uint64_t n_pz1_empty         = 0;
    uint64_t n_pz2_empty         = 0;
    uint64_t n_mass_points       = 0;
    uint64_t n_mscan_invalid     = 0;
    uint64_t n_wmiss_zero        = 0;
    uint64_t n_theta_zero        = 0;
    uint64_t n_solutions         = 0;
  } stats;

  auto printStats = [&](const MMCScanStats& s) {
    std::cout
      << "[MMC debug] phi_pairs="   << s.n_phi_pairs
      << " sin12_small="           << s.n_sin12_small
      << " met_points="            << s.n_met_points
      << " pt_negative="           << s.n_pt_negative
      << " hadhad_nodes="          << s.n_hadhad_nodes
      << " lephad_nodes="          << s.n_lephad_nodes
      << " pz1_empty="             << s.n_pz1_empty
      << " pz2_empty="             << s.n_pz2_empty
      << " mass_points="           << s.n_mass_points
      << " mscan_invalid="         << s.n_mscan_invalid
      << " wmiss_zero="            << s.n_wmiss_zero
      << " theta_zero="            << s.n_theta_zero
      << " solutions="             << s.n_solutions
      << std::endl;
  };
  // ------------------------------------------------------------

  // not processing leplep: exit early
  if (isLep1 && isLep2) {
    return mditau_solutions;
  }

  // for had-had we can increase scanning steps and MET-width
  //if (!isLep1 && !isLep2) {
  //  nMETsteps *= 2;
  //  nsteps    *= 2;
  //  nMETsig    = 4;
  //}

  (void)n_b_jets_medium;
  (void)n_tau_jets_medium;

  auto wrapToPi = [](float a) -> float {
    a = std::fmod(a + static_cast<float>(M_PI), 2.f * static_cast<float>(M_PI));
    if (a < 0.f) a += 2.f * static_cast<float>(M_PI);
    return a - static_cast<float>(M_PI);
  };

  /* 
  ------------------------------------------------------------------
  IMPORTANT FIX: visible hadronic mass poor representation of true underlying tau visible mass
  Must therefore assign most-probable mass for each prong-set, 0.8(1.2) for 1(3) prongs.
  Increases baseline had-had efficiency from ~60% to ~95% (without increasing MET scan window)
  If altered you may see significantly worse acceptance, where the algorithm gets 'stuck' in the quadratic solvers
  ------------------------------------------------------------------ 
  */
  auto applyHadVisMassHyp = [](const TLorentzVector& v, int n_charged_tracks) -> TLorentzVector {
    const float m_hyp = (n_charged_tracks <= 2) ? 0.8f : 1.2f; 
    TLorentzVector out;
    // still using all measured visible components, just with an altered mass hypothesis
    out.SetPtEtaPhiM(v.Pt(), v.Eta(), v.Phi(), m_hyp);
    return out;
  };

  // Only apply to hadronic legs. For leptonic legs, keep lepton mass as is
  TLorentzVector tau1_use = tau1;
  // just for sanity checks, see lepton mass
  if (isLep1) std::cout << "Mass of lepton as stored in used tau: " << tau1_use.M() << std::endl;

  TLorentzVector tau2_use = tau2;
  if (!isLep1) tau1_use = applyHadVisMassHyp(tau1, n_charged_tracks_1);
  if (!isLep2) tau2_use = applyHadVisMassHyp(tau2, n_charged_tracks_2);
  // ------------------------------------------------------------------

  // met scanning (x/y) resolutions, important for penalising large deviations
  const float inv_metres_x2 = 1.f / (metres_x * metres_x);
  const float inv_metres_y2 = 1.f / (metres_y * metres_y);

  const float halfx = nMETsig * metres_x;
  const float halfy = nMETsig * metres_y;

  // define step-width based on nsteps in grid with specific met x/y resolution
  // before para/perp calibration this is identical, now with object-based MET-res
  // these should now differ
  const float dmetx = (2.f * halfx) / (nMETsteps - 1);
  const float dmety = (2.f * halfy) / (nMETsteps - 1);

  const float m_tau = 1.77686f;

  const float PHI_WIN = 0.4f;
  const float phi1_c  = tau1_use.Phi();
  const float phi2_c  = tau2_use.Phi();
  const float dphi1   = (2.f * PHI_WIN) / static_cast<float>(nsteps);
  const float dphi2   = (2.f * PHI_WIN) / static_cast<float>(nsteps);

  // leptonic missing-mass prior (Michel mapped to m_miss)
  auto w_lep_miss = [](float mMiss, float mTau, float mLep)->float {
    const float mt2 = mTau * mTau;
    const float x   = (mt2 + mLep * mLep - mMiss * mMiss) / mt2;
    if (x <= 0.f || x >= 1.f || mMiss <= 0.f) return 0.f;
    const float w_x = x * x * (3.f - 2.f * x);
    const float jac = 2.f * mMiss / mt2;
    return w_x * jac;
  };

  // ------------------------------------------------------------------
  // Empirical beta-PDF weights for missing momentum fraction R = |p_mis| / |p_tau|
  // Parameters taken from x_misP_fits_beta
  // TODO: check leptonic branch (p0)
  struct BetaParams { float a; float b; };
  const BetaParams beta_leg1_p1{1.07885234f, 1.63434510f};
  const BetaParams beta_leg1_p3{1.24681582f, 3.68901032f};
  const BetaParams beta_leg1_p0{1.96933834f, 1.11499697f}; 
  const BetaParams beta_leg2_p1{1.07475452f, 1.69395393f};
  const BetaParams beta_leg2_p3{1.24888073f, 3.70853247f};
  const BetaParams beta_leg2_p0{2.02570375f, 1.11420266f}; 

  auto beta_pdf = [](float x, const BetaParams& p) -> float {
    if (!(x > 0.f && x < 1.f)) return 0.f;
    const double a = p.a;
    const double b = p.b;
    const double lnB = std::lgamma(a) + std::lgamma(b) - std::lgamma(a + b);
    const double lnpdf = (a - 1.0) * std::log(x) + (b - 1.0) * std::log(1.0 - x) - lnB;
    return static_cast<float>(std::exp(lnpdf));
  };

  auto pick_beta = [&](int ntracks, bool isLep, int leg) -> BetaParams {
    if (isLep) {
     if (leg == 1) {
      return beta_leg1_p0; // 0 here corresponds to 0 truth charged hadrons
     } else {
      return beta_leg2_p0;
     } 
    }
      // no ratio weight on leptonic leg -> why?
    if (leg == 1) {
      if (ntracks >= 3) return beta_leg1_p3;
      if (ntracks >= 1) return beta_leg1_p1;
      return beta_leg1_p0;
    } else {
      if (ntracks >= 3) return beta_leg2_p3;
      if (ntracks >= 1) return beta_leg2_p1;
      return beta_leg2_p0;
    }
  };

  for (int i = 0; i < nsteps; i++) {
    const float phi1 = wrapToPi(phi1_c - PHI_WIN + (i + 0.5f) * dphi1);

    for (int j = 0; j < nsteps; j++) {
      const float phi2 = wrapToPi(phi2_c - PHI_WIN + (j + 0.5f) * dphi2);

      stats.n_phi_pairs++;

      const float sin12 = std::sin(phi2 - phi1);
      if (std::fabs(sin12) < 1e-4f) {
        stats.n_sin12_small++;
        continue;
      }
      const float csc_dphi = 1.f / sin12;

      for (int k = 0; k < nMETsteps; k++) {
        const float sMET_x = MET_x - nMETsig * metres_x + k * dmetx;

        for (int l = 0; l < nMETsteps; l++) {
          const float sMET_y = MET_y - nMETsig * metres_y + l * dmety;

          stats.n_met_points++;

          const float dx = sMET_x - MET_x;
          const float dy = sMET_y - MET_y;
          const double log_w_met = -0.5 * (dx * dx * inv_metres_x2 + dy * dy * inv_metres_y2);
          const double w_met = std::exp(log_w_met);

          // Solve pT1,pT2 from MET decomposition along phi1,phi2
          float pT1 = csc_dphi * ( sMET_x * std::sin(phi2) - sMET_y * std::cos(phi2) );
          float pT2 = -csc_dphi * ( sMET_x * std::sin(phi1) - sMET_y * std::cos(phi1) );

          // Physical requirement: magnitudes positive -> makes wedge in MET / pT space 
          // i.e. force MET to lie in between the two proposed neutrino directions in the transverse plane
          if (pT1 <= 0.f || pT2 <= 0.f) {
            stats.n_pt_negative++;
            continue;
          }

          // ---------------------------
          // Had-had
          if (!isLep1 && !isLep2) {
            stats.n_hadhad_nodes++;

            // IMPORTANT: use tau*_use with mass hypotheses to avoid inefficient solvers
            std::vector<float> pz1 = solve_pz_quadratic_tau(tau1_use, phi1, pT1, isLep1, n_charged_tracks_1, 0.0);
            std::vector<float> pz2 = solve_pz_quadratic_tau(tau2_use, phi2, pT2, isLep2, n_charged_tracks_2, 0.0);

            if (pz1.empty()) { stats.n_pz1_empty++; continue; }
            if (pz2.empty()) { stats.n_pz2_empty++; continue; }

            for (float z1 : pz1) {
              const float px1 = pT1 * std::cos(phi1);
              const float py1 = pT1 * std::sin(phi1);
              const float E1  = std::sqrt(px1*px1 + py1*py1 + z1*z1); // no need to worry about mass hypothesis -> is 0 for hadhad
              TLorentzVector nu1; nu1.SetPxPyPzE(px1, py1, z1, E1);

              for (float z2 : pz2) {
                const float px2 = pT2 * std::cos(phi2);
                const float py2 = pT2 * std::sin(phi2);
                const float E2  = std::sqrt(px2*px2 + py2*py2 + z2*z2); // no need to worry about mass hypothesis -> is 0 for hadhad
                TLorentzVector nu2; nu2.SetPxPyPzE(px2, py2, z2, E2);

                TLorentzVector tau_full_1 = tau1_use + nu1;
                TLorentzVector tau_full_2 = tau2_use + nu2;

                const float theta_3D_1 = tau1_use.Vect().Angle(nu1.Vect());
                const float theta_3D_2 = tau2_use.Vect().Angle(nu2.Vect());
                const float p_tau1     = tau_full_1.P();
                const float p_tau2     = tau_full_2.P();

                float w_theta1=0.f, w_theta2=0.f, w_ratio1=0.f, w_ratio2=0.f;
                if (use_atlas_tf1) {
                  const bool lead1 = tau1_use.Pt() >= tau2_use.Pt();
                  const bool lead2 = !lead1;
                  auto w = atlas_tf1_weights(
                    tau1_use, nu1, isLep1, n_charged_tracks_1, lead1,
                    tau2_use, nu2, isLep2, n_charged_tracks_2, lead2
                  );
                  w_theta1 = w[1]; w_theta2 = w[2]; w_ratio1 = w[3]; w_ratio2 = w[4];
                  if (w[0] <= 0.f) { stats.n_theta_zero++; continue; }
                } else {
                  const float THETA_MAX = 0.3f;
                  const MixCoeffs& K1 =
                    (n_charged_tracks_1 <= 2) ? COEFFS_1PRONG_THESIS : COEFFS_3PRONG_THESIS;
                  const MixCoeffs& K2 =
                    (n_charged_tracks_2 <= 2) ? COEFFS_1PRONG_THESIS : COEFFS_3PRONG_THESIS;
                  //w_theta1 = theta_pdf_mixture_trunc(theta_3D_1, p_tau1, K1, THETA_MAX);
                  //w_theta2 = theta_pdf_mixture_trunc(theta_3D_2, p_tau2, K2, THETA_MAX);
                  w_theta1 = lognormal_pdf_trunc(theta_3D_1, tau1_use.Pt(), n_charged_tracks_1);
                  w_theta2 = lognormal_pdf_trunc(theta_3D_2, tau2_use.Pt(), n_charged_tracks_2);

                  if (w_theta1 <= 0.f || w_theta2 <= 0.f) { stats.n_theta_zero++; continue; }
                  const float r1 = (p_tau1 > 0.f) ? (nu1.P() / p_tau1) : 0.f;
                  const float r2 = (p_tau2 > 0.f) ? (nu2.P() / p_tau2) : 0.f;
                  w_ratio1 = beta_pdf(r1, pick_beta(n_charged_tracks_1, isLep1, 1));
                  w_ratio2 = beta_pdf(r2, pick_beta(n_charged_tracks_2, isLep2, 2));
                  if (w_ratio1 <= 0.f || w_ratio2 <= 0.f) { stats.n_theta_zero++; continue; }
                }
                const float w_miss = 1.f;
                // also check when we're using the ATLAS weighting:
                //std::cout << "checking the derived weights from the ATLAS implementation. w_met: " << w_met <<
                //" w_miss: " << w_miss << " w_theta1: " << w_theta1 << " w_theta2: " << w_theta2 << 
                //" w_ratio1: " << w_ratio1 << " w_ratio1: " << w_ratio1 << std::endl;
                const float w_event = use_atlas_tf1
                  ? static_cast<float>(w_met * w_ratio1 * w_ratio2 * w_theta1 * w_theta2)
                  : static_cast<float>(w_theta1 * w_theta2 * w_met * w_ratio1 * w_ratio2);
                const float mditau  = (tau_full_1 + tau_full_2).M();
                if (diagnostic) {
                  const float denom1 = tau1_use.E() - tau1_use.P() * std::cos(theta_3D_1);
                  const float denom2 = tau2_use.E() - tau2_use.P() * std::cos(theta_3D_2);
                  diag_entries.push_back(
                    {w_event, mditau, theta_3D_1, theta_3D_2, denom1, denom2,
                     static_cast<float>(nu1.P()), static_cast<float>(nu2.P()),
                     p_tau1, p_tau2, w_theta1, w_theta2, w_ratio1, w_ratio2,
                     static_cast<float>(w_met), w_miss}
                  );
                }
                if (weight_components) {
                  weight_components->push_back(
                    {mditau, static_cast<float>(w_met), static_cast<float>(w_theta1), static_cast<float>(w_theta2),
                     static_cast<float>(w_ratio1), static_cast<float>(w_ratio2), static_cast<float>(w_miss), static_cast<float>(w_event)}
                  );
                }

                mditau_solutions.push_back({mditau, w_event});
                stats.n_solutions++;
              }
            }

          // ---------------------------
          // Lep-had (leg1 leptonic)
          } else if (isLep1) {
            stats.n_lephad_nodes++;

            const float mLep = tau1_use.M(); // leptonic leg unchanged
            const float mMax = std::max(0.f, m_tau - mLep);
            const float dm   = (nMass_steps > 0) ? (mMax / nMass_steps) : 0.f;
            if (dm <= 0.f) { stats.n_mscan_invalid++; continue; }

            std::vector<float> pz2 = solve_pz_quadratic_tau(tau2_use, phi2, pT2, isLep2, n_charged_tracks_2, 0.0);
            if (pz2.empty()) { stats.n_pz2_empty++; continue; }

            for (int t = 0; t < nMass_steps; ++t) {
              stats.n_mass_points++;

              const float m_scan = (t + 0.5f) * dm;
              if (m_scan <= 0.f) { stats.n_mscan_invalid++; continue; }

              const float w_miss = w_lep_miss(m_scan, m_tau, mLep);
              if (w_miss <= 0.f) { stats.n_wmiss_zero++; continue; }

              std::vector<float> pz1 = solve_pz_quadratic_tau(
                tau1_use, phi1, pT1, isLep1, n_charged_tracks_1, m_scan
              );
              if (pz1.empty()) { stats.n_pz1_empty++; continue; }

              for (float z1 : pz1) {
                const float px1 = pT1 * std::cos(phi1);
                const float py1 = pT1 * std::sin(phi1);
                const float E1  = std::sqrt(px1*px1 + py1*py1 + z1*z1 + m_scan*m_scan); // need missing mass included for leptonic legs
                TLorentzVector nu1; nu1.SetPxPyPzE(px1, py1, z1, E1);

                for (float z2 : pz2) {
                  const float px2 = pT2 * std::cos(phi2);
                  const float py2 = pT2 * std::sin(phi2);
                  const float E2  = std::sqrt(px2*px2 + py2*py2 + z2*z2);
                  TLorentzVector nu2; nu2.SetPxPyPzE(px2, py2, z2, E2);

                  TLorentzVector tau_full_1 = tau1_use + nu1;
                  TLorentzVector tau_full_2 = tau2_use + nu2;

                  const float theta_3D_1 = tau1_use.Vect().Angle(nu1.Vect());
                  const float theta_3D_2 = tau2_use.Vect().Angle(nu2.Vect());
                  const float p_tau1     = tau_full_1.P();
                  const float p_tau2     = tau_full_2.P();

                  float w_theta1=0.f, w_theta2=0.f, w_ratio1=0.f, w_ratio2=0.f;
                  if (use_atlas_tf1) {
                    const bool lead1 = true; // leptonic leg treated as leading by construction
                    const bool lead2 = false;
                    auto w = atlas_tf1_weights(
                      tau1_use, nu1, isLep1, n_charged_tracks_1, lead1,
                      tau2_use, nu2, isLep2, n_charged_tracks_2, lead2
                    );
                    w_theta1 = w[1]; w_theta2 = w[2]; w_ratio1 = w[3]; w_ratio2 = w[4];
                    if (w[0] <= 0.f) { stats.n_theta_zero++; continue; }
                  } else {
                    
                    w_theta1 = lognormal_pdf_trunc(theta_3D_1, tau1_use.Pt(), -1);
                    w_theta2 = lognormal_pdf_trunc(theta_3D_2, tau2_use.Pt(), n_charged_tracks_2);

                    if (w_theta1 <= 0.f || w_theta2 <= 0.f) { stats.n_theta_zero++; continue; }
                    const float r1 = (p_tau1 > 0.f) ? (nu1.P() / p_tau1) : 0.f;
                    const float r2 = (p_tau2 > 0.f) ? (nu2.P() / p_tau2) : 0.f;
                    w_ratio1 = beta_pdf(r1, pick_beta(n_charged_tracks_1, isLep1, 1));
                    w_ratio2 = beta_pdf(r2, pick_beta(n_charged_tracks_2, isLep2, 2));
                    if (w_ratio1 <= 0.f || w_ratio2 <= 0.f) { stats.n_theta_zero++; continue; }
                  }

                  const float w_event = use_atlas_tf1
                    ? static_cast<float>(w_met * w_miss * w_theta1 * w_theta2 * w_ratio1 * w_ratio2)
                    : static_cast<float>(w_theta1 * w_theta2 * w_met * w_miss * w_ratio1 * w_ratio2);
                  const float mditau  = (tau_full_1 + tau_full_2).M();
                  if (diagnostic) {
                    const float denom1 = tau1_use.E() - tau1_use.P() * std::cos(theta_3D_1);
                    const float denom2 = tau2_use.E() - tau2_use.P() * std::cos(theta_3D_2);
                    diag_entries.push_back(
                      {w_event, mditau, theta_3D_1, theta_3D_2, denom1, denom2,
                       static_cast<float>(nu1.P()), static_cast<float>(nu2.P()),
                       p_tau1, p_tau2, w_theta1, w_theta2, w_ratio1, w_ratio2,
                       static_cast<float>(w_met), w_miss}
                    );
                  }
                  if (weight_components) {
                    weight_components->push_back(
                      {mditau, static_cast<float>(w_met), static_cast<float>(w_theta1), static_cast<float>(w_theta2),
                       static_cast<float>(w_ratio1), static_cast<float>(w_ratio2), static_cast<float>(w_miss), static_cast<float>(w_event)}
                    );
                  }

                  mditau_solutions.push_back({mditau, w_event});
                  stats.n_solutions++;
                }
              }
            }

          // ---------------------------
          // Had-lep (leg2 leptonic)
          } else if (isLep2) {
            stats.n_lephad_nodes++;

            const float mLep = tau2_use.M();
            const float mMax = std::max(0.f, m_tau - mLep);
            // can check the lepton measured mass:
            //std::cout << "mass of the reconstructed leptons " << mLep << std::endl;
            const float dm   = (nMass_steps > 0) ? (mMax / nMass_steps) : 0.f;
            if (dm <= 0.f) { stats.n_mscan_invalid++; continue; }

            std::vector<float> pz1 = solve_pz_quadratic_tau(tau1_use, phi1, pT1, isLep1, n_charged_tracks_1, 0.0);
            if (pz1.empty()) { stats.n_pz1_empty++; continue; }

            for (int t = 0; t < nMass_steps; ++t) {
              stats.n_mass_points++;

              const float m_scan = (t + 0.5f) * dm;
              if (m_scan <= 0.f) { stats.n_mscan_invalid++; continue; }

              const float w_miss = w_lep_miss(m_scan, m_tau, mLep);
              if (w_miss <= 0.f) { stats.n_wmiss_zero++; continue; }

              std::vector<float> pz2 = solve_pz_quadratic_tau(
                tau2_use, phi2, pT2, isLep2, n_charged_tracks_2, m_scan
              );
              if (pz2.empty()) { stats.n_pz2_empty++; continue; }

              for (float z1 : pz1) {
                const float px1 = pT1 * std::cos(phi1);
                const float py1 = pT1 * std::sin(phi1);
                const float E1  = std::sqrt(px1*px1 + py1*py1 + z1*z1);
                TLorentzVector nu1; nu1.SetPxPyPzE(px1, py1, z1, E1);

                for (float z2 : pz2) {
                  const float px2 = pT2 * std::cos(phi2);
                  const float py2 = pT2 * std::sin(phi2);
                  const float E2  = std::sqrt(px2*px2 + py2*py2 + z2*z2 + m_scan*m_scan);
                  TLorentzVector nu2; nu2.SetPxPyPzE(px2, py2, z2, E2);

                  TLorentzVector tau_full_1 = tau1_use + nu1;
                  TLorentzVector tau_full_2 = tau2_use + nu2;

                  const float theta_3D_1 = tau1_use.Vect().Angle(nu1.Vect());
                  const float theta_3D_2 = tau2_use.Vect().Angle(nu2.Vect());
                  const float p_tau1     = tau_full_1.P();
                  const float p_tau2     = tau_full_2.P();

                  float w_theta1=0.f, w_theta2=0.f, w_ratio1=0.f, w_ratio2=0.f;
                  if (use_atlas_tf1) {
                    const bool lead1 = false;
                    const bool lead2 = true;
                    auto w = atlas_tf1_weights(
                      tau1_use, nu1, isLep1, n_charged_tracks_1, lead1,
                      tau2_use, nu2, isLep2, n_charged_tracks_2, lead2
                    );
                    w_theta1 = w[1]; w_theta2 = w[2]; w_ratio1 = w[3]; w_ratio2 = w[4];
                    if (w[0] <= 0.f) { stats.n_theta_zero++; continue; }
                  } else {
                    w_theta1 = lognormal_pdf_trunc(theta_3D_1, tau1_use.Pt(), n_charged_tracks_1);
                    w_theta2 = lognormal_pdf_trunc(theta_3D_2, tau2_use.Pt(), -1);

                    if (w_theta1 <= 0.f || w_theta2 <= 0.f) { stats.n_theta_zero++; continue; }
                    const float r1 = (p_tau1 > 0.f) ? (nu1.P() / p_tau1) : 0.f;
                    const float r2 = (p_tau2 > 0.f) ? (nu2.P() / p_tau2) : 0.f;
                    w_ratio1 = beta_pdf(r1, pick_beta(n_charged_tracks_1, isLep1, 1));
                    w_ratio2 = beta_pdf(r2, pick_beta(n_charged_tracks_2, isLep2, 2));
                    if (w_ratio1 <= 0.f || w_ratio2 <= 0.f) { stats.n_theta_zero++; continue; }
                  }
                  
                  const float w_event = use_atlas_tf1
                    ? static_cast<float>(w_met * w_miss * w_theta1 * w_theta2 * w_ratio1 * w_ratio2)
                    : static_cast<float>(w_theta1 * w_theta2 * w_met * w_miss * w_ratio1 * w_ratio2);
                  const float mditau  = (tau_full_1 + tau_full_2).M();
                  if (diagnostic) {
                    const float denom1 = tau1_use.E() - tau1_use.P() * std::cos(theta_3D_1);
                    const float denom2 = tau2_use.E() - tau2_use.P() * std::cos(theta_3D_2);
                    diag_entries.push_back(
                      {w_event, mditau, theta_3D_1, theta_3D_2, denom1, denom2,
                       static_cast<float>(nu1.P()), static_cast<float>(nu2.P()),
                       p_tau1, p_tau2, w_theta1, w_theta2, w_ratio1, w_ratio2,
                       static_cast<float>(w_met), w_miss}
                    );
                  }
                  if (weight_components) {
                    weight_components->push_back(
                      {mditau, static_cast<float>(w_met), static_cast<float>(w_theta1), static_cast<float>(w_theta2),
                       static_cast<float>(w_ratio1), static_cast<float>(w_ratio2), static_cast<float>(w_miss), static_cast<float>(w_event)}
                    );
                  }

                  mditau_solutions.push_back({mditau, w_event});
                  stats.n_solutions++;
                }
              }
            }

          } else {
            std::cout << "[MMC debug] Neither lep/had? Check configuration." << std::endl;
          }

        } // MET_y
      }   // MET_x
    }     // phi2
  }       // phi1

  // Debug summary for problematic events
  if (mditau_solutions.empty()) {
    std::cout << "[MMC debug] NO SOLUTIONS"
              << " isLep1=" << isLep1 << " isLep2=" << isLep2
              << " Tau1(raw): pT=" << tau1.Pt() << " eta=" << tau1.Eta() << " phi=" << tau1.Phi()
              << " E=" << tau1.E() << " M=" << tau1.M()
              << " Tau1(use): pT=" << tau1_use.Pt() << " eta=" << tau1_use.Eta() << " phi=" << tau1_use.Phi()
              << " E=" << tau1_use.E() << " M=" << tau1_use.M()
              << " Tau2(raw): pT=" << tau2.Pt() << " eta=" << tau2.Eta() << " phi=" << tau2.Phi()
              << " E=" << tau2.E() << " M=" << tau2.M()
              << " Tau2(use): pT=" << tau2_use.Pt() << " eta=" << tau2_use.Eta() << " phi=" << tau2_use.Phi()
              << " E=" << tau2_use.E() << " M=" << tau2_use.M()
              << " MET=(" << MET_x << "," << MET_y << ")"
              << " phi_vis=(" << tau1_use.Phi() << "," << tau2_use.Phi() << ")"
              << " nsteps=" << nsteps << " nMETsteps=" << nMETsteps
              << " nMass_steps=" << nMass_steps
              << std::endl;
    printStats(stats);
  } else if (mditau_solutions.size() < 20) {
    std::cout << "[MMC debug] FEW SOLUTIONS: " << mditau_solutions.size() << std::endl;
    printStats(stats);
  }

  if (diagnostic && !diag_entries.empty()) {
    std::sort(diag_entries.begin(), diag_entries.end(),
              [](const DiagEntry& a, const DiagEntry& b) { return a.w_event > b.w_event; });
    const int nPrint = std::min<int>(diag_topN, diag_entries.size());
    std::cout << "[MMC diagnostic] Top " << nPrint << " solutions by weight (w_event)" << std::endl;
    for (int i = 0; i < nPrint; ++i) {
      const auto& d = diag_entries[i];
      std::cout << "  #" << i
                << " mditau=" << d.mditau
                << " w_event=" << d.w_event
                << " w_met=" << d.w_met
                << " w_theta=(" << d.w_theta1 << "," << d.w_theta2 << ")"
                << " w_ratio=(" << d.w_ratio1 << "," << d.w_ratio2 << ")"
                << " w_miss=" << d.w_miss
                << " theta_3D=(" << d.theta1 << "," << d.theta2 << ")"
                << " denom=(" << d.denom1 << "," << d.denom2 << ")"
                << " nuP=(" << d.nuP1 << "," << d.nuP2 << ")"
                << " p_tau=(" << d.pTau1 << "," << d.pTau2 << ")"
                << std::endl;
    }
  }

  return mditau_solutions;
}



MMCSolutionsAndWeights AnalysisFCChh::solve_ditau_MMC_METScan_para_perp_vispTanglecalibration_weights(
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
) {
  std::vector<std::array<float,8>> weight_components;
  auto solutions = ::solve_ditau_MMC_METScan_para_perp_vispTAngleCalibration(
    tau1, tau2, isLep1, isLep2, n_charged_tracks_1, n_charged_tracks_2,
    MET_x, MET_y, nsteps, metres_x, metres_y, nMETsig, nMETsteps, nMass_steps,
    n_b_jets_medium, n_tau_jets_medium, &weight_components, diagnostic, diag_topN, /*use_atlas_tf1=*/false
  );
  return {std::move(solutions), std::move(weight_components)};
}

