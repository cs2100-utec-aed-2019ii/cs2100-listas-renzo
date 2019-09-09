#pragma once
#include "Node.h"

template <typename T>
class DoubleListNode : public Node<T> {
private:
	template <typename B>
	friend class DoubleList;

protected:
	DoubleListNode* next;
	DoubleListNode* prev;

public:
	DoubleListNode() {
		next = nullptr;
		prev = nullptr;
	}
	DoubleListNode(T value) : Node(value) {
		next = nullptr;
		prev = nullptr;
	}
	~DoubleListNode(void) {}
};