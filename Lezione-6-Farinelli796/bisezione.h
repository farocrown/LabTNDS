#ifndef __bisezione__
#define __bisezione__

#include <float.h> // Serve per includere DBL_MAX

#include "Solutore.h"

using namespace std;

// funzione sign utile negli algoritmi di ricerca zeri

int sign(double x){
  if(x<0)
    return -1;
  else
    return 1;
}

class Bisezione : public Solutore {

public:

// costruttori 

	Bisezione () : Solutore() {;} ;
  Bisezione (double a, double b, double prec) : Solutore (a,b,prec) { ; } ;

  ~Bisezione () {;};

  double CercaZeri (double a, 	
										double b, 
										const FunzioneBase* f,
										double prec = 0.001,
										unsigned int nmax = 100 ) override {
// IMPLEMENTARE
  }

  double CercaZeri (double a, 
										double b, 
										const FunzioneBase& f,
										double prec = 0.001,
										unsigned int nmax = 100 ) override {
// IMPLEMENTARE
  }

};

#endif // __bisezione__
