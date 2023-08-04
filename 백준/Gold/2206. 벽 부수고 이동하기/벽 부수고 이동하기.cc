#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[1001][1001] = { 0, };
int visited[1001][1001] = { 0, };
struct Node {
    int row, col, dist, removed;
};
queue<Node>qNow;
queue<Node>qNext;

int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };

void init() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string x;
        cin >> x;

        for (int j = 1; j <= M; j++) {
            map[i][j] = x[j - 1] - '0';
        }
    }
}

int bfs() {

    while (!qNow.empty()) {

        while (!qNow.empty()) {
            Node now = qNow.front();
            qNow.pop();

            if (now.row == N && now.col == M) return now.dist;

            for (int d = 0; d < 4; d++) {
                int nr = now.row + dr[d];
                int nc = now.col + dc[d];

                if (nr<1 || nc<1 || nr>N || nc>M) continue;
                if (visited[nr][nc] > 0) continue;     // 벽을 뚫지 않고 지나간적 있으면 짤

                if (visited[nr][nc] < 0) {     // 벽을 뚫고 지나간적 있으면?
                    if (now.removed == 1) continue;     // 나도 벽 뚫었으면 짤
                }

                if (map[nr][nc] == 1) { // 벽이 있으면
                    if (now.removed == 1) continue;  // 이미 부신적이 있으면 짤
                    else {
                        qNext.push({ nr,nc,now.dist + 1,1 });
                        visited[nr][nc] = (-1) * (now.dist + 1);
                    }
                }
                else {
                    qNext.push({ nr,nc,now.dist + 1,now.removed });
                    if (now.removed == 1) visited[nr][nc] = (now.dist + 1) * (-1);       // 벽을 뚫고 온 경로일 경우
                    else visited[nr][nc] = now.dist + 1;                       // 벽을 뚫지 않고 온 경로일 경우
                }
             }
        }

        while (!qNext.empty()) {
            qNow.push(qNext.front());
            qNext.pop();
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    qNow.push({ 1,1,1,0 });
    visited[1][1] = 1;
    int ans = bfs();

    cout << ans;

    return 0;
}