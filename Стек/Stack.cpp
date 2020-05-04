#include "Stack.h"
#include "ListStack.h"
#include "VectorStack.h"
#include "StackImplementation.h"

#include <stdexcept>

using namespace std;

Stack::Stack(StackContainer container)
	: _containerType(container)
{
	switch (container)
	{
	case StackContainer::List :{
		_pimpl = new ListStack();	// конкретизируйте под ваши конструкторы, если надо
		break;
	}
	case StackContainer::Vector :{
		_pimpl = new VectorStack();	// конкретизируйте под ваши конструкторы, если надо
		break;
	}
	default:
		throw std::runtime_error("Неизвестный тип контейнера");
	}
}

Stack::Stack(const ValueType* valueArray, const size_t arraySize, StackContainer container)

    : _containerType(container)
    {
    switch (container)
    {
        case StackContainer::List: {
        _pimpl = new ListStack();// конкретизируйте под ваши конструкторы, если надо
        for(size_t i = 0; i < arraySize;i++)
		{
            _pimpl->pushStack(valueArray[i]);
        }
        break;
       }

        case StackContainer::Vector: {
        _pimpl = new VectorStack(); // конкретизируйте под ваши конструкторы, если надо
        for(size_t i = 0; i < arraySize;i++)
        {
            _pimpl->pushStack(valueArray[i]);
        }
        break;
        }

        default:
            throw std::runtime_error("Неизвестный тип контейнера");
        }
    }

Stack::Stack(const Stack& copyStack)
 : _containerType(copyStack._containerType), _pimpl(copyStack._pimpl)
{
	*_pimpl = *(copyStack._pimpl);
}

Stack& Stack::operator=(const Stack& copyStack) {
    int copySize = copyStack.size();
    if(copyStack._containerType == StackContainer::List) {
        _pimpl = new ListStack();// конкретизируйте под ваши конструкторы, если надо
    }
    if(copyStack._containerType == StackContainer::Vector) {
        _pimpl = new VectorStack();    // конкретизируйте под ваши конструкторы, если надо
    }
    ValueType* array = new ValueType[copySize];
    for (int i = copySize - 1; i >= 0; i--) {
        array[i] = copyStack._pimpl->top();
        copyStack._pimpl->popStack();
    }
    for (int i = 0; i < copySize; i++) {
        _pimpl->pushStack(array[i]);
        copyStack._pimpl->pushStack(array[i]);
    }
    delete[] array;
    return *this;
    // TODO: вставьте здесь оператор return
}

Stack::~Stack()
{
	delete _pimpl;		// композиция!
}

void Stack::push(const ValueType& value)
{
	// можно, т.к. pushStack определен в интерфейсе
    _pimpl->pushStack(value);
}

void Stack::pop()
{
    _pimpl->popStack();
}

const ValueType& Stack::top() const
{
	return _pimpl->top();
}

bool Stack::isEmpty() const
{
	return _pimpl->isEmptyStack();
}

size_t Stack::size() const
{
	return _pimpl->sizeStack();
}
