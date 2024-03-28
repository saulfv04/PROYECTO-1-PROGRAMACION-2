#include "Embutido.h"

Embutido::Embutido(Empaque* ptrEm, string mar, string nA, string pA, Perecedero* ptrPere, Fecha* ptrF, string eN, bool n, double p, string c, string nC, string d, double pC, string cat, int e, int l)
{
    ptrEmpaque = ptrEm;
    marca = mar;
    nombreAnimal = nA;
    parteDelAnimal = pA;
    nacional = n;
    peso = p;
    codigo = c;
    nombreComercial = nC;
    descripcion = d;
    precioCosto = pC;
    categoria = cat;
    existencia = e;
    limite = l;
    ptrPer = ptrPere;
    ptrFechaIng = ptrF;
}

Embutido::Embutido(const Embutido& e)
{
    this->ptrEmpaque = new Empaque(*e.ptrEmpaque);
    this->marca = e.marca;
    this->nombreAnimal = e.nombreAnimal;
    this->parteDelAnimal = e.parteDelAnimal;
    this->nacional = e.nacional;
    this->peso = e.peso;
    this->codigo = e.codigo;
    this->nombreComercial = e.nombreComercial;
    this->descripcion = e.descripcion;
    this->precioCosto = e.precioCosto;
    this->categoria = e.categoria;
    this->existencia = e.existencia;
    this->limite = e.limite;
    this->ptrPer = new Perecedero(*e.ptrPer);
    this->ptrFechaIng = new Fecha(*e.ptrFechaIng);
}

Embutido::~Embutido()
{
    if (ptrFechaIng != nullptr) {
        delete ptrFechaIng;
    }
    if (ptrPer != nullptr) {
        delete ptrPer;
    }
    if (ptrEmpaque != nullptr) {
        delete ptrEmpaque;
    }
}

string Embutido::getMarca()
{
    return marca;
}

bool Embutido::getEmpaque()
{
    return ptrEmpaque->getTripa();
}

void Embutido::setMarca(string m)
{
    marca = m;
}

void Embutido::setEmpaque(Empaque* em)
{
    ptrEmpaque = em;
}

bool Embutido::getNacional()
{
    return false;
}

double Embutido::getPeso()
{
    return 0.0;
}

void Embutido::setNacional(bool)
{
}

void Embutido::setPeso(double)
{
}

string Embutido::getNombreAnimal()
{
    return nombreAnimal;
}

string Embutido::getparteDelAnimal()
{
    return parteDelAnimal;
}

void Embutido::setNombreAnimal(string nA)
{
    nombreAnimal = nA;
}

void Embutido::setparteDelAnimal(string pA)
{
    parteDelAnimal = pA;
}

int Embutido::getFechaIng()
{
    return ptrFechaIng->getFecha();
}

int Embutido::getFechaPer()
{
    return ptrPer->getFechaPer();
}

string Embutido::toString()
{
    stringstream s;
    s << "----- PRODUCTO CONSERVA ----- " << endl;
    s << "Marca: " << this->marca << endl;
    s << "Nombre: " << this->nombreComercial << endl;
    s << "Codigo:  " << this->codigo << endl;
    s << "Fecha de ingreso: " << this->ptrFechaIng->toString() << endl;
    s << "Categoria:  " << this->categoria << endl;
    s << "Empaque: ";
    if (ptrEmpaque->getTripa()) {
        s << "(con) tripa " << endl;
    }
    else {
        s << "(sin) tripa " << endl;
    }
    s << "Descripcion:  " << this->descripcion << endl;
    s << "Procedencia animal:  " << this->nombreAnimal<< endl;
    s << "Parte animal:  " << this->parteDelAnimal << endl;
    s << "Precio costo:  $" << this->precioCosto << endl;
    s << "Existencia:  " << this->existencia << endl;
    s << "Limite de compra:  " << this->limite << endl;
    return s.str();
}

string Embutido::getnombreComecial()
{
    return nombreComercial;
}

string Embutido::getCodigo()
{
    return codigo;
}

string Embutido::getDescripcion()
{
    return descripcion;
}

double Embutido::getprecioCosto()
{
    return precioCosto;
}

string Embutido::getCategoria()
{
    return categoria;
}

int Embutido::getExistencia()
{
    return existencia;
}

int Embutido::getLimite()
{
    return limite;
}

void Embutido::setCodigo(string c)
{
    codigo = c;
}

void Embutido::setnombreComercial(string nC)
{
    nombreComercial = nC;
}

void Embutido::setDescripcion(string d)
{
    descripcion = d;
}

void Embutido::setprecioCosto(double pC)
{
    precioCosto = pC;
}

void Embutido::setCategoria(string cat)
{
    categoria = cat;
}

void Embutido::setExistencia(int e)
{
    existencia = e;
}

void Embutido::setLimite(int l)
{
    limite = l;
}

double Embutido::ganancia()
{
    Categoria c;
    return precioCosto * c.porceganancia(categoria);
}
