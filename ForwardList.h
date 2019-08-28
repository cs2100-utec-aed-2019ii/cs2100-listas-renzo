#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class ForwardList {
protected:
	Node <T>* Head;

public:
	ForwardList() : Head{ nullptr } {}

	~ForwardList();

	void push_front();

	void pop_front();

	Node <T>* front();

	Node <T>* back();

	void push_back();

	void pop_back();

	T& operator[] (int n);

	bool empty();

	int size();

	void clear();

	ForwardList<T>& sort();

	ForwardList<T>& reverse();

	ostream& operator+(ForwardList<T>& fl, ostream& out) {

	}

};
