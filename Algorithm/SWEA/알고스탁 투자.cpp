#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct Node {
	int price, profit;
};

int Money, m, N, record;
int map[15][15];
int maxProfit;
vector <Node> v;
int Original = 0;

void init() {
	cin >> Money >> m;
	Original = Money;
	cin >> N >> record;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= record; j++) {
			cin >> map[i][j];
		}
	}
}

void DP(int MM, int profit) {
	if (profit > maxProfit) {
		maxProfit = profit;
	}

	for (int i = 0; i < v.size(); i++) {
		if (MM - v[i].price < 0) continue;
		MM -= v[i].price;
		profit += v[i].profit;
		DP(MM, profit);
		MM += v[i].price;
		profit -= v[i].profit;
	}
	return;
}

int solve(int month) {

	if (month > record) return Money;
	if (month >= 1) Money += m;

	v.clear();

	for (int i = 0; i < N; i++) {
		if (map[i][month] < map[i][month + 1]) v.push_back({ map[i][month], map[i][month + 1] - map[i][month] });
	}

	// �̵��� ���� �ż��� 2�� �̻� ���� ��� DP
	// 1���� ���� ��� �� ���� Ǯ�ż�
	// ���� ��� �ƹ��͵� ��������(����) ���� �޷� ����

	if (v.size() >= 2) {
		int MM = Money;
		DP(MM, 0);
		Money += maxProfit;
		maxProfit = 0;
	}

	else if (v.size() == 1) {
		int cnt = Money / v[0].price;
		Money += cnt * v[0].profit;
	}

	month++;
	solve(month);
}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		maxProfit = 0;
		memset(map, 0, sizeof(map));
		init();
		int ans = solve(0);
		cout << "#" << tc << " " << ans - Original - m * record << "\n";
	}
	return 0;
}

