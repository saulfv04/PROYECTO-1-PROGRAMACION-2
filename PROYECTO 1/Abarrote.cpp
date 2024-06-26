#include "Abarrote.h"

Abarrote::Abarrote()
{
    this->categoria = "i";
    this->codigo = "i";
    this->descripcion = "i";
    this->empresaNombre = "i";
    this->existencia = 0;
    this->limite = 0;
    this->nacional = false;
    this->nombreComercial = "i";
    this->peso = 0;
    this->precioCosto = 0;
    this->ptrFechaIng = NULL;
    this->ptrPer = NULL;
}

Abarrote::Abarrote(Perecedero* ptrP,Fecha* ptrFI, string eN,bool n, double p, string c, string nC, string d, double pC, string cat, int e, int l)
{
    ptrFechaIng =new Fecha(*ptrFI);
    ptrPer = new Perecedero(*ptrP);
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

Perecedero* Abarrote::getPer()
{
    return ptrPer;
}

int Abarrote::getFechaPer()
{
    return ptrPer->getFechaPer();
}

string Abarrote::toString()const
{
    stringstream s;
    s << "----- PRODUCTO ABARROTE ----- " << endl;
    s << "Nombre " << this->nombreComercial << endl;
    s << "Codigo:  " << this->codigo << endl;
    s << "Fecha de ingreso: " << *this->ptrFechaIng << endl;
    s << "Fecha de vencimiento: " << *this->ptrPer << endl;
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

string Abarrote::getCodigo()const
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

Producto* Abarrote::clonar() const
{
    return new Abarrote(*this);
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


void Abarrote::setFechaIng(Fecha* f){
    this->ptrFechaIng = new Fecha(*f);
}

void Abarrote::SetFechaPer(Perecedero* f){
    this->ptrPer = new Perecedero(*f);
}

double Abarrote::ganancia()
{
    Categoria c;
    return precioCosto * c.porceganancia(categoria);
}

void Abarrote::leerDatos(istream& s)
{
    this->setCategoria("2");
    string op;
	cout << "INGRESO DE DATOS DE PRODUCTOS ABARROTE" << endl << endl;
    Perecedero* p = new Perecedero();
    s >> *p;
    this->SetFechaPer(p);
	Fecha* fI = new Fecha();
    cout << "Fecha de ingreso" << endl;
	s >> *fI;
    if (fI->getFecha() > p->getFechaPer()) {
        throw string("La fecha de ingreso no puede ser mayor a la de vencimiento");
        delete p;
        delete fI;
    }
	this->setFechaIng(fI);
	cout << "Nombre empresa procedencia: " << endl;
	s >> empresaNombre;
    cout << "Nacional (N)No || (S):Si " << endl;
    cin >> op;
    if (op == "S" || op == "s") {
        this->setNacional(true);
    }
    else {
        this->setNacional(false);
    }
	cout << "Nombre Comercial: " << endl;
	s >> nombreComercial;
	cout << "Descripcion: " << endl;
	s >> descripcion;
    cout << "Codigo: " << endl;
    s >> codigo;
	cout << "Precio: " << endl;
	s >> precioCosto;
    if (precioCosto <= 0.0) {
        throw ERI(precioCosto, 0, 0);
    }
	cout << "Peso: " << endl;
	s >> peso;
    if (peso <= 0.0) {
        
        throw ERI(precioCosto, 0, 0);
    }
	cout << "Existencia de producto: " << endl;
	s >> existencia;
	cout << "Limite de compra: " << endl;
	s >> limite;   
    if (existencia < limite) {
        throw string("La existencia no puede menor al limite disponible de productos");
        delete p;
        delete fI;
    }
    if (s.fail()) {
        s.clear();
        s.ignore(1);
        throw string("Se ha digitado un caracter invalido");
    }
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
    file << "Abarrote"<< '\t' <<empresaNombre<<'\t' << Nacional << '\t' << peso << '\t' << codigo << '\t' << nombreComercial << '\t' << descripcion
        << '\t' << precioCosto << '\t' << categoria << '\t' << existencia << '\t' << limite <<'\n';
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
    int exis, limi;
    bool nac;
    getline(file, NombreEmpresa, '\n');
    getline(file, Nacional, '\t');
    getline(file, Peso, '\t');
    getline(file, Codigo, '\t');
    getline(file, NombreComercial, '\t');
    getline(file, Descripcion, '\t');
    getline(file, PrecioCosto, '\t');
    getline(file, Categoria, '\t');
    getline(file, Existencia, '\t');
    getline(file, Limite, '\n');

    fecha = Fecha::leerFecha(file);
    venc = Perecedero::leerPerecedero(file);

    exis = stoi(Existencia);
    limi = stoi(Limite);
    pes = stod(Peso);
    pCost = stod(PrecioCosto);

    if (Nacional == "Nacional")nac = true;
    else nac = false;

    return new Abarrote(venc,fecha, NombreEmpresa,nac, pes,Codigo, NombreComercial, Descripcion, pCost, Categoria, exis, limi);
}


ostream& operator<<(ostream& s, Abarrote& abarrote){
    s << abarrote.toString();
    return s;
}

