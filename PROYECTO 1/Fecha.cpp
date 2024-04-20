#include "Fecha.h"

Fecha::Fecha()
{
    this->anio = 0;
    this->mes = 0;
    this->dia = 0;
}

Fecha::Fecha(int d, int m, int a)
{
    dia = d;
    mes = m;
    anio = a;
}

Fecha::Fecha(const Fecha& copia)
{
    this->anio = copia.anio;
    this->mes = copia.mes;
    this->dia = copia.dia;
}

Fecha::~Fecha(){
    cout << "Borrando fecha" << endl;

}

int Fecha::getFecha()
{
    int a, d, m = 0;

    a = anio * 31536000;
    d = dia * 86400;
    m = mes * 2592000;

    return a + d + m;

}

string Fecha::toString()
{
    stringstream s;
    s << "FECHA (D/M/A): "  << dia << " / " << mes << " / " << anio;
    return s.str();
}

void Fecha::guardarFecha(ofstream& file)
{
    file << dia << '\t' << mes << '\t' << anio << '\n';
}

Fecha* Fecha::leerFecha(ifstream& file)
{
    string diaF, mesF, anioF;
    int dia, mes, anio;
    getline(file, diaF, '\t');
    getline(file, mesF, '\t');
    getline(file, anioF, '\n');

    dia = stoi(diaF);
    mes = stoi(mesF);
    anio = stoi(anioF);

    return new Fecha(dia,mes,anio);
}

ostream& operator<<(ostream& s, Fecha& fec)
{
    s << fec.toString();
    return s;
}

istream& operator>>(istream& i, Fecha& f)
{
    cout << "Agregar fecha: "<<endl;
    cout << "Anno: " << endl;
    i >> f.anio;
    cout << "Mes: " << endl;
    i >> f.mes;
    cout << "Dia: " << endl;
    i >> f.dia;
    return i;
}
