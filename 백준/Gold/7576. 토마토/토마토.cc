#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct tomato {
    int y, x;
};
queue<tomato> q;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 , -1 };
int n, m, result = 0;
int map[1001][1001];

bool IsInside(int ny, int nx) {
    return (0 <= nx && 0 <= ny && nx < m&& ny < n);
}

void bfs(void) {
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (IsInside(ny, nx) == 1 && map[ny][nx] == 0) {
                map[ny][nx] = map[y][x] + 1;
                q.push({ ny, nx });
            }
        }
    }
}

void init() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                q.push({ i, j });
            }
        }
    }
}

void printing() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                cout << -1 << '\n';
                return;
            }
            if (result < map[i][j]) result = map[i][j];
        }
    }
    cout << result - 1;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    bfs();
    printing();
    return 0;
}