#pragma once
#include <iostream>
#include <sstream>
#include <fstream> 
using namespace std;
#include "Persona.h"
#include "ContenedorGenerico.h"
#include "Producto.h"
#include "Embutido.h"
#include "Abarrote.h"
#include "Conserva.h"
#include "Venta.h"
class Minisuper
{
private:
	Lista<Persona>* listPersona;
	Lista<Producto>* listProducto;
	Lista<Venta>* listVenta;

public:
	Minisuper();
	virtual ~Minisuper();


	void agregarPersona(Persona*);
	void agregarProducto(Producto*);
	void agregarVenta(Venta*);


	Nodo<Venta>* getFactura(string);


	Nodo<Producto>* buscarProducto(string);

	string toStringListProd();
};

