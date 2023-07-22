#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans;
int D, W, K;
int map[13][20];
int copy_map[13][20];
int used[13];
int changeUsed[13];
vector <int> order;



// 합격기준을 통과하는지 검사
bool check() {
	int mincol = 15;
	for (int col = 0; col < W; col++) {
		int maxcell = 0;
		int cnt = 1;
		for (int row = 0; row < D - 1; row++) {
			if (map[row][col] == map[row + 1][col]) cnt++;
			else {
				if (cnt > maxcell) maxcell = cnt;
				cnt = 1;
			}
		}
		if (maxcell < mincol) mincol = maxcell;
	}
	if (mincol >= K) return true;
	else return false;
}

// 바꿀 애들을 다 바꿔주는 함수
void changeRow() {

	for (int a = 0; a < order.size(); a++) {
		int row = order[a];
		for (int i = 0; i <= 1; i++) {
			for (int col = 0; col < W; col++) {
				map[row][col] = i;
			}
		}
	}

}

// 넣을 곳을 정하는 함수
void BFS(int a) {

	if (a == 0) {
		changeRow();
		return;
	}

	for (int row = 0; row < D; row++) {
		if (used[row]) continue;
		order.push_back(row);
		used[row] = 1;
		a--;
		BFS(a);
	}

}

// 최소 투약 횟수를 정하는 함수
int changeCnt() {
	int left = 1;
	int right = D;
	int mid = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		BFS(mid);
		if (check()) right = mid - 1;
		else left = mid + 1;
	}
	return mid;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}


		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}