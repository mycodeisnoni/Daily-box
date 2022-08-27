#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char map[30] = { 0, };


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	string x;
	cin >> x;

	int l = x.size();
	int d = l / 2;

	for (int i = 0; i < l; i++) {
		map[i] = x[i];
	}

	int de = -1;

	while (d > 0)
	{
		for (int i = 0; i <= l - d; i++) {
			int flag = 0;
			for (int j = 0; j < d; j++) {
				if (map[i + j] != map[i + d + j]) {
					flag++;
				}
			}
			if (flag == 0) {
				cout << d;
				return 0;
			}
		}
		d--;
	}

	cout << d;
	return 0;
}