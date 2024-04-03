#include "DecoradorConserva.h"

DecoradorConserva::DecoradorConserva(BaseCarrito* ptrCarro, Conserva* ptrConser)
{
    this->ptrCarrito = ptrCarro;
    this->ptrConserva = ptrConser;
}

DecoradorConserva::~DecoradorConserva(){}

BaseCarrito* DecoradorConserva::getSiguiente()
{
    return ptrCarrito;
}

void DecoradorConserva::setSiguiente(BaseCarrito* conserva)
{
    ptrCarrito = conserva;
}

void DecoradorConserva::imprimir()
{
    ptrConserva->toString();
    ptrCarrito->imprimir();
}
