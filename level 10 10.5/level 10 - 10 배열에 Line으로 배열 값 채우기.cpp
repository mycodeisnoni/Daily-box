#include<iostream>
using namespace std;
int main()
{
	int arr[3][4];
	int t = 1;
	int x, y;
	for (y = 2; y >= 0; y--)
	{
		for (x = 3; x >= 0; x--) {
			arr[y][x] = t;
			t++;
		}
	}
	int input;
	cin >> input;
	for (y = 0; y < 3; y++)
	{
		arr[y][input] = 0;
	}
	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 4; x++)
		{
			cout << arr[y][x] << " ";
		}
		cout << endl;
	}
	return 0;
}
