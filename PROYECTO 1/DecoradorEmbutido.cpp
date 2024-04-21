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



ostream& operator<<(ostream& o, DecoradorEmbutido& p)
{
	o << p.toString() << endl;
	return o;
}

