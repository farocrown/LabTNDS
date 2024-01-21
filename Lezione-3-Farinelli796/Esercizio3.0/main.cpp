#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include "lib1.h"
#include "vector.h"

using namespace std;

int main(int marco, char** luca){

if (marco<4){
    cout<<"Il programma "<<luca[0]<<"  ha bisogno di <ndati>, <inputfile> e <outputfile>"<<endl;
    return -1;
}

int ndati = atoi(luca[1]);
char *nomefile = luca[2];
char *output = luca[3];

gianni<double> V = leggi<double>(ndati, nomefile);
gianni<double> Z=V;
selsort(Z);

cout<<endl<<"La media dei valori è: "<<media<double>(V)<<endl;
cout<<"La varianza dei valori è: "<<varianza<double>(V)<<endl;
cout<<"La mediana dei valori è: "<<mediana<double>(Z)<<endl;

ofstream out(output);
stampa(Z, out);
out.close();

/*cout<<endl<<"Stampo a video i valori riordinati:"<<endl;
stampa(Z);*/
cout<<endl<<"Il programma è terminato, ciao!"<<endl;

return 0;
}