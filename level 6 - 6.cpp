#include <iostream>
using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char st;
	cin >> st;

	if (st >= 'A' && st <= 'Z') {
		cout << "�빮���Դϴ�";
	}
	if (st >= 'a' && st <= 'z') {
		cout << "�ҹ����Դϴ�";
	}
	return 0;
}