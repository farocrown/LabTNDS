#ifndef funzionebase_h
#define funzionebase_h

#include <iostream>
#include <cmath>
using namespace std;

class funzionebase{
public:
    virtual double eval(double x) const=0;
    virtual ~funzionebase(){;};
};
#endif /* funzionebase_h */

#ifndef parabola_h
#define parabola_h

class parabola: public funzionebase{
public:
//    costruttori
    parabola(){
        m_a=0;
        m_b=0;
        m_c=0;
    };
    parabola(double a, double b, double c){
        m_a=a;
        m_b=b;
        m_c=c;
    };
//    set component
    void setA(double a){m_a=a;};
    void setB(double b){m_b=b;};
    void setC(double c){m_c=c;};
//    get component
    double getA(){return m_a;};
    double getB(){return m_b;};
    double getC(){return m_c;};
//    funzione
    virtual double eval(double x) const override {
        return m_a*pow(x,2)+m_b*x+m_c;
    }
private:
    double m_a, m_b, m_c;
};
#endif /* parabola_h */

#ifndef segno_h
#define segno_h

class segno: public funzionebase{
public:
    segno(){;};
    ~segno(){};
    virtual double eval (double x)const override{
        if(x<0)
            return -1;
        else if(x>0)
            return 1;
        else
            return 0;
    }
};
#endif /* segno_h */

#ifndef sincope_h
#define sincope_h

class sincope: public funzionebase{
public:
    sincope(){;};
    ~sincope(){};
    virtual double eval (double x)const override{
        return sin(x)-x*cos(x);
    }
};
#endif /* sincope_h */

#ifndef seno_h
#define seno_h

class seno: public funzionebase{
public:
//    costruttori y=Asin(wx)+c
    seno(){
        m_A=0;
        m_w=0;
        m_c=0;
    };
    seno(double a, double b, double c){
        m_A=a;
        m_w=b;
        m_c=c;
    };
//    set component
    void setA(double a){m_A=a;};
    void setW(double b){m_w=b;};
    void setC(double c){m_c=c;};
//    get component
    double getA(){return m_A;};
    double getW(){return m_w;};
    double getC(){return m_c;};
//    funzione
    virtual double eval(double x) const override {
        return m_A*sin(m_w*x)+m_c;
    }
private:
    double m_A, m_w, m_c;
};
#endif /* seno_h */
