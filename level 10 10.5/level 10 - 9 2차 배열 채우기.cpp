#include<iostream>
using namespace std;
int main()
{
	int vect[4][4] = { 0 };
	int x, y, t;
	t = 1;
	for (x = 3; x >= 0; x--) {
		for (y = 0; y < 4; y++) {
			vect[y][x] = t++;
		}
	}
	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			cout << vect[y][x] << " ";
		}
		cout << endl;
	}
	return 0;
}
