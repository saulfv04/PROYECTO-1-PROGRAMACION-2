#pragma once
#include <iostream>
#include <sstream>

using namespace std;
class BaseCarrito {

public:
	virtual ~BaseCarrito(){}
	virtual BaseCarrito* getSiguiente()=0;
	virtual void setSiguiente(BaseCarrito*)=0;
	virtual string toString() const = 0;
	friend ostream& operator<<(ostream&, BaseCarrito&);
	virtual double getTotal() = 0;
	virtual BaseCarrito* clonar() const = 0;
	/*virtual int getCantidad() = 0;*/
};