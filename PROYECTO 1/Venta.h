#pragma once
#include "BaseCarrito.h"
#include "Persona.h"



class Venta
{
	private:
		BaseCarrito* carrito;
		Persona* persona;
		string codigo;
	public:
		Venta(BaseCarrito*,Persona*,string);
		Venta(const Venta&);
		virtual ~Venta();
		string getCodigo();
		void setCodigo(string);
		BaseCarrito* getCarrito();
		void setCarrito(BaseCarrito*);
		Persona* getPersona();
		void setPersona(Persona*);
		string toString();//Factura
		friend ostream& operator<<(ostream&, Venta&);
		double totalbruto();
		double totalIVa();
		double totalneto();
};

