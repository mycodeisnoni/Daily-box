#include<iostream>
using namespace std;

int main()
{
	int arr[7] = { 3,4,1,3,2,7,3 };

	int a;
	cin >> a;

	int flag = 0;
	for (int i = 0; i < 7; i++) {
		if (arr[i] == a) {
			flag = 1;
			break;
		}
	}

	if (flag == 1) {
		cout << "�߰�";
	}
	else {
		cout << "�̹߰�";
	}

	return 0;
}
