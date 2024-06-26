#pragma once
#include "Prod-Perecedero.h"

class Carne :public ProdPerecedero
{
	protected:
		string nombreAnimal;
		string parteDelAnimal;
	public:
		//Destructor
		virtual ~Carne(){}

		//Accesores y Mutadores de la propia clase
		virtual string getNombreAnimal() = 0;
		virtual string getparteDelAnimal() = 0;
		virtual void setNombreAnimal(string) = 0;
		virtual void setparteDelAnimal(string) = 0;

		//Accesores y Mutadores heredados
		virtual bool getNacional() = 0;
		virtual double getPeso() = 0;
		virtual void setNacional(bool) = 0;
		virtual void setPeso(double) = 0;
		virtual string toString()const = 0;
		virtual int getFechaPer() = 0;
		virtual Perecedero* getPer() = 0;
		virtual int getFechaIng() = 0;
		virtual  Producto* clonar()const = 0;
		//Accesores y Mutadores heredados
		virtual string getnombreComecial() = 0;
		virtual string getCodigo()const = 0;
		virtual string getDescripcion() = 0;
		virtual double getprecioCosto() = 0;
		virtual string getCategoria() = 0;
		virtual int getExistencia() = 0;
		virtual int getLimite() = 0;

		//Mutadores
		virtual void setCodigo(string) = 0;
		virtual void setnombreComercial(string) = 0;
		virtual void setDescripcion(string) = 0;
		virtual void setprecioCosto(double) = 0;
		virtual void setCategoria(string) = 0;
		virtual void setExistencia(int) = 0;
		virtual void setLimite(int) = 0;
		virtual void setFechaIng(Fecha*) = 0;

		//M�todos de c�lculo
		virtual double ganancia()=0;

		//Archivos
		virtual void guardarProducto(ofstream&) = 0;
		virtual void leerDatos(istream&) = 0;

		



};

