#include<iostream>
#include <string.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int arr[4][4] = { {1,3,6,2},{4,2,4,5},{6,3,7,3},{1,5,4,6} };

	int a;
	cin >> a;

	select[16] = { 0, };

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			if (arr[row][col] > a) {
				select[strlen(select)] = arr[row][col];
			}
		}
	}
	
	for (int i = 0; i < strlen(select); i++) {
		cout << select[i] << " ";
	}
	

	return 0;
}
