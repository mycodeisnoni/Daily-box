#include <iostream>
using namespace std;

char arr[2][3] = { {'F','E','W'},{'D','C','A'} };


void checkChar(char tar) {
	if (tar >= 'A' && tar <= 'Z') {
		cout << "´ë";
	}
	else if (tar >= 'a' && tar <= 'z') {
		cout << "¼Ò";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	struct Person
	{
		int age;
		int height;
	};

	Person a;
	Person b;

	cin >> a.age >> a.height >> b.age >> b.height;

	cout << (a.age + b.age) / 2 << " " << (a.height + b.height) / 2;

	return 0;
}