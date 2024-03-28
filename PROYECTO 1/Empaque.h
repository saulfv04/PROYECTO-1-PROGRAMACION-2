#pragma once
#include <iostream>
#include <sstream>

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
};

