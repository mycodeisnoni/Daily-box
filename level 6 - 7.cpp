#include <iostream>
using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int a, i;
	cin >> a;

	for (i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			cout << "#";
		}
		cout << "\n";
	}

	return 0;
}