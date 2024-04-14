#include "ComponenteAbstracto.h"

ostream& operator<<(ostream& o, ComponenteAbstracto& c)
{
    o << c.toString();
    return o;
}
