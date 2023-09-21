#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N;
int map[126][126] = { 0, };
int dp[126][126] = { 0, };
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };
struct Node {
    int row, col, cost;
};
bool operator<(Node A, Node B) {
    if (A.cost > B.cost) return true;
    else return false;
}
priority_queue<Node>pq;

int init() {
    cin >> N;
    if (N == 0) return -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            dp[i][j] = 2e9;
        }
    }
    pq.push({ 0,0,map[0][0] });
    dp[0][0] = map[0][0];

    return 1;
}

void DP() {
    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        if (now.cost > dp[now.row][now.col]) continue;

        for (int i = 0; i < 4; i++) {
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];

            if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
            int nextcost = now.cost + map[nr][nc];
            if (nextcost >= dp[nr][nc]) continue;
            dp[nr][nc] = nextcost;
            pq.push({ nr,nc,nextcost });

        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int casenum = 0;
    while (1) {
        int flag = init();
        if (flag == -1) return 0;
        casenum++;
        DP();
        cout << "Problem " << casenum << ": " << dp[N - 1][N - 1] << '\n';
    }

}