#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

int N, W, H;
int cnt;

vector<int> order;

int map[15][12];
int map_copy[15][12];
int used[15][12];

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

struct Node {
	int row, col;
};
queue <Node> q;
vector <Node> v;

void printMap() {
	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++) {
			cout << map[y][x];
		}
		cout << &apos; \n& apos;;
	}
	cout << &apos; \n& apos;;
}

// 중력에 의해 떨어지는 상황을 구현하는 함수
// 각 col마다 아래에서부터 map이 0이 아니면 Nidx[col]에 푸시
// 그 다음 0이면 0을 푸시
// 순서 맞췄으니까 map변경
int gravity() {
	int num = 0;
	for (int j = 0; j < W; j++) {
		vector<int> Nidx;
		for (int i = H - 1; i >= 0; i--) {
			if (map[i][j]) {
				Nidx.push_back(map[i][j]);
				map[i][j] = 0;
				num++;
			}
		}

		int idx = H - 1;
		for (int i = 0; i < Nidx.size(); i++) {
			map[idx][j] = Nidx[i];
			idx--;
		}
	}
	return num;
}

// 제일 위의 벽돌에 구슬을 맞추는 상황을 구현
// 들어오는 상수 == 몇번째 구슬인지
void punch(int glass) {

	memset(used, 0, sizeof(used));

	// 각 구슬이 처음으로 떨어질 열을 결정
	// 해당 열에서 구슬을 첫번째로 맞는 블럭의 좌표를 popGlass함수에 전달
	int row = 0;
	int col = glass;
	for (int i = 0; i < H; i++) {
		if (map[i][col]) {
			row = i;
			break;
		}
	}

	// 터질 애들을 다 벡터에 집어넣자
	// 큐에는 블럭에 적힌 숫자가 2이상이라 주변을 또 터뜨릴 애들을 푸시
	v.clear();
	q.push({ row, col });
	used[row][col] = 1;
	v.push_back({ row,col });

	if (map[row][col] > 1) {
		while (!q.empty()) {
			Node now = q.front();
			q.pop();
			int dis = map[now.row][now.col] - 1;

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

// 벽돌을 떨어트릴 순서를 정하는 함수 구현
void orderMaker(int a) {

	if (a == N) {
		//map init
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				map[y][x] = map_copy[y][x];
			}
		}

		int blockNow = 0;
		for (int b = 0; b < N; b++) {
			punch(order[b]);
			blockNow = gravity();
			int de = 1;
		}
		if (blockNow < cnt) {
			cnt = blockNow;
		}
		return;
	}

	for (int i = 0; i < W; i++) {
		order.push_back(i);
		orderMaker(a + 1);
		order.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		cnt = 200;
		cin >> N >> W >> H;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
				map_copy[i][j] = map[i][j];
			}
		}

		orderMaker(0);
		cout << &quot; # & quot; << tc << &quot; &quot; << cnt << &quot; \n & quot;;
	}

	return 0;
}
