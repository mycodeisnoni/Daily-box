#include<iostream>
using namespace std;

int sum(int a, int b) {
	return a + b;
}

int comp(int a, int b) {
	if (a >= b) {
		return a - b;
	}
	else {
		return b - a;
	}
}

void print(int t1, int t2) {
	cout << "ÇÕ:" << t1 << endl;
	cout << "Â÷:" << t2;
}

int main()
{
	int a, b;
	cin >> a >> b;
	print(sum(a, b),comp(a, b));


	return 0;
}
