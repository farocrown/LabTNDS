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
    cerr << "Per utilizzare il programma "<< argv[0] << " è necessario inserire: <precisione>" << endl;
    return -1;
    }

    double eps = atof(argv[1]);
    int prec = precisione(eps);

    debye s();
    trapezi myInt(0,acos(-1)); //M_PI
    
    int az = myInt.trovah(eps, s);
    double I = myInt.integra(az, s);
    

    cout << " Passi = "  << az << endl ;
    cout << " Integrale = "  << fixed << setprecision(prec) << I << endl ;
    cout << " Incertezza = "  << eps << endl ;
    
    TApplication myApp("myApp",0,0);
        
    TGraph trap;

    int k = 4;
    double a = 0;
    double b = M_PI;
    for (int i=0; i<20; i++) {
        trapezi MID (a,b);
        double V = MID.integra(k,s);
        double passo = abs(a-b)/k;
        trap.SetPoint(i,passo,abs(V-2));
        k+=4;
    }
        
    TCanvas * myCanvas = new TCanvas();
    myCanvas->cd();

    trap.SetTitle("Errore - metodo dei trapezi");
    trap.GetXaxis()->SetTitle("x [passo h]");
    trap.GetYaxis()->SetTitle("y [errore]");

    myCanvas -> SetLogy();
    myCanvas-> SetLogx();
    
    trap.SetLineColor(46);
    trap.SetMarkerStyle(20);
    trap.Draw("ALP");
        
    myApp.Run();

    return 0;


}