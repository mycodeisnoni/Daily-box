#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N;
int map[101][101] = { 0, };
int visited[101][101] = { 0, };
int maxheight = 0;
int lowheight = 101;
int maxcount = 1;

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
struct basket {
	int row, col;
};
queue<basket>q;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] > maxheight) maxheight = map[i][j];
			if (map[i][j] < lowheight) lowheight = map[i][j];
		}
	}
}


void func(int rain) {

	while (!q.empty()) {
		basket now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int row = now.row + dr[i];
			int col = now.col + dc[i];

			if (row >= N || row < 0 || col >= N || col < 0) continue;	// map벗어나면 pass
			if (map[row][col] <= rain) continue;	// 물에 잠겼으면 pass
			if (visited[row][col]) continue;		// 이미 방문 시 pass

			q.push({ row,col });
			visited[row][col] = 1;	// 방문체크
		}
	}
}


int main() {

	init();
	for (int rain = lowheight; rain <= maxheight; rain++) {
		memset(visited, 0, sizeof(visited));
		int nowcount = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > rain && visited[i][j] == 0) {
					nowcount++;
					q.push({ i,j });
					func(rain);	// 물에 잠기거나 방문하지 않은 곳을 마주할 때 마다 bfs 호출
				}
			}
		}
		if (nowcount > maxcount) maxcount = nowcount;
	}

	cout << maxcount;

	return 0;
}