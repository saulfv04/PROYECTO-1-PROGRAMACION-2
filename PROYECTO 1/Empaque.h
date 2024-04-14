#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

class Empaque{
	private:
		bool tripa;
	public:
		//Constructores y Destructor
		Empaque();
		Empaque(bool);
		Empaque(const Empaque&);
		virtual ~Empaque();

		//Accesores y mutadores de la clase
		bool getTripa();
		void setTripa(bool);

		//Archivos
		void guardarEmpaque(ofstream&);
		static Empaque* leerEmpaque(ifstream&);

		//Sobrecargas
		friend ostream& operator<<(ostream&, Empaque&);
		friend istream& operator>>(istream&, Empaque&);
};

