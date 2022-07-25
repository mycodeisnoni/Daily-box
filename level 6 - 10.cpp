#include <iostream>
using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char st;
	cin >> st;

	cout << char(st - 'a' + 'A');

	return 0;
}