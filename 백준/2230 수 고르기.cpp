#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int>arr;	// 수열 기록
vector<int>v;	// 차이만 기록해둘 벡터

void init() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	for (int i = 1; i < N; i++) {	// 정렬
		v.push_back(arr[i] - arr[i - 1]);
	}
}

int calc() {
	int left = 0;
	int right = -1;
	int cnt = 0;
	int ans = 2e9;

	while (left < N - 1) {

		if (cnt == M) return M;
		else if (cnt > M) {
			if (cnt < ans) ans = cnt;
			cnt -= v[left];
			left++;
		}
		else {
			if (right + 1 < N - 1) {
				right++;
				cnt += v[right];
			}
			else return ans;
		}
	}
	return ans;
}

int main() {
	init();
	int ans = calc();
	cout << ans;
	return 0;
}