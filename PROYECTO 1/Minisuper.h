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
#include "ComponenteAbstracto.h"
#include "Carrito.h"
#include "ProductoDecorador.h"
#include "DecoradorAbarrote.h"
#include "DecoradorEmbutido.h"
#include "DecoradorConserva.h"
class Minisuper
{
protected:
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
	Nodo<Persona>* getCliente(string);
	Nodo<Producto>* getProducto(string);


	Nodo<Producto>* buscarProducto(string);
	Producto* eliminarProductoEspecifico(string);
	

	Nodo<Producto>* getProducto();
	Nodo<Venta>* getVenta();
	Nodo<Persona>* getCliente();

	int getSizeVenta();
	int getSizePersona();


	string toStringListProd();
	string toStringListClientes();

	void guardarClientes();
	void guardarProductos();
	void guardarVentas();

	void leerClientes();
	void leerProductos();
	void leerVentas();





};

