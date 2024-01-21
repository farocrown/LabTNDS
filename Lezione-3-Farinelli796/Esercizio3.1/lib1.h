#ifndef __funzioni__
#define __funzioni__

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm> 


using namespace std;

template <typename T> vector<T> leggi(int n, const char* f){
vector<T> V;
ifstream in; 
in.open(f);
    if (!in){
        cout<<"File inesistente!"<<endl;
        exit(46);
    }
    else{
        for (int i = 0; i < n; i++){
          T a=0;
          in>>a;
            V.push_back(a); 
        }
    }

in.close();
return V;
}

template <typename T> double media(const vector<T> &V){
if(V.size()==0){
    cout<<"non ci sono dati da analizzare!"<<endl;
    exit(46);
}
double a=0;
  for(int i=0; i<V.size(); i++)
    a+=V[i]/V.size();
  return a;
}

template <typename T> double varianza(const vector<T> &V){
double a=media(V);
double b=0;
    for(int i=0; i<V.size(); i++)
        b+=pow(a-V[i],2)/V.size();
return b;
}

/*template <typename T> void selsort(vector<T> &V){
int alfredo=V.size();
for (int i = 0; i <alfredo-1 ; i++){
  int z=i;
    for (int j = i+1; j < alfredo; j++){
        if (V[j]<V[z])
            z=j;
    }
  swap(V[z],V[i]);  
}
}*/

template <typename T> double mediana(vector<T> &V){
//selsort<double>(V);
sort( V.begin(), V.end() );
double a=0;
if(V.size()==0)
    cout<<"non ci sono dati da analizzare!"<<endl;   
else if(V.size()%2==0)
    a=(V[V.size()/2-1]+V[V.size()/2])/2;
else
    a=V[V.size()/2];
  return a;
}


template <typename T> void stampa(const vector<T> &V){
    for(int i=0; i<V.size(); i++)
        cout<<i+1<<") "<<V[i]<<endl;
}

template <typename T> void stampa(const vector<T> &V, ofstream&out){
    for(int i=0; i<V.size(); i++)
        out<<i+1<<") "<<V[i]<<endl;
}


#endif