#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int cnt;
vector<int>want;
int check[100001] = { 0, };
vector<int>group;

void init() {
    cin >> N;
    cnt = N;
    for (int i = 1; i <= N; i++) {
        int now;
        cin >> now;
        want.push_back(now);
        if (i == now) {
            check[now] = 1;
            cnt--;
        }
    }
}

void dfs(int now) {
    if (check[want[now]] == 1 || check[want[now]] == -1) {
        for (int i = 0; i < group.size(); i++) check[group[i]] = -1;
        return;
    }
    if (check[want[now]] == 3) {
        cnt -= group.size();
        for (int i = 0; i < group.size(); i++) check[group[i]] = 1;
        return;
    }
    if (check[want[now]] == 2) {
        int end = want[now];
        int start = 0;
        while (group[start] != end) {
            check[group[start]] = -1;
            start++;
        }
        for (int i = start; i < group.size(); i++) {
            check[group[i]] = 1;
            cnt--;
        }
        return;
    }
    check[want[now]] = 2;
    group.push_back(want[now]);
    dfs(want[now]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        memset(check, 0, sizeof(check));
        want.clear();
        want.push_back(0);
        init();
        for (int i = 1; i <= N; i++) {
            if (check[i] != 0) continue;
            if (check[want[i]] == 1) {
                check[i] = -1;
                continue;
            }
            group.clear();
            group.push_back(i);
            check[i] = 3;
            dfs(i);
        }
        cout << cnt << '\n';
    }
    return 0;
}
