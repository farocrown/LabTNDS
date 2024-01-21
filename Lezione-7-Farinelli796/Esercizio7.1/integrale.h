#ifndef __integrale_h__
#define __integrale_h__

#include <iostream>
#include <cmath>
#include "funzionebase.h"

using namespace std;

// Base class : generic integrator

class integrale {

 public:
  
  integrale (double a, double b){
    checkInterval (a,b);
    m_nstep = 0;
    m_h = 0; 
    m_sum = 0;
    m_integral =0;
  }

  virtual double integra(unsigned int nstep, funzionebase& f) = 0;

 protected:

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

  unsigned int m_nstep;
  double m_a, m_b;
  double m_sum, m_integral, m_h;
  int m_sign;
};

// derived class : Midpoint integrator

class midpoint : public integrale {
public:

midpoint (double a, double b) : integrale (a, b){;};

virtual double integra(unsigned int nstep, funzionebase& f) override {
    m_nstep=nstep;
    m_h = (m_b-m_a)/m_nstep;
    for (int n=0; n<m_nstep; n++) {
        m_integral+=f.eval(m_a+(n+0.5)*m_h)*m_h;
    }
    m_integral*=m_sign;
    return m_integral;
};

};

class simpson : public integrale {
public:

simpson (double a, double b) : integrale (a, b){;};
    
    int coefficiente (int a){
//        nel for non c'è mai l'int = 0
        if (a%2==0) return 2;
        else return 4;
    }

virtual double integra(unsigned int nstep, funzionebase& f) override {
    if (nstep%2!=0) {
        cerr<<"Errore: la formula di Simpson richiede un numero di steps pari."<<endl;
        exit(54);
    }
    m_nstep=nstep;
    m_h = (m_b-m_a)/m_nstep;
    for (int n=1; n<m_nstep; n++) {
        m_integral+=coefficiente(n)*f.eval(m_a+n*m_h);
    }
    m_integral+=f.eval(m_a)+f.eval(m_b);
    m_integral*=m_sign*m_h/3;
    return m_integral;
};
};
    
class trapezi : public integrale {
public:

trapezi (double a, double b) : integrale (a, b){;};
        
       

    virtual double integra(unsigned int nstep, funzionebase& f) override {
        m_nstep=nstep;
        m_h = (m_b-m_a)/m_nstep;
        for (int n=0; n<m_nstep; n++) {
            m_sum+=f.eval(m_a+n*m_h);
        }
        m_sum+=0.5*(f.eval(m_a)+f.eval(m_b));
        m_sum*=m_sign*m_h;
        return m_sum;
    };
    int trovah (int nstep, double prec, funzionebase& f){
        double h = (m_b-m_a)/nstep;
        double c = sqrt((prec*3*h*h)/(4*abs(integra(nstep, f)-integra(2*nstep, f))));
        double a = (m_b-m_a)/c;
        int b=trunc(a)+1;
        return b;
    };

    };



#endif // __integrale_h__

int precisione(double e){
    double a = -log10(e);
    if (a-(int)a==0.) {
        int b = (int)a;
        return b;
    } else {
        int c = trunc(a)+1;
        return c;
    }
};
