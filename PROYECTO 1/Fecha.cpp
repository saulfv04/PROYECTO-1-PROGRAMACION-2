#include "Fecha.h"

Fecha::Fecha(int d, int m, int a)
{
    dia = d;
    mes = m;
    anio = a;
}

Fecha::Fecha(const Fecha& copia)
{
    this->anio = copia.anio;
    this->mes = copia.mes;
    this->dia = copia.dia;
}

Fecha::~Fecha(){}

int Fecha::getFecha()
{
    int a, d, m = 0;

    a = anio * 31536000;
    d = dia * 86400;
    m = mes * 2592000;

    return a + d + m;

}

string Fecha::toString()
{
    stringstream s;

    s << "Fecha (D/M/A): " << dia << " / " << mes << " / " << anio << " / " << endl;

    return s.str();

}
