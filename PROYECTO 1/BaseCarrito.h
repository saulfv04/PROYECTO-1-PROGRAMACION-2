#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class BaseCarrito {

public:
	virtual ~BaseCarrito(){}
	virtual BaseCarrito* getSiguiente()=0;
	virtual void setSiguiente(BaseCarrito*)=0;
	virtual void imprimir() =0;
};