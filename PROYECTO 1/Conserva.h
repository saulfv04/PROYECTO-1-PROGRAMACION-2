#pragma once
#include "Producto.h"
class Conserva : public Producto
{
	private:
		bool envasado;
	public:
		//Constructores y destructor
		Conserva();
		Conserva(Fecha*,bool,string,string,string,double,string,int,int);
		Conserva(const Conserva&);
		virtual ~Conserva();
		
		//Accesores y Mutadores propios de la clase
		bool getEnvasado();
		void setEnvasado(bool);


		//Accesores y Mutadores heredados
		virtual string toString()const;
		virtual int getFechaIng();
		virtual  Producto* clonar()const;
		//Accesores
		virtual string getnombreComecial();
		virtual string getCodigo()const;
		virtual string getDescripcion();
		virtual double getprecioCosto();
		virtual string getCategoria();
		virtual int getExistencia();
		virtual int getLimite();

		//Mutadores
		virtual void setCodigo(string);
		virtual void setnombreComercial(string);
		virtual void setDescripcion(string);
		virtual void setprecioCosto(double);
		virtual void setCategoria(string);
		virtual void setExistencia(int);
		virtual void setLimite(int);
		virtual void setFechaIng(Fecha*);

		virtual double ganancia();
		virtual void guardarProducto(ofstream&);
		static Conserva* leerConserva(ifstream&);
		friend ostream& operator <<(ostream& s, Conserva&);
		virtual void leerDatos(istream&);



};

