#include "Interfaz.h"

int Interfaz::menuPrincipalOp(){
    int op;
    system("cls");
    cout << endl;
    cout << "_________________________________________________" << endl;
    cout << "|              -GESTION DE MINISUPER-           |" << endl;
    cout << "|                                               |" << endl;
    cout << "|                    OPCIONES                   |" << endl;
    cout << "|                                               |" << endl;
    cout << "|    <1>  Mantenimiento.                        |" << endl;
    cout << "|    <2>  Ventas.                               |" << endl;
    cout << "|    <3>  Reportes.                             |" << endl;
    cout << "|    <4>  Salir.                                |" << endl;
    cout << "|_______________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    return op;
}

int Interfaz::menuMantenimiento(){
    int op;
    system("cls");
    cout << endl;
    cout << "_________________________________________________" << endl;
    cout << "|           -GESTION DE MANTENIMIENTOS-         |" << endl;
    cout << "|                                               |" << endl;
    cout << "|                                               |" << endl;
    cout << "|                   OPCIONES                    |" << endl;
    cout << "|                                               |" << endl;
    cout << "|    <1>  Mnt.Facturas.                         |" << endl;
    cout << "|    <2>  Mnt.Productos.                        |" << endl;
    cout << "|    <3>  Clientes.                             |" << endl;
    cout << "|    <4>  Regresar.                             |" << endl;
    cout << "|_______________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    return op;
}

int Interfaz::menuMantenimientoVentas(){
    int op;
    system("cls");
    cout << endl;
    cout << "_________________________________________________" << endl;
    cout << "|               -GESTION DE VENTAS-             |" << endl;
    cout << "|                                               |" << endl;
    cout << "|                                               |" << endl;
    cout << "|                  OPCIONES                     |" << endl;
    cout << "|    <1>  Buscar Factura.                       |" << endl;
    cout << "|    <2>  Regresar.                             |" << endl;
    cout << "|_______________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    return op;
}

void Interfaz::menuFacturas(Minisuper* mini){
    string op;
    system("cls");
    cout << endl;
    cout << "------------Digite el numero de factura deseado----------" << endl;
    cin >> op;
    if (mini->getFactura(op) != nullptr) {
        cout << "Factura encontrada" << endl;
    }
    else {
        cout << "Ninguna venta asociada al codigo proporcionado" << endl;
    }
    system("pause");
}
int Interfaz::menuMantenimientoProductos()
{
    int op;
    system("cls");
    cout << endl;
    cout << "_________________________________________________" << endl;
    cout << "|          -GESTION DE PRODUCTOS-               |" << endl;
    cout << "|                                               |" << endl;
    cout << "|                                               |" << endl;
    cout << "|                OPCIONES                       |" << endl;
    cout << "|    <1>  Ingresar Producto.                    |" << endl;
    cout << "|    <2>  Eliminar Producto.                    |" << endl;
    cout << "|    <3>  Modificar Producto.                   |" << endl;
    cout << "|    <4>  Regresar.                             |" << endl;
    cout << "|_______________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    system("pause");
    return op;
}

int Interfaz::menuMantIngresoProductos(){
    int op;
    system("cls");
    cout << "_________________________________________________" << endl;
    cout << "|           -TIPO DE PRODUCTO A INGRESAR-       |" << endl;
    cout << "|                                               |" << endl;
    cout << "|                                               |" << endl;
    cout << "|                OPCIONES                       |" << endl;
    cout << "|    <1>  Prod.Conserva.                        |" << endl;
    cout << "|    <2>  Prod.Embutido.                        |" << endl;
    cout << "|    <3>  Prod.Abarrote.                        |" << endl;
    cout << "|    <4>  Regresar.                             |" << endl;
    cout << "|_______________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    system("pause");
    return op;
}


void Interfaz::agregarProductoConserva(Minisuper* mini){
    Producto* c = new Conserva();
    cin >> *c;
    mini->agregarProducto(c);
    cout << "Producto tipo conserva ingresado" << endl;
    system("pause");
}

void Interfaz::agregarProductoEmbutido(Minisuper* mini){
    Producto* c = new Embutido();
    cin >> *c;
    cout << "Producto tipo embutido ingresado" << endl;
    mini->agregarProducto(c);
    system("pause");
}

void Interfaz::agregarProductoAbarrote(Minisuper* mini){
    Producto* c = new Abarrote();
    cin >> *c;
    cout << "Producto tipo abarrote ingresado" << endl;
    mini->agregarProducto(c);
    system("pause");
}

