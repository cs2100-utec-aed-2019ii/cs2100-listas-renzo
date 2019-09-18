template <typename T>
class Node {
protected:
	T value;

public:
  typedef T value_t;

	Node() = default;
	Node(T _value) : value{_value} {}
	~Node(void) {}
	T& operator *() { return value; }
};
