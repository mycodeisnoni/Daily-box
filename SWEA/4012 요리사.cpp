#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[16][16] = { 0, };
vector <int> v;
vector <int> cal;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		// v�� ������ ����
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				v.push_back(map[i][j] + map[j][i]);
			}
		}

		// ������ ����
		sort(v.begin(), v.end());

		// ������ ���̸� �ٽ� ���� cal�� ����
		for (int i = 0; i < v.size() - 1; i++) {
			cal.push_back(abs(v[i] - v[i + 1]));
		}

		// cal ���� ����
		sort(cal.begin(), cal.end());
		int ans = cal[0];
	}

	return 0;
}