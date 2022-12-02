#include <iostream>
using namespace std;

int a;
char x;

int one() {
	cin >> a;
	return a;
}

char two() {
	cin >> x;
	return x;
}

int main() {
	cout << one();
	cout << two();

	return 0;
}