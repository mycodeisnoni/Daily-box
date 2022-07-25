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
		cout << "더 큰수를 입력하세요" << "\n";
	}
	else if (arr[i] == 20) {
		cout << "정답입니다\n";
	}
	else {
		cout << "더 작은수를 입력하세요\n";
	}
	}

	return 0;
}