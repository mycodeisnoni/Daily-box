#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

int N, W, H;
int cnt;

int order[4] = { 0, };

int map[15][12] = { 0, };
int used[15][12] = { 0, };

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

struct Node {
	int row, col;
};
queue <Node> q;
vector <Node> v;
vector<int>Nidx[12];

// �߷¿� ���� �������� ��Ȳ�� �����ϴ� �Լ�
// �� col���� �Ʒ��������� map�� 0�� �ƴϸ� Nidx[col]�� Ǫ��
// �� ���� 0�̸� 0�� Ǫ��
// ���� �������ϱ� map����
int gravity() {
	int num = 0;
	Nidx->clear();
	for (int j = 0; j < W; j++) {
		for (int i = H - 1; i >= 0; i--) {
			if (map[i][j]) {
				Nidx[j].push_back(map[i][j]);
				num++;
			}
		}
	}
	for (int j = 0; j < W; j++) {
		for (int i = H - 1; i >= 0; i--) {
			if (!map[i][j]) Nidx[j].push_back(0);
		}
	}
	for (int j = 0; j < W; j++) {
		for (int i = H - 1; i >= 0; i--) {
			map[i][j] = Nidx[j][H - 1 - i];
		}
	}
	return num;
}

// ���� ���� ������ ������ ���ߴ� ��Ȳ�� ����
// ������ ��� == ���° ��������
void punch(int glass) {

	memset(used, 0, sizeof(used));

	// �� ������ ó������ ������ ���� ����
	// �ش� ������ ������ ù��°�� �´� ���� ��ǥ�� popGlass�Լ��� ����
	int row = 0;
	int col = glass;
	for (int i = 0; i < H; i++) {
		if (map[i][col]) row = i;
		break;
	}

	// ���� �ֵ��� �� ���Ϳ� �������
	// ť���� ���� ���� ���ڰ� 2�̻��̶� �ֺ��� �� �Ͷ߸� �ֵ��� Ǫ��
	v.clear();
	int dis = map[row][col] - 1;
	q.push({ row, col });
	used[row][col] = 1;
	v.push_back({ row,col });

	if (map[row][col] > 1) {
		while (!q.empty()) {
			Node now = q.front();
			q.pop();
			for (int d = 1; d <= dis; d++) {
				for (int i = 0; i < 4; i++) {
					int nr = now.row + dr[i] * d;
					int nc = now.col + dc[i] * d;

					if (nr < 0 || nc < 0 || nr >= H || nc >= W) continue;
					if (!map[nr][nc]) continue;
					if (used[nr][nc]) continue;

					used[nr][nc] = 1;
					v.push_back({ nr,nc });
					if (map[nr][nc] > 1) q.push({ nr,nc });
				}
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		map[v[i].row][v[i].col] = 0;
	}
	return;
}

// ������ ����Ʈ�� ������ ���ϴ� �Լ� ����
void orderMaker(int a) {

	if (a == N) {
		int blockNow = 0;
		for (int b = 0; b < N; b++) {
			punch(order[b]);
			blockNow = gravity();
		}
		if (blockNow < cnt) cnt = blockNow;
		return;
	}

	for (int i = 0; i < W; i++) {
		order[a] = i;
		orderMaker(a++);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		cnt = 0;
		cin >> N >> W >> H;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}

		orderMaker(0);
		cout << "#" << tc << " " << cnt << "\n";
	}

	return 0;
}