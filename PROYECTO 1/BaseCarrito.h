#pragma once
#include <iostream>
#include <sstream>
#include "ObjetoBase.h"
using namespace std;
class BaseCarrito:public ObjetoBase {

public:
	virtual ~BaseCarrito(){}
	virtual BaseCarrito* getSiguiente()=0;
	virtual void setSiguiente(BaseCarrito*)=0;
	virtual string toString() const = 0;
	friend ostream& operator<<(ostream&, BaseCarrito&);
	virtual double getTotal() = 0;
	virtual ObjetoBase* clonar() const = 0;
	/*virtual int getCantidad() = 0;*/
};