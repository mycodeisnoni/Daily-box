#include<iostream>
#include <cstring>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int arr[5][4] = { 0, };

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			sum += arr[i][j];
		} cout << sum << " ";
	}

	return 0;
}
