#include <iostream>
using namespace std;

char flag, a, b, c;

void input() {
	cin >> a >> b >> c;
}

void process() {
	if (a == 'A' && b == 'B' && c == 'C') {
		flag = 1;
	}
}

void output() {
	if (flag == 1) {
		cout << "ABC��ã�Ҵ�";
	}
	else {
		cout << "��ã�Ҵ�";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	input();
	process();
	output();

	return 0;
}