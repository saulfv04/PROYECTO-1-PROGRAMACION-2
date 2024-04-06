#include "BaseCarrito.h"

ostream& operator<<(ostream& o, BaseCarrito& c)
{
    o << c.imprimir();
    return o;
}
