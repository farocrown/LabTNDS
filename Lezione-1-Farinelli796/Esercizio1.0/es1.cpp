#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main(int argc, char**argv){
  
if (argc<4){
  cout<<"Il programma "<<argv[0]<<" ha bisogno di <ndati>, <inputfile> e <outputfile>"<<endl;
  return -1;
}

int ndati = atoi(argv[1]);
double *X = new double [ndati];
char *nomefile = argv[2];
char *output = argv[3];
double media=0;
double var=0;
double mediana=0;

/*caricamento file su X*/
ifstream in; 
in.open(nomefile);
if (!in){
  cout<<"File inesistente!"<<endl;
  return -1;
}
for (int i = 0; i < ndati; i++)
  in>>X[i];        

/*calcolo media*/
if(ndati==0){
  cout<<"non ci sono dati da analizzare!"<<endl;
  return -1;
}
for (int i = 0; i < ndati; i++)
  media+=X[i]/ndati;

cout<<"La media dei valori numerici è: "<<media<<endl;

/*calcolo varianza*/
for (int i = 0; i < ndati; i++)
  var+=pow(media-X[i],2)/ndati;

cout<<"La varianza dei valori numerici è: "<<var<<endl;

/*sorting array dinamico*/
double *Y= new double [ndati];
for (int i = 0; i < ndati; i++)
  Y[i]=X[i];

for (int i = 0; i < ndati-1; i++){
  int z=i;
    for (int j = i+1; j < ndati; j++){
        if (Y[j]<Y[z])
            z=j;
   }
  double t=Y[i];
  Y[i]=Y[z];
  Y[z]=t;
}
/*calcolo mediana*/
if(ndati%2==0)
  mediana=(Y[ndati/2 - 1]+Y[ndati/2])/2;
else
  mediana=Y[ndati/2];

cout<<"La mediana dei valori numerici è: "<<mediana<<endl;

/*Scrittura elementi riordinati su un file*/
ofstream out(output);
for(int i=0; i<ndati; i++)
  out<<i+1<<") "<<Y[i]<<endl;

in.close();
out.close();

cout<<endl<<"Il programma è terminato, ciao!"<<endl;

delete[]X;
X=NULL;
delete[]Y;
Y=NULL;
return 0;
}