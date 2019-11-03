#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"

using namespace std;

class TPostfix
{
	string infix;
	string postfix;
	string operations = "+-*/";
	int operation_priority[4] = { 1,1,2,2 };
public:
	TPostfix(string _infix = "a+b")
	{
		for (int i = 0; i < _infix.length(); i++)			// убрали пробелы и записали в infix
		{
			if (_infix[i] != ' ')
			{
				infix += _infix[i];
			}
		}
		if (infix.length() < 1)
		{
			throw "Error with lenght";
		}
	}

	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	string ToPostfix();
	double Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
