#include "Minisuper.h"

Minisuper::Minisuper(){
	this->listPersona = new Lista<Persona>();
	this->listProducto = new Lista<Producto>();
	this->listVenta = new Lista<Venta>();

	/*leerClientes();*/
	leerProductos();
	/*leerVentas();*/
}

Minisuper::~Minisuper(){
	if (this->listPersona) {
		delete listPersona;
	}
	if (this->listProducto) {
		delete listProducto;
	}
	if (this->listVenta) {
		delete listVenta;
	}
}

void Minisuper::agregarPersona(Persona* p){
	this->listPersona->agregarFinal(p);
}

void Minisuper::agregarProducto(Producto* prd){
	this->listProducto->agregarFinal(prd);
}

void Minisuper::agregarVenta(Venta* vt){
	this->listVenta->agregarFinal(vt);
}

Nodo<Venta>* Minisuper::getFactura(string c)
{
	return listVenta->buscarElemento(c);
}

Nodo<Persona>* Minisuper::getCliente(string c)
{
	return this->listPersona->buscarElemento(c);
}

Nodo<Producto>* Minisuper::getProducto(string c)
{
	return this->listProducto->buscarElemento(c);
}

Nodo<Producto>* Minisuper::buscarProducto(string c){

	return this->listProducto->buscarElemento(c);
}

Producto* Minisuper::eliminarProductoEspecifico(string c)
{
	return this->listProducto->eliminarEspecifico(c);
}

Nodo<Producto>* Minisuper::getProducto()
{
	return this->listProducto->getPrimero();
}

Nodo<Venta>* Minisuper::getVenta()
{
	return this->listVenta->getPrimero();
}

Nodo<Persona>* Minisuper::getCliente()
{
	return this->listPersona->getPrimero();
}

int Minisuper::getSizeVenta()
{
	return this->listVenta->size();
}

int Minisuper::getSizePersona()
{
	return this->listPersona->size();
}

string Minisuper::toStringListProd()
{
	stringstream s;
	s << listProducto->toString();
	return s.str();
}

string Minisuper::toStringListClientes()
{
	stringstream s;
	s << listPersona->toString();
	return s.str();
}

void Minisuper::guardarClientes()
{
	Lista<Persona>* listaClient = listPersona->clonar();
	Nodo<Persona>* pAct = listaClient->getPrimero();
	ofstream file;
	file.open("../Clientes.txt", ios::out);
	if (file.good()) {
		while (pAct) {
			pAct->obtenerInfo()->guardarPersona(file);
			pAct = pAct->obtenerSig();
		}
		file.close();
	}
	else {
		cout << "Error al abrir el archivo" << endl;	
	}
}

void Minisuper::guardarProductos()
{
	Lista<Producto>* listaProd = listProducto->clonar();
	Nodo<Producto>* pAct = listaProd->getPrimero();
	ofstream file;
	file.open("../Productos.txt", ios::out);
	if (file.good()) {
		while (pAct) {
			pAct->obtenerInfo()->guardarProducto(file);
			pAct = pAct->obtenerSig();
		}
		file.close();
	}
	else {
		cout << "Error al abrir el archivo" << endl;
	}
}

void Minisuper::guardarVentas() {
	Lista<Venta>* listaVentas = listVenta->clonar();
	Nodo<Venta>* pAct = listaVentas->getPrimero();
	ofstream file;
	file.open("../Ventas.txt", ios::out);
	if (file.good()) {
		while (pAct) {
			pAct->obtenerInfo()->guardarVenta(file);
			pAct = pAct->obtenerSig();
		}
		file.close();
	}
	else {
		cout << "Error al abrir el archivo" << endl;
		system("pause");
	}
}

void Minisuper::leerClientes() {
	Nodo<Persona>* pAct = listPersona->getPrimero();
	ifstream file;
	file.open("../Clientes.txt", ios::in);
	if (file.good()) {
		while (!file.eof()) {
			Persona* p = Persona::leerPersona(file);
			if (p != nullptr) {
				agregarPersona(p);
			}
		}
		file.close();
	}
	else {
		cout << "Error al abrir el archivo" << endl;
		system("pause");
	}
}

void Minisuper::leerProductos() {
	Producto* prod = NULL;
	string tipo;
	ifstream file;
	file.open("../Productos.txt", ios::in);
	if (!file.is_open()) {
		cerr << "No se pudo abrir el archivo de productos." << endl;
		return;
	}

	if (file.good()) {
		while (!file.eof()) {
			getline(file, tipo, '\t');

			if (tipo == "Abarrote") {
				prod = Abarrote::leerAbarrote(file);
			}
			if (tipo == "Conserva") {
				prod = Conserva::leerConserva(file);
			}
			if (tipo == "Embutido") {
				prod = Embutido::leerEmbutido(file);
			}
			if (file.eof()) {
				break;
			}

			if (prod != NULL) {
				listProducto->agregarFinal(prod);
			}
		}
	}
	else {
		cout << "Error al abrir el archivo" << endl;
		system("pause");
	}
	file.close();
}

void Minisuper::leerVentas()
{
	Venta* venta = NULL;
	string tipo;
	ifstream file;
	file.open("../Ventas.txt", ios::in);
	if (file.good()) {
		while (!file.eof()) {
			file >> tipo;
			if (tipo == "Venta") {
				venta = Venta::leerVenta(file);
				if (venta != nullptr) {
					agregarVenta(venta);
				}
			}
		}
		file.close();
	}
	else {
		cout << "Error al abrir el archivo" << endl;
	}
	
}


