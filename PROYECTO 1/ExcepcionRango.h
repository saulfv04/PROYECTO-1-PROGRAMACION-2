#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class ExcepcionRango
{
protected:
	int max;
	int min;
public:
		ExcepcionRango(int, int);
		virtual ~ExcepcionRango();
		virtual const char* what()const throw() = 0;
		virtual string toString()=0;
};