int Interfaz::menuEliminarProducto(){
    int op;
    system("cls");
    cout << endl;
    cout << "_________________________________________________" << endl;
    cout << "|         -GESTION BORRADO DE PRODUCTO-         |" << endl;
    cout << "|                                               |" << endl;
    cout << "|                    OPCIONES                   |" << endl;
    cout << "|    <1>  Eliminar.                             |" << endl;
    cout << "|    <2>  Regresar.                             |" << endl;
    cout << "|_______________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    system("pause");
    return op;
}

void Interfaz::Eliminacion(Minisuper* mini)
{
    string op;
    string borrado;
    system("cls");
    cout << endl;
    cout << "__________________________________________" << endl;
    cout << "|         -ELIMINACION PRODUCTO-         |" << endl;
    cout << "|                                        |" << endl;
    cout << "|                                        |" << endl;
    cout << "|                OPCIONES                |" << endl;
    cout << "|                                        |" << endl;
    cout << "|    <1>   Cod.Producto.                 |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "Digite la opcion: ";    
    cin >> op;
    Producto* aux = mini->eliminarProductoEspecifico(op);
    if (aux!=nullptr) {
        cout <<"Producto Encontrado" << endl;
        cout << "El produto encontrado es el deseado..." << endl;
        cout << *aux;
        cout << "Desea borrar el producto de forma definitiva... " << endl;
        cout << "         (S)BORRAR          (N)Conservar        "<< endl;
        cout << "Digite la opcion : ";
        cin >> borrado;
        if (borrado=="S"||borrado=="s") {
            cout << "PRODUCTO BORRADO CON EXITO..." << endl;
        }
        else {
            mini->agregarProducto(aux);
            cout << "PRODUCTO DISPONIBLE EN MINISUPER." << endl;
        }
    }
    else {
        cout << "Producto no encontrado en minisuper" << endl;
    }
    system("pause");
}

int Interfaz::menuMantClientes(){
    int op;
    system("cls");
    cout << endl;
    cout << "_____________________________________________________" << endl;
    cout << "|         -GESTION MANTENIMIENTOS DE CLIENTES-      |" << endl;
    cout << "|                                                   |" << endl;
    cout << "|                      OPCIONES                     |" << endl;
    cout << "|    <1>  Agregar.Clientes.                         |" << endl;
    cout << "|    <2>  Regresar.                                 |" << endl;
    cout << "|___________________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    return op;
    system("pause");
}

void Interfaz::menuMantAgregarClientes(Minisuper* mini)
{
    Persona* p = new Persona();
    cin >> *p;
    cout << *p;
    mini->agregarPersona(p);
    cout << "Persona ingresada..." << endl;
}

int Interfaz::menuReporteClientes()
{
    int op;
    system("cls");
    cout << endl;
    cout << "__________________________________________" << endl;
    cout << "|       -REPORTE DE CLIENTES TOTAL-      |" << endl;
    cout << "|                                        |" << endl;
    cout << "|                                        |" << endl;
    cout << "|                OPCIONES                |" << endl;
    cout << "|                                        |" << endl;
    cout << "|    <1>   Ver.Clientes.                 |" << endl;
    cout << "|    <2>   Regresar.                     |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    system("pause");
    return op;
}

void Interfaz::ReporteClientes(Minisuper* mini){
    system("cls");
    cout << "__________________________________________" << endl;
    cout << "|          -CLIENTES MINISUPER-          |" << endl;
    cout << "|                                        |" << endl;
    cout << "|________________________________________|" << endl;
    cout << mini->toStringListClientes();
    system("pause");
}
//Reporte Facturas por su cédula
void Interfaz::ReporteClienteEspecifico(Minisuper* mini){

    string cedula;
    Nodo <Venta>* pAct = mini->getVenta();
    system("cls");
    cout << endl;
    cout << "__________________________________________" << endl;
    cout << "|       -VENTAS CLIENTE ESPECIFICO-      |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> cedula;
    while (pAct) {
        if (pAct->obtenerInfo()->getPersona() == cedula) {
            cout << *pAct->obtenerInfo() << endl;
        }
        pAct = pAct->obtenerSig();
    }
    system("pause");
}
int Interfaz::menuCreacionVentas()
{
    int op;
    system("cls");
    cout << endl;
    cout << "__________________________________________" << endl;
    cout << "|           -CARRITO DE COMPRAS-         |" << endl;
    cout << "|                                        |" << endl;
    cout << "|                                        |" << endl;
    cout << "|                OPCIONES                |" << endl;
    cout << "|                                        |" << endl;
    cout << "|    <1>   Crear Venta.                  |" << endl;
    cout << "|    <2>   Regresar.                     |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    system("pause");
    return op;
}
void Interfaz::crearVenta(Minisuper* mini)
{
 /*   string op;*/
   /* ComponenteAbstracto* carrito = new Carrito();
    do {



    } while (op!="N"||op!="n");
*/


}
//Menu para reporte Facturas por su cédula
int Interfaz::menuReportesClienteEspecifico(){
    int op;
    system("cls");
    cout << endl;
    cout << "__________________________________________" << endl;
    cout << "|      -REPORTE VENTAS POR CLIENTE-      |" << endl;
    cout << "|                                        |" << endl;
    cout << "|                                        |" << endl;
    cout << "|                OPCIONES                |" << endl;
    cout << "|                                        |" << endl;
    cout << "|    <1>   Ver.Clientes.Ced.             |" << endl;
    cout << "|    <2>   Regresar.                     |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    system("pause");
    return op;
}

