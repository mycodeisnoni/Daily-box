#include <iostream>
#include <queue>
using namespace std;

int N;
int map[501][501] = { 0, };
int dp[501][501] = { 0, };

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,-1,1 };
int maxi = 0;


void init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }
}

int DP(int row, int col) {

    if (dp[row][col] > 0) return dp[row][col];
    int flag = 0;

    for (int d = 0; d < 4; d++) {
        int nr = row + dr[d];
        int nc = col + dc[d];
        if (nr < 1 || nr > N || nc < 1 || nc > N) {
            flag++;
            continue;
        }
        if (map[nr][nc] <= map[row][col]) {
            flag++;
            continue;
        }

        int next = DP(nr, nc);
        if (next+1 > dp[row][col]) {
            dp[row][col] = next+1;
            if (dp[row][col] > maxi) maxi = dp[row][col];
        }
    }
    if (flag == 4) {
        dp[row][col] = 1;
        if (dp[row][col] > maxi) maxi = dp[row][col];
    }
    return dp[row][col];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    init();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j]= DP(i, j);
        }
    }
    cout << maxi;

    return 0;
}