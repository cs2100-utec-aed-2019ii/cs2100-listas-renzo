#pragma once

template <typename T>
class Node {
protected:
	T data;
	Node* Next;

public:
	Node() : Next{ nullptr } {}
	T& operator *() { return data; }
};