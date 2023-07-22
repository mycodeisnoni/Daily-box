#include<iostream>
using namespace std;
int main()
{
	int arr[3][3];
	int input;
	int x, y;
	cin >> input;
	if (input % 5 == 1)
	{
		int t = 1;
		for (x = 2; x >= 0; x--)
		{
			for (y = 2; y >= 0; y--)
			{
				arr[y][x] = t;
				t++;
			}
		}
	}
	else if (input % 5 == 2)
	{
		int t = 1;
		for (y = 2; y >= 0; y--)
		{
			for (x = 0; x < 3; x++)
			{
				arr[y][x] = t;
				t++;
			}
		}
	}
	else {
		int t = 10;
		for (x = 0; x < 3; x++)
		{
			for (y = 0; y < 3; y++)
			{
				arr[y][x] = t;
				t++;
			}
		}
	}
	//Ãâ·Â
	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			cout << arr[y][x] << " ";
		}
		cout << endl;
	}
	return 0;
}
