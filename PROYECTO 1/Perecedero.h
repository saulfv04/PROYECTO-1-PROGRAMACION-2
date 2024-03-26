#pragma once
#include "Fecha.h"



class Perecedero
{
	private:
		Fecha* ptrFechaPer;
	public:
		Perecedero(Fecha*);
		virtual ~Perecedero();

		string toString();
		int getFechaPer();


};

