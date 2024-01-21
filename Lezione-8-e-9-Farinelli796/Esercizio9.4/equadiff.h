#ifndef equadiff_h
#define equadiff_h

#include "calcolovettoriale.h"

using namespace std;

class fpiccolo {
public:
    virtual vector<double> eval (double t, const vector<double> & x) const =0;
    virtual ~fpiccolo(){;};
};

class risolutore {
public:
  virtual vector<double> passo(double t, const vector<double> &x, double h, const fpiccolo &f) const = 0;
};

class OscAr: public fpiccolo{
public:
    OscAr(double a){m_w0=a;}
    virtual vector<double> eval(double t, const vector<double> &V) const override {
        vector<double> Y {V[1],-pow(m_w0,2)*V[0]};
        return Y;
    }
//    getW0
//    setW0

private:
    double m_w0;
};

class OscArFor: public fpiccolo{
public:
    OscArFor(double omega0, double gamma, double ampiezzaf, double omegaf){
        m_w0 = omega0;
        m_gamma = gamma;
        m_C = ampiezzaf;
        m_wf = omegaf;
    }
    
    void setAMPL(double a){m_wf=a;}
    
    virtual vector<double> eval(double t, const vector<double> &V) const override {
        vector<double> Y {V[1],m_C*cos(m_wf*t)-pow(m_w0,2)*V[0]-m_gamma*V[1]};
        return Y;
    }
//    getW0
//    setW0

private:
    double m_w0, m_gamma, m_C, m_wf;
};

class Pendolo: public fpiccolo{
public:
    Pendolo(double a){m_l=a;}
    virtual vector<double> eval(double t, const vector<double> &V) const override {
        vector<double> Y {V[1],-g*sin(V[0])/m_l};
        return Y;
    }
//    getW0
//    setW0

private:
    double m_l;
    double g = 9.81;
};

class Eulero: public risolutore{
public:
    Eulero(){;}
    virtual vector<double> passo(double t, const vector<double> &V, double h, const fpiccolo &f) const override{
       return V+(f.eval(t,V)*h);
    }
};

class RK4: public risolutore{
public:
    RK4(){;}
    virtual vector<double> passo(double t, const vector<double> &V, double h, const fpiccolo &f) const override{
        vector<double> k1 = f.eval(t,V);
        vector<double> k2 = f.eval(t+h/2.,V+(h*k1)/2.);
        vector<double> k3 = f.eval(t+h/2.,V+(h*k2)/2.);
        vector<double> k4 = f.eval(t+h,V+(h*k3));
        
        return V+h*(k1+2.*k2+2.*k3+k4)/6.;
    }
};



#endif /* equadiff_h */
