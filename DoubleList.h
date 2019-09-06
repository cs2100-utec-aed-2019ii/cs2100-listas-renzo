#pragma once
#include "DoubleListNode.h"
#include "List.h"

template <typename T>
class DoubleList : public List<T> {
protected:
	DoubleListNode<T>* head;
	DoubleListNode<T>* tail;
};