#include "DecoradorAbarrote.h"

DecoradorAbarrote::DecoradorAbarrote(BaseCarrito* carro, Abarrote* prtAba)
{
    this->ptrCarrito = carro;
    this->ptrAbarrote = prtAba;
}

DecoradorAbarrote::~DecoradorAbarrote(){}

BaseCarrito* DecoradorAbarrote::getSiguiente()
{
    return ptrCarrito;
}

void DecoradorAbarrote::setSiguiente(BaseCarrito* ptrCarro)
{
    ptrCarrito = ptrCarro;
}

void DecoradorAbarrote::imprimir()
{
    ptrAbarrote->toString();
    ptrCarrito->imprimir();
}
