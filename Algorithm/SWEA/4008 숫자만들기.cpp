#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int acc[4];
int map[15];
vector<int>calc;

void DFS(int now, int cnt) {

	if (cnt == N) {
		calc.push_back(now);
		return;
	}

	if (acc[0]) {
		now += map[cnt];
		cnt++;
		acc[0]--;
		DFS(now, cnt);
		acc[0]++;
		cnt--;
		now -= map[cnt];
	}
	if (acc[1]) {
		now -= map[cnt];
		cnt++;
		acc[1]--;
		DFS(now, cnt);
		acc[1]++;
		cnt--;
		now += map[cnt];
	}
	if (acc[2]) {
		now *= map[cnt];
		cnt++;
		acc[2]--;
		DFS(now, cnt);
		acc[2]++;
		cnt--;
		now = now / map[cnt];
	}
	if (acc[3] && map[cnt] != 0) {
		// �������� ���� ����ص־���
		int rest = now % map[cnt];
		now = now / map[cnt];
		cnt++;
		acc[3]--;
		DFS(now, cnt);
		cnt--;
		now = now * map[cnt] + rest;
		acc[3]++;
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		calc.clear();

		cin >> N;
		for (int i = 0; i < 4; i++) {
			cin >> acc[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> map[i];
		}

		// �� �����ȣ�� ������ �Է¹ް� ����,
		// ��� ������ �ε����� ���ؼ� ������ �����
		// �ϳ��ϳ� ����غ��鼭 Max, Min�� ����ؼ� �������

		DFS(map[0], 1);


		sort(calc.begin(), calc.end());

		int ans = calc[calc.size()-1] - calc[0];
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}