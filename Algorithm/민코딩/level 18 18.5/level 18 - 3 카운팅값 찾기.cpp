#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int arr[3][5] = {
	{1, 3, 3, 5, 1},
	{3, 6, 2, 4, 2},
	{1, 9, 2, 6, 5}
	};

	int map[10] = { 0, };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			map[arr[i][j]]++;
		}
	}
	
	int N;
	cin >> N;

	for (int i = 1; i <= 9; i++) {
		if (map[i] == N) cout << i << " ";
	}


	return 0;
}