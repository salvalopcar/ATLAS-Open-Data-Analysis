//=============================================================//
//                                                             //
//                                                             //
//              Análisis del proceso H -> Z Z*                 //
//                                                             //
//                                                             //
//=============================================================//
  

#include <iostream>
#include <TChain.h>
#include <vector>
#include <TFile.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <TMath.h>
#include <TLorentzVector.h>
#include <ctime>


void HZZ_Analisis () {

  unsigned t0, t1;          // Medir el tiempo de ejecución

  t0 = clock ();


  // DECLARAR HISTOGRAMAS

    TH1F *hist_pt = new TH1F("hist_pt", "Leptons Transverse Momentum; p_{T}^{all lep} [GeV]; Leptons / bin", 5, 0, 200);

    TH1F *hist_eta = new TH1F("hist_eta", "Leptons Pseudorapidity; #eta^{all lep}; Leptons / bin", 10, -3, 3);

    TH1F *hist_E = new TH1F("hist_E", "Leptons Energy; E^{all lep} [GeV]; Leptons / bin", 10, 0, 300);

    TH1F *hist_phi = new TH1F("hist_phi", "Leptons Azimuthal Angle; #phi^{all lep}; Leptons / bin", 8, -3.2, 3.2);

    TH1F *hist_mLL1 = new TH1F("hist_mLL1", "Mass of Dilepton System; m_{ll,1} [GeV]; Events / bin", 30, 50, 106);

    TH1F *hist_mLL2 = new TH1F("hist_mLL2", "Mass of Dilepton System; m_{ll,2} [GeV]; Events / bin", 30, 12, 140);

    TH1F *hist_Njets = new TH1F("hist_Njets", "Number of Jets; N_{jets}; Events", 4, -0.5, 3.5);

    TH1F *hist_mass = new TH1F("hist_mass", "Mass of four-lepton system; m_{4l} [GeV]; Events / bin", 24, 80, 170);

    // DATA

        TH1F *hist_pt_Data = new TH1F("hist_pt_Data", "Leptons Transverse Momentum; p_{T}^{all lep} [GeV]; Data / Pred", 5, 0, 200);
        hist_pt_Data -> SetLineColor(kBlack);
        hist_pt_Data -> GetXaxis () -> SetLabelSize (0.13);
        hist_pt_Data -> GetXaxis () -> SetTitleSize (0.14);
        hist_pt_Data -> GetXaxis () -> SetTitleOffset (0.85);
        hist_pt_Data -> GetYaxis () -> SetLabelSize (0.13);
        hist_pt_Data -> GetYaxis () -> SetTitleSize (0.13);
        hist_pt_Data -> GetYaxis () -> SetTitleOffset (0.27);

        TH1F *hist_eta_Data = new TH1F("hist_eta_Data", "Leptons Pseudorapidity; #eta^{all lep}; Data / Pred", 10, -3, 3);
        hist_eta_Data -> SetLineColor(kBlack);
        hist_eta_Data -> GetXaxis () -> SetLabelSize (0.13);
        hist_eta_Data -> GetXaxis () -> SetTitleSize (0.14);
        hist_eta_Data -> GetXaxis () -> SetTitleOffset (0.85);
        hist_eta_Data -> GetYaxis () -> SetLabelSize (0.13);
        hist_eta_Data -> GetYaxis () -> SetTitleSize (0.13);
        hist_eta_Data -> GetYaxis () -> SetTitleOffset (0.27);

        TH1F *hist_E_Data = new TH1F("hist_E_Data", "Leptons Energy; E^{all lep} [GeV]; Data / Pred", 10, 0, 300);
        hist_E_Data -> SetLineColor(kBlack);
        hist_E_Data -> GetXaxis () -> SetLabelSize (0.13);
        hist_E_Data -> GetXaxis () -> SetTitleSize (0.14);
        hist_E_Data -> GetXaxis () -> SetTitleOffset (0.85);
        hist_E_Data -> GetYaxis () -> SetLabelSize (0.13);
        hist_E_Data -> GetYaxis () -> SetTitleSize (0.13);
        hist_E_Data -> GetYaxis () -> SetTitleOffset (0.27);

        TH1F *hist_phi_Data = new TH1F("hist_phi_Data", "Leptons Azimuthal Angle; #phi^{all lep}; Data / Pred", 8, -3.2, 3.2);
        hist_phi_Data -> SetLineColor(kBlack);
        hist_phi_Data -> GetXaxis () -> SetLabelSize (0.13);
        hist_phi_Data -> GetXaxis () -> SetTitleSize (0.14);
        hist_phi_Data -> GetXaxis () -> SetTitleOffset (0.85);
        hist_phi_Data -> GetYaxis () -> SetLabelSize (0.13);
        hist_phi_Data -> GetYaxis () -> SetTitleSize (0.13);
        hist_phi_Data -> GetYaxis () -> SetTitleOffset (0.27);

        TH1F *hist_mLL1_Data = new TH1F("hist_mLL1_Data", "Mass of Dilepton System; m_{ll,1} [GeV]; Data / Pred", 30, 50, 106);
        hist_mLL1_Data -> SetLineColor(kBlack);
        hist_mLL1_Data -> GetXaxis () -> SetLabelSize (0.13);
        hist_mLL1_Data -> GetXaxis () -> SetTitleSize (0.14);
        hist_mLL1_Data -> GetXaxis () -> SetTitleOffset (0.85);
        hist_mLL1_Data -> GetYaxis () -> SetLabelSize (0.13);
        hist_mLL1_Data -> GetYaxis () -> SetTitleSize (0.13);
        hist_mLL1_Data -> GetYaxis () -> SetTitleOffset (0.27);

        TH1F *hist_mLL2_Data = new TH1F("hist_mLL2_Data", "Mass of Dilepton System; m_{ll,2} [GeV]; Data / Pred", 30, 12, 140);
        hist_mLL2_Data -> SetLineColor(kBlack);
        hist_mLL2_Data -> GetXaxis () -> SetLabelSize (0.13);
        hist_mLL2_Data -> GetXaxis () -> SetTitleSize (0.14);
        hist_mLL2_Data -> GetXaxis () -> SetTitleOffset (0.85);
        hist_mLL2_Data -> GetYaxis () -> SetLabelSize (0.13);
        hist_mLL2_Data -> GetYaxis () -> SetTitleSize (0.13);
        hist_mLL2_Data -> GetYaxis () -> SetTitleOffset (0.27);

        TH1F *hist_Njets_Data = new TH1F("hist_Njets_Data", "Number of Jets; N_{jets}; Data / Pred", 4, -0.5, 3.5);
        hist_Njets_Data -> SetLineColor(kBlack);
        hist_Njets_Data -> GetXaxis () -> SetLabelSize (0.13);
        hist_Njets_Data -> GetXaxis () -> SetTitleSize (0.14);
        hist_Njets_Data -> GetXaxis () -> SetTitleOffset (0.85);
        hist_Njets_Data -> GetYaxis () -> SetLabelSize (0.13);
        hist_Njets_Data -> GetYaxis () -> SetTitleSize (0.13);
        hist_Njets_Data -> GetYaxis () -> SetTitleOffset (0.27);

        TH1F *hist_mass_Data = new TH1F("hist_mass_Data", "Mass of four-lepton system; m_{4l} [GeV]; Data / Pred", 24, 80, 170);
        hist_mass_Data -> SetLineColor(kBlack);
        hist_mass_Data -> GetXaxis () -> SetLabelSize (0.13);
        hist_mass_Data -> GetXaxis () -> SetTitleSize (0.14);
        hist_mass_Data -> GetXaxis () -> SetTitleOffset (0.85);
        hist_mass_Data -> GetYaxis () -> SetLabelSize (0.13);
        hist_mass_Data -> GetYaxis () -> SetTitleSize (0.13);
        hist_mass_Data -> GetYaxis () -> SetTitleOffset (0.27);


    // HIGGS

        TH1F *hist_pt_Higgs = new TH1F("hist_pt_Higgs", "Leptons Transverse Momentum; p_{T}^{all lep} [GeV]; Leptons / bin", 5, 0, 200);
        hist_pt_Higgs -> SetLineColor(kRed);
        hist_pt_Higgs -> SetFillColor(kRed);

        TH1F *hist_eta_Higgs = new TH1F("hist_eta_Higgs", "Leptons Pseudorapidity; #eta^{all lep}; Leptons / bin", 10, -3, 3);
        hist_eta_Higgs -> SetLineColor(kRed);
        hist_eta_Higgs -> SetFillColor(kRed);

        TH1F *hist_E_Higgs = new TH1F("hist_E_Higgs", "Leptons Energy; E^{all lep} [GeV]; Leptons / bin", 10, 0, 300);
        hist_E_Higgs -> SetLineColor(kRed);
        hist_E_Higgs -> SetFillColor(kRed);

        TH1F *hist_phi_Higgs = new TH1F("hist_phi_Higgs", "Leptons Azimuthal Angle; #phi^{all lep}; Leptons / bin", 8, -3.2, 3.2);
        hist_phi_Higgs -> SetLineColor(kRed);
        hist_phi_Higgs -> SetFillColor(kRed);

        TH1F *hist_mLL1_Higgs = new TH1F("hist_mLL1_Higgs", "Mass of Dilepton System; m_{ll,1} [GeV]; Events / bin", 30, 50, 106);
        hist_mLL1_Higgs -> SetLineColor(kRed);
        hist_mLL1_Higgs -> SetFillColor(kRed);

        TH1F *hist_mLL2_Higgs = new TH1F("hist_mLL2_Higgs", "Mass of Dilepton System; m_{ll,2} [GeV]; Events / bin", 30, 12, 140);
        hist_mLL2_Higgs -> SetLineColor(kRed);
        hist_mLL2_Higgs -> SetFillColor(kRed);

        TH1F *hist_Njets_Higgs = new TH1F("hist_Njets_Higgs", "Number of Jets; N_{jets}; Events", 4, -0.5, 3.5);
        hist_Njets_Higgs -> SetLineColor(kRed);
        hist_Njets_Higgs -> SetFillColor(kRed);

        TH1F *hist_mass_Higgs = new TH1F("hist_mass_Higgs", "Mass of four-lepton system; m_{4l} [GeV]; Events / bin", 24, 80, 170);
        hist_mass_Higgs -> SetLineColor(kRed);
        hist_mass_Higgs -> SetFillColor(kRed);


    // ZZ

        TH1F *hist_pt_ZZ = new TH1F("hist_pt_ZZ", "Leptons Transverse Momentum; p_{T}^{all lep} [GeV]; Leptons / bin", 5, 0, 200);
        hist_pt_ZZ -> SetLineColor(kCyan);
        hist_pt_ZZ -> SetFillColor(kCyan);

        TH1F *hist_eta_ZZ = new TH1F("hist_eta_ZZ", "Leptons Pseudorapidity; #eta^{all lep}; Leptons / bin", 10, -3, 3);
        hist_eta_ZZ -> SetLineColor(kCyan);
        hist_eta_ZZ -> SetFillColor(kCyan);

        TH1F *hist_E_ZZ = new TH1F("hist_E_ZZ", "Leptons Energy; E^{all lep} [GeV]; Leptons / bin", 10, 0, 300);
        hist_E_ZZ -> SetLineColor(kCyan);
        hist_E_ZZ -> SetFillColor(kCyan);

        TH1F *hist_phi_ZZ = new TH1F("hist_phi_ZZ", "Leptons Azimuthal Angle; #phi^{all lep}; Leptons / bin", 8, -3.2, 3.2);
        hist_phi_ZZ -> SetLineColor(kCyan);
        hist_phi_ZZ -> SetFillColor(kCyan);

        TH1F *hist_mLL1_ZZ = new TH1F("hist_mLL1_ZZ", "Mass of Dilepton System; m_{ll,1} [GeV]; Events / bin", 30, 50, 106);
        hist_mLL1_ZZ -> SetLineColor(kCyan);
        hist_mLL1_ZZ -> SetFillColor(kCyan);

        TH1F *hist_mLL2_ZZ = new TH1F("hist_mLL2_ZZ", "Mass of Dilepton System; m_{ll,2} [GeV]; Events / bin", 30, 12, 140);
        hist_mLL2_ZZ -> SetLineColor(kCyan);
        hist_mLL2_ZZ -> SetFillColor(kCyan);

        TH1F *hist_Njets_ZZ = new TH1F("hist_Njets_ZZ", "Number of Jets; N_{jets}; Events", 4, -0.5, 3.5);
        hist_Njets_ZZ -> SetLineColor(kCyan);
        hist_Njets_ZZ -> SetFillColor(kCyan);

        TH1F *hist_mass_ZZ = new TH1F("hist_mass_ZZ", "Mass of four-lepton system; m_{4l} [GeV]; Events / bin", 24, 80, 170);
        hist_mass_ZZ -> SetLineColor(kCyan);
        hist_mass_ZZ -> SetFillColor(kCyan);


    // OTHER

        TH1F *hist_pt_Other = new TH1F("hist_pt_Other", "Leptons Transverse Momentum; p_{T}^{all lep} [GeV]; Leptons / bin", 5, 0, 200);
        hist_pt_Other -> SetLineColor(kViolet);
        hist_pt_Other -> SetFillColor(kViolet);

        TH1F *hist_eta_Other = new TH1F("hist_eta_Other", "Leptons Pseudorapidity; #eta^{all lep}; Leptons / bin", 10, -3, 3);
        hist_eta_Other -> SetLineColor(kViolet);
        hist_eta_Other -> SetFillColor(kViolet);

        TH1F *hist_E_Other = new TH1F("hist_E_Other", "Leptons Energy; E^{all lep} [GeV]; Leptons / bin", 10, 0, 300);
        hist_E_Other -> SetLineColor(kViolet);
        hist_E_Other -> SetFillColor(kViolet);

        TH1F *hist_phi_Other = new TH1F("hist_phi_Other", "Leptons Azimuthal Angle; #phi^{all lep}; Leptons / bin", 8, -3.2, 3.2);
        hist_phi_Other -> SetLineColor(kViolet);
        hist_phi_Other -> SetFillColor(kViolet);

        TH1F *hist_mLL1_Other = new TH1F("hist_mLL1_Other", "Mass of Dilepton System; m_{ll,1} [GeV]; Events / bin", 30, 50, 106);
        hist_mLL1_Other -> SetLineColor(kViolet);
        hist_mLL1_Other -> SetFillColor(kViolet);

        TH1F *hist_mLL2_Other = new TH1F("hist_mLL2_Other", "Mass of Dilepton System; m_{ll,2} [GeV]; Events / bin", 30, 12, 140);
        hist_mLL2_Other -> SetLineColor(kViolet);
        hist_mLL2_Other -> SetFillColor(kViolet);

        TH1F *hist_Njets_Other = new TH1F("hist_Njets_Other", "Number of Jets; N_{jets}; Events", 4, -0.5, 3.5);
        hist_Njets_Other -> SetLineColor(kViolet);
        hist_Njets_Other -> SetFillColor(kViolet);

        TH1F *hist_mass_Other = new TH1F("hist_mass_Other", "Mass of four-lepton system; m_{4l} [GeV]; Events / bin", 24, 80, 170);
        hist_mass_Other -> SetLineColor(kViolet);
        hist_mass_Other -> SetFillColor(kViolet);


  // DEFINICIÓN DE UNA VARIABLE QUE INDICA EL TIPO DE CONTRIBUCIÓN
  // 0: Data, 1 - 4: Higgs, 5: Diboson ZZ, 6: Other

    int tipo = 0;


  // RUTA DE LOS ARCHIVOS DATA Y MC

    TString path = "/media/sf_TFG/Datos";


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  for ( tipo = 0; tipo < 7; tipo ++ )
  {

    TChain* fChain = new TChain("mini");


    // ABRIR DATOS

      // DATA

        if ( tipo == 0 )
        {

            fChain -> AddFile (path + "/4lep/Data/data_A.4lep.root"); 
            fChain -> AddFile (path + "/4lep/Data/data_B.4lep.root");
            fChain -> AddFile (path + "/4lep/Data/data_C.4lep.root");
            fChain -> AddFile (path + "/4lep/Data/data_D.4lep.root");

            std::cout << "Análisis para Data:" << std::endl;

        }


      // HIGGS

        if ( tipo == 1 )
        {

            fChain -> AddFile (path + "/4lep/MC/mc_345060.ggH125_ZZ4lep.4lep.root");        // ggF HIGGS

            std::cout << " " << std::endl;
            std::cout << "Análisis para ggF Higgs:" << std::endl;

        }

        if ( tipo == 2 )
        {

            fChain -> AddFile (path + "/4lep/MC/mc_344235.VBFH125_ZZ4lep.4lep.root");       // VBF HIGGS

            std::cout << " " << std::endl;
            std::cout << "Análisis para VBF Higgs:" << std::endl;

        }

        if ( tipo == 3 )
        {

            fChain -> AddFile (path + "/4lep/MC/mc_341947.ZH125_ZZ4lep.4lep.root");         // ZH HIGGS

            std::cout << " " << std::endl;
            std::cout << "Análisis para ZH Higgs:" << std::endl;

        }

        if ( tipo == 4 )
        {

            fChain -> AddFile (path + "/4lep/MC/mc_341964.WH125_ZZ4lep.4lep.root");         // WH Higgs

            std::cout << " " << std::endl;
            std::cout << "Análisis para WH Higgs:" << std::endl;

        }


      // ZZ

        if ( tipo == 5 )
        {

            fChain -> AddFile (path + "/4lep/MC/mc_363358.WqqZll.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_363489.WlvZqq.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_363491.lllv.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_363493.lvvv.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_363359.WpqqWmlv.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_363360.WplvWmqq.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_363492.llvv.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_363356.ZqqZll.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_363490.llll.4lep.root");

            std::cout << " " << std::endl;
            std::cout << "Análisis para ZZ:" << std::endl;

        }


      // Others

        if ( tipo == 6 )
        {

          // V + jets

            fChain -> AddFile (path + "/4lep/MC/mc_361100.Wplusenu.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_361101.Wplusmunu.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_361102.Wplustaunu.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_361103.Wminusenu.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_361104.Wminusmunu.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_361105.Wminustaunu.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_361106.Zee.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_361107.Zmumu.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_361108.Ztautau.4lep.root");


          // TOP - ANTITOP

            fChain -> AddFile (path + "/4lep/MC/mc_410000.ttbar_lep.4lep.root");


          // SINGLE TOP

            fChain -> AddFile (path + "/4lep/MC/mc_410011.single_top_tchan.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_410012.single_antitop_tchan.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_410013.single_top_wtchan.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_410014.single_antitop_wtchan.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_410025.single_top_schan.4lep.root");
            fChain -> AddFile (path + "/4lep/MC/mc_410026.single_antitop_schan.4lep.root");


            std::cout << " " << std::endl;
            std::cout << "Análisis para Otros ( V + jets, top - antitop, single top):" << std::endl;

        }


    // DEFINIR LAS VARIABLES

      // NÚMERO DE EVENTOS

        Int_t             RunNumber = 0;
        Int_t             EventNumber = 0;
        Int_t             ChannelNumber = 0;


      // PESOS

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


      // LEPTONES  

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


      // FOTONES

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


      // INCERTIDUMBRES

        vector<float>     *Lep_pt_syst = 0;
        Float_t           *Met_et_syst = 0;
        vector<float>     *Jet_pt_syst = 0;
        vector<float>     *Photon_pt_syst = 0;
        vector<float>     *LargeRjet_pt_syst = 0;
        vector<float>     *Tau_pt_syst = 0;


      // BRANCH

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


    // LEER LOS DATOS

      // LEER LOS DATOS DEL NÚMERO DE EVENTOS

        fChain -> SetBranchAddress ( "runNumber",                         &RunNumber,                             &b_runNumber);
        fChain -> SetBranchAddress ( "eventNumber",                       &EventNumber,                           &b_eventNumber);
        fChain -> SetBranchAddress ( "channelNumber",                     &ChannelNumber,                         &b_channelNumber);


      // LEER LOS DATOS DE LOS PESOS

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


      // LEER LOS DATOS DE LOS TRIGGER

        fChain -> SetBranchAddress ( "trigE",                             &TrigE,                                 &b_TrigE );
        fChain -> SetBranchAddress ( "trigM",                             &TrigM,                                 &b_TrigM );
        fChain -> SetBranchAddress ( "trigP",                             &TrigP,                                 &b_TrigP );


      // LEER LOS DATOS DE LOS LEPTONES

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


      // LEER LOS DATOS DE ETMISS

        fChain -> SetBranchAddress ( "met_et",                            &Met_et,                                &b_Met_et );
        fChain -> SetBranchAddress ( "met_phi",                           &Met_phi,                               &b_Met_phi );


      // LEER LOS DATOS DE LOS JETS

        fChain -> SetBranchAddress ( "jet_n",                             &Jet_n,                                 &b_Jet_n );
        fChain -> SetBranchAddress ( "jet_pt",                            &Jet_pt,                                &b_Jet_pt );
        fChain -> SetBranchAddress ( "jet_eta",                           &Jet_eta,                               &b_Jet_eta );
        fChain -> SetBranchAddress ( "jet_phi",                           &Jet_phi,                               &b_Jet_phi );
        fChain -> SetBranchAddress ( "jet_E",                             &Jet_E,                                 &b_Jet_E );
        fChain -> SetBranchAddress ( "jet_jvt",                           &Jet_jvt,                               &b_Jet_jvt );
        fChain -> SetBranchAddress ( "jet_trueflav",                      &Jet_trueflav,                          &b_Jet_trueflav );
        fChain -> SetBranchAddress ( "jet_truthMatched",                  &Jet_truthMatched,                      &b_Jet_truthMatched );
        fChain -> SetBranchAddress ( "jet_MV2c10",                        &Jet_MV2c10,                            &b_Jet_MV2c10 );


      // LEER LOS DATOS DE LOS FOTONES

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


      // LEER LOS DATOS DE LOS LARGE R JETS

        fChain -> SetBranchAddress ( "largeRjet_n",                       &LargeRjet_n,                           &b_LargeRjet_n );
        fChain -> SetBranchAddress ( "largeRjet_pt",                      &LargeRjet_pt,                          &b_LargeRjet_pt );
        fChain -> SetBranchAddress ( "largeRjet_eta",                     &LargeRjet_eta,                         &b_LargeRjet_eta );
        fChain -> SetBranchAddress ( "largeRjet_phi",                     &LargeRjet_phi,                         &b_LargeRjet_phi );
        fChain -> SetBranchAddress ( "largeRjet_E",                       &LargeRjet_E,                           &b_LargeRjet_E );
        fChain -> SetBranchAddress ( "largeRjet_m",                       &LargeRjet_m,                           &b_LargeRjet_m );
        fChain -> SetBranchAddress ( "largeRjet_truthMatched",            &LargeRjet_truthMatched,                &b_LargeRjet_truthMatched );
        fChain -> SetBranchAddress ( "largeRjet_D2",                      &LargeRjet_D2,                          &b_LargeRjet_D2 );
        fChain -> SetBranchAddress ( "largeRjet_tau32",                   &LargeRjet_tau32,                       &b_LargeRjet_tau32 );


      // LEER LOS DATOS DE LOS TAU

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


      // LEER LOS DATOS DE LAS INCERTIDUMBRES

        fChain -> SetBranchAddress ( "lep_pt_syst",                       &Lep_pt_syst,                           &b_Lep_pt_syst );
        fChain -> SetBranchAddress ( "met_et_syst",                       &Met_et_syst,                           &b_Met_et_syst );
        fChain -> SetBranchAddress ( "jet_pt_syst",                       &Jet_pt_syst,                           &b_Jet_pt_syst );
        fChain -> SetBranchAddress ( "photon_pt_syst",                    &Photon_pt_syst,                        &b_Photon_pt_syst );
        fChain -> SetBranchAddress ( "largeRjet_pt_syst",                 &LargeRjet_pt_syst,                     &b_LargeRjet_pt_syst );
        fChain -> SetBranchAddress ( "tau_pt_syst",                       &Tau_pt_syst,                           &b_Tau_pt_syst );


      // CRITERIOS DE SELECCIÓN

        int nentries = 0;
        int nbytes = 0;
        int i = 0;

        nentries = (Int_t) fChain -> GetEntries();

        std::cout << "* Número de entradas para analizar: " << nentries << std::endl;

        for ( i = 0; i < nentries; i++)
        {

            nbytes = fChain -> GetEntry(i);

            float Lumi = 10000;       // Porque la sección eficaz está en pb (10 si fuese fb)
            Float_t SF = 0;
            Float_t weight = 0;
            float norm = 1.;

            if ( tipo == 3 )            // La sección eficaz del ZH es distinta
            {

                XSection = 0.00023545150;

            }

            if ( tipo == 5 )
            {

                norm = 1.31;

            }

            SF = SF_Ele * SF_Muon * SF_LepTrig * SF_Pileup;
            weight = norm * SF * mcWeight * XSection * Lumi / SumWeights;

             if ( TrigE || TrigM )
            {

                int goodlep_index[Lep_n];
                int goodlep_n = 0;
                int lep_index = 0;

                for ( unsigned int j = 0; j < Lep_n; j ++ )
                {

                    TLorentzVector leptemp = TLorentzVector();

                    leptemp.SetPtEtaPhiE ( Lep_pt -> at(j) / 1000., Lep_eta -> at(j), Lep_phi -> at(j), Lep_E -> at(j) / 1000. );

                    if ( Lep_pt -> at(j) > 7000. && ( Lep_ptcone30 -> at(j) / Lep_pt -> at(j) ) < 0.3 && ( Lep_etcone20 -> at(j) / Lep_pt -> at(j) ) < 0.3 )
                    {

                        if ( TMath::Abs ( Lep_eta -> at(j) ) < 2.5 )
                        {

                            if ( Lep_type -> at(j) == 11 )
                            {

                                if ( TMath::Abs( Lep_trackd0pvunbiased -> at(j) ) / Lep_tracksigd0pvunbiased -> at(j) < 5 && TMath::Abs ( Lep_z0 -> at(j) * TMath::Sin( leptemp.Theta() ) ) < 0.5 )
                                {

                                    goodlep_n = goodlep_n + 1;
                                    goodlep_index [lep_index] = j;
                                    lep_index ++;

                                }

                            }


                            if ( Lep_type -> at(j) == 13 )
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


                if ( goodlep_n == 4 )
                {

                    int goodlep1_index = goodlep_index[0];
                    int goodlep2_index = goodlep_index[1];
                    int goodlep3_index = goodlep_index[2];
                    int goodlep4_index = goodlep_index[3];

                    if ( Lep_pt -> at(goodlep1_index) > 25000. && Lep_pt -> at(goodlep2_index) > 15000. && Lep_pt -> at(goodlep3_index) > 10000. )
                    {

                            int goodjet_n = 0;
                            int goodjet_index = 0;

                            if ( Jet_n > 0 )
                            {

                                for ( unsigned int j = 0; j < Jet_n; j++ )
                                {

				                    if( Jet_pt -> at (j) > 25000. && TMath::Abs( Jet_eta -> at (j) ) < 2.4 && Jet_jvt -> at (j) > 0.59 )
				                    {

				                        goodjet_n ++;
				                        goodjet_index = j;

				                    }

                                }

                            }

		            TLorentzVector Lepton_1 = TLorentzVector();
		            TLorentzVector Lepton_2 = TLorentzVector();
		            TLorentzVector Lepton_3 = TLorentzVector();
		            TLorentzVector Lepton_4 = TLorentzVector();
		  
		            Lepton_1.SetPtEtaPhiE( Lep_pt -> at(goodlep1_index), Lep_eta -> at(goodlep1_index), Lep_phi -> at(goodlep1_index),Lep_E -> at(goodlep1_index) );
		            Lepton_2.SetPtEtaPhiE( Lep_pt -> at(goodlep2_index), Lep_eta -> at(goodlep2_index), Lep_phi -> at(goodlep2_index),Lep_E -> at(goodlep2_index) );
		            Lepton_3.SetPtEtaPhiE( Lep_pt -> at(goodlep3_index), Lep_eta -> at(goodlep3_index), Lep_phi -> at(goodlep3_index),Lep_E -> at(goodlep3_index) );
		            Lepton_4.SetPtEtaPhiE( Lep_pt -> at(goodlep4_index), Lep_eta -> at(goodlep4_index), Lep_phi -> at(goodlep4_index),Lep_E -> at(goodlep4_index) );

		  		    float delta_Z1 = 0;
		            float delta_Z2 = 0;

		            float massZ1 = 0;
		            float massZ2 = 0;

		            float massZ1_min = 0;
		            float massZ2_min = 0;

		            float mZ = 91.18;
		  
		  		    float sum_charges = Lep_charge -> at(goodlep1_index) + Lep_charge -> at(goodlep2_index) + Lep_charge -> at(goodlep3_index) + Lep_charge -> at(goodlep4_index);			 
		  
                    if ( sum_charges == 0  ) 
		            {
		      		      
		                int sum_types  = Lep_type -> at(goodlep1_index) + Lep_type -> at(goodlep2_index) + Lep_type -> at(goodlep3_index) + Lep_type -> at(goodlep4_index) ;

		                if ( sum_types == 44 || sum_types == 52  )
			            {



			                if ( Lep_charge -> at(goodlep1_index) * Lep_charge -> at(goodlep3_index) < 0 )
			                {

                                massZ1 = (Lepton_1 + Lepton_3).Mag() / 1000.;
			                    massZ2 = (Lepton_2 + Lepton_4).Mag() / 1000.;
			                    delta_Z1 = TMath::Abs(massZ1 - mZ); 
			                    delta_Z2 = TMath::Abs(massZ2 - mZ);

			                    if(delta_Z1 < delta_Z2)
                                {

                                    massZ1_min = massZ1;
                                    massZ2_min = massZ2;

                                }

                                if(delta_Z2 < delta_Z1)
                                {

                                    massZ1_min = massZ2;
                                    massZ2_min = massZ1;

                                }

			                }

			                if ( Lep_charge -> at(goodlep1_index) * Lep_charge -> at(goodlep4_index) < 0 )
			                {

			                    massZ1 = (Lepton_1 + Lepton_4).Mag() / 1000.;
			                    massZ2 = (Lepton_2 + Lepton_3).Mag() / 1000.;
			                    delta_Z1 = TMath::Abs(massZ1 - mZ); 
			                    delta_Z2 = TMath::Abs(massZ2 - mZ);

			                    if(delta_Z1 < delta_Z2)
                                {

                                    massZ1_min = massZ1;
                                    massZ2_min = massZ2;

                                }

                                if(delta_Z2 < delta_Z1)
                                {

                                    massZ1_min = massZ2;
                                    massZ2_min = massZ1;

                                }

			                }

			            }
		      
		                if ( sum_types == 48 )
			            {
			  
			                if ( Lep_type -> at(goodlep1_index) == Lep_type -> at(goodlep2_index) )
			                {

			                    massZ1 = (Lepton_1 + Lepton_2).Mag() / 1000.;
			                    massZ2 = (Lepton_3 + Lepton_4).Mag() / 1000.;
			                    delta_Z1 = TMath::Abs(massZ1 - mZ); 
			                    delta_Z2 = TMath::Abs(massZ2 - mZ);

			                }

			                if ( Lep_type -> at(goodlep1_index) == Lep_type -> at(goodlep3_index) )
			                {

			                    massZ1 = (Lepton_1 + Lepton_3).Mag() / 1000.;
			                    massZ2 = (Lepton_2 + Lepton_4).Mag() / 1000.;
			                    delta_Z1 = TMath::Abs(massZ1 - mZ); 
			                    delta_Z2 = TMath::Abs(massZ2 - mZ);

			                }

			                if ( Lep_type -> at(goodlep1_index) == Lep_type -> at(goodlep4_index) )
			                {

			                    massZ1 = (Lepton_1+Lepton_4).Mag() / 1000.;
			                    massZ2 = (Lepton_2+Lepton_3).Mag() / 1000.;
			                    delta_Z1 = TMath::Abs(massZ1 - mZ); 
			                    delta_Z2 = TMath::Abs(massZ2 - mZ);
			                }
			  
			                if(delta_Z1 < delta_Z2)
                            {

                                massZ1_min = massZ1;
                                massZ2_min = massZ2;

                            }

			                if(delta_Z2 < delta_Z1)
                            {

                                massZ1_min = massZ2;
                                massZ2_min = massZ1;

                            }

			            }
		      
		                if ( (sum_types == 44 || sum_types == 52 || sum_types == 48) )
			            {
			  
			                TLorentzVector FourLepSystem = TLorentzVector();

			                FourLepSystem = Lepton_1 + Lepton_2 + Lepton_3 + Lepton_4;

			                float mass = FourLepSystem.Mag() / 1000.;

                            if ( tipo == 0 )
                            {                                               

                                hist_eta_Data -> Fill ( Lepton_1.Eta() );
                                hist_eta_Data -> Fill ( Lepton_2.Eta() );
                                hist_eta_Data -> Fill ( Lepton_3.Eta() );
                                hist_eta_Data -> Fill ( Lepton_4.Eta() );

                                hist_phi_Data -> Fill ( Lepton_1.Phi() );
                                hist_phi_Data -> Fill ( Lepton_2.Phi() );
                                hist_phi_Data -> Fill ( Lepton_3.Phi() );
                                hist_phi_Data -> Fill ( Lepton_4.Phi() );

                                hist_pt_Data -> Fill ( Lepton_1.Pt()/1000. );
                                hist_pt_Data -> Fill ( Lepton_2.Pt()/1000. );
                                hist_pt_Data -> Fill ( Lepton_3.Pt()/1000. );
                                hist_pt_Data -> Fill ( Lepton_4.Pt()/1000. );

                                hist_E_Data -> Fill ( Lepton_1.E()/1000. );
                                hist_E_Data -> Fill ( Lepton_2.E()/1000. );
                                hist_E_Data -> Fill ( Lepton_3.E()/1000. );
                                hist_E_Data -> Fill ( Lepton_4.E()/1000. );

                                hist_mLL1_Data -> Fill ( massZ1_min );

                                hist_mLL2_Data -> Fill ( massZ2_min );

                                hist_Njets_Data -> Fill ( goodjet_n );

                                hist_mass_Data -> Fill ( mass );

                            }
           
                            if ( tipo == 1 || tipo == 2 || tipo == 3 || tipo == 4  )
                            {                                               

                                hist_eta_Higgs -> Fill ( Lepton_1.Eta(), weight );
                                hist_eta_Higgs -> Fill ( Lepton_2.Eta(), weight );
                                hist_eta_Higgs -> Fill ( Lepton_3.Eta(), weight );
                                hist_eta_Higgs -> Fill ( Lepton_4.Eta(), weight );
                                hist_eta -> Fill ( Lepton_1.Eta(), weight );
                                hist_eta -> Fill ( Lepton_2.Eta(), weight );
                                hist_eta -> Fill ( Lepton_3.Eta(), weight );
                                hist_eta -> Fill ( Lepton_4.Eta(), weight );

                                hist_phi_Higgs -> Fill ( Lepton_1.Phi(), weight );
                                hist_phi_Higgs -> Fill ( Lepton_2.Phi(), weight );
                                hist_phi_Higgs -> Fill ( Lepton_3.Phi(), weight );
                                hist_phi_Higgs -> Fill ( Lepton_4.Phi(), weight );
                                hist_phi -> Fill ( Lepton_1.Phi(), weight );
                                hist_phi -> Fill ( Lepton_2.Phi(), weight );
                                hist_phi -> Fill ( Lepton_3.Phi(), weight );
                                hist_phi -> Fill ( Lepton_4.Phi(), weight );

                                hist_pt_Higgs -> Fill ( Lepton_1.Pt()/1000., weight );
                                hist_pt_Higgs -> Fill ( Lepton_2.Pt()/1000., weight );
                                hist_pt_Higgs -> Fill ( Lepton_3.Pt()/1000., weight );
                                hist_pt_Higgs -> Fill ( Lepton_4.Pt()/1000., weight );
                                hist_pt -> Fill ( Lepton_1.Pt()/1000., weight );
                                hist_pt -> Fill ( Lepton_2.Pt()/1000., weight );
                                hist_pt -> Fill ( Lepton_3.Pt()/1000., weight );
                                hist_pt -> Fill ( Lepton_4.Pt()/1000., weight );

                                hist_E_Higgs -> Fill ( Lepton_1.E()/1000., weight );
                                hist_E_Higgs -> Fill ( Lepton_2.E()/1000., weight );
                                hist_E_Higgs -> Fill ( Lepton_3.E()/1000., weight );
                                hist_E_Higgs -> Fill ( Lepton_4.E()/1000., weight );
                                hist_E -> Fill ( Lepton_1.E()/1000., weight );
                                hist_E -> Fill ( Lepton_2.E()/1000., weight );
                                hist_E -> Fill ( Lepton_3.E()/1000., weight );
                                hist_E -> Fill ( Lepton_4.E()/1000., weight );

                                hist_mLL1_Higgs -> Fill ( massZ1_min, weight );
                                hist_mLL1 -> Fill ( massZ1_min, weight );

                                hist_mLL2_Higgs -> Fill ( massZ2_min, weight );
                                hist_mLL2 -> Fill ( massZ1_min, weight );

                                hist_Njets_Higgs -> Fill ( goodjet_n, weight );
                                hist_Njets -> Fill ( goodjet_n, weight );

                                hist_mass_Higgs -> Fill ( mass, weight );
                                hist_mass -> Fill ( mass, weight );

                            }

                            if ( tipo == 5 )
                            {                                               

                                hist_eta_ZZ -> Fill ( Lepton_1.Eta(), weight );
                                hist_eta_ZZ -> Fill ( Lepton_2.Eta(), weight );
                                hist_eta_ZZ -> Fill ( Lepton_3.Eta(), weight );
                                hist_eta_ZZ -> Fill ( Lepton_4.Eta(), weight );
                                hist_eta -> Fill ( Lepton_1.Eta(), weight );
                                hist_eta -> Fill ( Lepton_2.Eta(), weight );
                                hist_eta -> Fill ( Lepton_3.Eta(), weight );
                                hist_eta -> Fill ( Lepton_4.Eta(), weight );

                                hist_phi_ZZ -> Fill ( Lepton_1.Phi(), weight );
                                hist_phi_ZZ -> Fill ( Lepton_2.Phi(), weight );
                                hist_phi_ZZ -> Fill ( Lepton_3.Phi(), weight );
                                hist_phi_ZZ -> Fill ( Lepton_4.Phi(), weight );
                                hist_phi -> Fill ( Lepton_1.Phi(), weight );
                                hist_phi -> Fill ( Lepton_2.Phi(), weight );
                                hist_phi -> Fill ( Lepton_3.Phi(), weight );
                                hist_phi -> Fill ( Lepton_4.Phi(), weight );

                                hist_pt_ZZ -> Fill ( Lepton_1.Pt()/1000., weight );
                                hist_pt_ZZ -> Fill ( Lepton_2.Pt()/1000., weight );
                                hist_pt_ZZ -> Fill ( Lepton_3.Pt()/1000., weight );
                                hist_pt_ZZ -> Fill ( Lepton_4.Pt()/1000., weight );
                                hist_pt -> Fill ( Lepton_1.Pt()/1000., weight );
                                hist_pt -> Fill ( Lepton_2.Pt()/1000., weight );
                                hist_pt -> Fill ( Lepton_3.Pt()/1000., weight );
                                hist_pt -> Fill ( Lepton_4.Pt()/1000., weight );

                                hist_E_ZZ -> Fill ( Lepton_1.E()/1000., weight );
                                hist_E_ZZ -> Fill ( Lepton_2.E()/1000., weight );
                                hist_E_ZZ -> Fill ( Lepton_3.E()/1000., weight );
                                hist_E_ZZ -> Fill ( Lepton_4.E()/1000., weight );
                                hist_E -> Fill ( Lepton_1.E()/1000., weight );
                                hist_E -> Fill ( Lepton_2.E()/1000., weight );
                                hist_E -> Fill ( Lepton_3.E()/1000., weight );
                                hist_E -> Fill ( Lepton_4.E()/1000., weight );

                                hist_mLL1_ZZ -> Fill ( massZ1_min, weight );
                                hist_mLL1 -> Fill ( massZ1_min, weight );

                                hist_mLL2_ZZ -> Fill ( massZ2_min, weight );
                                hist_mLL2 -> Fill ( massZ1_min, weight );

                                hist_Njets_ZZ -> Fill ( goodjet_n, weight );
                                hist_Njets -> Fill ( goodjet_n, weight );

                                hist_mass_ZZ -> Fill ( mass, weight );
                                hist_mass -> Fill ( mass, weight );

                            }

                            if ( tipo == 6 )
                            {                                               

                                hist_eta_Other -> Fill ( Lepton_1.Eta(), weight );
                                hist_eta_Other -> Fill ( Lepton_2.Eta(), weight );
                                hist_eta_Other -> Fill ( Lepton_3.Eta(), weight );
                                hist_eta_Other -> Fill ( Lepton_4.Eta(), weight );
                                hist_eta -> Fill ( Lepton_1.Eta(), weight );
                                hist_eta -> Fill ( Lepton_2.Eta(), weight );
                                hist_eta -> Fill ( Lepton_3.Eta(), weight );
                                hist_eta -> Fill ( Lepton_4.Eta(), weight );

                                hist_phi_Other -> Fill ( Lepton_1.Phi(), weight );
                                hist_phi_Other -> Fill ( Lepton_2.Phi(), weight );
                                hist_phi_Other -> Fill ( Lepton_3.Phi(), weight );
                                hist_phi_Other -> Fill ( Lepton_4.Phi(), weight );
                                hist_phi -> Fill ( Lepton_1.Phi(), weight );
                                hist_phi -> Fill ( Lepton_2.Phi(), weight );
                                hist_phi -> Fill ( Lepton_3.Phi(), weight );
                                hist_phi -> Fill ( Lepton_4.Phi(), weight );

                                hist_pt_Other -> Fill ( Lepton_1.Pt()/1000., weight );
                                hist_pt_Other -> Fill ( Lepton_2.Pt()/1000., weight );
                                hist_pt_Other -> Fill ( Lepton_3.Pt()/1000., weight );
                                hist_pt_Other -> Fill ( Lepton_4.Pt()/1000., weight );
                                hist_pt -> Fill ( Lepton_1.Pt()/1000., weight );
                                hist_pt -> Fill ( Lepton_2.Pt()/1000., weight );
                                hist_pt -> Fill ( Lepton_3.Pt()/1000., weight );
                                hist_pt -> Fill ( Lepton_4.Pt()/1000., weight );

                                hist_E_Other -> Fill ( Lepton_1.E()/1000., weight );
                                hist_E_Other -> Fill ( Lepton_2.E()/1000., weight );
                                hist_E_Other -> Fill ( Lepton_3.E()/1000., weight );
                                hist_E_Other -> Fill ( Lepton_4.E()/1000., weight );
                                hist_E -> Fill ( Lepton_1.E()/1000., weight );
                                hist_E -> Fill ( Lepton_2.E()/1000., weight );
                                hist_E -> Fill ( Lepton_3.E()/1000., weight );
                                hist_E -> Fill ( Lepton_4.E()/1000., weight );

                                hist_mLL1_Other -> Fill ( massZ1_min, weight );
                                hist_mLL1 -> Fill ( massZ1_min, weight );

                                hist_mLL2_Other -> Fill ( massZ2_min, weight );
                                hist_mLL2 -> Fill ( massZ1_min, weight );

                                hist_Njets_Other -> Fill ( goodjet_n, weight );
                                hist_Njets -> Fill ( goodjet_n, weight );

                                hist_mass_Other -> Fill ( mass, weight );
                                hist_mass -> Fill ( mass, weight );

                            }

                        }

                    }
                                                
                }

            }

        }

    }

  }


 // CÁLCULO DE LA INTEGRAL DE LOS HISTOGRAMAS

    std::cout << " " << std::endl;
    std::cout << "CÁLCULO DE LAS INTEGRALES PARA DATA:" << std::endl;
    float Int_eta_Data = hist_eta_Data -> Integral (0, 10);
    std::cout << "* eta: " << Int_eta_Data << std::endl;
    float Int_phi_Data = hist_phi_Data -> Integral (0, 8);
    std::cout << "* phi: " << Int_phi_Data << std::endl;
    float Int_pt_Data = hist_pt_Data -> Integral (0, 5);
    std::cout << "* pt: " << Int_pt_Data << std::endl;
    float Int_E_Data = hist_E_Data -> Integral (0, 10);
    std::cout << "* E: " << Int_E_Data << std::endl;
    float Int_mLL1_Data = hist_mLL1_Data -> Integral (0, 30);
    std::cout << "* mLL1: " << Int_mLL1_Data << std::endl;
    float Int_mLL2_Data = hist_mLL2_Data -> Integral (0, 30);
    std::cout << "* mLL2: " << Int_mLL2_Data << std::endl;
    float Int_Njets_Data = hist_Njets_Data -> Integral (0, 10);
    std::cout << "* Njets: " << Int_Njets_Data << std::endl;
    float Int_mass_Data = hist_mass_Data -> Integral (0, 24);
    std::cout << "* mass: " << Int_mass_Data << std::endl;

    std::cout << " " << std::endl;
    std::cout << "CÁLCULO DE LAS INTEGRALES PARA HIGGS:" << std::endl;
    float Int_eta_Higgs = hist_eta_Higgs -> Integral (0, 10);
    std::cout << "* eta: " << Int_eta_Higgs << std::endl;
    float Int_phi_Higgs = hist_phi_Higgs -> Integral (0, 8);
    std::cout << "* phi: " << Int_phi_Higgs << std::endl;
    float Int_pt_Higgs = hist_pt_Higgs -> Integral (0, 5);
    std::cout << "* pt: " << Int_pt_Higgs << std::endl;
    float Int_E_Higgs = hist_E_Higgs -> Integral (0, 10);
    std::cout << "* E: " << Int_E_Higgs << std::endl;
    float Int_mLL1_Higgs = hist_mLL1_Higgs -> Integral (0, 30);
    std::cout << "* mLL1: " << Int_mLL1_Higgs << std::endl;
    float Int_mLL2_Higgs = hist_mLL2_Higgs -> Integral (0, 30);
    std::cout << "* mLL2: " << Int_mLL2_Higgs << std::endl;
    float Int_Njets_Higgs = hist_Njets_Higgs -> Integral (0, 10);
    std::cout << "* Njets: " << Int_Njets_Higgs << std::endl;
    float Int_mass_Higgs = hist_mass_Higgs -> Integral (0, 24);
    std::cout << "* mass: " << Int_mass_Higgs << std::endl;

    std::cout << " " << std::endl;
    std::cout << "CÁLCULO DE LAS INTEGRALES PARA ZZ:" << std::endl;
    float Int_eta_ZZ = hist_eta_ZZ -> Integral (0, 10);
    std::cout << "* eta: " << Int_eta_ZZ << std::endl;
    float Int_phi_ZZ = hist_phi_ZZ -> Integral (0, 8);
    std::cout << "* phi: " << Int_phi_ZZ << std::endl;
    float Int_pt_ZZ = hist_pt_ZZ -> Integral (0, 5);
    std::cout << "* pt: " << Int_pt_ZZ << std::endl;
    float Int_E_ZZ = hist_E_ZZ -> Integral (0, 10);
    std::cout << "* E: " << Int_E_ZZ << std::endl;
    float Int_mLL1_ZZ = hist_mLL1_ZZ -> Integral (0, 30);
    std::cout << "* mLL1: " << Int_mLL1_ZZ << std::endl;
    float Int_mLL2_ZZ = hist_mLL2_ZZ -> Integral (0, 30);
    std::cout << "* mLL2: " << Int_mLL2_ZZ << std::endl;
    float Int_Njets_ZZ = hist_Njets_ZZ -> Integral (0, 10);
    std::cout << "* Njets: " << Int_Njets_ZZ << std::endl;
    float Int_mass_ZZ = hist_mass_ZZ -> Integral (0, 24);
    std::cout << "* mass: " << Int_mass_ZZ << std::endl;

    std::cout << " " << std::endl;
    std::cout << "CÁLCULO DE LAS INTEGRALES PARA OTHER:" << std::endl;
    float Int_eta_Other = hist_eta_Other -> Integral (0, 10);
    std::cout << "* eta: " << Int_eta_Other << std::endl;
    float Int_phi_Other = hist_phi_Other -> Integral (0, 8);
    std::cout << "* phi: " << Int_phi_Other << std::endl;
    float Int_pt_Other = hist_pt_Other -> Integral (0, 5);
    std::cout << "* pt: " << Int_pt_Other << std::endl;
    float Int_E_Other = hist_E_Other -> Integral (0, 10);
    std::cout << "* E: " << Int_E_Other << std::endl;
    float Int_mLL1_Other = hist_mLL1_Other -> Integral (0, 30);
    std::cout << "* mLL1: " << Int_mLL1_Other << std::endl;
    float Int_mLL2_Other = hist_mLL2_Other -> Integral (0, 30);
    std::cout << "* mLL2: " << Int_mLL2_Other << std::endl;
    float Int_Njets_Other = hist_Njets_Other -> Integral (0, 10);
    std::cout << "* Njets: " << Int_Njets_Other << std::endl;
    float Int_mass_Other = hist_mass_Other -> Integral (0, 24);
    std::cout << "* mass: " << Int_mass_Other << std::endl;


  // OVERFLOW

    // DATA

        hist_eta_Data -> SetBinContent( hist_eta_Data -> GetNbinsX(), hist_eta_Data -> GetBinContent( hist_eta_Data -> GetNbinsX()) + hist_eta_Data -> GetBinContent( hist_eta_Data -> GetNbinsX() + 1));
        hist_phi_Data -> SetBinContent( hist_phi_Data -> GetNbinsX(), hist_phi_Data -> GetBinContent( hist_phi_Data -> GetNbinsX()) + hist_phi_Data -> GetBinContent( hist_phi_Data -> GetNbinsX() + 1));
        hist_pt_Data -> SetBinContent( hist_pt_Data -> GetNbinsX(), hist_pt_Data -> GetBinContent( hist_pt_Data -> GetNbinsX()) + hist_pt_Data -> GetBinContent( hist_pt_Data -> GetNbinsX() + 1));
        hist_E_Data -> SetBinContent( hist_E_Data -> GetNbinsX(), hist_E_Data -> GetBinContent( hist_E_Data -> GetNbinsX()) + hist_E_Data -> GetBinContent( hist_E_Data -> GetNbinsX() + 1));
        hist_mLL1_Data -> SetBinContent( hist_mLL1_Data -> GetNbinsX(), hist_mLL1_Data -> GetBinContent( hist_mLL1_Data -> GetNbinsX()) + hist_mLL1_Data -> GetBinContent( hist_mLL1_Data -> GetNbinsX() + 1));
        hist_mLL2_Data -> SetBinContent( hist_mLL2_Data -> GetNbinsX(), hist_mLL2_Data -> GetBinContent( hist_mLL2_Data -> GetNbinsX()) + hist_mLL2_Data -> GetBinContent( hist_mLL2_Data -> GetNbinsX() + 1));
        hist_Njets_Data -> SetBinContent( hist_Njets_Data -> GetNbinsX(), hist_Njets_Data -> GetBinContent( hist_Njets_Data -> GetNbinsX()) + hist_Njets_Data -> GetBinContent( hist_Njets_Data -> GetNbinsX() + 1));
        

    // HIGGS

        hist_eta_Higgs -> SetBinContent( hist_eta_Higgs -> GetNbinsX(), hist_eta_Higgs -> GetBinContent( hist_eta_Higgs -> GetNbinsX()) + hist_eta_Higgs -> GetBinContent( hist_eta_Higgs -> GetNbinsX() + 1));
        hist_phi_Higgs -> SetBinContent( hist_phi_Higgs -> GetNbinsX(), hist_phi_Higgs -> GetBinContent( hist_phi_Higgs -> GetNbinsX()) + hist_phi_Higgs -> GetBinContent( hist_phi_Higgs -> GetNbinsX() + 1));
        hist_pt_Higgs -> SetBinContent( hist_pt_Higgs -> GetNbinsX(), hist_pt_Higgs -> GetBinContent( hist_pt_Higgs -> GetNbinsX()) + hist_pt_Higgs -> GetBinContent( hist_pt_Higgs -> GetNbinsX() + 1));
        hist_E_Higgs -> SetBinContent( hist_E_Higgs -> GetNbinsX(), hist_E_Higgs -> GetBinContent( hist_E_Higgs -> GetNbinsX()) + hist_E_Higgs -> GetBinContent( hist_E_Higgs -> GetNbinsX() + 1));
        hist_mLL1_Higgs -> SetBinContent( hist_mLL1_Higgs -> GetNbinsX(), hist_mLL1_Higgs -> GetBinContent( hist_mLL1_Higgs -> GetNbinsX()) + hist_mLL1_Higgs -> GetBinContent( hist_mLL1_Higgs -> GetNbinsX() + 1));
        hist_mLL2_Higgs -> SetBinContent( hist_mLL2_Higgs -> GetNbinsX(), hist_mLL2_Higgs -> GetBinContent( hist_mLL2_Higgs -> GetNbinsX()) + hist_mLL2_Higgs -> GetBinContent( hist_mLL2_Higgs -> GetNbinsX() + 1));
        hist_Njets_Higgs -> SetBinContent( hist_Njets_Higgs -> GetNbinsX(), hist_Njets_Higgs -> GetBinContent( hist_Njets_Higgs -> GetNbinsX()) + hist_Njets_Higgs -> GetBinContent( hist_Njets_Higgs -> GetNbinsX() + 1));
        

    // ZZ

        hist_eta_ZZ -> SetBinContent( hist_eta_ZZ -> GetNbinsX(), hist_eta_ZZ -> GetBinContent( hist_eta_ZZ -> GetNbinsX()) + hist_eta_ZZ -> GetBinContent( hist_eta_ZZ -> GetNbinsX() + 1));
        hist_phi_ZZ -> SetBinContent( hist_phi_ZZ -> GetNbinsX(), hist_phi_ZZ -> GetBinContent( hist_phi_ZZ -> GetNbinsX()) + hist_phi_ZZ -> GetBinContent( hist_phi_ZZ -> GetNbinsX() + 1));
        hist_pt_ZZ -> SetBinContent( hist_pt_ZZ -> GetNbinsX(), hist_pt_ZZ -> GetBinContent( hist_pt_ZZ -> GetNbinsX()) + hist_pt_ZZ -> GetBinContent( hist_pt_ZZ -> GetNbinsX() + 1));
        hist_E_ZZ -> SetBinContent( hist_E_ZZ -> GetNbinsX(), hist_E_ZZ -> GetBinContent( hist_E_ZZ -> GetNbinsX()) + hist_E_ZZ -> GetBinContent( hist_E_ZZ -> GetNbinsX() + 1));
        hist_mLL1_ZZ -> SetBinContent( hist_mLL1_ZZ -> GetNbinsX(), hist_mLL1_ZZ -> GetBinContent( hist_mLL1_ZZ -> GetNbinsX()) + hist_mLL1_ZZ -> GetBinContent( hist_mLL1_ZZ -> GetNbinsX() + 1));
        hist_mLL2_ZZ -> SetBinContent( hist_mLL2_ZZ -> GetNbinsX(), hist_mLL2_ZZ -> GetBinContent( hist_mLL2_ZZ -> GetNbinsX()) + hist_mLL2_ZZ -> GetBinContent( hist_mLL2_ZZ -> GetNbinsX() + 1));
        hist_Njets_ZZ -> SetBinContent( hist_Njets_ZZ -> GetNbinsX(), hist_Njets_ZZ -> GetBinContent( hist_Njets_ZZ -> GetNbinsX()) + hist_Njets_ZZ -> GetBinContent( hist_Njets_ZZ -> GetNbinsX() + 1));
        

    // OTHER

        hist_eta_Other -> SetBinContent( hist_eta_Other -> GetNbinsX(), hist_eta_Other -> GetBinContent( hist_eta_Other -> GetNbinsX()) + hist_eta_Other -> GetBinContent( hist_eta_Other -> GetNbinsX() + 1));
        hist_phi_Other -> SetBinContent( hist_phi_Other -> GetNbinsX(), hist_phi_Other -> GetBinContent( hist_phi_Other -> GetNbinsX()) + hist_phi_Other -> GetBinContent( hist_phi_Other -> GetNbinsX() + 1));
        hist_pt_Other -> SetBinContent( hist_pt_Other -> GetNbinsX(), hist_pt_Other -> GetBinContent( hist_pt_Other -> GetNbinsX()) + hist_pt_Other -> GetBinContent( hist_pt_Other -> GetNbinsX() + 1));
        hist_E_Other -> SetBinContent( hist_E_Other -> GetNbinsX(), hist_E_Other -> GetBinContent( hist_E_Other -> GetNbinsX()) + hist_E_Other -> GetBinContent( hist_E_Other -> GetNbinsX() + 1));
        hist_mLL1_Other -> SetBinContent( hist_mLL1_Other -> GetNbinsX(), hist_mLL1_Other -> GetBinContent( hist_mLL1_Other -> GetNbinsX()) + hist_mLL1_Other -> GetBinContent( hist_mLL1_Other -> GetNbinsX() + 1));
        hist_mLL2_Other -> SetBinContent( hist_mLL2_Other -> GetNbinsX(), hist_mLL2_Other -> GetBinContent( hist_mLL2_Other -> GetNbinsX()) + hist_mLL2_Other -> GetBinContent( hist_mLL2_Other -> GetNbinsX() + 1));
        hist_Njets_Other -> SetBinContent( hist_Njets_Other -> GetNbinsX(), hist_Njets_Other -> GetBinContent( hist_Njets_Other -> GetNbinsX()) + hist_Njets_Other -> GetBinContent( hist_Njets_Other -> GetNbinsX() + 1));
        

  // LEYENDA DE LOS HISTOGRAMAS

    auto legend_eta = new TLegend (0.75, 0.65, 0.85, 0.85);
    legend_eta -> AddEntry (hist_eta_Data," #bf{Data}","lep");
    legend_eta -> AddEntry (hist_eta_Higgs," #bf{Higgs}","f");
    legend_eta -> AddEntry (hist_eta_ZZ," #bf{ZZ}","f");
    legend_eta -> AddEntry (hist_eta_Other," #bf{Other}","f");
    legend_eta -> SetBorderSize(0);

    auto legend_phi = new TLegend (0.75, 0.65, 0.85, 0.85);
    legend_phi -> AddEntry (hist_phi_Data," #bf{Data}","lep");
    legend_phi -> AddEntry (hist_phi_Higgs," #bf{Higgs}","f");
    legend_phi -> AddEntry (hist_phi_ZZ," #bf{ZZ}","f");
    legend_phi -> AddEntry (hist_phi_Other," #bf{Other}","f");
    legend_phi -> SetBorderSize(0);

    auto legend_pt = new TLegend (0.75, 0.65, 0.85, 0.85);
    legend_pt -> AddEntry (hist_pt_Data," #bf{Data}","lep");
    legend_pt -> AddEntry (hist_pt_Higgs," #bf{Higgs}","f");
    legend_pt -> AddEntry (hist_pt_ZZ," #bf{ZZ}","f");
    legend_pt -> AddEntry (hist_pt_Other," #bf{Other}","f");
    legend_pt -> SetBorderSize(0);

    auto legend_E = new TLegend (0.75, 0.65, 0.85, 0.85);
    legend_E -> AddEntry (hist_E_Data," #bf{Data}","lep");
    legend_E -> AddEntry (hist_E_Higgs," #bf{Higgs}","f");
    legend_E -> AddEntry (hist_E_ZZ," #bf{ZZ}","f");
    legend_E -> AddEntry (hist_E_Other," #bf{Other}","f");
    legend_E -> SetBorderSize(0);

    auto legend_mLL1 = new TLegend (0.80, 0.65, 0.90, 0.85);
    legend_mLL1 -> AddEntry (hist_mLL1_Data," #bf{Data}","lep");
    legend_mLL1 -> AddEntry (hist_mLL1_Higgs," #bf{Higgs}","f");
    legend_mLL1 -> AddEntry (hist_mLL1_ZZ," #bf{ZZ}","f");
    legend_mLL1 -> AddEntry (hist_mLL1_Other," #bf{Other}","f");
    legend_mLL1 -> SetBorderSize(0);

    auto legend_mLL2 = new TLegend (0.75, 0.65, 0.85, 0.85);
    legend_mLL2 -> AddEntry (hist_mLL2_Data," #bf{Data}","lep");
    legend_mLL2 -> AddEntry (hist_mLL2_Higgs," #bf{Higgs}","f");
    legend_mLL2 -> AddEntry (hist_mLL2_ZZ," #bf{ZZ}","f");
    legend_mLL2 -> AddEntry (hist_mLL2_Other," #bf{Other}","f");
    legend_mLL2 -> SetBorderSize(0);

    auto legend_Njets = new TLegend (0.75, 0.65, 0.85, 0.85);
    legend_Njets -> AddEntry (hist_Njets_Data," #bf{Data}","lep");
    legend_Njets -> AddEntry (hist_Njets_Higgs," #bf{Higgs}","f");
    legend_Njets -> AddEntry (hist_Njets_ZZ," #bf{ZZ}","f");
    legend_Njets -> AddEntry (hist_Njets_Other," #bf{Other}","f");
    legend_Njets -> SetBorderSize(0);

    auto legend_mass = new TLegend (0.75, 0.65, 0.85, 0.85);
    legend_mass -> AddEntry (hist_mass_Data," #bf{Data}","lep");
    legend_mass -> AddEntry (hist_mass_Higgs," #bf{Higgs}","f");
    legend_mass -> AddEntry (hist_mass_ZZ," #bf{ZZ}","f");
    legend_mass -> AddEntry (hist_mass_Other," #bf{Other}","f");
    legend_mass -> SetBorderSize(0);


  // TEXTO #sqrt{13} = TeV, 10 fb^{-1} Y H -> ZZ* -> 4l

    auto *pt_s = new TLegend ( 0.15, 0.80, 0.50, 0.85 );
    pt_s -> SetHeader ( "#bf{#sqrt{s} = 13 TeV, 10 fb^{-1}}" );
    pt_s -> SetBorderSize(0);

    auto *pt_HZZ = new TLegend ( 0.15, 0.75, 0.50, 0.80 );
    pt_HZZ -> SetHeader ( "#bf{H #rightarrow ZZ* #rightarrow 4l}" );
    pt_HZZ -> SetBorderSize(0);

    auto *pt_s_2 = new TLegend ( 0.30, 0.80, 0.65, 0.85 );
    pt_s_2 -> SetHeader ( "#bf{#sqrt{s} = 13 TeV, 10 fb^{-1}}" );
    pt_s_2 -> SetBorderSize(0);

    auto *pt_HZZ_2 = new TLegend ( 0.30, 0.75, 0.65, 0.80 );
    pt_HZZ_2 -> SetHeader ( "#bf{H #rightarrow ZZ* #rightarrow 4l}" );
    pt_HZZ_2 -> SetBorderSize(0);

    auto *pt_s_Njets = new TLegend ( 0.35, 0.80, 0.65, 0.85 );
    pt_s_Njets -> SetHeader ( "#bf{#sqrt{s} = 13 TeV, 10 fb^{-1}}" );
    pt_s_Njets -> SetBorderSize(0);

    auto *pt_HZZ_Njets = new TLegend ( 0.35, 0.75, 0.65, 0.80 );
    pt_HZZ_Njets -> SetHeader ( "#bf{H #rightarrow ZZ* #rightarrow 4l}" );
    pt_HZZ_Njets -> SetBorderSize(0);


  // LÍNEAS PARA EL RATIO PLOT

    TLine *l_eta = new TLine ( -3, 1, 3, 1 );
    l_eta -> SetLineColor (kRed);

    TLine *l_phi = new TLine ( -3.2, 1, 3.2, 1 );
    l_phi -> SetLineColor (kRed);

    TLine *l_pt = new TLine ( 0, 1, 200, 1 );
    l_pt -> SetLineColor (kRed);

    TLine *l_E = new TLine ( 0, 1, 300, 1 );
    l_E -> SetLineColor (kRed);

    TLine *l_mLL1 = new TLine ( 50, 1, 106, 1 );
    l_mLL1 -> SetLineColor (kRed);

    TLine *l_mLL2 = new TLine ( 12, 1, 140, 1 );
    l_mLL2 -> SetLineColor (kRed);

    TLine *l_Njets = new TLine ( -0.5, 1, 3.5, 1 );
    l_Njets -> SetLineColor (kRed);

    TLine *l_mass = new TLine ( 80, 1, 170, 1 );
    l_mass -> SetLineColor (kRed);


  // DIBUJAR HISTOGRAMAS

    // MASS

        TCanvas *cs_mass = new TCanvas("cs_mass","cs_mass",10,10,900,600);
        TPad *pad1_mass = new TPad("pad1_mass", "pad1_mass", 0, 0.27, 1, 1);
        THStack *hs_mass = new THStack ("hs_mass", "Mass of four-lepton system; m_{4l} [GeV]; Events / bin");

        pad1_mass -> SetTopMargin (0.1);
        pad1_mass -> SetBottomMargin (0);
        pad1_mass -> SetLeftMargin (0.1);

        hs_mass -> Add (hist_mass_Other);   
        hs_mass -> Add (hist_mass_ZZ);
        hs_mass-> Add (hist_mass_Higgs);

        pad1_mass -> Draw ();
        pad1_mass -> cd ();
        hs_mass -> Draw ("histo");
        hist_mass_Data -> DrawCopy ("e1,same");
        legend_mass -> Draw ();
        pt_s_2 -> Draw ();
        pt_HZZ_2 -> Draw ();

        hs_mass -> SetMinimum (0.01);
        hs_mass -> SetMaximum (27);
        hs_mass -> GetYaxis () -> SetTitleOffset (0.75);

        cs_mass -> cd ();

        TPad *pad2_mass = new TPad("pad2_mass", "pad2_mass", 0, 0, 1, 0.27);
        pad2_mass -> SetTopMargin (0);
        pad2_mass -> SetBottomMargin (0.40);
        pad2_mass -> SetLeftMargin (0.1);

        pad2_mass -> Draw ();
        pad2_mass -> cd ();
        hist_mass_Data -> Sumw2 ();
        hist_mass_Data -> SetStats (0);
        hist_mass_Data -> Divide (hist_mass);
        hist_mass_Data -> Draw ("e1,p");
        l_mass -> Draw ();

        hist_mass_Data -> SetMaximum (1.99);
        hist_mass_Data -> SetMinimum (0.01);
        hist_mass_Data -> GetYaxis () -> SetNdivisions (4, 1, 0, kTRUE);

        cs_mass -> cd ();


    // N JETS

        TCanvas *cs_Njets = new TCanvas("cs_Njets","cs_Njets",10,10,900,600);
        TPad *pad1_Njets = new TPad("pad1_Njets", "pad1_Njets", 0, 0.27, 1, 1);
        THStack *hs_Njets = new THStack ("hs_Njets", "Number of Jets; N_{jets}; Events");
        
        pad1_Njets -> SetTopMargin (0.1);
        pad1_Njets -> SetBottomMargin (0);
        pad1_Njets -> SetLeftMargin (0.1);

        hs_Njets -> Add (hist_Njets_Other);   
        hs_Njets -> Add (hist_Njets_ZZ);
        hs_Njets-> Add (hist_Njets_Higgs);

        pad1_Njets -> Draw ();
        pad1_Njets -> cd ();
        hs_Njets -> Draw ("histo");
        hist_Njets_Data -> DrawCopy ("e1,same");
        legend_Njets -> Draw ();
        pt_s_2 -> Draw ();
        pt_HZZ_2 -> Draw ();

        hs_Njets -> SetMinimum (0.01);
        hs_Njets -> SetMaximum (220);
        hs_Njets -> GetYaxis () -> SetTitleOffset (0.75);

        cs_Njets -> cd ();

        TPad *pad2_Njets = new TPad("pad2_Njets", "pad2_Njets", 0, 0, 1, 0.27);
        pad2_Njets -> SetTopMargin (0);
        pad2_Njets -> SetBottomMargin (0.40);
        pad2_Njets -> SetLeftMargin (0.1);

        pad2_Njets -> Draw ();
        pad2_Njets -> cd ();
        hist_Njets_Data -> Sumw2 ();
        hist_Njets_Data -> SetStats (0);
        hist_Njets_Data -> Divide (hist_Njets);
        hist_Njets_Data -> Draw ("e1,p");
        l_Njets -> Draw ();

        hist_Njets_Data -> SetMaximum (1.99);
        hist_Njets_Data -> SetMinimum (0.01);
        hist_Njets_Data -> GetYaxis () -> SetNdivisions (4, 1, 0, kTRUE);

        cs_Njets -> cd ();


    // MLL2

        TCanvas *cs_mLL2 = new TCanvas("cs_mLL2","cs_mLL2",10,10,900,600);
        TPad *pad1_mLL2 = new TPad("pad1_mLL2", "pad1_mLL2", 0, 0.27, 1, 1);
        THStack *hs_mLL2 = new THStack ("hs_mLL2", "Mass of Dilepton System; m_{ll,2} [GeV]; Events / bin");

        pad1_mLL2 -> SetTopMargin (0.1);
        pad1_mLL2 -> SetBottomMargin (0);
        pad1_mLL2 -> SetLeftMargin (0.1);

        hs_mLL2 -> Add (hist_mLL2_Other);   
        hs_mLL2 -> Add (hist_mLL2_ZZ);
        hs_mLL2-> Add (hist_mLL2_Higgs);

        pad1_mLL2 -> Draw ();
        pad1_mLL2 -> cd ();
        hs_mLL2 -> Draw ("histo");
        hist_mLL2_Data -> DrawCopy ("e1,same");
        legend_mLL2 -> Draw ();
        pt_s -> Draw ();
        pt_HZZ -> Draw ();

        hs_mLL2 -> SetMinimum (0.01);
        hs_mLL2 -> SetMaximum (70);
        hs_mLL2 -> GetYaxis () -> SetTitleOffset (0.75);

        cs_mLL2 -> cd ();

        TPad *pad2_mLL2 = new TPad("pad2_mLL2", "pad2_mLL2", 0, 0, 1, 0.27);
        pad2_mLL2 -> SetTopMargin (0);
        pad2_mLL2 -> SetBottomMargin (0.40);
        pad2_mLL2 -> SetLeftMargin (0.1);

        pad2_mLL2 -> Draw ();
        pad2_mLL2 -> cd ();
        hist_mLL2_Data -> Sumw2 ();
        hist_mLL2_Data -> SetStats (0);
        hist_mLL2_Data -> Divide (hist_mLL2);
        hist_mLL2_Data -> Draw ("e1,p");
        l_mLL2 -> Draw ();

        hist_mLL2_Data -> SetMaximum (1.99);
        hist_mLL2_Data -> SetMinimum (0.01);
        hist_mLL2_Data -> GetYaxis () -> SetNdivisions (4, 1, 0, kTRUE);

        cs_mLL2 -> cd ();


    // MLL1

        TCanvas *cs_mLL1 = new TCanvas("cs_mLL1","cs_mLL1",10,10,900,600);
        TPad *pad1_mLL1 = new TPad("pad1_mLL1", "pad1_mLL1", 0, 0.27, 1, 1);
        THStack *hs_mLL1 = new THStack ("hs_mLL1", "Mass of Dilepton System; m_{ll,1} [GeV]; Events / bin");

        pad1_mLL1 -> SetTopMargin (0.1);
        pad1_mLL1 -> SetBottomMargin (0);
        pad1_mLL1 -> SetLeftMargin (0.1);

        hs_mLL1 -> Add (hist_mLL1_Other);   
        hs_mLL1 -> Add (hist_mLL1_ZZ);
        hs_mLL1-> Add (hist_mLL1_Higgs);

        pad1_mLL1 -> Draw ();
        pad1_mLL1 -> cd ();
        hs_mLL1 -> Draw ("histo");
        hist_mLL1_Data -> DrawCopy ("e1,same");
        legend_mLL1 -> Draw ();
        pt_s -> Draw ();
        pt_HZZ -> Draw ();

        hs_mLL1 -> SetMinimum (0.01);
        hs_mLL1 -> SetMaximum (80);
        hs_mLL1 -> GetYaxis () -> SetTitleOffset (0.75);

        cs_mLL1 -> cd ();

        TPad *pad2_mLL1 = new TPad("pad2_mLL1", "pad2_mLL1", 0, 0, 1, 0.27);
        pad2_mLL1 -> SetTopMargin (0);
        pad2_mLL1 -> SetBottomMargin (0.40);
        pad2_mLL1 -> SetLeftMargin (0.1);

        pad2_mLL1 -> Draw ();
        pad2_mLL1 -> cd ();
        hist_mLL1_Data -> Sumw2 ();
        hist_mLL1_Data -> SetStats (0);
        hist_mLL1_Data -> Divide (hist_mLL1);
        hist_mLL1_Data -> Draw ("e1,p");
        l_mLL1 -> Draw ();

        hist_mLL1_Data -> SetMaximum (1.99);
        hist_mLL1_Data -> SetMinimum (0.01);
        hist_mLL1_Data -> GetYaxis () -> SetNdivisions (4, 1, 0, kTRUE);

        cs_mLL1 -> cd ();


    // E

        TCanvas *cs_E = new TCanvas("cs_E","cs_E",10,10,900,600);
        TPad *pad1_E = new TPad("pad1_E", "pad1_E", 0, 0.27, 1, 1);
        THStack *hs_E = new THStack ("hs_E", "Leptons Energy; E^{all lep} [GeV]; Leptons / bin");

        pad1_E -> SetTopMargin (0.1);
        pad1_E -> SetBottomMargin (0);
        pad1_E -> SetLeftMargin (0.1);

        hs_E -> Add (hist_E_Other);   
        hs_E -> Add (hist_E_ZZ);
        hs_E -> Add (hist_E_Higgs);

        pad1_E -> Draw ();
        pad1_E -> cd ();
        hs_E -> Draw ("histo");
        hist_E_Data -> DrawCopy ("e1,same");
        legend_E -> Draw ();
        pt_s_2 -> Draw ();
        pt_HZZ_2 -> Draw ();

        hs_E -> SetMinimum (0.01);
        hs_E -> SetMaximum (400);
        hs_E -> GetYaxis () -> SetTitleOffset (0.75);

        cs_E -> cd ();

        TPad *pad2_E = new TPad("pad2_E", "pad2_E", 0, 0, 1, 0.27);
        pad2_E -> SetTopMargin (0);
        pad2_E -> SetBottomMargin (0.40);
        pad2_E -> SetLeftMargin (0.1);

        pad2_E -> Draw ();
        pad2_E -> cd ();
        hist_E_Data -> Sumw2 ();
        hist_E_Data -> SetStats (0);
        hist_E_Data -> Divide (hist_E);
        hist_E_Data -> Draw ("e1,p");
        l_E -> Draw ();

        hist_E_Data -> SetMaximum (1.99);
        hist_E_Data -> SetMinimum (0.01);
        hist_E_Data -> GetYaxis () -> SetNdivisions (4, 1, 0, kTRUE);

        cs_E -> cd ();


    // PT

        TCanvas *cs_pt = new TCanvas("cs_pt","cs_pt",10,10,900,600);
        TPad *pad1_pt = new TPad("pad1_pt", "pad1_pt", 0, 0.27, 1, 1);
        THStack *hs_pt = new THStack ("hs_pt", "Leptons Transverse Momentum; p_{T}^{all lep} [GeV]; Leptons / bin");

        pad1_pt -> SetTopMargin (0.1);
        pad1_pt -> SetBottomMargin (0);
        pad1_pt -> SetLeftMargin (0.1);

        hs_pt -> Add (hist_pt_Other);   
        hs_pt -> Add (hist_pt_ZZ);
        hs_pt -> Add (hist_pt_Higgs);

        pad1_pt -> Draw ();
        pad1_pt -> cd ();
        hs_pt -> Draw ("histo");
        hist_pt_Data -> DrawCopy ("e1,same");
        legend_pt -> Draw ();
        pt_s_2 -> Draw ();
        pt_HZZ_2 -> Draw ();

        hs_pt -> SetMinimum (0.01);
        hs_pt -> SetMaximum (720);
        hs_pt -> GetYaxis () -> SetTitleOffset (0.75);

        cs_pt -> cd ();

        TPad *pad2_pt = new TPad("pad2_pt", "pad2_pt", 0, 0, 1, 0.27);
        pad2_pt -> SetTopMargin (0);
        pad2_pt -> SetBottomMargin (0.40);
        pad2_pt -> SetLeftMargin (0.1);

        pad2_pt -> Draw ();
        pad2_pt -> cd ();
        hist_pt_Data -> Sumw2 ();
        hist_pt_Data -> SetStats (0);
        hist_pt_Data -> Divide (hist_pt);
        hist_pt_Data -> Draw ("e1,p");
        l_pt -> Draw ();

        hist_pt_Data -> SetMaximum (1.99);
        hist_pt_Data -> SetMinimum (0.01);
        hist_pt_Data -> GetYaxis () -> SetNdivisions (4, 1, 0, kTRUE);

        cs_pt -> cd ();


    // PHI

        TCanvas *cs_phi = new TCanvas("cs_phi","cs_phi",10,10,900,600);
        TPad *pad1_phi = new TPad("pad1_phi", "pad1_phi", 0, 0.27, 1, 1);
        THStack *hs_phi = new THStack ("hs_phi", "Leptons Azimuthal Angle; #phi^{all lep}; Leptons / bin");

        pad1_phi -> SetTopMargin (0.1);
        pad1_phi -> SetBottomMargin (0);
        pad1_phi -> SetLeftMargin (0.1);

        hs_phi -> Add (hist_phi_Other);   
        hs_phi -> Add (hist_phi_ZZ);
        hs_phi -> Add (hist_phi_Higgs);

        pad1_phi -> Draw ();
        pad1_phi -> cd ();
        hs_phi -> Draw ("histo");
        hist_phi_Data -> DrawCopy ("e1,same");
        legend_phi -> Draw ();
        pt_s -> Draw ();
        pt_HZZ -> Draw ();

        hs_phi -> SetMinimum (0.01);
        hs_phi -> SetMaximum (280);
        hs_phi -> GetYaxis () -> SetTitleOffset (0.75);

        cs_phi -> cd ();

        TPad *pad2_phi = new TPad("pad2_phi", "pad2_phi", 0, 0, 1, 0.27);
        pad2_phi -> SetTopMargin (0);
        pad2_phi -> SetBottomMargin (0.40);
        pad2_phi -> SetLeftMargin (0.1);

        pad2_phi -> Draw ();
        pad2_phi -> cd ();
        hist_phi_Data -> Sumw2 ();
        hist_phi_Data -> SetStats (0);
        hist_phi_Data -> Divide (hist_phi);
        hist_phi_Data -> Draw ("e1,p");
        l_phi -> Draw ();

        hist_phi_Data -> SetMaximum (1.99);
        hist_phi_Data -> SetMinimum (0.01);
        hist_phi_Data -> GetYaxis () -> SetNdivisions (4, 1, 0, kTRUE);

        cs_phi -> cd ();


    // ETA

        TCanvas *cs_eta = new TCanvas("cs_eta","cs_eta",10,10,900,600);
        TPad *pad1_eta = new TPad("pad1_eta", "pad1_phi", 0, 0.27, 1, 1);
        THStack *hs_eta = new THStack ("hs_eta", "Leptons Pseudorapidity; #eta^{all lep}; Leptons / bin");

        pad1_eta -> SetTopMargin (0.1);
        pad1_eta -> SetBottomMargin (0);
        pad1_eta -> SetLeftMargin (0.1);

        hs_eta -> Add (hist_eta_Other);   
        hs_eta -> Add (hist_eta_ZZ);
        hs_eta -> Add (hist_eta_Higgs);

        pad1_eta -> Draw ();
        pad1_eta -> cd ();
        hs_eta -> Draw ("histo");
        hist_eta_Data -> DrawCopy ("e1,same");
        legend_eta -> Draw ();
        pt_s -> Draw ();
        pt_HZZ -> Draw ();

        hs_eta -> SetMinimum (0.01);
        hs_eta -> SetMaximum (275);
        hs_eta -> GetYaxis () -> SetTitleOffset (0.75);

        cs_eta -> cd ();

        TPad *pad2_eta = new TPad("pad2_eta", "pad2_eta", 0, 0, 1, 0.27);
        pad2_eta -> SetTopMargin (0);
        pad2_eta -> SetBottomMargin (0.40);
        pad2_eta -> SetLeftMargin (0.1);

        pad2_eta -> Draw ();
        pad2_eta -> cd ();
        hist_eta_Data -> Sumw2 ();
        hist_eta_Data -> SetStats (0);
        hist_eta_Data -> Divide (hist_eta);
        hist_eta_Data -> Draw ("e1,p");
        l_eta -> Draw ();

        hist_eta_Data -> SetMaximum (1.99);
        hist_eta_Data -> SetMinimum (0.01);
        hist_eta_Data -> GetYaxis () -> SetNdivisions (4, 1, 0, kTRUE);

        cs_eta -> cd ();


    // GUARDAR LOS PLOTS EN EL DIRECTORIO DONDE SE ENCUENTRA EL CÓDIGO

        std::cout << " " << std::endl;

        cs_eta -> SaveAs ("HZZ_eta.png");
        cs_phi -> SaveAs ("HZZ_phi.png");
        cs_pt -> SaveAs ("HZZ_pt.png");
        cs_E -> SaveAs ("HZZ_E.png");
        cs_mLL1 -> SaveAs ("HZZ_mLL1.png");
        cs_mLL2 -> SaveAs ("HZZ_mLL2.png");
        cs_Njets -> SaveAs ("HZZ_Njets.png");
        cs_mass -> SaveAs ("HZZ_mass.png");


  t1 = clock ();

  float time = ( float (t1 - t0) / CLOCKS_PER_SEC ) / 60;        // Tiempo de ejecución en minutos

  std::cout << " " << std::endl;
  std::cout << "Tiempo de ejecución: " << time << " minutos." << std::endl;


  return;

}
