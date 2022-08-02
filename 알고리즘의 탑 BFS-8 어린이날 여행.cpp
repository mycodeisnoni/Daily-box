#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> v[200001];
int used[200001] = { 0, };
int level[200001] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int N, M, K, P;
    cin >> N >> M >> K >> P;

    for (int i = 0; i < M; i++)   //간선 개수까지
    {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
    }

    queue<int>q;

    used[P] = 1;
    q.push(P);


    while (!q.empty()) {

        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            if (used[next] != 0) continue;
            used[next] = 1;
            level[next] = level[now] + 1;
            q.push(next);
        }
    }

    int cnt = 0;

    for (int i = 0; i <= N; i++) {
        if (level[i] == K) {
            cout << i << '\n';
            cnt++;
        }
    }
    if (cnt == 0) cout << "-1";
    return 0;
}