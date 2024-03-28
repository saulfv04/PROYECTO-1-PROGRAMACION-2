#include "Abarrote.h"
#include "Carne.h"
#include "Producto.h"
#include "Conserva.h"
#include "Empaque.h"
#include "Embutido.h"
#include "Fecha.h"
#include "Perecedero.h"
#include "Prod-Perecedero.h"


int main() {

	Fecha* fechaIng = new Fecha(11, 12, 2004);
	Fecha* fechaIng1 = new Fecha(9, 12, 2014);
	Fecha* fechaIng2= new Fecha(1, 2, 2024);
	Fecha* fechaIng3 = new Fecha(18, 9, 2003);

	Fecha* fechaPer = new Fecha(10,8,2010);
	Fecha* fechaPer1 = new Fecha(3, 4, 2012);

	Perecedero* pere1 = new Perecedero(fechaPer);
	Perecedero* pere2 = new Perecedero(fechaPer1);

	Producto* prod1 = new Embutido()








	system("pause");
	return 0;
}