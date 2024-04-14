#include "Categoria.h"

Categoria::Categoria()
{
	cout << "Borrando Categoria" << endl;

}

Categoria::~Categoria()
{
}

double Categoria::porceganancia(string cat)
{
	if (cat == "01") {
		return 0.015;
	}
	else if (cat == "02") {
		return 0.020;
	}
	else {
		return 0.030;
	}
}
