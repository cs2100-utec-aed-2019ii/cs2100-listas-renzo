#pragma once

template <typename T>
class Node {
private:
	template <typename B>
	friend class ForwardList;
	
protected:
	T data;
	Node* Next;

public:
	Node() : Next{ nullptr } {}
	T& operator *() { return data; }
};
