#include <iostream>
#include <queue>
using namespace std;

int map[100][100] = { 0, };
int used[100][100] = { 0, };


struct Node {
	int row;
	int col;
};

queue<Node> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int H, W;
	cin >> H >> W;

	int R, C;
	cin >> R >> C;

	int Y, X;
	cin >> Y >> X;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int y;
		int x;
		cin >> y >> x;
		map[y][x] = -1;
		used[y][x] = 1;
	}

	int de = -1;

	q.push({ R,C });
	used[R][C] = 1;
	

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		int pr = now.row;
		int pc = now.col;


		int dr[8] = { 3,2,-2,-3,-3,-2,2,3 };
		int dc[8] = { 2,3,3,2,-2,-3,-3,-2 };

		for (int i = 0; i < 8; i++) {
			int nr = pr + dr[i];
			int nc = pc + dc[i];

			if (nr<0 || nc<0 || nr>H || nc>W) continue;
			if (used[nr][nc]) continue;

			used[nr][nc] = used[pr][pc] + 1;
			q.push({ nr,nc });
		}

	}

	if (used[Y][X] == 0) cout << "-1";
	else cout << used[Y][X]-1;

	return 0;
}




//6 5
//0 0
//5 3
//5
//0 1
//1 0
//2 2
//2 3
//3 0