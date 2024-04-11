#pragma once
#include "ProductoDecorador.h"
#include "Persona.h"
#include "ObjetoBase.h"
using namespace std;


class Venta:public ObjetoBase{
	private:
		ProductoDecorador* carrito;
		Persona* persona;
		string codigo;
	public:

		//Constructores y Destructor
		Venta(ProductoDecorador*,Persona*,string);
		Venta(const Venta&);
		virtual ~Venta();


		//Accesores
		string getCodigo();
		Persona* getPersona();
		BaseCarrito* getCarrito();

		//Mutadores
		void setCodigo(string);
		void setCarrito(ProductoDecorador*);
		void setPersona(Persona*);


		string toString()const;//Factura
		friend ostream& operator<<(ostream&, Venta&);

		//Métodos de cálculo
		double totalbruto()const;
		double totalIVa()const;
		double totalneto()const;

		//Heredados
		ObjetoBase* clonar()const;
};

