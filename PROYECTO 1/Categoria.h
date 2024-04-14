#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Categoria {

	public:
		//Constructor
		Categoria();
		//Destructor
		virtual ~Categoria();
		//Método de cálculo
		double porceganancia(string);

};
