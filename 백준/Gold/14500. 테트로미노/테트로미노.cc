#include <iostream>
using namespace std;

int N, M;
struct Node {
    int row, col;
};
Node tt[19][3] = {
    {{0,1},{0,2},{0,3}},
    {{1,0},{2,0},{3,0}},
    {{0,1},{1,0},{1,1}},
    {{0,1},{0,2},{1,0}},
    {{0,1},{0,2},{-1,2}},
    {{0,1},{0,2},{-1,1}},
    {{0,1},{-1,1},{-1,2}},
    {{0,1},{1,1},{0,2}},
    {{1,0},{2,0},{2,1}},
    {{0,1},{1,1},{2,1}},
    {{1,0},{1,1},{2,1}},
    {{1,0},{1,-1},{2,0}},
    {{1,0},{1,1},{2,0}},
    {{1,0},{2,0},{2,-1}},
    {{1,0},{2,0},{0,1}},
    {{1,0},{1,-1},{2,-1}},
    {{0,-1},{0,-2},{1,0}},
    {{-1,0},{0,1},{0,2}},
    {{0,1},{1,1},{1,2}},
};

int map[501][501] = { 0, };

void init() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }
}

int solve(int row, int col) {
     
    int maxcnt = 0;

    for (int i = 0; i < 19; i++) {
        int cnt = 0;
        int flag = 0;

        for (int j = 0; j < 3; j++) {
            int nr = row + tt[i][j].row;
            int nc = col + tt[i][j].col;
            if (nr < 1 || nc <1 || nr>N || nc>M) {
                flag = 1;
                break;
            }
            cnt += map[nr][nc];
        }
        if (flag == 1) continue;
        else {
            if (cnt > maxcnt) maxcnt = cnt;
        }
    }
    if (maxcnt == 0) return -1;
    else return maxcnt + map[row][col];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int cnt = solve(i, j);
            if (cnt > ans) ans = cnt;
        }
    }
    
    cout << ans;

    return 0;


}