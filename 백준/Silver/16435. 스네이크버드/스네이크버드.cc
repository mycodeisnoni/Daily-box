#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L;
vector<int>v;

void init() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
}

int func() {
    sort(v.begin(), v.end());
    int nowidx = 0;
    int nowlength = L;
    bool flag = true;
    while (flag && (nowidx<N)) {
        if (nowlength >= v[nowidx]) {
            nowlength++;
            nowidx++;
        }
        else flag = false;
    }
    return nowlength;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int ans = func();
    cout << ans;
    
    return 0;
}