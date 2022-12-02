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

	char arr[5] = { 0, };
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 5; i++) {

	checkChar(arr[i]);

	}

	return 0;
}