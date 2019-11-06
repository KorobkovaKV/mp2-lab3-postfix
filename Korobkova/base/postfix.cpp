#include "postfix.h"
#include "stack.h"

string TPostfix::ToPostfix()
{
	TStack<char> STACK(MaxStackSize);		//создаем стэк
	int L = infix.length();					//размер инф
	string OPERATIONS = "+-*/()";			//используемые операции
	for (int i = 0; i < L; i++)					//проходимся по infix
	{
		for (int k = 0; k < 6; k++)				// если не операция
		{
			if (infix[i] != OPERATIONS[k])
			{
				postfix += infix[i];
			}
		}
		if ((infix[i] >= '0') && (infix[i] <= '9'))
		{
			if (i != L)					//если не последний элемент
			{
				if ((infix[i + 1] < '0') || (infix[i + 1] > '9'))			//если следующий не цифра
				{
					postfix += '\\';										// разделитель //
				}
			}

			else						// если последний
			{
				postfix += '\\';
			}
		}
		if (infix[i] == '(')			//если ( , то в стэк
		{
			STACK.PUSH_El(infix[i]);
		}
		if (infix[i] == ')')			// если ), то всё из стэка в постфикс
		{
			char a = STACK.POP_El();
			while (a != '(')
			{
				postfix += a;
				a = STACK.POP_El();
			}
		}
		for (int k = 0; k < 4; k++)				// если не операция
		{
			if (infix[i] == OPERATIONS[k])			//если операция
			{
				if (STACK.Empty() == true)				//если стэк пуст, то операцию в стэк
				{
					STACK.PUSH_El(infix[i]);
				}
				else
				{
					int b1 = OPERATIONS.find(infix[i]);				// ищем индекс операции
					while (STACK.Empty() == false)
					{
						char s = STACK.POP_El();		//последний элемент, который решал в стэке
						if (s == '(')				//если (
						{
							STACK.PUSH_El(s);			//возвращаем в стэк
							break;
						}
						int b2 = OPERATIONS.find(s);				// ищем индекс операции s
						if (operation_priority[b2] <= operation_priority[b1])
						{
							postfix += s;
						}
						else
						{
							STACK.PUSH_El(s);
							break;
						}
					}
					STACK.PUSH_El(infix[i]);
				}

			}
		}

	}
	while (STACK.Empty() == false)					//записываем из стэка постфикс
	{
		postfix += STACK.POP_El();
	}
	return postfix;
}

double TPostfix::Calculate()
{
	if (postfix.length() == 0)
	{
		ToPostfix();											//создаем постфиксную форму
	}
	int LEN = postfix.length();							//размер постф
	TStack<char> STACK(MaxStackSize);
	string nameArguments;								//массив имен
	double *Arguments = new double[LEN];				//массив значений

	for (int i = 0; i < LEN; i++)					//проходимся по postfix
	{
		bool IsNotOperation;
		for (int k = 0; k < 6; k++)				// если не операция
		{
			if (postfix[i] != operations[k])
			{
				IsNotOperation = true;					//это не операция
			}
			else
				IsNotOperation = false;				//это операция
		}
		if (IsNotOperation == true)
		{
			double z;
			bool FirstTime;
			if ((postfix[i] < '0') || (postfix[i] > '9'))					//cимвол не цифра
			{
				for (int j = 0; j < nameArguments.length(); j++)			//проходим по массиву имен пременных
				{
					if (postfix[j] != nameArguments[j])					// если первый раз встр
					{
						FirstTime = true;
					}
					else
					{
						FirstTime = false;
					}
				}
				if (FirstTime == true)							//переменная встр первый раз
				{
					nameArguments += postfix[i];									//записали имя переменной			
					cout << "Введите значение переменной - " << postfix[i] << endl;
					cin >> z;
					Arguments[nameArguments.length() - 1] = z;								//записали значение переменной в массив заначений
				}
				else if (FirstTime == false)				// если встречается переменная не в первый раз
				{
					z = Arguments[nameArguments.find(postfix[i])];			//в р записываем значение соответсвующей переменной
				}
			}
			else
			{
				string NUMBER;
				while (postfix[i] != '\\')									//пока не найдем разделитель
				{
					NUMBER += postfix[i];
					i++;
				}
				z = stoi(NUMBER);										//преобразует строку в число
			}
			STACK.PUSH_El(z);										//положили в стэк
		}
		else if (IsNotOperation == false)
		{
			double arg1, arg2, Res;

			arg2 = STACK.POP_El();							//Взяли из стека последний элемент
			arg1 = STACK.POP_El();							//Взяли из стека предпоследний элемент

			switch (postfix[i])							//определяем операцию
			{
			case '+':										//если +
				Res = arg1 + arg2;
				break;
			case '-':										//если -
				Res = arg1 - arg2;
				break;
			case '*':										//если *
				Res = arg1 * arg2;
				break;
			case '/':										//если /
				Res = arg1 / arg2;
				break;
			}
			STACK.PUSH_El(Res);								//положили в стек результат операции
		}
	}
	delete[] Arguments;										//удаляем массив значений
	double result = STACK.POP_El();

	return result;											//возвращаем единственный элемент стека 
}
