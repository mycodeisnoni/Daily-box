#include<iostream>
using namespace std;
int input()
{
	int input;
	cin >> input;
	return input;
}
void CountDown(int input)
{
	int x;
	for (x = input; x >= 1; x--)
	{
		cout << x << " ";
	}
}
int main()
{
	CountDown(input());
	return 0;
}
