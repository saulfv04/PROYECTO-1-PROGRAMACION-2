#pragma once
#include <iostream>
#include<sstream>

using namespace std;

template<class T>

class Nodo {
private:
	Nodo* siguiente;
	T* dato;
public:
	Nodo(Nodo<T>*, T&);
	virtual~Nodo();
	Nodo<T>* obtenerSig()const;
	T* obtenerInfo()const;
	void setInfo(T*);
	void setSig(Nodo<T>*);


};

template<class T>
Nodo<T>::Nodo(Nodo<T>* sig, T& dat) :siguiente(sig), dato(&dat) {}

template<class T>
Nodo<T>::~Nodo()
{
	if (dato)//Esto depende de la aplicacion
		delete dato;

}

template<class T>
Nodo<T>* Nodo<T>::obtenerSig() const
{
	return siguiente;
}

template<class T>
T* Nodo<T>::obtenerInfo() const
{
	return dato;
}

template<class T>
void Nodo<T>::setInfo(T* dat)
{
	dato = dat;
}

template<class T>
void Nodo<T>::setSig(Nodo<T>* sig)
{
	siguiente = sig;
}
