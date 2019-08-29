#pragma once
#include "Node.h"
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class ForwardList {
protected:
	Node <T>* Head;

public:
	ForwardList() : Head{ nullptr } {}
	
	ForwardList(int n) {
		for (int i = 0; i < n; i++) {
			push_back(i);
		}
	}

	~ForwardList() {
		clear();
	}

	void push_front(const T& element) {
		if (Head == nullptr) {
			Node<T>* newNode = new Node <T>;
			newNode->data = element;
			Head = newNode;
		}
		else {
			Node<T>* newNode = new Node<T>;
			newNode->data = element;
			newNode->Next = Head;
			Head = newNode;
		}
	}

	Node<T>* pop_front() {
		if (Head == nullptr) {
			cout << "Error : No Elements in Forward List" << endl;
		}
		else {
			Node<T>* toDeleteNode = Head;
			Head = Head->Next;
			return toDeleteNode;
		}
	}

	Node <T>* front() { return Head; }

	Node <T>* back() {
		Node<T>* temp = Head;
		while (temp->Next != nullptr) {
			temp = temp->Next;
		}
		return temp;
	}

	void push_back(const T& element) {
		if (Head == nullptr) {
			Node<T>* newNode = new Node <T>;
			newNode->data = element;
			Head = newNode;
		}
		else {
			int size = ForwardList::size();
			Node<T>* temp = Head;

			while (temp->Next != nullptr) {
				temp = temp->Next;
			}
			Node<T>* newNode = new Node<T>;
			newNode->data = element;
			temp->Next = newNode;
		}
	}

	Node<T>* pop_back() {
		if (Head == nullptr) {
			cout << "Error : No Existen Elementos" << endl;
		}
		else {
			int size = ForwardList::size();
			Node<T>* temp = Head;

			while (temp->Next->Next != nullptr) {
				temp = temp->Next;
			}
			Node<T>* toDeleteNode = temp->Next;
			temp->Next = nullptr;
			return toDeleteNode;
		}
	}

	T& operator[] (int n) {
		Node<T>* temp = Head;
		for (int i = 0; i < n; i++) {
			if (n > size() - 1) { cout << "Error: Fuera de Lugar" << endl; break; }
			temp = temp->Next;
		}
		return *(*temp);
	}

	bool empty() {
		if (Head != nullptr) { return false; }
		else { return true; }
	}

	int size() {
		int size = 0;
		Node<T>* temp = Head;
		while (temp != nullptr) {
			temp = temp->Next;
			size++;
		}
		return size;
	}

	void clear() {
		for (int i = 0; i < size() - 1; i++) {
			pop_back();
		}
		delete Head;
		Head = nullptr;
	}

	void Combine(ForwardList<T>& v, int leftIndex, int middle, int rightIndex) {
		int Len_1 = middle - leftIndex + 1;
		int Len_2 = rightIndex - middle;
		ForwardList<T> tempV_1(Len_1);
		ForwardList<T> tempV_2(Len_2);

		for (int i = 0; i < Len_1; i++) {
			tempV_1[i] = v[leftIndex + i];
		}
		for (int i = 0; i < Len_2; i++) {
			tempV_2[i] = v[middle + i + 1];
		}

		int cont_1 = 0;
		int cont_2 = 0;
		int cont_3 = leftIndex;
		
		while (cont_1 < Len_1 && cont_2 < Len_2) {
			if (tempV_1[cont_1] < tempV_2[cont_2]) {
				v[cont_3] = tempV_1[cont_1];
				cont_1++;
			}
			else {
				v[cont_3] = tempV_2[cont_2];
				cont_2++;
			}
			cont_3++;
		}

		while (cont_1 < Len_1) {
			v[cont_3] = tempV_1[cont_1];
			cont_1++;
			cont_3++;
		}
		while (cont_2 < Len_2) {
			v[cont_3] = tempV_2[cont_2];
			cont_2++;
			cont_3++;
		}
		
	}

	void Merge(ForwardList<T>& v, int leftIndex, int rightIndex) {
		if (leftIndex < rightIndex) {
			int middle = (leftIndex + (rightIndex - 1)) / 2;
			Merge(v, leftIndex, middle);
			Merge(v, middle + 1, rightIndex);

			Combine(v, leftIndex, middle, rightIndex);
		}
	}

	ForwardList& sort() {
		Merge(*this, 0, size()-1);
		return *this;
	}

	ForwardList& reverse() {
		vector <T> tempV;
		for (int i = 0; i < size(); i++) {
			tempV.push_back((*this)[i]);
		}
		for (int i = 0; i < size(); i++) {
			(*this)[i] = tempV[tempV.size()-1-i];
		}
		return *this;
	}
	
	void print(ostream& out) {
		Node<T>* temp = Head;
			out << *(*temp) << ' ';
		while (temp->Next != nullptr) {
			temp = temp->Next;
			out << *(*temp) << ' ';
		}
		out << endl;
	}

	friend ostream& operator << (ostream& out, ForwardList& f) {
		f.print(out);
		return out;
	}
	
};
