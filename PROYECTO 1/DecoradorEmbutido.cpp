#include "DecoradorEmbutido.h"

DecoradorEmbutido::DecoradorEmbutido(BaseCarrito* carro, Empaque* emp, Perecedero* ptrPer, string marca, string nombreAni, string partAni, string codi, string nombre, string desc, double pes, double prec, bool nac)
{
	this->ptrCarrito = carro;
	this->ptrEmpaque = emp;
	this->ptrPer = ptrPer;
	this->marca = marca;
	this->nombreAnimal = nombreAni;
	this->parteDelAnimal = partAni;
	this->codigo = codi;
	this->nombreComercial = nombre;
	this->descripcion = desc;
	this->nacional = nac;
	this->peso = pes;
	this->precioCosto = prec;
}



DecoradorEmbutido::DecoradorEmbutido(const DecoradorEmbutido& copia)
{
	this->ptrCarrito = copia.ptrCarrito;
	this->ptrEmpaque = new Empaque(*copia.ptrEmpaque);
	this->ptrPer = new Perecedero(*copia.ptrPer);
	this->marca = copia.marca;
	this->nombreAnimal = copia.nombreAnimal;
	this->parteDelAnimal = copia.parteDelAnimal;
	this->codigo = copia.codigo;
	this->nombreComercial = copia.nombreComercial;
	this->descripcion = copia.descripcion;
	this->nacional = copia.nacional;
	this->peso = copia.peso;
	this->precioCosto = copia.precioCosto;
}
DecoradorEmbutido::~DecoradorEmbutido()
{
	if (ptrEmpaque) {
		delete ptrEmpaque;
	}
	if (ptrPer) {
		delete ptrPer;
	}
}

BaseCarrito* DecoradorEmbutido::getSiguiente()
{
	return ptrCarrito;
}

void DecoradorEmbutido::setSiguiente(BaseCarrito* carro)
{
	this->ptrCarrito = carro;
}

string DecoradorEmbutido::imprimir(){
	stringstream s;
	s << "Embutido: " << " ";
	s << "marca: " << this->marca<< " ";
	s << "nombre: " << this->nombreComercial << " ";
	s << "codigo: " << this->codigo << " ";
	s << "nombre animal: " << this->nombreAnimal << " ";
	s << "parte animal: " << this->parteDelAnimal << " ";
	s << "descripcion: " << this->descripcion << " ";
	s << "empresa: " << this->nombreComercial << " ";
	s << "Procedencia: ";
	if (this->nacional) {
		s << "nacional " << " ";
	}
	else {
		s << "internacional " << " ";
	}
	if (this->ptrEmpaque->getTripa()) {
		s << "contiene tripa " << " ";
	}
	else {
		s << "no contiene tripa " << " ";
	}
	s << "fecha vecimiento: " << this->ptrPer->toString() << " ";
	s << "precio: " << this->precioCosto;
	s << endl;
	s<< ptrCarrito->imprimir();
	return s.str();
}

double DecoradorEmbutido::getTotal()
{
	return this->precioCosto + ptrCarrito->getTotal();
}



ostream& operator<<(ostream& o, DecoradorEmbutido& p)
{
	o << p.imprimir() << endl;
	return o;
}

