#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int arr[4];

	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++) {

	if (arr[i] < 20) {
		cout << "�� ū���� �Է��ϼ���" << "\n";
	}
	else if (arr[i] == 20) {
		cout << "�����Դϴ�\n";
	}
	else {
		cout << "�� �������� �Է��ϼ���\n";
	}
	}

	return 0;
}