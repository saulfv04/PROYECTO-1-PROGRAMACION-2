#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include "ObjetoBase.h"
using namespace std;
class Persona :public ObjetoBase{
private:
	string cedula;

public:
	//c
	Persona();
	Persona(string);
	Persona(const Persona&);
	~Persona();

	//
	string getCedula();

	string toString()const;

	//Heredado
	virtual  ObjetoBase* clonar()const;
	friend ostream& operator<<(ostream&, Persona&);
	friend ifstream& operator>>(ifstream&, Persona&);
};
