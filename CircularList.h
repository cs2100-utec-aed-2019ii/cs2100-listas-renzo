#pragma once
#include "ForwardListNode.h"
#include "List.h"

template <typename T>
class CircularList : public List<T> {
protected:
	ForwardListNode<T>* head;
};