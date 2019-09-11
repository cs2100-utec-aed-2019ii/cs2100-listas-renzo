#pragma once
#include "DoubleListNode.h"
#include "List.h"

template <typename T>
class DoubleCircularList : public List<T> {
protected:
	DoubleListNode<T>* head;
  DoubleListNode<T>* tail; //En este caso apunta al anterior del tail/head. Se utiliza por la alta demanda de esta dirección.
  public:
  DoubleCircularList() : head{ nullptr } {};
	DoubleCircularList(int n) {
		for (int i = 0; i < n; i++) {
			push_back(i);
		}
	}
	DoubleCircularList(DoubleCircularList& list_2) {
		for (int i = 0; i < list_2.size(); i++) {
			push_back(list_2[i]);
		}
	} 
	DoubleCircularList(T* arr, int size) {
		for (int i = 0; i < size; i++) {
			push_back(arr[i]);
		}
	} 
	DoubleCircularList(DoubleListNode<T>* n) {
		push_back(n->value);
	}
	~DoubleCircularList() {
		clear();
	}

	T& front() override { return *(*head); }
	T& back() override { return *(*head); }

	void push_back(const T& element) override {
		if (head == nullptr) {
			DoubleListNode<T>* newNode = new DoubleListNode<T>;
			newNode->value = element;
			head = newNode;
			tail = newNode;
      tail->next = head;
		}
		else {
			DoubleListNode<T>* newNode = new DoubleListNode<T>;
			newNode->value = element;
			tail->next = newNode;
			tail = newNode;
      tail->next = head;
		}
	}
	void push_front(const T& element) override {
		if (head == nullptr) {
			DoubleListNode<T>* newNode = new DoubleListNode<T>;
			newNode->value = element;
			head = newNode;
			tail = newNode;
      tail->next = head;
		}
		else {
			DoubleListNode<T>* newNode = new DoubleListNode<T>;
			newNode->value = element;
			newNode->next = head;
			head = newNode;
      tail->next = head;
		}
	}

	DoubleListNode<T>* pop_back() override {
		if (head == nullptr) {
			cout << "Error : No Existen Elementos" << endl;
			return head;
		}
		else {
			int size = this->size();
			DoubleListNode<T>* temp = head;

			while (temp->next->next != head) {
				temp = temp->next;
			}
			DoubleListNode<T>* toDeleteNode = temp->next;
			tail = temp;
			temp->next = head;
			return toDeleteNode;
		}
	}
	DoubleListNode<T>* pop_front() override {
		if (head == nullptr) {
			cout << "Error : No Elements in Forward List" << endl;
			return head;
		}
		else {
			DoubleListNode<T>* toDeleteNode = head;
			head = head->next;
      tail->next = head;
			return toDeleteNode;
		}
	}

	T& operator[] (const unsigned int& n) override {
		DoubleListNode<T>* temp = head;
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
    if (empty()){
      return size;
    }else{
      size++;
      DoubleListNode<T>* temp = head->next;
		while (temp != head) {
			temp = temp->next;
			size++;
		}
		return size;
    }
		
	}
	void clear() override {
		for (unsigned int i = 0; i < size() - 1; i++) {
			pop_back();
		}
		delete head;
		head = nullptr;
		tail = nullptr;
	}

	void erase(const int& index) override {
		DoubleListNode<T>* temp = head;
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		if (temp->next->next == head) {
			delete temp->next;
			temp->next = head;
		}
		else {
			DoubleListNode<T>* toDeleteNode = temp->next;
			temp->next = temp->next->next;
			delete toDeleteNode;
			toDeleteNode = nullptr;
		}
			
	}
	void insert(const int& index, const T& value) override {
		DoubleListNode<T>* temp = head;
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		DoubleListNode<T>* toInsert = new DoubleListNode<T>;
		toInsert->value = value;
		toInsert->next = temp->next;
		temp->next = toInsert;
	}
	void drop(const T& value) override {
		DoubleListNode<T>* temp = head;
		int i = 0;
		if (*(*head) == value) { erase(i); }
		while (temp->next != head) {
			i++;
			temp = temp->next;
			if (*(*temp) == value) { erase(i); temp = head; i = 0; }
		}
	}
	
	void Combine(DoubleCircularList<T>& v, int leftIndex, int middle, int rightIndex) {
		int Len_1 = middle - leftIndex + 1;
		int Len_2 = rightIndex - middle;
		DoubleCircularList<T> tempV_1(Len_1);
		DoubleCircularList<T> tempV_2(Len_2);

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

	void Merge(DoubleCircularList<T>& v, int leftIndex, int rightIndex) {
		if (leftIndex < rightIndex) {
			int middle = (leftIndex + (rightIndex - 1)) / 2;
			Merge(v, leftIndex, middle);
			Merge(v, middle + 1, rightIndex);

			Combine(v, leftIndex, middle, rightIndex);
		}
	}

	DoubleCircularList& sort() override {
		Merge(*this, 0, size() - 1);
		return *this;
	}
	DoubleCircularList& reverse() override {
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
		DoubleListNode<T>* temp = head;
		out << *(*temp) << ' ';
		while (temp->next != head) {
			temp = temp->next;
			out << *(*temp) << ' ';
		}
		out << endl;
	}
	
	inline friend std::ostream& operator<< (std::ostream& out, DoubleCircularList<T>& fl) {
		fl.print(out);
		return out;
	}
	
	inline friend DoubleCircularList& operator<< (DoubleCircularList<T>& fl, const T& value) {
		fl.push_back(value);
		return fl;
	}

	inline friend DoubleCircularList& operator>> (DoubleCircularList<T>& fl, const T& value) {
		fl.pop_back();
		return fl;
	}
};
