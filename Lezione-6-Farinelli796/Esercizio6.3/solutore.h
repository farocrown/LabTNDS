#ifndef solutore_h
#define solutore_h

#include "funzionebase.h"

const double eps_def = 0.001;
const unsigned int nnmax_def = 100;

class solutore{
public:
    solutore(){
        m_a=0;
        m_b=0;
        m_eps=eps_def;
        m_Nmax=nnmax_def;
        m_Nit=0;
    };
    solutore(double a, double b, double eps){
        m_a=a;
        m_b=b;
        m_eps=eps;
        m_Nmax=nnmax_def;
        m_Nit=0;
    };
    ~solutore(){;};
    
    virtual double zeri(double , double , const funzionebase&, double, unsigned int)=0;
//    set component
        void setA(double a){m_a=a;};
        void setB(double b){m_b=b;};
        void setEPS(double e){m_eps=e;};
        void setN(unsigned int c){m_Nmax=c;};
        void setNit(unsigned int d){m_Nit=d;};
//    get component
        double getA(){return m_a;};
        double getB(){return m_b;};
        double getEPS(){return m_eps;};
        unsigned int getN(){return m_Nmax;};
        unsigned int getNit(){return m_Nit;};
protected:
    double m_a, m_b, m_eps;
    unsigned int m_Nmax, m_Nit;
};

#endif /* solutore_h */
