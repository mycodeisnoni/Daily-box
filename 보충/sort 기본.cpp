#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//int arr[10] = { 4,3,5,1,2,1,2,1,3,5 };
//
//
//// 3. custom cmp ���
//// � �ƱԸ�Ʈ�� � ���� ���縻�� �Ű� �Ⱦ�
//// a�� b ���� �� ���ʿ� ��ġ�� �ֶ�� true
//// �ƴϸ� false
//bool cmp(int a, int b) {
//	if (a < b) return true;
//	return false;
//}
//int main() {
//
//	// 1. ��������
//	sort(arr, arr + 10);
//	int d = 1;
//	
//	// 2. ��������
//	sort(arr, arr + 10, greater<int>());
//	
//	
//	return 0;
//}



//=========================================================


vector<int> arr = { 32,12,5,3,21 };

// 3.��������
// ���ڸ� �� �켱 => ���� �� �켱
bool cmp(int a, int b) {
	// a�� b���� �� ���ʿ� ��ġ�Ǿ���ϸ� true
	// �ƴϸ� false

	if (a >= 10 && b < 10) return true;
	if (a < 10 && b >= 10) return false;
	if (a < b) return false;
	return false;
}

int main() {
	// 1.��������
	sort(arr.begin(), arr.end());
	// 2.��������
	sort(arr.begin(), arr.end(), greater<int>());
	

	// 3.
	sort(arr.begin(), arr.end(), cmp);

	return 0;
}



