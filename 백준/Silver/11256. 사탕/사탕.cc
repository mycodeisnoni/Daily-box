#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int J, N;
vector<int>box;
bool cmd(int a, int b){
    if (a > b) return true;
    else return false;
}

void init() {
    cin >> J >> N;
    for (int i = 1; i <= N; i++) {
        int r, c;
        cin >> r >> c;
        box.push_back(r * c);
    }
    sort(box.begin(), box.end(), cmd);
}

int func() {
    int idx = 0;
    while (J > 0) {
        J -= box[idx];
        idx++;
    }
    return idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        box.clear();
        init();
        int ans = func();
        cout << ans << '\n';
    }
    return 0;
}