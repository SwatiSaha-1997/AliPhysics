/**************************************************************************
 * Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 *                                                                        *
 * Author: The ALICE Off-line Project.                                    *
 * Contributors are mentioned in the code where appropriate.              *
 *                                                                        *
 * Permission to use, copy, modify and distribute this software and its   *
 * documentation strictly for non-commercial purposes is hereby granted   *
 * without fee, provided that the above copyright notice appears in all   *
 * copies and that both the copyright notice and this permission notice   *
 * appear in the supporting documentation. The authors make no claims     *
 * about the suitability of this software for any purpose. It is          *
 * provided "as is" without express or implied warranty.                  *
 **************************************************************************/
#ifndef AliAnalysisTaskCorrPbPb_treemerge_v2_H
#define AliAnalysisTaskCorrPbPb_treemerge_v2_H

#include "AliAnalysisTaskSE.h"
#include "TString.h"
#include "TTree.h"
#include "AliEventCuts.h"

class TList;
class TTree;

class AliESDEvent;
//class AliAODEvent;
class AliESDtrackCuts;
class AliMCEvent;
class AliStack;
class AliVTrack;
class AliAODTrack;

class TH1D;
class TH2D;
class TH3D;
class TProfile;
class AliPIDResponse;
class AliMultSelection;


class AliAnalysisTaskCorrPbPb_treemerge_v2 : public AliAnalysisTaskSE {
 public:
  AliAnalysisTaskCorrPbPb_treemerge_v2();
  AliAnalysisTaskCorrPbPb_treemerge_v2(const char *name);
  virtual ~AliAnalysisTaskCorrPbPb_treemerge_v2();
  
  virtual void   UserCreateOutputObjects();
  virtual void   UserExec(Option_t *option);
  virtual void   Terminate(Option_t *);
  Bool_t GetEvent();
  Bool_t PassedTrackQualityCuts (AliAODTrack *track);
  Bool_t KaonSelector (AliVTrack *track, Double_t nSigmaCut); 
  Bool_t ProtonSelector (AliVTrack *track, Double_t nSigmaCut); 
  Bool_t PionSelector (AliVTrack *track, Double_t nSigmaCut); 
  Bool_t PassedPIDSelection (AliAODTrack *track, AliPID::EParticleType type);
  Bool_t PassedSingleParticlePileUpCuts(AliAODTrack *track);
  void GetMCEffCorrectionHist();

  void SetListForTrkCorr (TList *fList)
  {
 	this->fListTRKCorr = (TList*) fList->Clone();
  }

  void SetVzRangeMax(Double_t VzMax)
  {
    this->fVertexZMax = VzMax;
  }
   void SetPileupCutValue (Int_t cutval)
  {
    this->fPileupCutVal = cutval;
  }
  void SetCentralityEstimator (Int_t val)
  {
    this->fCentralityEstimator_flag = val;
  }
  void SetTrackFilterBit(Int_t FBno)
  {
    this->fFBNo = FBno;
  }
  void SetMaxChi2PerTPCClusterRange(Double_t chi2tpc)
  {
    this->fChi2TPC = chi2tpc;
  }
  void SetMaxChi2PerITSClusterRange(Double_t chi2its)
  {
    this->fChi2ITS = chi2its;
  }
  void SetPIDnSigmaCut(Double_t PIDnSigmaCut_pion, Double_t PIDnSigmaCut_kaon, Double_t PIDnSigmaCut_proton)
  {
    this->fPIDnSigmaPionCut = PIDnSigmaCut_pion;
    this->fPIDnSigmaKaonCut = PIDnSigmaCut_kaon;
    this->fPIDnSigmaProtonCut = PIDnSigmaCut_proton;
  }
  void SetMinNoTPCCrossedRows(Double_t tpccrossedrows)
  {
    this->fTPCcrossedrows = tpccrossedrows;
  }
  void SetEtaCut(Double_t eta_max)
  {
    this->fEtaMax = eta_max;
  
  }
  void SetTreeName(TString TreeName)
  {
    fTreeName = TreeName;
  }
  void SetPtMaxMinCutsSet1and2(Double_t ptmin1, Double_t ptmax1, Double_t ptmin2, Double_t ptmax2)
  {
    this->fPtMinSet1 = ptmin1;
    this->fPtMaxSet1 = ptmax1;
    this->fPtMinSet2 = ptmin2;
    this->fPtMaxSet2 = ptmax2;
  }
  

  
 private:
  
  
  AliESDEvent *fESDevent;
  AliAODEvent *fAODevent;
  AliVEvent *fInputEvent;
  AliPIDResponse   *fPIDResponse;
  AliESDtrackCuts  *fESDtrackCuts;
  AliESDtrackCuts  *fESDtrackCuts_primary;
  AliAnalysisUtils *fUtils;
  AliEventCuts fAODeventCuts;
  TList *fOutputList;
  TList *fQAList;
  Double_t fMultLow;
  Double_t fMultHigh;
  TH1D *hNumberOfEvents;
  TH1D *hNumberOfKaonPlus;
  TH1D *hNumberOfKaonMinus;
  TH1D *hNumberOfPionPlus;
  TH1D *hNumberOfPionMinus;
  TH1D *hNumberOfProtonPlus;
  TH1D *hNumberOfProtonMinus;

