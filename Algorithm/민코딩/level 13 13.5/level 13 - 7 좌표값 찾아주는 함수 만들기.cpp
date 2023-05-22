#include <iostream>
#include <cstring>
using namespace std;

char arr[3][3] = {
	'A','D','F',
	'Q','W','E',
	'Z','X','C'
};

void find(char x, int*row,int*col) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] == x) {
				*row = i;
				*col = j;
				break;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char x;
	cin >> x;
	int row = -1;
	int col = -1;
	find(x,&row,&col);

	cout << row << "," << col;
	return 0;
}