#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, K;
int timer[100001] = { 0, };
queue<int>q;

void init() {
    cin >> N >> K;
}

void func() {

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        int next = 0;
        for (int i = 0; i < 3; i++) {
            if (i == 0) next = now - 1;
            if (i == 1) next = now + 1;
            if (i == 2) next = now * 2;

            if (next < 0) continue;
            if (next > 100000) continue;
            if (timer[next] != -1) continue;

            timer[next] = timer[now] + 1;
            q.push(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    memset(timer, -1, sizeof(timer));

    q.push(N);
    timer[N] = 0;

    func();
    cout << timer[K];
    return 0;
}