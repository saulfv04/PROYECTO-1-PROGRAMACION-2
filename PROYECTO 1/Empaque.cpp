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

void Empaque::guardarEmpaque(ofstream& file)
{
    file << tripa << '\n';
}

Empaque* Empaque::leerEmpaque(ifstream& file)
{
    string tripaF;
    int tripa;


    getline(file, tripaF, '\n');

    tripa = stoi(tripaF);

    if (tripa == 1) {
        return new Empaque(true);
    }
    else {
        return new Empaque(false);
    }
}
