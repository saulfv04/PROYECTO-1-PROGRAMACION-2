#include "ObjetoBase.h"


ObjetoBase::ObjetoBase()
{
}

ObjetoBase::~ObjetoBase(){
}

ostream& operator<<(ostream& o, const ObjetoBase& objB){
	o << objB.toString();
	return o;
}
