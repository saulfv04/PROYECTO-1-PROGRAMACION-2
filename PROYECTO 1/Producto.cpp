#include "Producto.h"

ostream& operator<<(ostream& o, Producto& p)
{
    o << p.toString();
    return o;
}
