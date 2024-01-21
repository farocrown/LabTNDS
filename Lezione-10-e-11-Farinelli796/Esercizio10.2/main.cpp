/*Calcolare 10000 volte il valore dell'integrale di sin(x) tra [0,π] utilizzando il metodo della media a 100 punti e fare un grafico ( istogramma ) della distribuzione dei valori ottenuti.
 Estendere il punto precedente calcolando 10000 volte il valore dell'integrale di sin(x) tra [0,π] utilizzando il metodo della media a N punti con N pari a 100, 500, 1000, 5000, 10000 punti. Per ogni valore di N produrre il grafico della distribuzione dei 10000 valori ottenuti. [NOTA: poichè il calcolo degli integrali con N molto elevato potrebbe richiedere un certo tempo, potrebbe essere utile salvare in diversi files i valori degli integrali calcolati per un determinato N e svolgere i punti successivi con un secondo programma che utilizzi come input i files di integrali del programma precedente.]
 Stimare l'errore sul calcolo dell'integrale a 100, 500, 1000, 5000, 10000 punti come deviazione standard dei 10000 valori calcolati per ogni N. Far un grafico di questo errore in funzione di N.
 Assumendo che l'andamento dell'errore sia noto ( del tipo k/ √N ) si determini quanti punti sono necessari per ottenere una precisione di 0.001. Si ripeta lo stesso lavoro con il metodo hit-or-miss.*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "funzionebase.h"
#include "integrale.h"

using namespace std;

int main(){
    
    integrale inte(0,M_PI,1);
    sen seno(1,1,0);
    vector<double> V{100,500,1000,5000,10000};
    vector<double> A,C,D;
    double a,b;
    double eps = 0.001;
    
//    parte sui dati da graficare
    for (int j=0; j<V.size(); j++) {
        string titolo ="dataMid"+to_string(j+1)+".dat";
        ofstream out (titolo);
        for (int i=0; i<10000; i++) {
            a = inte.integraMid(V[j],seno);
            A.push_back(a);
            out<<a<<endl;
        }
        out.close();
        C.push_back(sqrt(varianza<double>(A)));
        A.erase(A.begin(),A.end());
    }
    
    ofstream out ("erroriMid.dat");
    for (int i=0; i<C.size(); i++) {
        out<<C[i]<<endl;
    }
    out.close();
    
    for (int j=0; j<V.size(); j++) {
        string titolo ="dataHM"+to_string(j+1)+".dat";
        ofstream out (titolo);
        for (int i=0; i<10000; i++) {
            b = inte.integraHM(seno,1,V[j]);
            A.push_back(b);
            out<<b<<endl;
        }
        out.close();
        D.push_back(sqrt(varianza<double>(A)));
        A.erase(A.begin(),A.end());
    }
    
    ofstream fout ("erroriHM.dat");
    for (int i=0; i<D.size(); i++) {
        fout<<D[i]<<endl;
    }
    fout.close();
    
    ofstream sout ("size.dat");
    sout<<V.size()<<endl;
    sout<<10000<<endl;
    for (int i=0; i<=V.size(); i++) {
        sout<<V[i]<<endl;
    }
    sout.close();
    
    //    parte sulla precisione
    int nm = round(pow(C[4],2)*V[4]/(eps*eps))+1;
    int nhm = round(pow(D[4],2)*V[4]/(eps*eps))+1;
    
//    cout<<endl<<endl<<C[0]<<endl<<endl<<D[0]<<endl<<endl<<eps<<endl;
        cout<<"Il numero di punti per ottenere una precisione di "<<eps<<" con il metodo della media è "<<nm<<endl;
        cout<<"Il numero di punti per ottenere una precisione di "<<eps<<" con il metodo <<Hit or Miss>> è "<<nhm<<endl;
    
    
    return 0;
}
