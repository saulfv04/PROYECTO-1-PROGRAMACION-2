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
