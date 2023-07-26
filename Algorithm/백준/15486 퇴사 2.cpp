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
int nowMax[1500001] = { 0, };	// N�� ������ �ִ� ��� ��Ͽ�

void init() {
	cin >> N;
	talk.push_back({ 0,0 });	// idx���߱� ��
	for (int i = 0; i < N; i++) {
		int day, cost = 0;
		cin >> day >> cost;
		talk.push_back({ day, cost });
	}
}

void calc() {
	for (int i = 1; i <= N; i++) {
		// i : ���� �ϼ� 
		int nowDay = talk[i].day;		// ������ �ɸ��� �������(���� ����)
		int nowCost = talk[i].cost;		// �󸶸� ���� �� �ִ� �������

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