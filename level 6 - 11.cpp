#include <iostream>
using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char ch1, ch2, x;
	cin >> ch1 >> ch2;


	for (int i = 0; i < 4; i++) {

		for (x = ch1; x <= ch2; x++) {
		cout << x << " ";
		}
		cout << '\n';
	}

	return 0;
}