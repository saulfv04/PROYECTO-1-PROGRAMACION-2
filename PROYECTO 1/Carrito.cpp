#include "Carrito.h"

Carrito::Carrito()
{
}

Carrito::~Carrito()
{

}

Carrito::Carrito(const Carrito& p) {
 
}

BaseCarrito* Carrito::getSiguiente()
{
    return nullptr;
}

void Carrito::setSiguiente(BaseCarrito*)
{
}

string Carrito::toString() const
{
    stringstream s;
    s << endl << "------------CARRITO COMPRAS------------" << endl;
    return s.str();
}

double Carrito::getTotal()
{
    return 0.0;
}

BaseCarrito* Carrito::clonar() const
{
    return NULL;
}

//int Carrito::getCantidad()
//{
//    return 0;
//}

ostream& operator<<(ostream& o, Carrito& ca)
{
    o << ca.toString() << endl;
    return o;
}
