#include <iostream>
using namespace std;

char arr[2][3] = { {'F','E','W'},{'D','C','A'} };


void findCh(char tar) {
	int cnt = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] == tar) {
				cnt++;
			}
		}
	}
	if (cnt == 1) {
		cout << "발견";
	}
	else {
		cout << "미발견";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char tar;
	cin >> tar;

	findCh(tar);
	return 0;
}