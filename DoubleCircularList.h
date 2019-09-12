#pragma once
#include "DoubleListNode.h"
#include "List.h"

template <typename T>
class DoubleCircularList : public List<T> {
protected:
	DoubleCircularList<T>* head;
};