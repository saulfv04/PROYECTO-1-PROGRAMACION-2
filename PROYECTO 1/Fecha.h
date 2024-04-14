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
		//Constructor y Destructor
		Fecha();
		Fecha(int, int, int);
		Fecha(const Fecha&);
		virtual ~Fecha();

		//Accesor
		int getFecha();

		string toString();


		//Archivos
		void guardarFecha(ofstream&);
		static Fecha* leerFecha(ifstream&);

		//Sobrecargas
		friend ostream& operator<<(ostream&, Fecha&);
		friend istream& operator>>(istream&, Fecha&);

};

