#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int a,b;
	cin >> a >> b;

	if (a > b) {
		if ((a - b) % 2) {
			cout << "°í¹éÇÑ´Ù";
		}
		else {
			cout << "Â¦»ç¶û¸¸";
		}
	}
	else if (a < b) {
		if ((b - a) % 2) {
			cout << "°í¹éÇÑ´Ù";
		}
		else {
			cout << "Â¦»ç¶û¸¸";
		}
	}
	return 0;
}