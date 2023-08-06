#include <cstring>
#include <iostream>
using namespace std;

int row, col;
int map[501][501] = { 0, };
int dp[501][501] = { 0, };        // 해당 위치에서부터 올바른 길의 개수를 저장하는 배열

int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { -1, 1, 0, 0 };

void init() {
    cin >> row >> col;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
}

int dfs(int r, int c) {

    if (r == row && c == col) return 1;     // 목적지 도착 
    if (dp[r][c] != -1) return dp[r][c];    // 탐색했던 곳이면 경로 개수 리턴

    int now = map[r][c];

    dp[r][c] = 0;       // 방문 시, 0으로 초기화

    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (nr < 1 || nc < 1 || nr > row || nc > col) continue;
        if (now <= map[nr][nc]) continue;

        dp[r][c] = dp[r][c] + dfs(nr, nc);
    }
    return dp[r][c];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int ans = dfs(1, 1);

    cout << ans;

    return 0;
}