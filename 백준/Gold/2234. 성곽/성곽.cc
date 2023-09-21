#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int map[51][51] = {0,};
int group[51][51] = { 0, };
int dr[4] = { 0,-1,0,1 };
int dc[4] = { -1,0,1,0 };
vector<int>groupsize;
struct Node {
    int row, col;
};
int maxi = 0;


void init() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }
}

int grouping() {
    int cnt = 0;
    groupsize.push_back(0);
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (group[i][j]) continue;

            queue<Node>q;
            q.push({ i,j });
            int nowmax = 1;
            cnt++;
            group[i][j] = cnt;
            while (!q.empty()) {
                Node now = q.front();
                q.pop();
                int cango[4] = { 0, };
                if (map[now.row][now.col] & 8) cango[3] = 1;   // 남쪽 벽 : 3
                if (map[now.row][now.col] & 4) cango[2] = 1;   // 동쪽 벽 : 2
                if (map[now.row][now.col] & 2) cango[1] = 1;   // 북쪽 벽 : 1
                if (map[now.row][now.col] & 1) cango[0] = 1;   // 서쪽 벽 : 0             
                for (int d = 0; d < 4; d++) {
                    if (cango[d] == 1) continue;
                    int nr = now.row + dr[d];
                    int nc = now.col + dc[d];
                    if (nr < 1 || nc <1 || nr>M || nc>N) continue;
                    if (group[nr][nc]) continue;
                    q.push({ nr,nc });
                    group[nr][nc] = cnt;
                    nowmax++;
                }
            }
            if (nowmax > maxi) maxi = nowmax;
            groupsize.push_back(nowmax);
        }
    }
    return cnt;
}

int dest() {
    int mmaxi = -1;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            for (int d = 0; d < 4; d++) {
                int nr = i + dr[d];
                int nc = j + dc[d];
                if (nr < 1 || nc <1 || nr>M || nc>N) continue;
                if (group[i][j] == group[nr][nc]) continue;
                int nowmaxi = groupsize[group[i][j]] + groupsize[group[nr][nc]];
                if (nowmaxi > mmaxi) mmaxi = nowmaxi;
            }
        }
    }
    return mmaxi;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int cnt = grouping();
    int mmaxi = dest();
    cout << cnt << '\n' << maxi << '\n' << mmaxi;

    return 0;
}