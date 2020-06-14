#include "ListStack.h"

void ListStack::push(const ValueType& value) {
	this->LinkedList::pushFront(value);
}

void ListStack::pop() {
    this->LinkedList::removeFront();
}

const ValueType& ListStack::top() const{
	return LinkedList::getNode(0)->value;
}

bool ListStack::isEmpty() const {
	if (this->LinkedList::size() == 0)
		return true;
	return false;
}
size_t ListStack::size() const {
	return this->LinkedList::size();
}