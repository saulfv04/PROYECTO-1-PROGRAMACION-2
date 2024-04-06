#include "Embutido.h"

Embutido::Embutido(Empaque* ptrEm, string mar, string nA, string pA, Perecedero* ptrPere, Fecha* ptrF, bool n, double p, string c, string nC, string d, double pC, string cat, int e, int l)
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

Perecedero* Embutido::getPer()
{
    return ptrPer;
}

int Embutido::getFechaPer()
{
    return ptrPer->getFechaPer();
}

string Embutido::toString()
{
    stringstream s;
    s << "----- PRODUCTO EMBUTIDO ----- " << endl;
    s << "Marca: " << this->marca << endl;
    s << "Nombre: " << this->nombreComercial << endl;
    s << "Codigo:  " << this->codigo << endl;
    s << "Fecha de ingreso: " << *this->ptrFechaIng << endl;
    s << "Fecha de vencimiento: " << *this->ptrPer << endl;
    s << "Categoria:  " << this->categoria << endl;
    s << "Empaque: ";
    if (this->ptrEmpaque->getTripa()) {
        s << "(con) tripa " << endl;
    }
    else {
        s << "(sin) tripa " << endl;
    }
    if (this->nacional) {
        s << "Nacional " << endl;
    }
    else {
        s << "Internacional " << endl;
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

void Embutido::guardarProducto(ofstream& file)
{
    string nacionalF;
    if (this->nacional)nacionalF = "(Verdadero)";
    else nacionalF = "(Falso)";


    file << "Embutido" << '\t' << marca << '\t' << nombreAnimal<<'\t'<<parteDelAnimal<<'\t'<<nacionalF<<'\t'<<peso<< '\t' << codigo << '\t' << nombreComercial << '\t' << descripcion << '\t'
        << precioCosto << '\t' << categoria << '\t' << existencia << '\t' << limite << '\n';
    if (ptrFechaIng != nullptr) {
        ptrFechaIng->guardarFecha(file);
    }

    if (ptrEmpaque != nullptr) {
        ptrEmpaque->guardarEmpaque(file);
    }
    if (ptrPer != nullptr) {
        ptrPer->guardarPerecedero(file);
    }
    if (ptrFechaIng != nullptr) {
        ptrFechaIng->guardarFecha(file);
    }
}

Embutido* Embutido::leerEmbutido(ifstream& file)
{

    string marcaF,nombreAnimalF,parteDelAnimalF,nacionalF,pesoF, codigoF, nombreComercialF, descripcionF, precioCostoF, categoriaF, existenciaF, limiteF;
    bool nac;
    double precioCost, pe;
    int exist, limit;
    Empaque* emp;
    Fecha* fec;
    Perecedero* fecPer;



    getline(file, marcaF, '\t');
    getline(file, nombreAnimalF, '\t');
    getline(file, parteDelAnimalF, '\t');
    getline(file, nacionalF, '\t');
    getline(file, pesoF, '\t');
    getline(file, codigoF, '\t');
    getline(file, nombreComercialF, '\t');
    getline(file, descripcionF, '\t');
    getline(file, precioCostoF, '\t');
    getline(file, categoriaF, '\t');
    getline(file, existenciaF, '\t');
    getline(file, limiteF, '\n');


    pe = stod(pesoF);
    precioCost = stod(precioCostoF);
    exist = stoi(existenciaF);
    limit = stoi(limiteF);

    if (nacionalF == "(Verdadero)")nac = true;
    else  nac = false;


    emp = Empaque::leerEmpaque(file);
    fec = Fecha::leerFecha(file);
    fecPer = Perecedero::leerPerecedero(file);

    return new Embutido(emp,marcaF,nombreAnimalF,parteDelAnimalF,fecPer,fec,nac,pe, codigoF, nombreComercialF, descripcionF, precioCost, categoriaF, exist, limit);
}
ostream& operator<<(ostream& s, Embutido& e)
{
    s << e.toString();
    return s;
}
