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
            cout << "Regresando..." << endl;
            break;
        default:
            cout << "Opcion no disponible" << endl;
            break;
        }
    } while (op != 6);
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

void Controlador::control1_1()
{
    int op;
    do {
       op= controlMantenimientoFacturas();
        switch (op) {
        case 1:
            this->control1_1_1();
            break;
        case 2:
            cout << "Regresando..." << endl;
            this->control1();
        default:
            cout << "Opcion no disponible" << endl;
            break;
        }
    } while (op != 2);
}

void Controlador::control1_1_1()
{
    string op = controlRetornoFacturas();
    if (this->minisuper->getFactura(op) != nullptr) {
        cout << "Factura encontrada" << endl;
    }
    else {
        cout << "Ninguna venta asociada al codigo proporcionado" << endl;
    }
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
            system("pause");
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
     op=  Interfaz::menuEliminarProducto();
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
}

void Controlador::control2_1()
{
}

void Controlador::control3_1()
{
    Interfaz::menuReportesProductos(minisuper);
}

void Controlador::control3_2()
{
}

void Controlador::control3_3()
{
}

void Controlador::control3_4()
{
}

void Controlador::control3_5()
{
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

string Controlador::controlRetornoFacturas()
{
    return Interfaz::retornoFacturas();
}

int Controlador::controlMantemientoProductos()
{
    return Interfaz::menuMantenimientoProductos();
}

int Controlador::controlMntIngresoProductos()
{
    return Interfaz::menuMantIngresoProductos();
}

int Controlador::controlMntIngresoClientes()
{
    return Interfaz::menuMantClientes();
}

int Controlador::controlReport()
{
    return Interfaz::menuReportesPrincipal();
}
