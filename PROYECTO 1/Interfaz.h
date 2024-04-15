#pragma once
#include "Controlador.h"
class Interfaz
{
public:

	//Men� Principal
	static int menuPrincipalOp();

	//SubMen�s
	static int menuMantenimiento();
	static int menuMantenimientoVentas();
	static void menuFacturas(Minisuper*);


	//Reportes principales.
	static int menuReportesPrincipal();

	//PRODUCTOS.

	//Mant. Productos.
	static int menuMantenimientoProductos();
	static int menuMantIngresoProductos();

	//Agregar productos (Por Tipo).
	static void agregarProductoConserva(Minisuper*);
	static void agregarProductoEmbutido(Minisuper*);
	static void agregarProductoAbarrote(Minisuper*);

	//Reportes.
	static void menuReportesProductos(Minisuper*);
	static void menuReportesProdConserva(Minisuper*);
	static void menuReportesProdAbarrote(Minisuper*);
	static void menuReportesProdEmbutido(Minisuper*);
	static int  menuReportProdMinimo(Minisuper*);
	static int  menuReportesProductosEspecificos();

	//Men� eliminaci�n Productos.
	static int menuEliminarProducto();
	static void Eliminacion(Minisuper*);

	//CLIENTES.

	//Men� de clientes.
	static int  menuMantClientes();
	static void menuMantAgregarClientes(Minisuper*);

	//Reporte clientes.
	static int  menuReporteClientes();
	static void ReporteClientes(Minisuper*);
	static int  menuReportesClienteEspecifico(Minisuper*);
	static int  menuReportesTopClientes(Minisuper*);


};

