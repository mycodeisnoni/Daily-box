#include <iostream>
using namespace std;

int a, i;

void BBQ() {
	if (a > 0 && a < 5) {
		cout << "�ʱⰪ";
	}
	else if (a > 6 && a < 10) {
		cout << "�߰���";
	}

	else {
		cout << "�˼����°�";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> a;

	if (a == 3 || a == 5 || a == 7) {
		for (i = 1; i <= 10; i++) {
			cout << i;
		}
	}

	else if (a == 0 || a == 8) {
		for (i = 10; i > 0; i--) {
			cout << i;
		}
	}

	else {
		BBQ();
	}

	return 0;
}