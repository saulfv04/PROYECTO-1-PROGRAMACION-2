#pragma once
#include "Prod-Perecedero.h"

class Carne :public ProdPerecedero
{
	protected:
		string nombreAnimal;
		string parteDelAnimal;
	public:
		virtual ~Carne(){}

		//Accesores y Mutadores de la propia clase
		virtual string getNombreAnimal() = 0;
		virtual string getparteDelAnimal() = 0;
		virtual void setNombreAnimal() = 0;
		virtual void setparteDelAnimal() = 0;

		//Accesores y Mutadores heredados
		virtual bool getNacional() = 0;
		virtual double getPeso() = 0;
		virtual void setNacional(bool) = 0;
		virtual void setPeso(double) = 0;
		virtual string toString() = 0;
		virtual int getFechaPer() = 0;
		virtual int getFechaIng() = 0;

		//Accesores y Mutadores heredados
		virtual int getFechaIng() = 0;
		virtual string getnombreComecial() = 0;
		virtual string getCodigo() = 0;
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


};

