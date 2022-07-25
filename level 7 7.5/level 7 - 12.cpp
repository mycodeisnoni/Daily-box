#include <iostream>
using namespace std;

int a, i;

void BBQ() {
	if (a > 0 && a < 5) {
		cout << "초기값";
	}
	else if (a > 6 && a < 10) {
		cout << "중간값";
	}

	else {
		cout << "알수없는값";
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