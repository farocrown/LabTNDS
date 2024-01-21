/*///////////////////////////////////////////////////////////////////////////
Costruiamo una classe Particella caratterizzata dall'avere una massa ed una carica, quindi dotata dei seguenti metodi:

    Un construttore avente come argomenti massa e carica.
    Dei metodi di accesso ai valori di massa e carica.
    Un metodo per stampare tali valori. 
///////////////////////////////////////////////////////////////////////////*/

#ifndef __particella_h__
#define __particella_h__

#include <iostream>
#include <cmath>

using namespace std;

class particella{
  public:
  //costruttore
  particella(double a, double b){p_mass=a; p_charge=b;}
  //distruttore
  ~particella(){;};
  //access methods
  double getMass() const {return p_mass;}
  double getCharge() const {return p_charge;}
  //print 
  virtual void print() const {
    cout<<"Particella: m="<< p_mass <<", q="<< p_charge <<"."<<endl;
  }

  protected:
  double p_mass;
  double p_charge;
};

#endif //__particella_h__

#ifndef __elettrone_h__
#define __elettrone_h__

class elettrone: public particella{
  public:
  //costruttore
  elettrone(): particella(9.1093826E-31,-1.60217653E-19){};
  //distruttore
  //~elettrone(){;};
  //stampa
  void print() const {cout<<"Elettrone: m="<< p_mass <<", q="<< p_charge <<"."<<endl;}
};

#endif //__elettrone_h__

