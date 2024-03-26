#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Fecha
{
	private:
		int dia;
		int mes;
		int anio;
	public:
		Fecha(int, int, int);
		virtual ~Fecha();

		int getFecha();
		string toString();

};

