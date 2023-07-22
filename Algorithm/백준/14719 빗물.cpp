#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int H, W;
vector <int> v;
int wall[501] = { 0, };
int firstWall;	// ó������ ���� ���� �ε��� ���
int cnt = 0;


void init() {
	cin >> H >> W;
	int flag = 0;
	for (int i = 0; i < W; i++) {
		int a;
		cin >> a;
		v.push_back(a);

		if (a != 0) {	// �ϴ� ���� �ִ� �ε��� ���
			if (flag == 0) {
				firstWall = i;
				flag = 1;
			}
		}
	}
	memset(wall, -1, sizeof(wall));
	for (int i = 1; i <= v[firstWall]; i++) wall[i] = firstWall;
}



int calc() {
	for (int i = firstWall; i < W - 1; i++) {
		for (int j = 1; j <= v[i]; j++) {
			wall[j] = i;
		}
		if (v[i] < v[i + 1]) {	// �� �ڰ� ������ ������ ������ ���δ�.
			for (int j = 1; j <= v[i + 1]; j++) {	// ���� ���̱���
				if (wall[j] == -1) continue;
				cnt += (i - wall[j]);
			}
		}
	}
	return cnt;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	int ans = calc();
	cout << ans;

	return 0;
}