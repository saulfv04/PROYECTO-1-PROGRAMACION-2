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
    cout << "|    (1)  Mantenimiento.                        |" << endl;
    cout << "|    (2)  Ventas.                               |" << endl;
    cout << "|    (3)  Reportes.                             |" << endl;
    cout << "|    (4)  Salir.                                |" << endl;
    cout << "|_______________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
        throw string("Se ha digitado un caracter invalido");
    }
    if (op > 4) {
        throw ERS(op,4,1);
    }
    if (op < 1) {
        throw ERI(op, 4, 1);
    }
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
    cout << "|    (1)  Mnt.Facturas.                         |" << endl;
    cout << "|    (2)  Mnt.Productos.                        |" << endl;
    cout << "|    (3)  Clientes.                             |" << endl;
    cout << "|    (4)  Regresar.                             |" << endl;
    cout << "|_______________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
        throw string("Se ha digitado un caracter invalido");
    }
    if (op > 4) {
        throw ERS(op, 4, 1);
    }
    if (op < 1) {
        throw ERI(op, 4, 1);
    }
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
    cout << "|    (1)  Buscar Factura.                       |" << endl;
    cout << "|    (2)  Regresar.                             |" << endl;
    cout << "|_______________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
        throw string("Se ha digitado un caracter invalido");
    }
    if (op > 2) {
        throw ERS(op, 2, 1);
    }
    if (op < 1) {
        throw ERI(op, 2, 1);
    }
    return op;
}

void Interfaz::menuFacturas(Minisuper* mini){
    string op;
    system("cls");
    cout << endl;
    cout << "___________________________________________________________" << endl;
    cout << "|           -Digite el numero de factura deseado-         |" << endl;
    cout << "|_________________________________________________________|" << endl;
    cin >> op;
    Nodo < Venta >* pAct = mini->getFactura(op);
    if (pAct != nullptr) {
        Venta* facturaBuscada = pAct->obtenerInfo();
        cout << "____________________" << endl;
        cout << "|Factura encontrada|" << endl;
        cout << "|__________________|" << endl << endl;
        cout << *facturaBuscada << endl;
    }
    else {
        cout << "________________________________________________" << endl;
        cout << "|Ninguna venta asociada al codigo proporcionado|" << endl;
        cout << "|______________________________________________|" << endl;
    }
    system("pause");
}
int Interfaz::menuMantenimientoProductos()
{
    int op;
    system("cls");
    cout << endl;
    cout << "_________________________________________________" << endl;
    cout << "|             -GESTION DE PRODUCTOS-            |" << endl;
    cout << "|                                               |" << endl;
    cout << "|                                               |" << endl;
    cout << "|                OPCIONES                       |" << endl;
    cout << "|    (1)  Ingresar Producto.                    |" << endl;
    cout << "|    (2)  Eliminar Producto.                    |" << endl;
    cout << "|    (3)  Modificar Producto.                   |" << endl;
    cout << "|    (4)  Regresar.                             |" << endl;
    cout << "|_______________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
        throw string("Se ha digitado un caracter invalido");
    }
    if (op > 4) {
        throw ERS(op, 4, 1);
    }
    if (op < 1) {
        throw ERI(op, 4, 1);
    }
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
    cout << "|    (1)  Prod.Conserva.                        |" << endl;
    cout << "|    (2)  Prod.Embutido.                        |" << endl;
    cout << "|    (3)  Prod.Abarrote.                        |" << endl;
    cout << "|    (4)  Regresar.                             |" << endl;
    cout << "|_______________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
        throw string("Se ha digitado un caracter invalido");
    }
    if (op > 4) {
        throw ERS(op, 4, 1);
    }
    if (op < 1) {
        throw ERI(op, 4, 1);
    }
    system("pause");
    return op;
}


void Interfaz::agregarProductoConserva(Minisuper* mini){
    Producto* c = new Conserva();
    cin >> *c;
    if (mini->getProducto(c->getCodigo())==nullptr) {
    mini->agregarProducto(c);
    cout << "__________________________________" << endl;
    cout << "|Producto tipo Conserva ingresado|" << endl;
    cout << "|________________________________|" << endl;
    }
    else {
        cout << "_________________________________________" << endl;
        cout << "| El Producto esta ingresado actualmente|" << endl;
        cout << "|_______________________________________|" << endl;
        delete c;
    }
    system("pause");
}

