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
public:

    DecoradorEmbutido(BaseCarrito*, Empaque*, Perecedero*, string, string, string, string, string, string, double, double, bool);
	DecoradorEmbutido(const DecoradorEmbutido&);
	virtual ~DecoradorEmbutido();
	virtual BaseCarrito* getSiguiente();
	virtual void setSiguiente(BaseCarrito*);
	virtual string toString() const;
	friend ostream& operator<<(ostream& o, DecoradorEmbutido&);
    virtual double getTotal();
    /*virtual int getCantidad();*/
    virtual ObjetoBase* clonar() const;
};

