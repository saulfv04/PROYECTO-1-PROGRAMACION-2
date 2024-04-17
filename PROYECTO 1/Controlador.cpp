#include "Controlador.h"


Controlador::Controlador()
{
    this->minisuper = new Minisuper();

}

Controlador::~Controlador()
{
    if (this->minisuper) {
        delete minisuper;
    }
}

void Controlador::control0(){
    int op;
    do {
      op=  controlmenuPrincipal();
    switch (op){
    case 1:
        this->control1();
        break;
    case 2:
        this->control2();
        break;
    case 3:
        this->control3();
        break;
    case 4:
        cout << "Gracias por su visita" << endl;
        break;
    default:
        cout <<"Opcion no disponible" << endl;
        break;
    }
    } while (op != 4);
}

void Controlador::control1()
{
    int op;
    do {
      op= controlMantenimientos();
        switch (op) {
        case 1:
            this->control1_1();
            break;
        case 2:
            this->control1_2();
            break;
        case 3:
            this->control4();
            break;
        case 4:
            this->control0();
            break;
        default:
            cout << "Opcion no disponible" << endl;
            break;
        }
    } while (op != 4);
}

void Controlador::control2()
{
    int op;
    do {
        op = controlCreancionVentas();
        switch (op) {
        case 1:
            control2_1();
            break;
        case 2:
            cout << "Regresando..." << endl;
            break;
        }
    } while (op != 2);
}

void Controlador::control3(){
    int op;
    do {
        op= controlReport();
        switch (op) {
        case 1:
            control3_1();
            break;
        case 2:
            control3_2();
            break;
        case 3:
            control3_3();
            break;
        case 4:
            control3_4();
            break;
        case 5:
            control3_5();
            break;
        case 6:
            control3_6();
            break;
        case 7:
            cout << "Regresando..." << endl;
            break;
        default:
            cout << "Opcion no disponible" << endl;
            break;
        }
    } while (op != 7);
}

void Controlador::control4()
{
    int person;
    do {
        person= controlMntIngresoClientes();
        switch (person) {
        case 1:
            this->control4_1();
            break;
        case 2:
            cout << "Regresando..." << endl;
            break;
        default:
            cout << "Opcion no disponible" << endl;
            break;
        }
    } while (person != 2);
}

void Controlador::control1_1(){
    int op;
    do {
       op= controlMantenimientoFacturas();
        switch (op) {
        case 1:
            this->control1_1_1();
            break;
        case 2:
            cout << "Regresando..." << endl;
        default:
            cout << "Opcion no disponible" << endl;
            break;
        }
    } while (op != 2);
}

void Controlador::control1_1_1()
{
    Interfaz::menuFacturas(minisuper);
}

void Controlador::control1_2()
{
    int op;
    do {
        op= controlMantemientoProductos();
        switch (op) {
        case 1:
            this->control1_2_1();
            break;
        case 2:
            this->control1_2_2();
            break;
        case 3:
            this->control1_2_3();
            break;
        case 4:
            cout << "Regresando..." << endl;
            break;
        default:
            cout << "Opcion no disponible" << endl;
            break;
        }
    } while (op != 4);

}

void Controlador::control1_2_1(){
    int type;
    do {
        type= controlMntIngresoProductos();
        switch (type) {
        case 1:
            control1_2_1_1();
            break;
        case 2:
            control1_2_1_2();
            break;
        case 3:
            control1_2_1_3();
            break;
        case 4:
            cout << "Regresando..." << endl;
            break;
        default:
            cout << "Opcion no disponible" << endl;
            break;
        }
    } while (type != 4);
}

void Controlador::control1_2_1_1(){
    Interfaz::agregarProductoConserva(minisuper);
}

void Controlador::control1_2_1_2(){
    Interfaz::agregarProductoEmbutido(minisuper);
}

void Controlador::control1_2_1_3(){
    Interfaz::agregarProductoAbarrote(minisuper);
}

void Controlador::control1_2_2(){
    int op;
   do{
       op = controlMntEliminarProducto();
    switch (op){
    case 1:
        control1_2_2_2();
        break;
    case 2:
        cout << "Regresando..." << endl;
        break;
    }
    }while (op != 2);
}

void Controlador::control1_2_2_2(){
    Interfaz::Eliminacion(minisuper);
}

