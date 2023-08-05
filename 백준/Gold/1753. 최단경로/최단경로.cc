#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int nodeCnt, edgeCnt;
int startNode;
struct Node {
    int to, cost;
};
vector<Node>Edge[20001];
int dist[20001] = { 0, };

const int MAX = 2e9;
bool operator<(Node A, Node B) {
    if (A.cost > B.cost) return true;
    else return false;
}
priority_queue<Node>pq;

void init() {
    cin >> nodeCnt >> edgeCnt;
    cin >> startNode;
    for (int i = 1; i <= edgeCnt; i++) {
        int now, to, cost;
        cin >> now >> to >> cost;
        Edge[now].push_back({ to, cost });
    }
}

void dijkstra() {
    for (int i = 1; i <= nodeCnt; i++) {
        dist[i] = MAX;
    }
    dist[startNode] = 0;
    pq.push({ startNode, 0 });

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        int now = node.to;
        int now_cost = node.cost;

        for (int i = 0; i < Edge[now].size(); i++) {
            int next = Edge[now][i].to;
            int cost = Edge[now][i].cost;

            if (dist[next] <= now_cost + cost) continue;
            dist[next] = now_cost + cost;
            pq.push({ next, dist[next] });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    dijkstra();
    
    for (int i = 1; i <= nodeCnt; i++) {
        if (i == startNode) cout << 0 << '\n';
        else if (dist[i] < MAX) cout << dist[i] << '\n';
        else cout << "INF\n";
    }

    return 0;
}