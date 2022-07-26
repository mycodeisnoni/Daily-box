#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	struct ABC
	{
		int x;
		int y;
	};

	int a, b;
	cin >> a >> b;


	ABC t;
	t.x = a;
	t.y = b;

	cout << t.x + t.y;



	return 0;
}