#pragma once
#include <iostream>
#include <sstream>
#include "Fecha.h"
#include "Categoria.h"
using namespace std;


class Producto {
protected:
	string codigo;
	string nombreComercial;
	string descripcion;
	double precioCosto;
	string categoria;
	int existencia;
	int limite;
	Fecha* ptrFechaIng;
public:
	virtual ~Producto() {}
	virtual string toString() = 0;

	//Accesores
	virtual string getnombreComecial() = 0;
	virtual string getCodigo() = 0;
	virtual string getDescripcion() = 0;
	virtual double getprecioCosto() = 0;
	virtual string getCategoria() = 0;
	virtual int getExistencia() = 0;
	virtual int getLimite() = 0;
	virtual int getFechaIng() = 0;

	//Mutadores
	virtual void setCodigo(string) = 0;
	virtual void setnombreComercial(string) = 0;
	virtual void setDescripcion(string) = 0;
	virtual void setprecioCosto(double) = 0;
	virtual void setCategoria(string) = 0;
	virtual void setExistencia(int) = 0;
	virtual void setLimite(int) = 0;
	virtual double ganancia() = 0;
	virtual void guardarProducto(ofstream&) = 0;

	friend ostream& operator<<(ostream& , Producto&);

};