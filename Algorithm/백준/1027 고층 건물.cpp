#include <iostream>
#include <vector>
using namespace std;

int N;
int building[51] = { 0, };
vector<double>degree[51];


void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> building[i];

	}
}

void record() {	// ���� ���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			else degree[i].push_back(static_cast<double>(building[j] - building[i]) / (j - i));
		}
	}
}

int calc(int nowIdx) {

	double minDe = 2e9;
	double maxDe = -2e9;
	int cnt = 0;

	// nowIdx ���� ���ʿ� �ִ� ������ : �� ���� ���⸦ ������ ���δ�.
	for (int i = nowIdx - 1; i >= 0; i--) {
		double nowDe = degree[nowIdx][i];
		if (nowDe < minDe) {
			minDe = nowDe;
			cnt++;
		}
	}

	// nowIdx ���� �����ʿ� �ִ� ������ : �� ū ���⸦ ������ ���δ�.
	for (int i = nowIdx; i < degree[nowIdx].size(); i++) {
		double nowDe = degree[nowIdx][i];
		if (nowDe > maxDe) {
			maxDe = nowDe;
			cnt++;
		}
	}

	return cnt;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	record();	// ���� ����
	
	int maxSee = 0;
	for (int i = 0; i < N; i++) {
		int nowSee = calc(i);
		if (nowSee > maxSee) maxSee = nowSee;
	}

	cout << maxSee;
	return 0;
}