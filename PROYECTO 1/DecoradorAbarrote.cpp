#include "DecoradorAbarrote.h"

DecoradorAbarrote::DecoradorAbarrote(ComponenteAbstracto* carro, Perecedero* ptrPere, string eN, string c, string nC, string d, bool n, double p, double pre, int can)
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
    this->categoria = "2";
    this->cantidad = can;
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
    this->cantidad = copia.cantidad;
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
    s << "\t    " << this->cantidad << "\t\t   " << this->nombreComercial<< "\t $" << this->precioCosto << "\t           $" << this->precioCosto * this->cantidad << "\n";
    s << *ptrCarrito;
    return s.str();
}

double DecoradorAbarrote::getTotal()
{
    return (this->precioCosto * cantidad) + ptrCarrito->getTotal();
}

double DecoradorAbarrote::getGanancia()
{
    Categoria c;
    return (this->precioCosto*cantidad) * (c.porceganancia(categoria)/100) + ptrCarrito->getTotal();
}

double DecoradorAbarrote::getCantidad()
{
    return this->cantidad;
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
