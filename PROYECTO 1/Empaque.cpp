#include "Empaque.h"

Empaque::Empaque(bool t)
{
    tripa = t;
}

Empaque::~Empaque()
{
}

bool Empaque::getTripa()
{
    return tripa;
}