void Interfaz::agregarProductoEmbutido(Minisuper* mini){
    Producto* c = new Embutido();
    cin >> *c;
    if (mini->getProducto(c->getCodigo()) == nullptr) {
    cout << "__________________________________" << endl;
    cout << "|Producto tipo Embutido ingresado|" << endl;
    cout << "|________________________________|" << endl;
    mini->agregarProducto(c);
    }
    else {
        cout << "_________________________________________" << endl;
        cout << "| El Producto esta ingresado actualmente|" << endl;
        cout << "|_______________________________________|" << endl;
        delete c;
    }
    system("pause");
}

void Interfaz::agregarProductoAbarrote(Minisuper* mini){
    Producto* c = new Abarrote();
    cin >> *c;
    if (mini->getProducto(c->getCodigo()) == nullptr) {
    cout << "__________________________________" << endl;
    cout << "|Producto tipo Abarrote ingresado|" << endl;
    cout << "|________________________________|" << endl;
    mini->agregarProducto(c);
    }
    else {
        cout << "_________________________________________" << endl;
        cout << "| El Producto esta ingresado actualmente|" << endl;
        cout << "|_______________________________________|" << endl;
        delete c;
    }
    system("pause");
}

int Interfaz::menuMantModifProd()
{
    int op;
    system("cls");
    cout << endl;
    cout << "_________________________________________________" << endl;
    cout << "|       -GESTION MODIFICACION DE PRODUCTO-      |" << endl;
    cout << "|                                               |" << endl;
    cout << "|                    OPCIONES                   |" << endl;
    cout << "|    (1)  Modificiar.Prod.                      |" << endl;
    cout << "|    (2)  Regresar.                             |" << endl;
    cout << "|_______________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
        throw string("Se ha digitado un caracter invalido");
    }
    if (op > 2) {
        throw ERS(op, 2, 1);
    }
    if (op < 1) {
        throw ERI(op, 2, 1);
    }
    system("pause");
    return op;
}

void Interfaz::mantModifProd(Minisuper* mini)
{
    string prod,descrip,nombreC;
    int opModificacion,p;
    double precio;
    cout << "____________________________________________" << endl;
    cout << "Ingresar el codigo de producto a modificar:";
    cin >> prod;
    Nodo <Producto>* aux = mini->buscarProducto(prod);
    if (aux!=nullptr) {
        Producto* modificar = aux->obtenerInfo();
        do {
            opModificacion = menuOpcionesModificicado();
            cout << "-Producto a modificar-" << endl;
            cout << *modificar;
        switch (opModificacion)
        {
        case 1:
            cout << "____________________________________________" << endl;
            cout << "Ingresar nuevo nombre para producto:";
            cin >> nombreC;
            modificar->setnombreComercial(nombreC);
            break;
        case 2:
            cout << "____________________________________________" << endl;
            cout << "Ingresar nueva descripcion para producto:";
            cin >> descrip;
            modificar->setDescripcion(descrip);
            break;
        case 3:
            cout << "____________________________________________" << endl;
            cout << "Ingresar nuevo precio producto:";
            cin >> precio;
            modificar->setprecioCosto(precio);
            break;
        case 4:
            cout << "____________________________________________" << endl;
            cout << "Ingresar nueva cantidad de existencia del producto:";
            cin >> p;
            modificar->setExistencia(p);
            break;
        case 5:
            cout << "____________________________________________" << endl;
            cout << "Ingresar nuevo limite del producto:";
            cin >> p;
            modificar->setLimite(p);
            break;
        case 6:
            cout << "Regresando...";
            break;
        default:
            break;
        }
        } while (opModificacion!=6);
    }
    else {
        cout << "El producto a modificar no existe en nuestro almacen actual" << endl;
    }
    system("pause");
}

