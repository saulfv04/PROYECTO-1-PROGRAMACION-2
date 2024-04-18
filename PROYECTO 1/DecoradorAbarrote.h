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
	string categoria;
public:
	DecoradorAbarrote(ComponenteAbstracto*, Perecedero*, string, string, string, string, bool, double, double);
	DecoradorAbarrote(const DecoradorAbarrote&);
	virtual ~DecoradorAbarrote();
	virtual ComponenteAbstracto* getSiguiente();
	virtual void setSiguiente(ComponenteAbstracto*);
	virtual string toString() const;
	virtual double getTotal();
	virtual double getGanancia();
	/*virtual int getCantidad();*/
	virtual ComponenteAbstracto* clonar() const;

	//Sobrecargas
	friend ostream& operator<<(ostream&, DecoradorAbarrote&);

};

