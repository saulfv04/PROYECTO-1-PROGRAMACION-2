#pragma once
#include "ProductoDecorador.h"
#include "Embutido.h"
class DecoradorEmbutido : public ProductoDecorador {
private:
    Empaque* ptrEmpaque;
    Perecedero* ptrPer;
    string marca;
    string nombreAnimal;
    string parteDelAnimal;
    string codigo;
    string nombreComercial;
    string descripcion;
    double peso;
    double precioCosto;
    bool nacional;
    string categoria;
    double cantidad;
public:

    DecoradorEmbutido(ComponenteAbstracto*, Empaque*, Perecedero*, string, string, string, string, string, string, double, double, bool, double);
	DecoradorEmbutido(const DecoradorEmbutido&);
	virtual ~DecoradorEmbutido();
	virtual ComponenteAbstracto* getSiguiente();
	virtual void setSiguiente(ComponenteAbstracto*);
	virtual string toString() const;
    virtual double getTotal();
    virtual double getGanancia();
    virtual double getCantidad();
    virtual ComponenteAbstracto* clonar() const;


    //Sobrecargas
    friend ostream& operator<<(ostream& o, DecoradorEmbutido&);

};

