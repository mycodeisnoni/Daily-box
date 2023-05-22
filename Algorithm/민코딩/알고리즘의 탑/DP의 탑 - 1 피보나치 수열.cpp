#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

int map[50] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	cin >> n;

	map[0] = 0;
	map[1] = 1;

	for (int i = 2; i < n; i++) {
		map[i] = map[i - 1] + map[i - 2];
	}

	cout << map[n - 1];

}