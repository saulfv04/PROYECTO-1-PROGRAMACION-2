#pragma once
#pragma once
#include <iostream>
#include "Nodo.h"

using namespace std;

template<class T>

class Lista {
private:
	Nodo<T>* primero;
public:
	Lista();
	Lista(const Lista&);
	Lista& operator = (const Lista&);//operador de asignacion
	virtual ~Lista();
	void agregarInicio(T&);
	void agregarFinal(T*);
	T* eliminar(); // Eliminar primero, que devuelve lo que se borro
	string toString()const;
	void eliminarTodos();//elimina los elementos de la lista
	void invierteLista();
	//Nuevos metodos;
	int size();
	T* getElemento(unsigned int i);
	void remove(int p);
	void removeInicio();
	bool isEmpty();







};


template<class T>
Lista<T>::Lista()
{
	primero = NULL;
}

template<class T>
Lista<T>::Lista(const Lista& lis)
{
	primero = NULL;
	Nodo<T>* pAct = lis.primero;// De la lista que llega
	while (pAct != NULL) {
		T* dat1 = new T(*pAct->obtenerInfo());
		this->agregarFinal(pAct);
		pAct = pAct->obtenerSig();
	}

}

template<class T>
Lista<T>& Lista<T>::operator=(const Lista& l) {
	if (this != &l) {
		Nodo<T>* pAct = l.primero;
		while (pAct) {
			T* dat1 = new T(*pAct->obtenerInfo());
			this->agregarFinal(dat1);
			pAct = pAct->obtenerSig();
		}
	}
	return *this;
 }



template<class T>
Lista<T>::~Lista() {
	eliminarTodos();
	delete this;
}

template<class T>
bool Lista<T>::isEmpty()
{
	return (primero == NULL);
}

template<class T>
int Lista<T>::size()
{
	Nodo<T>* pAct = primero;
	int size = 0;
	if (pAct == NULL) {
		return size;
	}
	while (pAct) {
		size++;
		pAct = pAct->obtenerSig();
	}

	return size;
}

template<class T>
inline T* Lista<T>::getElemento(unsigned int i)
{
	return nullptr;
}

template<class T>
inline void Lista<T>::remove(int p)
{
}

template<class T>
inline void Lista<T>::removeInicio()
{
}

template<class T>
void Lista<T>::agregarInicio(T& dat) {
	T* dato1 = new T(*dat);
	if (primero == NULL) {
		primero = new Nodo<T>(NULL, *dato1);
	}
	else {
		Nodo<T>* pNuevo = new Nodo<T>(primero, *dato1);
		primero = pNuevo;
	}	
}

template<class T>
void Lista<T>::agregarFinal(T* dat){
	T* dato1 = new T(*dat);
	if (primero == NULL) {
		primero = new Nodo<T>(NULL, *dato1);
	}
	else {
		Nodo<T>* pAct = primero;
		while (pAct->obtenerSig() != NULL) {
			pAct = pAct->obtenerSig();
		}
		pAct->setSig(new Nodo<T>(NULL, *dato1));
	}
}

template<class T>
T* Lista<T>::eliminar() {
	if (primero != NULL) {
		delete primero;
	}
 }

template<class T>
string Lista<T>::toString() const
{
	Nodo<T>* pAct = primero;
	stringstream s;
	while (pAct) {
		s << *pAct->obtenerInfo()<< endl;
		pAct = pAct->obtenerSig();
	}
	return s.str();
}

template<class T>
void Lista<T>::eliminarTodos() {
	Nodo<T>* pAct = primero;
	while (pAct) {
		Nodo<T>* pBorrar = pAct;
		pAct = pAct->obtenerSig();
		delete pBorrar;
	}
	primero = NULL;
}

template<class T>
void Lista<T>::invierteLista(){
	Nodo<T>* pAct = primero;
	Nodo<T>* pAnt = NULL;
	while (pAct) {
		Nodo<T>* pSig = pAct->obtenerSig();
		pAct->setSig(pAnt);
		pAnt = pAct;
		pAct = pSig;
	}
	primero = pAnt;	
}
