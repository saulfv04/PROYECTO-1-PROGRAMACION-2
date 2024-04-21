#include "Carrito.h"

Carrito::Carrito()
{
}

Carrito::~Carrito()
{
}

Carrito::Carrito(const Carrito& p) {
 
}

ComponenteAbstracto* Carrito::getSiguiente()
{
    return nullptr;
}

void Carrito::setSiguiente(ComponenteAbstracto*)
{
}

string Carrito::toString() const
{
    return "";
}

double Carrito::getTotal()
{
    return 0.0;
}

double Carrito::getCantidad()
{
    return 0.0;
}

ComponenteAbstracto* Carrito::clonar() const
{
    return NULL;
}

void Carrito::guardarComponenteAbstracto(ofstream&){}

Carrito* Carrito::leerCarrito(ifstream&){
    return new Carrito();
}



ostream& operator<<(ostream& o, Carrito& ca)
{
    o << ca.toString() << endl;
    return o;
}
