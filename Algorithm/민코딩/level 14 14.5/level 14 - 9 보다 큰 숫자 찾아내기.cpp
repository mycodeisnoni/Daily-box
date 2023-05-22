#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int arr[6] = { 10,50,40,20,30,40 };
	int newarr[6] = {0,};

	for (int i = 0; i < 6; i++) {
		cin >> newarr[i];
	}

	int cnt[6] = { 0, };

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (newarr[i] < arr[j]) cnt[i]++;
		}
	}

	for (int i = 0; i < 6; i++) {
		cout << newarr[i] << "=" << cnt[i] << "°³\n";
	}
	return 0;
}