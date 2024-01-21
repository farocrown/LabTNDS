/*/////////////////////////////////////////////////////////////////////////////
La classe PuntoMateriale: questa classe ci servirà per rappresentare le sorgenti dei campi. Costruire la classe in modo che erediti da entrambe le classi Particella e Posizione.

    Implementare i costruttori che pensate siano utili.
    Implementare il metodo CampoVettoriale CampoElettrico(const Posizione&) const che restituisca il campo elettrico generato dal PuntoMateriale nel punto r (per i più volenterosi anche il metodo CampoVettoriale CampoGravitazionale(const Posizione&) const che restituisca il campo gravitazionale generato dal PuntoMateriale nel punto r). 
/////////////////////////////////////////////////////////////////////////////*/
#ifndef __puntomateriale_h__
#define __puntomateriale_h__

#include <iostream>
#include "posizione.h"
#include "particella.h"
#include "campovettoriale.h"

using namespace std;

class puntomateriale: public particella, public posizione{
  public:
  //costruttori
    puntomateriale (const posizione& P, double m, double q);
    puntomateriale (const posizione& P, const particella &D);
    puntomateriale (double x, double y, double z, double m, double q);
    puntomateriale (double x, double y, double z, const particella &D);
  //distruttore
  ~puntomateriale(){;};
  //campo elettrico
  campovettoriale campoElettrico (const posizione& P);
  campovettoriale CampoGravitazionale (const posizione& P);
  //campo gravitazionale
};

puntomateriale::puntomateriale (const posizione& P, double m, double q): particella(m,q), posizione(P){}

puntomateriale::puntomateriale (const posizione& P, const particella &D): particella(D), posizione(P){}

puntomateriale::puntomateriale (double x, double y, double z, double m, double q):particella(m,q), posizione(x,y,z){}

puntomateriale::puntomateriale (double x, double y, double z, const particella &D):particella(D), posizione(x,y,z){}

campovettoriale puntomateriale::campoElettrico (const posizione& P){
  double c=p_charge/(4*acos(-1)*8.8541788E-12*pow(distanza(P),3));
  double Ex=c*(P.getX()-p_a);
  double Ey=c*(P.getY()-p_b);
  double Ez=c*(P.getZ()-p_c);
  return campovettoriale(P.getX(),P.getY(),P.getZ(),Ex,Ey,Ez);
}
/*campovettoriale CampoGravitazionale (const posizione& P){
  Gx=
  Gy=
  Gz=
  return campovettoriale(P,Gx,Gy,Gz)
}*/

#endif //__puntomateriale_h__
