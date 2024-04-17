#pragma once
#include "Controlador.h"
class Interfaz
{
public:

	//Menú Principal
	static int menuPrincipalOp();

	//SubMenús
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

	//Modificación Prod. Específico
	static int menuMantModifProd();
	static void mantModifProd(Minisuper*);
	static int menuOpcionesModificicado();

	//Reportes.
	static void menuReportesProductos(Minisuper*);
	static void menuReportesProdConserva(Minisuper*);
	static void menuReportesProdAbarrote(Minisuper*);
	static void menuReportesProdEmbutido(Minisuper*);
	static int  menuReportProdMinimo();
	static void reportProdEscasoz(Minisuper*);
	static int  menuReportesProductosEspecificos();

	//Menú eliminación Productos.
	static int menuEliminarProducto();
	static void Eliminacion(Minisuper*);

	//CLIENTES.

	//Menú de clientes.
	static int  menuMantClientes();
	static void menuMantAgregarClientes(Minisuper*);

	//Reporte clientes.
	static int  menuReporteClientes();
	static void ReporteClientes(Minisuper*);
	static int  menuReportesClienteEspecifico();
	static void ReporteClienteEspecifico(Minisuper*);
	static int  menuReportesTopClientes(Minisuper*);

	//Menú Creación de ventas
	static int menuCreacionVentas();
	static void agregarProductoVenta(Minisuper*);
	static ComponenteAbstracto* crearVenta(Minisuper*, ComponenteAbstracto&);
	

};

