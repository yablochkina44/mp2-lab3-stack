#pragma once
#include <string>
#include <stdlib.h>
#include <iostream>
#include "TStack.h"

//2+5*4-3     infix
//2 5 4 * + 3 -     postfix
//push polosh 
//pop vzyat
//calc.SetExpr("2+2")
//calc.ToPostfix();
//cout << calc.GetPostfix();
//cout << calc.Calc;

using namespace std;
class TCalculator
{
	string expr;             // выражение в инфиксной форме
	string postfix;          // выражение в постфиксной форме
	TStack <string> st_c;      // стэк для операций
	TStack <double> st_d;    // стек для чисел 

	int Priority(const string& op);      // определение приоритетных операций
	bool isOperator(char c);		   	 // операция?
	bool isFunction(const string& func);	 //функция?
	bool isNumber(char c);				 // число?
	void ClearStacks();					 //очистить стеки
	void PushResultOp(const string&);	 //посчитать выражение
	void PushResultFunc(const string&);	 //посчитать функцию

public:

	TCalculator(string _expr = "") : expr(_expr) {};      //конструктор 
	//~TCalculator();
	double CalcPostfix();	    // вычислить в постфиксной форме
	double Calc();				//вычислить в инфиксной форме
	void ToPostfix();			// Перевод в постфиксную форму
	void SetExpression(string c = "") { expr = c; };
	string GetPost() { return postfix; }
	bool CheckBrackets();	 // проверка расстановки скобок
};