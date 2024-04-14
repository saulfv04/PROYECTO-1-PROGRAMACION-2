#pragma once
#include "ProductoDecorador.h"
#include "Persona.h"
#include "Fecha.h"
using namespace std;


class Venta{
	private:
		ProductoDecorador* carrito;
		string nombreCliente;
		string codigo;
		Fecha* fVenta;
	public:

		//Constructores y Destructor
		Venta(ProductoDecorador*,string,Fecha*,string);  
		Venta(const Venta&);
		virtual ~Venta();


		//Accesores
		string getCodigo()const;
		string getPersona();
		ComponenteAbstracto* getCarrito();
		Fecha* getFecha();

		//Mutadores
		void setCarrito(ProductoDecorador*);
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

