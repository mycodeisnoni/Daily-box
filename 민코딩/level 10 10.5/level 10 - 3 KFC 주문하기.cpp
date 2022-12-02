
#include <iostream>
using namespace std;
int main()
{
	int input;
	int x, y;
	int i;
	int vect[4][4] = { 0 };
	cin >> input;
	if (input % 2 == 0)
	{
		for (i = 0; i < 4; i++)
		{
			vect[i][i] = i + 1;
		}
	}
	else
	{
		x = 3;
		for (y = 0; y < 4; y++)
		{
			vect[y][x] = y + 1;
			x--;
		}
	}
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			cout << vect[y][x] << " ";
		}
		cout << endl;
	}
	return 0;
}