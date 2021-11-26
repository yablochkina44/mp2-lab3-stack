#include <string>
#include <iostream>
#include "TStack.h"
#include "TCalculator.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	//TStack<int> st(10);
	//for (int i = 0; i < 10; i++)
	//{
	//	st.Push(i * 2);
	//}

	//while (!st.Empty())
	//{
	//	cout << st.Pop() << endl;
	//}


	//string str = "(2+2)*2(";
	//TStack <char> ch(20);

	//for (int i = 0; i < str.size(); i++)
	//{
	//	if (str[i] == '(')
	//	{
	//		ch.Push(str[i]);
	//	}

	//	if (str[i] == ')')
	//	{
	//		ch.Pop();
	//	}
	//}

	//if (ch.Empty())
	//{
	//	cout << "Расстановка корректна" << endl;
	//}
	//else
	//{
	//	cout << "Расстановка не корректна" << endl;
	//}

	cout << "-------------------" << endl;
	cout << "Калькулятор" << endl;
	TCalculator ex;
	ex.SetExpression("((3-1)*1)^3");
	cout << ex.ToPostfix() << endl;
	cout << ex.CalcPostfix() << endl;
	cout << ex.Calc() << endl;



}



/*main
TStack<int> st(10);
st.Push(5);
st.Push(2);
// очистить стек
1 зад. пока не эмпти брать элементы
2 зад. (2+2)*2 запсиано в строке String (include <string>)
String str = "(2+2)*2";
str.size(); или str.length(); размер или длина одно и тоже
str[0];
проверить корректность расстановки скобок
число скобок[2)+3+(3-6)] и их вложенность[ 2-)3+2( ] соответсвовала
идти по строке если видим открыавающую скобку кладем в стек  TStack<char >
увидели закрывающую вынули
если стек пустой то скобки корректны
если не дошли до конца стек неправильный если открывающих скобок оч много
// еа след занятии вычисление арифм выражения

*/