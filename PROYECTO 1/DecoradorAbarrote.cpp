#include "DecoradorAbarrote.h"

DecoradorAbarrote::DecoradorAbarrote(BaseCarrito* carro, Perecedero* ptrPere, string eN, string c, string nC, string d, bool n, double p, double pre)
{
    this->ptrCarrito = carro;
    this->ptrPer = ptrPere;
    this->empresaNombre = eN;
    this->codigo = c;
    this->nombreComercial = nC;
    this->descripcion = d;
    this->nacional = n;
    this->peso = p;
    this->precioCosto = pre;
}
DecoradorAbarrote::DecoradorAbarrote(const DecoradorAbarrote& copia)
{
    this->ptrCarrito = copia.ptrCarrito;
    this->ptrPer = new Perecedero(*copia.ptrPer);
    this->empresaNombre = copia.empresaNombre;
    this->codigo = copia.codigo;
    this->nombreComercial = copia.nombreComercial;
    this->descripcion = copia.descripcion;
    this->nacional = copia.nacional;
    this->peso = copia.peso;
    this->precioCosto = copia.precioCosto;
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

string DecoradorAbarrote::imprimir(){
    stringstream s;
    s <<"----------------ABARROTE----------------" << endl;
    s << endl;
    s <<"nombre: " << this->nombreComercial << endl;
    s << "codigo: " << this->codigo << endl;
    s << "descripcion: " << this->descripcion << endl;
    s << "empresa: " << this->nombreComercial << endl;
    s << "Procedencia: ";
    if (this->nacional) {
        s << "nacional " << endl;
    }
    else {
        s << "internacional " << endl;
    }
    s << "fecha vecimiento: " << this->ptrPer->toString() << endl;
    s << "precio costo: " << this->precioCosto << endl;
    s << endl;
    s<<ptrCarrito->imprimir();
    return s.str();
}

ostream& operator<<(ostream& o, DecoradorAbarrote& ab)
{
    o << ab.imprimir() << endl;
    return o;
}
