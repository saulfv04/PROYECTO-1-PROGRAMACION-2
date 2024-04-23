#include "Persona.h"

Persona::Persona(){
	this->cedula = "i";
	this->cantVentas = 0;
	
}

Persona::Persona(string c){

	this->cedula = c;
	this->cantVentas = 0;
}

Persona::Persona(string c, int cany)
{
	this->cedula = c;
	this->cantVentas = cany;
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

int Persona::getCantVentas()
{
	return this->cantVentas;
}

void Persona::setCantidadVentas(int n)
{
	this->cantVentas = n;
}


string Persona::toString()const
{
	stringstream s;
	s << "Cedula: " << this->cedula << endl;
	s<< "Cantidad de Ventas: " << this->cantVentas << endl;
	return s.str();
}

void Persona::guardarPersona(ofstream& file)
{
	file <<"Persona"<< '\t' << cedula << '\t' << cantVentas << '\n';
}

Persona* Persona::leerPersona(ifstream& file)
{
	string cedula,cant;
	int cantidadVentas;

	getline(file, cedula, '\t');
	getline(file, cant, '\n');
	cantidadVentas = stoi(cant);

	return new Persona(cedula,cantidadVentas);
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
