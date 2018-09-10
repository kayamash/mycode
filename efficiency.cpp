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
#include <string>
#include <sstream>
#include <TF1.h>
#include <TTree.h>
#include <TStyle.h>
#include <TText.h>
#include <vector>

 const string name = "mu26ivm";
 const Int_t max = 60;
 const Double_t threshold_SA = 5;

 void draw_histgram(TH1D *h1,string title){}

 void draw_resolution(TH1D *h1,string title){}

 void draw_histgram(TH2F *h1,string title){}

 void draw_pt_distribution(TH1D *h1,TH1D *h2,TH1D *h3,TH1D *h4,TH1D *h5,string label1,string label2,string label3,string label4,string label5,string title_axis,string title){}

 void draw_efficiency(TH1D *h1,TH1D *h2,string title_axis,string title){}

 void efficiency(){
  TFile *tf1 = TFile::Open("../src/Zmumu.root","read");
  TTree *tr1 = dynamic_cast<TTree*>(tf1->Get("t_tap"));
  TH2F *h_probe_mesSA_pt = new TH2F("probe_mesSA_pt","probe_pt vs probe_mesSA_pt@mu26ivm;probe_pt[GeV];probe_mesSA_pt[GeV]",150,0,150,150,0,150);
  TH2F *h_tag_SA_pt = new TH2F("tag_SA_pt","tag_pt vs tag_SA_pt;tag_SA_pt;tag_pt",150,0,150,150,0,150000);

  TH1D *h_probe_SA_inverse_residual_pt = new TH1D("probe_SA_inverse_residual_pt","probe_SA_residual_pt;1/#Delta pt;Entries",400,-200,200);
  TH1D *h_probe_SA_residual_pt = new TH1D("probe_SA_residual_pt","probe_SA_residual_pt;#Delta pt;Entries",160,-10,10);
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

  Double_t tag_pt,tag_SA_pt,probe_pt;
  std::vector<string> *mes_name;
  std::vector<Double_t> *probe_mesL1_pt,*probe_mesSA_pt,*probe_mesCB_pt,*probe_mesEF_pt;
  TBranch *b_mes_name,*b_probe_mesL1_pt,*b_probe_mesSA_pt,*b_probe_mesCB_pt,*b_probe_mesEF_pt;

  tr1->SetBranchAddress("mes_name",&mes_name,&b_mes_name);
  tr1->SetBranchAddress("tag_pt",&tag_pt);
  tr1->SetBranchAddress("tag_SA_pt",&tag_SA_pt);
  tr1->SetBranchAddress("probe_pt",&probe_pt);
  tr1->SetBranchAddress("probe_mesL1_pt",&probe_mesL1_pt,&b_probe_mesL1_pt);
  tr1->SetBranchAddress("probe_mesSA_pt",&probe_mesSA_pt,&b_probe_mesSA_pt);
  tr1->SetBranchAddress("probe_mesCB_pt",&probe_mesCB_pt,&b_probe_mesCB_pt);
  tr1->SetBranchAddress("probe_mesEF_pt",&probe_mesEF_pt,&b_probe_mesEF_pt);

  for(Int_t event = 0;event < tr1->GetEntries();event++){
    tr1->GetEntry(event);
    Double_t buf_tag_pt = tag_pt;
    Double_t buf_tag_SA_pt = std::fabs(tag_SA_pt);
    Double_t buf_probe_pt = probe_pt/1000.0;
    Double_t buf_probe_mesL1_pt = 99999;
    Double_t buf_probe_mesSA_pt = 99999;
    Double_t buf_probe_mesCB_pt = 99999;
    Double_t buf_probe_mesEF_pt = 99999;
    for(Int_t mes = 0;mes < 25;mes++){
     if(mes_name->at(mes) == name){
      buf_probe_mesL1_pt = std::fabs(probe_mesL1_pt->at(mes));
      buf_probe_mesSA_pt = std::fabs(probe_mesSA_pt->at(mes));
      buf_probe_mesCB_pt = std::fabs(probe_mesCB_pt->at(mes));
      buf_probe_mesEF_pt = std::fabs(probe_mesEF_pt->at(mes));
     }
    }
    h_tag_SA_pt->Fill(buf_tag_SA_pt,buf_tag_pt);
    h_probe_pt->Fill(buf_probe_pt);
    if(buf_probe_mesL1_pt != 99999){
     h_mesL1_pt->Fill(buf_probe_mesL1_pt/1000.0);
     h_eff_off_L1_pt->Fill(buf_probe_pt);
     if(buf_probe_mesSA_pt != 99999 && buf_probe_mesSA_pt >= threshold_SA){
       h_probe_mesSA_pt->Fill(buf_probe_pt,buf_probe_mesSA_pt);
       h_probe_SA_inverse_residual_pt->Fill(1.0/(1.0 - buf_probe_pt/buf_probe_mesSA_pt));
       h_probe_SA_residual_pt->Fill(1.0 - buf_probe_pt/buf_probe_mesSA_pt);
       h_mesSA_pt->Fill(buf_probe_mesSA_pt);
       h_eff_off_SA_pt->Fill(buf_probe_pt);
       h_eff_L1_SA_pt->Fill(buf_probe_pt);
       if(buf_probe_mesCB_pt != 99999){
        h_mesCB_pt->Fill(buf_probe_mesCB_pt/1000.0);
        h_eff_off_CB_pt->Fill(buf_probe_pt);
        h_eff_SA_CB_pt->Fill(buf_probe_pt);
        if(buf_probe_mesEF_pt != 99999){
          h_mesEF_pt->Fill(buf_probe_mesEF_pt/1000.0);
          h_eff_off_EF_pt->Fill(buf_probe_pt);
          h_eff_CB_EF_pt->Fill(buf_probe_pt);
        }
       }
     }
   }
  }

  TFile *output_file = new TFile("../output/plot.root","RECREATE");

  draw_histgram(h_mesL1_pt,"../output/mesL1_pt.png");
  draw_histgram(h_mesSA_pt,"../output/mesSA_pt.png");
  draw_histgram(h_mesCB_pt,"../output/mesCB_pt.png");
  draw_histgram(h_mesEF_pt,"../output/mesEF_pt.png");
  draw_resolution(h_probe_SA_residual_pt,"../output/probe_SA_residual_pt.png");
  draw_resolution(h_probe_SA_inverse_residual_pt,"../output/probe_SA_inverse_residual_pt.png");

  draw_pt_distribution(h_mesL1_pt,h_mesSA_pt,h_mesCB_pt,h_mesEF_pt,h_probe_pt,"L1 pt","SA pt","CB pt","EF pt","offline pt","pt distribution;pt[GeV];Entries","../output/pt_distribution_All.png");
/*
  draw_efficiency(h_eff_off_L1_pt,h_probe_pt,"offvsL1_efficiency@mu26ivm;offline pt[GeV];efficiency","../output/offvsL1_efficiency@mu26ivm.png");
  draw_efficiency(h_eff_off_SA_pt,h_probe_pt,"offvsSA_efficiency@mu26ivm;offline pt[GeV];efficiency","../output/offvsSA_efficiency@mu26ivm.png");
  draw_efficiency(h_eff_off_CB_pt,h_probe_pt,"offvsCB_efficiency@mu26ivm;offline pt[GeV];efficiency","../output/offvsCB_efficiency@mu26ivm.png");
  draw_efficiency(h_eff_off_EF_pt,h_probe_pt,"offvsEF_efficiency@mu26ivm;offline pt[GeV];efficiency","../output/offvsEF_efficiency@mu26ivm.png");
*/
  draw_efficiency(h_eff_off_SA_pt,h_eff_off_L1_pt,"L1vsSA_efficiency@mu26ivm;offline pt[GeV];efficiency","../output/L1vsSA_efficiency@mu26ivm.png");
  draw_efficiency(h_eff_off_CB_pt,h_eff_off_SA_pt,"SAvsCB_efficiency@mu26ivm;offline pt[GeV];efficiency","../output/SAvsCB_efficiency@mu26ivm.png");
  draw_efficiency(h_eff_off_EF_pt,h_eff_off_CB_pt,"CBvsEF_efficiency@mu26ivm;offline pt[GeV];efficiency","../output/CBvsEF_efficiency@mu26ivm.png");


  draw_histgram(h_probe_mesSA_pt,"../output/probe_mesSA_pt.png");
  draw_histgram(h_tag_SA_pt,"../output/tag_SA_pt.png");

  delete h_probe_mesSA_pt;
  delete h_tag_SA_pt;
  delete h_probe_SA_residual_pt;
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
}


 void draw_histgram(TH1D *h1,string title){
  TCanvas *c1 = new TCanvas("c1","c1",1600,900);
  gStyle->SetTitleYOffset(1.5);
  h1->SetFillColor(kRed);
  h1->SetLineColor(kRed);
  h1->Draw();
  c1->SaveAs(title.c_str());
  h1->Write();
  delete c1;
 }

 void draw_resolution(TH1D *h1,string title){
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
  h1->Fit("fitgaus","","",-2,2);
  gStyle->SetOptFit(1111);
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

 void draw_efficiency(TH1D *h1,TH1D *h2,string title_axis,string title){
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
  c1->SaveAs(title.c_str());
  tg1->Write();
  eff_y.clear();
  eff_y_err.clear();
  delete tg1;
  delete c1; 
 }
