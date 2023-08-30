#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
struct Node {
    int row, col;
};
queue<Node>q;
vector<Node>v;
int map[101][101] = { 0, };
int visited[101][101] = { 0, };
int checkmap[101][101] = { 0, };
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };
queue<Node>sg;
queue<Node>sgnext;

void init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            if(map[i][j]) v.push_back({ i,j });
        }
    }
}

int setting() {
    int cnt = 1;
    for (int i = 0; i < v.size(); i++) {
        if (visited[v[i].row][v[i].col]) continue;
        q.push({ v[i].row, v[i].col });
        visited[v[i].row][v[i].col] = cnt;
        while (!q.empty()) {
            Node now = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = now.row + dr[d];
                int nc = now.col + dc[d];
                if (nr < 1 || nc < 1 || nr > N || nc >N) continue;
                if (map[nr][nc] == 0) continue;
                if (visited[nr][nc]) continue;
                visited[nr][nc] = cnt;
                q.push({ nr,nc });
            }
        }
        cnt++;
    }
    return cnt - 1;
}

int checking(int start) {

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            checkmap[i][j] = visited[i][j];
            if (visited[i][j] == start) {
                int flag = 0;
                for (int d = 0; d < 4; d++) {
                    int nr = i + dr[d];
                    int nc = j + dc[d];
                    if (nr <1 || nc <1 || nr >N || nc >N) continue;
                    if (visited[nr][nc] == 0) flag = 1;
                }
                if(flag == 1) sg.push({ i,j });
            }
        }
    }

    int cnt = 1;
    while (!sg.empty()) {
        while (!sg.empty()) {
            Node now = sg.front();
            sg.pop();

            for (int d = 0; d < 4; d++) {
                int nr = now.row + dr[d];
                int nc = now.col + dc[d];
                if (nr <1 || nc <1 || nr >N || nc >N) continue;
                if (checkmap[nr][nc] < 0) continue;
                if (checkmap[nr][nc] > 0 && checkmap[nr][nc] != start) return cnt - 1;
                checkmap[nr][nc] = (-1) * cnt;
                sgnext.push({ nr,nc });
            }
        }
        while (!sgnext.empty()) {
            sg.push({ sgnext.front() });
            sgnext.pop();
        }
        cnt++;
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int groupcnt = setting();
    int ans = 2e9;
    for (int i = 1; i < groupcnt; i++) {
        int nowdist = checking(i);
        if (nowdist < ans && nowdist > 0) ans = nowdist;
        while (!sg.empty())sg.pop();
        while (!sgnext.empty())sgnext.pop();

    }
    cout << ans;

    return 0;
}