#ifndef TEST_FORWARDLISTNODE_H
#define TEST_FORWARDLISTNODE_H

template <typename T>
class ForwardListNode : public Node<T> {
private:
	template <typename B>
	friend class ForwardList;

protected:
	ForwardListNode* next;

public:
  typedef typename Node<T>::value_t value_t;

	ForwardListNode() {
		next = nullptr;
	}
	ForwardListNode(T value): Node<T>(value) {
		next = nullptr;
	}
	~ForwardListNode(void) {}
};

#endif