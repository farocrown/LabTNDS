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

class Eulero: public risolutore{
public:
    Eulero(){;}
    virtual vector<double> passo(double t, const vector<double> &V, double h, const fpiccolo &f) const override{
       return V+(f.eval(t,V)*h);
    }
};



#endif /* equadiff_h */
