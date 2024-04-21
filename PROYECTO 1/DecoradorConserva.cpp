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

ostream& operator<<(ostream& o , DecoradorConserva& con)
{
    o <<con.toString()<< endl;
    return o;
}

