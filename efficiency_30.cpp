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

 void draw_resolution(TH1D *h1,string title,Double_t width){}

 void draw_efficiency(TH1D *h1,TH1D *h2,string title_axis,string title){}

//main loop
 void efficiency_30(){
  std::cout<<"start!"<<std::endl;
  TFile *output_file = new TFile("../output/plot.root","RECREATE");
  for(Int_t i = 0;i < 24;i += 4){
   efficiency("mu26ivm",i,60,output_file);
  }
  efficiency("mu26ivm",26,60,output_file);
  for(Int_t i = 0;i < 55;i += 5){
   efficiency("mu50",i,80,output_file);
  }
 }

 void efficiency(const string name,const Int_t threshold_SA,const Int_t max,TFile *output_file){
  TFile *tf1 = TFile::Open("../src/Zmumu.root","read");
  TTree *tr1 = dynamic_cast<TTree*>(tf1->Get("t_tap"));

  TH1D *h_probe_SA_residual_pt_30 = new TH1D("probe_SA_residual_pt_30","probe_SA_residual_pt;#Delta pt;Entries",160,-10,10);
  TH1D *h_probe_CB_residual_pt_30 = new TH1D("probe_CB_residual_pt_30","probe_CB_residual_pt;#Delta pt;Entries",320,-10,10);
  TH1D *h_probe_EF_residual_pt_30 = new TH1D("probe_EF_residual_pt_30","probe_EF_residual_pt;#Delta pt;Entries",640,-10,10);
  TH1D *h_probe_eta_30 = new TH1D("probe_offline_eta_30","probe_offline_eta;offline eta;Entries",50,-2.5,2.5);
  TH1D *h_eff_L1_SA_eta_30 = new TH1D("L1_SA_eta_30","mesSA_eta;SA eta;Entries",50,-2.5,2.5);
  TH1D *h_eff_SA_CB_eta_30 = new TH1D("SA_CB_eta_30","mesCB_eta;CB eta;Entries",50,-2.5,2.5);
  TH1D *h_eff_CB_EF_eta_30 = new TH1D("CB_EF_eta_30","mesCB_eta;EF eta;Entries",50,-2.5,2.5);

  Double_t probe_pt,probe_eta;
  std::vector<string> *mes_name;
  std::vector<Double_t> *probe_mesSA_pt,*probe_mesCB_pt,*probe_mesEF_pt;
  std::vector<Int_t> *probe_mesL1_pass,*probe_mesSA_pass,*probe_mesCB_pass,*probe_mesEF_pass;
  TBranch *b_mes_name,*b_probe_mesSA_pt,*b_probe_mesCB_pt,*b_probe_mesEF_pt,*b_probe_mesL1_pass,*b_probe_mesSA_pass,*b_probe_mesCB_pass,*b_probe_mesEF_pass;

  tr1->SetBranchStatus("*",0);
  tr1->SetBranchStatus("mes_name",1);
  tr1->SetBranchStatus("probe_pt",1);
  tr1->SetBranchStatus("probe_eta",1);
  tr1->SetBranchStatus("probe_mesSA_pt",1);
  tr1->SetBranchStatus("probe_mesCB_pt",1);
  tr1->SetBranchStatus("probe_mesEF_pt",1);
  tr1->SetBranchStatus("probe_mesL1_pass",1);
  tr1->SetBranchStatus("probe_mesSA_pass",1);
  tr1->SetBranchStatus("probe_mesCB_pass",1);
  tr1->SetBranchStatus("probe_mesEF_pass",1);

  tr1->SetBranchAddress("mes_name",&mes_name,&b_mes_name);
  tr1->SetBranchAddress("probe_pt",&probe_pt);
  tr1->SetBranchAddress("probe_eta",&probe_eta);
  tr1->SetBranchAddress("probe_mesSA_pt",&probe_mesSA_pt,&b_probe_mesSA_pt);
  tr1->SetBranchAddress("probe_mesCB_pt",&probe_mesCB_pt,&b_probe_mesCB_pt);
  tr1->SetBranchAddress("probe_mesEF_pt",&probe_mesEF_pt,&b_probe_mesEF_pt);
  tr1->SetBranchAddress("probe_mesL1_pass",&probe_mesL1_pass,&b_probe_mesL1_pass);
  tr1->SetBranchAddress("probe_mesSA_pass",&probe_mesSA_pass,&b_probe_mesSA_pass);
  tr1->SetBranchAddress("probe_mesCB_pass",&probe_mesCB_pass,&b_probe_mesCB_pass);
  tr1->SetBranchAddress("probe_mesEF_pass",&probe_mesEF_pass,&b_probe_mesEF_pass);

  for(Int_t event = 0;event < tr1->GetEntries();event++){
    tr1->GetEntry(event);
    Double_t buf_probe_pt = probe_pt;
    if(std::fabs(buf_probe_pt)*0.001 <= 30)continue;
    Double_t buf_probe_mesSA_pt = -99999;
    Double_t buf_probe_mesCB_pt = -99999;
    Double_t buf_probe_mesEF_pt = -99999;
    Int_t buf_probe_mesL1_pass = 0;
    Int_t buf_probe_mesSA_pass = 0;
    Int_t buf_probe_mesCB_pass = 0;
    Int_t buf_probe_mesEF_pass = 0;
    Double_t buf_probe_eta = probe_eta;
    for(Int_t mes = 0;mes < 25;mes++){
     if(mes_name->at(mes) == name){
      buf_probe_mesSA_pt = probe_mesSA_pt->at(mes);
      buf_probe_mesCB_pt = probe_mesCB_pt->at(mes);
      buf_probe_mesEF_pt = probe_mesEF_pt->at(mes);
      buf_probe_mesL1_pass = probe_mesL1_pass->at(mes);
      buf_probe_mesSA_pass = probe_mesSA_pass->at(mes);
      buf_probe_mesCB_pass = probe_mesCB_pass->at(mes);
      buf_probe_mesEF_pass = probe_mesEF_pass->at(mes);
     }
    }
    if(buf_probe_mesL1_pass > 0){
     h_probe_eta_30->Fill(buf_probe_eta);
     if(buf_probe_mesSA_pass > 0 && std::fabs(buf_probe_mesSA_pt) >= threshold_SA){
       h_probe_SA_residual_pt_30->Fill(1.0 - std::fabs(buf_probe_pt*0.001)/std::fabs(buf_probe_mesSA_pt));
       h_eff_L1_SA_eta_30->Fill(buf_probe_eta);
       if(buf_probe_mesCB_pass > 0){
        h_probe_CB_residual_pt_30->Fill(1.0 - std::fabs(buf_probe_pt*0.001)/std::fabs(buf_probe_mesCB_pt));
        h_eff_SA_CB_eta_30->Fill(buf_probe_eta);
        if(buf_probe_mesEF_pass > 0){
          h_probe_EF_residual_pt_30->Fill(1.0 - std::fabs(buf_probe_pt*0.001)/std::fabs(buf_probe_mesEF_pt));
          h_eff_CB_EF_eta_30->Fill(buf_probe_eta);
        }
       }
     }
   }
  }

  output_file->cd();
  string title_threshold = name + Form("-%dGeV.png",threshold_SA);

  draw_resolution(h_probe_SA_residual_pt_30,"../output/" + name + Form("/%dGeV/probe_SA_residual_pt_30.png",threshold_SA),2.0);
  draw_resolution(h_probe_CB_residual_pt_30,"../output/" + name + Form("/%dGeV/probe_CB_residual_pt_30.png",threshold_SA),0.5);
  draw_resolution(h_probe_EF_residual_pt_30,"../output/" + name + Form("/%dGeV/probe_EF_residual_pt_30.png",threshold_SA),0.1);

  draw_efficiency(h_eff_L1_SA_eta_30,h_probe_eta_30,"L1vsSA_efficiency@" + name + ";offline eta;efficiency","../output/" + name + Form("/%dGeV/L1vsSA_efficiency_eta_30GeV@",threshold_SA) + title_threshold);
  draw_efficiency(h_eff_SA_CB_eta_30,h_eff_L1_SA_eta_30,"SAvsCB_efficiency@" + name + ";offline eta;efficiency","../output/" + name + Form("/%dGeV/SAvsCB_efficiency_eta_30GeV@",threshold_SA) + title_threshold);
  draw_efficiency(h_eff_CB_EF_eta_30,h_eff_SA_CB_eta_30,"CBvsEF_efficiency@" + name + ";offline eta;efficiency","../output/" + name + Form("/%dGeV/CBvsEF_efficiency_eta_30GeV@",threshold_SA) + title_threshold);


  delete h_probe_eta_30;
  delete h_eff_L1_SA_eta_30;
  delete h_eff_SA_CB_eta_30;
  delete h_eff_CB_EF_eta_30;
  delete h_probe_SA_residual_pt_30;
  delete h_probe_CB_residual_pt_30;
  delete h_probe_EF_residual_pt_30;

  probe_mesL1_pass->clear();
  probe_mesSA_pt->clear();
  probe_mesSA_pass->clear();
  probe_mesCB_pass->clear();
  probe_mesEF_pass->clear();
}

 void draw_resolution(TH1D *h1,string title,Double_t width){
  TCanvas *c1 = new TCanvas("c1","c1",1600,900);
  gStyle->SetTitleYOffset(1.5);
  h1->SetFillColor(kRed);
  h1->SetLineColor(kRed);
  h1->Draw();
  TF1 *fitgaus = new TF1("fitgaus","[0]*TMath::Gaus(x,[1],[2])",-100,100);
  fitgaus->SetParameter(0,5000);
  fitgaus->SetParameter(1,0);
  fitgaus->SetParameter(2,7);
  fitgaus->SetParLimits(2,0.0,100.0);
  fitgaus->SetLineColor(kBlue);
  fitgaus->SetLineWidth(4);
  h1->Fit("fitgaus","","",-width,width);
  gStyle->SetOptFit(1111);
  c1->SaveAs(title.c_str());
  h1->Write();
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

