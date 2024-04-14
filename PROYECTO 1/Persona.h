#pragma once
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
class Persona{
private:
	string cedula;

public:
	//c
	Persona();
	Persona(string);
	Persona(const Persona&);
	~Persona();

	//
	string getCodigo()const;

	string toString()const;

	//Heredado
	virtual  Persona* clonar()const;
	friend ostream& operator<<(ostream&, Persona&);
	friend ifstream& operator>>(ifstream&, Persona&);
};
