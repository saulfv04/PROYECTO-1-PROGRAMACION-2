#include "Empaque.h"

Empaque::Empaque(){
    this->tripa = false;
}

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
    cout << "Borrando Empaque" << endl;

}

bool Empaque::getTripa()
{
    return tripa;
}

void Empaque::setTripa(bool t)
{
    this->tripa = t;
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

ostream& operator<<(ostream& s, Empaque& emp)
{
    s << emp.getTripa();
    return s;
}

istream& operator>>(istream& i, Empaque& e)
{
    string op;
    cout << "Tiene Tripa (N)No o (S)Si" << endl;
    cin >> op;
    if (op=="S"||op=="s") {
        e.setTripa(true);
    }
    else {
        e.setTripa(false);
    }
    return i;
}
