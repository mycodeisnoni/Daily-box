#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int T;
int N, K, W;
int delay[1001] = { 0, };
int dp[1001] = { 0, };
vector<int>after[1001];     // 반드시 내 다음에 지을 수 있다
vector<int>before[1001];    // 반드시 나보다 먼저 지어야한다
struct Node {
    int next, time;
};
vector<Node>start;

void init() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        after[i].clear();
        before[i].clear();
        dp[i] = -1;
    }
    for (int i = 1; i <= N; i++) cin >> delay[i];
    for (int i = 1; i <= K; i++) {
        int x, y;
        cin >> x >> y;
        after[x].push_back(y);
        before[y].push_back(x);
    }
    cin >> W;
}

void setting() {
    for (int i = 1; i <= N; i++) {
        if (after[i].size() == 0) start.push_back({ i, 0 });
        if (before[i].size() == 0) dp[i] = delay[i];
    }
}

int func(int now) {

    if (dp[now] != -1) return dp[now];

    for (int i = 0; i < before[now].size(); i++) {
        int next = before[now][i];
        int nowcost = func(next);
        if (nowcost + delay[now] > dp[now]) dp[now] = nowcost + delay[now];
    }
    return dp[now];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        memset(delay, 0, sizeof(delay));
        start.clear();
        init();
        setting();
        for(int i = 0; i < start.size(); i++) func(start[i].next);
        cout << dp[W] << '\n';
    }

    return 0;
}
