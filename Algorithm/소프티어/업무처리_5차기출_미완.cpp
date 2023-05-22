#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H,K,R;
int worker = 1;
vector<vector<int>>task;
vector<int>order;
vector<int>idxCalc;

void init() {
	cin >> H >> K >> R;

	for (int i = 0; i < H; i++) {
		worker *= 2;
	}

	for (int i = 0; i < worker; i++) {
		for (int j = 0; j < K; j++) {
			int a;
			cin >> a;
			task[i].push_back(a);
		}
	}
}

// 처리를 어떻게 할까
// H가 총 높이, 현재 말단 사원의 수 = 2^H
// 인덱스 순서
// 절반 뚝 잘라서 앞
// 0, H/2
// 다시 절반 잘라서 0,H/2 인덱스에 더한다
// 0 + H/4, H/2 + H/4
// 다시 절반 잘라서  이전 인덱스들에 더한다
// 이 때, 이전 모든 인덱스들에 대한 정렬이 필요하다,
//  0 + H/8, 0 + H/4+H/8, H/2+H/8 + H/2+H/4+H/8
// 일단 순서는 다 지정해놓고 처리 가능한 업무만큼 확인
// 언제까지 하냐면, worker-1==마지막으로 계산한 인덱스


// 전체 직원(인덱스)순서를 정해주는 함수
void mergesort() {
	int now = worker;
	order.push_back(0);
	order.push_back(worker / 2);
	idxCalc.push_back(0);
	idxCalc.push_back(worker / 2);

	int config = 0;
	while (worker - 1 == config) {
		sort(idxCalc.begin(), idxCalc.end());
		int num = idxCalc.size();
		for (int i = 0; i < num; i++) {
			int nowidx = idxCalc[i];
			config = nowidx + now / 2;
			order.push_back(config);
			idxCalc.push_back(config);
		}	
	}
}

// 업무 처리 가능 일수에 따른 처리업무계산
int owner() {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	init();
	mergesort();
	int ans = owner();
	cout << ans;

	return 0;
}