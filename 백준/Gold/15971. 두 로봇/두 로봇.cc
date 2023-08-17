#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N;
int robot1, robot2;
struct Node {
    int left, right;
};
vector<Node>bridge;

struct Edge {
    int to, cost;
};
bool operator < (Edge A, Edge B) {
    if (A.cost > B.cost) return true;
    else return false;
}
priority_queue<Edge>pq1;
priority_queue<Edge>pq2;
vector<Edge>v[100001];
int dist1[100001] = { 0, };
int dist2[100001] = { 0, };

void init() {
    cin >> N >> robot1 >> robot2;
    pq1.push({ robot1, 0 });
    pq2.push({ robot2, 0 });
    for (int i = 1; i < N; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        v[start].push_back({ end, cost });
        v[end].push_back({ start, cost });
        bridge.push_back({ start, end });
    }
}

void dijkstra() {

    for (int i = 1; i <= N; i++) {
        dist1[i] = 2e9;
        dist2[i] = 2e9;
    }
    dist1[pq1.top().to] = 0;
    dist2[pq2.top().to] = 0;

    while (!pq1.empty()) {
        
        Edge now = pq1.top();

        int nowPlace = now.to;
        int nowCost = now.cost;
        pq1.pop();

        for (int i = 0; i < v[nowPlace].size(); i++) {
            int next = v[nowPlace][i].to;
            int nextCost = nowCost + v[nowPlace][i].cost;

            if (dist1[next] < nextCost) continue;
            dist1[next] = nextCost;
            pq1.push({ next, nextCost });
        }
    }

    while (!pq2.empty()) {

        Edge now = pq2.top();

        int nowPlace = now.to;
        int nowCost = now.cost;
        pq2.pop();

        for (int i = 0; i < v[nowPlace].size(); i++) {
            int next = v[nowPlace][i].to;
            int nextCost = nowCost + v[nowPlace][i].cost;

            if (dist2[next] < nextCost) continue;
            dist2[next] = nextCost;
            pq2.push({ next, nextCost });
        }
    }
}

int solve() {
    int mindist = 2e9;

    for (int i = 0; i < bridge.size(); i++) {
        int left = bridge[i].left;
        int right = bridge[i].right;

        int d1 = dist1[left] + dist2[left];
        int d2 = dist1[left] + dist2[right];
        int d3 = dist1[right] + dist2[left];
        int d4 = dist1[right] + dist2[right];

        int minnow = min(min(d1, d2), min(d3, d4));
        if (minnow < mindist) mindist = minnow;
    }
    return mindist;
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
    dijkstra();
    int ans = solve();
    cout << ans;
    
    return 0;
}