#include <iostream>
using namespace std;

int N, K;
int arr[200001] = { 0, };
int counting[100001] = { 0, };
int leftIdx = 0;
int rightIdx = -1;
int maxlength = 0;


void init() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void tp() {
	while (rightIdx < N) {
		rightIdx++;
		counting[arr[rightIdx]]++;
		if (counting[arr[rightIdx]] > K) {
			if (rightIdx - leftIdx > maxlength) maxlength = rightIdx - leftIdx;
			while (arr[leftIdx] != arr[rightIdx]) {
				counting[arr[leftIdx]]--;
				leftIdx++;
			}
			counting[arr[leftIdx]]--;
			leftIdx++;
		}
	}
	if (rightIdx - leftIdx > maxlength) maxlength = rightIdx - leftIdx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	tp();
	cout << maxlength;

	return 0;
}