#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int a, b, c;
	int MaxValue, MinValue;
	cin >> a >> b >> c;

	if (a >= b && a >= c) {
		MaxValue = a;
	}
	else if (b >= c && b >= a) {
		MaxValue = b;
	}
	else {
		MaxValue = c;
	}

	if (a <= b && a <= c) {
		MinValue = a;
	}
	else if (b <= c && b <= a) {
		MinValue = b;
	}
	else {
		MinValue = c;
	}

	cout << "MAX=" << MaxValue << '\n';
	cout << "MIN=" << MinValue;


	return 0;
}