  //ftreeEvent object variables
  TTree *fTreeEvent;
  Float_t fTreeVariableCentrality;
  //reconstruced
  Float_t fNoKaonPlus_ptmax2;
  Float_t fNoKaonMinus_ptmax2;
  Float_t fNoKaonPlus_ptmax3;
  Float_t fNoKaonMinus_ptmax3;
  Float_t fNoPionPlus_ptmax2;
  Float_t fNoPionMinus_ptmax2;
  Float_t fNoPionPlus_ptmax3;
  Float_t fNoPionMinus_ptmax3;
  Float_t fNoProtonPlus_ptmax2;
  Float_t fNoProtonMinus_ptmax2;
  Float_t fNoProtonPlus_ptmax3;
  Float_t fNoProtonMinus_ptmax3;
  //CORRECTED
  Float_t fCorrectedNoKaonPlus_ptmax2;
  Float_t fCorrectedNoKaonMinus_ptmax2;
  Float_t fCorrectedNoKaonPlus_ptmax3;
  Float_t fCorrectedNoKaonMinus_ptmax3;
  Float_t fCorrectedNoPionPlus_ptmax2;
  Float_t fCorrectedNoPionMinus_ptmax2;
  Float_t fCorrectedNoPionPlus_ptmax3;
  Float_t fCorrectedNoPionMinus_ptmax3;
  Float_t fCorrectedNoProtonPlus_ptmax2;
  Float_t fCorrectedNoProtonMinus_ptmax2;
  Float_t fCorrectedNoProtonPlus_ptmax3;
  Float_t fCorrectedNoProtonMinus_ptmax3;
  //Eff.square factors
  Float_t fEffSqrFactrPionMinus_ptmax2;
  Float_t fEffSqrFactrPionPlus_ptmax2;
  Float_t fEffSqrFactrProtonMinus_ptmax2;
  Float_t fEffSqrFactrProtonPlus_ptmax2;
  Float_t fEffSqrFactrKaonMinus_ptmax2;
  Float_t fEffSqrFactrKaonPlus_ptmax2;
  Float_t fEffSqrFactrPionMinus_ptmax3;
  Float_t fEffSqrFactrPionPlus_ptmax3;
  Float_t fEffSqrFactrProtonMinus_ptmax3;
  Float_t fEffSqrFactrProtonPlus_ptmax3;
  Float_t fEffSqrFactrKaonMinus_ptmax3;
  Float_t fEffSqrFactrKaonPlus_ptmax3;

  //Efficiency list of histograms
  TList *fListTRKCorr; 
  TH1D *fHistMCEffKaonPlus;
  TH1D *fHistMCEffKaonMinus;
  TH1D *fHistMCEffPionPlus;
  TH1D *fHistMCEffPionMinus;
  TH1D *fHistMCEffProtonPlus;
  TH1D *fHistMCEffProtonMinus;
  TH1D *fEffPionPlus[9];
  TH1D *fEffKaonPlus[9];
  TH1D *fEffProtonPlus[9];
  TH1D *fEffPionMinus[9];
  TH1D *fEffKaonMinus[9];
  TH1D *fEffProtonMinus[9];
 
  Double_t fVertexZMax;
  Int_t fFBNo;
  Double_t fChi2TPC;
  Double_t fChi2ITS;
  Double_t fPIDnSigmaPionCut;
  Double_t fPIDnSigmaKaonCut;
  Double_t fPIDnSigmaProtonCut;
  Double_t fTPCcrossedrows;
  Double_t fEtaMax;
  Double_t fPtMinSet1;
  Double_t fPtMaxSet1;
  Double_t fPtMinSet2;
  Double_t fPtMaxSet2;
  TString fTreeName;

  //Pileup cut val
  Int_t fPileupCutVal;
  
  //Flag to select which centrality estimator
  Int_t fCentralityEstimator_flag;
  

  /*
  //Custom Functions:
  TF1 *fCenCutLowPU;
  TF1 *fCenCutHighPU;
  TF1 *fSPDCutPU;
  TF1 *fV0CutPU;
  TF1 *fMultCutPU;

  //Argument variables
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  TString fTreeName;
  Double_t fEtaMax;
  Double_t fVertexZMax;
  Double_t fDCAxyMax;
  Double_t fDCAzMax;
  Double_t fChi2TPC;
  Double_t fChi2ITS;
  Double_t fNCrossedRowsTPC;
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  */
 
  
  AliAnalysisTaskCorrPbPb_treemerge_v2(const AliAnalysisTaskCorrPbPb_treemerge_v2&);
  AliAnalysisTaskCorrPbPb_treemerge_v2& operator=(const AliAnalysisTaskCorrPbPb_treemerge_v2&);  
  ClassDef(AliAnalysisTaskCorrPbPb_treemerge_v2, 1);
};

#endif