int Interfaz::menuOpcionesModificicado()
{
    int op;
    system("cls");
    cout << endl;
    cout << "_________________________________________________" << endl;
    cout << "|       -OPCIONES  MODIFICADO  PRODUCTO-        |" << endl;
    cout << "|                                               |" << endl;
    cout << "|                    OPCIONES                   |" << endl;
    cout << "|    (1)  Nombre comecial.                      |" << endl;
    cout << "|    (2)  Descripcion.                          |" << endl;
    cout << "|    (3)  Precio Costo.                         |" << endl;
    cout << "|    (4)  Existencia.                           |" << endl;
    cout << "|    (5)  Limite.                               |" << endl;
    cout << "|    (6)  Terminar Modificacion.                |" << endl;
    cout << "|_______________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
        throw string("Se ha digitado un caracter invalido");
    }
    if (op > 6) {
        throw ERS(op, 6, 1);
    }
    if (op < 1) {
        throw ERI(op, 6, 1);
    }
    return op;
    system("pause");
}

int Interfaz::menuEliminarProducto(){
    int op;
    system("cls");
    cout << endl;
    cout << "_________________________________________________" << endl;
    cout << "|         -GESTION ELIMINACION PRODUCTO-        |" << endl;
    cout << "|                                               |" << endl;
    cout << "|                    OPCIONES                   |" << endl;
    cout << "|    (1)  Eliminar.Prod.                        |" << endl;
    cout << "|    (2)  Regresar.                             |" << endl;
    cout << "|_______________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
        throw string("Se ha digitado un caracter invalido");
    }
    if (op > 2) {
        throw ERS(op, 2, 1);
    }
    if (op < 1) {
        throw ERI(op, 2, 1);
    }
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
    cout << "|    (1)   Cod.Producto.                 |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "Digite la opcion: ";    
    cin >> op;
    Producto* aux = mini->eliminarProductoEspecifico(op);
    if (aux!=nullptr) {
        cout <<"_____________________" << endl;
        cout <<"|Producto Encontrado|" << endl;
        cout <<"|___________________|" << endl;
        cout << "El produto encontrado es el deseado..." << endl;
        cout << *aux;
        cout << "Desea borrar el producto de forma definitiva... " << endl << endl;
        cout << "         (S)BORRAR          (N)Conservar        "<< endl;
        cout << "Digite la opcion : ";
        cin >> borrado;
        if (borrado=="S"||borrado=="s") {
            system("pause");
            cout << "PRODUCTO BORRADO CON EXITO..." << endl;
        }
        else {
            mini->agregarProducto(aux);
            system("pause");
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
    cout << "|    (1)  Agregar.Clientes.                         |" << endl;
    cout << "|    (2)  Regresar.                                 |" << endl;
    cout << "|___________________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
        throw string("Se ha digitado un caracter invalido");
    }
    if (op > 2) {
        throw ERS(op, 2, 1);
    }
    if (op < 1) {
        throw ERI(op, 2, 1);
    }
    return op;
    system("pause");
}

void Interfaz::menuMantAgregarClientes(Minisuper* mini)
{
    Persona* p = new Persona();
    cin >> *p;
    if (mini->getCliente(p->getCodigo())==nullptr) {
    mini->agregarPersona(p);
    cout << "Cliente ingresada..." << endl;
    }
    else {
        cout << "El cliente ya existe en nuestro sistema actual..." << endl;
        delete p;
    }
    system("pause");
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
    cout << "|    (1)   Ver.Clientes.                 |" << endl;
    cout << "|    (2)   Regresar.                     |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
        throw string("Se ha digitado un caracter invalido");
    }
    if (op > 2) {
        throw ERS(op, 2, 1);
    }
    if (op < 1) {
        throw ERI(op, 2, 1);
    }
    system("pause");
    return op;
}

