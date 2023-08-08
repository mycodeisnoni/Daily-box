#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, T;
int member[51] = { 0, };    // 각 사람의 진실 여부
vector<int>party[51];       // 각 파티마다의 참여자
int fiction[51] = { 0, };   // 각 파티가 과장이 가능한지
vector<int>bubble;          // 현재 과장할 수 있는 파티의 인덱스
vector<int>need_check;      // 추후 확인해봐야할 애들

bool cmd(int a, int b){
    if (a > b) return true;
    else return false;
}

void init() {
    cin >> N >> M;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int know_true;
        cin >> know_true;
        member[know_true] = 1;
    }
    for (int k = 0; k < M; k++) {
        int num;
        cin >> num;
        int flag = 0;
        for (int j = 1; j <= num; j++) {
            int now;
            cin >> now;
            party[k].push_back(now);
            if (member[now] == 1) flag = 1;
        }
        if (flag == 1) {
            for (int j = 0; j < num; j++) {
                member[party[k][j]] = 1;
            }
        }
        else bubble.push_back(k);
    }
}

int solve() {

    while (1) {

        int da = -1;

        vector<int>erase_idx;
        for (int i = 0; i < bubble.size(); i++) {
            int flag = 0;
            int checking_len = party[bubble[i]].size();
            for (int d = 0; d < checking_len; d++) {
                if (member[party[bubble[i]][d]]) {      // 진실을 아는 애가 있음
                    flag = 1;
                    for (int m = 0; m < checking_len; m++) member[party[bubble[i]][m]] = 1;
                    break;
                }
            }
            //if (flag == 1) bubble.erase(bubble.begin()+i);
            if (flag == 1) erase_idx.push_back(i);
        }

        if (erase_idx.empty()) break;
        else {
            sort(erase_idx.begin(), erase_idx.end(), cmd);
            for (int re = 0; re < erase_idx.size(); re++) {
                bubble.erase(bubble.begin() + erase_idx[re]);
            }
        }
    }

    int cnt = bubble.size();
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int ans = solve();

    cout << ans;

    return 0;


}