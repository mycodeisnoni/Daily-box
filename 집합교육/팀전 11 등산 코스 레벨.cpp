#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
	int row, col;
};
vector< Node> v;
int map[501][501] = { 0, };
int N, M;
int maxheight = -1;
int visited[501][501] = { 0, };
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
queue<Node>q;


bool CanHike(int mid) {

	memset(visited, 0, sizeof(visited));
	q.push({ v[0].row, v[0].col });
	visited[v[0].row][v[0].col] = 1;

	while (!q.empty()) 
	{
		Node now = q.front();
		q.pop();
		int pr = now.row;
		int pc = now.col;
		for (int i = 0; i < 4; i++) {
			int nr = pr + dr[i];
			int nc = pc + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
			if (visited[nr][nc]) continue;
			if (abs(map[nr][nc] - map[pr][pc]) > mid) continue;
			q.push({ nr,nc });
			visited[nr][nc] = 1;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (visited[v[i].row][v[i].col] == 0) return false;
	}

	return true;
}

int decision() {

	int left = 0;
	int right = maxheight;
	int mid;
	int temp = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (CanHike(mid)) { 
			temp = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}

	return temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] > maxheight) maxheight = map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;
			if (a) v.push_back({ i,j });
		}
	}

	cout << decision();
	
	return 0;
}