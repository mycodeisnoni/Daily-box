#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int arr[3][3] = { {3,4,1},{2,1,4},{3,3,0} };
	int odd = 0;
	int add = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] % 2) {
				odd++;
			}
			else {
				add++;
			}
		}
	}

	cout << "Â¦¼ö : " << add << '\n';
	cout << "È¦¼ö : " << odd;

	return 0;
}