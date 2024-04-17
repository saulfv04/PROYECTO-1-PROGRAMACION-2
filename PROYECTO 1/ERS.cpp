#include "ERS.h"

ERS::ERS(int v, int mx, int mn):valor(v),ExcepcionRango(mx,mn) {}

ERS::~ERS(){}

const char* ERS::what() const throw()
{
    return "El valor ingresado en mayor al permitido";
}

string ERS::toString()
{
    stringstream s;
    s << "El valor ingresado: " << valor << " es mayor al permitido: " << max;
    return s.str();
}
