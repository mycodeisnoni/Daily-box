#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int a;
	int arr1[5] = { 3,5,2,4,1 };
	int arr2[3][2] = { {9,8},{7,1},{3,4} };

	cin >> a;

	if (a % 2) {
		for (int i = 0; i < 5; i++) {
			cout << arr1[i];
		}
	}

	if (!(a % 2)) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++) {
				cout << arr2[i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}