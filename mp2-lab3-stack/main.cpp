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
	//	cout << "����������� ���������" << endl;
	//}
	//else
	//{
	//	cout << "����������� �� ���������" << endl;
	//}

	cout << "-------------------" << endl;
	cout << "�����������" << endl;
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
// �������� ����
1 ���. ���� �� ����� ����� ��������
2 ���. (2+2)*2 �������� � ������ String (include <string>)
String str = "(2+2)*2";
str.size(); ��� str.length(); ������ ��� ����� ���� � ����
str[0];
��������� ������������ ����������� ������
����� ������[2)+3+(3-6)] � �� �����������[ 2-)3+2( ] ��������������
���� �� ������ ���� ����� ������������ ������ ������ � ����  TStack<char >
������� ����������� ������
���� ���� ������ �� ������ ���������
���� �� ����� �� ����� ���� ������������ ���� ����������� ������ �� �����
// �� ���� ������� ���������� ����� ���������

*/