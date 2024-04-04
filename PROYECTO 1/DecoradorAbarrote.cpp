#include "DecoradorAbarrote.h"

DecoradorAbarrote::DecoradorAbarrote(BaseCarrito* carro, Abarrote* prtAba)
{
    this->ptrCarrito = carro;
    this->ptrAbarrote = prtAba;
}

DecoradorAbarrote::DecoradorAbarrote(const DecoradorAbarrote& copia)
{
    this->ptrCarrito = copia.ptrCarrito;
    this->ptrAbarrote = copia.ptrAbarrote;
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
    cout<<"----------------ABARROTE----------------" << endl;
    cout << endl;
    cout << ptrAbarrote->toString();
    cout << endl;
    ptrCarrito->imprimir();
}

//ostream& operator<<(ostream& o, DecoradorAbarrote& ab)
//{
//    o << "Abarrote:" << ab.ptrAbarrote << '\n' << ab.ptrCarrito << endl;
//    return o;
//}
