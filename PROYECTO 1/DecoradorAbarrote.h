#pragma once
#include "ProductoDecorador.h"
#include "Abarrote.h"
class DecoradorAbarrote : public ProductoDecorador{
private:

	Perecedero* ptrPer;
	string empresaNombre;
	string codigo;
	string nombreComercial;
	string descripcion;
	bool nacional;
	double peso;
	double precioCosto;
public:
	DecoradorAbarrote(BaseCarrito*, Perecedero*, string, string, string, string, bool, double, double);
	DecoradorAbarrote(const DecoradorAbarrote&);
	virtual ~DecoradorAbarrote();
	virtual BaseCarrito* getSiguiente();
	virtual void setSiguiente(BaseCarrito*);
	virtual string imprimir();
	friend ostream& operator<<(ostream&, DecoradorAbarrote&);
};

