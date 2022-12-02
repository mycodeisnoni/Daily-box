#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	if (a > b) return true;
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int arr[6] = { 0, };
	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + 6, cmp);

	for (int i = 0; i < 6; i++) {
		cout << arr[i];
	}

	return 0;
}