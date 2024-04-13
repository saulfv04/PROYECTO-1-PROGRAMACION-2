#include "Venta.h"

Venta::Venta(ProductoDecorador* carr, Persona* per,Fecha* f, string cod):carrito(carr),persona(per),fVenta(f),codigo(cod){}

Venta::Venta(const Venta& ven) {

    this->carrito = static_cast<ProductoDecorador*>(ven.carrito->clonar());
	persona = new Persona(*ven.persona);
	codigo = ven.codigo;
    fVenta = new Fecha(*ven.fVenta);
}

Venta::~Venta()
{
    if (carrito) {
        delete carrito;
    }
    if (persona) {
		delete persona;
	}
}

string Venta::getCodigo()
{
    return this->codigo;
}

void Venta::setCodigo(string c)
{
    	codigo = c;
}

BaseCarrito* Venta::getCarrito()
{
    return this->carrito;
}

Fecha* Venta::getFecha()
{
    return this->fVenta;
}

void Venta::setCarrito(ProductoDecorador* c)
{
	carrito = c;
}

Persona* Venta::getPersona()
{
    return this->persona;
}

void Venta::setPersona(Persona* p)
{
    	persona = p;
}

void Venta::setFecha(Fecha* f)
{
    fVenta = f;
}

string Venta::toString()const{
    stringstream s;
    s<<"----------------------------------------" <<"|"<<  endl;
    s<<"|" << "\t" << "\t" << "FACTURA " << "NUMERO: " << codigo << "|" << endl;
    s << "|" << "\t" << "\t" << "CLIENTE: " << *persona << "|" << endl;
    s << "|" << "\t" << "\t" << "FECHA: " << *fVenta << "|" << endl;
    s << "|" << "DETALLE DE COMPRA" << "|" << endl;
    s << "|" << carrito->toString();
    s << "|" << "TOTAL BRUTO: " << totalbruto()<< "%13"<< "IMPORTE: " << totalIVa() << " TOTAL NETO: " << totalneto() << "|" << endl;
    s << "---------------------------------------- "<<"|" << endl;
    return s.str();
}

double Venta::totalbruto()const{
    return carrito->getTotal();
}

double Venta::totalIVa()const
{
    return totalbruto() * 0.013;
}

double Venta::totalneto()const
{
    return totalbruto() + totalIVa();
}

Venta* Venta::clonar() const
{
    return new Venta(*this);
}

ostream& operator<<(ostream& o , Venta& v)
{
	o << v.toString() << endl;
	return o;
}
