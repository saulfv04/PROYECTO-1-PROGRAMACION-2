#include "Persona.h"

Persona::Persona(){
	this->cedula = "i";
	this->cantVentas = 0;
	
}

Persona::Persona(string c){

	this->cedula = c;
	this->cantVentas = 0;
}

Persona::Persona(const Persona& p){
	this->cedula = p.cedula;
	this->cantVentas = p.cantVentas;
	
}

Persona::~Persona(){
}




string Persona::getCodigo()const{
	return this->cedula;
}

int Persona::getCantVentas() const
{
	return this->cantVentas;
}

void Persona::setCantidadVentas(int c)
{
	this->cantVentas = c;
}

string Persona::toString()const
{
	stringstream s;
	s << "Cedula: " << this->cedula << endl;
	s<< "Cantidad de Ventas: " << this->cantVentas << endl;
	return s.str();
}

Persona* Persona::clonar() const
{
	return new Persona(*this);
}

ostream& operator<<(ostream& o, Persona& p)
{
	o << p.toString();
	return o;
}

istream& operator>>(istream& i, Persona& p)
{
	cout << "Creando Persona" << endl;
	cout << "Ingresar Cedula:" << endl;
	i  >>  p.cedula;
	return i;
}
