#include "particella.h"

int main (){

  particella *a = new particella(1.,2.);
  elettrone  *e = new elettrone();
  particella *b = new elettrone(); // puntatore a Particella punta a un Elettrone

  a->print(); // Meteodo Print di Particella
  e->print(); // Meteodo Print di Elettrone
  b->print(); // ???

  delete a;
  delete e;
  delete b;

  return 0;
}
