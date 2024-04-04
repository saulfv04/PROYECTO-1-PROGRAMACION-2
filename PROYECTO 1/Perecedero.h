#pragma once
#include "Fecha.h"



class Perecedero
{
	private:
		Fecha* ptrFechaPer;
	public:
		Perecedero(Fecha*);
		Perecedero(const Perecedero&);
		virtual ~Perecedero();

		string toString();
		int getFechaPer();

		virtual void guardarPerecedero(ofstream&);
		static Perecedero* leerPerecedero(ifstream&);
		/*friend ostream& operator<<(ostream&, Perecedero&);*/


};

