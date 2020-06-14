#include "VectorStack.h"

void VectorStack::push(const ValueType& value) {
	this->MyVector::pushBack(value);
}

void VectorStack::pop() {
	this->MyVector::popBack();
}

const ValueType& VectorStack::top() const {
	return (*this)[this->MyVector::size() - 1];
}

bool VectorStack::isEmpty() const {
	if (this->MyVector::size() == 0)
		return true;
	return false;
}

size_t VectorStack::size() const {
	return this->MyVector::size();
}
