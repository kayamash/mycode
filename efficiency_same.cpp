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

 void draw_efficiency(TH1D *h1,TH1D *h2,TH1D *h3,TH1D *h4,TH1D *h5,TH1D *h6,TH1D *h7,TH1D *h8,TH1D *h9,TH1D *h10,TH1D *h11,TH1D *h12,TH1D *h13,TH1D *h14,string title_axis,string title,Int_t max){}

 void efficiency_same(){
  TFile *tf1 = TFile::Open("../src/Zmumu.root","read");
  TTree *tr1 = dynamic_cast<TTree*>(tf1->Get("t_tap"));
  const string name = "mu26ivm";
  const Int_t max = 60;

  TH1D *h_eff_off_L1_pt_0 = new TH1D("off_L1_pt_0","mesL1_pt;L1 pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_SA_pt_0 = new TH1D("off_SA_pt_0","mesSA_pt;SA pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_CB_pt_0 = new TH1D("off_CB_pt_0","mesCB_pt;CB pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_EF_pt_0 = new TH1D("off_EF_pt_0","mesEF_pt;EF pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_L1_pt_4 = new TH1D("off_L1_pt_4","mesL1_pt;L1 pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_SA_pt_4 = new TH1D("off_SA_pt_4","mesSA_pt;SA pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_CB_pt_4 = new TH1D("off_CB_pt_4","mesCB_pt;CB pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_EF_pt_4 = new TH1D("off_EF_pt_4","mesEF_pt;EF pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_L1_pt_8 = new TH1D("off_L1_pt_8","mesL1_pt;L1 pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_SA_pt_8 = new TH1D("off_SA_pt_8","mesSA_pt;SA pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_CB_pt_8 = new TH1D("off_CB_pt_8","mesCB_pt;CB pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_EF_pt_8 = new TH1D("off_EF_pt_8","mesEF_pt;EF pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_L1_pt_12 = new TH1D("off_L1_pt_12","mesL1_pt;L1 pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_SA_pt_12 = new TH1D("off_SA_pt_12","mesSA_pt;SA pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_CB_pt_12 = new TH1D("off_CB_pt_12","mesCB_pt;CB pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_EF_pt_12 = new TH1D("off_EF_pt_12","mesEF_pt;EF pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_L1_pt_16 = new TH1D("off_L1_pt_16","mesL1_pt;L1 pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_SA_pt_16 = new TH1D("off_SA_pt_16","mesSA_pt;SA pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_CB_pt_16 = new TH1D("off_CB_pt_16","mesCB_pt;CB pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_EF_pt_16 = new TH1D("off_EF_pt_16","mesEF_pt;EF pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_L1_pt_20 = new TH1D("off_L1_pt_20","mesL1_pt;L1 pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_SA_pt_20 = new TH1D("off_SA_pt_20","mesSA_pt;SA pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_CB_pt_20 = new TH1D("off_CB_pt_20","mesCB_pt;CB pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_EF_pt_20 = new TH1D("off_EF_pt_20","mesEF_pt;EF pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_L1_pt_26 = new TH1D("off_L1_pt_26","mesL1_pt;L1 pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_SA_pt_26 = new TH1D("off_SA_pt_26","mesSA_pt;SA pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_CB_pt_26 = new TH1D("off_CB_pt_26","mesCB_pt;CB pt[GeV];Entries",150,0,150);
  TH1D *h_eff_off_EF_pt_26 = new TH1D("off_EF_pt_26","mesEF_pt;EF pt[GeV];Entries",150,0,150);

  Double_t probe_pt;
  std::vector<string> *mes_name;
  std::vector<Double_t> *probe_mesSA_pt;
  std::vector<Int_t> *probe_mesL1_pass,*probe_mesSA_pass,*probe_mesCB_pass,*probe_mesEF_pass;
  TBranch *b_mes_name,*b_probe_mesL1_pass,*b_probe_mesSA_pass,*b_probe_mesCB_pass,*b_probe_mesEF_pass,*b_probe_mesSA_pt;

  tr1->SetBranchStatus("*",0);
  tr1->SetBranchStatus("mes_name",1);
  tr1->SetBranchStatus("probe_pt",1);
  tr1->SetBranchStatus("probe_mesL1_pass",1);
  tr1->SetBranchStatus("probe_mesSA_pass",1);
  tr1->SetBranchStatus("probe_mesCB_pass",1);
  tr1->SetBranchStatus("probe_mesEF_pass",1);
  tr1->SetBranchStatus("probe_mesSA_pt",1);

  tr1->SetBranchAddress("mes_name",&mes_name,&b_mes_name);
  tr1->SetBranchAddress("probe_pt",&probe_pt);
  tr1->SetBranchAddress("probe_mesL1_pass",&probe_mesL1_pass,&b_probe_mesL1_pass);
  tr1->SetBranchAddress("probe_mesSA_pass",&probe_mesSA_pass,&b_probe_mesSA_pass);
  tr1->SetBranchAddress("probe_mesCB_pass",&probe_mesCB_pass,&b_probe_mesCB_pass);
  tr1->SetBranchAddress("probe_mesEF_pass",&probe_mesEF_pass,&b_probe_mesEF_pass);
  tr1->SetBranchAddress("probe_mesSA_pt",&probe_mesSA_pt,&b_probe_mesSA_pt);

  Double_t threshold_SA = 0;

  for(Int_t event = 0;event < tr1->GetEntries();event++){
    tr1->GetEntry(event);
    Double_t buf_probe_pt = probe_pt;
    Int_t buf_probe_mesL1_pass = 0;
    Int_t buf_probe_mesSA_pass = 0;
    Int_t buf_probe_mesCB_pass = 0;
    Int_t buf_probe_mesEF_pass = 0;
    Double_t buf_probe_mesSA_pt = -99999;
    for(Int_t mes = 0;mes < 25;mes++){
     if(mes_name->at(mes) == name){
      buf_probe_mesL1_pass = probe_mesL1_pass->at(mes);
      buf_probe_mesSA_pass = probe_mesSA_pass->at(mes);
      buf_probe_mesCB_pass = probe_mesCB_pass->at(mes);
      buf_probe_mesEF_pass = probe_mesEF_pass->at(mes);
      buf_probe_mesSA_pt = probe_mesSA_pt->at(mes);
     }
    }
    if(buf_probe_mesL1_pass > 0){
     h_eff_off_L1_pt_0->Fill(std::fabs(buf_probe_pt*0.001));
     if(buf_probe_mesSA_pass > 0 && std::fabs(buf_probe_mesSA_pt) >= threshold_SA){
       h_eff_off_SA_pt_0->Fill(std::fabs(buf_probe_pt*0.001));
       if(buf_probe_mesCB_pass > 0){
        h_eff_off_CB_pt_0->Fill(std::fabs(buf_probe_pt*0.001));
        if(buf_probe_mesEF_pass > 0){
          h_eff_off_EF_pt_0->Fill(std::fabs(buf_probe_pt*0.001));
        }
       }
     }
   }
  }

  threshold_SA = 4.0;
  for(Int_t event = 0;event < tr1->GetEntries();event++){
    tr1->GetEntry(event);
    Double_t buf_probe_pt = probe_pt;
    Int_t buf_probe_mesL1_pass = 0;
    Int_t buf_probe_mesSA_pass = 0;
    Int_t buf_probe_mesCB_pass = 0;
    Int_t buf_probe_mesEF_pass = 0;
    Double_t buf_probe_mesSA_pt = -99999;
    for(Int_t mes = 0;mes < 25;mes++){
     if(mes_name->at(mes) == name){
      buf_probe_mesL1_pass = probe_mesL1_pass->at(mes);
      buf_probe_mesSA_pass = probe_mesSA_pass->at(mes);
      buf_probe_mesCB_pass = probe_mesCB_pass->at(mes);
      buf_probe_mesEF_pass = probe_mesEF_pass->at(mes);
      buf_probe_mesSA_pt = probe_mesSA_pt->at(mes);
     }
    }
    if(buf_probe_mesL1_pass > 0){
     h_eff_off_L1_pt_4->Fill(std::fabs(buf_probe_pt*0.001));
     if(buf_probe_mesSA_pass > 0 && std::fabs(buf_probe_mesSA_pt) >= threshold_SA){
       h_eff_off_SA_pt_4->Fill(std::fabs(buf_probe_pt*0.001));
       if(buf_probe_mesCB_pass > 0){
        h_eff_off_CB_pt_4->Fill(std::fabs(buf_probe_pt*0.001));
        if(buf_probe_mesEF_pass > 0){
          h_eff_off_EF_pt_4->Fill(std::fabs(buf_probe_pt*0.001));
        }
       }
     }
   }
  }

  threshold_SA = 8.0;
  for(Int_t event = 0;event < tr1->GetEntries();event++){
    tr1->GetEntry(event);
    Double_t buf_probe_pt = probe_pt;
    Int_t buf_probe_mesL1_pass = 0;
    Int_t buf_probe_mesSA_pass = 0;
    Int_t buf_probe_mesCB_pass = 0;
    Int_t buf_probe_mesEF_pass = 0;
    Double_t buf_probe_mesSA_pt = -99999;
    for(Int_t mes = 0;mes < 25;mes++){
     if(mes_name->at(mes) == name){
      buf_probe_mesL1_pass = probe_mesL1_pass->at(mes);
      buf_probe_mesSA_pass = probe_mesSA_pass->at(mes);
      buf_probe_mesCB_pass = probe_mesCB_pass->at(mes);
      buf_probe_mesEF_pass = probe_mesEF_pass->at(mes);
      buf_probe_mesSA_pt = probe_mesSA_pt->at(mes);
     }
    }
    if(buf_probe_mesL1_pass > 0){
     h_eff_off_L1_pt_8->Fill(std::fabs(buf_probe_pt*0.001));
     if(buf_probe_mesSA_pass > 0 && std::fabs(buf_probe_mesSA_pt) >= threshold_SA){
       h_eff_off_SA_pt_8->Fill(std::fabs(buf_probe_pt*0.001));
       if(buf_probe_mesCB_pass > 0){
        h_eff_off_CB_pt_8->Fill(std::fabs(buf_probe_pt*0.001));
        if(buf_probe_mesEF_pass > 0){
          h_eff_off_EF_pt_8->Fill(std::fabs(buf_probe_pt*0.001));
        }
       }
     }
   }
  }

  threshold_SA = 12.0;
  for(Int_t event = 0;event < tr1->GetEntries();event++){
    tr1->GetEntry(event);
    Double_t buf_probe_pt = probe_pt;
    Int_t buf_probe_mesL1_pass = 0;
    Int_t buf_probe_mesSA_pass = 0;
    Int_t buf_probe_mesCB_pass = 0;
    Int_t buf_probe_mesEF_pass = 0;
    Double_t buf_probe_mesSA_pt = -99999;
    for(Int_t mes = 0;mes < 25;mes++){
     if(mes_name->at(mes) == name){
      buf_probe_mesL1_pass = probe_mesL1_pass->at(mes);
      buf_probe_mesSA_pass = probe_mesSA_pass->at(mes);
      buf_probe_mesCB_pass = probe_mesCB_pass->at(mes);
      buf_probe_mesEF_pass = probe_mesEF_pass->at(mes);
      buf_probe_mesSA_pt = probe_mesSA_pt->at(mes);
     }
    }
    if(buf_probe_mesL1_pass > 0){
     h_eff_off_L1_pt_12->Fill(std::fabs(buf_probe_pt*0.001));
     if(buf_probe_mesSA_pass > 0 && std::fabs(buf_probe_mesSA_pt) >= threshold_SA){
       h_eff_off_SA_pt_12->Fill(std::fabs(buf_probe_pt*0.001));
       if(buf_probe_mesCB_pass > 0){
        h_eff_off_CB_pt_12->Fill(std::fabs(buf_probe_pt*0.001));
        if(buf_probe_mesEF_pass > 0){
          h_eff_off_EF_pt_12->Fill(std::fabs(buf_probe_pt*0.001));
        }
       }
     }
   }
  }

  threshold_SA = 16.0;
  for(Int_t event = 0;event < tr1->GetEntries();event++){
    tr1->GetEntry(event);
    Double_t buf_probe_pt = probe_pt;
    Int_t buf_probe_mesL1_pass = 0;
    Int_t buf_probe_mesSA_pass = 0;
    Int_t buf_probe_mesCB_pass = 0;
    Int_t buf_probe_mesEF_pass = 0;
    Double_t buf_probe_mesSA_pt = -99999;
    for(Int_t mes = 0;mes < 25;mes++){
     if(mes_name->at(mes) == name){
      buf_probe_mesL1_pass = probe_mesL1_pass->at(mes);
      buf_probe_mesSA_pass = probe_mesSA_pass->at(mes);
      buf_probe_mesCB_pass = probe_mesCB_pass->at(mes);
      buf_probe_mesEF_pass = probe_mesEF_pass->at(mes);
      buf_probe_mesSA_pt = probe_mesSA_pt->at(mes);
     }
    }
    if(buf_probe_mesL1_pass > 0){
     h_eff_off_L1_pt_16->Fill(std::fabs(buf_probe_pt*0.001));
     if(buf_probe_mesSA_pass > 0 && std::fabs(buf_probe_mesSA_pt) >= threshold_SA){
       h_eff_off_SA_pt_16->Fill(std::fabs(buf_probe_pt*0.001));
       if(buf_probe_mesCB_pass > 0){
        h_eff_off_CB_pt_16->Fill(std::fabs(buf_probe_pt*0.001));
        if(buf_probe_mesEF_pass > 0){
          h_eff_off_EF_pt_16->Fill(std::fabs(buf_probe_pt*0.001));
        }
       }
     }
   }
  }

  threshold_SA = 20.0;
  for(Int_t event = 0;event < tr1->GetEntries();event++){
    tr1->GetEntry(event);
    Double_t buf_probe_pt = probe_pt;
    Int_t buf_probe_mesL1_pass = 0;
    Int_t buf_probe_mesSA_pass = 0;
    Int_t buf_probe_mesCB_pass = 0;
    Int_t buf_probe_mesEF_pass = 0;
    Double_t buf_probe_mesSA_pt = -99999;
    for(Int_t mes = 0;mes < 25;mes++){
     if(mes_name->at(mes) == name){
      buf_probe_mesL1_pass = probe_mesL1_pass->at(mes);
      buf_probe_mesSA_pass = probe_mesSA_pass->at(mes);
      buf_probe_mesCB_pass = probe_mesCB_pass->at(mes);
      buf_probe_mesEF_pass = probe_mesEF_pass->at(mes);
      buf_probe_mesSA_pt = probe_mesSA_pt->at(mes);
     }
    }
    if(buf_probe_mesL1_pass > 0){
     h_eff_off_L1_pt_20->Fill(std::fabs(buf_probe_pt*0.001));
     if(buf_probe_mesSA_pass > 0 && std::fabs(buf_probe_mesSA_pt) >= threshold_SA){
       h_eff_off_SA_pt_20->Fill(std::fabs(buf_probe_pt*0.001));
       if(buf_probe_mesCB_pass > 0){
        h_eff_off_CB_pt_20->Fill(std::fabs(buf_probe_pt*0.001));
        if(buf_probe_mesEF_pass > 0){
          h_eff_off_EF_pt_20->Fill(std::fabs(buf_probe_pt*0.001));
        }
       }
     }
   }
  }

  threshold_SA = 26.0;
  for(Int_t event = 0;event < tr1->GetEntries();event++){
    tr1->GetEntry(event);
    Double_t buf_probe_pt = probe_pt;
    Int_t buf_probe_mesL1_pass = 0;
    Int_t buf_probe_mesSA_pass = 0;
    Int_t buf_probe_mesCB_pass = 0;
    Int_t buf_probe_mesEF_pass = 0;
    Double_t buf_probe_mesSA_pt = -99999;
    for(Int_t mes = 0;mes < 25;mes++){
     if(mes_name->at(mes) == name){
      buf_probe_mesL1_pass = probe_mesL1_pass->at(mes);
      buf_probe_mesSA_pass = probe_mesSA_pass->at(mes);
      buf_probe_mesCB_pass = probe_mesCB_pass->at(mes);
      buf_probe_mesEF_pass = probe_mesEF_pass->at(mes);
      buf_probe_mesSA_pt = probe_mesSA_pt->at(mes);
     }
    }
    if(buf_probe_mesL1_pass > 0){
     h_eff_off_L1_pt_26->Fill(std::fabs(buf_probe_pt*0.001));
     if(buf_probe_mesSA_pass > 0 && std::fabs(buf_probe_mesSA_pt) >= threshold_SA){
       h_eff_off_SA_pt_26->Fill(std::fabs(buf_probe_pt*0.001));
       if(buf_probe_mesCB_pass > 0){
        h_eff_off_CB_pt_26->Fill(std::fabs(buf_probe_pt*0.001));
        if(buf_probe_mesEF_pass > 0){
          h_eff_off_EF_pt_26->Fill(std::fabs(buf_probe_pt*0.001));
        }
       }
     }
   }
  }

  string title_threshold = name + Form("-%dGeV.png",threshold_SA);

  draw_efficiency(h_eff_off_L1_pt_0,h_eff_off_SA_pt_0,h_eff_off_L1_pt_4,h_eff_off_SA_pt_4,h_eff_off_L1_pt_8,h_eff_off_SA_pt_8,h_eff_off_L1_pt_12,h_eff_off_SA_pt_12,h_eff_off_L1_pt_16,h_eff_off_SA_pt_16,h_eff_off_L1_pt_20,h_eff_off_SA_pt_20,h_eff_off_L1_pt_26,h_eff_off_SA_pt_26,"L1vsSA_efficiency@" + name + ";offline pt[GeV];efficiency","../output/" + name + "/efficiency_allL1vsSA.png",max);
  draw_efficiency(h_eff_off_SA_pt_0,h_eff_off_CB_pt_0,h_eff_off_SA_pt_4,h_eff_off_CB_pt_4,h_eff_off_SA_pt_8,h_eff_off_CB_pt_8,h_eff_off_SA_pt_12,h_eff_off_CB_pt_12,h_eff_off_SA_pt_16,h_eff_off_CB_pt_16,h_eff_off_SA_pt_20,h_eff_off_CB_pt_20,h_eff_off_SA_pt_26,h_eff_off_CB_pt_26,"SAvsCB_efficiency@" + name + ";offline pt[GeV];efficiency","../output/" + name + "/efficiency_allSAvsCB.png",max);
  draw_efficiency(h_eff_off_CB_pt_0,h_eff_off_EF_pt_0,h_eff_off_CB_pt_4,h_eff_off_EF_pt_4,h_eff_off_CB_pt_8,h_eff_off_EF_pt_8,h_eff_off_CB_pt_12,h_eff_off_EF_pt_12,h_eff_off_CB_pt_16,h_eff_off_EF_pt_16,h_eff_off_CB_pt_20,h_eff_off_EF_pt_20,h_eff_off_CB_pt_26,h_eff_off_EF_pt_26,"CBvsEF_efficiency@" + name + ";offline pt[GeV];efficiency","../output/" + name + "/efficiency_allCBvsEF.png",max);

  delete h_eff_off_L1_pt_0;
  delete h_eff_off_SA_pt_0;
  delete h_eff_off_L1_pt_4;
  delete h_eff_off_SA_pt_4;
  delete h_eff_off_L1_pt_8;
  delete h_eff_off_SA_pt_8;
  delete h_eff_off_L1_pt_12;
  delete h_eff_off_SA_pt_12;
  delete h_eff_off_L1_pt_16;
  delete h_eff_off_SA_pt_16;
  delete h_eff_off_L1_pt_20;
  delete h_eff_off_SA_pt_20;
  delete h_eff_off_L1_pt_26;
  delete h_eff_off_SA_pt_26;
  delete h_eff_off_CB_pt_0;
  delete h_eff_off_EF_pt_0;
  delete h_eff_off_CB_pt_4;
  delete h_eff_off_EF_pt_4;
  delete h_eff_off_CB_pt_8;
  delete h_eff_off_EF_pt_8;
  delete h_eff_off_CB_pt_12;
  delete h_eff_off_EF_pt_12;
  delete h_eff_off_CB_pt_16;
  delete h_eff_off_EF_pt_16;
  delete h_eff_off_CB_pt_20;
  delete h_eff_off_EF_pt_20;
  delete h_eff_off_CB_pt_26;
  delete h_eff_off_EF_pt_26;
  probe_mesL1_pass->clear();
  probe_mesSA_pass->clear();
  probe_mesCB_pass->clear();
  probe_mesEF_pass->clear();
  mes_name->clear();
}




 void draw_efficiency(TH1D *h1,TH1D *h2,TH1D *h3,TH1D *h4,TH1D *h5,TH1D *h6,TH1D *h7,TH1D *h8,TH1D *h9,TH1D *h10,TH1D *h11,TH1D *h12,TH1D *h13,TH1D *h14,string title_axis,string title,Int_t max){
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
  vector<Double_t> eff_x6;
  vector<Double_t> eff_y6;
  vector<Double_t> eff_x6_err;
  vector<Double_t> eff_y6_err;
  vector<Double_t> eff_x7;
  vector<Double_t> eff_y7;
  vector<Double_t> eff_x7_err;
  vector<Double_t> eff_y7_err;
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
    Double_t buf_11 = static_cast<Double_t>(h11->GetBinContent(i));
    Double_t buf_12 = static_cast<Double_t>(h12->GetBinContent(i));
    Double_t buf_13 = static_cast<Double_t>(h13->GetBinContent(i));
    Double_t buf_14 = static_cast<Double_t>(h14->GetBinContent(i));
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
    if(buf_11 != 0){
     eff_y6.push_back(buf_12/buf_11);
     eff_y6_err.push_back(sqrt(buf_12*(1 - buf_12/buf_11))/buf_11);
     eff_x6.push_back(static_cast<Double_t>(i));
     eff_x6_err.push_back(0.5);
    }
    if(buf_13 != 0){
     eff_y7.push_back(buf_14/buf_13);
     eff_y7_err.push_back(sqrt(buf_14*(1 - buf_14/buf_13))/buf_13);
     eff_x7.push_back(static_cast<Double_t>(i));
     eff_x7_err.push_back(0.5);
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
  TGraphErrors *tg6 = new TGraphErrors(eff_x6.size(),&(eff_x6.at(0)),&(eff_y6.at(0)),&(eff_x6_err.at(0)),&(eff_y6_err.at(0)));
  tg6->SetMarkerStyle(20);
  tg6->SetMarkerSize(1.0);
  tg6->SetMarkerColor(kOrange);
  tg6->Draw("P");
  TGraphErrors *tg7 = new TGraphErrors(eff_x7.size(),&(eff_x7.at(0)),&(eff_y7.at(0)),&(eff_x7_err.at(0)),&(eff_y7_err.at(0)));
  tg7->SetMarkerStyle(20);
  tg7->SetMarkerSize(1.0);
  tg7->SetMarkerColor(kPink);
  tg7->Draw("P");

  TLegend *legend = new TLegend(0.7,0.1,0.9,0.4,"");
  legend->AddEntry(tg1,"threshold_SA pt = 0GeV","lep");
  legend->AddEntry(tg2,"threshold_SA pt = 4GeV","lep");
  legend->AddEntry(tg3,"threshold_SA pt = 8GeV","lep");
  legend->AddEntry(tg4,"threshold_SA pt = 12GeV","lep");
  legend->AddEntry(tg5,"threshold_SA pt = 16GeV","lep");
  legend->AddEntry(tg6,"threshold_SA pt = 20GeV","lep");
  legend->AddEntry(tg7,"threshold_SA pt = 26GeV","lep");
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
  eff_x4.clear();
  eff_y4.clear();
  eff_x4_err.clear();
  eff_y4_err.clear();
  eff_x5.clear();
  eff_y5.clear();
  eff_x5_err.clear();
  eff_y5_err.clear();
  eff_x6.clear();
  eff_y6.clear();
  eff_x6_err.clear();
  eff_y6_err.clear();
  eff_x7.clear();
  eff_y7.clear();
  eff_x7_err.clear();
  eff_y7_err.clear();
  delete tg1;
  delete tg2;
  delete tg3;
  delete tg4;
  delete tg5;
  delete tg6;
  delete tg7;
  delete c1; 
  }


