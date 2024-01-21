#ifndef gaussiana_h
#define gaussiana_h

#include <iostream>
#include <cmath>
using namespace std;

class funzionebase{
public:
    virtual double eval(double x) const=0;
    virtual ~funzionebase(){;};
};

class gaussiana: public funzionebase{
public:
//    costruttori
    gaussiana(){
        m_mean=0;
        m_sigma=0;
    };
    gaussiana(double a, double b){
        m_mean=a;
        m_sigma=b;
    };
//    set component
    void setM(double a){m_mean=a;};
    void setS(double b){m_sigma=b;};
//    get component
    double getM(){return m_mean;};
    double getS(){return m_sigma;};
//    funzione
    virtual double eval(double x) const override {
        return exp(-0.5*pow((x-m_mean)/m_sigma,2))/sqrt(2*M_PI*pow(m_sigma,2));
    }
private:
    double m_mean, m_sigma;
};

#endif /* gaussiana_h */
