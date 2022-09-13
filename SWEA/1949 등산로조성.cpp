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

	// �����¿� ��  �� �ִ� ��� Ȯ��
	// ������ġ���� ������ �� �� �ִ�.
	// ���� Ƚ���� ǥ���ص״ٰ� �� ���� �ȱ������ �� �� ���� �� ����
	// ��, K��ŭ�� ���� �� ����
	// �� �� ������ �ǵ��� �����ԵǸ� ���� ���󺹱�
	// ��°� ������ �ϳ� �۰Ը� ����ָ� �ȴ�

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
	// ������ �׳� ����ߴ� == �����¿� ���ε� ���� ���ߴ�
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

		// 1. �Է�
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] > maxheight) maxheight = map[i][j];
			}
		}

		// 2. ��� ���� ����(�ִ� ����) ���
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == maxheight) v.push_back({ i,j });
			}
		}

		// 3. ��ϵ� �ִ� ���� ������ �ִ� ���� ���� ���
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
