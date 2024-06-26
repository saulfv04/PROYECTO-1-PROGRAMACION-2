#pragma once
#include "Carne.h"
#include "Empaque.h"
#include <fstream>
class Embutido :public Carne
{
	private:
		string marca;
		Empaque* ptrEmpaque;
	public:
		//Constructores y Destructores
		Embutido();
		Embutido(Empaque*, string, string, string, Perecedero*, Fecha*, bool, double, string, string, string, double, string, int, int);
		Embutido(const Embutido& e);
		virtual ~Embutido();
		
		//Accesores y Mutadores de la propia clase
		string getMarca();
		bool getEmpaque();
		void setMarca(string);
		void setEmpaque(Empaque*);

		//Accesores y Mutadores heredados
		virtual bool getNacional();
		virtual double getPeso();
		virtual void setNacional(bool);
		virtual void setPeso(double);
		virtual string getNombreAnimal();
		virtual string getparteDelAnimal();
		virtual void setNombreAnimal(string);
		virtual void setparteDelAnimal(string);
		virtual int getFechaIng();
		virtual Perecedero* getPer();
		virtual int getFechaPer();
		virtual string toString()const;
		virtual string getnombreComecial();
		virtual string getCodigo()const;
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
		virtual void setFechaIng(Fecha*);
		virtual void SetFechaPer(Perecedero*);
		Empaque* getEmaqueptr();

		virtual double ganancia();
		virtual  Producto* clonar()const;

		//Archivos
		virtual void guardarProducto(ofstream&);
		static Embutido* leerEmbutido(ifstream&);

		//Sobrecarga
		friend ostream& operator <<(ostream&, Embutido&);
		virtual void leerDatos(istream&);
};