int Interfaz::menuReportesPrincipal()
{
    int op;
    system("cls");
    cout << endl;
    cout << "______________________________________________________________________" << endl;
    cout << "|                    -GESTION REPORTES PRINCIPAL-                    |" << endl;
    cout << "|                                                                    |" << endl;
    cout << "|                                                                    |" << endl;
    cout << "|                                                                    |" << endl;
    cout << "|                            OPCIONES                                |" << endl;
    cout << "|    <1>  Reporte de todos los productos del minisuper.              |" << endl;
    cout << "|    <2>  Reporte solo productos por su categoria.                   |" << endl;
    cout << "|    <3>  Reporte productos por debajo de su minimo (Limite).        |" << endl;
    cout << "|    <4>  Reporte facturas de cliente especifico.                    |" << endl;
    cout << "|    <5>  Reporte 5 mejores clientes.                                |" << endl;
    cout << "|    <6>  Reporte Clientes Totales.                                  |" << endl;
    cout << "|    <7>  Regresar.                                                  |" << endl;
    cout << "|____________________________________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    return op;
}

void Interfaz::menuReportesProductos(Minisuper* mini){
    system("cls");
    cout << endl;
    cout << "------------PRODUCTOS MINISUPER----------" << endl;
    cout << mini->toStringListProd();
    system("pause");
}

int Interfaz::menuReportesProductosEspecificos(){
    int op;
    system("cls");
    cout << endl;
    cout << "______________________________________________________________________" << endl;
    cout << "|           -GESTION REPORTES PRODUCTO POR CATEGORIA-                |" << endl;
    cout << "|                                                                    |" << endl;
    cout << "|                                                                    |" << endl;
    cout << "|                            OPCIONES                                |" << endl;
    cout << "|    <1>  Reporte. Prod. Conserva.                                   | "<< endl;
    cout << "|    <2>  Reporte. Prod. Abarrote.                                   |" << endl;
    cout << "|    <3>  Reporte. Prod. Embutido.                                   |" << endl;
    cout << "|    <4>  Regresar.                                                  |" << endl;
    cout << "|____________________________________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    return op;
    system("pause");
}

void Interfaz::menuReportesProdConserva(Minisuper* mini){
    system("cls");
    cout << "_________________________________________" << endl;
    cout << "|     PRODUCTO LISTADOS DE CONSERVA     |" << endl;
    cout << "|_______________________________________|" << endl;
    Nodo <Producto>* tmp = mini->getProducto();
    while (tmp!=nullptr) {
        Conserva* con= dynamic_cast<Conserva*>(tmp->obtenerInfo());
        if (con!=nullptr) {
            cout << *tmp->obtenerInfo()<< endl;
        }
        tmp = tmp->obtenerSig();
    }
    system("pause");
}

void Interfaz::menuReportesProdAbarrote(Minisuper* mini){
    system("cls");
    cout << "_________________________________________" << endl;
    cout << "|     PRODUCTO LISTADOS DE ABARROTE     |" << endl;
    cout << "|_______________________________________|" << endl;
    Nodo <Producto>* tmp = mini->getProducto();
    while (tmp != nullptr) {
        Abarrote* con = dynamic_cast<Abarrote*>(tmp->obtenerInfo());
        if (con!= nullptr) {
            cout << *tmp->obtenerInfo() << endl;
        }
        tmp = tmp->obtenerSig();
    }
    system("pause");
}

void Interfaz::menuReportesProdEmbutido(Minisuper* mini){
    system("cls");
    cout << "_________________________________________" << endl;
    cout << "|     PRODUCTO LISTADOS DE EMBUTIDO     |" << endl;
    cout << "|_______________________________________|" << endl;
    Nodo <Producto>* tmp = mini->getProducto();
    while (tmp != nullptr) {
        Embutido* con = dynamic_cast<Embutido*>(tmp->obtenerInfo());
        if (con != nullptr) {
            cout << *tmp->obtenerInfo() << endl;
        }
        tmp = tmp->obtenerSig();
    }
    system("pause");
}
