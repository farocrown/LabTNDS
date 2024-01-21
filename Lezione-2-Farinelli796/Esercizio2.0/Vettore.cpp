
#include "Vettore.h"
#include <iomanip>
#include <cmath>
#include <cstdlib>

//#define NDEBUG 

#include <assert.h>

// costruttore senza argomenti

Vettore::Vettore()  {
  cout << "Calling default constructor" << endl;
  m_N = 0;
  m_v = NULL;
}

// costruttore con dimensione

Vettore::Vettore(unsigned int N) {
  cout << "Calling constructor with arguments" << endl;
  m_N = N;
  m_v = new double[N];
  for ( int k = 0 ; k < N ; k++ ) m_v[k] = 0;
  
}

void Vettore::SetComponent(unsigned int i, double a) {
  assert( ( m_N > i ) && "Errore : l'indice e' troppo grande");
  if ( i<m_N ) {
    m_v[i]=a;
  } else {
    cerr << "Errore: indice " << i << ", dimensione " << m_N << endl;
    exit (-1);
  }
}

// ...