#include "TCalculator.h"
#include "TStack.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;


//size_t ind;
//string tmp = "2.3 + 3.4";
// stod(tmp,&ind);
//cout << "ind= "<<ind<<endl;
int TCalculator::Priority(char c)
{
	setlocale(LC_ALL, "Russian");
	int p;
	switch (c)
	{
	case '(': p = 0; break;
	case ')': p = 0; break;
	case '+': p = 1; break;
	case '-': p = 1; break;
	case '*': p = 2; break;
	case '/': p = 2; break;
	case '^': p = 3; break;
	default: p = -1; break;
	}
	return p;
};

bool TCalculator::isOperator(char c)
{
	if ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^'))
		return true;
	else
		return false;
};

bool TCalculator::isNumber(char c)
{
	if (c <= '9' && c >= '0')
	{
		return true;
	}
	else return false;
}
void TCalculator::ClearStacks()
{
	st_d.Clear();
	st_c.Clear();
};


//конструкторо хз
TCalculator::TCalculator()
{
	//expr = c;

}


double TCalculator::CalcPostfix()
{
	for (int i = 0; i < postfix.size(); i++)
	{
		if (isNumber(postfix[i]))
		{
			double tmp = stod(&postfix[i]);
			st_d.Push(tmp);
		}
		if (isOperator(postfix[i]))
		{
			if (st_d.Empty())
				throw "Стек пуст";
			double b = st_d.Pop();
			double a = st_d.Pop();
			switch (postfix[i])
			{
			case '+': st_d.Push(a + b); break;
			case '-': st_d.Push(a - b); break;
			case '*': st_d.Push(a * b); break;
			case '/': st_d.Push(a / b); break;
			case '^': st_d.Push(pow(a, b)); break;
			default: throw 0; break;
			}

		}
	}
	return st_d.Pop();
}

double TCalculator::Calc()
{
	string infix = "(" + expr + ")";
	ClearStacks();

	for (int i = 0; i < infix.length(); i++)
	{
		if (isNumber(infix[i]))
		{
			size_t ind;
			double num = stod(&infix[i], &ind);
			st_d.Push(num);
			i += ind - 1;
		}
		if (infix[i] == '(')
		{
			st_c.Push('(');
		}
		if (infix[i] == ')')
		{
			while (st_c.Top() != '(')
			{
				double b = st_d.Pop();
				double a = st_d.Pop();
				switch (st_c.Pop())
				{
				case '+': st_d.Push(a + b); break;
				case '-': st_d.Push(a - b); break;
				case '*': st_d.Push(a * b); break;
				case '/': st_d.Push(a / b); break;
				case '^': st_d.Push(pow(a, b)); break;
				default: throw 0; break;
				}
			}
			st_c.Pop();
		}
		if (isOperator(infix[i]))
		{
			while (Priority(st_c.Top()) >= Priority(infix[i]))
			{
				double b = st_d.Pop();
				double a = st_d.Pop();
				switch (st_c.Pop())
				{
				case '+': st_d.Push(a + b); break;
				case '-': st_d.Push(a - b); break;
				case '*': st_d.Push(a * b); break;
				case '/': st_d.Push(a / b); break;
				case '^': st_d.Push(pow(a, b)); break;
				default: throw 0; break;
				}

			}
			st_c.Push(infix[i]);
		}

	}
	return st_d.Pop();
};

string TCalculator::ToPostfix()
{
	string infix = "(" + expr + ")";
	ClearStacks();
	for (int i = 0; i < infix.size(); i++)
	{
		if (isNumber(infix[i]))
		{
			postfix += infix[i];
			postfix += ' ';
		}
		if (infix[i] == '(')
			st_c.Push('(');

		if (infix[i] == ')')
		{
			while (st_c.Top() != '(')
			{
				postfix += st_c.Pop();
				postfix += ' ';
			}
			st_c.Pop();
		}

		if (isOperator(infix[i]))
		{
			int prioritet = Priority(infix[i]);

			while (Priority(st_c.Top()) >= Priority(infix[i]) && st_c.Empty() == false)
			{
				postfix += st_c.Pop();
				postfix += ' ';
			}
			st_c.Push(infix[i]);
		}
	}
	return postfix;
}
void TCalculator::SetExpression(string c)
{
	TStack <char> ch;
	for (int i = 0; i < c.size(); i++)
	{
		if (c[i] == '(')
		{
			ch.Push(c[i]);
		}

		if (c[i] == ')')
		{
			if (ch.Empty())
			{
				exit(0);
			}
			else
			{
				ch.Pop();
			}
		}
	}
	if (ch.Empty())
	{
		expr = c;
	}
	else
	{
		exit(0);

	}

};