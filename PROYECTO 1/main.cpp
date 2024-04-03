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

	Empaque* empaque = new Empaque(true);
	cout << "MAIN DE PRUEBA UML PRODUCTOS" << endl << endl;
	//Empaque*, string, string, string, Perecedero*, Fecha*, string, bool, double, string, string, string, double, string, int, int
	Producto* prod1 = new Embutido(empaque, "SABEMAS", "VACUNO", "COSTILLA", pere1, fechaIng, false, 2.1, "124331", "COSTILLA AHUMADA", "Procedencia Japonesa", 60.00, "01", 46, 5);
	cout << "Producto Embutido" << endl << prod1->toString()<<endl;

	//Fecha* ptrF, bool en, string c, string nC, string d, double pC, string cat, int e, int l
	Producto* prod2 = new Conserva(fechaIng1,true,"1299903","Atun en agua","Conserva sin fcha limite de vencimiento",3.99,"03",2000,15);
	cout << "Producto Conserva" << endl << prod1->toString() << endl;



	//Perecedero* ptrP,Fecha* ptrFI, string eN,bool n, double p, string c, string nC, string d, double pC, string cat, int e, int l
	Producto* prod3 = new Abarrote(pere2,fechaIng2,"Dos pinos",true,0.9,"134564","Helado de vainilla","Contiene chocoalte derretido en su interior",8.99,"02",88,4);
	cout << "Producto Abarrote" << endl << prod3->toString() << endl;


	system("pause");
	return 0;
}