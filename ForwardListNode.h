#pragma once
#include "Node.h"

template <typename T>
class ForwardListNode : public Node<T> {
private:
	template <typename B>
	friend class ForwardList;

protected:
	ForwardListNode* next;

public:
	ForwardListNode() {
		next = nullptr;
	}
	ForwardListNode(T value): Node(value) {
		next = nullptr;
	}
	~ForwardListNode(void) {}
};