#pragma once

template <typename T>
class Node {
protected:
	T value;

public:
	Node() = default;
	Node(T _value) : value{_value} {}
	~Node(void) {}
	T& operator *() { return value; }
};