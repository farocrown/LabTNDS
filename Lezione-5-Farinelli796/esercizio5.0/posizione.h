#ifndef __posizione_h__
#define __posizione_h__

#include <iostream>
#include <cmath>

class posizione{
  public:
  //costruttore vuoto:
  posizione(){p_a=0; p_b=0; p_c=0;}
  //costruttore pieno:
  posizione(double x, double y, double z){p_a=x; p_b=y; p_c=z;}
  //distruttore
  ~posizione(){;};
  //coordinate cartesiane:
  //coord x
  double getX() const {return p_a;}
  //coord y
  double getY() const {return p_b;}
  //coord z
  double getZ() const {return p_c;}

  //coordinate sferiche:
  //R
  double getR() const {
    double a=sqrt(pow(p_a,2)+pow(p_b,2)+pow(p_c,2));
    return a;
  }
  //Theta
  double getTheta() const { 
    double a= acos(p_a/getR());
    return a; 
  }
  //Phi 
  double getPhi() const { 
    double a= atan(p_b/p_a);
    return a; 
  }
  //coordinate cilindriche:
  //Rho
  double getRho() const {
    double a=sqrt(pow(p_a,2)+pow(p_b,2));
    return a;
  }
  //distanza:
  double distanza(posizione P) const {
    double a=sqrt(pow(p_a-P.getX(),2)+pow(p_b-P.getY(),2)+pow(p_c-P.getZ(),2));
    return a;
   }


protected:
double p_a, p_b, p_c;

};


#endif //__posizione_h__