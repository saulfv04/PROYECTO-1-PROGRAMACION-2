#pragma once
#include "Controlador.h"
class Interfaz
{
public:
	static int menuPrincipalOp();

	static int menuMantenimiento();
	static int menuMantenimientoVentas();
	static string retornoFacturas();

	static int menuMantenimientoProductos();

	static int menuMantIngresoProductos();


	static void agregarProductoConserva(Minisuper*);
	static void agregarProductoEmbutido(Minisuper*);
	static void agregarProductoAbarrote(Minisuper*);

	static int menuEliminarProducto();
	static void Eliminacion(Minisuper*);

	static int menuMantClientes();
	static void menuMantAgregarClientes(Minisuper*);

	static int menuReportesPrincipal();
	static void menuReportesProductos(Minisuper*);
	static int menuReportProdMinimo(Minisuper*);
	static int menuReportesClienteEspecifico(Minisuper*);
	static int menuReportesTopClientes(Minisuper*);


};

