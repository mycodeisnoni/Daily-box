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


	int select[16] = { 0, };
	int select_len = 0;

	//strlen: 문자열 길이 사용
//select_len으로 배열 길이 확인하는 방법으로 해보기
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			if (arr[row][col] > a) {
				select[select_len] = arr[row][col];
				select_len++;
			}
		}
	}

	for (int i = 0; i < select_len; i++) {
		cout << select[i] << " ";
	}



	//for (int row = 0; row < 4; row++) {
	//	for (int col = 0; col < 4; col++) {
	//		if (arr[row][col] > a) {
	//			select[strlen(select)] = arr[row][col];
	//		}
	//	}
	//}
	//
	//for (int i = 0; i < strlen(select); i++) {
	//	cout << select[i] << " ";
	//}


	return 0;
}
