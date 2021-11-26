#pragma once

#include <iostream>
using namespace std;


template <class T>
class TStack
{
private:
	int MaxSize; // размер
	int NumLast; // номер последнего элемента
	T* mas;   // массив

public:
	TStack(int _Size = 10)
	{
		if ((_Size <= 0) || (_Size > 1000))
		{
			throw "Некоретный размер стека";
		}
		else
		{
			MaxSize = _Size;
			mas = new T[MaxSize];
			NumLast = -1;
		}
	}
	TStack(const TStack& s)
	{
		MaxSize = s.MaxSize;
		NumLast = s.NumLast;
		mas = new T[MaxSize];
		for (int i = 1; i <= NumLast; i++)
		{
			mas[i] = s.mas[i];
		}
	}
	~TStack() { delete[] mas; }

	TStack& operator=(const TStack& s);
	bool operator==(const TStack& s);
	bool operator!=(const TStack& s);
	bool Empty();              //проверка на пустоту
	bool Full();               //проверка на полноту
	void Clear();              //очистка стека

	T Top();                   //посмотреть последний элемент
	T Pop();                   //взять последний элемент
	void Push(const T& n);     //положить элемент
};



template <class T>
TStack<T>& TStack<T>:: operator=(const TStack& s)
{
	if (MaxSize != s.MaxSize)
	{
		delete[] mas;
		MaxSize = s.MaxSize;
		mas = new T[MaxSize];
	}
	NumLast = s.NumLast;
	for (int i = 1; i <= NumLast; i++)
	{
		mas[i] = s.mas[i];
	}
	return *this;
}

template <class T>
bool TStack<T>:: operator==(const TStack& s)
{
	bool f = 0;
	if (MaxSize == s.MaxSize)
	{
		for (int i = 0; i < MaxSize; i++)
		{
			if (mas[i] == s.mas[i])
				f = 1;
			else
			{
				f = 0;
				break;
			}
		}
		return f;
	}
	else
		return f;
}

template <class T>
bool TStack<T>:: operator!=(const TStack<T>& s)
{
	bool f = 1;
	if (MaxSize == s.MaxSize)
	{
		for (int i = 0; i < MaxSize; i++)
		{
			if (mas[i] == s.mas[i])
				f = 0;
			else
			{
				f = 1;
				break;
			}
		}
		return f;
	}
	else
		return f;
}

template <class T>
bool TStack<T>::Empty()
{
	if (NumLast == -1)
		return true;
	else
		return false;
}

template <class T>
bool TStack<T>::Full()
{
	if (NumLast == (MaxSize - 1))
		return true;
	else
		return false;
}

template <class T>
void TStack<T>::Clear()
{
	NumLast = -1;
}

template <class T>
T TStack<T>::Top()
{
	//исключение если нечего смотреть
	if (Empty())
		throw "Стек пуст";
	else
		return mas[NumLast];
}

template <class T>
T TStack<T>::Pop()
{
	if (Empty())
		throw NumLast;
	else
		return mas[NumLast--];

}

template <class T>
void TStack<T>::Push(const T& n)
{
	if (Full())
		throw "Стек полон";
	else
		NumLast++;
	mas[NumLast] = n;

}