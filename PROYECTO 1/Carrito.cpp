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
    cout << "------------CARRITO COMPRAS------------" << endl;
}
