#ifndef __STACK_H__
#define __STACK_H__
#include <iostream>
const int MaxStackSize = 100;

template <class T>
class TStack
{
	T *pMem;
	int size;
	int top;
public:
	TStack(int _size)
	{
		size = _size;
		top = -1;
		if ((size < 1) || (size > MaxStackSize))
			throw size;
		pMem = new T[size];
	}

	~TStack()
	{
		delete[] pMem;
	}

	void PUSH_El(T el)			// положить элемент в стэк
	{
		if (Full() == true)			// если полный
			throw "Стек заполнен";
		top++;
		pMem[top] = el;
	}

	T POP_El()			// взять элемент из стэка
	{
		if (Empty() == true)				// если пустой
			throw "Стек пуст";
		int tmp = top;
		top--;
		return pMem[tmp];
	}

	bool Empty()					// проверка на пустоту
	{
		if (top == -1)
			return true;
		else
			return false;
	}

	bool Full()						// проверка на полноту
	{
		if (top == (size - 1))
			return true;
		else
			return false;
	}
};

#endif