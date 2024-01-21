#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double media(double *X, int dim);
double varianza(double *X, int dim);
double mediana(double *X, int dim);
void caricadafile(char* f, double *X, int dim);
void selectionsort(double*X, int dim);
void swap(double &x, double &y);
void stampa(ofstream &out, double *X, int dim);