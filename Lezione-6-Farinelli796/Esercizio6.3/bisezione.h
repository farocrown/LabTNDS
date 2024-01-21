#ifndef bisezione_h
#define bisezione_h

#include "solutore.h"

class bisezione: public solutore{
public:
//    costruttore
    bisezione():solutore(){;};
//    ~bisezione(){;};
    double zeri(double xmin , double xmax , const funzionebase& f, double eps=0.001, unsigned int Nmax=100){
        segno s;
        m_eps=eps;
        m_Nmax=Nmax;
        m_Nit=0;
        if (xmin<xmax) {
            m_a=xmin;
            m_b=xmax;
        }
        else{
            m_b=xmin;
            m_a=xmax;
        }
    
        double fa = f.eval(m_a);
        double fb = f.eval(m_b);
        
        if(s.eval(fa)*s.eval(fb)>0){
            cerr<<"Errore: non sono rispettate le ipotesi del teorema di Bolzano. Esco."<<endl;
            exit(-345);
        }
        if (s.eval(fa)==0) {
            cout<<"L'estremo inserito è uno zero della funzione: x_0="<<m_a<<". Fine."<<endl;
            exit(32);
        }
        if (s.eval(fb)==0) {
            cout<<"L'estremo inserito è uno zero della funzione: x_0="<<m_b<<". Fine."<<endl;
            exit(22);
        }
        do {
            double xm = (m_a+m_b)/2;
            double fc = f.eval(xm);
            if (m_Nit>m_Nmax) {
                cerr<<"Errore: numero massimo di iterazioni raggiunte, non ho ottenuto risultato il risultato richiesto. Si provi a modificare la precisione o il numero di iterazioni massime. Esco."<<endl;
                exit(46);
            }
            m_Nit++;
            if (s.eval(fc)*s.eval(fa)<0) {m_b=xm; fb=fc;}
            else if (s.eval(fc)*s.eval(fb)<0) {m_a=xm; fa=fc;}
            else return 0;
        } while (2*(m_b-m_a)>m_eps);
    
        return (m_b+m_a)/2;
    }

};

    
    
#endif /* bisezione_h */

