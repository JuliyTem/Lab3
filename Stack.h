#pragma once
#include <iostream>
template <class T>
class Stack
{
	T *p;
	int index, size;
public:
	Stack(int _size = 0) : size(_size), index(-1)
	{
		p = new T[size];
	}
	Stack(const Stack &b)
	{
		size = b.size;
		index = b.index;
		p = new T[size];
		for (int i = 0; i < index + 1; i++)
		{
			p[i] = b.p[i];
		}
	}
	~Stack()
	{
		delete[]p;
	}
	bool is_empty()
	{
		return(index == -1);
	}
	bool is_full()
	{
		return(index == size - 1);
	}
	void push(T val)
	{
		if (is_full()) throw - 1;
		index++;
		p[index] = val;
	}
	T pop()
	{
		if (is_empty()) throw - 1;
		index--;
		return(p[index + 1]);
	}
	Stack<T>&operator=(const Stack<T> &b)
	{
		if (&b == this) return *this;
		delete[]p;
		size = b.size;
		index = b.index;
		p = new T[size];
		for (int i = 0; i < index + 1; i++)
		{
			p[i] = b.p[i];
		}
		return *this;
	}
	void Show()
	{
		std::cout << "\n|";
		for (int i = 0; i < index + 1; i++)
		{
			std::cout << "" << p[i];
		}
	}

};

template<class T>
void copy(Stack<T> &a, int &count)
{
	Stack<char> b(count);
	Stack<char> c(count);

	while ((!a.is_empty()) && (!b.is_full()))
	{
		b.push(a.pop());
	}
	while ((!b.is_empty()) && (!c.is_full()))
	{
		c.push(b.pop());
	}
	a = c;
}
template<class T>
void input(Stack<T> &a, int &count)
{
	char k = '\0';

	while (true)
	{
		k = _getch();
		if (k == 8)
		{
			if (!a.is_empty())
			{
				a.pop();
				//count--;
				//copy(a, count);
				std::cout << "\b" << '\0' << "\b";
			}
		}
		else
			if (k == 13) break; else
			{
				count++;
				std::cout << k;
				copy(a, count);
				a.push(k);
			}
	}
}
