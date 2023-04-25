#pragma once
#include<iostream>

using namespace std;
#pragma once

template<class T>
class Tnodo{
private:
	T* data;
	Tnodo<T>* sig;

public:
	/*    Nodo(Object*, Nodo*);
    virtual ~Nodo();
    Object* getObjeto();
    Nodo* getSiguiente();
    void setObjeto(Object*);
    void setSiguiente(Nodo*);
*/


	Tnodo();
	Tnodo(T*, Tnodo<T>*);
	T* getData();
	Tnodo<T>* getSig();
	void setData(T*);
	void setSig(Tnodo<T>*);
};

template<class T>
Tnodo<T>::Tnodo(){
	sig = NULL;
	data = NULL;
}

template<class T>
Tnodo<T>::Tnodo(T* ptrH, Tnodo<T>* sigui):data(ptrH), sig(sigui) {}


template<class T>
Tnodo<T>* Tnodo<T>::getSig(){
	return sig;
}

template<class T>
void Tnodo<T>::setSig(Tnodo* sigue){
	this->sig = sigue;
}

template<class T>
T* Tnodo<T>::getData(){
	return data;
}

template<class T>
void Tnodo<T>::setData(T* dat){
	this->data = dat;
}