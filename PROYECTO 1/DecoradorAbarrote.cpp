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

DecoradorAbarrote::~DecoradorAbarrote(){
    if (ptrPer) {
		delete ptrPer;
	}
}

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
    s << "Cantidad : 1" << endl;
    s << "Abarrote: ";
    s <<"nombre: " << this->nombreComercial << " ";
    s << "codigo: " << this->codigo << " ";
    s << "descripcion: " << this->descripcion << " ";
    s << "empresa: " << this->nombreComercial << " ";
    s << "Procedencia: ";
    if (this->nacional) {
        s << "nacional " << " ";
    }
    else {
        s << "internacional " << " ";
    }
    s << "fecha vecimiento: " << this->ptrPer->toString() << " ";
    s << "precio: " << this->precioCosto;
    s << endl;
    s << ptrCarrito->imprimir();
    return s.str();
}

double DecoradorAbarrote::getTotal()
{
    return this->precioCosto + ptrCarrito->getTotal();
}

ostream& operator<<(ostream& o, DecoradorAbarrote& ab)
{
    o << ab.imprimir() << endl;
    return o;
}
