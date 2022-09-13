#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct Node {
	int row, col;
};
int map[8][8] = { 0, };
int visited[8][8] = { 0, };
int N, K;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int flag;
int cutting = 0;
int maxflag;

void calc(int row, int col) {

	// 상하좌우 갈  수 있는 경로 확인
	// 현재위치보다 작으면 갈 수 있다.
	// 깎은 횟수를 표시해뒀다가 한 번도 안깎았으면 한 번 깎을 수 있음
	// 단, K만큼만 깎을 수 있음
	// 단 그 점에서 되돌아 나오게되면 지도 원상복구
	// 깎는건 나보다 하나 작게만 깎아주면 된다

	for (int i = 0; i < 4; i++) {
		int nr = row + dr[i];
		int nc = col + dc[i];

		if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
		if (visited[nr][nc]) continue;
		if (map[nr][nc] - K >= visited[row][col]) continue;
		if (map[nr][nc] >= visited[row][col] && cutting == 1) continue;

		if (map[nr][nc] >= visited[row][col]) {
			visited[nr][nc] = visited[row][col] - 1;
			cutting++;
		}
		else visited[nr][nc] = map[nr][nc];
		flag++;
		calc(nr, nc);
		if (flag > maxflag) maxflag = flag;

		flag--;
	}

	if (cutting) {
		if (map[row][col] != visited[row][col])cutting--;
	}
	visited[row][col] = 0;
	// 포문을 그냥 통과했다 == 상하좌우 어디로도 가지 못했다
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		
		cin >> N >> K;
		int maxheight = -1;
		vector <Node> v;
		memset(map, 0, sizeof(map));

		// 1. 입력
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] > maxheight) maxheight = map[i][j];
			}
		}

		// 2. 출발 가능 지점(최대 높이) 기록
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == maxheight) v.push_back({ i,j });
			}
		}

		// 3. 기록된 최대 높이 마다의 최대 등산로 길이 계산
		int maxdist = 0;
		for (int i = 0; i < v.size(); i++) {
			memset(visited, 0, sizeof(visited));
			visited[v[i].row][v[i].col] = map[v[i].row][v[i].col];
			flag = 1;
			maxflag = 1;
			calc(v[i].row, v[i].col);
			if (maxflag > maxdist) maxdist = maxflag;
		}

		v.clear();
		cout << "#" << tc << " " << maxdist << "\n";
	}


	return 0;
}
