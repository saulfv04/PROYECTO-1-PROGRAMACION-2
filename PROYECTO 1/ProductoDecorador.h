#pragma once
#include "ComponenteAbstracto.h"
class ProductoDecorador : public ComponenteAbstracto{

protected:

	ComponenteAbstracto* ptrCarrito;

public:
	
	virtual ~ProductoDecorador();
	virtual ComponenteAbstracto* getSiguiente()=0;
	virtual void setSiguiente(ComponenteAbstracto*)=0;
	virtual string toString() const =0;
	virtual double getTotal() = 0;
	virtual double getGanancia() = 0;
	/*virtual int getCantidad() = 0;*/
	virtual ComponenteAbstracto* clonar() const = 0;
	
};

