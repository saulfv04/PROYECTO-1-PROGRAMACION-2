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
