#pragma once
#include "Carne.h"
#include "Empaque.h"
class Embutido :public Carne
{
	private:
		string marca;
		Empaque* ptrEmpaque;
	public:
		Embutido(Empaque*, string, string, string, Perecedero*, Fecha*, string, bool, double, string, string, string, double, string, int, int);
		Embutido(const Embutido& e);
		virtual ~Embutido();
		
		//Accesores y Mutadores de la propia clase
		string getMarca();
		bool getEmpaque();
		void setMarca(string);
		void setEmpaque(Empaque*);

		//Accesores y Mutadores heredados
		virtual string getNombreAnimal();
		virtual string getparteDelAnimal();
		virtual void setNombreAnimal(string);
		virtual void setparteDelAnimal(string);
		virtual int getFechaIng();
		virtual int getFechaPer();
		virtual string toString();
		virtual string getnombreComecial();
		virtual string getCodigo();
		virtual string getDescripcion();
		virtual double getprecioCosto();
		virtual string getCategoria();
		virtual int getExistencia();
		virtual int getLimite();
		virtual void setCodigo(string);
		virtual void setnombreComercial(string);
		virtual void setDescripcion(string);
		virtual void setprecioCosto(double);
		virtual void setCategoria(string);
		virtual void setExistencia(int);
		virtual void setLimite(int);
};

