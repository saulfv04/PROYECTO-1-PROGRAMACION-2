#pragma once
#include "Producto.h"
#include "Perecedero.h"

class ProdPerecedero:public Producto {
	protected:
		bool nacional;
		double peso;
		Perecedero* ptrPer;
	public:
		virtual ~ProdPerecedero(){}


		//Accesores y Mutadores propios de la clase
		virtual bool getNacional() = 0;
		virtual double getPeso() = 0;
		virtual void setNacional(bool) = 0;
		virtual void setPeso(double) = 0;
		virtual string toString()const =0;
		virtual int getFechaPer() = 0;
		virtual Perecedero* getPer()=0;

		//Accesores heredados
		virtual int getFechaIng() = 0;
		virtual string getnombreComecial()  = 0;
		virtual string getCodigo() const = 0;
		virtual string getDescripcion() = 0;
		virtual double getprecioCosto() = 0;
		virtual string getCategoria() = 0;
		virtual int getExistencia() = 0;
		virtual int getLimite() = 0;
		virtual  Producto* clonar()const = 0;

		//Mutadores heredados
		virtual void setCodigo(string) = 0;
		virtual void setnombreComercial(string) = 0;
		virtual void setDescripcion(string) = 0;
		virtual void setprecioCosto(double) = 0;
		virtual void setCategoria(string) = 0;
		virtual void setExistencia(int) = 0;
		virtual void setLimite(int) = 0;
		virtual void setFechaIng(Fecha*) = 0;
		virtual void SetFechaPer(Perecedero*)=0;


		virtual void guardarProducto(ofstream&) = 0;


};
