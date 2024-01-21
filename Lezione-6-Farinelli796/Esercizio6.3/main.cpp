#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cmath>
//#include <vector>

#include "funzionebase.h"
#include "solutore.h"
#include "bisezione.h"

#include "TH1F.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TEllipse.h"
#include "TText.h"
#include "TPaveText.h"

int main(/*int argc, char** argv*/){
    
  /*  if (argc<4){
      cout<<"Il programma "<<argv[0]<<"  ha bisogno di <xl>( estremo sinistro dell'intervallo), <xr> (estremo destro dell'intervallo) e <epsilon>(precisione richiesta per lo zero)"<<endl;
      return -1;
    }
   */
    double pi = acos(-1);
    double pimez = asin(1);
    double c = 1E-6;
//    vector<double> V;
//    vector<TEllipse> E;
    int cifre_significative = -log10(c);
    sincope f;
    bisezione q;
    q.setN(100);
    int d = q.getN();
    
    cout<<endl<<"\tCerco 20 zeri della funzione"<<endl<<"\t\t\t\t\t\tf(x)=tan(x)-x"<<endl<<"\tcon una precisione ε=10^-6."<<endl;
    cout<<endl<<"\tUtilizzando il metodi della bisezione sulla funzione g(x)=sin(x)-xcos(x), che ha gli stessi zeri di f(x), ma è continua su tutto R,ottengo i seguenti risultati:"<<endl<<endl;
    for (int n=1; n<=20; n++) {
        double xmin = n*pi;
        double xmax = xmin + pimez;
        double z = q.zeri(xmin,xmax,f,c,d);
//        V.push_back(z);
        cout<<"\t"<<n<<") intervallo ("<<n<<"π,"<<2*n+1<<"π/2) :\tx= "<<fixed<<setprecision(cifre_significative)<<z<<endl;
    }
    
    /*double z = q.zeri(pi,pi+pimez,f,c,d);
    TApplication app("App",0,0);
    TCanvas can ("Primo zero di f(x)=tan(x)-x", "Primo zero di f(x)=tan(x)-x");
    TF1 *t = new TF1 ("sin(x)-x*cos(x)","sin(x)-x*cos(x)", 2,70);
    TF1 *assex = new TF1 ("tan(x)-x","0", 2,70);
    for (int n=0; n<20; n++) {
        TEllipse *zero = new TEllipse(V[n],0,0.03,0.9);
        E[n]=*zero;
    }
//    TText *tes = new TText( z , -4, "x") ;

//    t->SetLineColor(kBlack);
    assex->SetLineColor(kGreen);
    t->SetTitle("f(x)=tan(x)-x");
//    tes->SetTextSize(0.03);
//    tes->SetTextColorAlpha(kBlack,0.4);
//    zero->SetFillColor(1);
    t->Draw();
    assex->Draw("same");
    for (int n=0; n<20; n++) {
        E[n].Draw("same");
    }
//    zero->Draw("same");
//    tes->Draw("same");
    
    app.Run();*/
    
    return 0;
}
