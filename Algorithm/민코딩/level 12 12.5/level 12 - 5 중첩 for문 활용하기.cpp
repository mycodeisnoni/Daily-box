#include<iostream>
#include <string>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int arr[3][4] = { 0, };
	int a;
	cin >> a;

	for (int row = 0; row < 3; row++) {
		for (int col = 2 - row; col < 4; col++) {
			arr[row][col] = a;
			a++;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 0) cout << " ";
			else cout << arr[i][j];
		}cout << '\n';
	}

	return 0;
}
