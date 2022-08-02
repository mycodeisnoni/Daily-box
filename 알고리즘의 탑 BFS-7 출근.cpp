#include <iostream>
#include <vector>
#include <queue>
using namespace std;
    
vector <int> v[100];
int used[20] = { 0, };
int level[50] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)   //간선 개수까지
    {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);

    }

    int T;
    cin >> T;
    queue<int>q;

    used[1] = 1;
    q.push(1);


    while (!q.empty()) {

        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            if (next == T) continue;
            if (used[next] != 0) continue;
            used[next] = 1;
            level[next] = level[now] + 1;
            if (next == N) break;
            q.push(next);
        }
    }
    if (level[N] == 0) cout << "-1";
    else cout << level[N];
    

    return 0;
}