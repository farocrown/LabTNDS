#ifndef __Vettore_h__
#define __Vettore_h__

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Vettore {
 public:

	Vettore();
	Vettore(unsigned int N);

	// ...

	void SetComponent(unsigned int, double); 

	// ...

 private:

	unsigned int m_N;
	double * m_v;

};

#endif __Vettore_h__
