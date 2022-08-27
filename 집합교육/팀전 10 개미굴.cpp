#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int N, M;
int map[1001][1001] = { 0, };
int used[1001][1001] = { 0, };

struct Node {
    int row, col;
};
queue <Node> q;

int bfs(int row, int col) {

    int cnt = 1;
    int dr[4] = { -1,1,0,0 };
    int dc[4] = { 0,0,-1,1 };
    vector <Node> a;

    q.push({ row,col });
    a.push_back({ row,col });
    used[row][col] = 1;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];

            if (nr < 1 || nc < 1 || nr > N || nc > M) continue;
            if (used[nr][nc]) continue;
            if (map[nr][nc] == 0) continue;

            used[nr][nc] = 1;
            q.push({ nr,nc });
            a.push_back({ nr,nc });
            cnt++;
        }
    }

    for (int i = 0; i < a.size(); i++) {
        used[a[i].row][a[i].col] = 0;
    }

    return cnt;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    cin >> N >> M;
    int maxsize = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }

    int de = -1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (map[i][j] == 0)
            {
                map[i][j] = 1;
                int a = bfs(i, j);
                if (a > maxsize) maxsize = a;
                map[i][j] = 0;
            }
        }
    }


    cout << maxsize;

    return 0;
}