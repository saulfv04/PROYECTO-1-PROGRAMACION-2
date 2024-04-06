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

void DecoradorAbarrote::imprimir()
{
    cout<<"----------------ABARROTE----------------" << endl;
    cout << endl;
    cout <<"nombre: " << this->nombreComercial << endl;
    cout << "codigo: " << this->codigo << endl;
    cout << "descripcion: " << this->descripcion << endl;
    cout << "empresa: " << this->nombreComercial << endl;
    cout << "Procedencia: ";
    if (this->nacional) {
        cout << "nacional " << endl;
    }
    else {
        cout << "internacional " << endl;
    }
    cout << "fecha vecimiento: " << this->ptrPer->toString() << endl;
    cout << "precio costo: " << this->precioCosto << endl;
    cout << endl;
    ptrCarrito->imprimir();
}

//ostream& operator<<(ostream& o, DecoradorAbarrote& ab)
//{
//    o << "Abarrote:" << ab.ptrAbarrote << '\n' << ab.ptrCarrito << endl;
//    return o;
//}
