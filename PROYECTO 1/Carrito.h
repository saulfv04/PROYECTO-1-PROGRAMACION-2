#pragma once
#include "ComponenteAbstracto.h"
class Carrito :public ComponenteAbstracto{

public:
	Carrito();
	virtual ~Carrito();
	Carrito(const Carrito&);
	ComponenteAbstracto* getSiguiente();
	virtual void setSiguiente(ComponenteAbstracto*);
	virtual string toString() const;
	virtual double getTotal();
	virtual double getCantidad();
	virtual ComponenteAbstracto* clonar() const;

	//Archivos
	virtual void guardarComponenteAbstracto(ofstream&);
	static Carrito* leerCarrito(ifstream&);

	//Sobrecargas
	friend ostream& operator<<(ostream&, Carrito&);

};

