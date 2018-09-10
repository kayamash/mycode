#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>
#include <sstream>
#include <TF1.h>
#include <TTree.h>
#include <TStyle.h>
#include <TText.h>
#include <vector>
#include <TGraphErrors.h>
#include <TLegend.h>
#include <TMath.h>
//#include <direct.h>

 void draw_histgram(TH1D *h1,string title){}

 void draw_resolution(TH1D *h1,string title,Double_t width){}

 void draw_histgram(TH2F *h1,string title){}

 void draw_pt_distribution(TH1D *h1,TH1D *h2,TH1D *h3,TH1D *h4,TH1D *h5,string label1,string label2,string label3,string label4,string label5,string title_axis,string title){}

 void draw_invariant_mass_distribution(TH1D *h1,TH1D *h2,TH1D *h3,TH1D *h4,TH1D *h5,string title){}

 void draw_efficiency(TH1D *h1,TH1D *h2,string title_axis,string title,Int_t max){}

 void draw_efficiency(TH1D *h1,TH1D *h2,string title_axis,string title){}

 void draw_efficiency(TH1D *h1,TH1D *h2,TH1D *h3,TH1D *h4,string title_axis,string title,Int_t max){}

 void draw_efficiency(TH1D *h1,TH1D *h2,TH1D *h3,TH1D *h4,TH1D *h5,TH1D *h6,TH1D *h7,TH1D *h8,TH1D *h9,TH1D *h10,string title_axis,string title,Int_t max){}

 void efficiency(const string name,const Int_t threshold_SA,const Int_t max,TFile *output_file){}

