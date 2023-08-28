#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, Q, N = 1;
int allice, allcnt;

int map[65][65] = { 0, };
int nowmap[65][65] = { 0, };
int nextmap[65][65] = { 0, };
int visited[65][65] = { 0, };


int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };

struct Node {
    int row, col;
};

void tornado(int L) {   // L * L 정사각형씩 90도 회전

    for (int i = 1; i < N; i += L) {
        for (int j = 1; j < N; j += L) {

            memset(nowmap, 0, sizeof(nowmap));
            memset(nextmap, 0, sizeof(nextmap));

            for (int r = i; r < i + L; r++) {
                for (int c = j; c < j + L; c++) {
                    nowmap[r - i + 1][c - j + 1] = map[r][c];
                }
            }

            for (int r = 1; r <= L; r++) {
                for (int c = 1; c <= L; c++) {
                    nextmap[c][L - r + 1] = nowmap[r][c];
                }
            }

            for (int r = i; r < i + L; r++) {
                for (int c = j; c < j + L; c++) {
                    map[r][c] = nextmap[r - i +1][c - j + 1];
                }
            }
        }
    }
}

void fireball() {   // 얼음이 3개이상 인접해있지 않으면 얼음양--

    vector<Node>v;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == 0) continue;

            int flag = 4;
            for (int d = 0; d < 4; d++) {
                int nr = i + dr[d];
                int nc = j + dc[d];

                if (nr <1 || nc <1 || nr >N || nc > N) {
                    flag--;
                    continue;
                }
                if (map[nr][nc] == 0) flag--;
            }
            if (flag < 3) v.push_back({ i, j });
        }
    }
    for (int k = 0; k < v.size(); k++) {
        map[v[k].row][v[k].col]--;
    }
    allice -= v.size();
}

int findmass() {

    int maxcnt = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == 0) continue;
            if (visited[i][j]) continue;

            queue<Node>q;
            q.push({ i,j });
            visited[i][j] = 1;
            int cnt = 1;

            while (!q.empty()) {
                Node now = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nr = now.row + dr[d];
                    int nc = now.col + dc[d];
                    if (nr <1 || nc <1 || nr >N || nc >N) continue;
                    if (map[nr][nc] == 0) continue;
                    if (visited[nr][nc]) continue;

                    visited[nr][nc] = 1;
                    cnt++;
                    q.push({ nr,nc });
                }
            }
            if (cnt > maxcnt) maxcnt = cnt;
        }
    }
    return maxcnt;
}

void init() {
    cin >> n >> Q;
    for (int i = 0; i < n; i++) N *= 2;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            allice += map[i][j];
            allcnt++;
        }
    }
    for (int i = 0; i < Q; i++) {
        int l, L = 1;
        cin >> l;
        for (int j = 0; j < l; j++) L *= 2;
        tornado(L);
        fireball();
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int ans = findmass();
    cout << allice << '\n' << ans;

    return 0;
}
