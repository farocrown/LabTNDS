#include <cmath>
#include <iostream>
#include <iomanip>

#include "TGraph.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TApplication.h"
#include "TAxis.h"
#include "TLegend.h"
#include "TPad.h"

#include "integrale.h"

using namespace std;

int main(int argc, char * argv[] ) {
  
    if (argc != 2) {
        cerr << "Per utilizzare il programma "<< argv[0] << " è necessario inserire: <nstep>" << endl;
        return -1;
    }

    unsigned int nstep = atoi(argv[1]);

    seno s(1,1,0);
    midpoint myInt(0,acos(-1)); //M_PI

    double I = myInt.integra(nstep, s);

    cout << " Passi = "  << nstep << endl ;
    cout << " Integrale = "  << fixed << setprecision(10) << I << endl ;

    TApplication myApp("myApp",0,0);
    TGraph mide;

    int k = 4;
    double a = 0;
    double b = M_PI;
    for (int i=0; i<20; i++) {
        midpoint MID (a,b);
        double V = MID.integra(k,s);
        double passo = abs(a-b)/k;
        mide.SetPoint(i,passo,abs(V-2));
        k+=4;
    }
    
    TCanvas * myCanvas = new TCanvas();
    myCanvas->cd();

    mide.SetTitle("Errore - metodo Midpoint");
    mide.GetXaxis()->SetTitle("x [passo]");
    mide.GetYaxis()->SetTitle("y [errore]");
    
//    mide.Fit("pol2");

    myCanvas -> SetLogy();
    myCanvas-> SetLogx();
    
    mide.SetLineColor(46);
    mide.SetMarkerStyle(20);
    mide.Draw("ALP");

    myApp.Run();

  return 0;
}
