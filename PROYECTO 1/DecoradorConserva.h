#pragma once
#include "ProductoDecorador.h"
#include "Conserva.h"
class DecoradorConserva :public ProductoDecorador{

private:
	Conserva* ptrConserva;
public:
	DecoradorConserva(BaseCarrito*, Conserva*);
	virtual ~DecoradorConserva();
	virtual BaseCarrito* getSiguiente();
	virtual void setSiguiente(BaseCarrito*);
	virtual void imprimir();
	/*friend ostream& operator<<(ostream&, DecoradorConserva&);*/
};

