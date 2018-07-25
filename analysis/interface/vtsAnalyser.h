#ifndef vtsAnalyser_H
#define vtsAnalyser_H

#include "hadAnalyser.h"

class vtsAnalyser : public hadAnalyser 
{
private:
  // for Test()
  std::vector<int>   b_GenPart_isGenFrom_vec; std::vector<bool> b_GenPart_isGenFromTop_vec; std::vector<bool> b_GenPart_isGenFromW_vec; std::vector<bool> b_GenPart_isFromKstar_vec;
  std::vector<float> b_GenPart_d_vec; std::vector<float> b_GenPart_pt_vec; std::vector<float> b_GenPart_eta_vec; std::vector<float> b_GenPart_phi_vec; std::vector<float> b_GenPart_mass_vec;
  std::vector<float> b_GenPart_x_j_vec; std::vector<float> b_GenPart_dr_j_vec; std::vector<bool> b_GenPart_isInSJet_j_vec;
  std::vector<float> b_GenPart_x_gj_vec; std::vector<float> b_GenPart_dr_gj_vec; std::vector<bool> b_GenPart_isInSJet_gj_vec;

  std::vector<int>   b_hadTruth_pdgId_vec; std::vector<int> b_hadTruth_nMatched_vec; std::vector<int> b_hadTruth_isFrom_vec;
  std::vector<bool>  b_hadTruth_isHadFromTop_vec; std::vector<bool> b_hadTruth_isHadFromW_vec; std::vector<bool> b_hadTruth_isHadFromS_vec; std::vector<bool> b_hadTruth_isHadFromC_vec; std::vector<bool> b_hadTruth_isHadFromB_vec;
  std::vector<float> b_hadTruth_d_vec; std::vector<float> b_hadTruth_pt_vec; std::vector<float> b_hadTruth_eta_vec; std::vector<float> b_hadTruth_phi_vec; std::vector<float> b_hadTruth_mass_vec;
  std::vector<float> b_hadTruth_lxy_vec; std::vector<float> b_hadTruth_lxySig_vec; std::vector<float> b_hadTruth_l3D_vec; std::vector<float> b_hadTruth_l3DSig_vec; std::vector<float> b_hadTruth_legDR_vec;
  std::vector<float> b_hadTruth_angleXY_vec; std::vector<float> b_hadTruth_angleXYZ_vec; std::vector<float> b_hadTruth_chi2_vec; std::vector<float> b_hadTruth_dca_vec;
  std::vector<float> b_hadTruth_dau1_chi2_vec; std::vector<float> b_hadTruth_dau1_ipsigXY_vec; std::vector<float> b_hadTruth_dau1_ipsigZ_vec; std::vector<float> b_hadTruth_dau1_pt_vec;
  std::vector<float> b_hadTruth_dau2_chi2_vec; std::vector<float> b_hadTruth_dau2_ipsigXY_vec; std::vector<float> b_hadTruth_dau2_ipsigZ_vec; std::vector<float> b_hadTruth_dau2_pt_vec;
  std::vector<float> b_hadTruth_x_j_vec; std::vector<float> b_hadTruth_dr_j_vec; std::vector<bool> b_hadTruth_isInSJet_j_vec;
  std::vector<float> b_hadTruth_x_gj_vec; std::vector<float> b_hadTruth_dr_gj_vec; std::vector<bool> b_hadTruth_isInSJet_gj_vec;

  // for CollectVar()
  float b_MET_pt, b_MET_phi, b_MET_sumEt;

  // for MatchingForMC()
  std::map<unsigned int, int> qjMapForMC_; std::map<unsigned int, int> qgjMapForMC_;
  std::vector<int> tqMC_; std::vector<int> wqMC_;
  std::vector<struct JetStat> recoJet_; std::vector<struct JetStat> genJet_;

  //functions
  void ResetBranch();
  void MakeBranch(TTree* t);
  void MatchingForMC();
  void HadronAnalysis();

  bool isGenFrom(int count, int idx, int & isFrom, bool & isFromTop, bool & isFromW, bool & isFromKstar);
  void Test();
  void CollectVar();

public:
  void setOutput(std::string outputName);

  vtsAnalyser(TTree *tree=0, TTree *had=0, TTree *hadTruth=0, Bool_t isMC = false, Bool_t dl = false, Bool_t sle = false, Bool_t slm = false);
  vtsAnalyser(TTree *tree=0, Bool_t isMC=false, Bool_t dl=false, Bool_t sle=false, Bool_t slm=false) : vtsAnalyser(tree, 0, 0, isMC, dl, sle, slm) {}
  ~vtsAnalyser();
  virtual void     Loop();
};

vtsAnalyser::vtsAnalyser(TTree *tree, TTree *had, TTree *hadTruth, Bool_t isMC, Bool_t dl, Bool_t sle, Bool_t slm) : hadAnalyser(tree, had, hadTruth, isMC, dl, sle, slm)
{ }

vtsAnalyser::~vtsAnalyser()
{ }

#endif
