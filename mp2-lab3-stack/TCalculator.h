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
	TStack <string> st_c;      // ���� ��� ��������
	TStack <double> st_d;    // ���� ��� ����� 

	int Priority(const string& op);      // ����������� ������������ ��������
	bool isOperator(char c);		   	 // ��������?
	bool isFunction(const string& func);	 //�������?
	bool isNumber(char c);				 // �����?
	void ClearStacks();					 //�������� �����
	void PushResultOp(const string&);	 //��������� ���������
	void PushResultFunc(const string&);	 //��������� �������

public:

	TCalculator(string _expr = "") : expr(_expr) {};      //����������� 
	//~TCalculator();
	double CalcPostfix();	    // ��������� � ����������� �����
	double Calc();				//��������� � ��������� �����
	void ToPostfix();			// ������� � ����������� �����
	void SetExpression(string c = "") { expr = c; };
	string GetPost() { return postfix; }
	bool CheckBrackets();	 // �������� ����������� ������
};