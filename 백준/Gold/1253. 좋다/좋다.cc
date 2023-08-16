#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<long long>number;
struct Node {
    long long value;
    int first, second;
};
bool operator<(Node A, Node B) {
    if (A.value > B.value) return true;
    else return false;
}
priority_queue<Node>can_make;
vector<Node>v;

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long a;
        cin >> a;
        number.push_back(a);
    }
    sort(number.begin(), number.end());
}

int bp() {
    for (int i = 0; i< number.size(); i++) {
        for (int j = i + 1; j < number.size(); j++) {
            //can_make.push_back(number[i] + number[j]);
            can_make.push({number[i] + number[j] , i, j});
        }
    }

    while (!can_make.empty()) {
        v.push_back(can_make.top());
        can_make.pop();
    }

    int nowIdx = 0;
    int cnt = 0;
    int flag = 0;

    for (int i = 0; i < number.size(); i++) {
        long long now = number[i];
        while (v[nowIdx].value < now) {
            if (nowIdx == v.size()-1) {
                flag = 1;
                break;
            }
            nowIdx++;
        }
        if (flag == 1) break;

        if (now == v[nowIdx].value) {

            int checking = nowIdx;

            while (v[checking].value == v[nowIdx].value) {
                if (v[checking].first != i && v[checking].second != i) {
                    cnt++;
                    break;
                }
                else {
                    if (checking == v.size() - 1) break;
                    checking++;
                }
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    if (N == 1) {
        cout << 0;
        return 0;
    }
    int ans = bp();
    cout << ans;

    return 0;
}
