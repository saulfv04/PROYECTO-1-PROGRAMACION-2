#pragma once
#pragma once
#include <iostream>
#include "Nodo.h"

using namespace std;

template<class T>
class Lista{
private:
	Nodo<T>* primero;
public:
	Lista();
	Lista(const Lista&);
	Lista& operator = (const Lista&);//operador de asignacion
	virtual ~Lista();
	void agregarInicio(T*);
	void agregarFinal(T*);
	T* eliminar(); // Eliminar primero, que devuelve lo que se borro
	void eliminarTodos();//elimina los elementos de la lista
	void invierteLista();
	Nodo<T>* buscar(string);
	string toString() const;
	//Nuevos metodos;
	int size();
	T* getElemento(unsigned int i);
	void remove(int p);
	void removeInicio();
	bool isEmpty();

	//Clonación
	virtual Lista<T>* clonar()const;

	friend ostream& operator<<(ostream& o, Lista& l) { return o << l.toString(); }







};


template<class T>
Lista<T>::Lista()
{
	primero = nullptr;
}

template<class T>
Lista<T>::Lista(const Lista& list)
{
	Nodo<T>* pAct = list.primero;
	while (pAct != NULL) {
		agregarInicio(pAct->obtenerInfo()->clonar());
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
	cout << "Borrando Lista" << endl;

}

template<class T>
bool Lista<T>::isEmpty()
{
	return (primero == NULL);
}

template<class T>
 Lista<T>* Lista<T>::clonar() const{
	return new Lista<T>(*this);
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
 T* Lista<T>::getElemento(unsigned int i)
{
	return nullptr;
}

template<class T>
 void Lista<T>::remove(int p)
{
}

template<class T>
 void Lista<T>::removeInicio()
{
}

template<class T>
void Lista<T>::agregarInicio(T* dat) {
	T* dato1 = dat->clonar();	
	if (primero == nullptr) {
		primero = new Nodo<T>(nullptr, dato1);
	}
	else {
		Nodo<T>* pNuevo = new Nodo<T>(nullptr, dato1); // New node's next pointer should point to the current first node
		pNuevo->setSig(primero); // Set the next pointer of the new node to the current first node
		primero = pNuevo; // Update the first node pointer to the new node
	}
}

template<class T>
void Lista<T>::agregarFinal(T* dat){
	T* dato1 = dat->clonar();
	if (primero == NULL) {
		primero = new Nodo<T>(nullptr, dato1);
	}
	else {
		Nodo<T>* pAct = primero;
		while (pAct->obtenerSig() != NULL) {
			pAct = pAct->obtenerSig();
		}
		pAct->setSig(new Nodo<T>(nullptr, dato1));
	}
}

template<class T>
T* Lista<T>::eliminar() {
	if (primero != NULL) {
		delete primero;
	}
 }

template<class T>
string Lista<T>::toString() const{
	stringstream s;
	Nodo<T>* pAct = primero;
	s << "INFORMACION LISTA" << endl;
	while (pAct!=nullptr) {
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

template<class T>
Nodo<T>* Lista<T>::buscar(string codigo){
	Nodo<T>* aux = NULL;
	Nodo<T>* pAct = primero;
	if (!isEmpty()) {
	while (pAct) {
		if (pAct->getCodigo()==codigo) {
			return pAct;
		}
		pAct = pAct->obtenerSig();
	}
	}
	return aux;
}
