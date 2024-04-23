#include "Embutido.h"

Embutido::Embutido()
{
    this->categoria = "i";
    this->codigo = "i";
    this->descripcion = "i";
    this->ptrEmpaque = NULL;
    this->existencia = 0;
    this->limite = 0;
    this->nacional = false;
    this->nombreComercial = "i";
    this->peso = 0;
    this->precioCosto = 0;
    this->ptrFechaIng = NULL;
    this->ptrPer = NULL;
    this->parteDelAnimal = "i";
    this->nombreAnimal = "i";
    this->marca = "i";
}

Embutido::Embutido(Empaque* ptrEm, string mar, string nA, string pA, Perecedero* ptrPere, Fecha* ptrF, bool n, double p, string c, string nC, string d, double pC, string cat, int e, int l)
{
    ptrEmpaque = new Empaque(*ptrEm);
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
    ptrPer = new Perecedero(*ptrPere);
    ptrFechaIng = new Fecha(*ptrF);
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

string Embutido::toString()const
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

string Embutido::getCodigo()const
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

void Embutido::setFechaIng(Fecha* f)
{
    this->ptrFechaIng = new Fecha(*f);
}

void Embutido::SetFechaPer(Perecedero* f)
{
    this->ptrPer = new Perecedero(*f);
}

Empaque* Embutido::getEmaqueptr()
{
    return ptrEmpaque;
}

double Embutido::ganancia()
{
    Categoria c;
    return precioCosto * c.porceganancia(categoria);
}

Producto* Embutido::clonar() const
{
    return new Embutido(*this);
}

void Embutido::guardarProducto(ofstream& file)
{
    string nacionalF;
    if (this->nacional)nacionalF = "(Verdadero)";
    else nacionalF = "(Falso)";


    file << "Embutido" << '\t' <<codigo<< '\t' << marca << '\t' << nombreAnimal<<'\t'<<parteDelAnimal<<'\t'<<nacionalF<<'\t'<<peso << '\t' << nombreComercial << '\t' << descripcion << '\t'
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


    getline(file, codigoF, '\t');
    getline(file, marcaF, '\t');
    getline(file, nombreAnimalF, '\t');
    getline(file, parteDelAnimalF, '\t');
    getline(file, nacionalF, '\t');
    getline(file, pesoF, '\t');
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
void Embutido::leerDatos(istream& s)
{
    this->setCategoria("3");
    string nac;
    cout << "INGRESO DE DATOS DE PRODUCTOS EMBUTIDO" << endl << endl;
    Empaque* emp = new Empaque();
    s >> *emp;
    setEmpaque(emp);
    Perecedero* p = new Perecedero();
    s >> *p;
    SetFechaPer(p);
    Fecha* f = new Fecha();
    cout << "Fecha de ingreso: " << endl;
    s >> *f;
    if (f->getFecha() > p->getFechaPer()) {
        throw string("La fecha de ingreso no puede ser mayor a la de vencimiento");
        delete emp;
        delete f;
    }
    setFechaIng(f);
    cout<<"Marca: "<<endl;
	s >> marca;
	cout << "Nombre del animal: ";
	s >> nombreAnimal;
	cout << "Parte del animal: ";
	s >> parteDelAnimal;
    cout << "Nacional (N)No  (S):Si ";
    cin >> nac;
    if (nac == "S" || nac == "s") {
        setNacional(true);
    }
    else {
        setNacional(false);
    }
	cout << "Peso: ";
	s >> peso;
    if (peso <= 0) {
        throw ERI(peso, 0, 0);
        delete emp;
        delete f;
    }
	cout << "Codigo: ";
	s >> codigo;
	cout << "Nombre comercial: ";
	s >> nombreComercial;
	cout << "Descripcion: ";
	s >> descripcion;
	cout << "Precio de costo: ";
	s >> precioCosto;
    if (precioCosto <= 0) {
        throw ERI(precioCosto, 0, 0);
        delete emp;
        delete f;
    }
	cout << "Existencia: ";
	s >> existencia;
	cout << "Limite: ";
	s >> limite;
    if (existencia < limite) {
        throw string("La existencia no puede menor al limite disponible de productos");
        delete emp;
        delete f;
    }
    if (s.fail()) {
        s.clear();
        s.ignore(1);
        throw string("Se ha digitado un caracter invalido");
        delete emp;
        delete f;
    }
}
ostream& operator<<(ostream& s, Embutido& e)
{
    s << e.toString();
    return s;
}