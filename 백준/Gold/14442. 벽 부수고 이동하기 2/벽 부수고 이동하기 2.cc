#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
int map[1001][1001] = { 0, };
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
int used[1001][1001][2] = {0,};     // 0 : visited , 1: min broken

struct place {
    int row, col, cost, broken;
};
bool operator<(place A, place B) {
    if (A.cost > B.cost) return true;
    else return false;
}
priority_queue<place>pq;


void init(){
    cin >> N >> M >> K;
    for (int row = 0; row < N; row++) {
        string x;
        cin >> x;
        for (int col = 0; col < M; col++) map[row][col] = x[col] - '0';
        used[0][0][0] = 1;
    }
    pq.push({ 0,0,1,0 });
}

int bfs() {
    while (!pq.empty()) {
        place now = pq.top();
        pq.pop();

        int row = now.row;
        int col = now.col;
        int cost = now.cost;
        int broken = now.broken;
        if (row == N - 1 && col == M - 1) return cost;

        for (int d = 0; d < 4; d++) {
            int nr = row + dr[d];
            int nc = col + dc[d];
            if (nr < 0 || nc < 0 || nr >= N || col >= M) continue;
            if (map[nr][nc] == 1 && broken == K) continue;
            int nb = broken;
            if (map[nr][nc] == 1) nb++;
            if (used[nr][nc][0] && used[nr][nc][1] <= nb) continue;
            if (nr == N - 1 && nc == M - 1) return cost + 1;
            
            used[nr][nc][0] = 1;
            used[nr][nc][1] = nb;
            pq.push({ nr,nc,cost + 1, nb });
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