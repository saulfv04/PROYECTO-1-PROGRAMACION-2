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

		string toString();

		//Accesores
		int getFechaPer();

		//Mutadores
		void setFecha(Fecha*);

		virtual void guardarPerecedero(ofstream&);
		static Perecedero* leerPerecedero(ifstream&);
		friend ostream& operator<<(ostream&, Perecedero&);
		friend istream& operator>>(istream&, Perecedero&);

};

