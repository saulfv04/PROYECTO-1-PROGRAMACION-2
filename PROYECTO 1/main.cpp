#include "Abarrote.h"
#include "Carne.h"
#include "Producto.h"
#include "Conserva.h"
#include "Empaque.h"
#include "Embutido.h"
#include "Fecha.h"
#include "Perecedero.h"
#include "Prod-Perecedero.h"
#include "DecoradorAbarrote.h"
#include "DecoradorConserva.h"
#include "DecoradorEmbutido.h"
#include "Carrito.h"
#include "BaseCarrito.h"
#include <iostream>
#include "Persona.h"

#include "ContenedorGenerico.h"


int main() {

    Fecha* fechaIng = new Fecha(11, 12, 2004);
    Fecha* fechaIng1 = new Fecha(9, 12, 2014);
    Fecha* fechaIng2 = new Fecha(1, 2, 2024);
    Fecha* fechaIng3 = new Fecha(18, 9, 2003);

    Fecha* fechaPer = new Fecha(10, 8, 2010);
    Fecha* fechaPer1 = new Fecha(3, 4, 2012);

    Perecedero* pere1 = new Perecedero(fechaPer);
    Perecedero* pere2 = new Perecedero(fechaPer1);

    Empaque* empaque = new Empaque(true);
    //cout << "MAIN DE PRUEBA UML PRODUCTOS" << endl << endl;
    //Empaque, string, string, string, Perecedero, Fecha, string, bool, double, string, string, string, double, string, int, int
    Producto* prod1 =  new Embutido(empaque, "SABEMAS", "VACUNO", "COSTILLA", pere1, fechaIng, false, 2.1, "124331", "COSTILLA AHUMADA", "Procedencia Japonesa", 60.99, "01", 46, 5);
   /* cout << "Producto Embutido" << endl << prod1->toString() << endl; */

        //Fecha* ptrF, bool en, string c, string nC, string d, double pC, string cat, int e, int l
    Producto* prod2 = new Conserva(fechaIng1, true, "1299903", "Atun en agua", "Conserva sin fcha limite de vencimiento", 3.99, "03", 2000, 15);
   /* cout << "Producto Conserva" << endl << prod1->toString() << endl; */



     //Perecedero* ptrP,Fecha* ptrFI, string eN,bool n, double p, string c, string nC, string d, double pC, string cat, int e, int l
     Producto * prod3 = new Abarrote(pere2, fechaIng2, "Dos pinos", true, 0.9, "134564", "Helado de vainilla", "Contiene chocolate derretido en su interior", 8.99, "02", 88, 4);
    //cout << "Producto Abarrote" << endl << prod3->toString() << endl;
     /**/


    /* cout << *prod1;
     cout << endl;
     cout << endl;

     cout << *prod2;
     cout << endl;
     cout << endl;

     cout << *prod3;
     cout << endl;
     cout << endl;*/

     Lista<Persona>* lista = new Lista<Persona>();
     Persona* p1 = new Persona("433456464");
     Persona* p2 = new Persona("433456464");
     Persona* p3 = new Persona("433456464");

     lista->agregarInicio(p1);
     lista->agregarInicio(p2);
     lista->agregarInicio(p3);
     cout << lista->toString() << endl;



    /*BaseCarrito* carro = nullptr;
    carro = new Carrito();
    carro = new DecoradorAbarrote(carro, abarrote->getPer(), abarrote->getnombreComecial(), abarrote->getCodigo(), abarrote->getnombreComecial(), abarrote->getDescripcion(), abarrote->getNacional(), abarrote->getPeso(), abarrote->getprecioCosto());
    cout << *carro*/;


  /*  Persona* p1 = new Persona("Juan", "433456464");
    cout << "Persona con sobrecarga" << endl;
    cout << *p1;*/
    system("pause");
    return 0;
}