#include "lib1.h"

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
