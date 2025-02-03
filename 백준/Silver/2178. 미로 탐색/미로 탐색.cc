#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[101][101] = { 0, };
int visited[101][101] = { 0, };
struct Node {
	int row, col, cnt;
};
bool operator <(Node A, Node B) {
	if (A.cnt > B.cnt) return true;
	else return false;
}
priority_queue<Node>pq;
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,-1,1 };

void init() {
	cin >> N >> M;
	for (int row = 1; row <= N; row++) {
		string x;
		cin >> x;
		for (int col = 1; col <= M; col++) {
			map[row][col] = x[col - 1] - '0';
		}
	}
}

int finding() {
	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nr = now.row + dr[i];
			int nc = now.col + dc[i];
			int ncnt = now.cnt + 1;

			if (nr <1 || nr > N || nc < 1 || nc > M) continue;
			if (map[nr][nc] == 0) continue;
			if (visited[nr][nc]) continue;

			visited[nr][nc] = ncnt;
			if (nr == N && nc == M) return ncnt;
			pq.push({ nr, nc, ncnt });
		}
	}
}

int main() {

	init();
	pq.push({ 1,1,1 });
	visited[1][1] = 1;
	int ans = finding();
	cout << ans;

	return 0;
}