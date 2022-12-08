#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

//int map[100][100] = { 0, };

int max(int a, int b) {
	if (a >= b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int rowmax = 0;
	int colmax = 0;
	int xmax = 0;
	int rowsum = 0;
	int colsum = 0;
	int xsum1 = 0;
	int xsum2 = 0;

	for (int tc = 1; tc <= 10; tc++) {
		int i;
		cin >> i;
		int map[100][100] = { 0, };

		for (int row = 0; row < 100; row++) {
			for (int col = 0; col < 100; col++) {
				cin >> map[row][col];
				rowsum += map[row][col];
			}
			if (rowsum > rowmax) rowmax = rowsum;
			rowsum = 0;
		}

		for (int col = 0; col < 100; col++) {
			for (int row = 0; row < 100; row++) {
				colsum += map[row][col];
			}
			if (colsum > colmax) colmax = colsum;
			colsum = 0;
		}

		for (int i = 0; i < 100; i++) {
			xsum1 += map[i][99 - i];
		}
		for (int i = 0; i < 100; i++) {
			xsum2 += map[99-i][i];
		}

		int realmax = max(max(max(rowmax, colmax), max(xsum1, xsum2)), max(max(rowmax, xsum1), max(colmax, xsum2)));

		cout << "#"<< tc << " " << realmax << endl;
		xsum1 = 0;
		xsum2 = 0;
		rowmax = 0;
		colmax = 0;
	}
	
	return 0;
}