/*Costruire una classe EsperimentoPrisma con le seguenti caratteristiche:
 come data membri deve avere sia i valori veri che i valori misurati di tutte le quantità ed in più un generatore di numeri casuali RandomGen (vedi lezione 10);
 nel costruttore deve definire tutti i valori di ingresso delle quantità misurabili a partire dai parametri A, B ed α e dalle lunghezze d'onda;
 N.B.: il valore di θ0 è arbitrario, ma, una volta definito, i θm sono fissati.
 un metodo Esegui() che effettua la misura sperimentale e determina dei valori misurati di θ0, θm(λ1), θm(λ2);
 N.B.: il valore misurato di un angolo si ottiene estraendo un numero distribuito in maniera gaussiana intorno al suo valore di ingresso nella simulazione e deviazione standard σθ.
 i metodi necessari per accedere ai valori dei data membri, sia quelli di ingresso che quelli misurati.*/
#ifndef prisma_h
#define prisma_h
#include <iostream>
#include <cmath>
#include "RandomGen.h"

using namespace std;

class EsperimentoPrisma {

public:
    EsperimentoPrisma(double t):
        m_rgen(1),
        m_lambda1(579.1E-9),
        m_lambda2(404.7E-9),
        m_alpha(60.*M_PI/180.),
        m_sigmat(0.3E-3),
        m_A_input(2.7),
        m_B_input(60000E-18)
      {
        // calcolo degli indici di rifrazione con legge di Cauchy
          m_n1_input=sqrt(m_A_input+(m_B_input/pow(m_lambda1,2)));
          m_n2_input=sqrt(m_A_input+(m_B_input/pow(m_lambda2,2)));
        // theta0 e' arbitrario, scelgo 0. potrei anche darlo in input
          m_th0_input = t;
        // determino theta1 e theta2
          m_deltam1_input = 2.*asin(m_n1_input*sin(0.5*m_alpha))-m_alpha;
          m_th1_input = m_th0_input + m_deltam1_input;
          m_deltam2_input = 2.*asin(m_n2_input*sin(0.5*m_alpha))-m_alpha;
          m_th2_input = m_th0_input+m_deltam2_input;
    };
    ~EsperimentoPrisma(){;};

    void Misura(){
        m_th0_misurato = m_rgen.Gauss(m_th0_input,m_sigmat);
        m_th1_misurato = m_rgen.Gauss(m_th1_input,m_sigmat);
        m_th2_misurato = m_rgen.Gauss(m_th2_input,m_sigmat);
    };
    void Analizza(){
        m_deltam1_misurato = m_th1_misurato - m_th0_misurato;
        m_deltam2_misurato = m_th2_misurato - m_th0_misurato;
        m_n1_misurato = sin((m_deltam1_misurato+m_alpha)/2)/sin(m_alpha/2);
        m_n2_misurato = sin((m_deltam2_misurato+m_alpha)/2)/sin(m_alpha/2);
        m_A_misurato = (pow(m_lambda2*m_n2_misurato,2)-pow(m_lambda1*m_n1_misurato,2))/(pow(m_lambda2,2)-pow(m_lambda1,2));
        m_B_misurato = pow(m_lambda1*m_lambda2,2)*(pow(m_n2_misurato,2)-pow(m_n1_misurato,2))/(pow(m_lambda1,2)-pow(m_lambda2,2));
    };
    
    double GetAmis(){return m_A_misurato;};
    double GetBmis(){return m_B_misurato;};
    double GetAinp(){return m_A_input;};
    double GetBinp(){return m_B_input;};
    double GetT0i(){return m_th0_input;};
    double GetT1i(){return m_th1_input;};
    double GetT2i(){return m_th2_input;};
    double GetT0m(){return m_th0_misurato;};
    double GetT1m(){return m_th1_misurato;};
    double GetT2m(){return m_th2_misurato;};
    double GetD1i(){return m_deltam1_input;};
    double GetD2i(){return m_deltam2_input;};
    double GetD1m(){return m_deltam1_misurato;};
    double GetD2m(){return m_deltam2_misurato;};
    double GetN1i(){return m_n1_input;};
    double GetN2i(){return m_n2_input;};
    double GetN1m(){return m_n1_misurato;};
    double GetN2m(){return m_n2_misurato;};
    
private:

    // generatore di numeri casuali

    RandomGen m_rgen ;

    // parametri dell'apparato sperimentale: le due lunchezze d'onda del giallo e del viola, l'angolo alpha del prisma e l'incertezza che abbiamo scelto sulla misura di ogni angolo.
    double m_lambda1, m_lambda2, m_alpha, m_sigmat;

// valori delle quantita' misurabili :                                     // input    : valori assunti come ipotesi nella simulazione
    // misurato : valore dopo la simulazione di misura
    double m_A_input, m_A_misurato;
    double m_B_input, m_B_misurato;
    double m_n1_input, m_n1_misurato;
    double m_n2_input, m_n2_misurato;
    double m_deltam1_input, m_deltam1_misurato;
    double m_deltam2_input, m_deltam2_misurato;
    double m_th0_input, m_th0_misurato;
    double m_th1_input, m_th1_misurato;
    double m_th2_input, m_th2_misurato;


};

#endif /* prisma_h */
