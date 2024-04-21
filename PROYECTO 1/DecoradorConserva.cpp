#include "DecoradorConserva.h"


DecoradorConserva::DecoradorConserva(ComponenteAbstracto* ptrCarro, string n, string c, string d, double p, bool e,int can)
{
    this->ptrCarrito = ptrCarro;
    this->nombre = n;
    this->codigo = c;
    this->descricion = d;
    this->precio = p;
    this->envasado = e;
    this->categoria = "1";
    this->cantidad = can;
}

DecoradorConserva::DecoradorConserva(const DecoradorConserva& copia)
{
    this->ptrCarrito = copia.ptrCarrito;
    this->nombre = copia.nombre;
    this->codigo = copia.codigo;
    this->descricion = copia.descricion;
    this->precio = copia.precio;
    this->envasado = copia.envasado;
    this->categoria = copia.categoria;
    this->cantidad = copia.cantidad;
}

DecoradorConserva::~DecoradorConserva(){

}

ComponenteAbstracto* DecoradorConserva::getSiguiente()
{
    return ptrCarrito;
}

void DecoradorConserva::setSiguiente(ComponenteAbstracto* conserva)
{
    ptrCarrito = conserva;
}

string DecoradorConserva::toString() const{
    stringstream s;
    s<<"\t    "<<this->cantidad<<"\t\t   "<<this->nombre  << "\t\t $"<<this->precio << "\t\t   $" << this->precio * this->cantidad << "\n";
    s<< *ptrCarrito;
    return s.str();
}

double DecoradorConserva::getTotal()
{
    return (this->precio * cantidad) + ptrCarrito->getTotal();
}

double DecoradorConserva::getGanancia()
{
    Categoria c;
    return this->precio * (c.porceganancia(categoria)) + ptrCarrito->getTotal();
}

double DecoradorConserva::getCantidad()
{
    return this->cantidad;
}

ComponenteAbstracto* DecoradorConserva::clonar() const
{
    return new DecoradorConserva(*this);
}

void DecoradorConserva::guardarComponenteAbstracto(ofstream& file)
{
    string envasadoF;
    if (this->envasado)envasadoF = "Envasado";
    else envasadoF = "No envasado";

    file << "Conserva" 
        << '\t' << codigo 
        << '\t' << nombre 
        << '\t' << descricion 
        << '\t' << precio 
        << '\t' << envasadoF 
        << '\t' << cantidad << '\n';
    if (ptrCarrito != nullptr) {
        ptrCarrito->guardarComponenteAbstracto(file);
    }
}

DecoradorConserva* DecoradorConserva::leerDecoConserva(ifstream& file)
{
    string tipo, cantidadF, envasadoF, codigoF, nombreComercialF, descripcionF, precioCostoF;
    bool env;
    double precioCost;
    int cant;
    ComponenteAbstracto* car = NULL;

    getline(file, tipo, '\t');
    getline(file, codigoF, '\t');
    getline(file, nombreComercialF, '\t');
    getline(file, descripcionF, '\t');
    getline(file, precioCostoF, '\t');
    getline(file, envasadoF, '\t');
    getline(file, cantidadF, '\n');


    precioCost = stod(precioCostoF);
    cant = stoi(cantidadF);

    if (envasadoF == "Envasado") {
        env = true;
    }
    else {
        env = false;
    }

    if (tipo == "Abarrote") {
        car = DecoradorAbarrote::leerDecoAbarrote(file);
    }
    if (tipo == "Embutido") {
        car = DecoradorEmbutido::leerDecoEmbutido(file);
    }
    if (tipo == "Conserva") {
        car = leerDecoConserva(file);
    }
    if (tipo == "Carrito") {
        car = Carrito::leerCarrito(file);
    }
    return new DecoradorConserva(car,nombreComercialF,codigoF,descripcionF, precioCost,env,cant);
}

ostream& operator<<(ostream& o , DecoradorConserva& con)
{
    o <<con.toString()<< endl;
    return o;
}

