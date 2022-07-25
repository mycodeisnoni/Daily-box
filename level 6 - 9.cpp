#include <iostream>
using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char st,x;
	cin >> st;

	for (x = 'A'; x <= st; x++) {
		cout << x;
	}

	return 0;
}