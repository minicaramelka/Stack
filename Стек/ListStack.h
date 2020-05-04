#pragma once

#include"LinkedList.h"
#include "StackImplementation.h"
 // меняете на include вашего листа

// вариант с использованием ранее написанного списка и множественного наследования
// если бы список не был реализован, то было бы наследование только от интерфейса
// множественное наследование можно заменить на композицию
class ListStack : public StackImplementation, public LinkedList
{

	void pushStack(const ValueType& value);
	// удаление с хвоста
	void popStack();
	// посмотреть элемент в хвосте
	const ValueType& top() const;
	// проверка на пустоту
	bool isEmptyStack() const;
	// размер 
	size_t sizeStack() const;
};