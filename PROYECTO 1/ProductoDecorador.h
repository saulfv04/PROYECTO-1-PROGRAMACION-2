#pragma once
#include "ComponenteAbstracto.h"
#include <iomanip>
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
	virtual double getCantidad() = 0;

	virtual ComponenteAbstracto* clonar() const = 0;
	
	//Archivos
	/*virtual void guardarComponenteAbstracto(ofstream&) = 0;*/

};

