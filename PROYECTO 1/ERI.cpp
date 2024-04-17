#include "ERI.h"

ERI::ERI(int v, int mx, int mn) :valor(v), ExcepcionRango(mx, mn) {}

ERI::~ERI(){}

const char* ERI::what() const throw()
{
    return "El valor ingresado en menor al permitido";
}

string ERI::toString()
{
    stringstream s;
    s << "El valor ingresado: " << valor << " es menor al permitido: " << min;
    return s.str();
}
