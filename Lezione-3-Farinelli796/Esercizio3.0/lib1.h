#ifndef __funzioni__
#define __funzioni__

#include <iostream>
#include <cmath>
#include <fstream>
#include "vector.h"

using namespace std;

template <typename T> gianni<T> leggi( int dim, const char* f){
gianni<T> V(dim);
ifstream in; 
in.open(f);
    if (!in){
        cout<<"File inesistente!"<<endl;
        exit(46);
    }
    else{
        for (int i = 0; i < dim; i++){
            T a=0;
            in>>a;
            V.setcomp(i,a); 
        }
    }
in.close();
return V;
}

template <typename T> double media(const gianni<T> &V){
if(V.getsize()==0){
    cout<<"non ci sono dati da analizzare!"<<endl;
    exit(46);
}
double a=0;
  for(int i=0; i<V.getsize(); i++)
    a+=V.getcomp(i)/V.getsize();
  return a;
}

template <typename T> double varianza(const gianni<T> &V){
double a=media(V);
double b=0;
    for(int i=0; i<V.getsize(); i++)
        b+=pow(a-V.getcomp(i),2)/V.getsize();
return b;
}

template <typename T> double mediana(const gianni<T> &V){
double a=0;
if(V.getsize()==0)
    cout<<"non ci sono dati da analizzare!"<<endl;   
else if(V.getsize()%2==0)
    a=(V.getcomp(V.getsize()/2-1)+V.getcomp(V.getsize()/2))/2;
else
    a=V.getcomp(V.getsize()/2);
  return a;
}

template <typename T> void selsort(gianni<T> &V){
int alfredo=V.getsize();
for (int i = 0; i <alfredo-1 ; i++){
  int z=i;
    for (int j = i+1; j < alfredo; j++){
        if (V.getcomp(j)<V.getcomp(z))
            z=j;
    }
  V.swap(z,i);  
}
}

template <typename T> void stampa(const gianni<T> &V){
    for(int i=0; i<V.getsize(); i++)
        cout<<i+1<<") "<<V.getcomp(i)<<endl;
}

template <typename T> void stampa(const gianni<T> &V, ofstream&out){
    for(int i=0; i<V.getsize(); i++)
        out<<i+1<<") "<<V.getcomp(i)<<endl;
}


#endif