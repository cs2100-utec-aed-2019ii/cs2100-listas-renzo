#pragma once
#include "Node.h"

template <typename T>
class DoubleListNode : public Node<T> {
protected:
	DoubleListNode* next;
	DoubleListNode* prev;

public:
	DoubleListNode(T value) : Node(value) {
		next = nullptr;
		prev = nullptr;
	}
	~DoubleListNode(void) {}
};