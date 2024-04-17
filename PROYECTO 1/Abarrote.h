#pragma once
#include "Prod-Perecedero.h"
class Abarrote :public ProdPerecedero
{
	private:
		string empresaNombre;
	public:
		//Constructores y Destructor
		Abarrote();
		Abarrote(Perecedero*,Fecha*, string,bool, double, string, string, string, double, string, int, int);
		Abarrote(const Abarrote&);
		virtual ~Abarrote();

		//Accesores y Mutadores de la propia clase;
		string getEmpresaNombre();
		void setEmpresaNombre(string);


		//Accesores y Mutadores hereadados
		virtual bool getNacional();
		virtual double getPeso();
		virtual void setNacional(bool);
		virtual void setPeso(double);
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
		virtual  Producto* clonar()const;
	
		virtual void setCodigo(string);
		virtual void setnombreComercial(string);
		virtual void setDescripcion(string);
		virtual void setprecioCosto(double);
		virtual void setCategoria(string);
		virtual void setExistencia(int);
		virtual void setLimite(int);
		virtual void setFechaIng(Fecha*);
		virtual void SetFechaPer(Perecedero*);

		//Archivos
		virtual void guardarProducto(ofstream&);
		static Abarrote* leerAbarrote(ifstream&);

		//Sobrecargas
		friend ostream& operator <<(ostream& s,Abarrote&);

		//Métodos de cálculo
		virtual double ganancia();
		virtual void leerDatos(istream&);

};

