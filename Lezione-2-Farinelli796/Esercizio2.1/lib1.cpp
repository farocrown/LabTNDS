#include "lib1.h"
#include "vector.h"

gianni leggi( int dim, const char* f){
gianni V(dim);
ifstream in; 
in.open(f);
    if (!in){
        cout<<"File inesistente!"<<endl;
        exit(46);
    }
    else{
        for (int i = 0; i < dim; i++){
            double a=0;
            in>>a;
            V.setcomp(i,a); 
        }
    }
in.close();
return V;
}

double media(const gianni &V){
if(V.getsize()==0){
    cout<<"non ci sono dati da analizzare!"<<endl;
    exit(46);
}
double a=0;
  for(int i=0; i<V.getsize(); i++)
    a+=V.getcomp(i)/V.getsize();
  return a;
}

double varianza(const gianni &V){
double a=media(V);
double b=0;
    for(int i=0; i<V.getsize(); i++)
        b+=pow(a-V.getcomp(i),2)/V.getsize();
return b;
}

double mediana(const gianni &V){
double a=0;
if(V.getsize()==0)
    cout<<"non ci sono dati da analizzare!"<<endl;   
else if(V.getsize()%2==0)
    a=(V.getcomp(V.getsize()/2-1)+V.getcomp(V.getsize()/2))/2;
else
    a=V.getcomp(V.getsize()/2);
  return a;
}

void selsort(gianni &V){
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

void stampa(const gianni &V){
    for(int i=0; i<V.getsize(); i++)
        cout<<i+1<<") "<<V.getcomp(i)<<endl;
}

void stampa(const gianni &V, ofstream&out){
    for(int i=0; i<V.getsize(); i++)
        out<<i+1<<") "<<V.getcomp(i)<<endl;
}
