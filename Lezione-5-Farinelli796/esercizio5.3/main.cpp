#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

#include "puntomateriale.h"
#include "campovettoriale.h"


#include "TH1F.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TArrow.h"
#include "TEllipse.h"
#include "TText.h"
#include "TPaveText.h"

using namespace std;

int main(int argc, char** argv){

if (argc!=4){
    cout<<"Il programma "<<argv[0]<<"  ha bisogno di  <x>, <y> e <z>, ovvero la posizione scelta per calcolare il campo elettrico di un dipolo elettrone-protone."<<endl;
    return -1;
}
double x = atof(argv[1]);
double y = atof(argv[2]);
double z = atof(argv[3]);
posizione q (x,y,z);

double e = 1.60217653E-19;
double mp = 1.67262171E-27;
double me = 9.1093826E-31;
double d = 1.0E-10;

puntomateriale elettrone (0, 0, d/2, me, -e);
puntomateriale protone (0, 0, -d/2, mp, e);

campovettoriale E = elettrone.campoElettrico(q)+protone.campoElettrico(q);
    cout<<endl;
    cout<<"\tPosizione inserita (m): P ("<<x<<"\t"<<y<<"\t"<<z<<")"<<endl;
    cout<<"\tModulo del campo elettrico in P: "<<E.modulo()<<" V/m"<<endl;
    cout<<"\tComponenti del vettore campo elettrico in P (V/m) : ("<<E.getFx()<<"\t"<<E.getFy()<<"\t"<<E.getFz()<<")"<<endl;
    cout<<endl;
    
TApplication app("App",0,0);
TGraph field;
posizione P (0,0,0);
//double E1=0;
//double E2=0;
for(int k=100; k<=1000; k++){
    P.setZ(k*d);
    campovettoriale Ed = elettrone.campoElettrico(P)+protone.campoElettrico(P);
//    if(k==100) E1=Ed.modulo();
//    if(k==1000) E2=Ed.modulo();
    field.SetPoint(k-100, k*d, Ed.modulo());
}

TCanvas can ("Andamento del campo elettrico del dipolo", "Andamento del campo elettrico del dipolo");
can.SetLogy(); //scala le y
field.GetXaxis()->SetTitle("Distanza [m]");
field.GetYaxis()->SetTitle("Modulo del campo elettrico [V/m]");
field.SetTitle("Andamento del campo elettrico del dipolo");
field.Draw("ALP");
//field.SaveAs("Andamento campo.png");
    
    int maxind=10;
    TCanvas * canplot = new TCanvas("Campo del dipolo","Campo del dipolo",800,800) ;
    canplot->cd();
    canplot->DrawFrame (-maxind*d,-maxind*d,maxind*d,maxind*d, "Campo del dipolo;y[m];z[m]");
        
    for ( int k = -maxind ; k <= maxind ; k++ ) {
        for ( int j = -maxind ; j <=maxind ; j++ ) {
            if ( sqrt( k*k + j*j  ) < 4  ) continue ;
            double pz = k*d ;
            double py = j*d ;
            P.setZ( pz ) ;
            P.setY( py ) ;
            campovettoriale Ed = protone.campoElettrico(P) + elettrone.campoElettrico(P) ;
            double scale = 20E-21;
            TArrow *field = new TArrow( py , pz  , py + Ed.getFy()*scale, pz + Ed.getFz()*scale, 0.01 ,">") ;
            field->Draw(">same");
        }
    }
    
    TEllipse * Elettrone = new TEllipse(0,d/2, d/4 ) ;
    TEllipse * Protone = new TEllipse(0,-d/2, d/4 ) ;
    TText *meno = new TText( 0  , d/2, "-") ;
    meno->SetTextAlign(22);
    meno->SetTextSize(0.03);
    TText *piu = new TText( 0  , -d/2, "+") ;
    piu->SetTextAlign(22);
    piu->SetTextSize(0.02);

    Elettrone->SetFillColor(41);
    Protone->SetFillColor(46);
    Elettrone->Draw("same");
    Protone->Draw("same");
    meno->Draw("same");
    piu->Draw("same");

canplot->SaveAs("elettrone-protone.pdf");
    
app.Run();

return 0;
}
