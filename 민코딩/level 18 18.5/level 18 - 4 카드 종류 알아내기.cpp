#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int map[100] = { 0, };

	string x;
	cin >> x;
	
	int minchar = 1000;
	int maxchar = -1;

	for (int i = 0; i < x.size(); i++) {
		map[x[i]]++;
		if (x[i] > maxchar) maxchar = x[i];
		if (x[i] < minchar) minchar = x[i];
	}

	int cnt = 0;
	for (int i = minchar; i <= maxchar; i++) {
		if (map[i] != 0) cnt++;
	}

	cout << cnt << "°³";

	return 0;
}