#include "Producto.h"

ostream& operator<<(ostream& s, Producto& p)
{
    s << p.toString();
    return s;
}

istream& operator>>(istream& in, Producto& p){
    p.leerDatos(in);
    return in;
}

void Producto::leerDatos(istream&){}
