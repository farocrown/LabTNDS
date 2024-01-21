#ifndef __integralemonty_h__
#define __integralemonty_h__

#include <iostream>
#include <cmath>
#include "funzionebase.h"
#include "RandomGen.h"

using namespace std;

// Base class : generic integrator

class integralemonty{

public:
  
    integralemonty (double a, double b, unsigned int seed){
        checkInterval (a,b);
        m_gen=new RandomGen(seed);
    }

    double integraHM(funzionebase& f,double fmax, unsigned int ntot){
        double s=m_gen->Unif(m_a,m_b);
        double t=m_gen->Unif(0,fmax);
        int nhit = 0;
        for (int i=0; i<ntot; i++) {
            s=m_gen->Unif(m_a,m_b);
            t=m_gen->Unif(0,fmax);
            if (t<f.eval(s)) {nhit++;}
        }
        return m_sign*(m_b-m_a)*fmax*((double)nhit/ntot);
    }
    double integraMid(unsigned int punti, funzionebase& f){
        double val=0;
        double I =0;
        double s=0;
        for (int i=0; i<punti; i++) {
            s=m_a+(m_b-m_a)*m_gen->Rand();
            val+=f.eval(s);
        }
        I = m_sign*(m_b-m_a)*val/punti;
        return I;
    }
    double GetErr() const {return m_err;}
    void SetErr(double e) {m_err=e;}
    unsigned int GetN() const {return m_N;}
    void SetN(int e) {m_N=e;}
  
private:

    void checkInterval (double a, double b){
      if(a<b){
        m_a=a;
          m_b=b;
          m_sign=1;
      }
      if(a>b){
          m_a=b;
          m_b=a;
          m_sign=-1;
      }
      if(a==b){
          cout<<"Avete inserito due estremi con egual valore: l'integrale vale 0 per definizione."<<endl;
          exit(34);
      }
    }

    double m_a, m_b, m_err;
    RandomGen* m_gen;
    unsigned int m_N;
    int m_sign;
};

#endif // __integrale_h__

/*int precisione(double e){
    double a = -log10(e);
    if (a-(int)a==0.) {
        int b = (int)a;
        return b;
    } else {
        int c = trunc(a)+1;
        return c;
    }
};*/

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
