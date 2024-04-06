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
public:
	DecoradorConserva(BaseCarrito*, string,string,string,double,bool);
	DecoradorConserva(const DecoradorConserva&);
	virtual ~DecoradorConserva();
	virtual BaseCarrito* getSiguiente();
	virtual void setSiguiente(BaseCarrito*);
	virtual void imprimir();
	/*friend ostream& operator<<(ostream&, DecoradorConserva&);*/
};

