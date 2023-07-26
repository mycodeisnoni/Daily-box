#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int costRecord;
int maxcost;
struct node {
	int day, cost;
};
vector<node>talk;
int nowMax[1500001] = { 0, };	// N일 까지의 최대 비용 기록용

void init() {
	cin >> N;
	talk.push_back({ 0,0 });	// idx맞추기 용
	for (int i = 0; i < N; i++) {
		int day, cost = 0;
		cin >> day >> cost;
		talk.push_back({ day, cost });
	}
}

void calc() {
	for (int i = 1; i <= N; i++) {
		// i : 현재 일수 
		int nowDay = talk[i].day;		// 몇일이 걸리는 상담인지(오늘 포함)
		int nowCost = talk[i].cost;		// 얼마를 받을 수 있는 상담인지

		if (nowDay + i - 1 <= N) {
			nowMax[nowDay + i - 1] = max(nowMax[nowDay + i - 1], maxcost + nowCost);
		}
		if (nowMax[i] > maxcost) maxcost = nowMax[i];
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	calc();
	cout << maxcost;
	return 0;
}