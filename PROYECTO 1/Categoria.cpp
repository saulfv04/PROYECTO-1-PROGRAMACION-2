#include "Categoria.h"

Categoria::Categoria()
{

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
