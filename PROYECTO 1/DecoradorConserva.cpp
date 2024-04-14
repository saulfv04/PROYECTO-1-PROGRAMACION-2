#include "DecoradorConserva.h"

DecoradorConserva::DecoradorConserva(ComponenteAbstracto* ptrCarro, string n, string c, string d, double p, bool e)
{
    this->ptrCarrito = ptrCarro;
    this->nombre = n;
    this->codigo = c;
    this->descricion = d;
    this->precio = p;
    this->envasado = e;
}

DecoradorConserva::DecoradorConserva(const DecoradorConserva& copia)
{
    this->ptrCarrito = copia.ptrCarrito;
    this->nombre = copia.nombre;
    this->codigo = copia.codigo;
    this->descricion = copia.descricion;
    this->precio = copia.precio;
    this->envasado = copia.envasado;
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
    s << "Conserva: " << " ";
    s <<"nombre: " << this->nombre << " ";
    s << "codigo: " << this->codigo << " ";
    s << "descripcion: " << this->descricion << " ";
    s << "envasado: ";
    if (this->envasado) {
        s << "con envasado" << " ";
    }
    else {
        s << "sin envasar" << " ";
    }
    s << "precio: " << this->precio;
    s << endl;
    s<< *ptrCarrito;
    return s.str();
}

double DecoradorConserva::getTotal()
{
    return this->precio + ptrCarrito->getTotal();
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

