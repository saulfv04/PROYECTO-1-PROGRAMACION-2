#pragma once
#include "ProductoDecorador.h"
#include "Conserva.h"
#include "DecoradorAbarrote.h"
#include "DecoradorEmbutido.h"
#include "Carrito.h"
class DecoradorConserva :public ProductoDecorador{
private:
	string nombre;
	string codigo;
	string descricion;
	double precio;
	bool envasado;
	string categoria;
	int cantidad;
public:
	DecoradorConserva(ComponenteAbstracto*, string,string,string,double,bool,int);
	DecoradorConserva(const DecoradorConserva&);
	virtual ~DecoradorConserva();
	virtual ComponenteAbstracto* getSiguiente();
	virtual void setSiguiente(ComponenteAbstracto*);
	virtual string toString() const;
	virtual double getTotal();
	virtual double getGanancia();
	virtual double getCantidad();
	virtual ComponenteAbstracto* clonar() const;

	//Archivos
	virtual void guardarComponenteAbstracto(ofstream&);
	static DecoradorConserva* leerDecoConserva(ifstream&);

	//Sobrecargas
	friend ostream& operator<<(ostream&, DecoradorConserva&);

};

