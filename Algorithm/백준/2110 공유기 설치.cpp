#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int>v;
int maxdis = -1;
int mindis = 2e9;

void init() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        int house;
        cin >> house;
        v.push_back(house);
    }
    sort(v.begin(), v.end());
}

bool func(int dis) {

    int nowIdx = 0;
    int cnt = 1;
    int next = v[nowIdx] + dis;

    while (next <= v[N - 1]) {
        while (v[nowIdx] < next) {
            nowIdx++;
        }
        cnt++;
        next = v[nowIdx] + dis;
    }

    if (cnt >= C) return true;

    else return false;
}


int bp() {
    int left = 0;
    int right = v[v.size() - 1];
    int mid = 0;

    while (left <= right) {
        mid = (right + left) / 2;
        if (func(mid)) {
            if (mid > maxdis) maxdis = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return maxdis;
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    if (N == C) {    // 집까지의 거리가 가장 작은 곳이 답
        for (int i = 1; i < N; i++) {
            int nowdis = v[i] - v[i - 1];
            if (nowdis < mindis) mindis = nowdis;
        }
        cout << mindis;
        return 0;
    }
    int ans = bp();

    cout << ans;
    return 0;
}