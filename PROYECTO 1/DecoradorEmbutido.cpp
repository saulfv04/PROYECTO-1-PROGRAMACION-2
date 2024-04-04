#include "DecoradorEmbutido.h"

DecoradorEmbutido::DecoradorEmbutido(BaseCarrito* carro, Embutido* ptrEm)
{
	this->ptrCarrito = carro;
	this->ptrEmbutido = ptrEm;
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
	ptrEmbutido->toString();
	ptrCarrito->imprimir();
}
//
//ostream& operator<<(ostream& o, DecoradorEmbutido& p)
//{
//	o << "Embutido: " << p.ptrEmbutido<< '\n' << p.ptrCarrito << endl;
//	return o;
//}
