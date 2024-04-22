#include "Venta.h"
#include "ProductoDecorador.h"
#include "DecoradorAbarrote.h"
#include "DecoradorEmbutido.h"
#include "DecoradorConserva.h"

Venta::Venta(ProductoDecorador* carr, string per, Fecha* f, string cod) :carrito(carr), cedulaCliente(per), fVenta(f), codigo(cod){}



Venta::Venta()
{
    this->carrito = nullptr;
    this->codigo = "i";
    this->cedulaCliente = "i";
    this->fVenta = nullptr;
}

Venta::Venta(const Venta& ven) {

    this->carrito = static_cast<ProductoDecorador*>(ven.carrito->clonar());
    this->cedulaCliente = ven.cedulaCliente;
	codigo = ven.codigo;
    fVenta = new Fecha(*ven.fVenta);
}

Venta::~Venta()
{
    if (carrito) {
        delete carrito;
    }
}
ComponenteAbstracto* Venta::getCarrito(){
    return this->carrito;
}

Fecha* Venta::getFecha()
{
    return this->fVenta;
}

void Venta::setCarrito(ProductoDecorador* c)
{
	carrito = c;
}

string Venta::getCodigo()const {
    return this->codigo;
}

string Venta::getPersona()
{
    return this->cedulaCliente;
}



void Venta::setFecha(Fecha* f)
{
    fVenta = f;
}
void Venta::setCodigo(string c)
{
    this->codigo = c;
}
void Venta::setCliente(string c)
{
    this->cedulaCliente = c;
}


string Venta::toString()const{
    stringstream s;
    s << "================================================================================\n";
    s << "\t\t\tFACTURA: " << this->codigo << "\n";
    s << "\t\t\tCLIENTE: " << this->cedulaCliente << "\n";
    s << "\t\t\t"<< *fVenta << "\n";
    s << "================================================================================\n";
    s<< "\t CANTIDAD "<<"\t |CONCEPTO"<< "\t|PRECIO" << "\t\t  |IMPORTE" << "\n";
    s <<this->carrito->toString() << "\n";
    s << "================================================================================\n";
    s << "\t TOTAL BRUTO: $" << totalbruto() << " " << "| IMPORTE 13 % : $" << totalIVa() << "| TOTAL NETO: $" << totalneto() << endl;
    s << "================================================================================\n";
    return s.str();
}

double Venta::totalbruto()const{
    return carrito->getTotal() + carrito->getGanancia();
}

double Venta::totalIVa()const
{
    return totalbruto() * 0.013;
}

double Venta::totalneto()const
{
    return totalbruto() + totalIVa();
}

Venta* Venta::clonar() const
{
    return new Venta(*this);
}


void Venta::guardarVenta(ofstream& file){


    file << "Venta"
        << '\t' << codigo
        << '\t' << cedulaCliente << '\n';
    if (fVenta != nullptr) {
        this->fVenta->guardarFecha(file);
    }
    if (this->carrito!=nullptr) {
        this->carrito->guardarComponenteAbstracto(file);
    }
}
Venta* Venta::leerVenta(ifstream& file){
    string codigoL,cedL,tipo;
    ProductoDecorador* car = NULL;
    Fecha* f = nullptr;

    getline(file, codigoL, '\t');
    getline(file, cedL, '\t');
    f = Fecha::leerFecha(file);
    getline(file, tipo, '\t');
   
    if (tipo == "Abarrote") {
        car = DecoradorAbarrote::leerDecoAbarrote(file);
    }
    if (tipo == "Embutido") {
        car = DecoradorEmbutido::leerDecoEmbutido(file);
    }
    if (tipo == "Conserva") {
        car = DecoradorConserva::leerDecoConserva(file);
    }
    return new Venta(car,cedL,f,codigoL );
}

ostream& operator<<(ostream& o , Venta& v)
{
	o << v.toString() << endl;
	return o;
}


