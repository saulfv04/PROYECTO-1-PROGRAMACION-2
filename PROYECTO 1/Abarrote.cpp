#include "Abarrote.h"

Abarrote::Abarrote(Perecedero* ptrP,Fecha* ptrFI, string eN,bool n, double p, string c, string nC, string d, double pC, string cat, int e, int l)
{
    ptrFechaIng = ptrFI;
    ptrPer = ptrP;
    empresaNombre = eN;
	nacional = n;
	peso = p;
    codigo = c;
    nombreComercial = nC;
    descripcion = d;
    precioCosto = pC;
    categoria = cat;
    existencia = e;
    limite = l;
}

Abarrote::~Abarrote()
{
    if (ptrFechaIng != nullptr) {
        delete ptrFechaIng;
    }
    if (ptrPer != nullptr) {
        delete ptrPer;
    }
}

string Abarrote::getEmpresaNombre()
{
	return empresaNombre;
}

void Abarrote::setEmpresaNombre(string eN)
{
    empresaNombre = eN;

}

int Abarrote::getFechaIng()
{
    return ptrFechaIng->getFecha();
}

int Abarrote::getFechaPer()
{
    return ptrPer->getFechaPer();
}

string Abarrote::toString()
{
}

string Abarrote::getnombreComecial()
{
    return nombreComercial;
}

string Abarrote::getCodigo()
{
    return codigo;
}

string Abarrote::getDescripcion()
{
    return descripcion;
}

double Abarrote::getprecioCosto()
{
    return precioCosto;
}

string Abarrote::getCategoria()
{
    return categoria;
}

int Abarrote::getExistencia()
{
    return existencia;
}

int Abarrote::getLimite()
{
    return limite;
}

void Abarrote::setCodigo(string c)
{
    codigo = c;
}

void Abarrote::setnombreComercial(string nC)
{
    nombreComercial = nC;
}

void Abarrote::setDescripcion(string d)
{
    descripcion = d;
}

void Abarrote::setprecioCosto(double pC)
{
    precioCosto = pC;
}

void Abarrote::setCategoria(string cat)
{
    categoria = cat;
}

void Abarrote::setExistencia(int e)
{
    existencia = e;
}

void Abarrote::setLimite(int l)
{
    limite = l;
}
