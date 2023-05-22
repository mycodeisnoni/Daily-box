#include<iostream>
using namespace std;
int main()
{
	int vect[4][4];
	int x, y;
	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			cin >> vect[y][x];
		}
	}
	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			if (vect[y][x] == 0) cout << "!";
			else if (vect[y][x] % 2 == 0) cout << "#";
			else if (vect[y][x] % 2 == 1) cout << "@";
		}
		cout << endl;
	}
	return 0;
}
