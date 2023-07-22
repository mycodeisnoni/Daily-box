#include<iostream>
using namespace std;

int main()
{
	char a, b, c;
	cin >> a >> b >> c;

	char* x = &a;
	char* y = &b;
	char* z = &c;

	(*x)++;
	(*y)++;
	(*z)++;

	cout << *x << " " << *y << " " << *z;


	return 0;
}