void Interfaz::ReporteClientes(Minisuper* mini){
    system("cls");
    cout << "__________________________________________" << endl;
    cout << "|          -CLIENTES MINISUPER-          |" << endl;
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
    cout << "Digite el cliente: ";
    cin >> cedula;
    while (pAct) {
        if (pAct->obtenerInfo()->getPersona() == cedula) {
            cout << *pAct->obtenerInfo() << endl;
        }
        pAct = pAct->obtenerSig();
    }
    system("pause");
}
int Interfaz::menuReportesTopClientes()
{
    int op;
    system("cls");
    cout << endl;
    cout << "__________________________________________" << endl;
    cout << "|         -TOP CLIENTES POR VENTAS-      |" << endl;
    cout << "|                                        |" << endl;
    cout << "|                                        |" << endl;
    cout << "|                OPCIONES                |" << endl;
    cout << "|                                        |" << endl;
    cout << "|    (1)   Top.Clientes.                 |" << endl;
    cout << "|    (2)   Regresar.                     |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
        throw string("Se ha digitado un caracter invalido");
    }
    if (op > 2) {
        throw ERS(op, 2, 1);
    }
    if (op < 1) {
        throw ERI(op, 2, 1);
    }
    system("pause");
    return op;
}
void Interfaz::reporteTopClientes(Minisuper* mini) {
    system("cls");
    Lista<Persona> *listaClientes = new Lista<Persona>();
    Nodo <Persona>* pAct = mini->getCliente();
    while (pAct) {
		listaClientes->agregarFinal(pAct->obtenerInfo()->clonar());
		pAct = pAct->obtenerSig();
	}
    if (listaClientes->getPrimero() == nullptr || listaClientes->getPrimero()->obtenerSig() == nullptr) {
        cout<<"Lista esta vacia"<<endl;
    }

    bool intercambio;
    do {
        intercambio = false;
        Nodo<Persona>* actual = listaClientes->getPrimero();
        while (actual->obtenerSig() != nullptr) {
            if (actual->obtenerInfo()->getCantVentas() < actual->obtenerSig()->obtenerInfo()->getCantVentas()) {
                // Intercambiar las personas
                Persona temp = *actual->obtenerInfo();
                *actual->obtenerInfo() = *actual->obtenerSig()->obtenerInfo();
                *actual->obtenerSig()->obtenerInfo() = temp;
                intercambio = true;
            }
            actual = actual->obtenerSig();
        }
    } while (intercambio);

    if (listaClientes->size() < 5) {
		cout << "No hay suficientes clientes para mostrar el top 5" << endl;
		return;
	}

    Nodo<Persona>* actual = listaClientes->getPrimero();
    int i = 0;
    while (actual && i < 5) {
		cout << *actual->obtenerInfo() << endl;
		actual = actual->obtenerSig();
		i++;
	}
    delete listaClientes;
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
    cout << "|    (1)   Crear Venta.                  |" << endl;
    cout << "|    (2)   Regresar.                     |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
        throw string("Se ha digitado un caracter invalido");
    }
    if (op > 2) {
        throw ERS(op, 2, 1);
    }
    if (op < 1) {
        throw ERI(op, 2, 1);
    }
    system("pause");
    return op;
}
void Interfaz::agregarProductoVenta(Minisuper* mini)
{
    ComponenteAbstracto* carrito = new Carrito();
    Venta* ventaNueva = new Venta();
    string persona, continuar;
    string codVenta;
    Fecha* fNueva = new Fecha();
    system("cls");
    cout << endl;
    cout << "_____________________________" << endl;
    cout << "|       -CODIGO VENTA-      |" << endl;
    cout << "|___________________________|" << endl;
    cout << "Digite el codigo de la venta actual: ";
    cin >> codVenta;
    if (mini->getFactura(codVenta)==nullptr) {
    cout << "____________________________" << endl;
    cout << "|       -FECHA VENTA-      |" << endl;
    cout << "|__________________________|" << endl;
    cout << "Digite Fecha de venta: ";
    cin >> *fNueva;
    cout << "__________________________________________" << endl;
    cout << "|       -VENTAS CLIENTE ESPECIFICO-      |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "Digite el cliente: ";
    cin >> persona;
    Nodo <Persona>* personaVenta = mini->getCliente(persona);
    if (personaVenta != nullptr) {
        do {
            carrito = crearVenta(mini, *carrito);
            system("pause");
            cout<<"Desea agregar otro producto al carrito (S)SI  (N)NO"<<endl;
            cin>>continuar;
        } while(continuar == "S" || continuar == "s");
        cout << endl;
        ventaNueva->setCliente(persona);
        ventaNueva->setFecha(fNueva);
        ventaNueva->setCodigo(codVenta);
        personaVenta->obtenerInfo()->setCantidadVentas(personaVenta->obtenerInfo()->getCantVentas() + 1);
        ProductoDecorador* pd = dynamic_cast<ProductoDecorador*>(carrito);
        if (pd!=nullptr) {
            ventaNueva->setCarrito(pd);
            cout << *ventaNueva;
            mini->agregarVenta(ventaNueva);
        }
        else {
            cout << "Su carrito no pudo generarse..." << endl;
            delete ventaNueva;
            delete pd;
        }
	}
    else {

	}
    }
    else {
        cout << "Codigo de factura existente..." << endl;
    }
    system("pause");
}
ComponenteAbstracto* Interfaz::crearVenta(Minisuper* mini, ComponenteAbstracto& c)
{
    string codProd, continuar;
    double cant;
    Nodo <Producto>* productoIngresado; 
      cout << "_______________________________________" << endl;
      cout << "|       -COD PRODUCTO A COMPRAR-      |" << endl;
      cout << "|_____________________________________|" << endl;
      cout << "Digite el codigo: ";
      cin >> codProd;
      productoIngresado = mini->buscarProducto(codProd);
      if (productoIngresado == NULL) {
         cout<<"Producto no existe en el minisuper..." << endl;
         return &c;
      }
      if (productoIngresado->obtenerInfo()->getExistencia() <= 0) {
         cout << "Producto sin existencia en el minisuper..." << endl;
         return &c;
      }
      if (productoIngresado !=nullptr) {
          cout << "__________________________________________" << endl;
          cout << "|       -CANTIDAD QUE QUIERE COMPRAR-    |" << endl;
          cout << "|________________________________________|" << endl;
          cout << "Digite la cantidad del procucto que quiere comprar: ";
          cin >> cant;
            Abarrote* aba = dynamic_cast<Abarrote*>(productoIngresado->obtenerInfo());
            Embutido* emb = dynamic_cast<Embutido*>(productoIngresado->obtenerInfo());
            Conserva* con = dynamic_cast<Conserva*>(productoIngresado->obtenerInfo());
            if (aba!=nullptr) {
                if (mini->buscarProducto(codProd)->obtenerInfo()->getLimite() < cant) {
					cout << "No puede comprar: "<<cant <<" productos, ya que el limite de compra es: "<<mini->buscarProducto(codProd)->obtenerInfo()->getLimite()<< endl;
					return &c;
				}
                if (mini->buscarProducto(codProd)->obtenerInfo()->getExistencia() < cant) {
					cout << "No hay suficiente existencia para la cantidad solicitada..." << endl;
					return &c;
				}
                mini->buscarProducto(codProd)->obtenerInfo()->setExistencia(mini->buscarProducto(codProd)->obtenerInfo()->getExistencia()-cant);
                return new DecoradorAbarrote(&c, aba->getPer(), aba->getEmpresaNombre(), aba->getCodigo(), aba->getnombreComecial(), aba->getDescripcion(), aba->getNacional(), aba->getPeso(), aba->getprecioCosto(),cant);
            }
            else if(emb!=nullptr) {
                if (mini->buscarProducto(codProd)->obtenerInfo()->getLimite() < cant) {
                    cout << "No puede comprar: " << cant << " productos, ya que el limite de compra es: " << mini->buscarProducto(codProd)->obtenerInfo()->getLimite() << endl;
                    return &c;
                }
                if (mini->buscarProducto(codProd)->obtenerInfo()->getExistencia() < cant) {
                    cout << "No hay suficiente existencia para la cantidad solicitada..." << endl;
                    return &c;
                }
                mini->buscarProducto(codProd)->obtenerInfo()->setExistencia(mini->buscarProducto(codProd)->obtenerInfo()->getExistencia() - cant);
                return new DecoradorEmbutido(&c,emb->getEmaqueptr(), emb->getPer(), emb->getMarca(), emb->getNombreAnimal(), emb->getparteDelAnimal(), emb->getCodigo(), emb->getnombreComecial(), emb->getDescripcion(), emb->getPeso(), emb->getprecioCosto(),emb->getNacional(),cant);
            }
            else {
                if (mini->buscarProducto(codProd)->obtenerInfo()->getLimite() < cant) {
                    cout << "No puede comprar: " << cant << " productos, ya que el limite de compra es: " << mini->buscarProducto(codProd)->obtenerInfo()->getLimite() << endl;
                    return &c;
                }
                if (mini->buscarProducto(codProd)->obtenerInfo()->getExistencia() < cant) {
                    cout << "No hay suficiente existencia para la cantidad solicitada..." << endl;
                    return &c;
                }
                mini->buscarProducto(codProd)->obtenerInfo()->setExistencia(mini->buscarProducto(codProd)->obtenerInfo()->getExistencia() - cant);
                return new DecoradorConserva(&c, con->getnombreComecial(), con->getCodigo(), con->getDescripcion(), con->getprecioCosto(), con->getEnvasado(),cant);
            }
       }
      else {
         cout << "Producto no existe" << endl;
      }
      system("cls");
      cout << "Desea continuar su venta (S)SI  (N)NO" << endl;
      cin >> continuar;
      return &c;
      system("pause");
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
    cout << "|    (1)   Ver.Clientes.Ced.             |" << endl;
    cout << "|    (2)   Regresar.                     |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
        throw string("Se ha digitado un caracter invalido");
    }
    if (op > 2) {
        throw ERS(op, 2, 1);
    }
    if (op < 1) {
        throw ERI(op, 2, 1);
    }
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
    cout << "|                            OPCIONES                                |" << endl;
    cout << "|    (1) Reporte de todos los productos del minisuper.               |" << endl;
    cout << "|    (2)  Reporte solo productos por su categoria.                   |" << endl;
    cout << "|    (3)  Reporte productos por debajo de su minimo (Limite).        |" << endl;
    cout << "|    (4)  Reporte facturas de cliente especifico.                    |" << endl;
    cout << "|    (5)  Reporte 5 mejores clientes.                                |" << endl;
    cout << "|    (6)  Reporte Clientes Totales.                                  |" << endl;
    cout << "|    (7)  Regresar.                                                  |" << endl;
    cout << "|____________________________________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
        throw string("Se ha digitado un caracter invalido");
    }
    if (op > 7) {
        throw ERS(op, 7, 1);
    }
    if (op < 1) {
        throw ERI(op, 7, 1);
    }
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
    cout << "|    (1)  Reporte. Prod. Conserva.                                   | "<< endl;
    cout << "|    (2)  Reporte. Prod. Abarrote.                                   |" << endl;
    cout << "|    (3)  Reporte. Prod. Embutido.                                   |" << endl;
    cout << "|    (4)  Regresar.                                                  |" << endl;
    cout << "|____________________________________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
        throw string("Se ha digitado un caracter invalido");
    }
    if (op > 4) {
        throw ERS(op, 4, 1);
    }
    if (op < 1) {
        throw ERI(op, 4, 1);
    }
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

