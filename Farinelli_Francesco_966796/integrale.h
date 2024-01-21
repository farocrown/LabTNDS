#ifndef __integrale_h__
#define __integrale_h__

#include <iostream>
#include <cmath>
#include "funzionebase.h"
#include "RandomGen.h"

using namespace std;

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
          m_a=a;
          m_b=a;
          m_sign=0;
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
    double errore(int k, funzionebase& f){
        double z = 16/15.;
        double e = z*(abs(integra(k, f)-integra(2*k, f)));
        return e;
    }
    
    int trovaN (double prec, funzionebase& f){
        int k=2;
        double e;
        do {
            e = errore(k,f);
            k*=2;
        } while (prec<=e);
        return k/2;
    }

};

class midright : public integrale {
public:

midright (double a, double b) : integrale (a, b){;};

virtual double integra(unsigned int nstep, funzionebase& f) override {
    m_nstep=nstep;
    m_h = (m_b-m_a)/m_nstep;
    for (int n=0; n<m_nstep; n++) {
        m_integral+=f.eval(m_a+(n+1)*m_h)*m_h;
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
        if(m_sign==0){return 0.;};
        if (nstep%2!=0) {
            cerr<<"Errore: la formula di Simpson richiede un numero di steps pari."<<endl;
            exit(54);
        }
        m_nstep=nstep;
        m_integral=0;
        m_h = (m_b-m_a)/m_nstep;
        for (int n=1; n<m_nstep; n++) {
            m_integral+=coefficiente(n)*f.eval(m_a+n*m_h);
        }
        m_integral+=f.eval(m_a)+f.eval(m_b);
        m_integral*=m_sign*m_h/3;
        return m_integral;
    };
    
    double errore(int k, funzionebase& f){
        double z = 16/15.;
        double e = z*(abs(integra(k, f)-integra(2*k, f)));
        return e;
    }
    
    int trovaN (double prec, funzionebase& f){
        int k=2;
        double e;
        do {
            e = errore(k,f);
            k*=2;
        } while (prec<=e);
        return k/2;
    }
};
    
class trapezi : public integrale {
public:

trapezi (double a, double b) : integrale (a, b){;};
        
       

    virtual double integra(unsigned int nstep, funzionebase& f) override {
        m_integral=0;
        m_nstep=nstep;
        m_h = (m_b-m_a)/m_nstep;
        for (int n=0; n<m_nstep; n++) {
            m_sum+=f.eval(m_a+n*m_h);
        }
        m_sum+=0.5*(f.eval(m_a)+f.eval(m_b));
        m_sum*=m_sign*m_h;
        return m_sum;
    };
    
    int trovah (double prec, funzionebase& f){
        int k=2;
        double e;
        do {
            e = (4*abs(integra(k, f)-integra(2*k, f))/3.);
            k*=2;
        } while (prec<=e);
        
    
        
        return k/2;
        
        /*double h = (m_b-m_a)/nstep;
        double c = sqrt((prec*3*h*h)/(4*abs(integra(nstep, f)-integra(2*nstep, f))));
        double a = (m_b-m_a)/c;
        int b=trunc(a)+1;
        return b*/
    };

    };

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
    
    int npunti(double errtilde, unsigned int N, funzionebase& f){
        vector<double> A;
        for (int i = 0; i<1000; i++) {
            double a = integraMid(N,f);
            A.push_back(a);
        }
        double sigma = varianza<double>(A);
        int nm = round(sigma*N/(errtilde*errtilde))+1;
        return nm;
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




