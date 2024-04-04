#include "DecoradorEmbutido.h"

DecoradorEmbutido::DecoradorEmbutido(BaseCarrito* carro, Embutido* ptrEm)
{
	this->ptrCarrito = carro;
	this->ptrEmbutido = ptrEm;
}

DecoradorEmbutido::DecoradorEmbutido(const DecoradorEmbutido& copia)
{
	this->ptrCarrito = copia.ptrCarrito;
	this->ptrEmbutido = copia.ptrEmbutido;
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
	cout << ptrEmbutido->toString();
	cout << endl;
	ptrCarrito->imprimir();
}
//
//ostream& operator<<(ostream& o, DecoradorEmbutido& p)
//{
//	o << "Embutido: " << p.ptrEmbutido<< '\n' << p.ptrCarrito << endl;
//	return o;
//}
