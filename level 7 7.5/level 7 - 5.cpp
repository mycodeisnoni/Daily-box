#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int a;
	cin >> a;

	if (a >= 80) {
		cout << "��";
	}
	else if (a >= 70) {
		cout << "��";
	}
	else if (a >= 60) {
		cout << "��";
	}
	else {
		cout << "��õ�";
	}

	return 0;
}