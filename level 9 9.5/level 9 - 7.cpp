#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int arr[6][2] = { 0, };
	int temp;
	int cnt = 0;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 6; i++) {
		if (arr[i][0] < arr[i][1]) {
			temp = arr[i][0];
			arr[i][0] = arr[i][1];
			arr[i][1] = temp;
			cnt++;
		}
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 2; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}

	cout << cnt << "Έν";

	return 0;
}