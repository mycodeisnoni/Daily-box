#include <iostream>
using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char arr[4] = { 'B','T','K','A' };
	int a, i;
	cin >> a;

	for (i = 0; i < a; i++) {
		for (int j = 0; j < 4; j++) {
			cout << arr[j] << " ";
		}
		cout << "\n";
	}


	return 0;
}