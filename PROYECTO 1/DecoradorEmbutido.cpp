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

void DecoradorEmbutido::imprimir()
{
	cout << "----------------EMBUTIDO----------------" << endl;
	cout << endl;
	cout << "marca: " << this->marca<< endl;
	cout << "nombre: " << this->nombreComercial << endl;
	cout << "codigo: " << this->codigo << endl;
	cout << "nombre animal: " << this->nombreAnimal << endl;
	cout << "parte animal: " << this->parteDelAnimal << endl;
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
//
//ostream& operator<<(ostream& o, DecoradorEmbutido& p)
//{
//	o << "Embutido: " << p.ptrEmbutido<< '\n' << p.ptrCarrito << endl;
//	return o;
//}
