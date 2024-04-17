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
	return listVenta->buscarElemento(c);
}

Nodo<Persona>* Minisuper::getCliente(string c)
{
	return this->listPersona->buscarElemento(c);
}

Nodo<Producto>* Minisuper::getProducto(string c)
{
	return this->listProducto->buscarElemento(c);
}

Nodo<Producto>* Minisuper::buscarProducto(string c){

	return this->listProducto->buscarElemento(c);
}

Producto* Minisuper::eliminarProductoEspecifico(string c)
{
	return this->listProducto->eliminarEspecifico(c);
}

Nodo<Producto>* Minisuper::getProducto()
{
	return this->listProducto->getPrimero();
}

Nodo<Venta>* Minisuper::getVenta()
{
	return this->listVenta->getPrimero();
}

Nodo<Persona>* Minisuper::getCliente()
{
	return this->listPersona->getPrimero();
}

int Minisuper::getSizeVenta()
{
	return this->listVenta->size();
}

int Minisuper::getSizePersona()
{
	return this->listPersona->size();
}

string Minisuper::toStringListProd()
{
	stringstream s;
	s << listProducto->toString();
	return s.str();
}

string Minisuper::toStringListClientes()
{
	stringstream s;
	s << listPersona->toString();
	return s.str();
}


