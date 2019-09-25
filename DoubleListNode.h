#ifndef TEST_DOUBLELISTNODE_H
#define TEST_DOUBLELISTNODE_H

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
	DoubleListNode(T value) : Node<T>(value) {
		next = nullptr;
		prev = nullptr;
	}
	~DoubleListNode(void) {}
};

#endif