#include<iostream>
#include <string>
using namespace std;


void getName(char *a, char *b) {
	cin >> *a >> *b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char a, b;

	getName(&a,&b);

	if (a <= b) {
		cout << a;
	}
	else { cout << b; }

	return 0;
}
