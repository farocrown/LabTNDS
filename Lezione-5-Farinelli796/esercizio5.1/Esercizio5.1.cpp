#include "particella.h"
#include <iostream> 

using namespace std;

int main() {

  particella *a   = new particella(1.,1.6E-19);
  elettrone *e    = new elettrone();
  
  // Metodi della classe base
  cout << "Particella " << a->getMass() << "," << a->getCharge() << endl;
  a->print(); 

  // Metodi della classe derivata
  cout << "Elettrone " << e->getMass() << "," << e->getCharge() << endl;
  e->print(); 

  particella b(*a) ;  // costruisco una Particella a partire da una Particella
  particella d(*e);   // costruisco una Particella a partire da un Elettrone
  //elettrone f(d);    // costruisco un Elettrone a partire da una Particella 

  return 0;

}


