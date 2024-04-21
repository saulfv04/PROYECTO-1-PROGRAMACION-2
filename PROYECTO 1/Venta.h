#pragma once
#include "ProductoDecorador.h"
#include "Fecha.h"
#include <iostream>
#include <sstream>

using namespace std;

class Venta{
	private:
		ProductoDecorador* carrito;
		string cedulaCliente;
		string codigo;
		Fecha* fVenta;
	public:

		//Constructores y Destructor
		Venta();
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
		void setCliente(string);
		void setCodigo(string);
		//Información 
		string toString()const;//Factura

		//Métodos de cálculo
		double totalbruto()const;
		double totalIVa()const;
		double totalneto()const;

		//Sobrecargas
		Venta* clonar()const;
		friend ostream& operator<<(ostream&, Venta&);


		//Archivos

		virtual void guardarVenta(ofstream&);

		static Venta* leerVenta(ifstream&);
};

