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
  simpson simp(0,acos(-1)); //M_PI

  double B = simp.integra(nstep, s);

    cout << " Passi = "  << nstep << endl ;
    cout << " Integrale simpson = "  << fixed << setprecision(10) << B << endl ;

TApplication myApp("myApp",0,0);
    
TGraph myGraph;
    
int r=4;
double a = 0;
double b = M_PI;
    for (int i=0; i<20; i++) {
        simpson MID (a,b);
        double V = MID.integra(r,s);
        double passo = abs(a-b)/r;
        myGraph.SetPoint(i,passo,abs(V-2));
        r+=4;
    }
    
//myGraph.Fit("pol4");

TCanvas * myCanvas = new TCanvas();
myCanvas->cd();

myGraph.SetTitle("Errore - metodo di Simpson");
myGraph.GetXaxis()->SetTitle("x [passo]");
myGraph.GetYaxis()->SetTitle("y [errore]");


myCanvas -> SetLogy();
myCanvas-> SetLogx();

myGraph.SetLineColor(46);
myGraph.SetMarkerStyle(20);
myGraph.Draw("ALP");
    
myApp.Run();

return 0;
}

