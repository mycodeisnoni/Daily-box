#include <iostream>
#include <vector>
#include <queue>
using namespace std;
    
vector <int> v[100];
int used[100] = { 0, };
int level[100] = { 0, };

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

    int R, K;
    cin >> R>> K;

    queue<int>q;

    used[R] = 1;
    q.push(R);


    while (!q.empty()) {

        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            if (used[next] != 0) continue;
            if (level[now] + 1 > K) continue;
            used[next] = 1;
            level[next] = level[now] + 1;
            q.push(next);
        }
    }
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        cout << level[i] << "\n";
        if (level[i] != 0) ans++;
    }
    cout << ans;

    return 0;
}