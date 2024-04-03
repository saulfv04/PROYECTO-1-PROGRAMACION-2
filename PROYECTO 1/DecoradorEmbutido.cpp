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
