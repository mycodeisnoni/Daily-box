#include <iostream>
using namespace std;

int main()
{
	int n;

	cin >> n;

	int x, y;

	for (y = 0; y < n; y++) {
		for (x = 1; x <= 3; x++) {
			cout << x;
		}
		cout << endl;
	}

	return 0;
}
