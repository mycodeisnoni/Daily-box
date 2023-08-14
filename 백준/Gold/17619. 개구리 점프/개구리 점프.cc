#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, Q;
struct Node {
    int nowIdx, start, end;
};
bool operator <(Node A, Node B) {
    if (A.start > B.start) return true;
    else return false;
}
priority_queue<Node>tree;

int root[100001] = { 0, };      // 부모? 기록

void init() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        tree.push({ i, x1, x2 });
    }
}

void setting() {

    int cnt = 1;
    Node starting = tree.top();
    tree.pop();
    root[starting.nowIdx] = cnt;
    int checking = starting.end;
    
    while (!tree.empty()) {
        Node now = tree.top();
        tree.pop();

        if (now.start <= checking) {    // 이동 가능
            root[now.nowIdx] = cnt;
            if (now.end > checking) checking = now.end;     // 더 끝으로 갱신
        }
        else {      // 이동 불가능
            cnt++;
            root[now.nowIdx] = cnt;
            checking = now.end;         // 새로운 통나무의 끝으로 바꾸기
        }

    }
}

void solve() {
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        if (root[a] == root[b]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    setting();
    solve();
    
    return 0;
}