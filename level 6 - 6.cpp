#include <iostream>
using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char st;
	cin >> st;

	if (st >= 'A' && st <= 'Z') {
		cout << "대문자입니다";
	}
	if (st >= 'a' && st <= 'z') {
		cout << "소문자입니다";
	}
	return 0;
}