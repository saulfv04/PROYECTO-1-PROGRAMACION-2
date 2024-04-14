#include "Minisuper.h"

Minisuper::Minisuper(){
	this->listPersona = new Lista<Persona>();
	this->listProducto = new Lista<Producto>();
	this->listVenta = new Lista<Venta>();
	cout << "Creando minisuper" << endl;
}

Minisuper::~Minisuper(){
	if (this->listPersona) {
		delete listPersona;
	}
	if (this->listProducto) {
		delete listProducto;
	}
	if (this->listVenta) {
		delete listVenta;
	}
	cout << "Borrando Minisuper" <<endl;
}

void Minisuper::agregarPersona(Persona* p){
	this->listPersona->agregarFinal(p);
}

void Minisuper::agregarProducto(Producto* prd){
	this->listProducto->agregarFinal(prd);
}

void Minisuper::agregarVenta(Venta* vt){
	this->listVenta->agregarFinal(vt);
}

Nodo<Venta>* Minisuper::getFactura(string c)
{
	return listVenta->buscar(c);
}

Nodo<Producto>* Minisuper::buscarProducto(string c){

	return this->listProducto->buscar(c);
}

string Minisuper::toStringListProd()
{
	stringstream s;
	s << listProducto->toString();
	return s.str();
}


