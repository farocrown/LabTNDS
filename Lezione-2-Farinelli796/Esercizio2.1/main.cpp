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

gianni V = leggi(ndati, nomefile);
gianni Z=V;
selsort(Z);

cout<<"La media dei valori è: "<<media(V)<<endl;
cout<<"La varianza dei valori è: "<<varianza(V)<<endl;
cout<<"La mediana dei valori è: "<<mediana(Z)<<endl;

ofstream out(output);
stampa(Z, out);
out.close();

/*cout<<endl<<"Stampo a video i valori riordinati:"<<endl;
stampa(Z);*/
cout<<endl<<"Il programma è terminato, ciao!"<<endl;

return 0;
}