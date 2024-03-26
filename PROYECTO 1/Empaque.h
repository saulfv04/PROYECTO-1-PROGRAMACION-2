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
		virtual ~Empaque();
		bool getTripa();
};

