#pragma once
#include "ProductoDecorador.h"
#include "Abarrote.h"
class DecoradorAbarrote : public ProductoDecorador{
private:
	Abarrote* ptrAbarrote;
public:
	DecoradorAbarrote(BaseCarrito*, Abarrote*);
	virtual ~DecoradorAbarrote();
	virtual BaseCarrito* getSiguiente();
	virtual void setSiguiente(BaseCarrito*);
	virtual void imprimir();
};
