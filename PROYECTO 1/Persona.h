#pragma once
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
class Persona{
private:
	string cedula;
	int cantVentas;

public:
	//Contructores y Desctructor
	Persona();
	Persona(string);
	Persona(const Persona&);
	virtual ~Persona();


	//Accesores
	string getCodigo()const;
	int getCantVentas()const;
	void setCantidadVentas(int);

	//Información clase
	string toString()const;

	//Sobrecargas clase Persona
	virtual  Persona* clonar()const;
	friend ostream& operator<<(ostream&, Persona&);
	friend istream& operator>>(istream&, Persona&);
};
