#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int map[15][15] = { 0, };
struct Node {
	int row, col;
};
vector<Node>v;
int lineCnt, coreCnt, N;
int minLines = 5000;
int maxCores = -1;

void DFS(int a) {

	if (a == v.size()) {
		if (coreCnt > maxCores) {
			maxCores = coreCnt;
			minLines = lineCnt;
		}
		else if (coreCnt == maxCores) {
			if (lineCnt < minLines) minLines = lineCnt;
		}
		return;
	}

	Node now = v[a];
	int pr = now.row;
	int pc = now.col;
	bool abc = true;

	// 1. 위로 탐색 -> 가능하면 전선 입력
	for (int i = 0; i < pr; i++) {
		if (map[i][pc]) {
			abc = false;
			break;
		}
	}
	if (abc) {
		for (int i = 0; i < pr; i++) {
			map[i][pc] = 2;
			lineCnt++;
		}
		coreCnt++;
		DFS(a+1);
		coreCnt--;
		for (int i = 0; i < pr; i++) {
			map[i][pc] = 0;
			lineCnt--;
		}
	}

	// 2. 아래로 탐색
	for (int i = pr+1; i < N; i++) {
		if (map[i][pc]) {
			abc = false;
			break;
		}
	}
	if (abc) {
		for (int i = pr+1; i < N; i++) {
			map[i][pc] = 2;
			lineCnt++;
		}
		coreCnt++;
		DFS(a + 1);
		coreCnt--;
		for (int i = pr+1; i < N; i++) {
			map[i][pc] = 0;
			lineCnt--;
		}
	}

	// 3. 좌로 탐색
	for (int i = 0; i < pc; i++) {
		if (map[pr][i]) {
			abc = false;
			break;
		}
	}
	if (abc) {
		for (int i = 0; i < pc; i++) {
			map[pr][i] = 2;
			lineCnt++;
		}
		coreCnt++;
		DFS(a + 1);
		coreCnt--;
		for (int i = 0; i < pc; i++) {
			map[pr][i] = 0;
			lineCnt--;
		}
	}

	// 4. 우로 탐색
	for (int i = pc + 1; i < N; i++) {
		if (map[pr][i]) {
			abc = false;
			break;
		}
	}
	if (abc) {
		for (int i = pc + 1; i < N; i++) {
			map[pr][i] = 2;
			lineCnt++;
		}
		coreCnt++;
		DFS(a + 1);
		coreCnt--;
		for (int i = pc + 1; i < N; i++) {
			map[pr][i] = 0;
			lineCnt--;
		}
	}

	// 5. 탐색을 안하고 지나가는 경우
	DFS(a + 1);

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int T;
	cin >> T;
	for(int tc = 1; tc <= T; tc++) {
		cin >> N;
		coreCnt = 0;
		lineCnt = 0;
		v.clear();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j])
				{
					// 가장자리에 있어서 이미 연결된 애들 제외하고 벡터에 푸시
					if (i == 0 || j == 0 || i == N - 1 || j == N - 1) coreCnt++;
					else v.push_back({ i,j });
				}
			}
		}

		// 벡터에 들어간 코어에 대해서 상하좌우 연결 확인
		DFS(0);

		cout << "#" << tc << " ";
		cout << minLines << "\n";
	}

	return 0;
}
