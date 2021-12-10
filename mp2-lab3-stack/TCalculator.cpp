#include "TCalculator.h"
//#include "TStack.h"
#include "MyExceptoin.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;


//size_t ind;
//string tmp = "2.3 + 3.4";
// stod(tmp,&ind);
//cout << "ind= "<<ind<<endl;
int TCalculator::Priority(const string& op)
{
	if (op == "(" || isFunction(op))
		return 0;
	if (op == "+" || op == "-")
		return 1;
	if (op == "*" || op == "/")
		return 2;
	if (op == "^")
		return 3;	
};
bool TCalculator::isOperator(char c)
{
	if ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^'))
		return true;
	else
		return false;
}
bool TCalculator::isFunction(const string& func)
{
	if ((func == "sin") || (func == "cos") || (func == "tg"))
		return true;
	else
		return false;
}
bool TCalculator::isNumber(char c)
{
	if (c <= '9' && c >= '0')
		return true;
	return false;
}
void TCalculator::ClearStacks()
{
	st_d.Clear();
	st_c.Clear();
}
void TCalculator::PushResultOp(const string& op)
{
	double b = st_d.Pop();
	double a = st_d.Pop();

	if (op == "+")
	{
		st_d.Push(a + b);
	}
	else if (op == "-")
	{
		st_d.Push(a - b);
	}
	else if (op == "*")
	{
		st_d.Push(a * b);
	}
	else if (op == "/")
	{
		st_d.Push(a / b);
	}
	else if (op == "^")
	{
		st_d.Push(pow(a, b));
	}
}
void TCalculator::PushResultFunc(const string& func)
{
	double a = st_d.Pop();

	if (func == "sin")
	{
		st_d.Push(sin(a));
	}
	else if (func == "cos")
	{
		st_d.Push(cos(a));
	}
	else if (func == "tg")
	{
		st_d.Push(tan(a));
	}
}
double TCalculator::CalcPostfix()
{
	for (int i = 0; i < postfix.size(); i++)
	{
		if (isNumber(postfix[i]))
		{
			size_t ind;
			double tmp = stod(&postfix[i], &ind);
			st_d.Push(tmp);
			i += ind - 1;
			continue;
		}
		if (isOperator(postfix[i]))
		{
			if (st_d.Empty())
				throw "—тек пуст";
			PushResultOp(string(1,postfix[i]));
			continue;
		}
		if (postfix[i] != ' ')
		{
			string func;
			while (postfix[i] != ' ')
				func += postfix[i++];
			if (isFunction(func))
				PushResultFunc(func);
		}
	}
	postfix = "";
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
			continue;
		}
		if (infix[i] == '(')
		{
			st_c.Push("(");
			continue;
		}
		if (infix[i] == ')')
		{
			while (st_c.Top() != "(")
			{
				string op = st_c.Pop();
				PushResultOp(op);
			}
			st_c.Pop();
			if (!st_c.Empty() && isFunction(st_c.Top()))
				PushResultFunc(st_c.Pop());
			continue;
		}
		if (isOperator(infix[i]))
		{
			while (Priority(st_c.Top()) >= Priority(string(1,infix[i])))
			{
				string op = st_c.Pop();
				PushResultOp(op);
			}
			st_c.Push(string(1,infix[i]));
			continue;
		}

		if (infix[i] != ' ')
		{
			string func="";
			while (infix[i] != '(')
			{
				func += infix[i];
				i++;
			}
			while (!func.empty() && isspace(func[func.size() - 1]))
				func.erase(func.size() - 1);
			if (isFunction(func))
			{
				st_c.Push(func);
				st_c.Push("(");
				continue;
			}
			else
				throw MyExceptoin("Function unknow");
		}
	}
	double res = st_d.Pop();
	if (st_d.Empty())
		return res;
	else
		throw MyExceptoin("Expression not correct");
};
void TCalculator::ToPostfix()
{
	string infix = "(" + expr + ")";
	postfix = "";
	ClearStacks();
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == ' ')
			continue;
		if (isNumber(infix[i]))
		{
			size_t ind;
			double num = stod(&infix[i], &ind);
			postfix += to_string(num);
			postfix += ' '; // ' '
			i += ind - 1;
			continue;
		}
		if (infix[i] == '(')
		{
			st_c.Push("(");
			continue;
		}

		if (infix[i] == ')')
		{
			while (st_c.Top() != "(")
			{
				
				postfix += st_c.Pop();
				postfix += " ";
			}
			st_c.Pop();
			if (!st_c.Empty() && isFunction(st_c.Top()))
			{
				postfix += st_c.Pop();
				postfix += " ";
			}
			continue;
		}

		if (isOperator(infix[i]))
		{
			while (Priority(st_c.Top()) >= Priority(string(1,infix[i])) && !st_c.Empty())
			{
				postfix += st_c.Pop();
				postfix += " ";
			}
			st_c.Push(string(1,infix[i]));
			continue;
		}
		string func = "";
		while (infix[i] != '(')
		{
			func += infix[i];
			i++;
		}
		while (!func.empty() && isspace(func[func.size() - 1]))
		{
			func.erase(func.size() - 1);
		}

		if (isFunction(func))
		{
			st_c.Push(func);
			st_c.Push("(");
			continue;
		}
		else
			throw MyExceptoin("Function unknow");
	}
	// empy строка пуста€?
	// erase(iterator p) стирает символ на который указывает p
	// isspace(int ch) €вл€етс€ ли ch пробелом?qs

}
bool TCalculator::CheckBrackets()
{
	int size = expr.size();
	TStack<char> st_br(size);

	for (int i = 0; i < size; i++)
	{
		if (expr[i] == '(')
			st_br.Push('(');
		try
		{
			if (expr[i] == ')')
				st_br.Pop();
		}
		catch (const MyExceptoin&)
		{
			cout << "The placement of brackets is incorrect :(" << endl;
			return 0;
		}
	}

	if (!st_br.Empty())
	{
		cout << "The placement of brackets is incorrect :(" << endl;
		return 0;
	}
	cout << "The placement of brackets is correct :)" << endl;
	return 1;
}

//void TCalculator::SetExpression(string c)
//{
//	TStack <char> ch;
//	for (int i = 0; i < c.size(); i++)
//	{
//		if (c[i] == '(')
//		{
//			ch.Push(c[i]);
//		}
//
//		if (c[i] == ')')
//		{
//			if (ch.Empty())
//			{
//				exit(0);
//			}
//			else
//			{
//				ch.Pop();
//			}
//		}
//	}
//	if (ch.Empty())
//	{
//		expr = c;
//	}
//	else
//	{
//		exit(0);
//
//	}
//
//};