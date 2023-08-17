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
bool cmp(Node A, Node B) {
    if (A.value < B.value) return true;
    else return false;
}
vector<Node>can_make;

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
    for (int i = 0; i < number.size(); i++) {
        for (int j = i + 1; j < number.size(); j++) {
            //can_make.push_back(number[i] + number[j]);
            can_make.push_back({ number[i] + number[j] , i, j });
        }
    }
    sort(can_make.begin(), can_make.end(), cmp);


    int nowIdx = 0;
    int cnt = 0;
    int flag = 0;

    for (int i = 0; i < number.size(); i++) {
        long long now = number[i];
        while (can_make[nowIdx].value < now) {
            if (nowIdx == can_make.size() - 1) {
                flag = 1;
                break;
            }
            nowIdx++;
        }
        if (flag == 1) break;

        if (now == can_make[nowIdx].value) {

            int checking = nowIdx;

            while (can_make[checking].value == can_make[nowIdx].value) {
                if (can_make[checking].first != i && can_make[checking].second != i) {
                    cnt++;
                    break;
                }
                else {
                    if (checking == can_make.size() - 1) break;
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
