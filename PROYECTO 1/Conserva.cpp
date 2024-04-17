#include "Conserva.h"

Conserva::Conserva()
{
    this->categoria = "i";
    this->codigo = "i";
    this->descripcion = "i";
    this->envasado = false;
    this->existencia = 0;
    this->limite = 0;
    this->nombreComercial = "i";
    this->ptrFechaIng = NULL;
    this->precioCosto = 0;
}

Conserva::Conserva(Fecha* ptrF, bool en, string c, string nC, string d, double pC, string cat, int e, int l) {
    envasado = en;
    ptrFechaIng = new Fecha(*ptrF);
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
    cout << "Borrando Conserva" << endl;

}

bool Conserva::getEnvasado()
{
    return envasado;
}

void Conserva::setEnvasado(bool e)
{
    envasado = e;
}


string Conserva::toString()const
{
    stringstream s;
    s << "----- PRODUCTO CONSERVA ----- " << endl;
    s << "Nombre " << this->nombreComercial << endl;
    s << "Codigo:  " << this->codigo << endl;
    s << "Envasado: ";
    if (envasado) {
        s << "(Verdadero)" << endl;
    }
    else {
        s << "(Falso)" << endl;
    }
    s << "Descripcion:  " << this->descripcion<< endl;
    s << "Precio costo:  " << this->precioCosto << endl;
    s << "Existencia:  " << this->existencia << endl;
    s << "Limite:  " << this->limite << endl;
    return s.str();
}

int Conserva::getFechaIng()
{
    return ptrFechaIng->getFecha();
}

Producto* Conserva::clonar() const
{
    return new Conserva(*this);
}

string Conserva::getnombreComecial()
{
    return nombreComercial;
}

string Conserva::getCodigo()const
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

void Conserva::setFechaIng(Fecha* f)
{
    this->ptrFechaIng = new Fecha(*f);
}

double Conserva::ganancia()
{
    Categoria c;
    return precioCosto * c.porceganancia(categoria);
}

void Conserva::guardarProducto(ofstream& file)
{
    string envasadoF;
    if (this->envasado)envasadoF = "(Verdadero)";
    else envasadoF = "(Falso)";

    file<<"Conserva"<<'\t' << envasadoF << '\t' << codigo << '\t' << nombreComercial << '\t' << descripcion << '\t'
        << precioCosto << '\t' << categoria << '\t' << existencia << '\t' << limite << '\n';
    if (ptrFechaIng != nullptr) {
        ptrFechaIng->guardarFecha(file);
    }
}

Conserva* Conserva::leerConserva(ifstream& file){
    
    string envasadoF,codigoF,nombreComercialF,descripcionF,precioCostoF,categoriaF, existenciaF, limiteF;
    bool env;
    double precioCost;
    int exist, limit;
    Fecha* fec;


    getline(file, envasadoF, '\t');
    getline(file, codigoF, '\t');
    getline(file, nombreComercialF, '\t');
    getline(file, descripcionF, '\t');
    getline(file, precioCostoF, '\t');
    getline(file, categoriaF, '\t');
    getline(file, existenciaF, '\t');
    getline(file, limiteF, '\n');

    precioCost = stod(precioCostoF);
    exist = stoi(existenciaF);
    limit = stoi(limiteF);

    if (envasadoF == "(Verdadero)") {
        env = true;
    }
    else {
        env = false;
    }

    fec = Fecha::leerFecha(file);

    return new Conserva(fec,env,codigoF,nombreComercialF,descripcionF,precioCost,categoriaF,exist,limit);
}

void Conserva::leerDatos(istream& s)
{
    string env;
    cout << "Ingreso de datos Producto Conserva: " << endl;
    Fecha* f = new Fecha();
    s >> *f;
    setFechaIng(f);
    cout << "Codigo: " << endl;
    s >> codigo;
    cout << "Nombre: " << endl;
    s >> nombreComercial;
    cout << "Descripcion: " << endl;
    s >> descripcion;
    cout << "Precio: " << endl;
    s >> precioCosto;
    cout << "Existencia de producto: " << endl;
    s >> existencia;
    cout << "Limite de compra: " << endl;
    s >> limite;
    cout << "Envasado (N)No  (S):Si " << endl;
    cin >> env;
    if (env== "S" || env == "s") {
        envasado = true;
    }
    else {
        envasado = false;
    }
    this->setCategoria("1");
    if(s.fail()) {
        s.clear();
        s.ignore(1);
        throw string("Se ha digitado un caracter invalido");
    }

}

ostream& operator<<(ostream& s, Conserva& c)
{
    s << c.toString();
    return s;
}

