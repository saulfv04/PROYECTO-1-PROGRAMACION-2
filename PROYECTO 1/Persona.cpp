#include "Persona.h"

Persona::Persona(){
	this->cedula = "i";
	
}

Persona::Persona(string c){

	this->cedula = c;
}

Persona::Persona(const Persona& p){
	this->cedula = p.cedula;
	
}

Persona::~Persona(){
	cout << "Borrando Persona" << endl;

}




string Persona::getCodigo()const{
	return this->cedula;
}

string Persona::toString()const
{
	stringstream s;
	s << "Cedula: " << this->cedula << endl;
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

ifstream& operator>>(ifstream& i, Persona& p)
{
	i  >>  p.cedula;
	return i;
}
