#pragma once
#include "ProductoDecorador.h"
#include "Persona.h"
#include "Fecha.h"
using namespace std;


class Venta{
	private:
		ProductoDecorador* carrito;
		Persona* persona;
		string codigo;
		Fecha* fVenta;
	public:

		//Constructores y Destructor
		Venta(ProductoDecorador*,Persona*,Fecha*,string);
		Venta(const Venta&);
		virtual ~Venta();


		//Accesores
		string getCodigo();
		Persona* getPersona();
		BaseCarrito* getCarrito();
		Fecha* getFecha();

		//Mutadores
		void setCodigo(string);
		void setCarrito(ProductoDecorador*);
		void setPersona(Persona*);
		void setFecha(Fecha*);


		string toString()const;//Factura
		friend ostream& operator<<(ostream&, Venta&);

		//Métodos de cálculo
		double totalbruto()const;
		double totalIVa()const;
		double totalneto()const;

		//Heredados
		Venta* clonar()const;
};

