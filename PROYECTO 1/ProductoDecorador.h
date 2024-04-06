#pragma once
#include "BaseCarrito.h"
class ProductoDecorador : public BaseCarrito{

protected:

	BaseCarrito* ptrCarrito;

public:
	virtual ~ProductoDecorador();
	virtual BaseCarrito* getSiguiente()=0;
	virtual void setSiguiente(BaseCarrito*)=0;
	virtual string imprimir()=0;


};

