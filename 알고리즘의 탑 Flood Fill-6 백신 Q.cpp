#include <iostream>
#include <queue>
#include<cstring>
using namespace std;

struct Node {
    int row;
    int col;
};

int map[201][201] = { 0, };
int used[201][201] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int N, M;
    cin >> N >> M;
    string x[201];

    for (int i = 0, i < N; i++) {
        cin >> x[i];
        for (int j = 0; j < M; j++) {
            if (x[i][j] == 'A') map[i][j] = 1;
            else if (x[i][j] == 'B') map[i][j] = 2;
        }
    }

    queue<Node>q;

    //A : map값이 1인 것
    int cntA = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1 && used[i][j] == 0) {
                q.push(i, j);
                used[i, j] = 1;

                while (!q.empty()) {
                    Node now = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int dr[] = { -1,1,0,0 };
                        int dc[] = { 0,0,-1,1 };

                        int nr = now.row + dr[d];
                        int nc = now.col + dc[d];

                        if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
                        if (used[nr][nc] != 0) continue;
                        if (map[i][j] != 1) continue;
                        
                        used[nr][nc] = 1;
                        q.push({ nr,nc });
                    }
                }
                cntA++;
            }
        }
    }

    //B : map값이 2인 것
    used = { 0, };
    int cntB = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 2 && used[i][j] == 0) {
                q.push(i, j);
                used[i, j] = 1;

                while (!q.empty()) {
                    Node now = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int dr[] = { -1,1,0,0 };
                        int dc[] = { 0,0,-1,1 };

                        int nr = now.row + dr[d];
                        int nc = now.col + dc[d];

                        if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
                        if (used[nr][nc] != 0) continue;
                        if (map[i][j] != 1) continue;

                        used[nr][nc] = 1;
                        q.push({ nr,nc });
                    }
                }
                cntB++;
            }
        }
    }

    cout << cntA << " " << cntB;

    return 0;
}
