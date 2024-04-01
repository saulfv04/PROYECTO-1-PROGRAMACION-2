#pragma once
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Fecha
{
	private:
		int dia;
		int mes;
		int anio;
	public:
		Fecha(int, int, int);
		Fecha(const Fecha&);
		virtual ~Fecha();

		int getFecha();
		string toString();
		void guardarFecha(ofstream&);
		static Fecha* leerFecha(ifstream&);
};

