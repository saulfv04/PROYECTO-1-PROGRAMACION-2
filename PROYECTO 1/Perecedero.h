#pragma once
#include "Fecha.h"



class Perecedero
{
	private:
		Fecha* ptrFechaPer;
	public:

		//Contructores y Destructor
		Perecedero();
		Perecedero(Fecha*);
		Perecedero(const Perecedero&);
		virtual ~Perecedero();

		//Información
		string toString();

		//Accesores
		int getFechaPer();

		//Mutadores
		void setFecha(Fecha*);

		//Archivos
		virtual void guardarPerecedero(ofstream&);
		static Perecedero* leerPerecedero(ifstream&);

		//Sobrecargas
		friend ostream& operator<<(ostream&, Perecedero&);
		friend istream& operator>>(istream&, Perecedero&);

};

