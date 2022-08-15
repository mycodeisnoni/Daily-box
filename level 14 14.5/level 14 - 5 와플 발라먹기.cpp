#include <iostream>
#include <cstring>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int arr[3][3] = { 0, };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	int sum = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= i; j++) {
			sum += arr[i][j];
		}
	}

	cout << sum;

	return 0;
}