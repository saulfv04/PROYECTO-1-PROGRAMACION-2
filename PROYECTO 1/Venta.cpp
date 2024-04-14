#include "Venta.h"

Venta::Venta(ProductoDecorador* carr, string per, Fecha* f, string cod) :carrito(carr), nombreCliente(per), fVenta(f), codigo(cod){}



Venta::Venta(const Venta& ven) {

    this->carrito = static_cast<ProductoDecorador*>(ven.carrito->clonar());
    this->nombreCliente = ven.nombreCliente;
	codigo = ven.codigo;
    fVenta = new Fecha(*ven.fVenta);
}

Venta::~Venta()
{
    if (carrito) {
        delete carrito;
    }
    cout << "Borrando Venta" << endl;

}

string Venta::getCodigo()const{
    return this->codigo;
}


ComponenteAbstracto* Venta::getCarrito(){
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



string Venta::getPersona()
{
    return this->nombreCliente;
}



void Venta::setFecha(Fecha* f)
{
    fVenta = f;
}

string Venta::toString()const{
    stringstream s;
    s<<"----------------------------------------" <<"|"<<  endl;
    s<<"|" << "\t" << "\t" << "FACTURA " << "NUMERO: " << this->codigo << "|" << endl;
    s << "|" << "\t" << "\t" << "CLIENTE: " << this->nombreCliente << "|" << endl;
    s << "|" << "\t" << "\t" << "FECHA: " << *this->fVenta << "|" << endl;
    s << "|" << "DETALLE DE COMPRA" << "|" << endl;
    s << "|" << *this->carrito;
    s << "|" << "  TOTAL BRUTO: $" << totalbruto()<< "  "<< "   IMPORTE %13: $" << totalIVa() << "      TOTAL NETO: $" << totalneto() << " " << endl;
    s << "|  ----------------------------------------------------------------------- "<<"|" << endl;
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
