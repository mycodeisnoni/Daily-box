
#include<iostream>
using namespace std;
void PrintData(int value)
{
	cout << value << endl;
}
void even(int value)
{
	PrintData(value * 2);
}
void odd(int value)
{
	PrintData(value - 10);
}
int main()
{
	int a, b, c;
	cin >> a >> b;
	c = a / b;
	if (c % 2 == 0)
	{
		even(c);
	}
	else
	{
		odd(c);
	}
	PrintData(a + b);
}