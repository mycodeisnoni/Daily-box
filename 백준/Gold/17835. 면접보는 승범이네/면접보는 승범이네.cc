#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int nodecnt, edgecnt, cnt;


struct Node {
    int to;
    long long cost;
};
vector<Node>Edge[100001];
bool operator<(Node A, Node B) {
    if (A.cost > B.cost) return true;
    else return false;
}
vector<int>room;
long long dist[100001] = { 0, };
priority_queue<Node>pq;


void init() {
    cin >> nodecnt >> edgecnt >> cnt;
    for (int i = 0; i < edgecnt; i++) {
        int now, to;
        long long cost;
        cin >> now >> to >> cost;
        Edge[to].push_back({ now, cost });
    }

    for (int i = 1; i <= nodecnt; i++) dist[i] = 1e18;

    for (int i = 0; i < cnt; i++) {
        int num;
        cin >> num;
        room.push_back(num);
        pq.push({ num, 0 });
        dist[num] = 0;
    }
}

void dijkstra() {

    while (!pq.empty()) {

        int now = pq.top().to;
        long long nowDist = pq.top().cost;
        pq.pop();
        if (nowDist > dist[now]) continue;
       
        for (int i = 0; i < Edge[now].size(); i++) {
            int next = Edge[now][i].to;
            long long cost = Edge[now][i].cost;
            long long nextDist = cost + nowDist;

            if (nextDist >= dist[next]) continue;
            dist[next] = nextDist;
            pq.push({ next, nextDist });
        }
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    dijkstra();

    long long ansDist = -1;
    int ansIdx = 1;
    for (int i = 1; i <= nodecnt; i++) {
        if (dist[i] > ansDist) {
            ansDist = dist[i];
            ansIdx = i;
        }
    }

    cout << ansIdx << '\n' << ansDist;
    
    return 0;
}