//main loop
 void efficiency_loop(){
  std::cout<<"start!"<<std::endl;
  TFile *output_file = new TFile("../output/plot.root","RECREATE");
  for(Int_t i = 0;i < 24;i += 4){
   std::cout<<"mu26ivm"<<"   "<<i<<std::endl;
   efficiency("mu26ivm",i,60,output_file);
  }
  efficiency("mu26ivm",26,60,output_file);
  for(Int_t i = 0;i < 55;i += 5){
   std::cout<<"mu50"<<"   "<<i<<std::endl;
   efficiency("mu50",i,80,output_file);
  }
 }

 void efficiency(const string name,const Int_t threshold_SA,const Int_t max,TFile *output_file){
  TFile *tf1 = TFile::Open("../src/Zmumu.root","read");
  TTree *tr1 = dynamic_cast<TTree*>(tf1->Get("t_tap"));
  TH2F *h_probe_mesSA_pt = new TH2F("probe_mesSA_pt","probe_pt vs probe_mesSA_pt@mu26ivm;probe_pt[GeV];probe_mesSA_pt[GeV]",150,0,150,150,0,150);
  TH2F *h_tag_SA_pt = new TH2F("tag_SA_pt","tag_pt vs tag_SA_pt;tag_SA_pt;tag_pt",150,0,150,150,0,150000);
  TH2F *h_probe_eta_pt = new TH2F("probe_eta_pt","probe_eta vs probe_pt;probe_eta;probe_pt[GeV]",500,-2.5,2.5,500,0,100);

  TH1D *h_probe_SA_inverse_residual_pt = new TH1D("probe_SA_inverse_residual_pt","probe_SA_residual_pt;1/#Delta pt;Entries",400,-200,200);
  TH1D *h_probe_SA_residual_pt = new TH1D("probe_SA_residual_pt","probe_SA_residual_pt;#Delta pt;Entries",300,-1,1);
  TH1D *h_probe_CB_residual_pt = new TH1D("probe_CB_residual_pt","probe_CB_residual_pt;#Delta pt;Entries",640,-0.8,0.8);
  TH1D *h_probe_EF_residual_pt = new TH1D("probe_EF_residual_pt","probe_EF_residual_pt;#Delta pt;Entries",1800,-0.3,0.3);
  TH1D *h_probe_SA_residual_pt_30 = new TH1D("probe_SA_residual_pt_30","probe_SA_residual_pt;#Delta pt;Entries",300,-1,1);
  TH1D *h_probe_CB_residual_pt_30 = new TH1D("probe_CB_residual_pt_30","probe_CB_residual_pt;#Delta pt;Entries",640,-0.8,0.8);
  TH1D *h_probe_EF_residual_pt_30 = new TH1D("probe_EF_residual_pt_30","probe_EF_residual_pt;#Delta pt;Entries",1800,-0.3,0.3);
  TH1D *h_probe_pt = new TH1D("probe_offline_pt","probe_offline_pt;offline pt[GeV];Entries",150,0,150);
  TH1D *h_mesL1_pt = new TH1D("mesL1_pt","mesL1_pt;L1 pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_L1_pt = new TH1D("off_L1_pt","mesL1_pt;L1 pt[GeV];Entries",150,0,150);
  TH1D *h_mesSA_pt = new TH1D("mesSA_pt","mesSA_pt;SA pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_SA_pt = new TH1D("off_SA_pt","mesSA_pt;SA pt[GeV];Entries",150,0,150);
  TH1D *h_eff_L1_SA_pt = new TH1D("L1_SA_pt","mesSA_pt;SA pt[GeV];Entries",150,0,150);
  TH1D *h_mesCB_pt = new TH1D("mesCB_pt","mesCB_pt;CB pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_CB_pt = new TH1D("off_CB_pt","mesCB_pt;CB pt[GeV];Entries",150,0,150);
  TH1D *h_eff_SA_CB_pt = new TH1D("SA_CB_pt","mesCB_pt;CB pt[GeV];Entries",150,0,150);
  TH1D *h_mesEF_pt = new TH1D("mesEF_pt","mesEF_pt;EF pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_EF_pt = new TH1D("off_EF_pt","mesEF_pt;EF pt[GeV];Entries",150,0,150);
  TH1D *h_eff_CB_EF_pt = new TH1D("CB_EF_pt","mesEF_pt;EF pt[GeV];Entries",150,0,150);
  TH1D *h_probe_eta = new TH1D("probe_offline_eta","probe_offline_eta;offline eta;Entries",50,-2.5,2.5);
  TH1D *h_eff_L1_SA_eta = new TH1D("L1_SA_eta","mesSA_eta;SA eta;Entries",50,-2.5,2.5);
  TH1D *h_eff_SA_CB_eta = new TH1D("SA_CB_eta","mesCB_eta;CB eta;Entries",50,-2.5,2.5);
  TH1D *h_eff_CB_EF_eta = new TH1D("CB_EF_eta","mesCB_eta;EF eta;Entries",50,-2.5,2.5);
  TH1D *h_probe_eta_30 = new TH1D("probe_offline_eta_30","probe_offline_eta;offline eta;Entries",50,-2.5,2.5);
  TH1D *h_eff_L1_SA_eta_30 = new TH1D("L1_SA_eta_30","mesSA_eta;SA eta;Entries",50,-2.5,2.5);
  TH1D *h_eff_SA_CB_eta_30 = new TH1D("SA_CB_eta_30","mesCB_eta;CB eta;Entries",50,-2.5,2.5);
  TH1D *h_eff_CB_EF_eta_30 = new TH1D("CB_EF_eta_30","mesCB_eta;EF eta;Entries",50,-2.5,2.5);
  TH1D *z_invariant_mass = new TH1D("z_invariant_mass","z_invariant_mass",800,0,200);
  TH1D *z_invariant_mass_L1 = new TH1D("z_invariant_mass_L1","z_invariant_mass_L1",800,0,200);
  TH1D *z_invariant_mass_SA = new TH1D("z_invariant_mass_SA","z_invariant_mass_SA",800,0,200);
  TH1D *z_invariant_mass_CB = new TH1D("z_invariant_mass_CB","z_invariant_mass_CB",800,0,200);
  TH1D *z_invariant_mass_EF = new TH1D("z_invariant_mass_EF","z_invariant_mass_EF",800,0,200);

  TH1D *h_eff_off_L1_pt_1 = new TH1D("off_L1_pt_1","mesL1_pt;L1 pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_SA_pt_1 = new TH1D("off_SA_pt_1","mesSA_pt;SA pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_CB_pt_1 = new TH1D("off_CB_pt_1","mesCB_pt;CB pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_EF_pt_1 = new TH1D("off_EF_pt_1","mesEF_pt;EF pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_L1_pt_2 = new TH1D("off_L1_pt_2","mesL1_pt;L1 pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_SA_pt_2 = new TH1D("off_SA_pt_2","mesSA_pt;SA pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_CB_pt_2 = new TH1D("off_CB_pt_2","mesCB_pt;CB pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_EF_pt_2 = new TH1D("off_EF_pt_2","mesEF_pt;EF pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_L1_pt_3 = new TH1D("off_L1_pt_3","mesL1_pt;L1 pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_SA_pt_3 = new TH1D("off_SA_pt_3","mesSA_pt;SA pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_CB_pt_3 = new TH1D("off_CB_pt_3","mesCB_pt;CB pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_EF_pt_3 = new TH1D("off_EF_pt_3","mesEF_pt;EF pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_L1_pt_4 = new TH1D("off_L1_pt_4","mesL1_pt;L1 pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_SA_pt_4 = new TH1D("off_SA_pt_4","mesSA_pt;SA pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_CB_pt_4 = new TH1D("off_CB_pt_4","mesCB_pt;CB pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_EF_pt_4 = new TH1D("off_EF_pt_4","mesEF_pt;EF pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_L1_pt_5 = new TH1D("off_L1_pt_5","mesL1_pt;L1 pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_SA_pt_5 = new TH1D("off_SA_pt_5","mesSA_pt;SA pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_CB_pt_5 = new TH1D("off_CB_pt_5","mesCB_pt;CB pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_EF_pt_5 = new TH1D("off_EF_pt_5","mesEF_pt;EF pt[GeV];Entries",150,0,150);

  Double_t tag_pt,probe_pt,tag_eta,tag_phi,probe_eta,probe_phi,tag_charge,probe_charge;
  Double_t tag_L1_pt,tag_L1_eta,tag_L1_phi;
  Double_t tag_SA_pt,tag_SA_eta,tag_SA_phi;
  Double_t tag_CB_pt,tag_CB_eta,tag_CB_phi;
  Double_t tag_EF_pt,tag_EF_eta,tag_EF_phi;
  Double_t tp_mass;
  std::vector<string> *mes_name;
  std::vector<Double_t> *probe_mesL1_pt,*probe_mesSA_pt,*probe_mesCB_pt,*probe_mesEF_pt;
  std::vector<Double_t> *probe_mesL1_eta,*probe_mesSA_eta,*probe_mesCB_eta,*probe_mesEF_eta;
  std::vector<Double_t> *probe_mesL1_phi,*probe_mesSA_phi,*probe_mesCB_phi,*probe_mesEF_phi;
  std::vector<Double_t> *probe_mesL1_dR,*probe_mesSA_dR,*probe_mesCB_dR,*probe_mesEF_dR;
  std::vector<Int_t> *probe_mesL1_pass,*probe_mesSA_pass,*probe_mesCB_pass,*probe_mesEF_pass;
  TBranch *b_mes_name,*b_probe_mesL1_pt,*b_probe_mesSA_pt,*b_probe_mesCB_pt,*b_probe_mesEF_pt,*b_probe_mesL1_pass,*b_probe_mesSA_pass,*b_probe_mesCB_pass,*b_probe_mesEF_pass;
  TBranch *b_probe_mesL1_eta,*b_probe_mesSA_eta,*b_probe_mesCB_eta,*b_probe_mesEF_eta;
  TBranch *b_probe_mesL1_phi,*b_probe_mesSA_phi,*b_probe_mesCB_phi,*b_probe_mesEF_phi;
  TBranch *b_probe_mesL1_dR,*b_probe_mesSA_dR,*b_probe_mesCB_dR,*b_probe_mesEF_dR;

  tr1->SetBranchStatus("*",0);
  tr1->SetBranchStatus("mes_name",1);
  tr1->SetBranchStatus("tag_pt",1);
  tr1->SetBranchStatus("tag_eta",1);
  tr1->SetBranchStatus("tag_phi",1);
  tr1->SetBranchStatus("tp_mass",1);
  tr1->SetBranchStatus("tag_charge",1);
  tr1->SetBranchStatus("tag_L1_pt",1);
  tr1->SetBranchStatus("tag_L1_eta",1);
  tr1->SetBranchStatus("tag_L1_phi",1);
  tr1->SetBranchStatus("tag_SA_pt",1);
  tr1->SetBranchStatus("tag_SA_eta",1);
  tr1->SetBranchStatus("tag_SA_phi",1);
  tr1->SetBranchStatus("tag_CB_pt",1);
  tr1->SetBranchStatus("tag_CB_eta",1);
  tr1->SetBranchStatus("tag_CB_phi",1);
  tr1->SetBranchStatus("tag_EF_pt",1);
  tr1->SetBranchStatus("tag_EF_eta",1);
  tr1->SetBranchStatus("tag_EF_phi",1);
  tr1->SetBranchStatus("probe_pt",1);
  tr1->SetBranchStatus("probe_eta",1);
  tr1->SetBranchStatus("probe_phi",1);
  tr1->SetBranchStatus("probe_charge",1);
  tr1->SetBranchStatus("probe_mesL1_pt",1);
  tr1->SetBranchStatus("probe_mesL1_eta",1);
  tr1->SetBranchStatus("probe_mesL1_phi",1);
  tr1->SetBranchStatus("probe_mesSA_pt",1);
  tr1->SetBranchStatus("probe_mesSA_eta",1);
  tr1->SetBranchStatus("probe_mesSA_phi",1);
  tr1->SetBranchStatus("probe_mesCB_pt",1);
  tr1->SetBranchStatus("probe_mesCB_eta",1);
  tr1->SetBranchStatus("probe_mesCB_phi",1);
  tr1->SetBranchStatus("probe_mesEF_pt",1);
  tr1->SetBranchStatus("probe_mesEF_eta",1);
  tr1->SetBranchStatus("probe_mesEF_phi",1);
  tr1->SetBranchStatus("probe_mesL1_pass",1);
  tr1->SetBranchStatus("probe_mesSA_pass",1);
  tr1->SetBranchStatus("probe_mesCB_pass",1);
  tr1->SetBranchStatus("probe_mesEF_pass",1);
  tr1->SetBranchStatus("probe_mesL1_dR",1);
  tr1->SetBranchStatus("probe_mesSA_dR",1);
  tr1->SetBranchStatus("probe_mesCB_dR",1);
  tr1->SetBranchStatus("probe_mesEF_dR",1);

  tr1->SetBranchAddress("mes_name",&mes_name,&b_mes_name);
  tr1->SetBranchAddress("tag_pt",&tag_pt);
  tr1->SetBranchAddress("tp_mass",&tp_mass);
  tr1->SetBranchAddress("tag_eta",&tag_eta);
  tr1->SetBranchAddress("tag_phi",&tag_phi);
  tr1->SetBranchAddress("tag_charge",&tag_charge);
  tr1->SetBranchAddress("tag_L1_pt",&tag_L1_pt);
  tr1->SetBranchAddress("tag_L1_eta",&tag_L1_eta);
  tr1->SetBranchAddress("tag_L1_phi",&tag_L1_phi);
  tr1->SetBranchAddress("tag_SA_pt",&tag_SA_pt);
  tr1->SetBranchAddress("tag_SA_eta",&tag_SA_eta);
  tr1->SetBranchAddress("tag_SA_phi",&tag_SA_phi);
  tr1->SetBranchAddress("tag_CB_pt",&tag_CB_pt);
  tr1->SetBranchAddress("tag_CB_eta",&tag_CB_eta);
  tr1->SetBranchAddress("tag_CB_phi",&tag_CB_phi);
  tr1->SetBranchAddress("tag_EF_pt",&tag_EF_pt);
  tr1->SetBranchAddress("tag_EF_eta",&tag_EF_eta);
  tr1->SetBranchAddress("tag_EF_phi",&tag_EF_phi);
  tr1->SetBranchAddress("probe_pt",&probe_pt);
  tr1->SetBranchAddress("probe_eta",&probe_eta);
  tr1->SetBranchAddress("probe_phi",&probe_phi);
  tr1->SetBranchAddress("probe_charge",&probe_charge);
  tr1->SetBranchAddress("probe_mesL1_pt",&probe_mesL1_pt,&b_probe_mesL1_pt);
  tr1->SetBranchAddress("probe_mesSA_pt",&probe_mesSA_pt,&b_probe_mesSA_pt);
  tr1->SetBranchAddress("probe_mesCB_pt",&probe_mesCB_pt,&b_probe_mesCB_pt);
  tr1->SetBranchAddress("probe_mesEF_pt",&probe_mesEF_pt,&b_probe_mesEF_pt);
  tr1->SetBranchAddress("probe_mesL1_eta",&probe_mesL1_eta,&b_probe_mesL1_eta);
  tr1->SetBranchAddress("probe_mesSA_eta",&probe_mesSA_eta,&b_probe_mesSA_eta);
  tr1->SetBranchAddress("probe_mesCB_eta",&probe_mesCB_eta,&b_probe_mesCB_eta);
  tr1->SetBranchAddress("probe_mesEF_eta",&probe_mesEF_eta,&b_probe_mesEF_eta);
  tr1->SetBranchAddress("probe_mesL1_phi",&probe_mesL1_phi,&b_probe_mesL1_phi);
  tr1->SetBranchAddress("probe_mesSA_phi",&probe_mesSA_phi,&b_probe_mesSA_phi);
  tr1->SetBranchAddress("probe_mesCB_phi",&probe_mesCB_phi,&b_probe_mesCB_phi);
  tr1->SetBranchAddress("probe_mesEF_phi",&probe_mesEF_phi,&b_probe_mesEF_phi);
  tr1->SetBranchAddress("probe_mesL1_pass",&probe_mesL1_pass,&b_probe_mesL1_pass);
  tr1->SetBranchAddress("probe_mesSA_pass",&probe_mesSA_pass,&b_probe_mesSA_pass);
  tr1->SetBranchAddress("probe_mesCB_pass",&probe_mesCB_pass,&b_probe_mesCB_pass);
  tr1->SetBranchAddress("probe_mesEF_pass",&probe_mesEF_pass,&b_probe_mesEF_pass);
  tr1->SetBranchAddress("probe_mesL1_dR",&probe_mesL1_dR,&b_probe_mesL1_dR);
  tr1->SetBranchAddress("probe_mesSA_dR",&probe_mesSA_dR,&b_probe_mesSA_dR);
  tr1->SetBranchAddress("probe_mesCB_dR",&probe_mesCB_dR,&b_probe_mesCB_dR);
  tr1->SetBranchAddress("probe_mesEF_dR",&probe_mesEF_dR,&b_probe_mesEF_dR);

  for(Int_t event = 0;event < tr1->GetEntries();event++){
    tr1->GetEntry(event);
    Double_t buf_tag_pt = tag_pt;
    Double_t buf_tag_L1_pt = tag_L1_pt;
    Double_t buf_tag_SA_pt = tag_SA_pt;
    Double_t buf_tag_CB_pt = tag_CB_pt;
    Double_t buf_tag_EF_pt = tag_EF_pt;
    Double_t buf_tag_eta = tag_eta;
    Double_t buf_tag_L1_eta = tag_L1_eta;
    Double_t buf_tag_SA_eta = tag_SA_eta;
    Double_t buf_tag_CB_eta = tag_CB_eta;
    Double_t buf_tag_EF_eta = tag_EF_eta;
    Double_t buf_tag_phi = tag_phi;
    Double_t buf_tag_L1_phi = tag_L1_phi;
    Double_t buf_tag_SA_phi = tag_SA_phi;
    Double_t buf_tag_CB_phi = tag_CB_phi;
    Double_t buf_tag_EF_phi = tag_EF_phi;
    Double_t buf_probe_pt = probe_pt;
    Double_t buf_probe_mesL1_pt = -99999;
    Double_t buf_probe_mesSA_pt = -99999;
    Double_t buf_probe_mesCB_pt = -99999;
    Double_t buf_probe_mesEF_pt = -99999;
    Double_t buf_probe_phi = probe_phi;
    Double_t buf_probe_mesL1_phi;
    Double_t buf_probe_mesSA_phi;
    Double_t buf_probe_mesCB_phi;
    Double_t buf_probe_mesEF_phi;
    Double_t buf_probe_eta = probe_eta;
    Double_t buf_probe_mesL1_eta;
    Double_t buf_probe_mesSA_eta;
    Double_t buf_probe_mesCB_eta;
    Double_t buf_probe_mesEF_eta;
    Double_t buf_tag_charge = tag_charge;
    Double_t buf_probe_charge = probe_charge;
    Int_t buf_probe_mesL1_pass = 0;
    Int_t buf_probe_mesSA_pass = 0;
    Int_t buf_probe_mesCB_pass = 0;
    Int_t buf_probe_mesEF_pass = 0;
    for(Int_t mes = 0;mes < 25;mes++){
     if(mes_name->at(mes) == name){
      buf_probe_mesL1_pt = probe_mesL1_pt->at(mes);
      buf_probe_mesSA_pt = probe_mesSA_pt->at(mes);
      buf_probe_mesCB_pt = probe_mesCB_pt->at(mes);
      buf_probe_mesEF_pt = probe_mesEF_pt->at(mes);
      buf_probe_mesL1_eta = probe_mesL1_eta->at(mes);
      buf_probe_mesSA_eta = probe_mesSA_eta->at(mes);
      buf_probe_mesCB_eta = probe_mesCB_eta->at(mes);
      buf_probe_mesEF_eta = probe_mesEF_eta->at(mes);
      buf_probe_mesL1_phi = probe_mesL1_phi->at(mes);
      buf_probe_mesSA_phi = probe_mesSA_phi->at(mes);
      buf_probe_mesCB_phi = probe_mesCB_phi->at(mes);
      buf_probe_mesEF_phi = probe_mesEF_phi->at(mes);
      buf_probe_mesL1_pass = probe_mesL1_pass->at(mes);
      buf_probe_mesSA_pass = probe_mesSA_pass->at(mes);
      buf_probe_mesCB_pass = probe_mesCB_pass->at(mes);
      buf_probe_mesEF_pass = probe_mesEF_pass->at(mes);
     }
    }
    h_tag_SA_pt->Fill(buf_tag_SA_pt,buf_tag_pt);
    h_probe_pt->Fill(buf_probe_pt*0.001);
    z_invariant_mass->Fill(0.001*TMath::Sqrt(2.0*buf_tag_pt*buf_probe_pt*(TMath::CosH(buf_tag_eta - buf_probe_eta) - TMath::Cos(buf_tag_phi - buf_probe_phi))));
    //z_invariant_mass->Fill(0.001*tp_mass);
    h_probe_eta_pt->Fill(buf_probe_eta,buf_probe_pt*0.001);
    if(buf_probe_mesL1_pass > 0){
     h_mesL1_pt->Fill(std::fabs(buf_probe_mesL1_pt/1000.0));
     h_eff_off_L1_pt->Fill(std::fabs(buf_probe_pt*0.001));
     if(std::fabs(buf_probe_eta) <=0.5){
      h_eff_off_L1_pt_1->Fill(std::fabs(buf_probe_pt*0.001));
     }else if(std::fabs(buf_probe_eta) <=1.0){
      h_eff_off_L1_pt_2->Fill(std::fabs(buf_probe_pt*0.001));
     }else if(std::fabs(buf_probe_eta) <=1.5){
      h_eff_off_L1_pt_3->Fill(std::fabs(buf_probe_pt*0.001));
     }else if(std::fabs(buf_probe_eta) <=2.0){
      h_eff_off_L1_pt_4->Fill(std::fabs(buf_probe_pt*0.001));
     }else if(std::fabs(buf_probe_eta) <=2.5){
      h_eff_off_L1_pt_5->Fill(std::fabs(buf_probe_pt*0.001));
     }
     h_probe_eta->Fill(buf_probe_eta);
     z_invariant_mass_L1->Fill(0.001*TMath::Sqrt(2.0*buf_tag_L1_pt*buf_probe_mesL1_pt*(TMath::CosH(buf_tag_L1_eta - buf_probe_mesL1_eta) - TMath::Cos(buf_tag_L1_phi - buf_probe_mesL1_phi))));
     if(buf_probe_mesSA_pass > 0 && std::fabs(buf_probe_mesSA_pt) >= threshold_SA){
       h_probe_mesSA_pt->Fill(std::fabs(buf_probe_pt*0.001),std::fabs(buf_probe_mesSA_pt));
       h_probe_SA_inverse_residual_pt->Fill(1.0/(1.0 - std::fabs(buf_probe_pt*0.001)/std::fabs(buf_probe_mesSA_pt)));
       h_probe_SA_residual_pt->Fill(1.0 - std::fabs(buf_probe_pt*0.001)/std::fabs(buf_probe_mesSA_pt));
       h_mesSA_pt->Fill(std::fabs(buf_probe_mesSA_pt));
       h_eff_off_SA_pt->Fill(std::fabs(buf_probe_pt*0.001));
       h_eff_L1_SA_pt->Fill(std::fabs(buf_probe_pt*0.001));
       z_invariant_mass_SA->Fill(TMath::Sqrt(2.0*buf_tag_SA_pt*buf_probe_mesSA_pt*(TMath::CosH(buf_tag_SA_eta - buf_probe_mesSA_eta) - TMath::Cos(buf_tag_SA_phi - buf_probe_mesSA_phi))));
       h_eff_L1_SA_eta->Fill(buf_probe_eta);
       if(std::fabs(buf_probe_eta) <=0.5){
        h_eff_off_SA_pt_1->Fill(std::fabs(buf_probe_pt*0.001));
       }else if(std::fabs(buf_probe_eta) <=1.0){
        h_eff_off_SA_pt_2->Fill(std::fabs(buf_probe_pt*0.001));
       }else if(std::fabs(buf_probe_eta) <=1.5){
        h_eff_off_SA_pt_3->Fill(std::fabs(buf_probe_pt*0.001));
       }else if(std::fabs(buf_probe_eta) <=2.0){
        h_eff_off_SA_pt_4->Fill(std::fabs(buf_probe_pt*0.001));
       }else if(std::fabs(buf_probe_eta) <=2.5){
        h_eff_off_SA_pt_5->Fill(std::fabs(buf_probe_pt*0.001));
       }
       if(buf_probe_mesCB_pass > 0){
        h_mesCB_pt->Fill(std::fabs(buf_probe_mesCB_pt/1000.0));
        h_eff_off_CB_pt->Fill(std::fabs(buf_probe_pt*0.001));
        h_eff_SA_CB_pt->Fill(std::fabs(buf_probe_pt*0.001));
        z_invariant_mass_CB->Fill(0.001*TMath::Sqrt(2.0*buf_tag_CB_pt*buf_probe_mesCB_pt*(TMath::CosH(buf_tag_CB_eta - buf_probe_mesCB_eta) - TMath::Cos(buf_tag_CB_phi - buf_probe_mesCB_phi))));
        h_probe_CB_residual_pt->Fill(1.0 - std::fabs(buf_probe_pt)/std::fabs(buf_probe_mesCB_pt));
        h_eff_SA_CB_eta->Fill(buf_probe_eta);
        if(std::fabs(buf_probe_eta) <=0.5){
         h_eff_off_CB_pt_1->Fill(std::fabs(buf_probe_pt*0.001));
        }else if(std::fabs(buf_probe_eta) <=1.0){
         h_eff_off_CB_pt_2->Fill(std::fabs(buf_probe_pt*0.001));
        }else if(std::fabs(buf_probe_eta) <=1.5){
         h_eff_off_CB_pt_3->Fill(std::fabs(buf_probe_pt*0.001));
        }else if(std::fabs(buf_probe_eta) <=2.0){
         h_eff_off_CB_pt_4->Fill(std::fabs(buf_probe_pt*0.001));
        }else if(std::fabs(buf_probe_eta) <=2.5){
         h_eff_off_CB_pt_5->Fill(std::fabs(buf_probe_pt*0.001));
        }
        if(buf_probe_mesEF_pass > 0){
          h_mesEF_pt->Fill(std::fabs(buf_probe_mesEF_pt/1000.0));
          h_eff_off_EF_pt->Fill(std::fabs(buf_probe_pt*0.001));
          h_eff_CB_EF_pt->Fill(std::fabs(buf_probe_pt*0.001));
          z_invariant_mass_EF->Fill(0.001*TMath::Sqrt(2.0*buf_tag_EF_pt*buf_probe_mesEF_pt*(TMath::CosH(buf_tag_EF_eta - buf_probe_mesEF_eta) - TMath::Cos(buf_tag_EF_phi - buf_probe_mesEF_phi))));
          h_probe_EF_residual_pt->Fill(1.0 - std::fabs(buf_probe_pt)/std::fabs(buf_probe_mesEF_pt));
          h_eff_CB_EF_eta->Fill(buf_probe_eta);
          if(std::fabs(buf_probe_eta) <=0.5){
           h_eff_off_EF_pt_1->Fill(std::fabs(buf_probe_pt*0.001));
          }else if(std::fabs(buf_probe_eta) <=1.0){
           h_eff_off_EF_pt_2->Fill(std::fabs(buf_probe_pt*0.001));
          }else if(std::fabs(buf_probe_eta) <=1.5){
           h_eff_off_EF_pt_3->Fill(std::fabs(buf_probe_pt*0.001));
          }else if(std::fabs(buf_probe_eta) <=2.0){
           h_eff_off_EF_pt_4->Fill(std::fabs(buf_probe_pt*0.001));
          }else if(std::fabs(buf_probe_eta) <=2.5){
           h_eff_off_EF_pt_5->Fill(std::fabs(buf_probe_pt*0.001));
          }
          if(std::fabs(buf_probe_pt)*0.001 < 30)continue;
          if(buf_probe_mesL1_pass > 0){
           h_probe_eta_30->Fill(buf_probe_eta);
           if(buf_probe_mesSA_pass > 0 && std::fabs(buf_probe_mesSA_pt) >= threshold_SA){
            h_eff_L1_SA_eta_30->Fill(buf_probe_eta);
            h_probe_SA_residual_pt_30->Fill(1 - std::fabs(buf_probe_pt*0.001)/std::fabs(buf_probe_mesSA_pt));
            if(buf_probe_mesCB_pass > 0){
             h_eff_SA_CB_eta_30->Fill(buf_probe_eta);
             h_probe_CB_residual_pt_30->Fill(1 - std::fabs(buf_probe_pt)/std::fabs(buf_probe_mesCB_pt));   
             if(buf_probe_mesCB_pass > 0){
              h_eff_CB_EF_eta_30->Fill(buf_probe_eta);
              h_probe_EF_residual_pt_30->Fill(1 - std::fabs(buf_probe_pt)/std::fabs(buf_probe_mesEF_pt));
             }
            }
           }
         }
        }
       }
     }
   }
  }

  output_file->cd();
  string title_threshold = name + Form("-%dGeV.png",threshold_SA);

  draw_histgram(h_mesL1_pt,"../output/" + name + Form("/%dGeV/mesL1_pt.png",threshold_SA));
  draw_histgram(h_mesSA_pt,"../output/" + name + Form("/%dGeV/mesSA_pt.png",threshold_SA));
  draw_histgram(h_mesCB_pt,"../output/" + name + Form("/%dGeV/mesCB_pt.png",threshold_SA));
  draw_histgram(h_mesEF_pt,"../output/" + name + Form("/%dGeV/mesEF_pt.png",threshold_SA));
 
  draw_resolution(h_probe_SA_residual_pt,"../output/" + name + Form("/%dGeV/probe_SA_residual_pt.png",threshold_SA),0.1);
  draw_resolution(h_probe_CB_residual_pt,"../output/" + name + Form("/%dGeV/probe_CB_residual_pt.png",threshold_SA),0.08);
  draw_resolution(h_probe_EF_residual_pt,"../output/" + name + Form("/%dGeV/probe_EF_residual_pt.png",threshold_SA),0.01);
  draw_resolution(h_probe_SA_residual_pt_30,"../output/" + name + Form("/%dGeV/probe_SA_residual_pt_30.png",threshold_SA),0.1);
  draw_resolution(h_probe_CB_residual_pt_30,"../output/" + name + Form("/%dGeV/probe_CB_residual_pt_30.png",threshold_SA),0.08);
  draw_resolution(h_probe_EF_residual_pt_30,"../output/" + name + Form("/%dGeV/probe_EF_residual_pt_30.png",threshold_SA),0.01);

  draw_pt_distribution(h_mesL1_pt,h_mesSA_pt,h_mesCB_pt,h_mesEF_pt,h_probe_pt,"L1 pt","SA pt","CB pt","EF pt","offline pt","pt distribution;pt[GeV];Entries","../output/" + name + Form("/%dGeV/pt_distribution_All.png",threshold_SA));

  draw_efficiency(h_eff_off_SA_pt,h_eff_off_L1_pt,"L1vsSA_efficiency@" + name + ";offline pt[GeV];efficiency","../output/" + name + Form("/%dGeV/L1vsSA_efficiency_pt@",threshold_SA) + title_threshold,max);
  draw_efficiency(h_eff_off_CB_pt,h_eff_off_SA_pt,"SAvsCB_efficiency@" + name + ";offline pt[GeV];efficiency","../output/" + name + Form("/%dGeV/SAvsCB_efficiency_pt@",threshold_SA) + title_threshold,max);
  draw_efficiency(h_eff_off_EF_pt,h_eff_off_CB_pt,"CBvsEF_efficiency@" + name + ";offline pt[GeV];efficiency","../output/" + name + Form("/%dGeV/CBvsEF_efficiency_pt@",threshold_SA) + title_threshold,max);

  draw_efficiency(h_eff_L1_SA_eta,h_probe_eta,"L1vsSA_efficiency@" + name + ";offline eta;efficiency","../output/" + name + Form("/%dGeV/L1vsSA_efficiency_eta@",threshold_SA) + title_threshold);
  draw_efficiency(h_eff_SA_CB_eta,h_eff_L1_SA_eta,"SAvsCB_efficiency@" + name + ";offline eta;efficiency","../output/" + name + Form("/%dGeV/SAvsCB_efficiency_eta@",threshold_SA) + title_threshold);
  draw_efficiency(h_eff_CB_EF_eta,h_eff_SA_CB_eta,"CBvsEF_efficiency@" + name + ";offline eta;efficiency","../output/" + name + Form("/%dGeV/CBvsEF_efficiency_eta@",threshold_SA) + title_threshold);

  draw_efficiency(h_eff_L1_SA_eta_30,h_probe_eta_30,"L1vsSA_efficiency@" + name + ";offline eta;efficiency","../output/" + name + Form("/%dGeV/L1vsSA_efficiency_eta_30GeV@",threshold_SA) + title_threshold);
  draw_efficiency(h_eff_SA_CB_eta_30,h_eff_L1_SA_eta_30,"SAvsCB_efficiency@" + name + ";offline eta;efficiency","../output/" + name + Form("/%dGeV/SAvsCB_efficiency_eta_30GeV@",threshold_SA) + title_threshold);
  draw_efficiency(h_eff_CB_EF_eta_30,h_eff_SA_CB_eta_30,"CBvsEF_efficiency@" + name + ";offline eta;efficiency","../output/" + name + Form("/%dGeV/CBvsEF_efficiency_eta_30GeV@",threshold_SA) + title_threshold);

  draw_efficiency(h_eff_off_L1_pt,h_eff_off_SA_pt,h_eff_off_CB_pt,h_eff_off_EF_pt,"efficiency@" + name + ";offline pt[GeV];efficiency","../output/" + name + Form("/%dGeV/efficiency_all@",threshold_SA) + title_threshold,max);

  draw_efficiency(h_eff_off_L1_pt_1,h_eff_off_SA_pt_1,h_eff_off_CB_pt_1,h_eff_off_EF_pt_1,"efficiency@" + name + ";offline pt[GeV];efficiency","../output/" + name + Form("/%dGeV/efficiency_all#eta1@",threshold_SA) + title_threshold,max);
  draw_efficiency(h_eff_off_L1_pt_2,h_eff_off_SA_pt_2,h_eff_off_CB_pt_2,h_eff_off_EF_pt_2,"efficiency@" + name + ";offline pt[GeV];efficiency","../output/" + name + Form("/%dGeV/efficiency_all#eta2@",threshold_SA) + title_threshold,max);
  draw_efficiency(h_eff_off_L1_pt_3,h_eff_off_SA_pt_3,h_eff_off_CB_pt_3,h_eff_off_EF_pt_3,"efficiency@" + name + ";offline pt[GeV];efficiency","../output/" + name + Form("/%dGeV/efficiency_all#eta3@",threshold_SA) + title_threshold,max);
  draw_efficiency(h_eff_off_L1_pt_4,h_eff_off_SA_pt_4,h_eff_off_CB_pt_4,h_eff_off_EF_pt_4,"efficiency@" + name + ";offline pt[GeV];efficiency","../output/" + name + Form("/%dGeV/efficiency_all#eta4@",threshold_SA) + title_threshold,max);
  draw_efficiency(h_eff_off_L1_pt_5,h_eff_off_SA_pt_5,h_eff_off_CB_pt_5,h_eff_off_EF_pt_5,"efficiency@" + name + ";offline pt[GeV];efficiency","../output/" + name + Form("/%dGeV/efficiency_all#eta5@",threshold_SA) + title_threshold,max);

  draw_efficiency(h_eff_off_L1_pt_1,h_eff_off_SA_pt_1,h_eff_off_L1_pt_2,h_eff_off_SA_pt_2,h_eff_off_L1_pt_3,h_eff_off_SA_pt_3,h_eff_off_L1_pt_4,h_eff_off_SA_pt_4,h_eff_off_L1_pt_5,h_eff_off_SA_pt_5,"L1vsSA_efficiency@" + name + ";offline pt[GeV];efficiency","../output/" + name + Form("/%dGeV/efficiency_all#eta@",threshold_SA) + title_threshold,max);

  draw_histgram(z_invariant_mass,"../output/" + name + Form("/%dGeV/z_invariant_mass_offline@",threshold_SA) + title_threshold);
  draw_histgram(z_invariant_mass_L1,"../output/" + name + Form("/%dGeV/z_invariant_mass_L1@",threshold_SA) + title_threshold);
  draw_histgram(z_invariant_mass_SA,"../output/" + name + Form("/%dGeV/z_invariant_mass_SA@",threshold_SA) + title_threshold);
  draw_histgram(z_invariant_mass_CB,"../output/" + name + Form("/%dGeV/z_invariant_mass_CB@",threshold_SA) + title_threshold);
  draw_histgram(z_invariant_mass_EF,"../output/" + name + Form("/%dGeV/z_invariant_mass_EF@",threshold_SA) + title_threshold);
  draw_invariant_mass_distribution(z_invariant_mass,z_invariant_mass_L1,z_invariant_mass_SA,z_invariant_mass_CB,z_invariant_mass_EF,"../output/" + name + Form("/%dGeV/z_invariant_mass_All@",threshold_SA) + title_threshold);

  draw_histgram(h_probe_mesSA_pt,"../output/" + name + Form("/%dGeV/probe_mesSA_pt.png",threshold_SA));
  draw_histgram(h_tag_SA_pt,"../output/" + name + Form("/%dGeV/tag_SA_pt.png",threshold_SA));
  draw_histgram(h_probe_eta_pt,"../output/" + name + Form("/%dGeV/probe_eta_pt.png",threshold_SA));

  delete h_probe_mesSA_pt;
  delete h_tag_SA_pt;
  delete h_probe_SA_residual_pt;
  delete h_probe_CB_residual_pt;
  delete h_probe_EF_residual_pt;
  delete h_probe_pt;
  delete h_mesL1_pt;
  delete h_eff_off_L1_pt;
  delete h_mesSA_pt;
  delete h_eff_off_SA_pt;
  delete h_eff_L1_SA_pt;
  delete h_mesCB_pt;
  delete h_eff_off_CB_pt;
  delete h_eff_SA_CB_pt;
  delete h_mesEF_pt;
  delete h_eff_off_EF_pt;
  delete h_eff_CB_EF_pt;
  delete z_invariant_mass;
  delete z_invariant_mass_L1;
  delete z_invariant_mass_SA;
  delete z_invariant_mass_CB;
  delete z_invariant_mass_EF;
  delete h_probe_eta_pt;
  delete h_probe_eta;
  delete h_eff_L1_SA_eta;
  delete h_eff_SA_CB_eta;
  delete h_eff_CB_EF_eta;
  delete h_probe_eta_30;
  delete h_eff_L1_SA_eta_30;
  delete h_eff_SA_CB_eta_30;
  delete h_eff_CB_EF_eta_30;

  probe_mesL1_pt->clear();
  probe_mesL1_eta->clear();
  probe_mesL1_phi->clear();
  probe_mesL1_dR->clear();
  probe_mesL1_pass->clear();
  probe_mesSA_pt->clear();
  probe_mesSA_eta->clear();
  probe_mesSA_phi->clear();
  probe_mesSA_dR->clear();
  probe_mesSA_pass->clear();
  probe_mesCB_pt->clear();
  probe_mesCB_eta->clear();
  probe_mesCB_phi->clear();
  probe_mesCB_dR->clear();
  probe_mesCB_pass->clear();
  probe_mesEF_pt->clear();
  probe_mesEF_eta->clear();
  probe_mesEF_phi->clear();
  probe_mesEF_dR->clear();
  probe_mesEF_pass->clear();
}

 void draw_histgram(TH1D *h1,string title){
  TCanvas *c1 = new TCanvas("c1","c1",1600,900);
  gStyle->SetTitleYOffset(1.5);
  h1->SetFillColor(kRed);
  h1->SetLineColor(kRed);
  h1->SetTitle("Mz distribution;Mz[GeV];Entries");
  h1->Draw();
  c1->SaveAs(title.c_str());
  h1->Write();
  delete c1;
 }

 void draw_resolution(TH1D *h1,string title,Double_t width){
  TCanvas *c1 = new TCanvas("c1","c1",1600,900);
  gStyle->SetTitleYOffset(1.5);
  h1->SetFillColor(kRed);
  h1->SetLineColor(kRed);
  h1->Draw();
  /*
  TF1 *fitgaus = new TF1("fitgaus","[0]*TMath::Gaus(x,[1],[2])",-100,100);
  fitgaus->SetParameter(0,5000);
  fitgaus->SetParameter(1,0);
  fitgaus->SetParameter(2,7);
  fitgaus->SetParLimits(2,0.0,100.0);
  fitgaus->SetLineColor(kBlue);
  fitgaus->SetLineWidth(4);
  h1->Fit("fitgaus","","",-width,width);
  gStyle->SetOptFit(1111);
  */
  c1->SaveAs(title.c_str());
  h1->Write();
  delete c1;
 }

 void draw_histgram(TH2F *h1,string title){
  TCanvas *c1 = new TCanvas("c1","c1",1200,1200);
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadBottomMargin(0.1);
  gStyle->SetPadLeftMargin(0.105);
  gStyle->SetPadRightMargin(0.165);
  h1->GetYaxis()->SetTitleOffset(1.5);
  h1->SetStats(0);
  h1->Draw("colz");
  h1->Write();
  c1->SaveAs(title.c_str());
  delete c1;
 }

 void draw_invariant_mass_distribution(TH1D *h1,TH1D *h2,TH1D *h3,TH1D *h4,TH1D *h5,string title){
  TCanvas *c1 = new TCanvas("c1","c1",1600,900);
  gStyle->SetTitleYOffset(1.5);
  h1->SetStats(0);
  h2->SetStats(0);
  h3->SetStats(0);
  h4->SetStats(0);
  h5->SetStats(0);
  h1->SetFillColor(kRed);
  h1->SetLineColor(kRed);
  h2->SetFillColor(kGreen);
  h2->SetLineColor(kGreen);
  h3->SetFillColor(kBlue);
  h3->SetLineColor(kBlue);
  h4->SetFillColor(kYellow);
  h4->SetLineColor(kYellow);
  h5->SetFillColor(kMagenta);
  h5->SetLineColor(kMagenta);
  h1->Draw();
  h2->Draw("same");
  h3->Draw("same");
  h4->Draw("same");
  h5->Draw("same");
  c1->RedrawAxis();
  h1->SetTitle("z invariant mass;Mz[GeV];Entries");
  TLegend *legend = new TLegend(0.7,0.1,0.9,0.4,"");
  legend->AddEntry(h1,"offline","f");
  legend->AddEntry(h2,"L1","f");
  legend->AddEntry(h3,"SA","f");
  legend->AddEntry(h4,"CB","f");
  legend->AddEntry(h5,"EF","f");
  legend->Draw();
  c1->SaveAs(title.c_str());
  delete c1;
 }

 void draw_pt_distribution(TH1D *h1,TH1D *h2,TH1D *h3,TH1D *h4,TH1D *h5,string label1,string label2,string label3,string label4,string label5,string title_axis,string title){
  TCanvas *c1 = new TCanvas("c1","c1",1600,900);
  gStyle->SetTitleYOffset(1.5);
  h1->SetStats(0);
  h2->SetStats(0);
  h3->SetStats(0);
  h4->SetStats(0);
  h5->SetStats(0);
  h1->SetFillColor(kRed);
  h1->SetLineColor(kRed);
  h2->SetFillColor(kGreen);
  h2->SetLineColor(kGreen);
  h3->SetFillColor(kBlue);
  h3->SetLineColor(kBlue);
  h4->SetFillColor(kYellow);
  h4->SetLineColor(kYellow);
  h5->SetFillColor(kMagenta);
  h5->SetLineColor(kMagenta);
  h1->Draw();
  h2->Draw("same");
  h3->Draw("same");
  h4->Draw("same");
  h5->Draw("same");
  c1->RedrawAxis();
  h1->SetTitle(title_axis.c_str());
  TLegend *legend = new TLegend(0.7,0.1,0.9,0.4,"");
  legend->AddEntry(h1,label1.c_str(),"f");
  legend->AddEntry(h2,label2.c_str(),"f");
  legend->AddEntry(h3,label3.c_str(),"f");
  legend->AddEntry(h4,label4.c_str(),"f");
  legend->AddEntry(h5,label5.c_str(),"f");
  legend->Draw();
  c1->SaveAs(title.c_str());
  delete c1;
}

 void draw_efficiency(TH1D *h1,TH1D *h2,string title_axis,string title,Int_t max){
  TCanvas *c1 = new TCanvas("c1","c1",1600,900);
  gStyle->SetTitleYOffset(1.0);
  TH1F *frame = gPad->DrawFrame(0,0,max,1);
  vector<Double_t> eff_x;
  vector<Double_t> eff_y;
  vector<Double_t> eff_x_err;
  vector<Double_t> eff_y_err;
  for(Int_t i = 0;i <= max;i++){
    Double_t buf_m = static_cast<Double_t>(h1->GetBinContent(i));
    Double_t buf_n = static_cast<Double_t>(h2->GetBinContent(i));
    if(buf_n != 0){
    eff_y.push_back(buf_m/buf_n);
    eff_y_err.push_back(sqrt(buf_m*(1 - buf_m/buf_n))/buf_n);
    eff_x.push_back(static_cast<Double_t>(i));
   }
   eff_x_err.push_back(0.5);
  }

  TGraphErrors *tg1 = new TGraphErrors(eff_x.size(),&(eff_x.at(0)),&(eff_y.at(0)),&(eff_x_err.at(0)),&(eff_y_err.at(0)));
  tg1->SetMarkerStyle(20);
  tg1->SetMarkerSize(1.0);
  frame->SetTitle(title_axis.c_str());
  tg1->Draw("P");
  TF1 * f1 = new TF1("f1","[0]/(TMath::Exp(-(x - [1])/[2]) + 1)",0,200);
  f1->SetParameter(0,0.9);
  f1->SetParameter(1,20);
  //f1->SetParameter(2,);
  f1->SetParLimits(0,0.5,1.0);
  f1->SetParLimits(1,15,30);
  f1->SetParLimits(2,0,100);
  f1->SetLineColor(kRed);
  tg1->Fit("f1","","",0,max);
  c1->SaveAs(title.c_str());
  tg1->Write();
  eff_y.clear();
  eff_y_err.clear();
  delete tg1;
  delete c1; 
 }

 void draw_efficiency(TH1D *h1,TH1D *h2,string title_axis,string title){
  TCanvas *c1 = new TCanvas("c1","c1",1600,900);
  gStyle->SetTitleYOffset(1.0);
  TH1F *frame = gPad->DrawFrame(-2.5,0,2.5,1);
  vector<Double_t> eff_x;
  vector<Double_t> eff_y;
  vector<Double_t> eff_x_err;
  vector<Double_t> eff_y_err;
  for(Int_t i = 0;i <= 50;i++){
    Double_t buf_m = static_cast<Double_t>(h1->GetBinContent(i));
    Double_t buf_n = static_cast<Double_t>(h2->GetBinContent(i));
    if(buf_n != 0){
    eff_y.push_back(buf_m/buf_n);
    eff_y_err.push_back(sqrt(buf_m*(1 - buf_m/buf_n))/buf_n);
    eff_x.push_back(static_cast<Double_t>(-2.5 + 0.1*i));
   }
   eff_x_err.push_back(0.05);
  }

  TGraphErrors *tg1 = new TGraphErrors(eff_x.size(),&(eff_x.at(0)),&(eff_y.at(0)),&(eff_x_err.at(0)),&(eff_y_err.at(0)));
  tg1->SetMarkerStyle(20);
  tg1->SetMarkerSize(1.0);
  frame->SetTitle(title_axis.c_str());
  tg1->Draw("P");
  c1->SaveAs(title.c_str());
  tg1->Write();
  eff_y.clear();
  eff_y_err.clear();
  delete tg1;
  delete c1; 
 }

  void draw_efficiency(TH1D *h1,TH1D *h2,TH1D *h3,TH1D *h4,string title_axis,string title,Int_t max){
  TCanvas *c1 = new TCanvas("c1","c1",1600,900);
  gStyle->SetTitleYOffset(1.0);
  TH1F *frame = gPad->DrawFrame(0,0,max,1);
  vector<Double_t> eff_x1;
  vector<Double_t> eff_y1;
  vector<Double_t> eff_x1_err;
  vector<Double_t> eff_y1_err;
  vector<Double_t> eff_x2;
  vector<Double_t> eff_y2;
  vector<Double_t> eff_x2_err;
  vector<Double_t> eff_y2_err;
  vector<Double_t> eff_x3;
  vector<Double_t> eff_y3;
  vector<Double_t> eff_x3_err;
  vector<Double_t> eff_y3_err;
  for(Int_t i = 0;i <= max;i++){
    Double_t buf_1 = static_cast<Double_t>(h1->GetBinContent(i));
    Double_t buf_2 = static_cast<Double_t>(h2->GetBinContent(i));
    Double_t buf_3 = static_cast<Double_t>(h3->GetBinContent(i));
    Double_t buf_4 = static_cast<Double_t>(h4->GetBinContent(i));
    if(buf_1 != 0){
     eff_y1.push_back(buf_2/buf_1);
     eff_y1_err.push_back(sqrt(buf_2*(1 - buf_2/buf_1))/buf_1);
     eff_x1.push_back(static_cast<Double_t>(i));
   }
    if(buf_2 != 0){
     eff_y2.push_back(buf_3/buf_2);
     eff_y2_err.push_back(sqrt(buf_3*(1 - buf_3/buf_2))/buf_2);
     eff_x2.push_back(static_cast<Double_t>(i));
   }
    if(buf_3 != 0){
     eff_y3.push_back(buf_4/buf_3);
     eff_y3_err.push_back(sqrt(buf_4*(1 - buf_4/buf_3))/buf_3);
     eff_x3.push_back(static_cast<Double_t>(i));
   }
   eff_x1_err.push_back(0.5);
   eff_x2_err.push_back(0.5);
   eff_x3_err.push_back(0.5);
  }

  TGraphErrors *tg1 = new TGraphErrors(eff_x1.size(),&(eff_x1.at(0)),&(eff_y1.at(0)),&(eff_x1_err.at(0)),&(eff_y1_err.at(0)));
  tg1->SetMarkerStyle(20);
  tg1->SetMarkerSize(1.0);
  tg1->SetMarkerColor(kRed);
  tg1->Draw("P");
  TGraphErrors *tg2 = new TGraphErrors(eff_x2.size(),&(eff_x2.at(0)),&(eff_y2.at(0)),&(eff_x2_err.at(0)),&(eff_y2_err.at(0)));
  tg2->SetMarkerStyle(20);
  tg2->SetMarkerSize(1.0);
  tg2->SetMarkerColor(kGreen);
  tg2->Draw("P");
  TGraphErrors *tg3 = new TGraphErrors(eff_x3.size(),&(eff_x3.at(0)),&(eff_y3.at(0)),&(eff_x3_err.at(0)),&(eff_y3_err.at(0)));
  tg3->SetMarkerStyle(20);
  tg3->SetMarkerSize(1.0);
  tg3->SetMarkerColor(kBlue);
  tg3->Draw("P");

  TLegend *legend = new TLegend(0.7,0.1,0.9,0.4,"");
  legend->AddEntry(tg1,"L1 vs SA","lep");
  legend->AddEntry(tg2,"SA vs CB","lep");
  legend->AddEntry(tg3,"CB vs EF","lep");
  legend->Draw();

  frame->SetTitle(title_axis.c_str());
  c1->SaveAs(title.c_str());

  eff_x1.clear();
  eff_y1.clear();
  eff_x1_err.clear();
  eff_y1_err.clear();
  eff_x2.clear();
  eff_y2.clear();
  eff_x2_err.clear();
  eff_y2_err.clear();
  eff_x3.clear();
  eff_y3.clear();
  eff_x3_err.clear();
  eff_y3_err.clear();
  delete tg1;
  delete tg2;
  delete tg3;
  delete c1; 
  }

 void draw_efficiency(TH1D *h1,TH1D *h2,TH1D *h3,TH1D *h4,TH1D *h5,TH1D *h6,TH1D *h7,TH1D *h8,TH1D *h9,TH1D *h10,string title_axis,string title,Int_t max){
  TCanvas *c1 = new TCanvas("c1","c1",1600,900);
  gStyle->SetTitleYOffset(1.0);
  TH1F *frame = gPad->DrawFrame(0,0,max,1);
  vector<Double_t> eff_x1;
  vector<Double_t> eff_y1;
  vector<Double_t> eff_x1_err;
  vector<Double_t> eff_y1_err;
  vector<Double_t> eff_x2;
  vector<Double_t> eff_y2;
  vector<Double_t> eff_x2_err;
  vector<Double_t> eff_y2_err;
  vector<Double_t> eff_x3;
  vector<Double_t> eff_y3;
  vector<Double_t> eff_x3_err;
  vector<Double_t> eff_y3_err;
  vector<Double_t> eff_x4;
  vector<Double_t> eff_y4;
  vector<Double_t> eff_x4_err;
  vector<Double_t> eff_y4_err;
  vector<Double_t> eff_x5;
  vector<Double_t> eff_y5;
  vector<Double_t> eff_x5_err;
  vector<Double_t> eff_y5_err;
  for(Int_t i = 0;i <= max;i++){
    Double_t buf_1 = static_cast<Double_t>(h1->GetBinContent(i));
    Double_t buf_2 = static_cast<Double_t>(h2->GetBinContent(i));
    Double_t buf_3 = static_cast<Double_t>(h3->GetBinContent(i));
    Double_t buf_4 = static_cast<Double_t>(h4->GetBinContent(i));
    Double_t buf_5 = static_cast<Double_t>(h5->GetBinContent(i));
    Double_t buf_6 = static_cast<Double_t>(h6->GetBinContent(i));
    Double_t buf_7 = static_cast<Double_t>(h7->GetBinContent(i));
    Double_t buf_8 = static_cast<Double_t>(h8->GetBinContent(i));
    Double_t buf_9 = static_cast<Double_t>(h9->GetBinContent(i));
    Double_t buf_10 = static_cast<Double_t>(h10->GetBinContent(i));
    if(buf_1 != 0){
     eff_y1.push_back(buf_2/buf_1);
     eff_y1_err.push_back(sqrt(buf_2*(1 - buf_2/buf_1))/buf_1);
     eff_x1.push_back(static_cast<Double_t>(i));
     eff_x1_err.push_back(0.5);
    }
    if(buf_3 != 0){
     eff_y2.push_back(buf_4/buf_3);
     eff_y2_err.push_back(sqrt(buf_4*(1 - buf_4/buf_3))/buf_3);
     eff_x2.push_back(static_cast<Double_t>(i));
     eff_x2_err.push_back(0.5);
    }
    if(buf_5 != 0){
     eff_y3.push_back(buf_6/buf_5);
     eff_y3_err.push_back(sqrt(buf_6*(1 - buf_6/buf_5))/buf_5);
     eff_x3.push_back(static_cast<Double_t>(i));
     eff_x3_err.push_back(0.5);
    }
    if(buf_7 != 0){
     eff_y4.push_back(buf_8/buf_7);
     eff_y4_err.push_back(sqrt(buf_8*(1 - buf_8/buf_7))/buf_7);
     eff_x4.push_back(static_cast<Double_t>(i));
     eff_x4_err.push_back(0.5);
    }
    if(buf_9 != 0){
     eff_y5.push_back(buf_10/buf_9);
     eff_y5_err.push_back(sqrt(buf_10*(1 - buf_10/buf_9))/buf_9);
     eff_x5.push_back(static_cast<Double_t>(i));
     eff_x5_err.push_back(0.5);
    }
   }

  TGraphErrors *tg1 = new TGraphErrors(eff_x1.size(),&(eff_x1.at(0)),&(eff_y1.at(0)),&(eff_x1_err.at(0)),&(eff_y1_err.at(0)));
  tg1->SetMarkerStyle(20);
  tg1->SetMarkerSize(1.0);
  tg1->SetMarkerColor(kRed);
  tg1->Draw("P");
  TGraphErrors *tg2 = new TGraphErrors(eff_x2.size(),&(eff_x2.at(0)),&(eff_y2.at(0)),&(eff_x2_err.at(0)),&(eff_y2_err.at(0)));
  tg2->SetMarkerStyle(20);
  tg2->SetMarkerSize(1.0);
  tg2->SetMarkerColor(kGreen);
  tg2->Draw("P");
  TGraphErrors *tg3 = new TGraphErrors(eff_x3.size(),&(eff_x3.at(0)),&(eff_y3.at(0)),&(eff_x3_err.at(0)),&(eff_y3_err.at(0)));
  tg3->SetMarkerStyle(20);
  tg3->SetMarkerSize(1.0);
  tg3->SetMarkerColor(kBlue);
  tg3->Draw("P");
  TGraphErrors *tg4 = new TGraphErrors(eff_x4.size(),&(eff_x4.at(0)),&(eff_y4.at(0)),&(eff_x4_err.at(0)),&(eff_y4_err.at(0)));
  tg4->SetMarkerStyle(20);
  tg4->SetMarkerSize(1.0);
  tg4->SetMarkerColor(kYellow);
  tg4->Draw("P");
  TGraphErrors *tg5 = new TGraphErrors(eff_x5.size(),&(eff_x5.at(0)),&(eff_y5.at(0)),&(eff_x5_err.at(0)),&(eff_y5_err.at(0)));
  tg5->SetMarkerStyle(20);
  tg5->SetMarkerSize(1.0);
  tg5->SetMarkerColor(kMagenta);
  tg5->Draw("P");

  TLegend *legend = new TLegend(0.7,0.1,0.9,0.4,"");
  legend->AddEntry(tg1,"0 <= #eta <= 0.5","lep");
  legend->AddEntry(tg2,"0.5 < #eta <= 1.0","lep");
  legend->AddEntry(tg3,"1.0 < #eta <= 1.5","lep");
  legend->AddEntry(tg4,"1.5 < #eta <= 2.0","lep");
  legend->AddEntry(tg5,"2.0 < #eta <= 2.5","lep");
  legend->Draw();

  frame->SetTitle(title_axis.c_str());
  c1->SaveAs(title.c_str());

  eff_x1.clear();
  eff_y1.clear();
  eff_x1_err.clear();
  eff_y1_err.clear();
  eff_x2.clear();
  eff_y2.clear();
  eff_x2_err.clear();
  eff_y2_err.clear();
  eff_x3.clear();
  eff_y3.clear();
  eff_x3_err.clear();
  eff_y3_err.clear();
  delete tg1;
  delete tg2;
  delete tg3;
  delete c1; 
  }


