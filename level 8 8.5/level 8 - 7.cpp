#include <iostream>
using namespace std;

char st;
char ch1[5] = { 'B','D','5','Q','A' };
char ch2[5] = { 'Q','E','R','E','F' };


void input() {
	cin >> st;
}

void output() {
	if (st >= 'a' && st <= 'z') {
		for (int i = 0; i < 5; i++) {
			cout << ch1[i];
		}
	}
	else if (st >= 'A' && st <= 'Z') {
		for (int i = 0; i < 5; i++) {
			cout << ch2[i];
		}
	}
	else {
		for (char x = 'H'; x >= 'A'; x--) {
			cout << x;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	input();
	output();

	return 0;
}