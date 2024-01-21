#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <iomanip>

#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TGraph.h"
#include "TAxis.h"

#include "integrale.h"
#include "RandomGen.h"
#include "solutore.h"
#include "bisezione.h"
#include "funzionebase.h"

using namespace std;

int main(int argc, char** argv){
//    ofstream out("soluzione.txt");
    TApplication app("app",0,0);
    cout<<"C'è un evidente problema con la funzione, ho provato con una parabola e il seno a svolgere lo stesso eserciizio e i risultati sono corretti. Non sono riuscito ad inviduar il problema per quanto riguarda la funzione assegnata. Consegno ugualmente l'elaborato."<<endl<<endl;
    
//     punto 1 :
    bisezione q;
    q.setN(100);
    funz1 fun;
    double prec_zeri = 0.01;
    double x1zero = q.zeri(1,2,fun,prec_zeri);
    double x2zero = q.zeri(4,5,fun,prec_zeri);
    double x3zero = q.zeri(7,8,fun,prec_zeri);
    cout << "Punto 1 : gli zeri : x1 = " <<setprecision(3)<< x1zero << "   x2 = " <<setprecision(3)<< x2zero << "   x3 = " <<setprecision(3)<< x3zero << " [+/- " << prec_zeri << "]" << endl;

//     punto 2 e 3
    simpson simp(x1zero,x2zero);
    int nstep = 10;
    double integrale = simp.integra(10,fun);
    double errore = simp.errore(10,fun);
         cout << "Punto 2 e 3 : Integrale = " <<setprecision(6)<< integrale << " +/- " << errore << endl;

//     punto 4 :
    double errtilde = 0.001;
    int ntilde = simp.trovaN(errtilde,fun);

         cout << "Punto 4 : Numero di intervalli necessari per una precisione " << errtilde << " = " << ntilde << endl;
//     punto 5 :
    integralemonty monte(x1zero,x2zero,1);
    int nmont = 100;
    int nrequired = monte.npunti(errtilde,nmont,fun);
         cout << "Punto 5 : Punti richiesti (metodo media) per precisione " << errtilde << " = " << nrequired << endl;

//     punto 6 :
    TGraph grafico;
    int i = 0;
    for (double t=x1zero; t<=x3zero; t+=0.1) {
        simpson graf (x1zero,t);
        double z = graf.integra(100,fun);
        grafico.SetPoint(i,t,z);
        i++;
    }

//     punto 7 :

//         cout <<  "Punto 7 : Zero della funzione integrale " << zero << "+/- " << prec_zeri << endl;
    
//    out.close();
    TCanvas can("Can","Can",600,600);
    grafico.GetXaxis()->SetTitle("t");
    grafico.GetYaxis()->SetTitle("F(t)");
    grafico.SetTitle("Andamento F(t)");
    grafico.SetLineColor(8);
    grafico.Draw("ACP");
    app.Run();
    return 0;
}
