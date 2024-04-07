#pragma once
#include "BaseCarrito.h"
class Carrito :public BaseCarrito{

public:
	Carrito();
	virtual ~Carrito();
	BaseCarrito* getSiguiente();
	virtual void setSiguiente(BaseCarrito*);
	virtual string imprimir();
	friend ostream& operator<<(ostream&, Carrito&);
	virtual double getTotal();
	/*virtual int getCantidad();*/

};

