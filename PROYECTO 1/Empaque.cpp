#include "Empaque.h"

Empaque::Empaque(bool t)
{
    tripa = t;
}

Empaque::Empaque(const Empaque& copia)
{
    this->tripa = copia.tripa;
}

Empaque::~Empaque()
{
}

bool Empaque::getTripa()
{
    return tripa;
}
