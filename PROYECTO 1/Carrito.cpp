#include "Carrito.h"

Carrito::Carrito()
{
}

Carrito::~Carrito()
{

}

BaseCarrito* Carrito::getSiguiente()
{
    return nullptr;
}

void Carrito::setSiguiente(BaseCarrito*)
{
}

string Carrito::imprimir()
{
    stringstream s;
    s << endl << "------------CARRITO COMPRAS------------" << endl;
    return s.str();
}

double Carrito::getTotal()
{
    return 0.0;
}

//int Carrito::getCantidad()
//{
//    return 0;
//}

ostream& operator<<(ostream& o, Carrito& ca)
{
    o << ca.imprimir() << endl;
    return o;
}
