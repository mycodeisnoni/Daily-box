#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char arr[3][3] = { 0, };
	char x = 'A';
	int temp;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arr[i][j] = x++;
		}
	}

	int y1, x1, y2, x2;
	cin >> y1 >> x1;
	cin >> y2 >> x2;

	temp = arr[y1][x1];
	arr[y1][x1] = arr[y2][x2];
	arr[y2][x2] = temp;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}

	return 0;
}