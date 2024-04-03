#pragma once
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;


class Empaque
{
	private:
		bool tripa;
	public:
		Empaque(bool);
		Empaque(const Empaque&);
		virtual ~Empaque();
		bool getTripa();
		void guardarEmpaque(ofstream&);
		static Empaque* leerEmpaque(ifstream&);
};

