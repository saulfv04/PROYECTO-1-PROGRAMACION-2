#include "Perecedero.h"

Perecedero::Perecedero(){
	this->ptrFechaPer = new Fecha();
}

Perecedero::Perecedero(Fecha* fP)
{
	ptrFechaPer = fP;
}

Perecedero::Perecedero(const Perecedero& copia){
	this->ptrFechaPer = new Fecha(*copia.ptrFechaPer);
}

Perecedero::~Perecedero()
{
	if (ptrFechaPer != nullptr) {
		delete ptrFechaPer;
	}
}

string Perecedero::toString()
{
	return ptrFechaPer->toString();
}

int Perecedero::getFechaPer()
{
	return ptrFechaPer->getFecha();
}

void Perecedero::setFecha(Fecha* f){
	this->ptrFechaPer = new Fecha(*f);
}

void Perecedero::guardarPerecedero(ofstream& file)
{
	if (ptrFechaPer != nullptr) {
		ptrFechaPer->guardarFecha(file);
	}
}

Perecedero* Perecedero::leerPerecedero(ifstream& file)
{
	Fecha* fecha;

	fecha = Fecha::leerFecha(file);
	
	return new Perecedero(fecha);
}

ostream& operator<<(ostream& s, Perecedero& per)
{
	s << per.toString();
	return s;
}

istream& operator>>(istream& i, Perecedero& p){
	Fecha* f = new Fecha();
	cout << "Fecha de vencimiento: " << endl;
	i >> *f;
	p.setFecha(f);
	return i;
}
