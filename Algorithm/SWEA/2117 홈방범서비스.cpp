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


// 좌표를 받으면
// 그 점에 대해서 범위를 확장시켜가며 최대 포함 가능 집 개수를 센다.
// 안된다고 끝내면 안됨 <- 2가 안됐는데 3, 4가 될 수도 있으므로 끝까지!
int BFS(int row, int col) {

	int Maxhouse = -1;
	memset(used, 0, sizeof(used));

	qNow.push({ row,col });
	used[row][col] = 1;

	int dr[4] = { -1,1,0,0 };
	int dc[4] = { 0,0,-1,1 };
	int K = 2;

	// 들어온 점에 집이 있을 경우 그걸 포함해서 세어주어야함
	int houseCnt = 0;
	if (map[row][col]) houseCnt++;

	// K의 크기를 N까지만 설정하면 오답 나는 경우가 있다.
	// 넉넉하게 설정할 것
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

		// map위의 모든 좌표에 대해 BFS
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