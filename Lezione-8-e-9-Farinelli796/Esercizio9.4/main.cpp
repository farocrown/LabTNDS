#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"

#include "equadiff.h"

using namespace std;

int main(int argc, char** argv){
    
    double omega0 = 10.; //w0
    double gamma = 1/30.; //2γ
    double tempokill = 10./gamma;
    double F = 1.; //F0/m
    double h = 0.01; //passo
    int nstep = 40;
    RK4 rungidame;
    OscArFor osc (omega0,gamma,F,9.95);
    double t = 0.;
    vector<double> X {0.,0.};
    
    
    TApplication app("app",0,0);
    TCanvas can("Oscillatore forzato","Oscillatore forzato",1500,500);
    can.Divide(2,1);
    TGraph forzato;
    TGraph lorentziana;
    int i=0;
    
    do {
        X=rungidame.passo(t,X,h,osc);
        forzato.SetPoint(i,t,X[0]);
        t+=h;
        i++;
    } while (t<tempokill);
    
    for (int i=0; i<nstep; i++) {
        double wf = 0.9*omega0+(0.2*omega0/nstep)*(i+1);
        osc.setAMPL(wf);
        X = {0.,0.};
        t=0.;
        double x = 0.;
        double v = 0.;
        double y = 0.;
        do {
            X=rungidame.passo(t,X,h,osc);
            t+=h;
        } while (t<tempokill);
        for (int j=0; j<30; j++) {
            do {
                x = X[0];
                v = X[1];
                X=rungidame.passo(t,X,h,osc);
                t+=h;
            } while (X[1]*v>=0);
            if (fabs(x)>=fabs(X[0])) y+=fabs(x);
                else y+=fabs(X[0]);
                }
//        cout<<i+1<<") "<<y<<endl;
        lorentziana.SetPoint(i,wf,y/30.);   //bisogna dividere per 30
    }

    can.cd(1);
    forzato.GetXaxis()->SetTitle("tempo [s]");
    forzato.GetYaxis()->SetTitle("posizione [m]");
    forzato.SetTitle("Oscillazione forzata (wf = 9.9 rad/s)");
    forzato.SetLineColor(8);
    forzato.Draw("ACP");
    
    can.cd(2);
    lorentziana.GetXaxis()->SetTitle("pulsazione forzante [rad/s]");
    lorentziana.GetYaxis()->SetTitle("ampiezza [m]");
    lorentziana.SetTitle("Lorentziana");
    lorentziana.SetLineColor(2);
    lorentziana.SetMarkerStyle(20);
    lorentziana.Draw("ACP");
    
    app.Run();

  return 0;
}



