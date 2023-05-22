#include <iostream>
#include <cstring>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int vect[7] = { 3,5,1,1,2,3,2 };
	int arr[4] = { 0, };
	int cnt[4] = { 0, };

	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			if (arr[i] == vect[j]) cnt[i]++;
		}
	}

	for (int i = 0; i < 4; i++) {
		cout << arr[i] << "=" << cnt[i] << "°³\n";
	}

	return 0;
}