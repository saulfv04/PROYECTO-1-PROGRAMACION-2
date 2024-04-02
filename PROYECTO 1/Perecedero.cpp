#include "Perecedero.h"

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
