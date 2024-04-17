#pragma once
#include <iostream>
#include <sstream>
#include "ExcepcionRango.h"
using namespace std;
class ERI :public ExcepcionRango {
	int valor;
public:
	ERI(int v, int mx, int mn);
	virtual ~ERI();
	const char* what()const throw();
	virtual string toString();
};

