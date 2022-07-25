#include <iostream>
using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char st;
	cin >> st;

	if (st >= '0' && st <= '9') {
		int a = st - '0' + 5;
		cout << a;

	}

	return 0;
}