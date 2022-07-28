#include<iostream>
using namespace std;

int input() {
	int a;
	cin >> a;
	return a;
}

int calc(int x,int y,int z) {
	int sum = 0;
	sum = x + y + z;
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();


	int num1, num2, num3;

	num1 = input();
	num2 = input();
	num3 = input();

	cout << calc(num1, num2, num3);

	return 0;
}
