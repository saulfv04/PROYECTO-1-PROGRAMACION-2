#pragma once
#include "Minisuper.h"
#include "Interfaz.h"
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
	void control1_2_2_2();
	void control1_2_3();//Mantemiento Productos (Modificación producto)



	//VENTA
	void control2_1();//Control Creación de Ventas



	//REPORTES
	void control3_1();//Reporte todos los productos del minisuper
	void control3_2();//Reporte de productos por su categoría
	void control3_3();//Reporte por debajo del minimo (Límite)
	void control3_4();//Reporte de las facturas de un cliente determinadas por su cédula
	void control3_5();//Reporte de cédulas de los mejores 5 cliente del minisuper


	void control4_1();//Mantenimiento de Clientes (Ingreso de cliente)


	//Dependecias con Interfaz
	int controlmenuPrincipal();

	int controlMantenimientos();
	int controlMantenimientoFacturas();
	string controlRetornoFacturas();


	int controlMantemientoProductos();
	int controlMntIngresoProductos();

	int controlMntIngresoClientes();


	int controlReport();
};

