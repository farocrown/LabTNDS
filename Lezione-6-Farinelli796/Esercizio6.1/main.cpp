#include <stdio.h>
#include <iostream>
#include <cmath>
#include "funzionebase.h"

using namespace std;

int main(int argc, char** argv){
    if (argc<4){
      cout<<"Il programma "<<argv[0]<<"  ha bisogno di <a>, <b> e <c>"<<endl;
      return -1;
    }
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);
    
    parabola P (a,b,c);
    cout<<"\tParabola: \t"<<a<<"x^2+"<<b<<"x+"<<c<<endl;
    cout<<"\tVertice: \t( "<<(-b/(2*a))<<" , "<<P.eval((-b/(2*a)))<<" )"<<endl;
    
    return 0;
    
}
