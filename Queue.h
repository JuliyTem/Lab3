#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>

template <class T>
class queue
{
	int size, top, end;
	T *p;
public:

	queue(int _size = 0) : size(_size), top(0), end(size - 1)
	{
		p = new T[size];
	}
	queue(const queue &b)
	{
		size = b.size;
		top = b.top;
		end = b.end;
		p = new T[size];

		int i = top;
		while (i != end + 1)
		{
			p[i] = b.p[i];
			i = (i + 1) % size;
		}
	}
	~queue()
	{
		delete [] p;
	}
	bool is_empty()
	{
		return((end + 1) % size == top);
	}
	bool is_full()
	{
		return((end + 2) % size == top);
	}
	void push(T val)
	{
		if (is_full()) throw -1;
		end = (end + 1) % size;
		p[end] = val;
	}
	T pop()
	{
		if (is_empty()) throw - 1;
		int k = top;
		top = (top + 1) % size;
		return (p[k]);
	}
	queue<T>&operator=(const queue<T> &b)
	{
		if (&b == this) return *this;
		delete[]p;
		size = b.size;
		top = b.top;
		end = b.end;
		p = new T[size];

		int i = top;
		while (i != end + 1)
		{
			p[i] = b.p[i];
			i = (i + 1) % size;
		}
		return *this;
	}
	void show()
	{
		int i = top;
		std::cout << "\n|";
		while (i != end + 1)
		{
			std::cout << p[i];
			i = (i + 1) % size;
		}
		
	}
};

template<class T>
void input(queue<T> &a, int &count)
{
	char k = '\0';

	while (true)
	{
		a.push(k);
		k = getch();
		if (k == 8)
		{
			if (!a.is_empty())
			{
				a.pop();
				//count--;
				copy(a, count);
				std::cout << "\b" << '\0' << "\b";
			}
		} else 
			if (k == 13) break; else
			{
				count++;
				std::cout << k;
				copy(a, count);
			}
	}
}
template<class T>
void copy(queue<T> &a, int count)
{
	queue<char> b(count);
 
	while ((!a.is_empty()) && (!b.is_full()))
	{
		b.push(a.pop());
	}
	a = b;
}
