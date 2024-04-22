#include "DecoradorEmbutido.h"
#include "Categoria.h"

DecoradorEmbutido::DecoradorEmbutido(ComponenteAbstracto* carro, Empaque* emp, Perecedero* ptrPer, string marca, string nombreAni, string partAni, string codi, string nombre, string desc, double pes, double prec, bool nac,int can)
{
	this->ptrCarrito = carro;
	this->ptrEmpaque = emp;
	this->ptrPer = ptrPer;
	this->marca = marca;
	this->nombreAnimal = nombreAni;
	this->parteDelAnimal = partAni;
	this->codigo = codi;
	this->nombreComercial = nombre;
	this->descripcion = desc;
	this->nacional = nac;
	this->peso = pes;
	this->precioCosto = prec;
	this->categoria = "3";
	this->cantidad = can;
}



DecoradorEmbutido::DecoradorEmbutido(const DecoradorEmbutido& copia)
{
	this->ptrCarrito = copia.ptrCarrito;
	this->ptrEmpaque = new Empaque(*copia.ptrEmpaque);
	this->ptrPer = new Perecedero(*copia.ptrPer);
	this->marca = copia.marca;
	this->nombreAnimal = copia.nombreAnimal;
	this->parteDelAnimal = copia.parteDelAnimal;
	this->codigo = copia.codigo;
	this->nombreComercial = copia.nombreComercial;
	this->descripcion = copia.descripcion;
	this->nacional = copia.nacional;
	this->peso = copia.peso;
	this->precioCosto = copia.precioCosto;
	this->categoria = copia.categoria;
	this->cantidad = copia.cantidad;
}
DecoradorEmbutido::~DecoradorEmbutido()
{
	if (ptrEmpaque) {
		delete ptrEmpaque;
	}
	if (ptrPer) {
		delete ptrPer;
	}
}

ComponenteAbstracto* DecoradorEmbutido::getSiguiente()
{
	return ptrCarrito;
}

void DecoradorEmbutido::setSiguiente(ComponenteAbstracto* carro)
{
	this->ptrCarrito = carro;
}

string DecoradorEmbutido::toString() const{
	stringstream s;
	s << "\t    " << this->cantidad << "\t\t   " << this->nombreComercial << "\t $" << this->precioCosto << "\t           $" << this->precioCosto * this->cantidad << "\n";
	s << *ptrCarrito;
	return s.str();
}

double DecoradorEmbutido::getTotal()
{
	Categoria c;
	return this->precioCosto * (c.porceganancia(categoria)/100) + ptrCarrito->getTotal();
}

double DecoradorEmbutido::getGanancia()
{
	Categoria c;
	return this->precioCosto * (c.porceganancia(categoria)) + ptrCarrito->getTotal();
}

double DecoradorEmbutido::getCantidad()
{
	return this->cantidad;
}

ComponenteAbstracto* DecoradorEmbutido::clonar() const
{
	return new DecoradorEmbutido(*this);
}

void DecoradorEmbutido::guardarComponenteAbstracto(ofstream& file)
{
	string nacio;
	if (this->nacional) {
		nacio = "Nacional";
	}
	else {
		nacio = "Internacional";
	}
	file << "Embutido" << '\t' << codigo << '\t' << nombreComercial << '\t' << descripcion<< '\t' << precioCosto << '\t' << peso << '\t' << nombreAnimal << '\t' << parteDelAnimal << '\t'<< marca << '\t'<< nacio << '\t' << cantidad << '\n';
	if (ptrCarrito != nullptr) {
		ptrCarrito->guardarComponenteAbstracto(file);
	}
	if (this->ptrPer != nullptr) {
		this->ptrPer->guardarPerecedero(file);
	}
	if (this->ptrEmpaque != nullptr) {
		this->ptrEmpaque->guardarEmpaque(file);
	}
}

DecoradorEmbutido* DecoradorEmbutido::leerDecoEmbutido(ifstream& file)
{
	string tipo, cantidadF, codigoF, nombreComercialF, descripcionF, precioCostoF, peso, nacion, nomAnimal,partAnimal,marc;
	bool env;
	double precioCost, pesoT;
	int cant;
	ComponenteAbstracto* car = NULL;
	Perecedero* pere = NULL;
	Empaque* empa = NULL;
	getline(file, codigoF, '\t');
	getline(file, nombreComercialF, '\t');
	getline(file, descripcionF, '\t');
	getline(file, precioCostoF, '\t');
	getline(file, peso, '\t');
	getline(file, nomAnimal, '\t');
	getline(file, partAnimal, '\t');
	getline(file, marc, '\t');
	getline(file, cantidadF, '\n');

	pere = Perecedero::leerPerecedero(file);
	empa = Empaque::leerEmpaque(file);
	precioCost = stod(precioCostoF);
	pesoT = stod(peso);
	cant = stoi(cantidadF);

	if (nacion == "Envasado") {
		env = true;
	}
	else {
		env = false;
	}

	getline(file, tipo, '\t');
	if (tipo == "Abarrote") {
		car =DecoradorAbarrote:: leerDecoAbarrote(file);
	}
	if (tipo == "Embutido") {
		car = leerDecoEmbutido(file);
	}
	if (tipo == "Conserva") {
		car = DecoradorConserva::leerDecoConserva(file);
	}
	if (tipo == "Carrito") {
		car = Carrito::leerCarrito(file);
	}
	return new DecoradorEmbutido(car, empa,pere,marc,nomAnimal,partAnimal, codigoF, nombreComercialF, descripcionF, pesoT, precioCost, env, cant);
}



ostream& operator<<(ostream& o, DecoradorEmbutido& p)
{
	o << p.toString() << endl;
	return o;
}

