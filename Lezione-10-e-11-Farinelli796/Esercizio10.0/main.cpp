#include <stdio.h>
#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include <iostream>
#include "RandomGen.h"

using namespace std;

int main(int argc, char**argv) {
    
    /*if (argc!=7) {
        cerr << "Per utilizzare il programma " << argv[0]  << " devi inserire: " << endl << "Uniforme :<seme>, <min> e <max>" << endl <<"Esponenziale: <lambda>" << endl <<"Gauss: <media> e <sigma>" << endl;
        return -1;
    }
    
    double seed = atof(argv[1]);
    double min = atof(argv[2]);
    double max = atof(argv[3]);
    double lambda = atof(argv[4]);
    double media = atof(argv[5]);
    double sigma = atof(argv[6]);*/
    
    double seed = 1;
    double min = 5;
    double max = 10;
    double lambda = 1;
    double media = 1;
    double sigma = 1;
    int nmax = 1000000;
    
    TApplication app("app",0,0);
    RandomGen gene(seed);

    TH1F unif("Uniforme", "Uniforme",100,min-1,max+1) ;
    for ( int k = 0 ; k < nmax ; k++ ) {
        unif.Fill(gene.Unif(min,max));
    }
    
    gene.SetS(seed);
    TH1F exp("Esponenziale", "Esponenziale",100,0,3*M_E/lambda) ;
    for ( int k = 0 ; k < nmax ; k++ ) {
        exp.Fill(gene.Exp(lambda));
    }
    
    gene.SetS(seed);
    TH1F gauss1("Gauss - Box Muller", "Gauss - Box Muller",100,media-4*sigma,media+4*sigma) ;
    for ( int k = 0 ; k < nmax ; k++ ) {
        gauss1.Fill(gene.Gauss(media, sigma));
    }
    
    gene.SetS(seed);
    TH1F gauss2("Gauss - Accepted/Rejected", "Gauss - Accepted/Rejected",100,media-4*sigma,media+4*sigma) ;
    for ( int k = 0 ; k < nmax ; k++ ) {
        gauss2.Fill(gene.GaussAR(media, sigma));
    }
    
    TCanvas can("Generatori di numeri casuali", "Generatori di numeri casuali", 1200,800);
    can.Divide(2,2);
    
    can.cd(1);
    unif.GetXaxis()->SetTitle("x [AU]");
    unif.GetYaxis()->SetTitle("N");
    unif.Draw();
    
    can.cd(2);
    exp.GetXaxis()->SetTitle("x [AU]");
    exp.GetYaxis()->SetTitle("N");
    exp.Draw();
    
    can.cd(3);
    gauss1.GetXaxis()->SetTitle("x [AU]");
    gauss1.GetYaxis()->SetTitle("N");
    gauss1.Draw();
    
    can.cd(4);
    gauss2.GetXaxis()->SetTitle("x [AU]");
    gauss2.GetYaxis()->SetTitle("N");
    gauss2.Draw();
    
    app.Run();
    return 0;
}
