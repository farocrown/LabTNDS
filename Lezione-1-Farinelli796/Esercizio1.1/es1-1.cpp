#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double media(double *X, int dim);
double varianza(double *X, int dim);
double mediana(double *X, int dim);
void caricadafile(char* f, double *X, int dim);
void selectionsort(double*X, int dim);
void swap(double &x, double &y);
void stampa(ofstream &out, double *X, int dim);

int main(int argc, char**argv){
  
if (argc<4){
  cout<<"Il programma "<<argv[0]<<" ha bisogno di <ndati>, <inputfile> e <outputfile>"<<endl;
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

cout<<endl<<"Il programma è terminato, ciao!"<<endl;

delete[]X;
X=NULL;
delete[]Y;
Y=NULL;


return 0;
}

double media(double *X, int dim){
  double a=0;
  if(dim==0){
    cout<<"non ci sono dati da analizzare!"<<endl;
    return a;
  }
  for(int i=0; i<dim; i++)
    a+=X[i]/dim;
    return a;
}

double varianza(double *X, int dim){
  double a=0;
  double b=media(X, dim);
  if(dim==0){
    cout<<"non ci sono dati da analizzare!"<<endl;
    return a;
  }
  for (int i = 0; i < dim; i++)
    a+=pow(b-X[i],2)/dim;
  return a;
}

double mediana(double *X, int dim){
  double a=0;
  if(dim==0)
    cout<<"non ci sono dati da analizzare!"<<endl;   
  else if(dim%2==0)
    a=(X[dim/2 - 1]+X[dim/2])/2;
  else
    a=X[dim/2];
  return a;
}

void caricadafile(char* f, double *X, int dim){
  ifstream in; 
  in.open(f);
  if (!in){
    cout<<"File inesistente!"<<endl;
  }
  else{
    for (int i = 0; i < dim; i++)
      in>>X[i]; 
  }
  in.close();
}

void selectionsort(double*X, int dim){
  for (int i = 0; i < dim-1; i++){
  int z=i;
    for (int j = i+1; j < dim; j++){
        if (X[j]<X[z])
            z=j;
   }
  swap(X[i], X[z]);
}
}

void swap(double &x, double &y){
  double t=x;
  x=y;
  y=t;
}

void stampa (ofstream &out, double *X, int dim){
  for(int i=0; i<dim; i++)
    out<<i+1<<") "<<X[i]<<endl;
}

