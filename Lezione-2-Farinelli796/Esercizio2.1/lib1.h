#ifndef __funzioni__
#define __funzioni__

#include <iostream>
#include <cmath>
#include <fstream>
#include "vector.h"

using namespace std;

gianni leggi(int, const char*);
double media(const gianni&);
double varianza(const gianni&);
double mediana(const gianni&); 
void selsort(gianni&);
void stampa(const gianni&);
void stampa(const gianni&, ofstream&out);


#endif
