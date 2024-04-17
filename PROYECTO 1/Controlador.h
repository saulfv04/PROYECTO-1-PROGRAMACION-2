#pragma once
#include "Minisuper.h"
#include "Interfaz.h"
#include "ExcepcionRango.h"
#include "ERI.h"
#include "ERS.h"
class Controlador{
private:
	Minisuper* minisuper;

public:
	Controlador();
	virtual ~Controlador();


	void control0();

	//Control principal
	void control1();//Control Principal de Mantenimiento
	void control2();//Control Principal de Ventas
	void control3();//Control Principal de Reportes
	void control4();//Control Principal de Clientes


	//MANTENIMIENTOS

	//MANTENIMIENTOS VENTAS
	void control1_1();//Mantemiento Facturas
	void control1_1_1();//Mantemiento Facturas (Retorno de Factura Específica)

	//MANTENIMIENTOS PRODUCTOS
	void control1_2();//Mantemiento Productos
	void control1_2_1();//Mantemiento Productos (Ingreso de producto)
	void control1_2_1_1();//Ingreso Prod.Conserva
	void control1_2_1_2();//Ingreso Prod.Embutido
	void control1_2_1_3();//Ingreso Prod.Abarrote

	void control1_2_2();//Mantemiento Productos (Eliminar producto)
	void control1_2_2_2();//Eliminacion de producto específico
	void control1_2_3();//Mantemiento Productos (Modificación producto)
	void control1_2_3_1();//Modificación Producto


	//VENTA
	void control2_1();//Control Creación de Ventas


	//REPORTES
	void control3_1();//Reporte todos los productos del minisuper
	void control3_2();//Reporte de productos por su categoría
	void control3_2_1();//Reporte de productos (Conserva)
	void control3_2_2();//Reporte de productos (Abarrote)
	void control3_2_3();//Reporte de productos (Embutido)
	void control3_3();//Reporte por debajo del minimo (Límite)
	void control3_3_1();//Reporte Escasez prod.
	void control3_4();//Reporte de las facturas de un cliente determinadas por su cédula
	void control3_4_1();//Reporte VENTAS cliente específico
	void control3_5();//Reporte de cédulas de los mejores 5 cliente del minisuper
	void control3_5_1();//Top 5 mejores cliente del minisuper
	void control3_6();//Reporte de todos los clientes
	void control3_6_1();//Mostrar Clientes por su cédula


	void control4_1();//Mantenimiento de Clientes (Ingreso de cliente)


	//Dependecias con Interfaz
	int controlmenuPrincipal();

	int controlMantenimientos();
	int controlMantenimientoFacturas();

	//Productos
	int controlMantemientoProductos();
	int controlMntIngresoProductos();
	int controlMntEliminarProducto();

	//Modificiación Prod.
	int contrlMntModificacionProducto();

	int controlMntIngresoClientes();

	//Control De Reportes
	int controlReportClientes();


	int controlReport();
	int controlReportEscasezProducto();
	int controlReportProductoCategoria();
	int controlReportVentasClienteEspecifico();


	//Ventas
	int controlCreancionVentas();
	
	int controlTopClientes();
};

