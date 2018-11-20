#include "Queue.h"
#include "Stack.h"
#include "Functions.h"
int main()
{
	try
	{
		//std::cout << "Enter the expression: \n";

		int count = 2;

		queue<char> a(count);
		Stack<char> b(count);
		input(b, count);
		b.Show();
		//a.show();
		
		


















	}
	catch (int)
	{
		std::cout << "GG";
	}
	return 0;
}
