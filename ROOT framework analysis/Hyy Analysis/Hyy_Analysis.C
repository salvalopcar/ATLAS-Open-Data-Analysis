//==============================================================//
//                                                              //
//                                                              //
//                  Analysis of H -> yy decay                   //
//                                                              //
//                                                              //
//==============================================================//
  

#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <cstring>
#include <stdio.h>

#include <TMath.h>
#include <TChain.h>
#include <TLorentzVector.h>
#include <TFile.h>


void Hyy_Analysis () {

  unsigned t0, t1;          // Execution time variables

  t0 = clock ();


  // DEFINE HISTOGRAMS

    // DATA

        TH1F *hist_myy1_Data = new TH1F("hist_myy1_Data", "Diphoton invariant mass; m_{#gamma#gamma} [GeV]; Data - bkg", 30, 105, 160);
        hist_myy1_Data -> SetMarkerColor(kBlack);
        hist_myy1_Data -> GetXaxis () -> SetLabelSize (0.13);
        hist_myy1_Data -> GetXaxis () -> SetTitleSize (0.14);
        hist_myy1_Data -> GetXaxis () -> SetTitleOffset (0.85);
        hist_myy1_Data -> GetYaxis () -> SetLabelSize (0.13);
        hist_myy1_Data -> GetYaxis () -> SetTitleSize (0.13);
        hist_myy1_Data -> GetYaxis () -> SetTitleOffset (0.35);
        hist_myy1_Data -> GetYaxis () -> CenterTitle ();

        TH1F *hist_myy2_Data = new TH1F("hist_myy2_Data", "Diphoton invariant mass unconv. central; m_{#gamma#gamma} [GeV]; Data - bkg", 30, 105, 160);
        hist_myy2_Data -> SetMarkerColor(kBlack);
        hist_myy2_Data -> GetXaxis () -> SetLabelSize (0.13);
        hist_myy2_Data -> GetXaxis () -> SetTitleSize (0.14);
        hist_myy2_Data -> GetXaxis () -> SetTitleOffset (0.85);
        hist_myy2_Data -> GetYaxis () -> SetLabelSize (0.13);
        hist_myy2_Data -> GetYaxis () -> SetTitleSize (0.13);
        hist_myy2_Data -> GetYaxis () -> SetTitleOffset (0.35);
        hist_myy2_Data -> GetYaxis () -> CenterTitle ();


    // HIGGS

        TH1F *hist_myy1_Higgs = new TH1F("hist_myy1_Higgs", "Diphoton invariant mass; m_{#gamma#gamma} [GeV]; Events / bin", 30, 105, 160);
        hist_myy1_Higgs -> SetLineColor(kBlack);

        TH1F *hist_myy2_Higgs = new TH1F("hist_myy2_Higgs", "Diphoton invariant mass unconv. central; m_{#gamma#gamma} [GeV]; Events / bin", 30, 105, 160);
        hist_myy2_Higgs -> SetLineColor(kBlack);


    // DATA + HIGGS

        TH1F *hist_myy1 = new TH1F("hist_myy1", "Diphoton invariant mass; m_{#gamma#gamma} [GeV]; Events / bin", 30, 105, 160);

        TH1F *hist_myy2 = new TH1F("hist_myy2", "Diphoton invariant mass unconv. central; m_{#gamma#gamma} [GeV]; Events / bin", 30, 105, 160);


  // 0: Data, 1: ggF Higgs, 2: VBF Higgs, 3: WH Higgs, 4: ZH Higgs, 5: tt Higgs

    int type = 0;


  // LOCAL PATH

    TString path = "/media/sf_TFG/Datos";


 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  for ( type = 0; type < 6; type ++ )
  {

    TChain* fChain = new TChain("mini");


  // OPEN FILES

    // DATA

        if ( type == 0 )
        {

            fChain -> AddFile (path + "/GamGam/Data/data_A.GamGam.root"); 
            fChain -> AddFile (path + "/GamGam/Data/data_B.GamGam.root");
            fChain -> AddFile (path + "/GamGam/Data/data_C.GamGam.root");
            fChain -> AddFile (path + "/GamGam/Data/data_D.GamGam.root");

        }


    // ggF HIGGS

        if ( type == 1 )
        {

            fChain -> AddFile (path + "/GamGam/MC/mc_343981.ggH125_gamgam.GamGam.root");

        }


    // VBF HIGGS

        if ( type == 2 )
        {

            fChain -> AddFile (path + "/GamGam/MC/mc_345041.VBFH125_gamgam.GamGam.root");

        }


    // WH HIGGS

        if ( type == 3 )
        {

            fChain -> AddFile (path + "/GamGam/MC/mc_345318.WpH125J_Wincl_gamgam.GamGam.root");

        }


    // ZH HIGGS

        if ( type == 4 )
        {

            fChain -> AddFile (path + "/GamGam/MC/mc_345319.ZH125J_Zincl_gamgam.GamGam.root");

        }


    // tt HIGGS

        if ( type == 5 )
        {

            fChain -> AddFile (path + "/GamGam/MC/mc_341081.ttH125_gamgam.GamGam.root");

        }


    // DEFINE VARIABLES

      // EVENTS NUMBER

        Int_t             RunNumber = 0;
        Int_t             EventNumber = 0;
        Int_t             ChannelNumber = 0;


      // WEIGHT

        Float_t           mcWeight = 0;
        Float_t           XSection = 0;
        Float_t           SumWeights = 0;
        Float_t           SF_Pileup = 0;
        Float_t           SF_Ele = 0;
        Float_t           SF_Muon = 0;
        Float_t           SF_Photon = 0;
        Float_t           SF_Tau = 0;
        Float_t           SF_btag = 0;
        Float_t           SF_LepTrig = 0;
        Float_t           SF_PhotonTrig = 0;


      // TRIGER

        Bool_t            TrigE = 0;
        Bool_t            TrigM = 0;
        Bool_t            TrigP = 0;


      // LEPTONS  

        UInt_t            Lep_n = 0;
        vector<bool>      *Lep_truthMatched = 0;
        vector<bool>      *Lep_trigMatched = 0;
        vector<float>     *Lep_pt = 0;
        vector<float>     *Lep_eta = 0;
        vector<float>     *Lep_phi = 0;
        vector<float>     *Lep_E = 0;
        vector<float>     *Lep_z0 = 0;
        vector<int>       *Lep_charge = 0;
        vector<int>       *Lep_type = 0;
        vector<bool>      *Lep_isTightID = 0;
        vector<float>     *Lep_ptcone30 = 0;
        vector<float>     *Lep_etcone20 = 0;
        vector<float>     *Lep_trackd0pvunbiased = 0;
        vector<float>     *Lep_tracksigd0pvunbiased = 0;


      // ETMISS

        Float_t           Met_et = 0;
        Float_t           Met_phi = 0;


      // JETS

        UInt_t            Jet_n = 0;
        vector<float>     *Jet_pt = 0;
        vector<float>     *Jet_eta = 0;
        vector<float>     *Jet_phi = 0;
        vector<float>     *Jet_E = 0;
        vector<float>     *Jet_jvt = 0;
        vector<int>       *Jet_trueflav = 0;
        vector<bool>      *Jet_truthMatched = 0;
        vector<float>     *Jet_MV2c10 = 0;


      // PHOTONS

        UInt_t            Photon_n = 0;
        vector<bool>      *Photon_truthMatched = 0;
        vector<bool>      *Photon_trigMatched = 0;
        vector<float>     *Photon_pt = 0;
        vector<float>     *Photon_eta = 0;
        vector<float>     *Photon_phi = 0;
        vector<float>     *Photon_E = 0;
        vector<bool>      *Photon_isTightID = 0;
        vector<float>     *Photon_ptcone30 = 0;
        vector<float>     *Photon_etcone20 = 0;
        vector<int>       *Photon_convType = 0;


      // LARGE R JETS

        UInt_t            LargeRjet_n = 0;
        vector<float>     *LargeRjet_pt = 0;
        vector<float>     *LargeRjet_eta = 0;
        vector<float>     *LargeRjet_phi = 0;
        vector<float>     *LargeRjet_E = 0;
        vector<float>     *LargeRjet_m = 0;
        vector<int>       *LargeRjet_truthMatched = 0;
        vector<float>     *LargeRjet_D2 = 0;
        vector<float>     *LargeRjet_tau32 = 0;


      // TAU

        UInt_t            Tau_n = 0;
        vector<float>     *Tau_pt = 0;
        vector<float>     *Tau_eta = 0;
        vector<float>     *Tau_phi = 0;
        vector<float>     *Tau_E = 0;
        vector<int>       *Tau_charge = 0;
        vector<bool>      *Tau_isTightID = 0;
        vector<bool>      *Tau_truthMatched = 0;
        vector<bool>      *Tau_trigMatched = 0;
        vector<int>       *Tau_nTracks = 0;
        vector<float>     *Tau_BDTid = 0;
        Float_t           Ditau_m = 0;


      // UNCERTAINTY

        vector<float>     *Lep_pt_syst = 0;
        Float_t           *Met_et_syst = 0;
        vector<float>     *Jet_pt_syst = 0;
        vector<float>     *Photon_pt_syst = 0;
        vector<float>     *LargeRjet_pt_syst = 0;
        vector<float>     *Tau_pt_syst = 0;


      // BRANCHES

        TBranch           *b_runNumber = 0;
        TBranch           *b_eventNumber = 0;
        TBranch           *b_channelNumber = 0;
        TBranch           *b_mcWeight = 0;
        TBranch           *b_XSection = 0;
        TBranch           *b_SumWeights = 0;
        TBranch           *b_SF_Pileup = 0;
        TBranch           *b_SF_Ele = 0;
        TBranch           *b_SF_Muon = 0;
        TBranch           *b_SF_Photon = 0;
        TBranch           *b_SF_Tau = 0;
        TBranch           *b_SF_btag = 0;
        TBranch           *b_SF_LepTrig = 0;
        TBranch           *b_SF_PhotonTrig = 0;
        TBranch           *b_TrigE = 0;
        TBranch           *b_TrigM = 0;
        TBranch           *b_TrigP = 0;
        TBranch           *b_Lep_n = 0;
        TBranch           *b_Lep_truthMatched = 0;
        TBranch           *b_Lep_trigMatched = 0;
        TBranch           *b_Lep_pt = 0;
        TBranch           *b_Lep_eta = 0;
        TBranch           *b_Lep_phi = 0;
        TBranch           *b_Lep_E = 0;
        TBranch           *b_Lep_z0 = 0;
        TBranch           *b_Lep_charge = 0;
        TBranch           *b_Lep_type = 0;
        TBranch           *b_Lep_isTightID = 0;
        TBranch           *b_Lep_ptcone30 = 0;
        TBranch           *b_Lep_etcone20 = 0;
        TBranch           *b_Lep_trackd0pvunbiased = 0;
        TBranch           *b_Lep_tracksigd0pvunbiased = 0;
        TBranch           *b_Met_et = 0;
        TBranch           *b_Met_phi = 0;
        TBranch           *b_Jet_n = 0;
        TBranch           *b_Jet_pt = 0;
        TBranch           *b_Jet_eta = 0;
        TBranch           *b_Jet_phi = 0;
        TBranch           *b_Jet_E = 0;
        TBranch           *b_Jet_jvt = 0;
        TBranch           *b_Jet_trueflav = 0;
        TBranch           *b_Jet_truthMatched = 0;
        TBranch           *b_Jet_MV2c10 = 0;
        TBranch           *b_Photon_n = 0;
        TBranch           *b_Photon_truthMatched = 0;
        TBranch           *b_Photon_trigMatched = 0;
        TBranch           *b_Photon_pt = 0;
        TBranch           *b_Photon_eta = 0;
        TBranch           *b_Photon_phi = 0;
        TBranch           *b_Photon_E = 0;
        TBranch           *b_Photon_isTightID = 0;
        TBranch           *b_Photon_ptcone30 = 0;
        TBranch           *b_Photon_etcone20 = 0;
        TBranch           *b_Photon_convType = 0;
        TBranch           *b_LargeRjet_n = 0;
        TBranch           *b_LargeRjet_pt = 0;
        TBranch           *b_LargeRjet_eta = 0;
        TBranch           *b_LargeRjet_phi = 0;
        TBranch           *b_LargeRjet_E = 0;
        TBranch           *b_LargeRjet_m = 0;
        TBranch           *b_LargeRjet_truthMatched = 0;
        TBranch           *b_LargeRjet_D2 = 0;
        TBranch           *b_LargeRjet_tau32 = 0;
        TBranch           *b_Tau_n = 0;
        TBranch           *b_Tau_pt = 0;
        TBranch           *b_Tau_eta = 0;
        TBranch           *b_Tau_phi = 0;
        TBranch           *b_Tau_E = 0;
        TBranch           *b_Tau_charge = 0;
        TBranch           *b_Tau_isTightID = 0;
        TBranch           *b_Tau_truthMatched = 0;
        TBranch           *b_Tau_trigMatched = 0;
        TBranch           *b_Tau_nTracks = 0;
        TBranch           *b_Tau_BDTid = 0;
        TBranch           *b_Ditau_m = 0;
        TBranch           *b_Lep_pt_syst = 0;
        TBranch           *b_Met_et_syst = 0;
        TBranch           *b_Jet_pt_syst = 0;
        TBranch           *b_Photon_pt_syst = 0;
        TBranch           *b_LargeRjet_pt_syst = 0;
        TBranch           *b_Tau_pt_syst = 0;


    // READ FILES

        fChain -> SetBranchAddress ( "runNumber",                         &RunNumber,                             &b_runNumber);
        fChain -> SetBranchAddress ( "eventNumber",                       &EventNumber,                           &b_eventNumber);
        fChain -> SetBranchAddress ( "channelNumber",                     &ChannelNumber,                         &b_channelNumber);

        fChain -> SetBranchAddress ( "mcWeight",                          &mcWeight,                              &b_mcWeight );
        fChain -> SetBranchAddress ( "XSection",                          &XSection,                              &b_XSection );
        fChain -> SetBranchAddress ( "SumWeights",                        &SumWeights,                            &b_SumWeights );
        fChain -> SetBranchAddress ( "scaleFactor_PILEUP",                &SF_Pileup,                             &b_SF_Pileup );
        fChain -> SetBranchAddress ( "scaleFactor_ELE",                   &SF_Ele,                                &b_SF_Ele );
        fChain -> SetBranchAddress ( "scaleFactor_MUON",                  &SF_Muon,                               &b_SF_Muon );
        fChain -> SetBranchAddress ( "scaleFactor_PHOTON",                &SF_Photon,                             &b_SF_Photon );
        fChain -> SetBranchAddress ( "scaleFactor_TAU",                   &SF_Tau,                                &b_SF_Tau );
        fChain -> SetBranchAddress ( "scaleFactor_BTAG",                  &SF_btag,                               &b_SF_btag );
        fChain -> SetBranchAddress ( "scaleFactor_LepTRIGGER",            &SF_LepTrig,                            &b_SF_LepTrig );
        fChain -> SetBranchAddress ( "scaleFactor_PhotonTRIGGER",         &SF_PhotonTrig,                         &b_SF_PhotonTrig );

        fChain -> SetBranchAddress ( "trigE",                             &TrigE,                                 &b_TrigE );
        fChain -> SetBranchAddress ( "trigM",                             &TrigM,                                 &b_TrigM );
        fChain -> SetBranchAddress ( "trigP",                             &TrigP,                                 &b_TrigP );

        fChain -> SetBranchAddress ( "lep_n",                             &Lep_n,                                 &b_Lep_n );
        fChain -> SetBranchAddress ( "lep_truthMatched",                  &Lep_truthMatched,                      &b_Lep_truthMatched );
        fChain -> SetBranchAddress ( "lep_trigMatched",                   &Lep_trigMatched,                       &b_Lep_trigMatched );
        fChain -> SetBranchAddress ( "lep_pt",                            &Lep_pt,                                &b_Lep_pt);
        fChain -> SetBranchAddress ( "lep_eta",                           &Lep_eta,                               &b_Lep_eta );
        fChain -> SetBranchAddress ( "lep_phi",                           &Lep_phi,                               &b_Lep_phi );
        fChain -> SetBranchAddress ( "lep_E",                             &Lep_E,                                 &b_Lep_E );
        fChain -> SetBranchAddress ( "lep_z0",                            &Lep_z0,                                &b_Lep_z0 );
        fChain -> SetBranchAddress ( "lep_charge",                        &Lep_charge,                            &b_Lep_charge );
        fChain -> SetBranchAddress ( "lep_type",                          &Lep_type,                              &b_Lep_type );
        fChain -> SetBranchAddress ( "lep_isTightID",                     &Lep_isTightID,                         &b_Lep_isTightID );
        fChain -> SetBranchAddress ( "lep_ptcone30",                      &Lep_ptcone30,                          &b_Lep_ptcone30 );
        fChain -> SetBranchAddress ( "lep_etcone20",                      &Lep_etcone20,                          &b_Lep_etcone20 );
        fChain -> SetBranchAddress ( "lep_trackd0pvunbiased",             &Lep_trackd0pvunbiased,                 &b_Lep_trackd0pvunbiased );
        fChain -> SetBranchAddress ( "lep_tracksigd0pvunbiased",          &Lep_tracksigd0pvunbiased,              &b_Lep_tracksigd0pvunbiased );

        fChain -> SetBranchAddress ( "met_et",                            &Met_et,                                &b_Met_et );
        fChain -> SetBranchAddress ( "met_phi",                           &Met_phi,                               &b_Met_phi );

        fChain -> SetBranchAddress ( "jet_n",                             &Jet_n,                                 &b_Jet_n );
        fChain -> SetBranchAddress ( "jet_pt",                            &Jet_pt,                                &b_Jet_pt );
        fChain -> SetBranchAddress ( "jet_eta",                           &Jet_eta,                               &b_Jet_eta );
        fChain -> SetBranchAddress ( "jet_phi",                           &Jet_phi,                               &b_Jet_phi );
        fChain -> SetBranchAddress ( "jet_E",                             &Jet_E,                                 &b_Jet_E );
        fChain -> SetBranchAddress ( "jet_jvt",                           &Jet_jvt,                               &b_Jet_jvt );
        fChain -> SetBranchAddress ( "jet_trueflav",                      &Jet_trueflav,                          &b_Jet_trueflav );
        fChain -> SetBranchAddress ( "jet_truthMatched",                  &Jet_truthMatched,                      &b_Jet_truthMatched );
        fChain -> SetBranchAddress ( "jet_MV2c10",                        &Jet_MV2c10,                            &b_Jet_MV2c10 );

        fChain -> SetBranchAddress ( "photon_n",                          &Photon_n,                              &b_Photon_n );
        fChain -> SetBranchAddress ( "photon_truthMatched",               &Photon_truthMatched,                   &b_Photon_truthMatched );
        fChain -> SetBranchAddress ( "photon_trigMatched",                &Photon_trigMatched,                    &b_Photon_trigMatched );
        fChain -> SetBranchAddress ( "photon_pt",                         &Photon_pt,                             &b_Photon_pt );
        fChain -> SetBranchAddress ( "photon_eta",                        &Photon_eta,                            &b_Photon_eta );
        fChain -> SetBranchAddress ( "photon_phi",                        &Photon_phi,                            &b_Photon_phi );
        fChain -> SetBranchAddress ( "photon_E",                          &Photon_E,                              &b_Photon_E );
        fChain -> SetBranchAddress ( "photon_isTightID",                  &Photon_isTightID,                      &b_Photon_isTightID );
        fChain -> SetBranchAddress ( "photon_ptcone30",                   &Photon_ptcone30,                       &b_Photon_ptcone30 );
        fChain -> SetBranchAddress ( "photon_etcone20",                   &Photon_etcone20,                       &b_Photon_etcone20 );
        fChain -> SetBranchAddress ( "photon_convType",                   &Photon_convType,                       &b_Photon_convType );

        fChain -> SetBranchAddress ( "largeRjet_n",                       &LargeRjet_n,                           &b_LargeRjet_n );
        fChain -> SetBranchAddress ( "largeRjet_pt",                      &LargeRjet_pt,                          &b_LargeRjet_pt );
        fChain -> SetBranchAddress ( "largeRjet_eta",                     &LargeRjet_eta,                         &b_LargeRjet_eta );
        fChain -> SetBranchAddress ( "largeRjet_phi",                     &LargeRjet_phi,                         &b_LargeRjet_phi );
        fChain -> SetBranchAddress ( "largeRjet_E",                       &LargeRjet_E,                           &b_LargeRjet_E );
        fChain -> SetBranchAddress ( "largeRjet_m",                       &LargeRjet_m,                           &b_LargeRjet_m );
        fChain -> SetBranchAddress ( "largeRjet_truthMatched",            &LargeRjet_truthMatched,                &b_LargeRjet_truthMatched );
        fChain -> SetBranchAddress ( "largeRjet_D2",                      &LargeRjet_D2,                          &b_LargeRjet_D2 );
        fChain -> SetBranchAddress ( "largeRjet_tau32",                   &LargeRjet_tau32,                       &b_LargeRjet_tau32 );

        fChain -> SetBranchAddress ( "tau_n",                             &Tau_n,                                 &b_Tau_n );
        fChain -> SetBranchAddress ( "tau_pt",                            &Tau_pt,                                &b_Tau_pt);
        fChain -> SetBranchAddress ( "tau_eta",                           &Tau_eta,                               &b_Tau_eta );
        fChain -> SetBranchAddress ( "tau_phi",                           &Tau_phi,                               &b_Tau_phi );
        fChain -> SetBranchAddress ( "tau_E",                             &Tau_E,                                 &b_Tau_E );
        fChain -> SetBranchAddress ( "tau_charge",                        &Tau_charge,                            &b_Tau_charge );
        fChain -> SetBranchAddress ( "tau_isTightID",                     &Tau_isTightID,                         &b_Tau_isTightID );
        fChain -> SetBranchAddress ( "tau_truthMatched",                  &Tau_truthMatched,                      &b_Tau_truthMatched );
        fChain -> SetBranchAddress ( "tau_trigMatched",                   &Tau_trigMatched,                       &b_Tau_trigMatched );
        fChain -> SetBranchAddress ( "tau_nTracks",                       &Tau_nTracks,                           &b_Tau_nTracks );
        fChain -> SetBranchAddress ( "tau_BDTid",                         &Tau_BDTid,                             &b_Tau_BDTid );
        fChain -> SetBranchAddress ( "ditau_m",                           &Ditau_m,                               &b_Ditau_m );

        fChain -> SetBranchAddress ( "lep_pt_syst",                       &Lep_pt_syst,                           &b_Lep_pt_syst );
        fChain -> SetBranchAddress ( "met_et_syst",                       &Met_et_syst,                           &b_Met_et_syst );
        fChain -> SetBranchAddress ( "jet_pt_syst",                       &Jet_pt_syst,                           &b_Jet_pt_syst );
        fChain -> SetBranchAddress ( "photon_pt_syst",                    &Photon_pt_syst,                        &b_Photon_pt_syst );
        fChain -> SetBranchAddress ( "largeRjet_pt_syst",                 &LargeRjet_pt_syst,                     &b_LargeRjet_pt_syst );
        fChain -> SetBranchAddress ( "tau_pt_syst",                       &Tau_pt_syst,                           &b_Tau_pt_syst );


      // SELECTION CRITERIA

        int nentries = 0;
        int nbytes = 0;
        int i = 0;

        nentries = (Int_t) fChain -> GetEntries();

        for ( i = 0; i < nentries; i++)
        {

            nbytes = fChain -> GetEntry(i);

            float Lumi = 10000;     // 10 for Cross Section in fb and 10000 for pb
            Float_t SF = 0;
            Float_t weight = 0;

            SF = SF_Ele * SF_Muon * SF_LepTrig * SF_Pileup;
            weight = SF * mcWeight * XSection * Lumi / SumWeights;

            if ( TrigP )
            {

                int goodphoton_index[Photon_n];
	            int goodphoton_n = 0;
	            int photon_index = 0;

                for ( unsigned int j = 0; j < Photon_n; j ++ )
                {

                    if ( Photon_isTightID -> at(j) )
                    {

                        if ( Photon_pt -> at(j) > 25000. )
                        {

                            if ( TMath::Abs ( Photon_eta -> at(j) ) < 2.37 && ( TMath::Abs ( Photon_eta -> at(j) ) < 1.37 || TMath::Abs ( Photon_eta -> at(j) ) > 1.52 ) )
                            {

                                goodphoton_n = goodphoton_n + 1;
		                        goodphoton_index [photon_index] = j;
		                        photon_index ++;

                            }

                        }

                    }

                }

                if ( goodphoton_n == 2 )
                {

                    int goodphoton1_index = goodphoton_index [0];
	                int goodphoton2_index = goodphoton_index [1];

                    if ( ( Photon_ptcone30 -> at(goodphoton1_index) / Photon_pt -> at(goodphoton1_index) ) < 0.065 && ( Photon_etcone20 -> at(goodphoton1_index) / Photon_pt -> at(goodphoton1_index) ) < 0.065 )
                    {

                        if ( ( Photon_ptcone30 -> at(goodphoton2_index) / Photon_pt -> at(goodphoton2_index) ) < 0.065 && ( Photon_etcone20 -> at(goodphoton2_index) / Photon_pt -> at(goodphoton2_index) ) < 0.065 )
                        {

                            if ( Photon_pt -> at(goodphoton1_index) > 35000. )
                            {

                                TLorentzVector Photon_1 = TLorentzVector ();
                                TLorentzVector Photon_2 = TLorentzVector ();

                                Photon_1.SetPtEtaPhiE( Photon_pt -> at(goodphoton1_index), Photon_eta -> at(goodphoton1_index), Photon_phi -> at(goodphoton1_index), Photon_E -> at(goodphoton1_index) );
                                Photon_2.SetPtEtaPhiE( Photon_pt -> at(goodphoton2_index), Photon_eta -> at(goodphoton2_index), Photon_phi -> at(goodphoton2_index), Photon_E -> at(goodphoton2_index) );

                                float dPhi_yy = TMath::Abs( Photon_phi -> at(goodphoton1_index) - Photon_phi -> at(goodphoton2_index) );
		                        dPhi_yy = dPhi_yy < TMath::Pi() ? dPhi_yy : 2 * TMath::Pi() - dPhi_yy;

                                float myy = sqrt ( 2 * Photon_1.Pt()/1000. * Photon_2.Pt()/1000. * ( cosh ( Photon_1.Eta() - Photon_2.Eta() ) - cos(dPhi_yy) ) );

                                float Photon1_Em = Photon_1.E() / 1000. / myy ;
                                float Photon2_Em = Photon_2.E() / 1000. / myy ;

                                if ( Photon1_Em > 0.35 && Photon2_Em > 0.25 )
                                {

                                    if ( myy > 105 && myy < 160 )
                                    {

                                        if ( type == 0 )
                                        {

                                            hist_myy1_Data -> Fill (myy);

                                        }

                                        if ( type == 1 || type == 2 || type == 3 || type == 4 || type == 5 )
                                        {

                                            hist_myy1_Higgs -> Fill (myy, weight);

                                        }

                                        if ( TMath::Abs( Photon_eta -> at(goodphoton1_index) ) < 0.75 && TMath::Abs( Photon_eta -> at(goodphoton2_index) ) < 0.75 )
                                        {

                                            if ( Photon_convType -> at(goodphoton1_index) == 0 && Photon_convType -> at(goodphoton2_index) == 0 )
                                            {

                                                if ( type == 0 )
                                                {

                                                    hist_myy2_Data -> Fill (myy);

                                                }

                                                if ( type == 1 || type == 2 || type == 3 || type == 4 || type == 5 )
                                                {

                                                    hist_myy2_Higgs -> Fill (myy, weight);

                                                }

                                            }

                                        }

                                    }

                                }

                            }

                        }

                    }

                }

            }

        }

  }


  // NUMBER OF EVENTS WHICH PASS THE FINAL EVENT SELECTION CRITERIA

    // DATA

        float Int_myy1_Data = hist_myy1_Data -> Integral (1, 30);
        std::cout << "* Data: " << Int_myy1_Data << std::endl;

        float Int_myy2_Data = hist_myy2_Data -> Integral (1, 30);
        std::cout << "* Data unconverted: " << Int_myy2_Data << std::endl;


    // HIGGS

        float Int_myy1_Higgs = hist_myy1_Higgs -> Integral (1, 30);
        std::cout << "* Higgs: " << Int_myy1_Higgs << std::endl;

        float Int_myy2_Higgs = hist_myy2_Higgs -> Integral (1, 30);
        std::cout << "* Higgs unconverted: " << Int_myy2_Higgs << std::endl;


  // BACKGROUND FIT

    // CONVERTED Y UNCONVERTED PHOTONS

        TF1 *myy1_bkg1 = new TF1 ("myy1_bkg1", "expo", 105, 160);
        myy1_bkg1 -> SetLineColor (kBlue);
        myy1_bkg1 -> SetLineStyle (kDashed);
        hist_myy1_Data -> Fit ("myy1_bkg1","R");

        TFitResultPtr fit_res_myy1_bkg1 = hist_myy1_Data -> Fit ("myy1_bkg1", "S");
        float chi2_myy1_bkg1 = fit_res_myy1_bkg1 -> MinFcnValue();
        float ndf_myy1_bkg1 = fit_res_myy1_bkg1 -> Ndf();
        std::cout << "Chi2/ndf para myy1_sigbkg1:" << chi2_myy1_bkg1 / ndf_myy1_bkg1 << std::endl;


    // UNCONVERTED PHOTONS

        TF1 *myy2_bkg1 = new TF1("myy2_bkg1", "expo", 105, 160);
        myy2_bkg1 -> SetLineColor(kBlue);
        myy2_bkg1 -> SetLineStyle (kDashed);
        hist_myy2_Data -> Fit ("myy2_bkg1", "R");

        TFitResultPtr fit_res_myy2_bkg1 = hist_myy2_Data -> Fit ("myy2_bkg1", "S");
        float chi2_myy2_bkg1 = fit_res_myy2_bkg1 -> MinFcnValue();
        float ndf_myy2_bkg1 = fit_res_myy2_bkg1 -> Ndf();
        std::cout << "Chi2/ndf para myy1_sigbkg1:" << chi2_myy2_bkg1 / ndf_myy2_bkg1 << std::endl;


  // SIGNAL + BACKGROUND FIT

    // CONVERTED Y UNCONVERTED PHOTONS

        TF1 *myy1_sigbkg1 = new TF1 ("myy1_sigbkg1", "expo + gaus(2)", 105, 160);
        myy1_sigbkg1 -> SetLineColor (kRed);
        myy1_sigbkg1 -> SetParameters (0, 0, 150, 125, 2);
        myy1_sigbkg1 -> SetParLimits (2, 100, 200);
        myy1_sigbkg1 -> SetParLimits (3, 120, 130);
        myy1_sigbkg1 -> SetParLimits (4, 2, 4);
        hist_myy1_Data -> Fit ("myy1_sigbkg1", "R");

        TFitResultPtr fit_res_myy1_sigbkg1 = hist_myy1_Data -> Fit ("myy1_sigbkg1", "S");
        float chi2_myy1_sigbkg1 = fit_res_myy1_sigbkg1 -> MinFcnValue();
        float ndf_myy1_sigbkg1 = fit_res_myy1_sigbkg1 -> Ndf();
        std::cout << "Chi2/ndf para myy1_sigbkg1:" << chi2_myy1_sigbkg1 / ndf_myy1_sigbkg1 << std::endl;


    // UNCONVERTED PHOTONS

        TF1 *myy2_sigbkg1 = new TF1 ("myy2_sigbkg1", "expo + gausn(2)", 105, 160);
        myy2_sigbkg1 -> SetLineColor (kRed);
        myy2_sigbkg1 -> SetParameters (0, 0, 150, 125, 2);
        myy2_sigbkg1 -> SetParLimits (2, 100, 200);
        myy2_sigbkg1 -> SetParLimits (3, 120, 130);
        myy2_sigbkg1 -> SetParLimits (4, 1, 4);
        hist_myy2_Data -> Fit ("myy2_sigbkg1", "R");

        TFitResultPtr fit_res_myy2_sigbkg1 = hist_myy2_Data -> Fit ("myy2_sigbkg1", "S");
        float chi2_myy2_sigbkg1 = fit_res_myy2_sigbkg1 -> MinFcnValue();
        float ndf_myy2_sigbkg1 = fit_res_myy2_sigbkg1 -> Ndf();
        std::cout << "Chi2/ndf para myy1_sigbkg1:" << chi2_myy2_sigbkg1 / ndf_myy2_sigbkg1 << std::endl;


  // LEGEND

    auto legend1 = new TLegend (0.70, 0.65, 0.90, 0.85);
    legend1 -> AddEntry (hist_myy1_Data, " #bf{Data}", "lep");
    legend1 -> AddEntry (myy1_bkg1, " #bf{Background}", "l");
    legend1 -> AddEntry (myy1_sigbkg1, " #bf{Signal + bkg}", "l");
    legend1 -> AddEntry (hist_myy1_Higgs, " #bf{Signal}", "l");
    legend1 -> SetBorderSize(0);

    auto legend2 = new TLegend (0.70, 0.65, 0.90, 0.85);
    legend2 -> AddEntry (hist_myy2_Data, " #bf{Data}", "lep");
    legend2 -> AddEntry (myy2_bkg1, " #bf{Background}", "l");
    legend2 -> AddEntry (myy2_sigbkg1, " #bf{Signal + bkg}", "l");
    legend2 -> AddEntry (hist_myy2_Higgs, " #bf{Signal}", "l");
    legend2 -> SetBorderSize(0);


  // TITLE #sqrt{13} = TeV, 10 fb^{-1} Y H -> yy

    auto *pt_s = new TLegend ( 0.15, 0.80, 0.70, 0.85 );
    pt_s -> SetHeader ( "#bf{#sqrt{s} = 13 TeV, 10 fb^{-1}}" );
    pt_s -> SetBorderSize(0);

    auto *pt_Hyy = new TLegend ( 0.15, 0.75, 0.70, 0.80 );
    pt_Hyy -> SetHeader ( "#bf{H #rightarrow #gamma#gamma}" );
    pt_Hyy -> SetBorderSize(0);

    auto *pt_Hyy_unconv = new TLegend ( 0.15, 0.75, 0.70, 0.80 );
    pt_Hyy_unconv -> SetHeader ( "#bf{H #rightarrow #gamma#gamma, unconv. central}" );
    pt_Hyy_unconv -> SetBorderSize(0);


  // DRAW HISTOGRAMS

    // CONVERTED Y UNCONVERTED PHOTONS

        TCanvas *cs_myy1 = new TCanvas("cs_myy1","cs_myy1",10,10,900,600);
        TPad *pad1_myy1 = new TPad("pad1_myy1", "pad1_myy1", 0, 0.27, 1, 1);

        pad1_myy1 -> SetTopMargin (0.1);
        pad1_myy1 -> SetBottomMargin (0);
        pad1_myy1 -> SetLeftMargin (0.1);

        pad1_myy1 -> Draw ();
        pad1_myy1 -> cd ();
        hist_myy1_Higgs -> Draw ("hist,lf2");
        hist_myy1_Data -> DrawCopy ("e1,same");
        myy1_bkg1 -> Draw ("AL,same");
        myy1_sigbkg1 -> Draw ("AL,same");
        
        legend1 -> Draw ();
        pt_s -> Draw ();
        pt_Hyy -> Draw ();

        hist_myy1_Higgs -> SetMinimum (0.01);
        hist_myy1_Higgs -> SetMaximum (7500);
        hist_myy1_Higgs -> GetYaxis () -> SetMaxDigits (3);
        hist_myy1_Higgs -> GetYaxis () -> SetTitleOffset (0.75);

        cs_myy1 -> cd ();

        TPad *pad2_myy1 = new TPad("pad2_myy1", "pad2_myy1", 0, 0, 1, 0.27);
        pad2_myy1 -> SetTopMargin (0);
        pad2_myy1 -> SetBottomMargin (0.40);
        pad2_myy1 -> SetLeftMargin (0.1);

        pad2_myy1 -> Draw ();
        pad2_myy1 -> cd ();

        hist_myy1_Data -> Sumw2 ();
        hist_myy1_Data -> SetStats (0);
        hist_myy1_Data -> Add ( myy1_bkg1, -1 );

          // DATA - BACKGROUND FIT

            TF1 *myy1_bkg2 = new TF1 ("myy1_bkg2", "pol3", 105, 160);
            myy1_bkg2 -> SetLineColor (kBlue);
            myy1_bkg2 -> SetLineStyle (kDashed);
            hist_myy1_Data -> Fit ("myy1_bkg2", "R");

            TF1 *myy1_sigbkg2 = new TF1 ("myy1_sigbkg2", "gaus", 105, 160);
            myy1_sigbkg2 -> SetParameters (150, 125, 2);
            myy1_sigbkg2 -> FixParameter (0, 150);
            myy1_sigbkg2 -> FixParameter (1, 125);
            myy1_sigbkg2 -> FixParameter (2, 2);
            myy1_sigbkg2 -> SetLineColor (kRed);
            hist_myy1_Data -> Fit ("myy1_sigbkg2", "B", "", 115, 135);
                

        hist_myy1_Data -> Draw ("e1");
        myy1_bkg2 -> Draw ("AL,same");
        myy1_sigbkg2 -> Draw ("AL,same");

        hist_myy1_Data -> SetMaximum (175);
        hist_myy1_Data -> SetMinimum (-175);
        hist_myy1_Data -> GetYaxis () -> SetNdivisions (4, 2, 4, kTRUE);

        cs_myy1 -> cd ();


    // UNCONVERTED PHOTONS

        TCanvas *cs_myy2 = new TCanvas("cs_myy2","cs_myy2",10,10,900,600);
        TPad *pad1_myy2 = new TPad("pad1_myy2", "pad1_myy2", 0, 0.27, 1, 1);

        pad1_myy2 -> SetTopMargin (0.1);
        pad1_myy2 -> SetBottomMargin (0);
        pad1_myy2 -> SetLeftMargin (0.1);

        pad1_myy2 -> Draw ();
        pad1_myy2 -> cd ();
        hist_myy2_Higgs -> Draw ("hist,lf2");
        hist_myy2_Data -> DrawCopy ("e1,same");
        myy2_bkg1 -> Draw ("AL,same");
        myy2_sigbkg1 -> Draw ("AL,same");
        
        legend2 -> Draw ();
        pt_s -> Draw ();
        pt_Hyy_unconv -> Draw ();

        hist_myy2_Higgs -> SetMinimum (0.01);
        hist_myy2_Higgs -> SetMaximum (800);
        hist_myy2_Higgs -> GetYaxis () -> SetMaxDigits (2);
        hist_myy2_Higgs -> GetYaxis () -> SetTitleOffset (0.75);

        cs_myy2 -> cd ();

        TPad *pad2_myy2 = new TPad("pad2_myy2", "pad2_myy2", 0, 0, 1, 0.27);
        pad2_myy2 -> SetTopMargin (0);
        pad2_myy2 -> SetBottomMargin (0.40);
        pad2_myy2 -> SetLeftMargin (0.1);

        pad2_myy2 -> Draw ();
        pad2_myy2 -> cd ();

        hist_myy2_Data -> Sumw2 ();
        hist_myy2_Data -> SetStats (0);
        hist_myy2_Data -> Add ( myy2_bkg1, -1 );

          // DATA - BACKGROUND FIT

            TF1 *myy2_bkg2 = new TF1 ("myy2_bkg2", "pol3", 105, 160);
            myy2_bkg2 -> SetLineColor (kBlue);
            myy2_bkg2 -> SetLineStyle (kDashed);
            hist_myy2_Data -> Fit ("myy2_bkg2", "R");

            TF1 *myy2_sigbkg2 = new TF1 ("myy2_sigbkg2", "gausn", 105, 160);
            myy2_sigbkg2 -> SetParameters (150, 125, 2);
            myy2_sigbkg2 -> FixParameter (0, 150);
            myy2_sigbkg2 -> FixParameter (1, 125);
            myy2_sigbkg2 -> FixParameter (2, 2);
            myy2_sigbkg2 -> SetLineColor (kRed);
            hist_myy2_Data -> Fit ("myy2_sigbkg2", "B", "", 120, 130);


        hist_myy2_Data -> Draw ("e1");
        myy2_bkg2 -> Draw ("AL,same");
        myy2_sigbkg2 -> Draw ("AL,same");

        hist_myy2_Data -> SetMaximum (60);
        hist_myy2_Data -> SetMinimum (-60);
        hist_myy2_Data -> GetYaxis () -> SetNdivisions (4, 2, 5, kTRUE);

        cs_myy2 -> cd ();


  // SAVE CANVAS

    std::cout << " " << std::endl;

    cs_myy1 -> SaveAs ("Hyy_myy.png");
    cs_myy2 -> SaveAs ("Hyy_myy_unconv.png");


  t1 = clock ();

  float time = ( float (t1 - t0) / CLOCKS_PER_SEC ) / 60;        // Execution time in minutes

  std::cout << " " << std::endl;
  std::cout << "Execution time: " << time << " minutes." << std::endl;


  return;

}






