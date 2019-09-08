#pragma once
#include <iostream>
#include <vector>
#include "List.h"
#include "ForwardListNode.h"
using namespace std;

template <typename T>
class ForwardList : public List<T> {
protected:
	ForwardListNode<T>* head;
	ForwardListNode<T>* tail;

public:
	ForwardList() : head{ nullptr }, tail{ nullptr } {};
	ForwardList(int n) {
		for (int i = 0; i < n; i++) {
			push_back(i);
		}
	}
	ForwardList(ForwardList& list_2) {
		for (int i = 0; i < list_2.size(); i++) {
			push_back(list_2[i]);
		}
	} 
	ForwardList(T* arr, int size) {
		for (int i = 0; i < size; i++) {
			push_back((*arr)[i]);
		}
	} 
	ForwardList(ForwardListNode<T>* n) {
		push_back(n->value);
	}
	~ForwardList() {
		clear();
	}

	T& front() override { return *(*head); }
	T& back() override { return *(*tail); }

	void push_back(const T& element) override {
		if (head == nullptr) {
			ForwardListNode<T>* newNode = new ForwardListNode <T>;
			newNode->value = element;
			head = newNode;
			tail = newNode;
		}
		else {
			ForwardListNode<T>* newNode = new ForwardListNode<T>;
			newNode->value = element;
			tail->next = newNode;
			tail = newNode;
		}
	}
	void push_front(const T& element) override {
		if (head == nullptr) {
			ForwardListNode<T>* newNode = new ForwardListNode <T>;
			newNode->value = element;
			head = newNode;
			tail = newNode;
		}
		else {
			ForwardListNode<T>* newNode = new ForwardListNode<T>;
			newNode->value = element;
			newNode->next = head;
			head = newNode;
		}
	}

	ForwardListNode<T>* pop_back() override {
		if (head == nullptr) {
			cout << "Error : No Existen Elementos" << endl;
			return head;
		}
		else {
			int size = ForwardList::size();
			ForwardListNode<T>* temp = head;

			while (temp->next->next != nullptr) {
				temp = temp->next;
			}
			ForwardListNode<T>* toDeleteNode = temp->next;
			temp->next = nullptr;
			delete toDeleteNode;
			tail = temp;
		}
	}
	ForwardListNode<T>* pop_front() override {
		if (head == nullptr) {
			cout << "Error : No Elements in Forward List" << endl;
			return head;
		}
		else {
			ForwardListNode<T>* toDeleteNode = head;
			head = head->next;
			return toDeleteNode;
		}
	}

	T& operator[] (const unsigned int& n) override {
		ForwardListNode<T>* temp = head;
		for (unsigned int i = 0; i < n; i++) {
			if (n > size() - 1) { cout << "Error: Fuera de Lugar" << endl; break; }
			temp = temp->next;
		}
		return *(*temp);
	}

	bool empty() override {
		if (head != nullptr) { return false; }
		else { return true; }
	}
	unsigned int size() override {
		int size = 0;
		ForwardListNode<T>* temp = head;
		while (temp != nullptr) {
			temp = temp->next;
			size++;
		}
		return size;
	}
	void clear() override {
		for (unsigned int i = 0; i < size() - 1; i++) {
			pop_back();
		}
		delete head;
		head = nullptr;
	}

	void erase(const int& index) override {
		ForwardListNode<T>* temp = head;
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		if (temp->next == tail) {
			ForwardListNode<T>* toDelete = temp->next;
			temp->next = nullptr;
			delete toDelete;
			toDelete = nullptr;
		}
		else {
			ForwardListNode<T>* toDelete = temp->next;
			temp->next = toDelete->next;
			delete toDelete;
			toDelete = nullptr;
		}
	}
	void insert(const int& index, const T& value) override {
		ForwardListNode<T>* temp = head;
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		ForwardListNode<T>* toInsert = new ForwardListNode<T>;
		toInsert->value = value;
		toInsert->next = temp->next;
		temp->next = toInsert;
	}
	void drop(const T& value) override {
		ForwardListNode<T>* temp = head;
		int i = 1;
		if (*(*temp) == value) { erase(i); }
		while (temp->next != nullptr) {
			temp = temp->next;
			if (*(*temp) == value) { erase(i); temp = head; }
			i++;
		}
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

	ForwardList& sort() override {
		Merge(*this, 0, size() - 1);
		return *this;
	}
	ForwardList& reverse() override {
		std::vector <T> tempV;
		for (unsigned int i = 0; i < size(); i++) {
			tempV.push_back((*this)[i]);
		}
		for (unsigned int i = 0; i < size(); i++) {
			(*this)[i] = tempV[tempV.size() - 1 - i];
		}
		return *this;
	}
	
	void print(std::ostream& out) {
		ForwardListNode<T>* temp = head;
		out << *(*temp) << ' ';
		while (temp->next != nullptr) {
			temp = temp->next;
			out << *(*temp) << ' ';
		}
		out << endl;
	}
	
	inline friend std::ostream& operator<< (std::ostream& out, ForwardList<T>& fl) {
		fl.print(out);
		return out;
	}
	
	inline friend ForwardList& operator<< (ForwardList<T>& fl, const T& value) {
		fl.push_back(value);
		return fl;
	}

	inline friend ForwardList& operator>> (ForwardList<T>& fl, const T& value) {
		fl.pop_back();
		return fl;
	}
	
};