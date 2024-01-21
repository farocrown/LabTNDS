
#include <iostream>
#include "vector.h"

using namespace std;
//costruttore "vuoto"
gianni::gianni(){
  cout<<"Creo un vettore nullo."<<endl;
  v_size=0;
  v_arr=NULL;
}
//costruttore "pieno"            
gianni::gianni(unsigned int n){
  v_size=n;
  v_arr=new double[n];
  for(int i=0; i<n; i++)
    v_arr[i]=0;
} 

gianni::gianni(const gianni& V){
  v_size=V.getsize();
  v_arr=new double[v_size];
  for(int i=0; i<v_size; i++)
    v_arr[i]=V.getcomp(i);
}
gianni& gianni::operator=(const gianni&V){
  v_size=V.getsize();
  if(v_arr) 
    delete[]v_arr;
  v_arr=new double[v_size];
  for(int i=0; i<v_size; i++)
    v_arr[i]=V.getcomp(i);
  return *this;
}

//distruttore
gianni::~gianni(){
  delete[]v_arr;
}

unsigned int gianni::getsize() const{
  return v_size;
}
void gianni::setcomp(unsigned int i, double a){
  if(i<v_size)
    v_arr[i]=a;
  else{
    cout<<"Errore: stai cercando di definire la "<<i<<"-esima componente di un vettore di dimensione "<<v_size<<"."<<endl;
    exit(-1);
  }
}

double gianni::getcomp(unsigned int c) const{
  if(c<v_size)
    return v_arr[c];
  else{
    cout<<"Errore: stai chiedendo la "<<c<<"-esima componente di un vettore di dimensione "<<v_size<<"."<<endl;
    exit(-1);
  }
}

void gianni::swap(unsigned int a,unsigned int b){
  double t=getcomp(a);
  setcomp(a,getcomp(b));
  setcomp(b,t);
}

