#pragma once
#include <iostream>
#include <sstream>

using namespace std;
class ComponenteAbstracto {

public:
	virtual ~ComponenteAbstracto(){}
	virtual ComponenteAbstracto* getSiguiente()=0;
	virtual void setSiguiente(ComponenteAbstracto*)=0;
	virtual string toString() const = 0;
	virtual double getTotal() = 0;
	virtual ComponenteAbstracto* clonar() const = 0;
	virtual double getCantidad() = 0;

	//virtual void guardarComponenteAbstracto(ofstream&) = 0;

	friend ostream& operator<<(ostream&, ComponenteAbstracto&);
};