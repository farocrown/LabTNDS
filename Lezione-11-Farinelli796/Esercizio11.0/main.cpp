#include <iostream>
#include <stdio.h>
#include <vector>
#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TAxis.h"
#include "prisma.h"
#include "RandomGen.h"

using namespace std;
int main(int argc, char** argv) {
    if(argc!=3){
        cout<<"Errore: per funzionare, il programma "<<argv[0]<<" ha bisogno di <n di iterazioni> e <teta0 [rad]>"<<endl;
        exit(-39);
    }
    unsigned int nit = atoi(argv[1]);
    double teta0 = atof(argv[2]);
    
    TApplication app("app",0,0);
    EsperimentoPrisma exp(teta0);
    
    vector<string> S {"Distribuzione dei " + to_string(nit) + " valori simulati per theta0", "Distribuzione dei " + to_string(nit) + " valori simulati per theta1", "Distribuzione dei " + to_string(nit) + " valori simulati per theta2"};
    
    TH1F histo1("Parametri1",S[0].c_str(),100,0,0);
    histo1.SetCanExtend(TH1::kAllAxes);
    histo1.StatOverflows(kTRUE);
    TH1F histo2("Parametri2",S[1].c_str(),100,0,0);
    histo2.SetCanExtend(TH1::kAllAxes);
    histo2.StatOverflows(kTRUE);
    TH1F histo3("Parametri3",S[2].c_str(),100,0,0);
    histo3.SetCanExtend(TH1::kAllAxes);
    histo3.StatOverflows(kTRUE);
    
    TH1F Datt1("Parametri4","Differenza tra deltam1 atteso e deltam1 misurato",100,0,0);
    histo1.SetCanExtend(TH1::kAllAxes);
    histo1.StatOverflows(kTRUE);
    TH1F Datt2("Parametri5","Differenza tra deltam2 atteso e deltam2 misurato",100,0,0);
    Datt2.SetCanExtend(TH1::kAllAxes);
    Datt2.StatOverflows(kTRUE);
    
    TH1F Natt1("Parametri6","Differenza tra n1 atteso e n1 misurato",100,0,0);
    Natt1.SetCanExtend(TH1::kAllAxes);
    Natt1.StatOverflows(kTRUE);
    TH1F Natt2("Parametri7","Differenza tra n2 atteso e n2 misurato",100,0,0);
    Natt2.SetCanExtend(TH1::kAllAxes);
    Natt2.StatOverflows(kTRUE);
    
    TH1F Aatt("Parametri8","Differenza tra A atteso e A misurato",100,0,0);
    Aatt.SetCanExtend(TH1::kAllAxes);
    Aatt.StatOverflows(kTRUE);
    TH1F Batt("Parametri9","Differenza tra B atteso e B misurato",100,0,0);
    Batt.SetCanExtend(TH1::kAllAxes);
    Batt.StatOverflows(kTRUE);
    
    TH2F Diff1 ("Parametri10", "differenze di deltam1 e deltam2",100,0,0,100,0,0);
    Diff1.SetCanExtend(TH2::kAllAxes);
    Diff1.StatOverflows(kTRUE);
    TH2F Diff2 ("Parametri11", "differenze di n1 e n2",100,0,0,100,0,0);
    Diff1.SetCanExtend(TH2::kAllAxes);
    Diff1.StatOverflows(kTRUE);
    TH2F Diff3 ("Parametri12", "differenze di A e B",100,0,0,100,0,0);
    Diff3.SetCanExtend(TH2::kAllAxes);
    Diff3.StatOverflows(kTRUE);
    
    /*Parte II
    Aggiungere alla classe un metodo Analizza() che faccia i calcoli relativi all'analisi dati ed estendere il programma in modo da eseguire l'analisi dati dei 10000 esperimenti e fare istogrammi di:
    differenza tra i valori misurati e quelli attesi di δm(λ1) e δm(λ2), quello bidimensionale delle differenze per le due lunghezze d'onda, e calcolare il coefficiente di correlazione.
    differenza tra i valori misurati e quelli attesi di n(λ1) e n(λ2), quello bidimensionale delle differenze per le due lunghezze d'onda, e calcolare il coefficiente di correlazione.
    differenza tra i valori misurati e quelli attesi di A e B, quello bidimensionale delle differenze, e calcolare il coefficiente di correlazione.*/
    
    for (int j=0; j<nit; j++) {
        exp.Misura();
        exp.Analizza();
        histo1.Fill(exp.GetT0m());
        histo2.Fill(exp.GetT1m());
        histo3.Fill(exp.GetT2m());
        Datt1.Fill(exp.GetD1m()-exp.GetD1i());
        Datt2.Fill(exp.GetD2m()-exp.GetD2i());
        Natt1.Fill(exp.GetN1m()-exp.GetN1i());
        Natt2.Fill(exp.GetN2m()-exp.GetN2i());
        Aatt.Fill(exp.GetAmis()-exp.GetAinp());
        Batt.Fill(exp.GetBmis()-exp.GetBinp());
        Diff1.Fill(exp.GetD1m()-exp.GetD1i(),exp.GetD2m()-exp.GetD2i());
        Diff2.Fill(exp.GetN1m()-exp.GetN1i(),exp.GetN2m()-exp.GetN2i());
        Diff3.Fill(exp.GetAmis()-exp.GetAinp(),exp.GetBmis()-exp.GetBinp());
        }
    
    TCanvas can("Distribuzioni di t0,t1 e t2", "Distribuzioni di t0,t1 e t2", 1500,500);
    can.Divide(3,1);
    
    TCanvas can2("Differenza tra valori attesi e valori misurati", "Differenza tra valori attesi e valori misurati", 1000,1500);
    can2.Divide(3,3);
    
    can.cd(1);
    histo1.GetXaxis()->SetTitle("valore theta_0 [rad]");
    histo1.GetYaxis()->SetTitle("occorrenze");
    histo1.SetTitle(S[0].c_str());
    histo1.Draw();
    
    can.cd(2);
    histo2.GetXaxis()->SetTitle("valore theta_1 [rad]");
    histo2.GetYaxis()->SetTitle("occorrenze");
    histo2.SetTitle(S[1].c_str());
    histo2.Draw();
    
    can.cd(3);
    histo3.GetXaxis()->SetTitle("valore theta_2 [rad]");
    histo3.GetYaxis()->SetTitle("occorrenze");
    histo3.SetTitle(S[2].c_str());
    histo3.Draw();
    
    can2.cd(1);
    Datt1.GetXaxis()->SetTitle("differenza tra delta1 atteso e misurato [rad]");
    Datt1.GetYaxis()->SetTitle("occorrenze");
    Datt1.SetTitle("Distribuzione differenze Delta 1");
    Datt1.Draw();
    
    can2.cd(2);
    Datt2.GetXaxis()->SetTitle("differenza tra delta2 atteso e misurato [rad]");
    Datt2.GetYaxis()->SetTitle("occorrenze");
    Datt2.SetTitle("Distribuzione differenze Delta 2");
    Datt2.Draw();
    
    can2.cd(3);
    Diff1.GetXaxis()->SetTitle("differenze tra delta1 e delta2 attesi e misurati [rad]");
    Diff1.GetYaxis()->SetTitle("occorrenze");
    Diff1.SetTitle(" Residui Delta1,2");
    Diff1.Draw();
    
    can2.cd(4);
    Natt1.GetXaxis()->SetTitle("differenza tra n1 atteso e misurato [Adim]");
    Natt1.GetYaxis()->SetTitle("occorrenze");
    Natt1.SetTitle("Distribuzione differenze n1");
    Natt1.Draw();
    
    can2.cd(5);
    Natt2.GetXaxis()->SetTitle("differenza tra n2 atteso e misurato [Adim]");
    Natt2.GetYaxis()->SetTitle("occorrenze");
    Natt2.SetTitle("Distribuzione differenze n2");
    Natt2.Draw();
    
    can2.cd(6);
    Diff2.GetXaxis()->SetTitle("differenza tra n1 e n2 attesi e misurati [Adim]");
    Diff2.GetYaxis()->SetTitle("occorrenze");
    Diff2.SetTitle("Residui n1,2");
    Diff2.Draw();
    
    can2.cd(7);
    Aatt.GetXaxis()->SetTitle("differenza tra A atteso e misurato [??]");
    Aatt.GetYaxis()->SetTitle("occorrenze");
    Aatt.SetTitle("Distribuzione di A");
    Aatt.Draw();
    
    can2.cd(8);
    Batt.GetXaxis()->SetTitle("differenza tra B atteso e misurato [??]");
    Batt.GetYaxis()->SetTitle("occorrenze");
    Batt.SetTitle("Distribuzione di B");
    Batt.Draw();
    
    can2.cd(9);
    Diff3.GetXaxis()->SetTitle("differenze tra A e B attesi e misurati [??]");
    Diff3.GetYaxis()->SetTitle("occorrenze");
    Diff3.SetTitle("Residui A e B");
    Diff3.Draw();
    
    cout<<"Il programma esegue "<<nit<<" simuazioni dell'esperienza dello spettrometro a prisma."<<endl;
    cout<<"Di seguito si elencano i valori medi con le relative incertezze dei dati simulati:"<<endl;
    cout<<"\ttheta0 = "<<histo1.GetMean()<<" +- "<<histo1.GetRMS()<<" rad"<<endl;
    cout<<"\ttheta1 = "<<histo2.GetMean()<<" +- "<<histo2.GetRMS()<<" rad"<<endl;
    cout<<"\ttheta0 = "<<histo3.GetMean()<<" +- "<<histo3.GetRMS()<<" rad"<<endl;
    cout<<"Dopo l'analisi dati si sono ottenuti i seguenti coefficienti di correlazione tra i dati relativi alle due lunghezze d'onda:"<<endl;
    cout<<"\trho(delta) = "<<Diff1.GetCorrelationFactor()<<endl;
    cout<<"\trho(n) = "<<Diff2.GetCorrelationFactor()<<endl;
    cout<<"\trho(AB) = "<<Diff3.GetCorrelationFactor()<<endl;
    
//    Usare iomanip
    
    app.Run();
    return 0;
    }
