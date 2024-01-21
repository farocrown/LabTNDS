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
  
    if(argc != 2)
    {
    cerr << "Per utilizzare il programma " << argv[0]  << " devi inserire <passo_di_integrazione>" << endl;
    return -1;
    }
    
    double h = atof(argv[1]); //precisione inserita
    Pendolo pendolino(1.); //equazione differenziale y''=-g/l*sin(y)
    RK4 rungidame;
    
    vector<double> X {0.,0.};
    double t = 0.;
    
    TApplication app("app",0,0);
    TCanvas can("Periodo del pendolo in funzione dell'ampiezza","Periodo del pendolo in funzione dell'ampiezza",500,500);
    TGraph periodo;
        
    for (int i=0; i<30; i++) {
        double a = 0.1*(i+1);
        double v = 0.;
        double t = 0.;
        double tu = 0.;
        vector<double> X {-a,v};
        
        while (X[1]>=0.) {
            v=X[1];
            tu=t;
            X=rungidame.passo(t,X,h,pendolino);
            t+=h;
        }
        double p = 2*(tu - h*X[1]/(v-X[1]));
        periodo.SetPoint(i,a,p);
    }
    
    periodo.GetXaxis()->SetTitle("ampiezza [rad]");
    periodo.GetYaxis()->SetTitle("periodo [s]");
    periodo.SetTitle("Periodo del pendolo in funzione dell'ampiezza");
    periodo.SetLineColor(8);
    periodo.SetMarkerStyle(20);
    periodo.Draw("ACP");
    
    app.Run();

  return 0;
}



