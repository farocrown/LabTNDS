#include <iostream>
#include <cmath>
#include <fstream>
#include "lib1.h"
using namespace std;

int main(int argc, char**argv){
  
if (argc<4){
  cout<<"Il programma "<<argv[0]<<"  ha bisogno di <ndati>, <inputfile> e <outputfile>"<<endl;
  return -1;
}

int ndati = atoi(argv[1]);
double *X = new double [ndati];
double *Y = new double [ndati];
char *nomefile = argv[2];
char *output = argv[3];

caricadafile(nomefile, X, ndati);
caricadafile(nomefile, Y, ndati);
selectionsort(Y, ndati);

cout<<"La media dei valori è: "<<media(X, ndati)<<endl;
cout<<"La varianza dei valori è: "<<varianza(X, ndati)<<endl;
cout<<"La mediana dei valori è: "<<mediana(Y, ndati)<<endl;

ofstream out(output);
stampa(out, Y, ndati);
out.close();
cout<<endl<<"Stampo a video i valori riordinati:"<<endl;
stampa(Y, ndati);

cout<<endl<<"Il programma è terminato, ciao!"<<endl;

delete[]X;
X=NULL;
delete[]Y;
Y=NULL;

return 0;
}