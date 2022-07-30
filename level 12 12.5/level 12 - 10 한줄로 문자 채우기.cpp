#include<iostream>
#include <string>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char arr[5][5] = { 0, };
	int a;
	char x;

	cin >> a >> x;

	for (int i = 4; i >= 0; i--) {
			arr[a-1][i] = x;
			x++;
	}
	

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] == '\0') { cout << 0; }
			else { 
				cout << arr[i][j];
			}
		}
		cout << '\n';
	}

	return 0;
}
