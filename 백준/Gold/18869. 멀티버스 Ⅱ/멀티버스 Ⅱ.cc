#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N;
struct Node {
    int idx, size;
};
bool cmp (Node A, Node B) {
    if (A.size < B.size) return true;
    else if (A.size > B.size) return false;
    else if (A.idx < B.idx) return true;
    else return false;
}
vector<Node>v[101];

void init() {
    cin >> M >> N;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            int size;
            cin >> size;
            v[i].push_back({ j, size });
        }
    }
    for (int i = 1; i <= M; i++) sort(v[i].begin(), v[i].end(), cmp);
}

int checking() {
    int cnt = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = i+1; j <= M; j++) {
            int flag = 0;
            int hidden1 = -1;
            int hidden2 = -1;
            for (int k = 0; k < N; k++) {
                if (v[i][k].idx != v[j][k].idx) {
                    flag = 1;
                    break;
                }
                if (v[i][k].size == hidden1 && v[j][k].size != hidden2) {
                    flag = 1;
                    break;
                }
                hidden1 = v[i][k].size;
                hidden2 = v[j][k].size;
            }
            if (flag == 0) cnt++;
        }
    }
    return cnt;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int ans = checking();
    cout << ans;

    return 0;
}
