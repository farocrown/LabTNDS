/*///////////////////////////////////////////////////////////////////////////
Costruire una classe CampoVettoriale, che erediti dalla classe Posizione :

    aggiungere le tre componenti di un vettore alla posizione
    implementare i metodi per accedere e/o modificare il vettore
    decidere quali costruttori implementare, in particolare, implementare un costruttore CampoVettoriale(const Posizione&) che crei un vettore nullo nella posizione assegnata
    implementare un metodo double Modulo() che restituisca la lunghezza del vettore
    fare overloading di operator+ e operator+= in modo da poter facilmente sommare campi. 
/////////////////////////////////////////////////////////////////////////////*/
#ifndef __campovettoriale_h__
#define __campovettoriale_h__

#include <iostream>
#include <cmath>
#include "posizione.h"

using namespace std;

class campovettoriale: public posizione{
  public:
  // costruttore nullo
  campovettoriale (posizione& P);
  // costruttore 
  campovettoriale (posizione& P, double Fx, double Fy, double Fz);
  campovettoriale (double x, double y, double z, double Fx, double Fy, double Fz);
  // distruttore
  ~campovettoriale(){;};
  //getcomp 
    //X
    double getFx()const {return c_Fx;}
    //Y
    double getFy()const {return c_Fy;}
    //Z
    double getFz()const {return c_Fz;}
    
    //setcomp
      //X
      void setFx(double a) {
          c_Fx=a;
      }
      //Y
      void setFy(double a) {
          c_Fy=a;
      }
      //Z
      void setFz(double a) {
          c_Fz=a;
      }
    
  // operatore somma +
  campovettoriale operator+(const campovettoriale &C) const;
  // operatore somma +=
  campovettoriale& operator+=(const campovettoriale& C);
  //modulo
  double modulo();

  private:
  double c_Fx, c_Fy, c_Fz;
};

campovettoriale::campovettoriale(posizione& P):posizione(P.getX(),P.getY(),P.getZ()){
  c_Fx=0;
  c_Fy=0;
  c_Fz=0;
}
campovettoriale::campovettoriale (posizione& P, double Fx, double Fy, double Fz):posizione(P.getX(),P.getY(),P.getZ()){
  c_Fx=Fx;
  c_Fy=Fy;
  c_Fz=Fz;
}
campovettoriale::campovettoriale (double x, double y, double z, double Fx, double Fy, double Fz):posizione(x,y,z){
  c_Fx=Fx;
  c_Fy=Fy;
  c_Fz=Fz;
}

campovettoriale campovettoriale::operator+(const campovettoriale &C) const{
    campovettoriale a (C);
    if (a.getX()==getX() && a.getY()==getY() && a.getZ()==getZ()) {
        a.setFx(getFx()+a.c_Fx);
        a.setFy(getFy()+a.c_Fy);
        a.setFz(getFz()+a.c_Fz);
    }
    else{
        cout<<"Errore: stai cercando di sommare il campo in due posizioni diverse!"<<endl;
        exit(-1);
    }
//  a.c_Fx+=getFx();
//  a.c_Fy+=getFy();
//  a.c_Fz+=getFz();

  return a;
}
campovettoriale& campovettoriale::operator+=(const campovettoriale& C){
  return(*this)=(*this)+C;
}

double campovettoriale::modulo(){
  double a=sqrt(pow(c_Fx,2)+pow(c_Fy,2)+pow(c_Fz,2));
  return a;
}

#endif //__campovettoriale_h__
