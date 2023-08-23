#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<int>go[32001];
vector<int>come[32001];
struct Node {
    int next, level;
};
queue<Node>qnow;
queue<Node>qnext;
int levelcnt[32001] = { 0, };

struct Edge {
    int idx, level;
};
vector<Edge>v;
bool cmp(Edge A, Edge B) {
    if (A.level < B.level) return true;
    else return false;
}

void init() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int first, second;
        cin >> first >> second;
        go[second].push_back(first);
        come[first].push_back(second);
    }
}

void setting() {
    for (int i = 1; i <= N; i++) {
        if (go[i].size() == 0) qnow.push({ i, 0 });
    }
}

void func() {

    while (!qnow.empty()) {
        Node now = qnow.front();
        qnow.pop();

        int nowidx = now.next;
        int level = now.level;
        for (int i = 0; i < come[nowidx].size(); i++) {
            if (levelcnt[come[nowidx][i]] >= level + 1) continue;
            levelcnt[come[nowidx][i]] = level + 1;
            qnow.push({ come[nowidx][i], level + 1 });
        }
    }
}

void calc() {
    for (int i = 1; i <= N; i++) {
        v.push_back({ i, levelcnt[i] });
    }
    sort(v.begin(), v.end(), cmp);
}

void printing() {
    for (int i = 0; i < v.size(); i++) cout << v[i].idx << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    setting();
    func();
    calc();
    printing();

    return 0;
}
