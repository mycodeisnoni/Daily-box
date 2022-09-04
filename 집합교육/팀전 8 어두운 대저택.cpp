#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int cnt;
int visited[101][101] = { 0, };
int map[101][101] = { 0, };
struct Node {
	int row, col;
};
vector<Node>v[101][101];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };


// 해당 점을 방문할 수 있는지 확인해주는 함수
bool CanVisit(int row, int col) {

	// 조사하고자 하는 점의 상하좌우를 확인
	// 한 점이라도 불이 켜져있으면서 방문 했던 점이어야 그 경로를 통해
	// 해당 점에 방문 가능한 것으로 판단
	for (int i = 0; i < 4; i++) {
		int nr = row + dr[i];
		int nc = col + dc[i];
		if (nr<1 || nc<1 || nr>N || nc>N) continue;
		if (!visited[nr][nc]) continue;
		if (!map[nr][nc]) continue;
		return true;
	}
	return false;
}

// 방문한 점들에 대한 작업을 해주는 함수
void search(int row, int col) {

	// 1. 방문했다고 기록 해주기
	visited[row][col] = 1;

	// 2. 방문한 점에 있는 스위치들 불켜주기
	for (int i = 0; i < v[row][col].size(); i++) {
		Node now = v[row][col][i];
		if (!map[now.row][now.col]) {
			map[now.row][now.col] = 1;
			cnt++;

			// ?
			// 3. 불을 켠 점이 갈 수 있는 점인지 확인
			// 갈 수 있는 점이면 방문!
			if (CanVisit(now.row, now.col)) {
				search(now.row, now.col);
			}
		}
	}

	// 4. 현재 위치에서 상하좌우로 이동이 가능한 점이 있나 확인
	for (int i = 0; i < 4; i++) {
		int nr = row + dr[i];
		int nc = col + dc[i];
		if (nr<1 || nc<1 || nr>N || nc>N) continue;
		if (!map[nr][nc]) continue;
		if (visited[nr][nc]) continue;
		search(nr, nc);
	}

	return;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		v[y1][x1].push_back({ y2,x2 });
	}

	map[1][1] = 1;
	cnt = 1;
	search(1, 1);
   
	cout << cnt;
}