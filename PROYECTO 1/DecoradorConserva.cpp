#include "DecoradorConserva.h"

DecoradorConserva::DecoradorConserva(BaseCarrito* ptrCarro, Conserva* ptrConser)
{
    this->ptrCarrito = ptrCarro;
    this->ptrConserva = ptrConser;
}

DecoradorConserva::DecoradorConserva(const DecoradorConserva& copia)
{
    this->ptrCarrito = copia.ptrCarrito;
    this->ptrConserva = copia.ptrConserva;
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
    cout << "----------------CONSERVA----------------" << endl;
    cout << endl;
    cout << ptrConserva->toString();
    cout << endl;
    ptrCarrito->imprimir();
}
//
//ostream& operator<<(ostream& o , DecoradorConserva& con)
//{
//    o << "Conserva: " << con.ptrConserva << '\n' << con.ptrCarrito << endl;
//    return o;
//}
