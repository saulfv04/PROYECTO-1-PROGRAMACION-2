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
		//M�todo de c�lculo
		double porceganancia(string);

};
