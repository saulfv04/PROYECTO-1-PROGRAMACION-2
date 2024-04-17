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
	T* eliminarEspecifico(string);
	void invierteLista();
	Nodo<T>* buscarElemento(string);
	string toString() const;
	//Nuevos metodos;
	int size();
	Nodo<T>* getPrimero();
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
 Nodo<T>* Lista<T>::getPrimero()
{
	return this->primero;
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
T* Lista<T>::eliminarEspecifico(string codigo) {
	Nodo<T>* busqueda = buscarElemento(codigo);
	if (busqueda == nullptr) {
		return nullptr;
	}
	Nodo<T>* pAct = primero;
	T* dato = busqueda->obtenerInfo(); // Almacenar el dato antes de borrar el nodo

	// Si el nodo a eliminar es el primero
	if (busqueda == primero) {
		primero = primero->obtenerSig(); // Avanzar el primero al siguiente nodo
		return dato; // Retornar el dato del nodo eliminado
		delete busqueda; // Liberar la memoria del nodo eliminado
	}
	// Encontrar el nodo anterior al que se desea eliminar
	while (pAct != nullptr && pAct->obtenerSig() != busqueda) {
		pAct = pAct->obtenerSig();
	}
	// Si no se encontró el nodo anterior porque el nodo a eliminar no está en la lista
	if (pAct == nullptr) {
		return nullptr;
	}
	// Desvincular el nodo encontrado de la lista
	pAct->setSig(busqueda->obtenerSig());
	return dato; // Retornar el dato del nodo eliminado
	delete busqueda; // Liberar la memoria del nodo eliminado
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
Nodo<T>* Lista<T>::buscarElemento(string codigo){
	Nodo<T>* pAct = primero;
	if (!isEmpty()) {
	while (pAct) {
		if (pAct->getCodigo()==codigo) {
			return pAct;
		}
		pAct = pAct->obtenerSig();
	}
	}
	return nullptr;
}
