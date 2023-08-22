#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int arr[11] = { 0, };
vector<int>v[11];
vector<vector<int>> area;
int all;

void init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        all += arr[i];
    }
    for (int i = 1; i <= N; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int to;
            cin >> to;
            v[i].push_back(to);
        }
    }
}

void generater_combination() {      // 1 ~ (N+1)/2 개 골라서 구역 만들기

    vector<int> elements(N);
    for (int i = 0; i < N; i++) {
        elements[i] = i + 1;
    }

    // 1 : i개, 0 : (N - i) 개
    for (int i = 1; i <= N; i++) {
        vector<bool> combination(N - i, false);
        combination.insert(combination.end(), i, true);

        do {
            vector<int>now;
            for (int j = 0; j < N; j++) {
                if (combination[j]) now.push_back(elements[j]);
            }
            area.push_back(now);
        } while (next_permutation(combination.begin(), combination.end()));
    }
}

int can_go[11] = { 0, };
int now_group[11] = { 0, };

void func(int now) {
    for (int i = 0; i < v[now].size(); i++) {
        if (can_go[v[now][i]]) continue;
        if (now_group[v[now][i]] == 0) continue;
        can_go[v[now][i]] = 1;
        func(v[now][i]);
    }
}


int calc() {
    int ans = 2e9;
    for (int i = 0; i < area.size(); i++) {
        if (area[i].size() > (N + 1) / 2) continue;
        memset(can_go, 0, sizeof(can_go));
        memset(now_group, 0, sizeof(now_group));
        for (int j = 0; j < area[i].size(); j++) now_group[area[i][j]] = 1;
        can_go[area[i][0]] = 1;
        func(area[i][0]);

        int flag = 0;
        for (int j = 0; j < area[i].size(); j++) {
            if (can_go[area[i][j]] == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            vector <int>now2;
            for (int a = 1; a <= N; a++) {
                int flagg = 0;
                for (int b = 0; b < area[i].size(); b++) {
                    if (a == area[i][b]) {
                        flagg = 1;
                        break;
                    }
                }
                if (flagg == 0) now2.push_back(a);
            }

            memset(can_go, 0, sizeof(can_go));
            can_go[now2[0]] = 1;
            memset(now_group, 0, sizeof(now_group));
            for (int j = 0; j < now2.size(); j++) now_group[now2[j]] = 1;
            func(now2[0]);

            int flaggg = 0;
            for (int j = 0; j < now2.size(); j++) {
                if (can_go[now2[j]] == 0) {
                    flaggg = 1;
                    break;
                }
            }
            if (flaggg == 0) {
                int nowcnt = 0;
                for (int j = 0; j < area[i].size(); j++) nowcnt += arr[area[i][j]];
                int nowmin = abs((all - nowcnt) - nowcnt);
                if (nowmin < ans) ans = nowmin;
            }
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    generater_combination();
    int ans = calc();
    if (ans == 2e9) ans = -1;
    cout << ans;

    return 0;
}
