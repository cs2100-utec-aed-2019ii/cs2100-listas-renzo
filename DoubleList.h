#ifndef TEST_DOUBLELIST_H
#define TEST_DOUBLELIST_H

#include "DoubleListNode.h"
#include "List.h"

template <typename T>
class DoubleList : public List<T> {
protected:
	DoubleListNode<T>* head;
	DoubleListNode<T>* tail;
	unsigned int DoubleListSize = 0;

public:
	DoubleList(DoubleList& list_2) {
		for (int i = 0; i < list_2.size(); i++) {
			push_back(list_2[i]);
		}
	} 
	DoubleList(T* arr, int size) {
		for (int i = 0; i < size; i++) {
			push_back((*arr)[i]);
		}
	} 
	DoubleList(DoubleListNode<T>* n) {
		push_back(n->value);
	} 
	DoubleList(int n) {
		for (int i = 0; i < n; i++) {
			push_back(0);
		}
	} 
	DoubleList() {
		head = nullptr; tail = nullptr;
	};
	~DoubleList() { clear(); }

	T& front() override { return *(*head); }
	T& back() override { return *(*tail); }

	void push_back(const T& element) override {
		if (head == nullptr) {
			DoubleListNode<T>* newNode = new DoubleListNode<T>;
			newNode->value = element;
			head = newNode;
			tail = newNode;
			DoubleListSize++;
		}
		else {
			DoubleListNode<T>* newNode = new DoubleListNode<T>;
			newNode->value = element;
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
			DoubleListSize++;
		}
	}
	void push_front(const T& element) override {
		if (head == nullptr) {
			DoubleListNode<T>* newNode = new DoubleListNode<T>;
			newNode->value = element;
			head = newNode;
			tail = newNode;
			DoubleListSize++;
		}
		else {
			DoubleListNode<T>* newNode = new DoubleListNode<T>;
			newNode->value = element;
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
			DoubleListSize++;
		}
	} 

	DoubleListNode<T>* pop_back() override {
		if (head == nullptr && tail == nullptr) {
			cout << "Error : No Elements in Double List" << endl;
			return head;
		}
		else {
			DoubleListNode<T>* temp = tail->prev;
			DoubleListNode<T>* toDeleteNode = tail;
			temp->next = nullptr;
			tail->prev = nullptr;
			tail = temp;
			DoubleListSize = DoubleListSize - 1;
			return toDeleteNode;
		}
	} 
	DoubleListNode<T>* pop_front() override {
		if (head == nullptr && tail == nullptr) {
			cout << "Error : No Elements in Double List" << endl;
			return head;
		}
		else {
			DoubleListNode<T>* toDeleteNode = head;
			head = head->next;
			DoubleListSize = DoubleListSize - 1;
			return toDeleteNode;
		}
	}

	T& operator[] (const unsigned int& n) override {
		if (n == 0) {
			return *(*head);
		}
		else if (n == DoubleListSize - 1) {
			return *(*tail);
		}
		else if (n <= DoubleListSize) {
			DoubleListNode<T>* temp = head;
			for (int i = 0; i < n; i++) {
				temp = temp->next;
			}
			return *(*temp);
		}
		else {
			DoubleListNode<T>* temp = tail;
			for (int i = 0; i < DoubleListSize - n - 1; i++) {
				temp = temp->prev;
			}
			return *(*temp);
		}
	} 

	bool empty() override { if (head == nullptr && tail == nullptr) { return true; } else { return false; } }

	unsigned int size() override {
		return DoubleListSize;
	}

	void clear() override {
		if (head == nullptr) { return; }
		for (unsigned int i = 0; i < size() - 1; i++) {
			pop_back();
		}
		delete head;
		head = nullptr;
		tail = nullptr;
	}

	void erase(const int& index) override {
		if (index == 0) {
			pop_front();
			return;
		}
		else if (index == DoubleListSize - 1) {
			pop_back();
			return;
		}
		else if (index <= DoubleListSize) {
			DoubleListNode<T>* temp = head;
			for (int i = 0; i < index - 1; i++) {
				temp = temp->next;
			}
			DoubleListNode<T>* toDeleteNode = temp->next;
			temp->next = toDeleteNode->next;
			toDeleteNode->next->prev = temp;
			delete toDeleteNode;
			toDeleteNode = nullptr;
			DoubleListSize--;
		}
		else {
			DoubleListNode<T>* temp = tail;
			for (int i = 0; i < DoubleListSize - index - 2; i++) {
				temp = temp->prev;
			}
			DoubleListNode<T>* toDeleteNode = temp->prev;
			toDeleteNode->prev->next = temp;
			temp->prev = toDeleteNode->prev;
			delete toDeleteNode;
			toDeleteNode = nullptr;
			DoubleListSize--;
		}
	} 
	void insert(const int& index, const T& value) override {
		if (index == 0) {
			push_front(value);
			return;
		}
		else if (index == DoubleListSize - 1) {
			push_back(value);
			return;
		}
		else if (index <= DoubleListSize) {
			DoubleListNode<T>* temp = head;
			for (int i = 0; i < index - 1; i++) {
				temp = temp->next;
			}
			DoubleListNode<T>* newNode = new DoubleListNode<T>;
			newNode->value = value;
			newNode->prev = temp;
			newNode->next = temp->next;
			temp->next->prev = newNode;
			temp->next = newNode;
			DoubleListSize++;
		}
		else {
			DoubleListNode<T>* temp = tail;
			for (int i = 0; i < DoubleListSize - index - 2; i++) {
				temp = temp->prev;
			}
			DoubleListNode<T>* newNode = new DoubleListNode<T>;
			newNode->value = value;
			newNode->next = temp;
			newNode->prev = temp->prev;
			temp->prev->next = newNode;
			temp->prev = newNode;
			DoubleListSize++;
		}
	} 
	void drop(const T& value) override {
		DoubleListNode<T>* temp = head;
		int i = 0;
		if (*(*head) == value) { erase(i); }
		while (temp->next != nullptr) {
			i++;
			temp = temp->next;
			if (*(*temp) == value) { erase(i); temp = head; i = 0; }
		}
	} 

	DoubleList& sort() override {
		int n = DoubleListSize;
		for (int i = 0; i < n; i++) {
			T temp = (*this)[i];
			int j = i - 1;
			while (j >= 0 && (*this)[j] > temp) {
				(*this)[j + 1] = (*this)[j];
				j--;
			}
			(*this)[j + 1] = temp;
		}
		return *this;
	} 
	DoubleList& reverse() override {
		DoubleList<T> temp(*this);
		DoubleListNode<T>* List_2 = temp.tail;
		DoubleListNode<T>* List_1 = head;
		for (int i = 0; i < DoubleListSize; i++) {
			*(*List_1) = *(*List_2);
			List_1 = List_1->next;
			List_2 = List_2->prev;
		}
		return *this;
	}

	void print(std::ostream& out) {
		DoubleListNode<T>* temp = head;
		out << *(*temp) << ' ';
		while (temp->next != nullptr) {
			temp = temp->next;
			out << *(*temp) << ' ';
		}
		out << endl;
	}

	inline friend std::ostream& operator<< (std::ostream& out, DoubleList<T>& Dl) {
		Dl.print(out);
		return out;
	}
	inline friend DoubleList& operator<< (DoubleList<T>& Dl , const T& value) {
		Dl.push_back(value);
		return Dl;
	} 
	inline friend DoubleList& operator>> (DoubleList<T>& Dl, const T& value) {
		Dl.pop_back();
		return Dl;
	}
	
};

#endif