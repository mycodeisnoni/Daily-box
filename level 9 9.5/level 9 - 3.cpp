#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char arr[6] = { 'A','F','G','A','B','C' };
	char x, y;
	cin >> x >> y;
	int cntx = 0;
	int cnty = 0;


	for (int i = 0; i < 6; i++) {
		if (arr[i] == x) {
			cntx++;
		}
		if (arr[i] == y) {
			cnty++;
		}
	}

	if (cntx != 0 && cnty != 0) {
		cout << "��2��";
	}
	else if (cntx != 0 || cnty != 0) {
		cout << "��1��";
	}
	else {
		cout << "��0��";
	}

	return 0;
}