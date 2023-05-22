#include <iostream>
#include <vector>
using namespace std;

int map[1025][1025] = { 0, };
int prefix[1025][1025] = { 0, };

struct box {
	int x1, y1, x2, y2;
};
vector<box>v;

int calc(int x1, int y1, int x2, int y2) {
	return prefix[x2][y2] - prefix[x2][y1-1] - prefix[x1-1][y2] + prefix[x1-1][y1-1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			prefix[a][b] = prefix[a - 1][b] + prefix[a][b - 1] - prefix[a - 1][b - 1] + map[a][b];
		}
	}
	
	
	for (int a = 0; a < M; a++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		v.push_back({ x1,y1,x2,y2 });
	}

	for (int a = 0; a < M; a++) {
		int cor = calc(v[a].x1, v[a].y1, v[a].x2, v[a].y2);
		cout << cor << "\n";
	}
	

	return 0;
}