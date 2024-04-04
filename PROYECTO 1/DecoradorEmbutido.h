#pragma once
#include "ProductoDecorador.h"
#include "Embutido.h"
class DecoradorEmbutido : public ProductoDecorador {
private:
	Embutido* ptrEmbutido;
public:
	DecoradorEmbutido(BaseCarrito*, Embutido*);
	virtual ~DecoradorEmbutido();
	virtual BaseCarrito* getSiguiente();
	virtual void setSiguiente(BaseCarrito*);
	virtual void imprimir();
	/*friend ostream& operator<<(ostream& o, DecoradorEmbutido&);*/
};

