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

	~ForwardList() = default;

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

	void pop_front() {
		if (Head == nullptr) {
			cout << "Error : No Elements in Forward List" << endl;
		}
		else {
			Node<T>* toDeleteNode = Head;
			Head = Head->Next;
			delete toDeleteNode;
			toDeleteNode = nullptr;
		}
	}

	Node <T>* front();

	Node <T>* back();

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

	void pop_back() {
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
			delete toDeleteNode;
			toDeleteNode = nullptr;
		}
	}

	T& operator[] (int n);

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

	void clear();

	ForwardList& sort();

	ForwardList& reverse();

	//ostream& operator<<(ForwardList& fl, ostream& out) {}

	void print() {
		Node<T>* temp = Head;
		cout << *(*temp) << ' ';
		while (temp->Next != nullptr) {
			temp = temp->Next;
			cout << *(*temp) << ' ';
		}
		cout << endl;
	}
};
