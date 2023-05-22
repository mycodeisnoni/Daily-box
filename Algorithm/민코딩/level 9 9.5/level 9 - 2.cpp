#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char arr[3][5] = { {'A','B','C','D','E'}, {'E','A','B','A','B'} ,{'A','C','D','E','R'} };

	char x;
	cin >> x;

	int cnt = 0;

	for (int i = 0; i < 3; i++) {
		for (int j =0; j < 5; j++) {
			if (arr[i][j] == x) {
				cnt++;
			}
		}
	}

	if (cnt >= 3) {
		cout << "대발견";
	}
	else if (cnt == 1 || cnt == 2) {
		cout << "발견";
	}
	else if (cnt == 0) {
		cout << "미발견";
	}
	return 0;
}