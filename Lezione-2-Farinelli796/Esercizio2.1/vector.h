#ifndef __gianni_h__
#define __gianni_h__

#include <iostream>
#include <fstream>
#include <string>

class gianni{
  public:
  //costruttori
  gianni();                   //costruttore "vuoto"
  gianni(unsigned int);     //costruttore "pieno"
  gianni(const gianni&);
  gianni& operator=(const gianni&);
  //distruttore
  ~gianni();
  //metodi
  unsigned int getsize() const;
  void setcomp(unsigned int, double);
  double getcomp(unsigned int) const;
  void swap(unsigned int,unsigned int);


  private:
  int v_size;
  double* v_arr;
  
};

#endif //__gianni_h__