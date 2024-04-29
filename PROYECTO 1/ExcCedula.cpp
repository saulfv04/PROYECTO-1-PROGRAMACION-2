#include "ExcCedula.h"

ExcCedula::ExcCedula(string v)
{
    valor = v;
}

ExcCedula::~ExcCedula()
{
}

const char* ExcCedula::what() const throw()
{
    return "La Cedula ingresada tiene el formato incorrecto";
}

string ExcCedula::toString()
{
    stringstream s;
    s << "La cedula ingresada fue: " << valor << " lleva el formato incorrecto";
    return s.str();
}
