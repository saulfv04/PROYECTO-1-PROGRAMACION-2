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

	//Destrcutor
	virtual ~Producto() {}


	virtual string toString()const = 0;

	//Accesores
	virtual string getnombreComecial() = 0;
	virtual string getCodigo()const = 0;
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
	virtual void setFechaIng(Fecha*)=0;

	//Métodos de cálculo
	virtual double ganancia() = 0;

	//Guardar y leer de archivos
	virtual void guardarProducto(ofstream&) = 0;

	//heredados
	virtual  Producto* clonar()const = 0;

	//Sobrecargas
	friend ostream& operator <<(ostream& s, Producto&);
	friend istream& operator >>(istream&, Producto&);
	virtual void leerDatos(istream&);


};