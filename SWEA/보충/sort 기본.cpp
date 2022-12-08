#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//int arr[10] = { 4,3,5,1,2,1,2,1,3,5 };
//
//
//// 3. custom cmp 사용
//// 어떤 아규먼트에 어떤 값이 들어가든말든 신경 안씀
//// a가 b 보다 더 왼쪽에 배치될 애라면 true
//// 아니면 false
//bool cmp(int a, int b) {
//	if (a < b) return true;
//	return false;
//}
//int main() {
//
//	// 1. 오름차순
//	sort(arr, arr + 10);
//	int d = 1;
//	
//	// 2. 내림차순
//	sort(arr, arr + 10, greater<int>());
//	
//	
//	return 0;
//}



//=========================================================


vector<int> arr = { 32,12,5,3,21 };

// 3.다중조건
// 두자릿 수 우선 => 작은 수 우선
bool cmp(int a, int b) {
	// a가 b보다 더 왼쪽에 배치되어야하면 true
	// 아니면 false

	if (a >= 10 && b < 10) return true;
	if (a < 10 && b >= 10) return false;
	if (a < b) return false;
	return false;
}

int main() {
	// 1.오름차순
	sort(arr.begin(), arr.end());
	// 2.내림차순
	sort(arr.begin(), arr.end(), greater<int>());
	

	// 3.
	sort(arr.begin(), arr.end(), cmp);

	return 0;
}



