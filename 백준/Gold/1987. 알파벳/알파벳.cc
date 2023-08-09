#include <iostream>
using namespace std;

int R, C;
int map[21][21] = { 0, };
int used[27] = { 0, };
int visited[21][21] = { 0, };

int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };

int cnt = 1;
int maxcnt = 1;

void init() {
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        string x;
        cin >> x;
        for (int j = 0; j < C; j++) {
            map[i][j + 1] = x[j] - 'A';
        }
    }
}

void dfs(int row, int col) {

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr <1 || nc< 1 || nr > R || nc > C) continue;
        if (used[map[nr][nc]]) continue;
        if (visited[nr][nc]) continue;

        used[map[nr][nc]]++;
        visited[nr][nc] = 1;
        cnt++;

        dfs(nr, nc);

        used[map[nr][nc]]--;
        visited[nr][nc] = 0;
        if (cnt > maxcnt) maxcnt = cnt;
        cnt--;
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    used[map[1][1]] = 1;
    visited[1][1] = 1;
    dfs(1, 1);
    
    cout << maxcnt;

    return 0;
}