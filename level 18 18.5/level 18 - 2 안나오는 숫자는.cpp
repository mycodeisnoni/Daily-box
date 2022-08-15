#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int MAP[3][3] = { 0, };
	int num[10] = { 0, };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> MAP[i][j];
			num[MAP[i][j]]++;
		}
	}

	for (int i = 1; i <= 9; i++) {
		if (!num[i]) cout << i << " ";
	}
	


	return 0;
}