#include<iostream>
#include <string>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int arr[3][3] = { 0, };
	char x;
	cin >> x;
	int cnt = 1;
	if (x >= '0' && x <= '9') {
		for (int i = 2; i >= 0; i--) {
			for (int j = 2; j >= i; j--) {
				arr[i][j] = cnt;
				cnt++;
			}
		}
	}
	else if (x >= 'A' && x <= 'Z') {
		for (int i = 2; i >= 0; i--) {
			for (int j = 0; j <= i; j++) {
				arr[i][j] = cnt;
				cnt++;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] == 0) { cout << " "; }
			else { cout << arr[i][j]; }
		}cout << endl;
	}


	return 0;
}
