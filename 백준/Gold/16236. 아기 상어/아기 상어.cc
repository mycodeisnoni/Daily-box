#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N;
int map[21][21] = { 0, };
int visited[21][21] = { 0, };
struct Node {
    int row, col;
};
vector<Node>fish[7];

int dr[4] = { -1,0,0,1 };
int dc[4] = { 0,-1,1,0 };

struct shark {
    int row, col;
};
queue<shark>qNow;
queue<shark>qNext;

int realtime = 0;
int ate = 0;
int weight = 2;

int nowrow, nowcol;

void init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            if (map[i][j] >= 1 && map[i][j] <= 6) fish[map[i][j]].push_back({ i,j });
            if (map[i][j] == 9) {
                qNow.push({ i,j});
                visited[i][j] = 1;
                map[i][j] = 0;
            }
        }
    }
}

int bfs() {

    int nowtime = 0;
    int rowRe = 22;
    int colRe = 22;
    
    while (!qNow.empty()) {
        nowtime++;
        while (!qNow.empty()) {
            shark now = qNow.front();
            qNow.pop();

            for (int i = 0; i < 4; i++) {
                int nr = now.row + dr[i];
                int nc = now.col + dc[i];

                if (nr <1 || nc <1 || nr > N || nc >N) continue;
                if (map[nr][nc] > weight) continue;
                if (visited[nr][nc]) continue;

                visited[nr][nc] = 1;
                if (map[nr][nc] < weight && map[nr][nc] != 0) {
                    if (nr < rowRe) {
                        rowRe = nr;
                        colRe = nc;
                    }
                    else if (nr == rowRe && nc < colRe) {
                        colRe = nc;
                    }
                }
                else if (map[nr][nc] == weight || map[nr][nc] == 0) qNext.push({ nr,nc });
            }
        }
            if (rowRe != 22 && colRe != 22) {
                map[rowRe][colRe] = 0;
                ate++;
                if (ate == weight) {
                    weight++;
                    ate = 0;
                }
                nowrow = rowRe;
                nowcol = colRe;

                return nowtime;     // 물고기 먹었으면 bfs 종료, 먹은 시간 리턴
            }

        while (!qNext.empty()) {
            qNow.push(qNext.front());
            qNext.pop();
        }
    }
    return 0;      // 더이상 먹을 수 있는 물고기 없음 : 0 리턴
}

int solve() {

    int addtime = bfs();
    realtime += addtime;

    while (addtime > 0) {

        while (!qNow.empty()) qNow.pop();
        while (!qNext.empty()) qNext.pop();
        qNow.push({nowrow, nowcol});
        memset(visited, 0, sizeof(visited));
        visited[nowrow][nowcol] = 1;
        addtime = bfs();
        realtime += addtime;
    }
    return realtime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int ans = solve();
    cout << ans;

    return 0;
}
