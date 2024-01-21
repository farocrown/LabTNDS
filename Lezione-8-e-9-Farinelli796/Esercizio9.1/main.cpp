#include <iostream>
#include <stdio.h>
#include <cmath>

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"

#include "equadiff.h"

using namespace std;

int main(int argc, char** argv){
  
    if(argc != 3)
    {
    cerr << "Per utilizzare il programma " << argv[0]  << " devi inserire <passo_di_integrazione> e <tempo_massimo> " << endl;
    return -1;
    }
    
    double h = atof(argv[1]); //precisione inserita
    double tmax = atof(argv[2]); //tempo massimo
    double t=0.; //tempo iniziale
    vector<double> X = {0.,1.}; //condizioni iniziali {posizione, velocità}
    int nstep = trunc(tmax/h)+1; //numero di iterazioni necessarie
    OscAr o(1.); //equazione differenziale y''=-w^2*y
    Eulero euler;

    TApplication app("app",0,0);
    TCanvas can1("Eulero","Eulero",1500,500);
    TCanvas can2("Eulero errore","Eulero errore",700,500);
    can1.Divide(2,1);
    TGraph eu;
    TGraph error;
    TGraph taccitua;
    string titolo = "Oscillatore armonico: metodo di Eulero con passo h="+to_string(h);
    string titolo2 = "Oscillatore armonico: errore in funzione del passo h";
    for (int i=0; i<nstep; i++) {
        eu.SetPoint(i,t,X[0]);
        taccitua.SetPoint(i,t,sin(t)-X[0]);
        X=euler.passo(t, X, h, o);
        t+=h;
    }
    double hmin = 0.1;
    for (int i=0; i<10; i++) {
        int n = int(tmax/hmin + 0.5);
        X = {0.,1.};
        t=0.;
            for (int j=0; j<n; j++) {
                X=euler.passo(t, X, hmin, o);
                t+=hmin;
            }
        error.SetPoint(i,hmin,(X[0]-sin(hmin*n)));
        hmin=hmin/2.;
    }
    
    can1.cd(1); //primo grafico: risoluzione equa diff
    eu.GetXaxis()->SetTitle("tempo [t]");
    eu.GetYaxis()->SetTitle("x(t) [m]");
    eu.SetTitle(titolo.c_str());
    eu.SetLineColor(8);
//    eu.SetLineWidth(2);
    eu.Draw("ACP");
    
    can1.cd(2);
    taccitua.GetXaxis()->SetTitle("tempo [s]");
    taccitua.GetYaxis()->SetTitle("errore su x(t) [m]");
    taccitua.SetTitle(titolo2.c_str());
    taccitua.SetLineColor(6);
//    error.SetMarkerStyle(21);
//    error.SetLineWidth(2);
    taccitua.Draw("ACP");
    
    can2.cd();
    error.GetXaxis()->SetTitle("passo [s]");
    error.GetYaxis()->SetTitle("errore a 70 s [m]");
    error.SetTitle(titolo2.c_str());
    error.SetLineColor(4);
    error.SetMarkerStyle(21);
    can2.SetLogx();
    can2.SetLogy();
//    error.SetLineWidth(2);
    error.Draw("ALP");
    
//    can.cd(3);
    
    
    app.Run();

  return 0;
}


