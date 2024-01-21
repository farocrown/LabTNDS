#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "lib1.h"

using namespace std;

int main(int marco, char** luca){

if (marco<4){
    cout<<"Il programma "<<luca[0]<<"  ha bisogno di <ndati>, <inputfile> e <outputfile>"<<endl;
    return -1;
}

vector<double> V = leggi<double>(atoi(luca[1]), luca[2]);
vector<double> Z=V;

cout<<"La media dei valori è: "<<media<double>(V)<<endl;
cout<<"La varianza dei valori è: "<<varianza<double>(V)<<endl;
cout<<"La mediana dei valori è: "<<mediana<double>(Z)<<endl;

ofstream out(luca[3]);
stampa(Z, out);
out.close();

cout<<endl<<"Stampo a video i valori riordinati:"<<endl;
stampa(Z);
cout<<endl<<"Il programma è terminato, ciao!"<<endl;

return 0;
}