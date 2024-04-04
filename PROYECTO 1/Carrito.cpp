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

void Carrito::imprimir()
{
    cout << endl << "------------CARRITO COMPRAS------------" << endl;
}

//ostream& operator<<(ostream& o, Carrito& ca)
//{
//    o << "Carrito Compras" << endl;
//    return o;
//}
