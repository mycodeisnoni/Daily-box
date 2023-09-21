#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<int>v;
vector<int>space;
vector<int>can;
vector<int>ans;

void init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
}

void setting() {
    for (int i = 1; i < v.size(); i++) {
        space.push_back(v[i] - v[i - 1]);
    }
    sort(space.begin(), space.end());

    int left = 2;
    int right = space[0];
    while (left < right) {
        if (space[0] % left == 0) {
            can.push_back(left);
            right = space[0] / left;
            if (left == right) continue;
            can.push_back(right);
        }
        left++;
    }
    can.push_back(space[0]);
    sort(can.begin(), can.end());

    for (int i = can.size() - 1; i >= 0; i--) {
        int flag = 0;
        for (int j = 1; j < space.size(); j++) {
            if (space[j] % can[i] != 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) ans.push_back(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    setting();
    for (int i = ans.size()-1; i >=0; i--) cout << can[ans[i]] << " ";

    return 0;
}