#include <stdio.h>
#include <iostream>
#include <iomanip>

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

int main(int argc, char** argv){
    
    if (argc<4){
      cout<<"Il programma "<<argv[0]<<"  ha bisogno di <xl>( estremo sinistro dell'intervallo), <xr> (estremo destro dell'intervallo) e <epsilon>(precisione richiesta per lo zero)"<<endl;
      return -1;
    }
    
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);
    int cifre_significative = -log10(c);
    
    parabola f (3, 5, -2);
    bisezione q;
    q.setN(100);
    int d = q.getN();
    double z=q.zeri(a,b,f,c,d);
    
    cout<<"Lo zero trovato con il metodo della bisezione è: x_0= "<<fixed<<setprecision(cifre_significative)<<z<<" con una precisione di  "<<c<<endl;
    
    TApplication app("App",0,0);
    TCanvas can ("Parabola", "Parabola");
    TF1 *t = new TF1 ("parabola","3*x^2+5*x-2", -5.,3.5);
    TF1 *assex = new TF1 ("parabola","0", -5.,3.5);
    TEllipse *zero = new TEllipse(z,0,0.06,0.6);
    TText *tes = new TText( z , -2, "x") ;

//    t->SetLineColor(kBlack);
    assex->SetLineColor(kGreen);
    t->SetTitle("Parabola");
    tes->SetTextSize(0.03);
//    tes->SetTextColorAlpha(kBlack,0.4);
    zero->SetFillColor(1);
    t->Draw();
    assex->Draw("same");
    zero->Draw("same");
    tes->Draw("same");
    
    app.Run();
    
    return 0;
}
