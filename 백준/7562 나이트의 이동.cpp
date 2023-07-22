#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int tc;
int N;
struct place {
	int row, col;
};
int s_row, s_col, g_row, g_col;
int dr[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dc[8] = { -2,-1,1,2,2,1,-1,-2 };

int map[301][301] = { 0, };
int visited[301][301] = { 0, };
queue <place> qNow;
queue <place> qNext;

int func() {

	int cnt = 0;

	while (!qNow.empty()) {

		while (!qNow.empty()) {
			place now = qNow.front();
			qNow.pop();

			if (now.row == g_row && now.col == g_col) return cnt;    // 목적지 도착 시 리턴

			for (int i = 0; i < 8; i++) {
				int nr = now.row + dr[i];
				int nc = now.col + dc[i];

				if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
				if (visited[nr][nc]) continue;

				if (nr == g_row && nc == g_col) return cnt + 1;

				visited[nr][nc] = 1;
				qNext.push({ nr,nc });
			}
		}

		cnt++;

		while (!qNext.empty()) {
			qNow.push(qNext.front());
			qNext.pop();
		}
	}
}



int main() {

	cin >> tc;
	for (int i = 0; i < tc; i++) {

		memset(visited, 0, sizeof(visited));	// 초기화

		cin >> N;
		cin >> s_row >> s_col >> g_row >> g_col;

		qNow.push({ s_row, s_col });
		visited[s_row][s_col] = 1;
		int ans = func();
		cout << ans << '\n';

		while (!qNow.empty()) qNow.pop();
		while (!qNext.empty()) qNext.pop();
	}

	return 0;
}