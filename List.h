#pragma once
#include <iostream>
#include "Node.h"
#include "ForwardListNode.h"
#include "DoubleListNode.h"

template <typename T>
class List {
protected:
	Node<T>* head;

public:
	
	List(List& list_2) {} // Constructor copia
	List(T* arr) {} //Constructor  parametro, llena una lista a partir de un array
	List(Node<T>* n) {} //Constructor por parametro, retorna una lista con un nodo
	List(int n) {} //Constructor por parametro, retorna un lista de randoms de tamaño n
	List() = default; // Constructor por defecto
	
	virtual T& front() = 0; // Retorna una referencia al primer elemento
	virtual T& back() = 0; // Retorna una referencia al ultimo elemento

	virtual void push_back(const T& element) = 0; // Inserta un elemento al final
	virtual void push_front(const T& element) = 0; // Inserta un elemento al inicio

	virtual Node<T>* pop_back() = 0; // Quita el ultimo elemento de la lista y retorna una referencia 
	virtual Node<T>* pop_front() = 0; // Quita el primer elemento de la lista y retorna una referencia 

	virtual T& operator[] (const unsigned int& n) = 0; // devuelve el valor de un nodo en una posicion determinada

	virtual bool empty() = 0; // la lista esta vacia?
	virtual unsigned int size() = 0; // retorna el tamaño de la lista
	virtual void clear() = 0; // Elimina toda la lista

	virtual void erase(const int& index) = 0; // Elimina un elemento de la lista en base a un puntero
	virtual void insert(const int& index, const T& value) = 0; // Inserta un elemento en la lista en base a un puntero
	virtual void drop(const T& value) = 0; // Elimina todos los elementos de la lista que tienen el valor igual al parametro

	virtual List& sort() = 0; // ordena la lista
	virtual List& reverse() = 0; // invierte la lista
	/*
	inline friend std::ostream& operator<< (std::ostream&, List<T>&) = 0; // Imprime la lista con cout
	inline friend List& operator<< (List<T>&, T&) = 0; // push_back de un elemento
	inline friend List& operator>> (List<T>&, T&) = 0; // pop_back de un elemento
	*/
};