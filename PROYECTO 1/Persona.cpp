#include "Persona.h"

Persona::Persona(){
	this->cedula = "i";
	this->dinero = 0.0;
	
}

Persona::Persona(string c){

	this->cedula = c;
	this->dinero = 0.0;
}

Persona::Persona(string c, double din)
{
	this->cedula = c;
	this->dinero = din;
}

Persona::Persona(const Persona& p){
	this->cedula = p.cedula;
	this->dinero = p.dinero;	
}

Persona::~Persona(){
}




string Persona::getCodigo()const{
	return this->cedula;
}

double Persona::getDinero()
{
	return this->dinero;
}

void Persona::setDinero(double n)
{
	this->dinero += n;
}


string Persona::toString()const
{
	stringstream s;
	s << "Cedula: " << this->cedula << endl;
	s<< "Dinero en ventas: " << this->dinero << endl;
	return s.str();
}

void Persona::guardarPersona(ofstream& file)
{
	file <<"Persona"<< '\t' << cedula << '\t' << dinero << '\n';
}

Persona* Persona::leerPersona(ifstream& file)
{
	string cedula,din;
	double dine;

	getline(file, cedula, '\t');
	getline(file, din, '\n');
	dine = stod(din);

	return new Persona(cedula,dine);
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
