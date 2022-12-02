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


// �ش� ���� �湮�� �� �ִ��� Ȯ�����ִ� �Լ�
bool CanVisit(int row, int col) {

	// �����ϰ��� �ϴ� ���� �����¿츦 Ȯ��
	// �� ���̶� ���� ���������鼭 �湮 �ߴ� ���̾�� �� ��θ� ����
	// �ش� ���� �湮 ������ ������ �Ǵ�
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

// �湮�� ���鿡 ���� �۾��� ���ִ� �Լ�
void search(int row, int col) {

	// 1. �湮�ߴٰ� ��� ���ֱ�
	visited[row][col] = 1;

	// 2. �湮�� ���� �ִ� ����ġ�� �����ֱ�
	for (int i = 0; i < v[row][col].size(); i++) {
		Node now = v[row][col][i];
		if (!map[now.row][now.col]) {
			map[now.row][now.col] = 1;
			cnt++;

			// ?
			// 3. ���� �� ���� �� �� �ִ� ������ Ȯ��
			// �� �� �ִ� ���̸� �湮!
			if (CanVisit(now.row, now.col)) {
				search(now.row, now.col);
			}
		}
	}

	// 4. ���� ��ġ���� �����¿�� �̵��� ������ ���� �ֳ� Ȯ��
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