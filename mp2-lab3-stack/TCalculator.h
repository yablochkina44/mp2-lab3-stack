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
	TStack <char> st_c;      // стэк для операций
	TStack <double> st_d;    // стек для чисел 

	int Priority(char c);    // определение приоритетных операций
	bool isOperator(char c); // операция?
	bool isNumber(char c);   // число?
	void ClearStacks();

public:

	TCalculator();      //конструктор 
	//~TCalculator();
	double CalcPostfix();	    // вычислить в постфиксной форме
	double Calc();				//вычислить в инфиксной форме
	string ToPostfix();			// Перевод в постфиксную форму
	void SetExpression(string c);

};