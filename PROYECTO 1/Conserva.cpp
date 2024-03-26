#include "Conserva.h"

Conserva::Conserva(Fecha* ptrF, bool en, string c, string nC, string d, double pC, string cat, int e, int l) {
    envasado = en;
    ptrFechaIng = ptrF;
    codigo = c;
    nombreComercial = nC;
    descripcion = d;
    precioCosto = pC;
    categoria = cat;
    existencia = e;
    limite = l;
}

Conserva::Conserva(const Conserva& copia)
{
}

Conserva::~Conserva(){
    if (ptrFechaIng != nullptr) {
        delete ptrFechaIng;
    }
}

bool Conserva::getEnvasado()
{
    return envasado;
}

void Conserva::setEnvasado(bool e)
{
    envasado = e;
}


string Conserva::toString()
{
    stringstream s;
    s << "Descripcion: " << descripcion;
    return s.str();
}

int Conserva::getFechaIng()
{
    return ptrFechaIng->getFecha();
}

string Conserva::getnombreComecial()
{
    return nombreComercial;
}

string Conserva::getCodigo()
{
    return codigo;
}

string Conserva::getDescripcion()
{
    return descripcion;
}

double Conserva::getprecioCosto()
{
    return precioCosto;
}

string Conserva::getCategoria()
{
    return categoria;
}

int Conserva::getExistencia()
{
    return existencia;
}

int Conserva::getLimite()
{
    return limite;
}

void Conserva::setCodigo(string c)
{
    codigo = c;
}

void Conserva::setnombreComercial(string nC)
{
    nombreComercial = nC;
}

void Conserva::setDescripcion(string d)
{
    descripcion = d;
}

void Conserva::setprecioCosto(double pC)
{
    precioCosto = pC;
}

void Conserva::setCategoria(string cat)
{
    categoria = cat;
}

void Conserva::setExistencia(int e)
{
    existencia = e;
}

void Conserva::setLimite(int l)
{
    limite = l;
}
