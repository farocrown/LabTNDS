#ifndef __gianni_h__
#define __gianni_h__

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

template <typename T> class gianni{
  public:
  //costruttori
  gianni();                   //costruttore "vuoto"
  gianni(unsigned int);       //costruttore "pieno"
  gianni(const gianni&);
  gianni& operator=(const gianni&);
  T& operator[](unsigned int);
  //distruttore
  ~gianni();
  //metodi
  unsigned int getsize() const;
  void setcomp(unsigned int, T);
  T getcomp(unsigned int) const;
  void swap(unsigned int,unsigned int);


  private:
  int v_size;
  T* v_arr;
  
};

//costruttore "vuoto"
template <class T> gianni<T>::gianni(){
  v_size=0;
  v_arr=NULL;
}
//costruttore "pieno"            
template <class T> gianni<T>::gianni(unsigned int n){
  v_size=n;
  v_arr=new double[n];
  for(int i=0; i<n; i++)
    v_arr[i]=0;
} 

template <class T> gianni<T>::gianni(const gianni& V){
  v_size=V.getsize();
  v_arr=new double[v_size];
  for(int i=0; i<v_size; i++)
    v_arr[i]=V.getcomp(i);
}
template <class T> gianni<T>& gianni<T>::operator=(const gianni&V){
  v_size=V.getsize();
  if(v_arr) 
    delete[]v_arr;
  v_arr=new double[v_size];
  for(int i=0; i<v_size; i++)
    v_arr[i]=V.getcomp(i);
  return *this;
}

template <class T> T& gianni<T>::operator[](unsigned int i){
  if(i<v_size)
    return v_arr[i];
  else{
    cout<<"Errore: stai cercando di definire e/o utilizzare la "<<i<<"-esima componente di un vettore di dimensione "<<v_size<<"."<<endl;
    exit(-1);
  }
}

//distruttore
template <class T> gianni<T>::~gianni(){
  delete[]v_arr;
}

template <class T> unsigned int gianni<T>::getsize() const{
  return v_size;
}
template <class T> void gianni<T>::setcomp(unsigned int i, T a){
  if(i<v_size)
    v_arr[i]=a;
  else{
    cout<<"Errore: stai cercando di definire la "<<i<<"-esima componente di un vettore di dimensione "<<v_size<<"."<<endl;
    exit(-1);
  }
}

template <class T> T gianni<T>::getcomp(unsigned int c) const{
  if(c<v_size)
    return v_arr[c];
  else{
    cout<<"Errore: stai chiedendo la "<<c<<"-esima componente di un vettore di dimensione "<<v_size<<"."<<endl;
    exit(-1);
  }
}

template <class T> void gianni<T>::swap(unsigned int a,unsigned int b){
  T t=getcomp(a);
  setcomp(a,getcomp(b));
  setcomp(b,t);
}


#endif //__gianni_h__