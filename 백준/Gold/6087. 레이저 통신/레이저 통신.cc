#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R, C;
char map[101][101] = { 0, };
int visited[101][101][2] = {0,};     // 거울 개수 기록, 0 상하 1 좌우
int dr[4] = { -1,1, 0, 0 };       // 0,1 : 상하  2,3 : 좌우
int dc[4] = { 0,0,1,-1 };
struct Node {
    int row, col, mirror, de;
};
bool operator<(Node A, Node B) {
    if (A.mirror > B.mirror) return true;
    else return false;
}
priority_queue<Node>pq;
int endrow, endcol;

void init() {
    cin >> C >> R;
    int flag = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> map[i][j];
            visited[i][j][0] = -1;
            visited[i][j][1] = -1;
            if (map[i][j] == 'C' && flag == 0) {
                pq.push({ i,j,0,-1 });
                visited[i][j][0] = 0;
                visited[i][j][1] = 0;
                flag = 1;
            }
            if (map[i][j] == 'C' && flag == 1) endrow = i, endcol = j;
        }
    }
}

int bfs() {

    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        if (now.row == endrow && now.col == endcol) {
            return now.mirror;
        }

        if (now.row == 9 && now.col == 6) {
            int dfff = -5;
        }

        for (int i = 0; i < 4; i++) {
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];
            if (nr < 1 || nc<1 || nr>R || nc>C) continue;
            if (map[nr][nc] == '*') continue;

            int nowde = now.de;     // 현재 방향


            // next 
            int mirror = now.mirror;
            if (((i == 0 || i == 1) && nowde == 1) || ((i == 2 || i == 3) && nowde == 0)) {
                mirror++;
            }

            if (i == 0 || i == 1) nowde = 0;
            else nowde = 1;
            
            // 더 적은 거울로 지나갈 수 있다.
            if (visited[nr][nc][0] < mirror && visited[nr][nc][0] != -1) continue;
            if (visited[nr][nc][1] < mirror && visited[nr][nc][1] != -1) continue;
            if (visited[nr][nc][nowde] == mirror) continue;
            visited[nr][nc][nowde] = mirror;

            pq.push({ nr, nc, mirror, nowde });
        }   
    }
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