void Controlador::control1_2_3()
{
    int op;
    do {
        op = contrlMntModificacionProducto();
        switch (op) {
        case 1:
            control1_2_3_1();
            break;
        case 2:
            cout << "Regresando..." << endl;
            break;
        }
    } while (op != 2);
}

void Controlador::control1_2_3_1()
{
    Interfaz::mantModifProd(minisuper);
}

void Controlador::control2_1()
{
    Interfaz::crearVenta(minisuper);
}

void Controlador::control3_1()
{
    Interfaz::menuReportesProductos(minisuper);
}

void Controlador::control3_2()
{
    int opC;
    do {
        opC = controlReportProductoCategoria();
        switch (opC) {
        case 1:
            control3_2_1();
            break;
        case 2:
            control3_2_2();
            break;
        case 3:
            control3_2_3();
            break;
        case 4:
            cout << "Regresando..." << endl;
            break;
        default:
            cout << "Opcion no disponible" << endl;
            break;
        }
    } while (opC != 4);
}

void Controlador::control3_2_1(){
    Interfaz::menuReportesProdConserva(minisuper);
}

void Controlador::control3_2_2(){
    Interfaz::menuReportesProdAbarrote(minisuper);
}

void Controlador::control3_2_3(){
    Interfaz::menuReportesProdEmbutido(minisuper);
}

void Controlador::control3_3()
{
    int opC;
    do {
        opC = controlReportEscasezProducto();
        switch (opC) {
        case 1:
            control3_3_1();
            break;
        case 2:
            cout << "Regresando..." << endl;
            break;
        default:
            cout << "Opcion no disponible" << endl;
            break;
        }
    } while (opC != 2);
}

void Controlador::control3_3_1()
{
    Interfaz::reportProdEscasoz(minisuper);
}

void Controlador::control3_5()
{
}

void Controlador::control3_6()
{
    int opC;
    do {
        opC = controlReportClientes();
        switch (opC) {
        case 1:
            control3_6_1();
            break;
        case 2:
            cout << "Regresando..." << endl;
            break;
        default:
            cout << "Opcion no disponible" << endl;
            break;
        }
    } while (opC != 2);
}

void Controlador::control3_6_1()
{
    Interfaz::ReporteClientes(minisuper);
}

void Controlador::control3_4()
{
    int opC;
    do {
        opC = controlReportVentasClienteEspecifico();
        switch (opC) {
        case 1:
            control3_4_1();
            break;
        case 2:
            cout << "Regresando..." << endl;
            break;
        default:
            cout << "Opcion no disponible" << endl;
            break;
        }
    } while (opC != 2);
}

void Controlador::control3_4_1()
{
    Interfaz::ReporteClienteEspecifico(minisuper);
}

void Controlador::control4_1()
{
    Interfaz::menuMantAgregarClientes(minisuper);
}

int Controlador::controlmenuPrincipal()
{
    return Interfaz::menuPrincipalOp();
}

int Controlador::controlMantenimientos()
{
    return Interfaz::menuMantenimiento();
}

int Controlador::controlMantenimientoFacturas()
{
    return Interfaz::menuMantenimientoVentas();
}



int Controlador::controlMantemientoProductos()
{
    return Interfaz::menuMantenimientoProductos();
}

int Controlador::controlMntIngresoProductos()
{
    return Interfaz::menuMantIngresoProductos();
}

int Controlador::controlMntEliminarProducto()
{
    return Interfaz::menuEliminarProducto();
}

int Controlador::contrlMntModificacionProducto()
{
    return Interfaz::menuMantModifProd(); ;
}

int Controlador::controlMntIngresoClientes()
{
    return Interfaz::menuMantClientes();
}

int Controlador::controlReportClientes()
{
    return Interfaz::menuReporteClientes();
}

int Controlador::controlReportVentasClienteEspecifico()
{
    return Interfaz::menuReportesClienteEspecifico();
}

int Controlador::controlCreancionVentas()
{
    return Interfaz::menuCreacionVentas();
}

int Controlador::controlReport()
{
    return Interfaz::menuReportesPrincipal();
}

int Controlador::controlReportEscasezProducto()
{
    return Interfaz::menuReportProdMinimo();
}

int Controlador::controlReportProductoCategoria()
{
    return Interfaz::menuReportesProductosEspecificos();
}
