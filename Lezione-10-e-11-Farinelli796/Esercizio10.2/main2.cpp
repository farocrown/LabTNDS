//per compilare eseguire la seguente riga: g++ -o graph.x main2.cpp `root-config --libs` `root-config --cflags` 

#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TF1.h"
#include "TGraph.h"
#include "TAxis.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    TApplication app("app",0,0);
    unsigned int a;
    double b,val,d;
    vector<double> N,HM,MID;
    
    ifstream in;
    in.open("size.dat");
    if (!in){
      cout<<"File inesistente!"<<endl;
      return -1;
    }
      in>>a;
      in>>d;
    for (int i=0; i<a; i++) {
        in>>val;
        N.push_back(val);
    }
    in.close();
    
    vector<string> V;
    vector<string> X;
    
    for (int i=0; i<a; i++) {
        string titolo = "dataMid"+to_string(i+1)+".dat";
        string titolo2 = "dataHM"+to_string(i+1)+".dat";
        V.push_back(titolo);
        X.push_back(titolo2);
    }
    
    ifstream er1;
    er1.open("erroriMid.dat");
    ifstream er2;
    er2.open("erroriHM.dat");
    for (int i=0; i<a; i++) {
        er2>>b;
        HM.push_back(b);
        er1>>b;
        MID.push_back(b);
    }
    
    vector<TH1F> histo;
    vector<TH1F> histo1;
    for (int i=0; i<a; i++) {
        string hi = "histoMid "+to_string(i+1);
        string hi1 = "histoHM "+to_string(i+1);
        TH1F swish (hi.c_str(), hi.c_str(),100,2-5*MID[i],2+5*MID[i]);
        swish.SetCanExtend(TH1::kAllAxes);
        TH1F swish1 (hi1.c_str(), hi1.c_str(),100,2-5*HM[i],2+5*HM[i]);
        swish1.SetCanExtend(TH1::kAllAxes);
        ifstream in;
        in.open(V[i]);
        ifstream fin;
        fin.open(X[i]);
        for (int j=0; j<d; j++) {
            in>>b;
            swish.Fill(b);
            fin>>b;
            swish1.Fill(b);
        }
        in.close();
        histo.push_back(swish);
        fin.close();
        histo1.push_back(swish1);
    }

    TGraph err1,err2;
    for (int i=0; i<a; i++) {
        err1.SetPoint(i,N[i],MID[i]);
        err2.SetPoint(i,N[i],HM[i]);
    }
    
    double c=(double)a;
    c=trunc(c/2);
    
    TCanvas can("Integrale Montecarlo - Metodo Media", "Integrale Montecarlo - Metodo Media", (c+1)*500,c*500);
    can.Divide(c+1,c);
    for (int i=0; i<a; i++) {
        can.cd(i+1);
        histo[i].GetXaxis()->SetTitle("valore integrale [AU]");
        histo[i].GetYaxis()->SetTitle("occorrenze");
        histo[i].SetTitle(V[i].c_str());
        histo[i].Draw();
    }
    
    TCanvas can1("Integrale Montecarlo - Metodo <<Hit or miss>>", "Integrale Montecarlo - Metodo <<Hit or miss>>", (c+1)*500,c*500);
    can1.Divide(c+1,c);
    for (int i=0; i<a; i++) {
        can1.cd(i+1);
        histo1[i].GetXaxis()->SetTitle("valore integrale [AU]");
        histo1[i].GetYaxis()->SetTitle("occorrenze");
        histo1[i].SetTitle(X[i].c_str());
        histo1[i].Draw();
    }
    
    TCanvas can3("Grafici dell'errore in funzione di N","Grafici dell'errore in funzione di N", 1000,500);
    can3.Divide(2,1);
    can3.cd(1);
    err1.GetXaxis()->SetTitle("punti N per l'integrale [Adim]");
    err1.GetYaxis()->SetTitle("errore [UA]");
    err1.SetTitle("Errore metodo media");
    err1.SetMarkerStyle(20);
    err1.SetLineColor(8);
    err1.Draw("ALP");
    
    can3.cd(2);
    err2.GetXaxis()->SetTitle("punti N per l'integrale [Adim]");
    err2.GetYaxis()->SetTitle("errore [UA]");
    err2.SetTitle("Errore metodo <<Hit or Miss>>");
    err2.SetMarkerStyle(20);
    err2.SetLineColor(8);
    err2.Draw("ALP");
    
    app.Run();
    
    return 0;
}


