#include "DecoradorConserva.h"

DecoradorConserva::DecoradorConserva(BaseCarrito* ptrCarro, string n, string c, string d, double p, bool e)
{
    this->ptrCarrito = ptrCarro;
    this->nombre = n;
    this->codigo = c;
    this->descricion = d;
    this->precio = p;
    this->envasado = e;
}

DecoradorConserva::DecoradorConserva(const DecoradorConserva& copia)
{
    this->ptrCarrito = copia.ptrCarrito;
    this->nombre = copia.nombre;
    this->codigo = copia.codigo;
    this->descricion = copia.descricion;
    this->precio = copia.precio;
    this->envasado = copia.envasado;
}

DecoradorConserva::~DecoradorConserva(){}

BaseCarrito* DecoradorConserva::getSiguiente()
{
    return ptrCarrito;
}

void DecoradorConserva::setSiguiente(BaseCarrito* conserva)
{
    ptrCarrito = conserva;
}

string DecoradorConserva::imprimir(){
    stringstream s;
    s << "----------------CONSERVA----------------" << endl;
    s << endl;
    s <<"nombre: " << this->nombre << endl;
    s << "codigo: " << this->codigo << endl;
    s << "descripcion: " << this->descricion << endl;
    s << "envasado: ";
    if (this->envasado) {
        s << "con envasado" << endl;
    }
    else {
        s << "sin envasar" << endl;
    }
    s << "precio costo: " << this->precio << endl;
    s << "" << endl;
    s<<ptrCarrito->imprimir();
    return s.str();
}

ostream& operator<<(ostream& o , DecoradorConserva& con)
{
    o <<con.imprimir()<< endl;
    return o;
}

