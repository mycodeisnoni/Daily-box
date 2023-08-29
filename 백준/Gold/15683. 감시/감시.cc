#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[9][9] = { 0, };
int cansee[9][9] = { 0, };      // 무조건 볼 수 있는 곳
int visited[9][9] = { 0, };     // 케이스마다 체크
int mincnt = 100;
int dr[4] = { 1,0,-1,0 };       // 상 우 하 좌 : 위부터 시계방향
int dc[4] = { 0,1,0,-1 };

struct Edge {
    int first, second, third;
};

Edge arr[14] = {
    {0},{1},{2},{3},                        // 0 ~ 3 : 1번
    {0,2},{1,3},                            // 4 ~ 5 : 2번
    {0,1},{1,2},{2,3},{3,0},                // 6 ~ 9 : 3번
    {0,1,2},{1,2,3},{2,3,0},{0,1,3},        // 10 ~ 13 : 4번
};

struct Node {
    int row, col, kindof, de;
};
vector<Node>cctv;
vector<Node>cctv5;
vector<Node>checking;

void init() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 5) cctv5.push_back({ i,j, });
            else if (map[i][j] == 6) cansee[i][j] = -1;
            else if (map[i][j] != 0) cctv.push_back({ i,j,map[i][j] });
        }
    }
}

void setting() {
    for (int i = 0; i < cctv5.size(); i++) {
        int r = cctv5[i].row;
        int c = cctv5[i].col;
        cansee[r][c] = 1;
        
        for (int d = 0; d < 4; d++) {
            int row = r;
            int col = c;
            while (row > 0 && col > 0 && row <= N && col <= M) {
                row += dr[d];
                col += dc[d];
                if (cansee[row][col] == -1) break;
                cansee[row][col] = 1;
            }
        }
    }
    for (int i = 0; i < cctv.size(); i++) {
        cansee[cctv[i].row][cctv[i].col] = 1;
    }
}

int seeing() {

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            visited[i][j] = cansee[i][j];
        }
    }

    for (int i = 0; i < checking.size(); i++) {
        int r = checking[i].row;
        int c = checking[i].col;
        int d = checking[i].de;

        while (1) {
            r += dr[d];
            c += dc[d];
            if (r < 1 || c <1 || r >N || c >M) break;
            if (visited[r][c] == -1) break;
            visited[r][c] = 1;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (visited[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

void dfs(int S) {

    if (S == cctv.size()) {
        int nowsee = seeing();
        if (nowsee < mincnt) mincnt = nowsee;
        return;
    }

    int nowkind = cctv[S].kindof;

    if (nowkind == 1) {
        for (int j = 0; j < 4; j++) {
            checking.push_back({ cctv[S].row, cctv[S].col, 0, arr[j].first });
            dfs(S + 1);
            checking.pop_back();
        }
    }
    if (nowkind == 2) {
        for (int j = 4; j < 6; j++) {
            checking.push_back({ cctv[S].row, cctv[S].col, 0, arr[j].first });
            checking.push_back({ cctv[S].row, cctv[S].col, 0, arr[j].second });
            dfs(S + 1);
            checking.pop_back();
            checking.pop_back();
        }
    }
    if (nowkind == 3) {
        for (int j = 6; j < 10; j++) {
            checking.push_back({ cctv[S].row, cctv[S].col, 0, arr[j].first });
            checking.push_back({ cctv[S].row, cctv[S].col, 0, arr[j].second });
            dfs(S + 1);
            checking.pop_back();
            checking.pop_back();
        }
    }
    if (nowkind == 4) {
        for (int j = 10; j < 14; j++) {
            checking.push_back({ cctv[S].row, cctv[S].col, 0, arr[j].first });
            checking.push_back({ cctv[S].row, cctv[S].col, 0, arr[j].second });
            checking.push_back({ cctv[S].row, cctv[S].col, 0, arr[j].third });
            dfs(S + 1);
            checking.pop_back();
            checking.pop_back();
            checking.pop_back();
        }
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    setting();
    dfs(0);
    cout << mincnt;

    return 0;
}