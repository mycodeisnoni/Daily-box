#include<iostream>
#include <string.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char arr[9] = { 0, };
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	char big[9] = { 0, };
	char small[9] = { 0, };

	for (int i = 0; i < 8; i++) {
		if (arr[i] >= 'A' && arr[i] <= 'Z') {
			big[strlen(big)] = arr[i];
		}
		else {
			small[strlen(small)] = arr[i];
		}
	}

	cout << "big=";
	for (int i = 0; i<strlen(big); i++) {
		cout << big[i];
	}

	cout << endl;

	cout << "small=";
	for (int i = 0;i< strlen(small);i++) {
		cout << small[i];
	}

	return 0;
}
