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
    this->envasado = copia.envasado;
    this->ptrFechaIng = new Fecha(*copia.ptrFechaIng);
    this->codigo = copia.codigo;
    this->nombreComercial = copia.nombreComercial;
    this->descripcion = copia.descripcion;
    this->precioCosto = copia.precioCosto;
    this->categoria = copia.categoria;
    this->existencia = copia.existencia;
    this->limite = copia.limite;
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
    s << "----- PRODUCTO CONSERVA ----- " << endl;
    s << "Nombre " << this->nombreComercial << endl;
    s << "Codigo:  " << this->codigo << endl;
    s << "Fecha de ingreso: " << this->ptrFechaIng->toString() << endl;
    s << "Categoria:  " << this->categoria << endl;
    s << "Envasado: ";
    if (envasado) {
        s << "(Verdadero)" << endl;
    }
    else {
        s << "(Falso)" << endl;
    }
    s << "Descripcion:  " << this->descripcion<< endl;
    s << "Precio costo:  $" << this->precioCosto << endl;
    s << "Existencia:  " << this->existencia << endl;
    s << "Limite de compra:  " << this->limite << endl;
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

double Conserva::ganancia()
{
    Categoria c;
    return precioCosto * c.porceganancia(categoria);
}
