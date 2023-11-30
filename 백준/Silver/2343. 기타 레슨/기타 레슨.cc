#include <iostream>
using namespace std;

int N, M;
int blueray[100001] = { 0, };
long long dis = 0;

void init() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> blueray[i];
        dis += blueray[i];
    }
}

bool calc(long long mid) {

    int cnt = 0;
    long long num = 0;
    int idx = 1;

    while (idx <= N) {

        long long next = num + blueray[idx];

        if (next <= mid) {
            num = next;
            idx++;
        }
        else {
            num = 0;
            cnt++;
        }
        if (idx == N + 1) cnt++;
        if (cnt > M) return false;
    }

    if (cnt <= M) return true;
}

long long bp() {
    long long left = blueray[N];
    long long right = dis;
    long long mid = 0;
    long long result = 0;

    while (left <= right) {
        mid = (right + left) / 2;

        if (calc(mid)) {
            right = mid - 1;
            result = mid;
        }
        else left = mid + 1;
    }

    return result;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    long long ans = bp();
    cout << ans;

    return 0;
}

