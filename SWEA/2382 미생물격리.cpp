#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

struct Node {
	int cnt, d;
};

int N, M, K;
int ans;
int map[100][100];
Node used[100][100];
// 미생물의 개수가 큰 순서대로 정렬
struct slime {
	int row, col, cnt, d;
};
struct cmp {
	bool operator()(slime a, slime b) {
		if (a.cnt < b.cnt) return true;
		return false;
	}
};

vector<slime>v;
queue<slime>pq;
priority_queue<slime, vector<slime>, cmp>q;
// 인덱스로 이동방향을 설정 : - 상 하 좌 우
int dr[5] = { 0,-1,1,0,0 };
int dc[5] = { 0,0,0,-1,1 };

int BFS(int M) {

	while (M > 0) {

		while (!pq.empty()) {
			slime Now = pq.front();
			pq.pop();
			int pr = Now.row;
			int pc = Now.col;
			int cntNow = Now.cnt;
			int dNow = Now.d;

			int nr = Now.row + dr[Now.d];
			int nc = Now.col + dc[Now.d];
			if (nr == 0 || nr == N - 1 || nc == 0 || nc == N - 1) {
				if (dNow == 1 || dNow == 3) dNow++;
				else dNow--;
				cntNow = cntNow / 2;
			}
			q.push({ nr,nc,cntNow,dNow });
		}

		// 전부 큐에 담아
		// 큐는 우선순위로 변경해주자
		// 큰 게 먼저 나오게
		// 다시 pq로 옮겨닮는 과정에서 used가 있으면 더해주자
		// 두 군집이 같은 곳에서 만난 경우,
		// cnt는 합쳐지고 d는 cnt가 더 큰 곳의 것을 따르게 되어야함
		// used에 q에 있는 것을 전부 옮겼음.
		memset(used, 0, sizeof(used));
		while (!q.empty()) {
			slime Now = q.top();
			q.pop();
			if (used[Now.row][Now.col].d) {
				used[Now.row][Now.col].cnt += Now.cnt;
			}
			else used[Now.row][Now.col] = { Now.cnt, Now.d };
		}

		ans = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (used[i][j].d) {
					pq.push({ i,j,used[i][j].cnt,used[i][j].d });
					ans += used[i][j].cnt;
				}
			}
		}
		M--;
	}

	while (!pq.empty()) {
		pq.pop();
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++) {
			int row, col, cnt, d;
			cin >> row >> col >> cnt >> d;
			pq.push({ row,col,cnt,d });
			map[row][col] = cnt;
		}

		ans = BFS(M);
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}
