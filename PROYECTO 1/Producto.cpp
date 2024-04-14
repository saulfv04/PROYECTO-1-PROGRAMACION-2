#include "Producto.h"

ostream& operator<<(ostream& s, Producto& p)
{
    s << p.toString();
    return s;
}

