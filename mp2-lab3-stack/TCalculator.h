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
	string expr;             // ��������� � ��������� �����
	string postfix;          // ��������� � ����������� �����
	TStack <char> st_c;      // ���� ��� ��������
	TStack <double> st_d;    // ���� ��� ����� 

	int Priority(char c);    // ����������� ������������ ��������
	bool isOperator(char c); // ��������?
	bool isNumber(char c);   // �����?
	void ClearStacks();

public:

	TCalculator();      //����������� 
	//~TCalculator();
	double CalcPostfix();	    // ��������� � ����������� �����
	double Calc();				//��������� � ��������� �����
	string ToPostfix();			// ������� � ����������� �����
	void SetExpression(string c);

};