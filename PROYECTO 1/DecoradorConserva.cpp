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

void DecoradorConserva::imprimir()
{
    cout << "----------------CONSERVA----------------" << endl;
    cout << endl;
    cout <<"nombre: " << this->nombre << endl;
    cout << "codigo: " << this->codigo << endl;
    cout << "descripcion: " << this->descricion << endl;
    cout << "envasado: ";
    if (this->envasado) {
        cout << "con envasado" << endl;
    }
    else {
        cout << "sin envasar" << endl;
    }
    cout << "precio costo: " << this->precio << endl;
    cout << "" << endl;
    ptrCarrito->imprimir();
}
//
//ostream& operator<<(ostream& o , DecoradorConserva& con)
//{
//    o << "Conserva: " << con.ptrConserva << '\n' << con.ptrCarrito << endl;
//    return o;
//}
