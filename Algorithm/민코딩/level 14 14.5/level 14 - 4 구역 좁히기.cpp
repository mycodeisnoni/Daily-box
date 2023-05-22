#include <iostream>
#include <cstring>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char arr[6] = { 0, };
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	
	for (int i = 4; i >= 0; i--) {
		for (int j = 4 - i; j < 5; j++) {
			cout << arr[j] << " ";
		}cout << endl;
	}

	return 0;
}