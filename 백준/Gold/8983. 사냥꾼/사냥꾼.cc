#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, L;
int catchable[100001] = { 0, };
vector<int>gun;
int cnt = 0;

void solve() {      // 각 x인덱스마다 잡을 수 있는 높이 기록

    for (int i = 0; i < gun.size(); i++) {

        if (i == 0) {
            int k = 0;
            for (int row = gun[0]; row > 0; row--) {
                if (row < 1) continue;
                catchable[row] = L - k;
                k++;
            }
        }

        else {
            int goal = (gun[i] + gun[i - 1]) / 2;
            for (int row = goal + 1; row <= gun[i]; row++) catchable[row] = L - (gun[i] - row);
        }

        if (i != gun.size() - 1) {
            int goal = (gun[i] + gun[i + 1]) / 2;
            for (int row = gun[i]; row <= goal; row++) catchable[row] = L - (row - gun[i]);
        }
    }
}

void init() {
    cin >> M >> N >> L;

    for (int i = 1; i <= M; i++) {
        int m;
        cin >> m;
        gun.push_back(m);
        catchable[m] = L;
    }
    sort(gun.begin(), gun.end());

    solve();

    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;

        if (x > gun[M - 1]) {       // 마지막 사대보다 큰 경우
            if (y <= L - (gun[M - 1] - x)) cnt++;
        }
        else {
           if (catchable[x] >= y) cnt++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    cout << cnt;

    return 0;
}