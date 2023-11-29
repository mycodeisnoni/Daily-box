#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int cnt = 0;
int flag[2000002] = { 0, };
vector<int>sensor;
vector<int>dist;

void init() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        if (flag[n + 1000000]) continue;
        else {
            sensor.push_back(n);
            flag[n+1000000] = 1;
            cnt++;
        }
    }
    sort(sensor.begin(), sensor.end());
    
}

int calc() {

    int value = 0;
    for (int i = 0; i < sensor.size() - 1; i++) {
        int distance = sensor[i + 1] - sensor[i];
        dist.push_back(distance);
    }
    sort(dist.begin(), dist.end());

    int idx = 0;

    while (cnt > K) {
        if (idx >= dist.size()) break;
        value += dist[idx];
        idx++;
        cnt--;
    }
    return value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    int ans = calc();
    cout << ans;

    return 0;
}