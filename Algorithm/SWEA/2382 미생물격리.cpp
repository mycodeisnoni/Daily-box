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
// �̻����� ������ ū ������� ����
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
// �ε����� �̵������� ���� : - �� �� �� ��
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

		// ���� ť�� ���
		// ť�� �켱������ ����������
		// ū �� ���� ������
		// �ٽ� pq�� �Űܴ�� �������� used�� ������ ��������
		// �� ������ ���� ������ ���� ���,
		// cnt�� �������� d�� cnt�� �� ū ���� ���� ������ �Ǿ����
		// used�� q�� �ִ� ���� ���� �Ű���.
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
