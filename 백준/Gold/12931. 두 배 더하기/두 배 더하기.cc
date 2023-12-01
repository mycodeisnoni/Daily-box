#include <iostream>
#include <queue>
using namespace std;

int N;
int arr[51] = { 0, };
int mini[1001][3] = {0,};   // 0은 총합, 1은 덧셈개수, 2는 곱셈개수
int maxi = -1;
int zerocnt = 0;

struct box {
    int num, cnt, plus, multi;
};
bool operator<(box A, box B) {
    if (A.cnt > B.cnt) return true;
    else if (A.cnt < B.cnt) return false;
    else if (A.multi < B.multi) return true;
    else return false;
}
priority_queue<box>pq;

void mapping() {
    pq.push({ 1,1, 1,0 });
    mini[1][0] = 1;
    mini[1][1] = 1;
    while (!pq.empty()) {
        box now = pq.top();
        pq.pop();
        for (int i = 0; i < 2; i++) {
            int num = now.num;
            int cnt = now.cnt;
            int plus = now.plus;
            int multi = now.multi;
            int next;
            if (i == 0) {
                next = num * 2;
                multi++;
            }
            else {
                next = num + 1;
                plus++;
            }

            if (next > maxi) continue;
            if (mini[next][0] != 0 && mini[next][0] < cnt + 1) continue;
            if (mini[next][0] == cnt + 1 && mini[next][1] < plus) continue;
            mini[next][0] = cnt + 1;
            mini[next][1] = plus;
            mini[next][2] = multi;
            
            pq.push({ next, cnt + 1, plus, multi });
        }
    }
}

int calc() {
    int maxmulti = -1;
    int allplus = 0;
    for (int i = 0; i < N; i++) {
        if (mini[arr[i]][2] > maxmulti)maxmulti = mini[arr[i]][2];
        allplus += mini[arr[i]][1];
    }
    return allplus + maxmulti;
}


void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] > maxi) maxi = arr[i];
        if (arr[i] == 0 ) zerocnt++;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    mapping();
    int ans = calc();
    cout << ans;

    return 0;
}