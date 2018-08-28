#pragma once

#include "LinkcedList.h"

template<typename T>
class MyStack
{
private:
	LinkedList<T> stack;
	size_t size;

public:
	MyStack() : stack(), size(0) {}
	~MyStack();
	// 복사생성자 대입연산자 정의 해야함

	T Pop() const;
	bool Push(T data);
	const size_t Size() const;
};

template<typename T>
inline MyStack<T>::~MyStack()
{
	stack.DeleteAll();
}

template<typename T>
inline T MyStack<T>::Pop() const
{
	if (!size)
		throw;
	size--;
	T result = stack.GetData(-1);
	stack.DeleteNode(stack.GetHead());

	return result;
}

template<typename T>
inline bool MyStack<T>::Push(T data)
{
	size++;
	return stack.InsertFront(data);
}

template<typename T>
inline const size_t MyStack<T>::Size() const
{
	return size;
}