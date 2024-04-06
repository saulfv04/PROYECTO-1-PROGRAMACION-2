#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
class Persona {
private:
	string nombre;
	string cedula;

public:
	//c
	Persona();
	Persona(string,string);
	Persona(const Persona&);
	~Persona();

	//
	string getNombre();
	string getCedula();

	void setNombre(string);

	string toString();

	friend ostream& operator<<(ostream&, Persona&);
	friend ifstream& operator>>(ifstream&, Persona&);
};
