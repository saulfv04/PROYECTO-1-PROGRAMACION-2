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
	s << "----------------EMBUTIDO----------------" << endl;
	s << endl;
	s << "marca: " << this->marca<< endl;
	s << "nombre: " << this->nombreComercial << endl;
	s << "codigo: " << this->codigo << endl;
	s << "nombre animal: " << this->nombreAnimal << endl;
	s << "parte animal: " << this->parteDelAnimal << endl;
	s << "descripcion: " << this->descripcion << endl;
	s << "empresa: " << this->nombreComercial << endl;
	s << "Procedencia: ";
	if (this->nacional) {
		s << "nacional " << endl;
	}
	else {
		s << "internacional " << endl;
	}
	if (this->ptrEmpaque->getTripa()) {
		s << "contiene tripa " << endl;
	}
	else {
		s << "no contiene tripa " << endl;
	}
	s << "fecha vecimiento: " << this->ptrPer->toString() << endl;
	s << "precio costo: " << this->precioCosto << endl;
	s << endl;
	s<< ptrCarrito->imprimir();
	return s.str();
}

ostream& operator<<(ostream& o, DecoradorEmbutido& p)
{
	o << p.imprimir() << endl;
	return o;
}

