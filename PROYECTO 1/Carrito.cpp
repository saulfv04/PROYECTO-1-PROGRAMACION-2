#include "Carrito.h"

Carrito::Carrito()
{
}

Carrito::~Carrito()
{
    cout << "Borrando Carrito" << endl;

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
    stringstream s;
    s << endl << "|  -------------------------CARRITO COMPRAS------------------------------- |" << endl;
    return s.str();
}

double Carrito::getTotal()
{
    return 0.0;
}

ComponenteAbstracto* Carrito::clonar() const
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