int Interfaz::menuReportProdMinimo()
{
    int op;
    system("cls");
    cout << endl;
    cout << "____________________________________________________________________________" << endl;
    cout << "|    -REPORTE DE PRODUCTOS POR DEBAJO DE SU MINIMO (LIMITE EXISTENCIA)-    |" << endl;
    cout << "|                                                                          |" << endl;
    cout << "|                                                                          |" << endl;
    cout << "|                            OPCIONES                                      |" << endl;
    cout << "|    (1)  Reporte. Productos.                                              | " << endl;
    cout << "|    (2)  Regresar.                                                        |" << endl;
    cout << "|__________________________________________________________________________|" << endl;
    cout << "Digite la opcion: ";
    cin >> op;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1);
        throw string("Se ha digitado un caracter invalido");
    }
    if (op > 2) {
        throw ERS(op, 2, 1);
    }
    if (op < 1) {
        throw ERI(op, 2, 1);
    }
    return op;
}

void Interfaz::reportProdEscasoz(Minisuper* mini)
{
    Nodo <Producto>* pAct = mini->getProducto();
    cout << "_______________________________" << endl;
    cout << "|PRODUCTOS CON BAJA EXISTENCIA|" << endl;
    cout << "|_____________________________|" << endl;
    while (pAct) {
        if (pAct->obtenerInfo()->getLimite() > pAct->obtenerInfo()->getExistencia()) {
            cout << *pAct->obtenerInfo();
        }
        pAct = pAct->obtenerSig();
    }
    system("pause");
}
