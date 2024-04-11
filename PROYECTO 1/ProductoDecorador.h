#pragma once
#include "BaseCarrito.h"
class ProductoDecorador : public BaseCarrito{

protected:

	BaseCarrito* ptrCarrito;

public:
	
	virtual ~ProductoDecorador();
	virtual BaseCarrito* getSiguiente()=0;
	virtual void setSiguiente(BaseCarrito*)=0;
	virtual string toString() const =0;
	virtual double getTotal() = 0;
	/*virtual int getCantidad() = 0;*/
	virtual ObjetoBase* clonar() const = 0;

};

