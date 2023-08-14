#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int map[501][501] = { 0, };

vector<int>go[501];
vector<int>come[501];

vector<int>can_go;
vector<int>can_come;

int gone[501] = { 0, };
int came[501] = { 0, };

void init() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        go[a].push_back(b);
        come[b].push_back(a);
    }
}

void dfs_go(int S) {

    for (int i = 0; i < go[S].size(); i++) {
        if (gone[go[S][i]]) continue;
        gone[go[S][i]] = 1;
        can_go.push_back(go[S][i]);
        dfs_go(go[S][i]);
    }
}

void dfs_come(int S) {

    for (int i = 0; i < come[S].size(); i++) {
        if (came[come[S][i]]) continue;
        came[come[S][i]] = 1;
        can_come.push_back(come[S][i]);
        dfs_come(come[S][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        memset(gone, 0, sizeof(gone));
        memset(came, 0, sizeof(came));
        gone[i] = 1;
        came[i] = 1;
        can_go.clear();
        can_come.clear();
        dfs_go(i);
        dfs_come(i);
        
        if (can_go.size() + can_come.size() == N - 1) cnt++;
    }
    
    cout << cnt;
    return 0;
}