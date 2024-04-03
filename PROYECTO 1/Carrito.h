#pragma once
#include "BaseCarrito.h"
class Carrito :public BaseCarrito{

public:
	Carrito();
	virtual ~Carrito();
	BaseCarrito* getSiguiente();
	virtual void setSiguiente(BaseCarrito*);
	void imprimir();

};

