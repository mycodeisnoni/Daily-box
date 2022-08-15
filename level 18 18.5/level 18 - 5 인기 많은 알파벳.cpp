#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int map[26] = { 0, };

	string x;
	cin >> x;
	
	for (int i = 0; i < 8; i++) {
		map[x[i] - 'A']++;
	}

	
	int maxchar = -1;
	int maxcnt = 0;

	for (int i = 0; i < 26; i++) {
		if (map[i] == 0) continue;

		if (map[i] > maxcnt) {
			maxcnt = map[i];
			maxchar = i;
		}
	}


		cout << char(maxchar + 'A');
	return 0;
}