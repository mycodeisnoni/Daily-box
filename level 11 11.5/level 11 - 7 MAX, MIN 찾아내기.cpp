#include<iostream>
using namespace std;

int main()
{
	int arr[7] = { 0, };

	for (int i = 0; i < 7; i++) {
		cin >> arr[i];
	}

	int max = 0;
	int  min = 10;

	for (int i = 0; i < 7; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	cout << "MAX=" << max << endl;
	cout << "MIN=" << min;

	return 0;
}
