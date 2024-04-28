#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class ExcCedula {
	private:
		string valor;
	public:
		ExcCedula(string);
		virtual ~ExcCedula();
		const char* what() const throw();
		string toString();

};
