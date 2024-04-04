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

Abarrote::Abarrote(const Abarrote& copia)
{
    this->ptrFechaIng = new Fecha(*copia.ptrFechaIng);
    this->ptrPer =new Perecedero(*copia.ptrPer);
    this->empresaNombre = copia.empresaNombre;
    this->nacional = copia.nacional;
    this->peso = copia.peso;
    this->codigo = copia.codigo;
    this->nombreComercial = copia.nombreComercial;
    this->descripcion = copia.descripcion;
    this->precioCosto = copia.precioCosto;
    this->categoria = copia.categoria;
    this->existencia = copia.existencia;
    this->limite = copia.limite;

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

bool Abarrote::getNacional()
{
    return this->nacional;
}

double Abarrote::getPeso()
{
    return this->precioCosto;
}

void Abarrote::setNacional(bool t)
{
    this->nacional = t;
}

void Abarrote::setPeso(double p)
{
    this->precioCosto = p;
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
    stringstream s;
    s << "----- PRODUCTO ABARROTE ----- " << endl;
    s << "Nombre " << this->nombreComercial << endl;
    s << "Codigo:  " << this->codigo << endl;
    s << "Fecha de ingreso: " << this->ptrFechaIng->toString() << endl;
    s << "Fecha de vencimiento: " << this->ptrPer->toString() << endl;
    s << "Categoria:  " << this->categoria << endl;
    if (this->nacional) {
        s << "Nacional " << endl;
    }
    else {
        s << "Internacional " << endl;
    }
    s << "Peso:  " << this->peso << endl;
    s << "Empresa nombre:  " << this->empresaNombre << endl;
    s << "Descripcion:  " << this->descripcion << endl;
    s << "Precio costo:  $" << this->precioCosto << endl;
    s << "Existencia:  " << this->existencia << endl;
    s << "Limite de compra:  " << this->limite << endl;
    return s.str();
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

double Abarrote::ganancia()
{
    Categoria c;
    return precioCosto * c.porceganancia(categoria);
}

void Abarrote::guardarProducto(ofstream& file)
{
    string Nacional;
    if (nacional == true) {
        Nacional = "(Verdadero)";
    }
    else {
        Nacional = "(Falso)";
    }
    file << "Abarrote"<<empresaNombre<<'\t' << Nacional << '\t' << peso << '\t' << codigo << '\t' << nombreComercial << '\t' << descripcion
        << '\t' << precioCosto << '\t' << categoria << '\t' << existencia << '\t'
        << '\t' << limite <<'\t';
    if (ptrFechaIng!= NULL) {
        ptrFechaIng->guardarFecha(file);
    }
    if (ptrPer != NULL) {
        ptrPer->guardarPerecedero(file);
    }
}

Abarrote* Abarrote::leerAbarrote(ifstream& file)
{
    string Codigo, NombreComercial, Descripcion, PrecioCosto, Categoria, Existencia, Limite, Peso, Nacional, NombreEmpresa;
    Fecha* fecha = NULL;
    Perecedero* venc = NULL;
    double pCost, pes;
    int exis, lim;
    bool nac;
    getline(file, Codigo, '\t');
    getline(file, NombreComercial, '\t');
    getline(file, Descripcion, '\t');
    getline(file, PrecioCosto, '\t');
    getline(file, Categoria, '\t');
    getline(file, Existencia, '\t');
    getline(file, Limite, '\t');
    getline(file, Peso, '\t');
    getline(file, Nacional, '\t');
    getline(file, Limite, '\t');
    getline(file, NombreEmpresa, '\n');

    fecha = Fecha::leerFecha(file);
    venc = Perecedero::leerPerecedero(file);

    exis = stoi(Existencia);
    lim = stoi(Limite);
    pes = stod(Peso);
    pCost = stod(PrecioCosto);

    if (Nacional == "Nacional")nac = true;
    else nac = false;

    return new Abarrote(venc,fecha, NombreEmpresa,nac, pes,Codigo, NombreComercial, Descripcion, pCost, Categoria, exis, lim);
}
//
//void Abarrote::print(ostream& s)
//{
//    s << "Nombre " << nombreComercial << endl;
//    s << "Fecha de vencimiento: " << ptrPer << endl;
//    if (nacional) {
//        s << "Nacional " << endl;
//    }
//    else {
//        s << "Internacional " << endl;
//    }
//    s << "Peso:  " << peso << endl;
//    s << "Empresa nombre:  " << empresaNombre << endl;
//    s << "Precio costo:  $" << precioCosto << endl;
//}

