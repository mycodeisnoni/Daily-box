#include <iostream>
using namespace std;

struct Data {
	int x;
	int y;
	int z;
};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	Data a, b;
	cin >> a.x >> a.y >> a.z >> b.x >> b.y >> b.z;
	cout << a.x + b.x << endl;
	cout << a.y + b.y << endl;
	cout << a.z + b.z << endl;



	return 0;
}