#pragma once
#include "ProductoDecorador.h"
#include "Conserva.h"
class DecoradorConserva :public ProductoDecorador{

private:
	Conserva* ptrConserva;
public:
	DecoradorConserva(BaseCarrito*, Conserva*);
	DecoradorConserva(const DecoradorConserva&);
	virtual ~DecoradorConserva();
	virtual BaseCarrito* getSiguiente();
	virtual void setSiguiente(BaseCarrito*);
	virtual void imprimir();
};

