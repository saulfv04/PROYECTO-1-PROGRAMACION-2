#pragma once
#include <iostream>
#include <sstream>
#include "ExcepcionRango.h"
using namespace std;
class ERS :public ExcepcionRango {
	int valor;
public:
	ERS(int v, int mx, int mn);
	virtual ~ERS();
	const char* what()const throw();
	virtual string toString();
};