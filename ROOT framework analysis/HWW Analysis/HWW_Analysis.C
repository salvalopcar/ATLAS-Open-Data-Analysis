//=============================================================//
//                                                             //
//                                                             //
//             	   Analysis of H -> WW* decay                  //
//                                                             //
//                                                             //
//=============================================================//
  

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <stdio.h>

#include <TChain.h>
#include <TMath.h>
#include <TLorentzVector.h>
#include <TFile.h>


void HWW_Analysis () {

  unsigned t0, t1;          // Execution time variables

  t0 = clock ();


  // DEFINE HISTOGRAMS

    TH1F *hist_mt = new TH1F("hist_mt", "Dilepton System Transverse mass; m_{T} [GeV]; Data / Pred", 15, 50, 200);
    TH1F *hist_mt_precut = new TH1F("hist_mt_precut", "Dilepton System Transverse mass; m_{T} [GeV]; Data / Pred", 15, 50, 200);

    TH1F *hist_etmiss = new TH1F("hist_etmiss", "Missing Transverse Momentum; E_{T}^{miss} [GeV]; Data / Pred", 20, 0, 200);
    TH1F *hist_etmiss_precut = new TH1F("hist_etmiss_precut", "Missing Transverse Momentum; E_{T}^{miss} [GeV]; Data / Pred", 20, 0, 200);

    TH1F *hist_ptLL = new TH1F("hist_ptLL", "Transverse Momentum of Dilepton System; p_{T}^{ll} [GeV]; Data / Pred", 30, 0, 200);
    TH1F *hist_ptLL_precut = new TH1F("hist_ptLL_precut", "Transverse Momentum of Dilepton System; p_{T}^{ll} [GeV]; Data / Pred", 30, 0, 200);

    TH1F *hist_dPhiLL = new TH1F("hist_dPhiLL", "dPhi_LL Dilepton System; #Delta#phi (ll); Data / Pred", 20, 0, 3.2);
    TH1F *hist_dPhiLL_precut = new TH1F("hist_dPhiLL_precut", "dPhi_LL Dilepton System; #Delta#phi (ll); Data / Pred", 20, 0, 3.2);


    // DATA

        // PRE - CUT

            TH1F *hist_mt_Data_precut = new TH1F("hist_mt_Data_precut", "Dilepton System Transverse mass; m_{T} [GeV]; Data / Pred", 15, 50, 200);
            hist_mt_Data_precut -> SetLineColor(kBlack);
            hist_mt_Data_precut -> GetXaxis () -> SetLabelSize (0.13);
            hist_mt_Data_precut -> GetXaxis () -> SetTitleSize (0.14);
            hist_mt_Data_precut -> GetXaxis () -> SetTitleOffset (0.85);
            hist_mt_Data_precut -> GetYaxis () -> SetLabelSize (0.13);
            hist_mt_Data_precut -> GetYaxis () -> SetTitleSize (0.13);
            hist_mt_Data_precut -> GetYaxis () -> SetTitleOffset (0.27);

            TH1F *hist_etmiss_Data_precut = new TH1F("hist_etmiss_Data_precut", "Missing Transverse Momentum; E_{T}^{miss} [GeV]; Data / Pred", 20, 0, 200);
            hist_etmiss_Data_precut -> SetLineColor(kBlack);
            hist_etmiss_Data_precut -> GetXaxis () -> SetLabelSize (0.13);
            hist_etmiss_Data_precut -> GetXaxis () -> SetTitleSize (0.14);
            hist_etmiss_Data_precut -> GetXaxis () -> SetTitleOffset (0.90);
            hist_etmiss_Data_precut -> GetYaxis () -> SetLabelSize (0.13);
            hist_etmiss_Data_precut -> GetYaxis () -> SetTitleSize (0.13);
            hist_etmiss_Data_precut -> GetYaxis () -> SetTitleOffset (0.27);

            TH1F *hist_ptLL_Data_precut = new TH1F("hist_ptLL_Data_precut", "Transverse Momentum of Dilepton System; p_{T}^{ll} [GeV]; Data / Pred", 30, 0, 200);
            hist_ptLL_Data_precut -> SetLineColor(kBlack);
            hist_ptLL_Data_precut -> GetXaxis () -> SetLabelSize (0.13);
            hist_ptLL_Data_precut -> GetXaxis () -> SetTitleSize (0.14);
            hist_ptLL_Data_precut -> GetXaxis () -> SetTitleOffset (0.90);
            hist_ptLL_Data_precut -> GetYaxis () -> SetLabelSize (0.13);
            hist_ptLL_Data_precut -> GetYaxis () -> SetTitleSize (0.13);
            hist_ptLL_Data_precut -> GetYaxis () -> SetTitleOffset (0.27);

            TH1F *hist_dPhiLL_Data_precut = new TH1F("hist_dPhiLL_Data_precut", "dPhi_LL Dilepton System; #Delta#phi (ll); Data / Pred", 20, 0, 3.2);
            hist_dPhiLL_Data_precut -> SetLineColor(kBlack);
            hist_dPhiLL_Data_precut -> GetXaxis () -> SetLabelSize (0.13);
            hist_dPhiLL_Data_precut -> GetXaxis () -> SetTitleSize (0.14);
            hist_dPhiLL_Data_precut -> GetXaxis () -> SetTitleOffset (0.85);
            hist_dPhiLL_Data_precut -> GetYaxis () -> SetLabelSize (0.13);
            hist_dPhiLL_Data_precut -> GetYaxis () -> SetTitleSize (0.13);
            hist_dPhiLL_Data_precut -> GetYaxis () -> SetTitleOffset (0.27);


        // POST - CUT

            TH1F *hist_mt_Data = new TH1F("hist_mt_Data", "Dilepton System Transverse mass; m_{T} [GeV]; Data / Pred", 15, 50, 200);
            hist_mt_Data -> SetLineColor(kBlack);
            hist_mt_Data -> GetXaxis () -> SetLabelSize (0.13);
            hist_mt_Data -> GetXaxis () -> SetTitleSize (0.14);
            hist_mt_Data -> GetXaxis () -> SetTitleOffset (0.85);
            hist_mt_Data -> GetYaxis () -> SetLabelSize (0.13);
            hist_mt_Data -> GetYaxis () -> SetTitleSize (0.13);
            hist_mt_Data -> GetYaxis () -> SetTitleOffset (0.27);

            TH1F *hist_etmiss_Data = new TH1F("hist_etmiss_Data", "Missing Transverse Momentum; E_{T}^{miss} [GeV]; Data / Pred", 20, 0, 200);
            hist_etmiss_Data -> SetLineColor(kBlack);
            hist_etmiss_Data -> GetXaxis () -> SetLabelSize (0.13);
            hist_etmiss_Data -> GetXaxis () -> SetTitleSize (0.14);
            hist_etmiss_Data -> GetXaxis () -> SetTitleOffset (0.90);
            hist_etmiss_Data -> GetYaxis () -> SetLabelSize (0.13);
            hist_etmiss_Data -> GetYaxis () -> SetTitleSize (0.13);
            hist_etmiss_Data -> GetYaxis () -> SetTitleOffset (0.27);

            TH1F *hist_ptLL_Data = new TH1F("hist_ptLL_Data", "Transverse Momentum of Dilepton System; p_{T}^{ll} [GeV]; Data / Pred", 30, 0, 200);
            hist_ptLL_Data -> SetLineColor(kBlack);
            hist_ptLL_Data -> GetXaxis () -> SetLabelSize (0.13);
            hist_ptLL_Data -> GetXaxis () -> SetTitleSize (0.14);
            hist_ptLL_Data -> GetXaxis () -> SetTitleOffset (0.90);
            hist_ptLL_Data -> GetYaxis () -> SetLabelSize (0.13);
            hist_ptLL_Data -> GetYaxis () -> SetTitleSize (0.13);
            hist_ptLL_Data -> GetYaxis () -> SetTitleOffset (0.27);

            TH1F *hist_dPhiLL_Data = new TH1F("hist_dPhiLL_Data", "dPhi_LL Dilepton System; #Delta#phi (ll); Data / Pred", 20, 0, 3.2);
            hist_dPhiLL_Data -> SetLineColor(kBlack);
            hist_dPhiLL_Data -> GetXaxis () -> SetLabelSize (0.13);
            hist_dPhiLL_Data -> GetXaxis () -> SetTitleSize (0.14);
            hist_dPhiLL_Data -> GetXaxis () -> SetTitleOffset (0.85);
            hist_dPhiLL_Data -> GetYaxis () -> SetLabelSize (0.13);
            hist_dPhiLL_Data -> GetYaxis () -> SetTitleSize (0.13);
            hist_dPhiLL_Data -> GetYaxis () -> SetTitleOffset (0.27);


    // HIGGS

        // NORMALIZE

            TH1F *hist_mt_Higgs_norm = new TH1F("hist_mt_Higgs_norm","Transverse mass; m_{T} [GeV]; Events / bin", 15, 50, 200);
            hist_mt_Higgs_norm -> SetLineColor(kRed);
            hist_mt_Higgs_norm -> SetLineStyle(kDashed);


            TH1F *hist_etmiss_Higgs_norm = new TH1F("hist_etmiss_Higgs_norm", "Missing Transverse Momentum; E_{T}^{miss} [GeV]; Events / bin", 20, 0, 200);
            hist_etmiss_Higgs_norm -> SetLineColor(kRed);
            hist_etmiss_Higgs_norm -> SetLineStyle(kDashed);

            TH1F *hist_ptLL_Higgs_norm = new TH1F("hist_ptLL_Higgs_norm", "Transverse Momentum of Dilepton System; p_{T}^{ll} [GeV]; Events / bin", 30, 0, 200);
            hist_ptLL_Higgs_norm -> SetLineColor(kRed);
            hist_ptLL_Higgs_norm -> SetLineStyle(kDashed);

            TH1F *hist_dPhiLL_Higgs_norm = new TH1F("hist_dPhiLL_Higgs_norm", "dPhi_LL Dilepton System; #Delta#phi (ll); Events / bin", 20, 0, 3.2);
            hist_dPhiLL_Higgs_norm -> SetLineColor(kRed);
            hist_dPhiLL_Higgs_norm -> SetLineStyle(kDashed);


        // PRE - CUT

            TH1F *hist_mt_Higgs_precut = new TH1F("hist_mt_Higgs_precut","Transverse mass; m_{T} [GeV]; Events / bin", 15, 50, 200);
            hist_mt_Higgs_precut -> SetLineColor(kRed);
            hist_mt_Higgs_precut -> SetFillColor(kRed);


            TH1F *hist_etmiss_Higgs_precut = new TH1F("hist_etmiss_Higgs_precut", "Missing Transverse Momentum; E_{T}^{miss} [GeV]; Events / bin", 20, 0, 200);
            hist_etmiss_Higgs_precut -> SetLineColor(kRed);
            hist_etmiss_Higgs_precut -> SetFillColor(kRed);

            TH1F *hist_ptLL_Higgs_precut = new TH1F("hist_ptLL_Higgs_precut", "Transverse Momentum of Dilepton System; p_{T}^{ll} [GeV]; Events / bin", 30, 0, 200);
            hist_ptLL_Higgs_precut -> SetLineColor(kRed);
            hist_ptLL_Higgs_precut -> SetFillColor(kRed);

            TH1F *hist_dPhiLL_Higgs_precut = new TH1F("hist_dPhiLL_Higgs_precut", "dPhi_LL Dilepton System; #Delta#phi (ll); Events / bin", 20, 0, 3.2);
            hist_dPhiLL_Higgs_precut -> SetLineColor(kRed);
            hist_dPhiLL_Higgs_precut -> SetFillColor(kRed);


        // POST - CUT

            TH1F *hist_mt_Higgs = new TH1F("hist_mt_Higgs","Transverse mass; m_{T} [GeV]; Events / bin", 15, 50, 200);
            hist_mt_Higgs -> SetLineColor(kRed);
            hist_mt_Higgs -> SetFillColor(kRed);

            TH1F *hist_etmiss_Higgs = new TH1F("hist_etmiss_Higgs", "Missing Transverse Momentum; E_{T}^{miss} [GeV]; Events / bin", 20, 0, 200);
            hist_etmiss_Higgs -> SetLineColor(kRed);
            hist_etmiss_Higgs -> SetFillColor(kRed);

            TH1F *hist_ptLL_Higgs = new TH1F("hist_ptLL_Higgs", "Transverse Momentum of Dilepton System; p_{T}^{ll} [GeV]; Events / bin", 30, 0, 200);
            hist_ptLL_Higgs -> SetLineColor(kRed);
            hist_ptLL_Higgs -> SetFillColor(kRed);

            TH1F *hist_dPhiLL_Higgs = new TH1F("hist_dPhiLL_Higgs", "dPhi_LL Dilepton System; #Delta#phi (ll); Events / bin", 20, 0, 3.2);
            hist_dPhiLL_Higgs -> SetLineColor(kRed);
            hist_dPhiLL_Higgs -> SetFillColor(kRed);


    // DIBOSON

        // PRE - CUT

            TH1F *hist_mt_Diboson_precut = new TH1F("hist_mt_Diboson_precut","Transverse mass; m_{T} [GeV]; Events / bin", 15, 50, 200);
            hist_mt_Diboson_precut -> SetLineColor(kViolet);
            hist_mt_Diboson_precut -> SetFillColor(kViolet);

            TH1F *hist_etmiss_Diboson_precut = new TH1F("hist_etmiss_Diboson_precut", "Missing Transverse Momentum; E_{T}^{miss} [GeV]; Events / bin", 20, 0, 200);
            hist_etmiss_Diboson_precut -> SetLineColor(kViolet);
            hist_etmiss_Diboson_precut -> SetFillColor(kViolet);

            TH1F *hist_ptLL_Diboson_precut = new TH1F("hist_ptLL_Diboson_precut", "Transverse Momentum of Dilepton System; p_{T}^{ll} [GeV]; Events / bin", 30, 0, 200);
            hist_ptLL_Diboson_precut -> SetLineColor(kViolet);
            hist_ptLL_Diboson_precut -> SetFillColor(kViolet);

            TH1F *hist_dPhiLL_Diboson_precut = new TH1F("hist_dPhiLL_Diboson_precut", "dPhi_LL Dilepton System; #Delta#phi (ll); Events / bin", 20, 0, 3.2);
            hist_dPhiLL_Diboson_precut -> SetLineColor(kViolet);
            hist_dPhiLL_Diboson_precut -> SetFillColor(kViolet);


        // POST - CUT

            TH1F *hist_mt_Diboson = new TH1F("hist_mt_Diboson","Transverse mass; m_{T} [GeV]; Events / bin", 15, 50, 200);
            hist_mt_Diboson -> SetLineColor(kViolet);
            hist_mt_Diboson -> SetFillColor(kViolet);

            TH1F *hist_etmiss_Diboson = new TH1F("hist_etmiss_Diboson", "Missing Transverse Momentum; E_{T}^{miss} [GeV]; Events / bin", 20, 0, 200);
            hist_etmiss_Diboson -> SetLineColor(kViolet);
            hist_etmiss_Diboson -> SetFillColor(kViolet);

            TH1F *hist_ptLL_Diboson = new TH1F("hist_ptLL_Diboson", "Transverse Momentum of Dilepton System; p_{T}^{ll} [GeV]; Events / bin", 30, 0, 200);
            hist_ptLL_Diboson -> SetLineColor(kViolet);
            hist_ptLL_Diboson -> SetFillColor(kViolet);

            TH1F *hist_dPhiLL_Diboson = new TH1F("hist_dPhiLL_Diboson", "dPhi_LL Dilepton System; #Delta#phi (ll); Events / bin", 20, 0, 3.2);
            hist_dPhiLL_Diboson -> SetLineColor(kViolet);
            hist_dPhiLL_Diboson -> SetFillColor(kViolet);


    // V JETS

        // PRE - CUT

            TH1F *hist_mt_Vjets_precut = new TH1F("hist_mt_Vjets_precut","Transverse mass; m_{T} [GeV]; Events / bin", 15, 50, 200);
            hist_mt_Vjets_precut -> SetLineColor(kGreen);
            hist_mt_Vjets_precut -> SetFillColor(kGreen);

            TH1F *hist_etmiss_Vjets_precut = new TH1F("hist_etmiss_Vjets_precut", "Missing Transverse Momentum; E_{T}^{miss} [GeV]; Events / bin", 20, 0, 200);
            hist_etmiss_Vjets_precut -> SetLineColor(kGreen);
            hist_etmiss_Vjets_precut -> SetFillColor(kGreen);

            TH1F *hist_ptLL_Vjets_precut = new TH1F("hist_ptLL_Vjets_precut", "Transverse Momentum of Dilepton System; p_{T}^{ll} [GeV]; Events / bin", 30, 0, 200);
            hist_ptLL_Vjets_precut -> SetLineColor(kGreen);
            hist_ptLL_Vjets_precut -> SetFillColor(kGreen);

            TH1F *hist_dPhiLL_Vjets_precut = new TH1F("hist_dPhiLL_Vjets_precut", "dPhi_LL Dilepton System; #Delta#phi (ll); Events / bin", 20, 0, 3.2);
            hist_dPhiLL_Vjets_precut -> SetLineColor(kGreen);
            hist_dPhiLL_Vjets_precut -> SetFillColor(kGreen);


        // POST - CUT

            TH1F *hist_mt_Vjets = new TH1F("hist_mt_Vjets","Transverse mass; m_{T} [GeV]; Events / bin", 15, 50, 200);
            hist_mt_Vjets -> SetLineColor(kGreen);
            hist_mt_Vjets -> SetFillColor(kGreen);

            TH1F *hist_etmiss_Vjets = new TH1F("hist_etmiss_Vjets", "Missing Transverse Momentum; E_{T}^{miss} [GeV]; Events / bin", 20, 0, 200);
            hist_etmiss_Vjets -> SetLineColor(kGreen);
            hist_etmiss_Vjets -> SetFillColor(kGreen);

            TH1F *hist_ptLL_Vjets = new TH1F("hist_ptLL_Vjets", "Transverse Momentum of Dilepton System; p_{T}^{ll} [GeV]; Events / bin", 30, 0, 200);
            hist_ptLL_Vjets -> SetLineColor(kGreen);
            hist_ptLL_Vjets -> SetFillColor(kGreen);

            TH1F *hist_dPhiLL_Vjets = new TH1F("hist_dPhiLL_Vjets", "dPhi_LL Dilepton System; #Delta#phi (ll); Events / bin", 20, 0, 3.2);
            hist_dPhiLL_Vjets -> SetLineColor(kGreen);
            hist_dPhiLL_Vjets -> SetFillColor(kGreen);


    // TOP - ANTITOP

        // PRE - CUT

            TH1F *hist_mt_tt_precut = new TH1F("hist_mt_tt_precut","Transverse mass; m_{T} [GeV]; Events / bin", 15, 50, 200);
            hist_mt_tt_precut -> SetLineColor(kOrange);
            hist_mt_tt_precut -> SetFillColor(kOrange);

            TH1F *hist_etmiss_tt_precut = new TH1F("hist_etmiss_tt_precut", "Missing Transverse Momentum; E_{T}^{miss} [GeV]; Events / bin", 20, 0, 200);
            hist_etmiss_tt_precut -> SetLineColor(kOrange);
            hist_etmiss_tt_precut -> SetFillColor(kOrange);

            TH1F *hist_ptLL_tt_precut = new TH1F("hist_ptLL_tt_precut", "Transverse Momentum of Dilepton System; p_{T}^{ll} [GeV]; Events / bin", 30, 0, 200);
            hist_ptLL_tt_precut -> SetLineColor(kOrange);
            hist_ptLL_tt_precut -> SetFillColor(kOrange);

            TH1F *hist_dPhiLL_tt_precut = new TH1F("hist_dPhiLL_tt_precut", "dPhi_LL Dilepton System; #Delta#phi (ll); Events / bin", 20, 0, 3.2);
            hist_dPhiLL_tt_precut -> SetLineColor(kOrange);
            hist_dPhiLL_tt_precut -> SetFillColor(kOrange);


        // POST - CUT

            TH1F *hist_mt_tt = new TH1F("hist_mt_tt","Transverse mass; m_{T} [GeV]; Events / bin", 15, 50, 200);
            hist_mt_tt -> SetLineColor(kOrange);
            hist_mt_tt -> SetFillColor(kOrange);

            TH1F *hist_etmiss_tt = new TH1F("hist_etmiss_tt", "Missing Transverse Momentum; E_{T}^{miss} [GeV]; Events / bin", 20, 0, 200);
            hist_etmiss_tt -> SetLineColor(kOrange);
            hist_etmiss_tt -> SetFillColor(kOrange);

            TH1F *hist_ptLL_tt = new TH1F("hist_ptLL_tt", "Transverse Momentum of Dilepton System; p_{T}^{ll} [GeV]; Events / bin", 30, 0, 200);
            hist_ptLL_tt -> SetLineColor(kOrange);
            hist_ptLL_tt -> SetFillColor(kOrange);

            TH1F *hist_dPhiLL_tt = new TH1F("hist_dPhiLL_tt", "dPhi_LL Dilepton System; #Delta#phi (ll); Events / bin", 20, 0, 3.2);
            hist_dPhiLL_tt -> SetLineColor(kOrange);
            hist_dPhiLL_tt -> SetFillColor(kOrange);


    // SINGLE TOP

        // PRE - CUT

            TH1F *hist_mt_t_precut = new TH1F("hist_mt_t_precut","Transverse mass; m_{T} [GeV]; Events / bin", 15, 50, 200);
            hist_mt_t_precut -> SetLineColor(kCyan);
            hist_mt_t_precut -> SetFillColor(kCyan);

            TH1F *hist_etmiss_t_precut = new TH1F("hist_etmiss_t_precut", "Missing Transverse Momentum; E_{T}^{miss} [GeV]; Events / bin", 20, 0, 200);
            hist_etmiss_t_precut -> SetLineColor(kCyan);
            hist_etmiss_t_precut -> SetFillColor(kCyan);

            TH1F *hist_ptLL_t_precut = new TH1F("hist_ptLL_t_precut", "Transverse Momentum of Dilepton System; p_{T}^{ll} [GeV]; Events / bin", 30, 0, 200);
            hist_ptLL_t_precut -> SetLineColor(kCyan);
            hist_ptLL_t_precut -> SetFillColor(kCyan);

            TH1F *hist_dPhiLL_t_precut = new TH1F("hist_dPhiLL_t_precut", "dPhi_LL Dilepton System; #Delta#phi (ll); Events / bin", 20, 0, 3.2);
            hist_dPhiLL_t_precut -> SetLineColor(kCyan);
            hist_dPhiLL_t_precut -> SetFillColor(kCyan);


        // POST - CUT

            TH1F *hist_mt_t = new TH1F("hist_mt_t","Transverse mass; m_{T} [GeV]; Events / bin", 15, 50, 200);
            hist_mt_t -> SetLineColor(kCyan);
            hist_mt_t -> SetFillColor(kCyan);

            TH1F *hist_etmiss_t = new TH1F("hist_etmiss_t", "Missing Transverse Momentum; E_{T}^{miss} [GeV]; Events / bin", 20, 0, 200);
            hist_etmiss_t -> SetLineColor(kCyan);
            hist_etmiss_t -> SetFillColor(kCyan);

            TH1F *hist_ptLL_t = new TH1F("hist_ptLL_t", "Transverse Momentum of Dilepton System; p_{T}^{ll} [GeV]; Events / bin", 30, 0, 200);
            hist_ptLL_t -> SetLineColor(kCyan);
            hist_ptLL_t -> SetFillColor(kCyan);

            TH1F *hist_dPhiLL_t = new TH1F("hist_dPhiLL_t", "dPhi_LL Dilepton System; #Delta#phi (ll); Events / bin", 20, 0, 3.2);
            hist_dPhiLL_t -> SetLineColor(kCyan);
            hist_dPhiLL_t -> SetFillColor(kCyan);


  // 0: Data, 1: ggF Higgs, 2: VBF Higgs, 3: Diboson WZ, 4: Diboson WW, 5: Diboson ZZ, 6: Vjets, 7: top anti-top, 8: single top

    int type = 0;


  // LOCAL PATH

    TString path = "/media/sf_TFG/Datos";


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  for ( type = 0; type < 9; type ++ )
  {

    TChain* fChain = new TChain("mini");


  // OPEN FILES

    // DATA

        if ( type == 0 )
        {

            fChain -> AddFile (path + "/exactly2lep/Data/data_A.exactly2lep.root"); 
            fChain -> AddFile (path + "/exactly2lep/Data/data_B.exactly2lep.root");
            fChain -> AddFile (path + "/exactly2lep/Data/data_C.exactly2lep.root");
            fChain -> AddFile (path + "/exactly2lep/Data/data_D.exactly2lep.root");

        }


    // ggF HIGGS

        if ( type == 1 )
        {

            fChain -> AddFile (path + "/exactly2lep/MC/mc_345324.ggH125_WW2lep.exactly2lep.root");

        }


    // VBF HIGGS

        if ( type == 2 )
        {

            fChain -> AddFile (path + "/exactly2lep/MC/mc_345323.VBFH125_WW2lep.exactly2lep.root");

        }


    // DIBOSON

      // WZ

        if ( type == 3 )
        {

            fChain -> AddFile (path + "/exactly2lep/MC/mc_363358.WqqZll.exactly2lep.root");
            fChain -> AddFile (path + "/exactly2lep/MC/mc_363489.WlvZqq.exactly2lep.root");
            fChain -> AddFile (path + "/exactly2lep/MC/mc_363491.lllv.exactly2lep.root");
            fChain -> AddFile (path + "/exactly2lep/MC/mc_363493.lvvv.exactly2lep.root");

        }


      // WW

        if ( type == 4 )
        {

            fChain -> AddFile (path + "/exactly2lep/MC/mc_363359.WpqqWmlv.exactly2lep.root");
            fChain -> AddFile (path + "/exactly2lep/MC/mc_363360.WplvWmqq.exactly2lep.root");
            fChain -> AddFile (path + "/exactly2lep/MC/mc_363492.llvv.exactly2lep.root");

        }


      // ZZ

        if ( type == 5 )
        {

            fChain -> AddFile (path + "/exactly2lep/MC/mc_363356.ZqqZll.exactly2lep.root");
            fChain -> AddFile (path + "/exactly2lep/MC/mc_363490.llll.exactly2lep.root");

        }


    // V JETS

        if ( type == 6 )
        {

            // W+jets

                fChain -> AddFile (path + "/exactly2lep/MC/mc_361100.Wplusenu.exactly2lep.root");
                fChain -> AddFile (path + "/exactly2lep/MC/mc_361101.Wplusmunu.exactly2lep.root");
                fChain -> AddFile (path + "/exactly2lep/MC/mc_361102.Wplustaunu.exactly2lep.root");
                fChain -> AddFile (path + "/exactly2lep/MC/mc_361103.Wminusenu.exactly2lep.root");
                fChain -> AddFile (path + "/exactly2lep/MC/mc_361104.Wminusmunu.exactly2lep.root");
                fChain -> AddFile (path + "/exactly2lep/MC/mc_361105.Wminustaunu.exactly2lep.root");

            // Z+jets

                fChain -> AddFile (path + "/exactly2lep/MC/mc_361106.Zee.exactly2lep.root");
                fChain -> AddFile (path + "/exactly2lep/MC/mc_361107.Zmumu.exactly2lep.root");
                fChain -> AddFile (path + "/exactly2lep/MC/mc_361108.Ztautau.exactly2lep.root");

        }


    // TOP - ANTITOP

        if ( type == 7 )
        {

            fChain -> AddFile (path + "/exactly2lep/MC/mc_410000.ttbar_lep.exactly2lep.root");

        }


    // SINGLE TOP

        if ( type == 8 )
        {

            fChain -> AddFile (path + "/exactly2lep/MC/mc_410011.single_top_tchan.exactly2lep.root");
            fChain -> AddFile (path + "/exactly2lep/MC/mc_410012.single_antitop_tchan.exactly2lep.root");
            fChain -> AddFile (path + "/exactly2lep/MC/mc_410013.single_top_wtchan.exactly2lep.root");
            fChain -> AddFile (path + "/exactly2lep/MC/mc_410014.single_antitop_wtchan.exactly2lep.root");
            fChain -> AddFile (path + "/exactly2lep/MC/mc_410025.single_top_schan.exactly2lep.root");
            fChain -> AddFile (path + "/exactly2lep/MC/mc_410026.single_antitop_schan.exactly2lep.root");

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

            float norm = 1;         // Scale factor

            if ( type == 1 )        // Cross Section for ggF
            {

                XSection =  0.5437;

            }

            if ( type == 2 )        // Cross Section for VBF
            {

                XSection = 0.0437;

            }

            if ( type == 3 )        // Scale factor for WZ diboson
            {

                norm = 1.15;

            }

            if ( type == 4 )        // Scale factor for WW diboson
            {

                norm = 1.09;

            }

            SF = SF_Ele * SF_Muon * SF_LepTrig * SF_Pileup;
            weight = norm * SF * mcWeight * XSection * Lumi / SumWeights;
   
            if ( TrigE || TrigM )
            {

                int goodlep_index[2];
                int goodlep_n = 0;
                int lep_index = 0;


                for ( unsigned int j = 0; j < Lep_n; j ++ )
                {

                    TLorentzVector leptemp = TLorentzVector();

                    leptemp.SetPtEtaPhiE ( Lep_pt -> at(j) / 1000., Lep_eta -> at(j), Lep_phi -> at(j), Lep_E -> at(j) / 1000. );

                    if ( Lep_isTightID -> at(j) )
                    {

                        if ( Lep_pt -> at(j) > 15000. && ( Lep_ptcone30 -> at(j) / Lep_pt -> at(j) ) < 0.1 && ( Lep_etcone20 -> at(j) / Lep_pt -> at(j) ) < 0.1 )
                        {

                            if ( Lep_type -> at(j) == 11 && TMath::Abs ( Lep_eta -> at(j) ) < 2.47 && ( TMath::Abs ( Lep_eta -> at(j) ) < 1.37 || TMath::Abs( Lep_eta -> at(j) ) > 1.52 ) )
                            {

                                if ( TMath::Abs( Lep_trackd0pvunbiased -> at(j) ) / Lep_tracksigd0pvunbiased -> at(j) < 5 && TMath::Abs ( Lep_z0 -> at(j) * TMath::Sin( leptemp.Theta() ) ) < 0.5 )
                                {

                                    goodlep_n = goodlep_n + 1;
                                    goodlep_index [lep_index] = j;
                                    lep_index ++;

                                }

                            }

                            if ( Lep_type -> at(j) == 13 && TMath::Abs ( Lep_eta -> at(j) ) < 2.5 && ( TMath::Abs ( Lep_eta -> at(j) ) < 1.37 || TMath::Abs( Lep_eta -> at(j) ) > 1.52 ) )
                            {

                                if ( TMath::Abs( Lep_trackd0pvunbiased -> at(j) ) / Lep_tracksigd0pvunbiased -> at(j) < 3 && TMath::Abs ( Lep_z0 -> at(j) * TMath::Sin( leptemp.Theta() ) ) < 0.5 )
                                {

                                    goodlep_n = goodlep_n + 1;
                                    goodlep_index [lep_index] = j;
                                    lep_index ++;

                                }

                            }

                        }

                    }

                }


                if ( goodlep_n == 2 )
                {

                    int goodlep1_index = goodlep_index[0];
                    int goodlep2_index = goodlep_index[1];


                    if ( Lep_pt -> at(goodlep1_index) > 22000. )
                    {

                        if ( Lep_charge -> at(goodlep1_index) * Lep_charge -> at(goodlep2_index) == -1 )
                        {

                            if ( Lep_type -> at(goodlep1_index) != Lep_type -> at(goodlep2_index) )
                            {

                                int goodjet_n = 0;
                                int goodbjet_n = 0;

                                int goodjet_index [Jet_n];
                                int jet_index = 0;

                                int goodbjet_index [Jet_n];
                                int bjet_index = 0;

                                for ( unsigned int j = 0; j < Jet_n; j ++ )
                                {

                                    if ( Jet_pt -> at(j) > 20000. && TMath::Abs ( Jet_eta -> at(j) ) < 2.5 )
                                    {

                                        bool jvt = true;

                                        if ( Jet_pt -> at(j) < 60000. && TMath::Abs ( Jet_eta -> at(j) ) < 2.4 && Jet_jvt -> at(j) < 0.59 )
                                        {

                                            jvt = false;

                                        }

                                        if ( jvt )
                                        {

                                            if ( Jet_pt -> at(j) > 30000. )
                                            {

                                                goodjet_n = goodjet_n + 1;
                                                goodjet_index [jet_index] = j;
                                                jet_index ++;

                                            }

                                            if ( Jet_MV2c10 -> at(j) > 0.1758475 )
                                            {

                                                goodbjet_n = goodbjet_n + 1;
                                                goodbjet_index [bjet_index] = j;
                                                jet_index ++;

                                            }

                                        }

                                    }

                                }

                                TLorentzVector Lepton_1 = TLorentzVector ();        // TLorentzVector for first lepton
                                TLorentzVector Lepton_2 = TLorentzVector ();        // TLorentzVector for second lepton
                                TLorentzVector MeT = TLorentzVector ();             // TLorentzVector for Etmiss

                                Lepton_1.SetPtEtaPhiE ( Lep_pt -> at(goodlep1_index), Lep_eta -> at(goodlep1_index), Lep_phi -> at(goodlep1_index), Lep_E -> at(goodlep1_index) );
                                Lepton_2.SetPtEtaPhiE ( Lep_pt -> at(goodlep2_index), Lep_eta -> at(goodlep2_index), Lep_phi -> at(goodlep2_index), Lep_E -> at(goodlep2_index) );
                                MeT.SetPtEtaPhiE ( Met_et, 0, Met_phi, Met_et );

                                TLorentzVector Lepton_12 = TLorentzVector ();       // TLorentzVector for lepton 1 + 2
                                Lepton_12 = Lepton_1 + Lepton_2;

                                float mLL = Lepton_12.Mag() / 1000.;            // Dilepton mass in GeV
                                float ptLL = Lepton_12.Pt() / 1000.;            // Dilepton transverse momentum in GeV
                    
                                float dPhiLL = TMath::Abs ( Lep_phi -> at(goodlep1_index) - Lep_phi -> at(goodlep2_index) );           // Angle between leptons
                                dPhiLL = dPhiLL < TMath::Pi() ? dPhiLL : 2*TMath::Pi() - dPhiLL;

                                float dPhiLLmet = TMath::Abs ( Lepton_12.Phi() - Met_phi );                            // Angle between Etmiss and dilepton system
                                dPhiLLmet = dPhiLLmet < TMath::Pi() ? dPhiLLmet : 2*TMath::Pi() - dPhiLLmet;

                                float mt = sqrt( 2 * Lepton_12.Pt() * MeT.Et() * ( 1 - cos( Lepton_12.DeltaPhi(MeT) ) ) )/1000.;    // Dilepton transverse mass in GeV

                                Met_et = Met_et / 1000.;        // Etmiss in GeV


                                // FILL HISTOGRAMS BEFORE CUTS

                                    if ( type == 0 )
                                    {                                               

                                        hist_mt_Data_precut -> Fill ( mt );
                                        hist_etmiss_Data_precut -> Fill ( Met_et );
                                        hist_ptLL_Data_precut -> Fill ( ptLL );
                                        hist_dPhiLL_Data_precut -> Fill ( dPhiLL );

                                    }

                                    if ( type == 1 || type == 2 )
                                    {                                               

                                        hist_mt_Higgs_precut -> Fill ( mt, weight );
                                        hist_etmiss_Higgs_precut -> Fill ( Met_et, weight );
                                        hist_ptLL_Higgs_precut -> Fill ( ptLL, weight );
                                        hist_dPhiLL_Higgs_precut -> Fill ( dPhiLL, weight );

                                        hist_mt_Higgs_norm -> Fill ( mt, weight );
                                        hist_etmiss_Higgs_norm -> Fill ( Met_et, weight );
                                        hist_ptLL_Higgs_norm -> Fill ( ptLL, weight );
                                        hist_dPhiLL_Higgs_norm -> Fill ( dPhiLL, weight );

                                        hist_mt_precut -> Fill ( mt, weight );
                                        hist_etmiss_precut -> Fill ( Met_et, weight );
                                        hist_ptLL_precut -> Fill ( ptLL, weight );
                                        hist_dPhiLL_precut -> Fill ( dPhiLL, weight );

                                    }

                                    if ( type == 3 || type == 4 || type == 5 )
                                    {                                               

                                        hist_mt_Diboson_precut -> Fill ( mt, weight );
                                        hist_etmiss_Diboson_precut -> Fill ( Met_et, weight );
                                        hist_ptLL_Diboson_precut -> Fill ( ptLL, weight );
                                        hist_dPhiLL_Diboson_precut -> Fill ( dPhiLL, weight );

                                        hist_mt_precut -> Fill ( mt, weight );
                                        hist_etmiss_precut -> Fill ( Met_et, weight );
                                        hist_ptLL_precut -> Fill ( ptLL, weight );
                                        hist_dPhiLL_precut -> Fill ( dPhiLL, weight );

                                    }

                                    if ( type == 6 )
                                    {                                               

                                        hist_mt_Vjets_precut -> Fill ( mt, weight );
                                        hist_etmiss_Vjets_precut -> Fill ( Met_et, weight );
                                        hist_ptLL_Vjets_precut -> Fill ( ptLL, weight );
                                        hist_dPhiLL_Vjets_precut -> Fill ( dPhiLL, weight );

                                        hist_mt_precut -> Fill ( mt, weight );
                                        hist_etmiss_precut -> Fill ( Met_et, weight );
                                        hist_ptLL_precut -> Fill ( ptLL, weight );
                                        hist_dPhiLL_precut -> Fill ( dPhiLL, weight );

                                    }

                                    if ( type == 7 )
                                    {                                               

                                        hist_mt_tt_precut -> Fill ( mt, weight );
                                        hist_etmiss_tt_precut -> Fill ( Met_et, weight );
                                        hist_ptLL_tt_precut -> Fill ( ptLL, weight );
                                        hist_dPhiLL_tt_precut -> Fill ( dPhiLL, weight );

                                        hist_mt_precut -> Fill ( mt, weight );
                                        hist_etmiss_precut -> Fill ( Met_et, weight );
                                        hist_ptLL_precut -> Fill ( ptLL, weight );
                                        hist_dPhiLL_precut -> Fill ( dPhiLL, weight );

                                    }

                                    if ( type == 8 )
                                    {                                               

                                        hist_mt_t_precut -> Fill ( mt, weight );
                                        hist_etmiss_t_precut -> Fill ( Met_et, weight );
                                        hist_ptLL_t_precut -> Fill ( ptLL, weight );
                                        hist_dPhiLL_t_precut -> Fill ( dPhiLL, weight );

                                        hist_mt_precut -> Fill ( mt, weight );
                                        hist_etmiss_precut -> Fill ( Met_et, weight );
                                        hist_ptLL_precut -> Fill ( ptLL, weight );
                                        hist_dPhiLL_precut -> Fill ( dPhiLL, weight );

                                    }


                                // CUTS

                                    if ( goodjet_n < 2 && goodbjet_n == 0 )
                                    {

                                        if ( dPhiLLmet > ( TMath::Pi() / 2) )
                                        {

                                            if ( ptLL > 30. )
                                            {

                                                if ( mLL > 10. && mLL < 55. )
                                                {

                                                    if ( Met_et > 30. )
                                                    {

                                                        if ( dPhiLL < 1.8 )
                                                        {


                                                            // FILL HISTOGRAMS

                                                                if ( type == 0 )
                                                                {                                               

                                                                    hist_mt_Data -> Fill ( mt );
                                                                    hist_etmiss_Data -> Fill ( Met_et );
                                                                    hist_ptLL_Data -> Fill ( ptLL );
                                                                    hist_dPhiLL_Data -> Fill ( dPhiLL );

                                                                }

                                                                if ( type == 1 || type == 2 )
                                                                {                                               

                                                                    hist_mt_Higgs -> Fill ( mt, weight );
                                                                    hist_etmiss_Higgs -> Fill ( Met_et, weight );
                                                                    hist_ptLL_Higgs -> Fill ( ptLL, weight );
                                                                    hist_dPhiLL_Higgs -> Fill ( dPhiLL, weight );

                                                                    hist_mt -> Fill ( mt, weight );
                                                                    hist_etmiss -> Fill ( Met_et, weight );
                                                                    hist_ptLL -> Fill ( ptLL, weight );
                                                                    hist_dPhiLL -> Fill ( dPhiLL, weight );

                                                                }

                                                                if ( type == 3 || type == 4 || type == 5)
                                                                {                                               

                                                                    hist_mt_Diboson -> Fill ( mt, weight );
                                                                    hist_etmiss_Diboson -> Fill ( Met_et, weight );
                                                                    hist_ptLL_Diboson -> Fill ( ptLL, weight );
                                                                    hist_dPhiLL_Diboson -> Fill ( dPhiLL, weight );

                                                                    hist_mt -> Fill ( mt, weight );
                                                                    hist_etmiss -> Fill ( Met_et, weight );
                                                                    hist_ptLL -> Fill ( ptLL, weight );
                                                                    hist_dPhiLL -> Fill ( dPhiLL, weight );

                                                                }

                                                                if ( type == 6 )
                                                                {                                               

                                                                    hist_mt_Vjets -> Fill ( mt, weight );
                                                                    hist_etmiss_Vjets -> Fill ( Met_et, weight );
                                                                    hist_ptLL_Vjets -> Fill ( ptLL, weight );
                                                                    hist_dPhiLL_Vjets -> Fill ( dPhiLL, weight );

                                                                    hist_mt -> Fill ( mt, weight );
                                                                    hist_etmiss -> Fill ( Met_et, weight );
                                                                    hist_ptLL -> Fill ( ptLL, weight );
                                                                    hist_dPhiLL -> Fill ( dPhiLL, weight );

                                                                }

                                                                if ( type == 7 )
                                                                {                                               

                                                                    hist_mt_tt -> Fill ( mt, weight );
                                                                    hist_etmiss_tt -> Fill ( Met_et, weight );
                                                                    hist_ptLL_tt -> Fill ( ptLL, weight );
                                                                    hist_dPhiLL_tt -> Fill ( dPhiLL, weight );

                                                                    hist_mt -> Fill ( mt, weight );
                                                                    hist_etmiss -> Fill ( Met_et, weight );
                                                                    hist_ptLL -> Fill ( ptLL, weight );
                                                                    hist_dPhiLL -> Fill ( dPhiLL, weight );

                                                                }

                                                                if ( type == 8 )
                                                                {                                               

                                                                    hist_mt_t -> Fill ( mt, weight );
                                                                    hist_etmiss_t -> Fill ( Met_et, weight );
                                                                    hist_ptLL_t -> Fill ( ptLL, weight );
                                                                    hist_dPhiLL_t -> Fill ( dPhiLL, weight );

                                                                    hist_mt -> Fill ( mt, weight );
                                                                    hist_etmiss -> Fill ( Met_et, weight );
                                                                    hist_ptLL -> Fill ( ptLL, weight );
                                                                    hist_dPhiLL -> Fill ( dPhiLL, weight );

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

        }

  }


  // INTEGRAL

    // DATA

        float Int_mt_Data_precut = hist_mt_Data_precut -> Integral (0, 16);
        std::cout << "* mt_precut: " << Int_mt_Data_precut << std::endl;

        float Int_etmiss_Data_precut = hist_etmiss_Data_precut -> Integral (0, 21);
        std::cout << "* etmiss_precut: " << Int_etmiss_Data_precut << std::endl;

        float Int_ptLL_Data_precut = hist_ptLL_Data_precut -> Integral (0, 31);
        std::cout << "* ptLL_precut: " << Int_ptLL_Data_precut << std::endl;

        float Int_dPhiLL_Data_precut = hist_dPhiLL_Data_precut -> Integral (0, 21);
        std::cout << "* dPhiLL_precut: " << Int_dPhiLL_Data_precut << std::endl;

        float Int_mt_Data = hist_mt_Data -> Integral (0, 16);
        std::cout << "* mt: " << Int_mt_Data << std::endl;

        float Int_etmiss_Data = hist_etmiss_Data -> Integral (0, 21);
        std::cout << "* etmiss: " << Int_etmiss_Data << std::endl;

        float Int_ptLL_Data = hist_ptLL_Data -> Integral (0, 31);
        std::cout << "* ptLL: " << Int_ptLL_Data << std::endl;

        float Int_dPhiLL_Data = hist_dPhiLL_Data -> Integral (0, 21);
        std::cout << "* dPhiLL: " << Int_dPhiLL_Data << std::endl;


    // HIGGS

        float Int_mt_Higgs_precut = hist_mt_Higgs_precut -> Integral (0, 16);
        std::cout << "* mt_precut: " << Int_mt_Higgs_precut << std::endl;

        float Int_etmiss_Higgs_precut = hist_etmiss_Higgs_precut -> Integral (0, 21);
        std::cout << "* etmiss_precut: " << Int_etmiss_Higgs_precut << std::endl;

        float Int_ptLL_Higgs_precut = hist_ptLL_Higgs_precut -> Integral (0, 31);
        std::cout << "* ptLL_precut: " << Int_ptLL_Higgs_precut << std::endl;

        float Int_dPhiLL_Higgs_precut = hist_dPhiLL_Higgs_precut -> Integral (0, 21);
        std::cout << "* dPhiLL_precut: " << Int_dPhiLL_Higgs_precut << std::endl;

        float Int_mt_Higgs = hist_mt_Higgs -> Integral (0, 16);
        std::cout << "* mt: " << Int_mt_Higgs << std::endl;

        float Int_etmiss_Higgs = hist_etmiss_Higgs -> Integral (0, 21);
        std::cout << "* etmiss: " << Int_etmiss_Higgs << std::endl;

        float Int_ptLL_Higgs = hist_ptLL_Higgs -> Integral (0, 31);
        std::cout << "* ptLL: " << Int_ptLL_Higgs << std::endl;

        float Int_dPhiLL_Higgs = hist_dPhiLL_Higgs -> Integral (0, 21);
        std::cout << "* dPhiLL: " << Int_dPhiLL_Higgs << std::endl;


    // DIBOSON

        float Int_mt_Diboson_precut = hist_mt_Diboson_precut -> Integral (0, 16);
        std::cout << "* mt_precut: " << Int_mt_Diboson_precut << std::endl;

        float Int_etmiss_Diboson_precut = hist_etmiss_Diboson_precut -> Integral (0, 21);
        std::cout << "* etmiss_precut: " << Int_etmiss_Diboson_precut << std::endl;

        float Int_ptLL_Diboson_precut = hist_ptLL_Diboson_precut -> Integral (0, 31);
        std::cout << "* ptLL_precut: " << Int_ptLL_Diboson_precut << std::endl;

        float Int_dPhiLL_Diboson_precut = hist_dPhiLL_Diboson_precut -> Integral (0, 21);
        std::cout << "* dPhiLL_precut: " << Int_dPhiLL_Diboson_precut << std::endl;

        float Int_mt_Diboson = hist_mt_Diboson -> Integral (0, 16);
        std::cout << "* mt: " << Int_mt_Diboson << std::endl;

        float Int_etmiss_Diboson = hist_etmiss_Diboson -> Integral (0, 21);
        std::cout << "* etmiss: " << Int_etmiss_Diboson << std::endl;

        float Int_ptLL_Diboson = hist_ptLL_Diboson -> Integral (0, 31);
        std::cout << "* ptLL: " << Int_ptLL_Diboson << std::endl;

        float Int_dPhiLL_Diboson = hist_dPhiLL_Diboson -> Integral (0, 21);
        std::cout << "* dPhiLL: " << Int_dPhiLL_Diboson << std::endl;


    // V + JETS

        float Int_mt_Vjets_precut = hist_mt_Vjets_precut -> Integral (0, 16);
        std::cout << "* mt_precut: " << Int_mt_Vjets_precut << std::endl;

        float Int_etmiss_Vjets_precut = hist_etmiss_Vjets_precut -> Integral (0, 21);
        std::cout << "* etmiss_precut: " << Int_etmiss_Vjets_precut << std::endl;

        float Int_ptLL_Vjets_precut = hist_ptLL_Vjets_precut -> Integral (0, 31);
        std::cout << "* ptLL_precut: " << Int_ptLL_Vjets_precut << std::endl;

        float Int_dPhiLL_Vjets_precut = hist_dPhiLL_Vjets_precut -> Integral (0, 21);
        std::cout << "* dPhiLL_precut: " << Int_dPhiLL_Vjets_precut << std::endl;

        float Int_mt_Vjets = hist_mt_Vjets -> Integral (0, 16);
        std::cout << "* mt: " << Int_mt_Vjets << std::endl;

        float Int_etmiss_Vjets = hist_etmiss_Vjets -> Integral (0, 21);
        std::cout << "* etmiss: " << Int_etmiss_Vjets << std::endl;

        float Int_ptLL_Vjets = hist_ptLL_Vjets -> Integral (0, 31);
        std::cout << "* ptLL: " << Int_ptLL_Vjets << std::endl;

        float Int_dPhiLL_Vjets = hist_dPhiLL_Vjets -> Integral (0, 21);
        std::cout << "* dPhiLL: " << Int_dPhiLL_Vjets << std::endl;


    // TOP - ANTITOP

        float Int_mt_tt_precut = hist_mt_tt_precut -> Integral (0, 16);
        std::cout << "* mt_precut: " << Int_mt_tt_precut << std::endl;

        float Int_etmiss_tt_precut = hist_etmiss_tt_precut -> Integral (0, 21);
        std::cout << "* etmiss_precut: " << Int_etmiss_tt_precut << std::endl;

        float Int_ptLL_tt_precut = hist_ptLL_tt_precut -> Integral (0, 31);
        std::cout << "* ptLL_precut: " << Int_ptLL_tt_precut << std::endl;

        float Int_dPhiLL_tt_precut = hist_dPhiLL_tt_precut -> Integral (0, 21);
        std::cout << "* dPhiLL_precut: " << Int_dPhiLL_tt_precut << std::endl;

        float Int_mt_tt = hist_mt_tt -> Integral (0, 16);
        std::cout << "* mt: " << Int_mt_tt << std::endl;

        float Int_etmiss_tt = hist_etmiss_tt -> Integral (0, 21);
        std::cout << "* etmiss: " << Int_etmiss_tt << std::endl;

        float Int_ptLL_tt = hist_ptLL_tt -> Integral (0, 31);
        std::cout << "* ptLL: " << Int_ptLL_tt << std::endl;

        float Int_dPhiLL_tt = hist_dPhiLL_tt -> Integral (0, 21);
        std::cout << "* dPhiLL: " << Int_dPhiLL_tt << std::endl;


    // SINGLE TOP

        float Int_mt_t_precut = hist_mt_t_precut -> Integral (0, 16);
        std::cout << "* mt_precut: " << Int_mt_t_precut << std::endl;

        float Int_etmiss_t_precut = hist_etmiss_t_precut -> Integral (0, 21);
        std::cout << "* etmiss_precut: " << Int_etmiss_t_precut << std::endl;

        float Int_ptLL_t_precut = hist_ptLL_t_precut -> Integral (0, 31);
        std::cout << "* ptLL_precut: " << Int_ptLL_t_precut << std::endl;

        float Int_dPhiLL_t_precut = hist_dPhiLL_t_precut -> Integral (0, 21);
        std::cout << "* dPhiLL_precut: " << Int_dPhiLL_t_precut << std::endl;

        float Int_mt_t = hist_mt_t -> Integral (0, 16);
        std::cout << "* mt: " << Int_mt_t << std::endl;

        float Int_etmiss_t = hist_etmiss_t -> Integral (0, 21);
        std::cout << "* etmiss: " << Int_etmiss_t << std::endl;

        float Int_ptLL_t = hist_ptLL_t -> Integral (0, 31);
        std::cout << "* ptLL: " << Int_ptLL_t << std::endl;

        float Int_dPhiLL_t = hist_dPhiLL_t -> Integral (0, 21);
        std::cout << "* dPhiLL: " << Int_dPhiLL_t << std::endl;


  // SCALE HIGGS IN PRE-CUT HISTOGRAMS

    float Int_mt_scale = ( Int_mt_Higgs_precut + Int_mt_Diboson_precut + Int_mt_Vjets_precut + Int_mt_tt_precut + Int_mt_t_precut );
    float Int_etmiss_scale = ( Int_etmiss_Higgs_precut + Int_etmiss_Diboson_precut + Int_etmiss_Vjets_precut + Int_etmiss_tt_precut + Int_etmiss_t_precut );
    float Int_ptLL_scale = ( Int_ptLL_Higgs_precut + Int_ptLL_Diboson_precut + Int_ptLL_Vjets_precut + Int_ptLL_tt_precut + Int_ptLL_t_precut );
    float Int_dPhiLL_scale = ( Int_dPhiLL_Higgs_precut + Int_dPhiLL_Diboson_precut + Int_dPhiLL_Vjets_precut + Int_dPhiLL_tt_precut + Int_dPhiLL_t_precut );

    hist_mt_Higgs_norm -> Scale ( Int_mt_scale / Int_mt_Higgs_precut );
    hist_etmiss_Higgs_norm -> Scale ( Int_etmiss_scale / Int_etmiss_Higgs_precut );
    hist_ptLL_Higgs_norm -> Scale ( Int_ptLL_scale / Int_ptLL_Higgs_precut );
    hist_dPhiLL_Higgs_norm -> Scale ( Int_dPhiLL_scale / Int_dPhiLL_Higgs_precut );


  // OVERFLOW IN LAST BIN OF HISTOGRAMS

    hist_mt_precut -> SetBinContent ( hist_mt_precut -> GetNbinsX(), hist_mt_precut -> GetBinContent ( hist_mt_precut -> GetNbinsX() ) + hist_mt_precut -> GetBinContent ( hist_mt_precut -> GetNbinsX() + 1 ) );

    hist_mt -> SetBinContent ( hist_mt -> GetNbinsX(), hist_mt -> GetBinContent ( hist_mt -> GetNbinsX() ) + hist_mt -> GetBinContent ( hist_mt -> GetNbinsX() + 1 ) );

    hist_etmiss_precut -> SetBinContent ( hist_etmiss_precut -> GetNbinsX(), hist_etmiss_precut -> GetBinContent ( hist_etmiss_precut -> GetNbinsX() ) + hist_etmiss_precut -> GetBinContent ( hist_etmiss_precut -> GetNbinsX() + 1 ) );

    hist_etmiss -> SetBinContent ( hist_etmiss -> GetNbinsX(), hist_etmiss -> GetBinContent ( hist_etmiss -> GetNbinsX() ) + hist_etmiss -> GetBinContent ( hist_etmiss -> GetNbinsX() + 1 ) );

    hist_ptLL_precut -> SetBinContent ( hist_ptLL_precut -> GetNbinsX(), hist_ptLL_precut -> GetBinContent ( hist_ptLL_precut -> GetNbinsX() ) + hist_ptLL_precut -> GetBinContent ( hist_ptLL_precut -> GetNbinsX() + 1 ) );

    hist_ptLL -> SetBinContent ( hist_ptLL -> GetNbinsX(), hist_ptLL -> GetBinContent ( hist_ptLL -> GetNbinsX() ) + hist_ptLL -> GetBinContent ( hist_ptLL -> GetNbinsX() + 1 ) );

    hist_dPhiLL_precut -> SetBinContent ( hist_dPhiLL_precut -> GetNbinsX(), hist_dPhiLL_precut -> GetBinContent ( hist_dPhiLL_precut -> GetNbinsX() ) + hist_dPhiLL_precut -> GetBinContent ( hist_dPhiLL_precut -> GetNbinsX() + 1 ) );

    hist_dPhiLL -> SetBinContent ( hist_dPhiLL -> GetNbinsX(), hist_dPhiLL -> GetBinContent ( hist_dPhiLL -> GetNbinsX() ) + hist_dPhiLL -> GetBinContent ( hist_dPhiLL -> GetNbinsX() + 1 ) );

    // DATA

        hist_mt_Data -> SetBinContent ( hist_mt_Data -> GetNbinsX(), hist_mt_Data -> GetBinContent ( hist_mt_Data -> GetNbinsX() ) + hist_mt_Data -> GetBinContent ( hist_mt_Data -> GetNbinsX() + 1 ) );

        hist_mt_Data_precut -> SetBinContent ( hist_mt_Data_precut -> GetNbinsX(), hist_mt_Data_precut -> GetBinContent ( hist_mt_Data_precut -> GetNbinsX() ) + hist_mt_Data_precut -> GetBinContent ( hist_mt_Data_precut -> GetNbinsX() + 1 ) );

        hist_etmiss_Data -> SetBinContent ( hist_etmiss_Data -> GetNbinsX(), hist_etmiss_Data -> GetBinContent ( hist_etmiss_Data -> GetNbinsX() ) + hist_etmiss_Data -> GetBinContent ( hist_etmiss_Data -> GetNbinsX() + 1 ) );

        hist_etmiss_Data_precut -> SetBinContent ( hist_etmiss_Data_precut -> GetNbinsX(), hist_etmiss_Data_precut -> GetBinContent ( hist_etmiss_Data_precut -> GetNbinsX() ) + hist_etmiss_Data_precut -> GetBinContent ( hist_etmiss_Data_precut -> GetNbinsX() + 1 ) );

        hist_ptLL_Data -> SetBinContent ( hist_ptLL_Data -> GetNbinsX(), hist_ptLL_Data -> GetBinContent ( hist_ptLL_Data -> GetNbinsX() ) + hist_ptLL_Data -> GetBinContent ( hist_ptLL_Data -> GetNbinsX() + 1 ) );

        hist_ptLL_Data_precut -> SetBinContent ( hist_ptLL_Data_precut -> GetNbinsX(), hist_ptLL_Data_precut -> GetBinContent ( hist_ptLL_Data_precut -> GetNbinsX() ) + hist_ptLL_Data_precut -> GetBinContent ( hist_ptLL_Data_precut -> GetNbinsX() + 1 ) );

        hist_dPhiLL_Data -> SetBinContent ( hist_dPhiLL_Data -> GetNbinsX(), hist_dPhiLL_Data -> GetBinContent ( hist_dPhiLL_Data -> GetNbinsX() ) + hist_dPhiLL_Data -> GetBinContent ( hist_dPhiLL_Data -> GetNbinsX() + 1 ) );

        hist_dPhiLL_Data_precut -> SetBinContent ( hist_dPhiLL_Data_precut -> GetNbinsX(), hist_dPhiLL_Data_precut -> GetBinContent ( hist_dPhiLL_Data_precut -> GetNbinsX() ) + hist_dPhiLL_Data_precut -> GetBinContent ( hist_dPhiLL_Data_precut -> GetNbinsX() + 1 ) );


    // HIGGS

        hist_mt_Higgs -> SetBinContent ( hist_mt_Higgs -> GetNbinsX(), hist_mt_Higgs -> GetBinContent ( hist_mt_Higgs -> GetNbinsX() ) + hist_mt_Higgs -> GetBinContent ( hist_mt_Higgs -> GetNbinsX() + 1 ) );

        hist_mt_Higgs_precut -> SetBinContent ( hist_mt_Higgs_precut -> GetNbinsX(), hist_mt_Higgs_precut -> GetBinContent ( hist_mt_Higgs_precut -> GetNbinsX() ) + hist_mt_Higgs_precut -> GetBinContent ( hist_mt_Higgs_precut -> GetNbinsX() + 1 ) );

        hist_mt_Higgs_norm -> SetBinContent ( hist_mt_Higgs_norm -> GetNbinsX(), hist_mt_Higgs_norm -> GetBinContent ( hist_mt_Higgs_norm -> GetNbinsX() ) + hist_mt_Higgs_norm -> GetBinContent ( hist_mt_Higgs_norm -> GetNbinsX() + 1 ) );

        hist_etmiss_Higgs -> SetBinContent ( hist_etmiss_Higgs -> GetNbinsX(), hist_etmiss_Higgs -> GetBinContent ( hist_etmiss_Higgs -> GetNbinsX() ) + hist_etmiss_Higgs -> GetBinContent ( hist_etmiss_Higgs -> GetNbinsX() + 1 ) );

        hist_etmiss_Higgs_precut -> SetBinContent ( hist_etmiss_Higgs_precut -> GetNbinsX(), hist_etmiss_Higgs_precut -> GetBinContent ( hist_etmiss_Higgs_precut -> GetNbinsX() ) + hist_etmiss_Higgs_precut -> GetBinContent ( hist_etmiss_Higgs_precut -> GetNbinsX() + 1 ) );

        hist_etmiss_Higgs_norm -> SetBinContent ( hist_etmiss_Higgs_norm -> GetNbinsX(), hist_etmiss_Higgs_norm -> GetBinContent ( hist_etmiss_Higgs_norm -> GetNbinsX() ) + hist_etmiss_Higgs_norm -> GetBinContent ( hist_etmiss_Higgs_norm -> GetNbinsX() + 1 ) );

        hist_ptLL_Higgs -> SetBinContent ( hist_ptLL_Higgs -> GetNbinsX(), hist_ptLL_Higgs -> GetBinContent ( hist_ptLL_Higgs -> GetNbinsX() ) + hist_ptLL_Higgs -> GetBinContent ( hist_ptLL_Higgs -> GetNbinsX() + 1 ) );

        hist_ptLL_Higgs_precut -> SetBinContent ( hist_ptLL_Higgs_precut -> GetNbinsX(), hist_ptLL_Higgs_precut -> GetBinContent ( hist_ptLL_Higgs_precut -> GetNbinsX() ) + hist_ptLL_Higgs_precut -> GetBinContent ( hist_ptLL_Higgs_precut -> GetNbinsX() + 1 ) );

        hist_ptLL_Higgs_norm -> SetBinContent ( hist_ptLL_Higgs_norm -> GetNbinsX(), hist_ptLL_Higgs_norm -> GetBinContent ( hist_ptLL_Higgs_norm -> GetNbinsX() ) + hist_ptLL_Higgs_norm -> GetBinContent ( hist_ptLL_Higgs_norm -> GetNbinsX() + 1 ) );

        hist_dPhiLL_Higgs -> SetBinContent ( hist_dPhiLL_Higgs -> GetNbinsX(), hist_dPhiLL_Higgs -> GetBinContent ( hist_dPhiLL_Higgs -> GetNbinsX() ) + hist_dPhiLL_Higgs -> GetBinContent ( hist_dPhiLL_Higgs -> GetNbinsX() + 1 ) );

        hist_dPhiLL_Higgs_precut -> SetBinContent ( hist_dPhiLL_Higgs_precut -> GetNbinsX(), hist_dPhiLL_Higgs_precut -> GetBinContent ( hist_dPhiLL_Higgs_precut -> GetNbinsX() ) + hist_dPhiLL_Higgs_precut -> GetBinContent ( hist_dPhiLL_Higgs_precut -> GetNbinsX() + 1 ) );

        hist_dPhiLL_Higgs_norm -> SetBinContent ( hist_dPhiLL_Higgs_norm -> GetNbinsX(), hist_dPhiLL_Higgs_norm -> GetBinContent ( hist_dPhiLL_Higgs_norm -> GetNbinsX() ) + hist_dPhiLL_Higgs_norm -> GetBinContent ( hist_dPhiLL_Higgs_norm -> GetNbinsX() + 1 ) );


    // DIBOSON

        hist_mt_Diboson -> SetBinContent ( hist_mt_Diboson -> GetNbinsX(), hist_mt_Diboson -> GetBinContent ( hist_mt_Diboson -> GetNbinsX() ) + hist_mt_Diboson -> GetBinContent ( hist_mt_Diboson -> GetNbinsX() + 1 ) );

        hist_mt_Diboson_precut -> SetBinContent ( hist_mt_Diboson_precut -> GetNbinsX(), hist_mt_Diboson_precut -> GetBinContent ( hist_mt_Diboson_precut -> GetNbinsX() ) + hist_mt_Diboson_precut -> GetBinContent ( hist_mt_Diboson_precut -> GetNbinsX() + 1 ) );

        hist_etmiss_Diboson -> SetBinContent ( hist_etmiss_Diboson -> GetNbinsX(), hist_etmiss_Diboson -> GetBinContent ( hist_etmiss_Diboson -> GetNbinsX() ) + hist_etmiss_Diboson -> GetBinContent ( hist_etmiss_Diboson -> GetNbinsX() + 1 ) );

        hist_etmiss_Diboson_precut -> SetBinContent ( hist_etmiss_Diboson_precut -> GetNbinsX(), hist_etmiss_Diboson_precut -> GetBinContent ( hist_etmiss_Diboson_precut -> GetNbinsX() ) + hist_etmiss_Diboson_precut -> GetBinContent ( hist_etmiss_Diboson_precut -> GetNbinsX() + 1 ) );

        hist_ptLL_Diboson -> SetBinContent ( hist_ptLL_Diboson -> GetNbinsX(), hist_ptLL_Diboson -> GetBinContent ( hist_ptLL_Diboson -> GetNbinsX() ) + hist_ptLL_Diboson -> GetBinContent ( hist_ptLL_Diboson -> GetNbinsX() + 1 ) );

        hist_ptLL_Diboson_precut -> SetBinContent ( hist_ptLL_Diboson_precut -> GetNbinsX(), hist_ptLL_Diboson_precut -> GetBinContent ( hist_ptLL_Diboson_precut -> GetNbinsX() ) + hist_ptLL_Diboson_precut -> GetBinContent ( hist_ptLL_Diboson_precut -> GetNbinsX() + 1 ) );

        hist_dPhiLL_Diboson -> SetBinContent ( hist_dPhiLL_Diboson -> GetNbinsX(), hist_dPhiLL_Diboson -> GetBinContent ( hist_dPhiLL_Diboson -> GetNbinsX() ) + hist_dPhiLL_Diboson -> GetBinContent ( hist_dPhiLL_Diboson -> GetNbinsX() + 1 ) );

        hist_dPhiLL_Diboson_precut -> SetBinContent ( hist_dPhiLL_Diboson_precut -> GetNbinsX(), hist_dPhiLL_Diboson_precut -> GetBinContent ( hist_dPhiLL_Diboson_precut -> GetNbinsX() ) + hist_dPhiLL_Diboson_precut -> GetBinContent ( hist_dPhiLL_Diboson_precut -> GetNbinsX() + 1 ) );


    // V + JETS

        hist_mt_Vjets -> SetBinContent ( hist_mt_Vjets -> GetNbinsX(), hist_mt_Vjets -> GetBinContent ( hist_mt_Vjets -> GetNbinsX() ) + hist_mt_Vjets -> GetBinContent ( hist_mt_Vjets -> GetNbinsX() + 1 ) );

        hist_mt_Vjets_precut -> SetBinContent ( hist_mt_Vjets_precut -> GetNbinsX(), hist_mt_Vjets_precut -> GetBinContent ( hist_mt_Vjets_precut -> GetNbinsX() ) + hist_mt_Vjets_precut -> GetBinContent ( hist_mt_Vjets_precut -> GetNbinsX() + 1 ) );

        hist_etmiss_Vjets -> SetBinContent ( hist_etmiss_Vjets -> GetNbinsX(), hist_etmiss_Vjets -> GetBinContent ( hist_etmiss_Vjets -> GetNbinsX() ) + hist_etmiss_Vjets -> GetBinContent ( hist_etmiss_Vjets -> GetNbinsX() + 1 ) );

        hist_etmiss_Vjets_precut -> SetBinContent ( hist_etmiss_Vjets_precut -> GetNbinsX(), hist_etmiss_Vjets_precut -> GetBinContent ( hist_etmiss_Vjets_precut -> GetNbinsX() ) + hist_etmiss_Vjets_precut -> GetBinContent ( hist_etmiss_Vjets_precut -> GetNbinsX() + 1 ) );

        hist_ptLL_Vjets -> SetBinContent ( hist_ptLL_Vjets -> GetNbinsX(), hist_ptLL_Vjets -> GetBinContent ( hist_ptLL_Vjets -> GetNbinsX() ) + hist_ptLL_Vjets -> GetBinContent ( hist_ptLL_Vjets -> GetNbinsX() + 1 ) );

        hist_ptLL_Vjets_precut -> SetBinContent ( hist_ptLL_Vjets_precut -> GetNbinsX(), hist_ptLL_Vjets_precut -> GetBinContent ( hist_ptLL_Vjets_precut -> GetNbinsX() ) + hist_ptLL_Vjets_precut -> GetBinContent ( hist_ptLL_Vjets_precut -> GetNbinsX() + 1 ) );

        hist_dPhiLL_Vjets -> SetBinContent ( hist_dPhiLL_Vjets -> GetNbinsX(), hist_dPhiLL_Vjets -> GetBinContent ( hist_dPhiLL_Vjets -> GetNbinsX() ) + hist_dPhiLL_Vjets -> GetBinContent ( hist_dPhiLL_Vjets -> GetNbinsX() + 1 ) );

        hist_dPhiLL_Vjets_precut -> SetBinContent ( hist_dPhiLL_Vjets_precut -> GetNbinsX(), hist_dPhiLL_Vjets_precut -> GetBinContent ( hist_dPhiLL_Vjets_precut -> GetNbinsX() ) + hist_dPhiLL_Vjets_precut -> GetBinContent ( hist_dPhiLL_Vjets_precut -> GetNbinsX() + 1 ) );


    // TOP - ANTITOP

        hist_mt_tt -> SetBinContent ( hist_mt_tt -> GetNbinsX(), hist_mt_tt -> GetBinContent ( hist_mt_tt -> GetNbinsX() ) + hist_mt_tt -> GetBinContent ( hist_mt_tt -> GetNbinsX() + 1 ) );

        hist_mt_tt_precut -> SetBinContent ( hist_mt_tt_precut -> GetNbinsX(), hist_mt_tt_precut -> GetBinContent ( hist_mt_tt_precut -> GetNbinsX() ) + hist_mt_tt_precut -> GetBinContent ( hist_mt_tt_precut -> GetNbinsX() + 1 ) );

        hist_etmiss_tt -> SetBinContent ( hist_etmiss_tt -> GetNbinsX(), hist_etmiss_tt -> GetBinContent ( hist_etmiss_tt -> GetNbinsX() ) + hist_etmiss_tt -> GetBinContent ( hist_etmiss_tt -> GetNbinsX() + 1 ) );

        hist_etmiss_tt_precut -> SetBinContent ( hist_etmiss_tt_precut -> GetNbinsX(), hist_etmiss_tt_precut -> GetBinContent ( hist_etmiss_tt_precut -> GetNbinsX() ) + hist_etmiss_tt_precut -> GetBinContent ( hist_etmiss_tt_precut -> GetNbinsX() + 1 ) );

        hist_ptLL_tt -> SetBinContent ( hist_ptLL_tt -> GetNbinsX(), hist_ptLL_tt -> GetBinContent ( hist_ptLL_tt -> GetNbinsX() ) + hist_ptLL_tt -> GetBinContent ( hist_ptLL_tt -> GetNbinsX() + 1 ) );

        hist_ptLL_tt_precut -> SetBinContent ( hist_ptLL_tt_precut -> GetNbinsX(), hist_ptLL_tt_precut -> GetBinContent ( hist_ptLL_tt_precut -> GetNbinsX() ) + hist_ptLL_tt_precut -> GetBinContent ( hist_ptLL_tt_precut -> GetNbinsX() + 1 ) );

        hist_dPhiLL_tt -> SetBinContent ( hist_dPhiLL_tt -> GetNbinsX(), hist_dPhiLL_tt -> GetBinContent ( hist_dPhiLL_tt -> GetNbinsX() ) + hist_dPhiLL_tt -> GetBinContent ( hist_dPhiLL_tt -> GetNbinsX() + 1 ) );

        hist_dPhiLL_tt_precut -> SetBinContent ( hist_dPhiLL_tt_precut -> GetNbinsX(), hist_dPhiLL_tt_precut -> GetBinContent ( hist_dPhiLL_tt_precut -> GetNbinsX() ) + hist_dPhiLL_tt_precut -> GetBinContent ( hist_dPhiLL_tt_precut -> GetNbinsX() + 1 ) );


    // SINGLE TOP

        hist_mt_t -> SetBinContent ( hist_mt_t -> GetNbinsX(), hist_mt_t -> GetBinContent ( hist_mt_t -> GetNbinsX() ) + hist_mt_t -> GetBinContent ( hist_mt_t -> GetNbinsX() + 1 ) );

        hist_mt_t_precut -> SetBinContent ( hist_mt_t_precut -> GetNbinsX(), hist_mt_t_precut -> GetBinContent ( hist_mt_t_precut -> GetNbinsX() ) + hist_mt_t_precut -> GetBinContent ( hist_mt_t_precut -> GetNbinsX() + 1 ) );

        hist_etmiss_t -> SetBinContent ( hist_etmiss_t -> GetNbinsX(), hist_etmiss_t -> GetBinContent ( hist_etmiss_t -> GetNbinsX() ) + hist_etmiss_t -> GetBinContent ( hist_etmiss_t -> GetNbinsX() + 1 ) );

        hist_etmiss_t_precut -> SetBinContent ( hist_etmiss_t_precut -> GetNbinsX(), hist_etmiss_t_precut -> GetBinContent ( hist_etmiss_t_precut -> GetNbinsX() ) + hist_etmiss_t_precut -> GetBinContent ( hist_etmiss_t_precut -> GetNbinsX() + 1 ) );

        hist_ptLL_t -> SetBinContent ( hist_ptLL_t -> GetNbinsX(), hist_ptLL_t -> GetBinContent ( hist_ptLL_t -> GetNbinsX() ) + hist_ptLL_t -> GetBinContent ( hist_ptLL_t -> GetNbinsX() + 1 ) );

        hist_ptLL_t_precut -> SetBinContent ( hist_ptLL_t_precut -> GetNbinsX(), hist_ptLL_t_precut -> GetBinContent ( hist_ptLL_t_precut -> GetNbinsX() ) + hist_ptLL_t_precut -> GetBinContent ( hist_ptLL_t_precut -> GetNbinsX() + 1 ) );

        hist_dPhiLL_t -> SetBinContent ( hist_dPhiLL_t -> GetNbinsX(), hist_dPhiLL_t -> GetBinContent ( hist_dPhiLL_t -> GetNbinsX() ) + hist_dPhiLL_t -> GetBinContent ( hist_dPhiLL_t -> GetNbinsX() + 1 ) );

        hist_dPhiLL_t_precut -> SetBinContent ( hist_dPhiLL_t_precut -> GetNbinsX(), hist_dPhiLL_t_precut -> GetBinContent ( hist_dPhiLL_t_precut -> GetNbinsX() ) + hist_dPhiLL_t_precut -> GetBinContent ( hist_dPhiLL_t_precut -> GetNbinsX() + 1 ) );


  // LEGEND

    auto legend_mt_precut = new TLegend (0.79, 0.50, 0.90, 0.85);
    legend_mt_precut -> AddEntry (hist_mt_Data_precut," #bf{Data}","lep");
    legend_mt_precut -> AddEntry (hist_mt_Higgs_precut," #bf{Higgs}","f");
    legend_mt_precut -> AddEntry (hist_mt_Diboson_precut," #bf{Diboson}","f");
    legend_mt_precut -> AddEntry (hist_mt_Vjets_precut," #bf{V+jets}","f");
    legend_mt_precut -> AddEntry (hist_mt_tt_precut," #bf{t#bar{t}}","f");
    legend_mt_precut -> AddEntry (hist_mt_t_precut," #bf{Single top}","f");
    legend_mt_precut -> AddEntry (hist_mt_Higgs_norm," #bf{Higgs_{norm}}","l");
    legend_mt_precut -> SetBorderSize(0);

    auto legend_etmiss_precut = new TLegend (0.79, 0.50, 0.90, 0.85);
    legend_etmiss_precut -> AddEntry (hist_etmiss_Data_precut," #bf{Data}","lep");
    legend_etmiss_precut -> AddEntry (hist_etmiss_Higgs_precut," #bf{Higgs}","f");
    legend_etmiss_precut -> AddEntry (hist_etmiss_Diboson_precut," #bf{Diboson}","f");
    legend_etmiss_precut -> AddEntry (hist_etmiss_Vjets_precut," #bf{V+jets}","f");
    legend_etmiss_precut -> AddEntry (hist_etmiss_tt_precut," #bf{t#bar{t}}","f");
    legend_etmiss_precut -> AddEntry (hist_etmiss_t_precut," #bf{Single top}","f");
    legend_etmiss_precut -> AddEntry (hist_etmiss_Higgs_norm," #bf{Higgs_{norm}}","l");
    legend_etmiss_precut -> SetBorderSize(0);

    auto legend_ptLL_precut = new TLegend (0.79, 0.50, 0.90, 0.85);
    legend_ptLL_precut -> AddEntry (hist_ptLL_Data_precut," #bf{Data}","lep");
    legend_ptLL_precut -> AddEntry (hist_ptLL_Higgs_precut," #bf{Higgs}","f");
    legend_ptLL_precut -> AddEntry (hist_ptLL_Diboson_precut," #bf{Diboson}","f");
    legend_ptLL_precut -> AddEntry (hist_ptLL_Vjets_precut," #bf{V+jets}","f");
    legend_ptLL_precut -> AddEntry (hist_ptLL_tt_precut," #bf{t#bar{t}}","f");
    legend_ptLL_precut -> AddEntry (hist_ptLL_t_precut," #bf{Single top}","f");
    legend_ptLL_precut -> AddEntry (hist_ptLL_Higgs_norm," #bf{Higgs_{norm}}","l");
    legend_ptLL_precut -> SetBorderSize(0);

    auto legend_dPhiLL_precut = new TLegend (0.55, 0.50, 0.66, 0.85);
    legend_dPhiLL_precut -> AddEntry (hist_dPhiLL_Data_precut," #bf{Data}","lep");
    legend_dPhiLL_precut -> AddEntry (hist_dPhiLL_Higgs_precut," #bf{Higgs}","f");
    legend_dPhiLL_precut -> AddEntry (hist_dPhiLL_Diboson_precut," #bf{Diboson}","f");
    legend_dPhiLL_precut -> AddEntry (hist_dPhiLL_Vjets_precut," #bf{V+jets}","f");
    legend_dPhiLL_precut -> AddEntry (hist_dPhiLL_tt_precut," #bf{t#bar{t}}","f");
    legend_dPhiLL_precut -> AddEntry (hist_dPhiLL_t_precut," #bf{Single top}","f");
    legend_dPhiLL_precut -> AddEntry (hist_dPhiLL_Higgs_norm," #bf{Higgs_{norm}}","l");
    legend_dPhiLL_precut -> SetBorderSize(0);

    auto legend_mt = new TLegend (0.79, 0.55, 0.90, 0.85);
    legend_mt -> AddEntry (hist_mt_Data," #bf{Data}","lep");
    legend_mt -> AddEntry (hist_mt_Higgs," #bf{Higgs}","f");
    legend_mt -> AddEntry (hist_mt_Diboson," #bf{Diboson}","f");
    legend_mt -> AddEntry (hist_mt_Vjets," #bf{V+jets}","f");
    legend_mt -> AddEntry (hist_mt_tt," #bf{t#bar{t}}","f");
    legend_mt -> AddEntry (hist_mt_t," #bf{Single top}","f");
    legend_mt -> SetBorderSize(0);

    auto legend_etmiss = new TLegend (0.79, 0.55, 0.90, 0.85);
    legend_etmiss -> AddEntry (hist_etmiss_Data," #bf{Data}","lep");
    legend_etmiss -> AddEntry (hist_etmiss_Higgs," #bf{Higgs}","f");
    legend_etmiss -> AddEntry (hist_etmiss_Diboson," #bf{Diboson}","f");
    legend_etmiss -> AddEntry (hist_etmiss_Vjets," #bf{V+jets}","f");
    legend_etmiss -> AddEntry (hist_etmiss_tt," #bf{t#bar{t}}","f");
    legend_etmiss -> AddEntry (hist_etmiss_t," #bf{Single top}","f");
    legend_etmiss -> SetBorderSize(0);

    auto legend_ptLL = new TLegend (0.79, 0.55, 0.90, 0.85);
    legend_ptLL -> AddEntry (hist_ptLL_Data," #bf{Data}","lep");
    legend_ptLL -> AddEntry (hist_ptLL_Higgs," #bf{Higgs}","f");
    legend_ptLL -> AddEntry (hist_ptLL_Diboson," #bf{Diboson}","f");
    legend_ptLL -> AddEntry (hist_ptLL_Vjets," #bf{V+jets}","f");
    legend_ptLL -> AddEntry (hist_ptLL_tt," #bf{t#bar{t}}","f");
    legend_ptLL -> AddEntry (hist_ptLL_t," #bf{Single top}","f");
    legend_ptLL -> SetBorderSize(0);

    auto legend_dPhiLL = new TLegend (0.79, 0.55, 0.90, 0.85);
    legend_dPhiLL -> AddEntry (hist_dPhiLL_Data," #bf{Data}","lep");
    legend_dPhiLL -> AddEntry (hist_dPhiLL_Higgs," #bf{Higgs}","f");
    legend_dPhiLL -> AddEntry (hist_dPhiLL_Diboson," #bf{Diboson}","f");
    legend_dPhiLL -> AddEntry (hist_dPhiLL_Vjets," #bf{V+jets}","f");
    legend_dPhiLL -> AddEntry (hist_dPhiLL_tt," #bf{t#bar{t}}","f");
    legend_dPhiLL -> AddEntry (hist_dPhiLL_t," #bf{Single top}","f");
    legend_dPhiLL -> SetBorderSize(0);


  // TITLE #sqrt{13} = TeV, 10 fb^{-1} Y H -> WW* -> e#mu + #mu e

    auto *pt_s = new TLegend ( 0.15, 0.80, 0.70, 0.85 );
    pt_s -> SetHeader ( "#bf{#sqrt{s} = 13 TeV, 10 fb^{-1}}" );
    pt_s -> SetBorderSize(0);

    auto *pt_HWW = new TLegend ( 0.15, 0.75, 0.70, 0.80 );
    pt_HWW -> SetHeader ( "#bf{H #rightarrow WW* #rightarrow e#nu #mu#nu, N_{jet} #leq 1}" );
    pt_HWW -> SetBorderSize(0);

    auto *pt_s_dPhiLL_precut = new TLegend ( 0.15, 0.80, 0.50, 0.85 );
    pt_s_dPhiLL_precut -> SetHeader ( "#bf{#sqrt{s} = 13 TeV, 10 fb^{-1}}" );
    pt_s_dPhiLL_precut -> SetBorderSize(0);

    auto *pt_HWW_dPhiLL_precut = new TLegend ( 0.15, 0.75, 0.50, 0.80 );
    pt_HWW_dPhiLL_precut -> SetHeader ( "#bf{H #rightarrow WW* #rightarrow e#nu #mu#nu, N_{jet} #leq 1}" );
    pt_HWW_dPhiLL_precut -> SetBorderSize(0);


  // RATIO PLOT LINES

    TLine *line = new TLine ( 0, 1, 200, 1 );
    line -> SetLineColor (kRed);

    TLine *line_mt = new TLine ( 50, 1, 200, 1 );
    line_mt -> SetLineColor (kRed);

    TLine *line_dPhiLL = new TLine ( 0, 1, 3.2, 1 );
    line_dPhiLL -> SetLineColor (kRed);


  // DRAW HISTOGRAMS

    // TRANSVERSE MASS

        TCanvas *cs_mt = new TCanvas("cs_mt","cs_mt",10,10,900,600);
        TPad *pad1_mt = new TPad("pad1_mt", "pad1_mt", 0, 0.27, 1, 1);
        THStack *hs_mt = new THStack ("hs_mt","Dilepton System Transverse Mass; m_{T} [GeV]; Events / bin");

        pad1_mt -> SetTopMargin (0.1);
        pad1_mt -> SetBottomMargin (0);
        pad1_mt -> SetLeftMargin (0.1);

        hs_mt -> Add (hist_mt_t);
        hs_mt -> Add (hist_mt_tt);
        hs_mt -> Add (hist_mt_Vjets);   
        hs_mt -> Add (hist_mt_Diboson);
        hs_mt -> Add (hist_mt_Higgs);

        pad1_mt -> Draw ();
        pad1_mt -> cd ();
        hs_mt -> Draw ("histo");
        hist_mt_Data -> DrawCopy ("e,same");
        legend_mt -> Draw ();
        pt_s -> Draw ();
        pt_HWW -> Draw ();

        hs_mt -> SetMinimum (0.01);
        hs_mt -> SetMaximum (425);
        hs_mt -> GetYaxis () -> SetMaxDigits (3);
        hs_mt -> GetYaxis () -> SetTitleOffset (0.75);

        cs_mt -> cd ();

        TPad *pad2_mt = new TPad("pad2_mt", "pad2_mt", 0, 0, 1, 0.27);
        pad2_mt -> SetTopMargin (0);
        pad2_mt -> SetBottomMargin (0.40);
        pad2_mt -> SetLeftMargin (0.1);

        pad2_mt -> Draw ();
        pad2_mt -> cd ();
        hist_mt_Data -> Sumw2 ();
        hist_mt_Data -> SetStats (0);
        hist_mt_Data -> Divide (hist_mt);
        hist_mt_Data -> Draw ("e1,p");
        line_mt -> Draw ();

        hist_mt_Data -> SetMaximum (1.99);
        hist_mt_Data -> SetMinimum (0.01);
        hist_mt_Data -> GetYaxis () -> SetNdivisions (4, 1, 0, kTRUE);

        cs_mt -> cd ();


    // ETMISS

        TCanvas *cs_etmiss = new TCanvas("cs_etmiss","cs_etmiss",10,10,900,600);
        TPad *pad1_etmiss = new TPad("pad1_etmiss", "pad1_etmiss", 0, 0.27, 1, 1);
        THStack *hs_etmiss = new THStack ("hs_etmiss","Dilepton System Transverse Mass; m_{T} [GeV]; Events / bin");

        pad1_etmiss -> SetTopMargin (0.1);
        pad1_etmiss -> SetBottomMargin (0);
        pad1_etmiss -> SetLeftMargin (0.1);

        hs_etmiss -> Add (hist_etmiss_t);
        hs_etmiss -> Add (hist_etmiss_tt);
        hs_etmiss -> Add (hist_etmiss_Vjets);   
        hs_etmiss -> Add (hist_etmiss_Diboson);
        hs_etmiss -> Add (hist_etmiss_Higgs);

        pad1_etmiss -> Draw ();
        pad1_etmiss -> cd ();
        hs_etmiss -> Draw ("histo");
        hist_etmiss_Data -> DrawCopy ("e,same");
        legend_etmiss -> Draw ();
        pt_s -> Draw ();
        pt_HWW -> Draw ();

        hs_etmiss -> SetMinimum (0.01);
        hs_etmiss -> SetMaximum (575);
        hs_etmiss -> GetYaxis () -> SetMaxDigits (3);
        hs_etmiss -> GetYaxis () -> SetTitleOffset (0.75);

        cs_etmiss -> cd ();

        TPad *pad2_etmiss = new TPad("pad2_etmiss", "pad2_etmiss", 0, 0, 1, 0.27);
        pad2_etmiss -> SetTopMargin (0);
        pad2_etmiss -> SetBottomMargin (0.40);
        pad2_etmiss -> SetLeftMargin (0.1);

        pad2_etmiss -> Draw ();
        pad2_etmiss -> cd ();
        hist_etmiss_Data -> Sumw2 ();
        hist_etmiss_Data -> SetStats (0);
        hist_etmiss_Data -> Divide (hist_etmiss);
        hist_etmiss_Data -> Draw ("e,p");
        line -> Draw ();

        hist_etmiss_Data -> SetMaximum (1.99);
        hist_etmiss_Data -> SetMinimum (0.01);
        hist_etmiss_Data -> GetYaxis () -> SetNdivisions (4, 1, 0, kTRUE);

        cs_etmiss -> cd ();


    // DILEPTON TRANSVERSE MOMENTUM

        TCanvas *cs_ptLL = new TCanvas("cs_ptLL","cs_ptLL",10,10,900,600);
        TPad *pad1_ptLL = new TPad("pad1_ptLL", "pad1_ptLL", 0, 0.27, 1, 1);
        THStack *hs_ptLL = new THStack ("hs_ptLL","Transverse Momentum of Dilepton System; p_{T}^{ll} [GeV]; Events / bin");

        pad1_ptLL -> SetTopMargin (0.1);
        pad1_ptLL -> SetBottomMargin (0);
        pad1_ptLL -> SetLeftMargin (0.1);

        hs_ptLL -> Add (hist_ptLL_t);
        hs_ptLL -> Add (hist_ptLL_tt);
        hs_ptLL -> Add (hist_ptLL_Vjets);   
        hs_ptLL -> Add (hist_ptLL_Diboson);
        hs_ptLL -> Add (hist_ptLL_Higgs);

        pad1_ptLL -> Draw ();
        pad1_ptLL -> cd ();
        hs_ptLL -> Draw ("histo");
        hist_ptLL_Data -> DrawCopy ("e,same");
        legend_ptLL -> Draw ();
        pt_s -> Draw ();
        pt_HWW -> Draw ();

        hs_ptLL -> SetMinimum (0.01);
        hs_ptLL -> SetMaximum (475);
        hs_ptLL -> GetYaxis () -> SetMaxDigits (3);
        hs_ptLL -> GetYaxis () -> SetTitleOffset (0.75);

        cs_ptLL -> cd ();

        TPad *pad2_ptLL = new TPad("pad2_ptLL", "pad2_ptLL", 0, 0, 1, 0.27);
        pad2_ptLL -> SetTopMargin (0);
        pad2_ptLL -> SetBottomMargin (0.40);
        pad2_ptLL -> SetLeftMargin (0.1);

        pad2_ptLL -> Draw ();
        pad2_ptLL -> cd ();
        hist_ptLL_Data -> Sumw2 ();
        hist_ptLL_Data -> SetStats (0);
        hist_ptLL_Data -> Divide (hist_ptLL);
        hist_ptLL_Data -> Draw ("e,p");
        line -> Draw ();

        hist_ptLL_Data -> SetMaximum (1.99);
        hist_ptLL_Data -> SetMinimum (0.01);
        hist_ptLL_Data -> GetYaxis () -> SetNdivisions (4, 1, 0, kTRUE);

        cs_ptLL -> cd ();


    // DILEPTON ANGLE

        TCanvas *cs_dPhiLL = new TCanvas("cs_dPhiLL","cs_dPhiLL",10,10,900,600);
        TPad *pad1_dPhiLL = new TPad("pad1_dPhiLL", "pad1_dPhiLL", 0, 0.27, 1, 1);
        THStack *hs_dPhiLL = new THStack ("hs_dPhiLL","dPhi_LL Dilepton System; #Delta#phi (ll); Events / bin");

        pad1_dPhiLL -> SetTopMargin (0.1);
        pad1_dPhiLL -> SetBottomMargin (0);
        pad1_dPhiLL -> SetLeftMargin (0.1);

        hs_dPhiLL -> Add (hist_dPhiLL_t);
        hs_dPhiLL -> Add (hist_dPhiLL_tt);
        hs_dPhiLL -> Add (hist_dPhiLL_Vjets);   
        hs_dPhiLL -> Add (hist_dPhiLL_Diboson);
        hs_dPhiLL -> Add (hist_dPhiLL_Higgs);

        pad1_dPhiLL -> Draw ();
        pad1_dPhiLL -> cd ();
        hs_dPhiLL -> Draw ("histo");
        hist_dPhiLL_Data -> DrawCopy ("e,same");
        legend_dPhiLL -> Draw ();
        pt_s -> Draw ();
        pt_HWW -> Draw ();

        hs_dPhiLL -> SetMinimum (0.01);
        hs_dPhiLL -> SetMaximum (375);
        hs_dPhiLL -> GetYaxis () -> SetMaxDigits (3);
        hs_dPhiLL -> GetYaxis () -> SetTitleOffset (0.75);

        cs_dPhiLL -> cd ();

        TPad *pad2_dPhiLL = new TPad("pad2_dPhiLL", "pad2_dPhiLL", 0, 0, 1, 0.27);
        pad2_dPhiLL -> SetTopMargin (0);
        pad2_dPhiLL -> SetBottomMargin (0.40);
        pad2_dPhiLL -> SetLeftMargin (0.1);

        pad2_dPhiLL -> Draw ();
        pad2_dPhiLL -> cd ();
        hist_dPhiLL_Data -> Sumw2 ();
        hist_dPhiLL_Data -> SetStats (0);
        hist_dPhiLL_Data -> Divide (hist_dPhiLL);
        hist_dPhiLL_Data -> Draw ("e,p");
        line_dPhiLL -> Draw ();

        hist_dPhiLL_Data -> SetMaximum (1.99);
        hist_dPhiLL_Data -> SetMinimum (0.01);
        hist_dPhiLL_Data -> GetYaxis () -> SetNdivisions (4, 1, 0, kTRUE);

        cs_dPhiLL -> cd ();


    // TRANSVERSE MASS PRE-CUT

        TCanvas *cs_mt_precut = new TCanvas("cs_mt_precut","cs_mt_precut",10,10,900,600);
        TPad *pad1_mt_precut = new TPad("pad1_mt_precut", "pad1_mt_precut", 0, 0.27, 1, 1);
        THStack *hs_mt_precut = new THStack ("hs_mt_precut","Dilepton System Transverse Mass; m_{T} [GeV]; Events / bin");

        pad1_mt_precut -> SetTopMargin (0.1);
        pad1_mt_precut -> SetBottomMargin (0);
        pad1_mt_precut -> SetLeftMargin (0.1);

        hs_mt_precut -> Add (hist_mt_t_precut);
        hs_mt_precut -> Add (hist_mt_tt_precut);
        hs_mt_precut -> Add (hist_mt_Vjets_precut);   
        hs_mt_precut -> Add (hist_mt_Diboson_precut);
        hs_mt_precut -> Add (hist_mt_Higgs_precut);

        pad1_mt_precut -> Draw ();
        pad1_mt_precut -> cd ();
        hs_mt_precut -> Draw ("histo");
        hist_mt_Higgs_norm -> Draw ("hist,same");
        hist_mt_Data_precut -> DrawCopy ("e,same");
        legend_mt_precut -> Draw ();
        pt_s -> Draw ();
        pt_HWW -> Draw ();

        hs_mt_precut -> SetMinimum (0.01);
        hs_mt_precut -> SetMaximum (19000);
        hs_mt_precut -> GetYaxis () -> SetMaxDigits (3);
        hs_mt_precut -> GetYaxis () -> SetTitleOffset (0.75);

        cs_mt_precut -> cd ();

        TPad *pad2_mt_precut = new TPad("pad2_mt_precut", "pad2_mt_precut", 0, 0, 1, 0.27);
        pad2_mt_precut -> SetTopMargin (0);
        pad2_mt_precut -> SetBottomMargin (0.40);
        pad2_mt_precut -> SetLeftMargin (0.1);

        pad2_mt_precut -> Draw ();
        pad2_mt_precut -> cd ();
        hist_mt_Data_precut -> Sumw2 ();
        hist_mt_Data_precut -> SetStats (0);
        hist_mt_Data_precut -> Divide (hist_mt_precut);
        hist_mt_Data_precut -> Draw ("e,p");
        line_mt -> Draw ();

        hist_mt_Data_precut -> SetMaximum (1.99);
        hist_mt_Data_precut -> SetMinimum (0.01);
        hist_mt_Data_precut -> GetYaxis () -> SetNdivisions (4, 1, 0, kTRUE);

        cs_mt_precut -> cd ();


    // ETMISS PRE-CUT

        TCanvas *cs_etmiss_precut = new TCanvas("cs_etmiss_precut","cs_etmiss_precut",10,10,900,600);
        TPad *pad1_etmiss_precut = new TPad("pad1_etmiss_precut", "pad1_etmiss_precut", 0, 0.27, 1, 1);
        THStack *hs_etmiss_precut = new THStack ("hs_etmiss_precut","Dilepton System Transverse Mass; m_{T} [GeV]; Events / bin");

        pad1_etmiss_precut -> SetTopMargin (0.1);
        pad1_etmiss_precut -> SetBottomMargin (0);
        pad1_etmiss_precut -> SetLeftMargin (0.1);

        hs_etmiss_precut -> Add (hist_etmiss_t_precut);
        hs_etmiss_precut -> Add (hist_etmiss_tt_precut);
        hs_etmiss_precut -> Add (hist_etmiss_Vjets_precut);   
        hs_etmiss_precut -> Add (hist_etmiss_Diboson_precut);
        hs_etmiss_precut -> Add (hist_etmiss_Higgs_precut);

        pad1_etmiss_precut -> Draw ();
        pad1_etmiss_precut -> cd ();
        hs_etmiss_precut -> Draw ("histo");
        hist_etmiss_Higgs_norm -> Draw ("hist,same");
        hist_etmiss_Data_precut -> DrawCopy ("e,same");
        legend_etmiss_precut -> Draw ();
        pt_s -> Draw ();
        pt_HWW -> Draw ();

        hs_etmiss_precut -> SetMinimum (0.01);
        hs_etmiss_precut -> SetMaximum (28000);
        hs_etmiss_precut -> GetYaxis () -> SetMaxDigits (3);
        hs_etmiss_precut -> GetYaxis () -> SetTitleOffset (0.75);

        cs_etmiss_precut -> cd ();

        TPad *pad2_etmiss_precut = new TPad("pad2_etmiss_precut", "pad2_etmiss_precut", 0, 0, 1, 0.27);
        pad2_etmiss_precut -> SetTopMargin (0);
        pad2_etmiss_precut -> SetBottomMargin (0.40);
        pad2_etmiss_precut -> SetLeftMargin (0.1);

        pad2_etmiss_precut -> Draw ();
        pad2_etmiss_precut -> cd ();
        hist_etmiss_Data_precut -> Sumw2 ();
        hist_etmiss_Data_precut -> SetStats (0);
        hist_etmiss_Data_precut -> Divide (hist_etmiss_precut);
        hist_etmiss_Data_precut -> Draw ("e,p");
        line -> Draw ();

        hist_etmiss_Data_precut -> SetMaximum (1.99);
        hist_etmiss_Data_precut -> SetMinimum (0.01);
        hist_etmiss_Data_precut -> GetYaxis () -> SetNdivisions (4, 1, 0, kTRUE);

        cs_etmiss_precut -> cd ();


    // DILEPTON TRANSVERSE MOMENTUM PRE-CUT

        TCanvas *cs_ptLL_precut = new TCanvas("cs_ptLL_precut","cs_ptLL_precut",10,10,900,600);
        TPad *pad1_ptLL_precut = new TPad("pad1_ptLL_precut", "pad1_ptLL_precut", 0, 0.27, 1, 1);
        THStack *hs_ptLL_precut = new THStack ("hs_ptLL_precut","Transverse Momentum of Dilepton System; p_{T}^{ll} [GeV]; Events / bin");

        pad1_ptLL_precut -> SetTopMargin (0.1);
        pad1_ptLL_precut -> SetBottomMargin (0);
        pad1_ptLL_precut -> SetLeftMargin (0.1);

        hs_ptLL_precut -> Add (hist_ptLL_t_precut);
        hs_ptLL_precut -> Add (hist_ptLL_tt_precut);
        hs_ptLL_precut -> Add (hist_ptLL_Vjets_precut);   
        hs_ptLL_precut -> Add (hist_ptLL_Diboson_precut);
        hs_ptLL_precut -> Add (hist_ptLL_Higgs_precut);

        pad1_ptLL_precut -> Draw ();
        pad1_ptLL_precut -> cd ();
        hs_ptLL_precut -> Draw ("histo");
        hist_ptLL_Higgs_norm -> Draw ("hist,same");
        hist_ptLL_Data_precut -> DrawCopy ("e,same");
        legend_ptLL_precut -> Draw ();
        pt_s -> Draw ();
        pt_HWW -> Draw ();

        hs_ptLL_precut -> SetMinimum (0.01);
        hs_ptLL_precut -> SetMaximum (21000);
        hs_ptLL_precut -> GetYaxis () -> SetMaxDigits (3);
        hs_ptLL_precut -> GetYaxis () -> SetTitleOffset (0.75);

        cs_ptLL_precut -> cd ();

        TPad *pad2_ptLL_precut = new TPad("pad2_ptLL_precut", "pad2_ptLL_precut", 0, 0, 1, 0.27);
        pad2_ptLL_precut -> SetTopMargin (0);
        pad2_ptLL_precut -> SetBottomMargin (0.40);
        pad2_ptLL_precut -> SetLeftMargin (0.1);

        pad2_ptLL_precut -> Draw ();
        pad2_ptLL_precut -> cd ();
        hist_ptLL_Data_precut -> Sumw2 ();
        hist_ptLL_Data_precut -> SetStats (0);
        hist_ptLL_Data_precut -> Divide (hist_ptLL_precut);
        hist_ptLL_Data_precut -> Draw ("e,p");
        line -> Draw ();

        hist_ptLL_Data_precut -> SetMaximum (1.99);
        hist_ptLL_Data_precut -> SetMinimum (0.01);
        hist_ptLL_Data_precut -> GetYaxis () -> SetNdivisions (4, 1, 0, kTRUE);

        cs_ptLL_precut -> cd ();


    // DILEPTON ANGLE PRE-CUT

        TCanvas *cs_dPhiLL_precut = new TCanvas("cs_dPhiLL_precut","cs_dPhiLL_precut",10,10,900,600);
        TPad *pad1_dPhiLL_precut = new TPad("pad1_dPhiLL_precut", "pad1_dPhiLL_precut", 0, 0.27, 1, 1);
        THStack *hs_dPhiLL_precut = new THStack ("hs_dPhiLL_precut","dPhi_LL Dilepton System; #Delta#phi (ll); Events / bin");

        pad1_dPhiLL_precut -> SetTopMargin (0.1);
        pad1_dPhiLL_precut -> SetBottomMargin (0);
        pad1_dPhiLL_precut -> SetLeftMargin (0.1);

        hs_dPhiLL_precut -> Add (hist_dPhiLL_t_precut);
        hs_dPhiLL_precut -> Add (hist_dPhiLL_tt_precut);
        hs_dPhiLL_precut -> Add (hist_dPhiLL_Vjets_precut);   
        hs_dPhiLL_precut -> Add (hist_dPhiLL_Diboson_precut);
        hs_dPhiLL_precut -> Add (hist_dPhiLL_Higgs_precut);

        pad1_dPhiLL_precut -> Draw ();
        pad1_dPhiLL_precut -> cd ();
        hs_dPhiLL_precut -> Draw ("histo");
        hist_dPhiLL_Higgs_norm -> Draw ("hist,same");
        hist_dPhiLL_Data_precut -> DrawCopy ("e,same");
        legend_dPhiLL_precut -> Draw ();
        pt_s_dPhiLL_precut -> Draw ();
        pt_HWW_dPhiLL_precut -> Draw ();


        hs_dPhiLL_precut -> SetMinimum (0.01);
        hs_dPhiLL_precut -> SetMaximum (16000);
        hs_dPhiLL_precut -> GetYaxis () -> SetMaxDigits (3);
        hs_dPhiLL_precut -> GetYaxis () -> SetTitleOffset (0.75);

        cs_dPhiLL_precut -> cd ();

        TPad *pad2_dPhiLL_precut = new TPad("pad2_dPhiLL_precut", "pad2_dPhiLL_precut", 0, 0, 1, 0.27);
        pad2_dPhiLL_precut -> SetTopMargin (0);
        pad2_dPhiLL_precut -> SetBottomMargin (0.40);
        pad2_dPhiLL_precut -> SetLeftMargin (0.1);

        pad2_dPhiLL_precut -> Draw ();
        pad2_dPhiLL_precut -> cd ();
        hist_dPhiLL_Data_precut -> Sumw2 ();
        hist_dPhiLL_Data_precut -> SetStats (0);
        hist_dPhiLL_Data_precut -> Divide (hist_dPhiLL_precut);
        hist_dPhiLL_Data_precut -> Draw ("e,p");
        line_dPhiLL -> Draw ();

        hist_dPhiLL_Data_precut -> SetMaximum (1.99);
        hist_dPhiLL_Data_precut -> SetMinimum (0.01);
        hist_dPhiLL_Data_precut -> GetYaxis () -> SetNdivisions (4, 1, 0, kTRUE);

        cs_dPhiLL_precut -> cd ();


  // SAVE CANVAS

    std::cout << " " << std::endl;

    cs_mt -> SaveAs ("HWW_mt.png");
    cs_etmiss -> SaveAs ("HWW_etmiss.png");
    cs_ptLL -> SaveAs ("HWW_ptLL.png");
    cs_dPhiLL -> SaveAs ("HWW_dPhiLL.png");

    cs_mt_precut -> SaveAs ("HWW_mt_precut.png");
    cs_etmiss_precut -> SaveAs ("HWW_etmiss_precut.png");
    cs_ptLL_precut -> SaveAs ("HWW_ptLL_precut.png");
    cs_dPhiLL_precut -> SaveAs ("HWW_dPhiLL_precut.png");


  t1 = clock ();

  float time = ( float (t1 - t0) / CLOCKS_PER_SEC ) / 60;        // Execution time in minutes

  std::cout << " " << std::endl;
  std::cout << "Execution time: " << time << " minutes." << std::endl;


  return;

}
