#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class BaseCarrito {

public:
	virtual ~BaseCarrito(){}
	virtual BaseCarrito* getSiguiente()=0;
	virtual void setSiguiente(BaseCarrito*)=0;
	virtual string imprimir() =0;
	friend ostream& operator<<(ostream&, BaseCarrito&);
	virtual double getTotal() = 0;
	/*virtual int getCantidad() = 0;*/
};