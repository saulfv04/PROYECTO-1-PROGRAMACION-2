#pragma once
#include "BaseCarrito.h"
class Carrito :public BaseCarrito{

public:
	Carrito();
	virtual ~Carrito();
	Carrito(const Carrito&);
	BaseCarrito* getSiguiente();
	virtual void setSiguiente(BaseCarrito*);
	virtual string toString() const;
	friend ostream& operator<<(ostream&, Carrito&);
	virtual double getTotal();
	/*virtual int getCantidad();*/
	virtual BaseCarrito* clonar() const;

};

