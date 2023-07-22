#include <iostream>
using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int a, i;
	cin >> a;
	int arr[6];

	for (i = 0; i < 6; i++) {
		arr[i] = a * (i + 1);
	}

	for (i = 0; i < 6; i++) {
		cout << arr[i] << " ";
	}


	return 0;
}