#include "Persona.h"

Persona::Persona(){
	this->cedula = "i";
	this->nombre = "i";
}

Persona::Persona(string n, string c){
	this->nombre = n;
	this->cedula = c;
}

Persona::Persona(const Persona& p){
	this->cedula = p.cedula;
	this->nombre = p.nombre;
}

Persona::~Persona(){}

string Persona::getNombre()
{
	return nombre;
}

string Persona::getCedula()
{
	return cedula;
}

void Persona::setNombre(string n){
	this->nombre = n;
}

ostream& operator<<(ostream& o, Persona& p)
{
	o << "Nombre: " << p.nombre << "Cedula: " << p.cedula<<endl;
	return o;
}

ifstream& operator>>(ifstream& i, Persona& p)
{
	i >> p.nombre >>  p.cedula;
	return i;
}
