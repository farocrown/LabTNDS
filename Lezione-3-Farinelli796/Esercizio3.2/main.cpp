#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "lib1.h"
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"

using namespace std;

int main(int marco, char** luca){

if (marco<4){
    cout<<"Il programma "<<luca[0]<<"  ha bisogno di <ndati>, <inputfile> e <outputfile>"<<endl;
    return -1;
}
TApplication app("app",0,0);

vector<double> V = leggi<double>(atoi(luca[1]), luca[2]);
vector<double> Z=V;

cout<<"La media dei valori è: "<<media<double>(V)<<endl;
cout<<"La varianza dei valori è: "<<varianza<double>(V)<<endl;
cout<<"La mediana dei valori è: "<<mediana<double>(Z)<<endl;

ofstream out(luca[3]);
stampa(Z, out);
out.close();

cout<<endl<<"Stampo a video i valori riordinati:"<<endl<<endl;
stampa(Z);

TH1F h ("Info","Dati", 100, -10, 100) ;
h.StatOverflows( kTRUE );
for ( int k = 0 ; k < V.size() ; k++ ) 
   h.Fill( V[k] );
//cout<<"Media dei valori caricati= "<<h.GetMean()<<endl;
TCanvas mycanvas ("Histo","Histo");
h.Draw();
h.GetXaxis()->SetTitle("Dati estratti dal file");

app.Run();

return 0;

}
