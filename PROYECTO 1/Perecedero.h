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


};

