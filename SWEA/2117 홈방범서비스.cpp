#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int map[20][20] = { 0, };
int used[20][20] = { 0, };

struct Node {
	int row, col;
};
queue <Node> qNow;
queue <Node> qNext;

int BFS(int row, int col) {

	int Maxhouse = -1;
	memset(used, 0, sizeof(used));

	qNow.push({ row,col });
	used[row][col] = 1;

	int dr[4] = { -1,1,0,0 };
	int dc[4] = { 0,0,-1,1 };
	int K = 2;
	int houseCnt = 0;
	if (map[row][col]) houseCnt++;

	while (K<=N+1) {

		while (!qNow.empty()) {

			Node now = qNow.front();
			qNow.pop();

			for (int d = 0; d < 4; d++) {
				int nr = now.row + dr[d];
				int nc = now.col + dc[d];

				if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
				if (used[nr][nc]) continue;

				used[nr][nc] = 1;
				if (map[nr][nc]) houseCnt++;
				qNext.push({ nr,nc });
			}
		}

		while (!qNext.empty()) {
			qNow.push(qNext.front());
			qNext.pop();
		}

		if (houseCnt * M >= K * K + (K - 1) * (K - 1)) {
			if (houseCnt > Maxhouse) Maxhouse = houseCnt;
		}
		K++;
	}

	while (!qNow.empty()) {
		qNow.pop();
	}

	return Maxhouse;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		int maxValue = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int nowValue = BFS(i, j);
				if (nowValue > maxValue) maxValue = nowValue;
			}
		}
		cout << "#" << tc << " " << maxValue << "\n";
	}

	return 0;
}