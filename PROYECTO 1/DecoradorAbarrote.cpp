#include "DecoradorAbarrote.h"

DecoradorAbarrote::DecoradorAbarrote(ComponenteAbstracto* carro, Perecedero* ptrPere, string eN, string c, string nC, string d, bool n, double p, double pre)
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
    categoria = "2";
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
    this->categoria = copia.categoria;
}

DecoradorAbarrote::~DecoradorAbarrote(){
    if (ptrPer) {
		delete ptrPer;
	}
}

ComponenteAbstracto* DecoradorAbarrote::getSiguiente()
{
    return ptrCarrito;
}

void DecoradorAbarrote::setSiguiente(ComponenteAbstracto* ptrCarro)
{
    ptrCarrito = ptrCarro;
}

string DecoradorAbarrote::toString() const{
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
    s << *ptrCarrito;
    return s.str();
}

double DecoradorAbarrote::getTotal()
{
    return this->precioCosto + ptrCarrito->getTotal();
}

double DecoradorAbarrote::getGanancia()
{
    Categoria c;
    return this->precioCosto * (c.porceganancia(categoria)) + ptrCarrito->getTotal();
}

ComponenteAbstracto* DecoradorAbarrote::clonar() const
{
    return new DecoradorAbarrote(*this);
}

ostream& operator<<(ostream& o, DecoradorAbarrote& ab)
{
    o << ab.toString() << endl;
    return o;
}
