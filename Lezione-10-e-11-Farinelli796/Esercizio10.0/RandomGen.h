#ifndef __RANDOMGEN_H__
#define __RANDOMGEN_H__

#include <cmath>
#include "gaussiana.h"

using namespace std;

class RandomGen{

public:
    RandomGen(unsigned int i){
        m_seed = i;
        m_agg = i;
        m_a = 1664525;
        m_c = 1013904223;
        m_m = pow(2,31);
    };

    void SetA(unsigned int a) {m_a = a;}
    void SetC(unsigned int c) {m_c = c;}
    void SetM(unsigned int m) {m_m = m;}
    void SetS(unsigned int s) {m_seed = s;}

    double Rand(){
        m_agg = ((m_a*m_agg+m_c)%m_m);
        return m_agg/double(m_m);
    };
    double Unif(double xmin, double xmax){
        return xmin+(xmax-xmin)*Rand();
    };
    double Exp(double lambda){
        return -(1./lambda)*log(1-Rand());
    };
    double Gauss(double mean, double sigma){
        double s=Rand();
        double t=Rand();
        double x =sqrt(-2.*log(1.-s))*cos(2.*M_PI*t);
        return mean+x*sigma;
    };
    double GaussAR(double mean, double sigma){
        gaussiana gauss(mean,sigma);
        double xmin = mean-4*sigma;
        double xmax = mean+4*sigma;
        double max = gauss.eval(mean);
        double t = Unif(0,max);
        double s = Unif(xmin,xmax);
        do {
            s=Unif(xmin,xmax);
            t=Unif(0,max);
        } while (gauss.eval(s)<=t);
        return s;
        
    };

private:
     unsigned int m_a, m_c, m_m;
     unsigned int m_seed, m_agg;
};

#endif
