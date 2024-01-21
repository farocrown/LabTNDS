#include <vector>
#include <iostream>

#include "calcolovettoriale.h"

using namespace std;

int main() {

    vector<double> v1 { 3.,4.,6.} ;
    vector<double> v2 { 4.,5.,6.} ;

    double para = 2.;
    
    

    stampa(v1+v2,"Sòòmma di v1 e v2");
    stampa(v1-v2,"Differenza di v1 e v2");
    stampa(para*v1,"Prodotto per lo scalare 2");
    stampa(v1*para,"Prodotto per lo scalare 2");
    cout<<"Prodotto scalare o interno che dir si voglia:"<<endl<<v1*v2<<endl;
    stampa(v1/para,"Divisione per uno scalare");

    // provare la somma e prodotto per scalare
    return 0;
}
