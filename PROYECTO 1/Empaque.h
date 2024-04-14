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
		Empaque();
		Empaque(bool);
		Empaque(const Empaque&);
		virtual ~Empaque();


		bool getTripa();
		void setTripa(bool);


		void guardarEmpaque(ofstream&);
		static Empaque* leerEmpaque(ifstream&);

		friend ostream& operator<<(ostream&, Empaque&);
		friend istream& operator>>(istream&, Empaque&);
};

