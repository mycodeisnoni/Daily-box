#include <iostream>
#include <cstring>
using namespace std;

void CompareGo(int arr[5],int input[5]) {
	int flag = 0;
	for (int i = 0; i < 5; i++) {
		if (arr[i] != input[i]) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) cout << "�ι迭����������";
	else cout << "�ι迭����������";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int arr[5] = { 3,5,1,2,7 };
	int input[5] = { 0, };

	for (int i = 0; i < 5; i++) {
		cin >> input[i];
	}

	CompareGo(arr, input);

	return 0;
}