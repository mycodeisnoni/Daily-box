#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int T;
int N, M, K;
int map[51][51] = { 0, };
struct Node {
    int row, col;
};
vector<Node>veg;
int visited[51][51] = { 0, };
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };

void init() {
    cin >> M >> N >> K;
    memset(map, 0, sizeof(map));
    veg.clear();
    for (int i = 1; i <= K; i++) {
        int row, col;
        cin >> col >> row;
        map[row+1][col+1] = 1;
        veg.push_back({ row+1, col+1 });
    }
}

int filled() {

    memset(visited, 0, sizeof(visited));
    int cnt = 1;

    for (int i = 0; i < veg.size(); i++) {

        
        queue<Node>q;
        if (visited[veg[i].row][veg[i].col]) continue;
        q.push({ veg[i] });
        visited[veg[i].row][veg[i].col] = cnt; 

        while (!q.empty()) {
            Node now = q.front();
            q.pop();

            int row = now.row;
            int col = now.col;

            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr <1 || nc<1 || nr>N || nc>M) continue;
                if (visited[nr][nc]) continue;
                if (map[nr][nc] == 0) continue;

                visited[nr][nc] = cnt;
                q.push({ nr,nc });
            }
        }
        cnt++;
    }
    return cnt - 1;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        init();
        int ans = filled();
        int aaaa = 2;
        cout << ans << '\n';
    }
    
    

    return 0;
}
