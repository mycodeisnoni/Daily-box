#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R, C;
int cnt = 0;
int timecnt = 0;
int map[101][101] = { 0, };
int visited[101][101] = { 0, };
int copymap[101][101] = { 0, };
int dr[4] = { 0,0,-1,1 };
int dc[4] = { 1,-1,0,0 };
struct Node {
    int row, col;
};
queue<Node>qnow;
queue<Node>qnext;

void init() {
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> map[i][j];
            copymap[i][j] = map[i][j];
            if (map[i][j] != 0) cnt++;
        }
    }
}

int bfs() {

    int nowremove = 0;

    while (!qnow.empty()) {
        Node now = qnow.front();
        qnow.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];

            if (nr <1 || nc<1 || nr>R || nc>C) continue;
            if (map[nr][nc] == 0) continue;

            map[nr][nc] = 0;
            nowremove++;
        }
    }
    return nowremove;
}

int counting() {
    int sr = 0, sc = 0;
    int flag = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (map[i][j] == 0) {
                sr = i;
                sc = j;
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
    }
    qnow.push({ sr, sc });

    while (!qnow.empty()) {
        Node now = qnow.front();
        qnow.pop();
        for (int d = 0; d < 4; d++) {
            int nr = now.row + dr[d];
            int nc = now.col + dc[d];
            if (nr <1 || nc<1 || nr>R || nc>C) continue;
            if (map[nr][nc] != 0) continue;
            if (copymap[nr][nc]) continue;
            copymap[nr][nc] = -1;
            qnow.push({ nr,nc });
        }
    }
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (copymap[i][j] == -1) qnow.push({i,j});
        }
    }
    int removed = bfs();
    return removed;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int ans2 = 0;

    while (cnt > 0) {
        timecnt++;
        memset(copymap, 0, sizeof(copymap));
        int nowremoved = counting();
        ans2 = nowremoved;
        cnt -= nowremoved;
    }
    cout << timecnt << '\n' << ans2;
    
    return 0;
}
