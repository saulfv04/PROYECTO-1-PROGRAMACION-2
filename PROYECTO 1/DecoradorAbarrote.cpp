#include "DecoradorAbarrote.h"

DecoradorAbarrote::DecoradorAbarrote(ComponenteAbstracto* carro, Perecedero* ptrPere, string eN, string c, string nC, string d, bool n, double p, double pre, int can)
{
    this->ptrCarrito = carro;
    this->ptrPer = ptrPere;
    this->empresaNombre = eN;
    this->codigo = c;
    this->nombreComercial = nC;
    this->descripcion = d;
    this->nacional = n;
    this->peso = p;
    this->precioCosto = pre;
    this->categoria = "2";
    this->cantidad = can;
}
DecoradorAbarrote::DecoradorAbarrote(const DecoradorAbarrote& copia)
{
    this->ptrCarrito = copia.ptrCarrito;
    this->ptrPer = new Perecedero(*copia.ptrPer);
    this->empresaNombre = copia.empresaNombre;
    this->codigo = copia.codigo;
    this->nombreComercial = copia.nombreComercial;
    this->descripcion = copia.descripcion;
    this->nacional = copia.nacional;
    this->peso = copia.peso;
    this->precioCosto = copia.precioCosto;
    this->categoria = copia.categoria;
    this->cantidad = copia.cantidad;
}

DecoradorAbarrote::~DecoradorAbarrote(){
    if (ptrPer) {
		delete ptrPer;
	}
}

ComponenteAbstracto* DecoradorAbarrote::getSiguiente()
{
    return ptrCarrito;
}

void DecoradorAbarrote::setSiguiente(ComponenteAbstracto* ptrCarro)
{
    ptrCarrito = ptrCarro;
}

string DecoradorAbarrote::toString() const{
    stringstream s;
    s << "\t    " << this->cantidad << "\t\t   " << this->nombreComercial<< "\t $" << this->precioCosto << "\t           $" << this->precioCosto * this->cantidad << "\n";
    s << *ptrCarrito;
    return s.str();
}

double DecoradorAbarrote::getTotal()
{
    return (this->precioCosto * cantidad) + ptrCarrito->getTotal();
}

double DecoradorAbarrote::getGanancia()
{
    Categoria c;
    return (this->precioCosto*cantidad) * (c.porceganancia(categoria)/100) + ptrCarrito->getTotal();
}

double DecoradorAbarrote::getCantidad()
{
    return this->cantidad;
}

ComponenteAbstracto* DecoradorAbarrote::clonar() const
{
    return new DecoradorAbarrote(*this);
}
void DecoradorAbarrote::guardarComponenteAbstracto(ofstream& file)
{
    string nacio;
    if (this->nacional){
        nacio = "Nacional";
    }
    else {
        nacio = "Internacional";
    }
    file << "Abarrote" 
        << '\t' << codigo 
        << '\t' << nombreComercial 
        << '\t' << descripcion 
        << '\t' << precioCosto 
        << '\t' <<peso 
        << '\t' <<empresaNombre
        << '\t' << nacio
        << '\t' << cantidad << '\n';
    if (ptrCarrito != nullptr) {
        ptrCarrito->guardarComponenteAbstracto(file);
    }
    if (this->ptrPer!=nullptr) {
        this->ptrPer->guardarPerecedero(file);
    }
}

DecoradorAbarrote* DecoradorAbarrote::leerDecoAbarrote(ifstream& file)
{
    string tipo, cantidadF, codigoF, nombreComercialF, descripcionF, precioCostoF,peso,nacion,empresaNom;
    bool env;
    double precioCost,pesoT;
    int cant;
    ComponenteAbstracto* car = NULL;
    Perecedero* pere = NULL;

    getline(file, tipo, '\t');
    getline(file, codigoF, '\t');
    getline(file, nombreComercialF, '\t');
    getline(file, descripcionF, '\t');
    getline(file, precioCostoF, '\t');
    getline(file, peso, '\t');
    getline(file, empresaNom, '\t');
    getline(file, nacion, '\t');
    getline(file, cantidadF, '\n');


    precioCost = stod(precioCostoF);
    pesoT = stod(peso);
    cant = stoi(cantidadF);

    if (nacion == "Envasado") {
        env = true;
    }
    else {
        env = false;
    }
    pere = Perecedero::leerPerecedero(file);

    if (tipo == "Abarrote") {
        car = leerDecoAbarrote(file);
    }
    if (tipo == "Embutido") {
        car = DecoradorEmbutido::leerDecoEmbutido(file);
    }
    if (tipo == "Conserva") {
        car = DecoradorConserva::leerDecoConserva(file);
    }
    if (tipo == "Carrito") {
        car = Carrito::leerCarrito(file);
    }
    return new DecoradorAbarrote(car,pere,empresaNom, codigoF,nombreComercialF,descripcionF,env,pesoT,precioCost,cant);
}
ostream& operator<<(ostream& o, DecoradorAbarrote& ab)
{
    o << ab.toString() << endl;
    return o;
}
