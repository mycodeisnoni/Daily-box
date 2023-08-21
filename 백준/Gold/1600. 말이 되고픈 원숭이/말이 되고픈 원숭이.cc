#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int K;
int R, C;
int map[201][201] = { 0, };
int visited[201][201] = {0,};       

int dr[12] = { 0,0,-1,1,1,2,2,1,-1,-2,-2,-1, };      // 4~11 : 말,  0~3 : 원숭이
int dc[12] = { -1,1,0,0,-2,-1,1,2,2,1,-1,-2  };

struct Node {
    int row, col, horse;
};
queue<Node>qnow1;
queue<Node>qnow2;
queue<Node>qnext;

void init() {
    cin >> K;
    cin >> C >> R;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            visited[i][j] = -1;
        }
    }
}

int bfs() {

    qnow1.push({ 1,1,0 });
    qnow2.push({ 1,1,0 });
    visited[1][1] = 0;
    int cnt = 0;

    while (!qnow1.empty() && !qnow2.empty()) {

        if (visited[R][C] != -1) return cnt;

        while (!qnow1.empty()) {

            Node now = qnow1.front();
            qnow1.pop();

            for (int i = 0; i < 4; i++) {
                int nr = now.row + dr[i];
                int nc = now.col + dc[i];
                int nh = now.horse;

                if (nr <1 || nc <1 || nr > R || nc > C) continue;
                if (map[nr][nc]) continue;
                if (nh >= visited[nr][nc] && visited[nr][nc] != -1) continue;

                visited[nr][nc] = nh;
                qnext.push({ nr, nc, nh });
            }
        }

        while (!qnow2.empty()) {
            Node now = qnow2.front();
            qnow2.pop();

            for (int i = 4; i < 12; i++) {

                int nr = now.row + dr[i];
                int nc = now.col + dc[i];
                int nh = now.horse;

                if (now.horse < K) nh++;
                else continue;
                
                if (nr <1 || nc <1 || nr > R || nc > C) continue;
                if (map[nr][nc]) continue;
                if (nh >= visited[nr][nc] && visited[nr][nc] != -1) continue;

                visited[nr][nc] = nh;
                qnext.push({ nr, nc, nh });
            }
        }

        cnt++;

        while (!qnext.empty()) {
            qnow1.push(qnext.front());
            qnow2.push(qnext.front());
            qnext.pop();
        }
    }
    return -1;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int ans = bfs();
    cout << ans;

    return 0;
}
