#include <iostream>
using namespace std;

int main()
{
	int n;

	cin >> n;

	int x, y;

	for (y = n; y > n - 4; y--)
	{
		for (x = 0; x < 4; x++)
		{
			cout << y;
		}
		cout << endl;
	}

	return 0;
}
