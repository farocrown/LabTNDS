#include <iostream>
#include <stdio.h>
#include <cmath>
#include<iomanip>

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
    RK4 rungidame;

    TApplication app("app",0,0);
    TCanvas can1("Runge-Kutta","Runge-Kutta",1500,500);
    TCanvas can2("Runge-Kutta errore","Runge-Kutta errore",700,500);
    can1.Divide(2,1);
    TGraph eu;
    TGraph error;
    TGraph taccitua;
    string titolo = "Oscillatore armonico: metodo di Runge-Kutta (ordine 4) con passo h="+to_string(h);
    string titolo2 = "Oscillatore armonico: errore metodo di Runge-Kutta (ordine 4) con passo h="+to_string(h);
    for (int i=0; i<nstep; i++) {
        eu.SetPoint(i,t,X[0]);
        taccitua.SetPoint(i,t,sin(t)-X[0]);
        X=rungidame.passo(t, X, h, o);
        t+=h;
    }
    
    double hmin = 0.1;
    for (int i=0; i<10; i++) {
        int n = int(tmax/hmin + 0.5);
        X = {0.,1.};
        t=0.;
            for (int j=0; j<n; j++) {
                X=rungidame.passo(t, X, hmin, o);
                t+=hmin;
            }
//        cout<<i+1<<") "<<fixed<<setprecision(20)<<X[0]<<endl;
//        cout<<i+1<<") "<<fixed<<setprecision(20)<<abs(X[0]-sin(n*hmin))<<endl;
        error.SetPoint(i,hmin,abs(X[0]-sin(n*hmin)));
        hmin=hmin/2.;
    }
    cout<<sin(70)<<endl;
    
    can1.cd(1); //primo grafico: risoluzione equa diff
    eu.GetXaxis()->SetTitle("tempo [t]");
    eu.GetYaxis()->SetTitle("x(t) [m]");
    eu.SetTitle(titolo.c_str());
    eu.SetLineColor(8);
    eu.Draw("ACP");
    
    can1.cd(2); //errore metodo
    taccitua.GetXaxis()->SetTitle("tempo [s]");
    taccitua.GetYaxis()->SetTitle("errore su x(t) [m]");
    taccitua.SetTitle(titolo2.c_str());
    taccitua.SetLineColor(6);
    taccitua.Draw("ACP");
    
    can2.cd(); //errore accumulato a tot tempo
    error.GetXaxis()->SetTitle("passo [s]");
    error.GetYaxis()->SetTitle("errore a 70 s [m]");
    error.SetTitle("Oscillatore armonico: errore in funzione del passo h");
    error.SetLineColor(4);
    error.SetMarkerStyle(21);
    can2.SetLogx();
    can2.SetLogy();
    error.Draw("ALP");
    
    app.Run();

  return 0;
}



