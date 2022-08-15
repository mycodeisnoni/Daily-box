#include <iostream>
using namespace std;

int map[4][4] = { 0, };

int rectSum(int y, int x) {
	int sum = 0;
	for (int i = y; i < y + 2; i++) {
		for (int j = x; j < x + 3; j++) {
			sum += map[i][j];
		}
	}
	return sum;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> map[i][j];
		}
	}

	int maxsum = -1;
	int maxrow = -1;
	int maxcol = -1;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			int sum = rectSum(i, j);
			if (sum > maxsum) {
				maxsum = sum;
				maxrow = i;
				maxcol = j;
			}
		}
	}

	cout << "(" << maxrow << "," << maxcol << ")";

	return 0;
}