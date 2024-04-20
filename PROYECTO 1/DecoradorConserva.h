#pragma once
#include "ProductoDecorador.h"
#include "Conserva.h"
class DecoradorConserva :public ProductoDecorador{
private:
	string nombre;
	string codigo;
	string descricion;
	double precio;
	bool envasado;
	string categoria;
	double cantidad;
public:
	DecoradorConserva(ComponenteAbstracto*, string,string,string,double,bool,double);
	DecoradorConserva(const DecoradorConserva&);
	virtual ~DecoradorConserva();
	virtual ComponenteAbstracto* getSiguiente();
	virtual void setSiguiente(ComponenteAbstracto*);
	virtual string toString() const;
	virtual double getTotal();
	virtual double getGanancia();
	virtual double getCantidad();
	virtual ComponenteAbstracto* clonar() const;

	//Sobrecargas
	friend ostream& operator<<(ostream&, DecoradorConserva&);

};

