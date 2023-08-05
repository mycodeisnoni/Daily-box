#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define LINF 1e18

int N, M;

struct Edge {
    long long now, cost;
};
vector<Edge>cross[100001];
long long dist[100001] = { 0, };

bool operator <(Edge A, Edge B) {
    if (A.cost > B.cost) return true;
    else return false;
}
priority_queue<Edge>pq;

void init() {

    cin >> N >> M;

    for (long long i = 1; i <= M; i++) {
        long long start, end;
        cin >> start >> end;

        // 자동으로 주기의 앞에 있는 애들이 먼저 들어가있는 cross
        cross[start].push_back({ end, i });
        cross[end].push_back({ start,i });
    }
}

long long dijkstra() {

    for (long long i = 1; i <= N; i++) {
        dist[i] = LINF;
    }
    dist[1] = 0;
    pq.push({ 1,0 });

    while (!pq.empty()) {
        Edge cross_now = pq.top();
        pq.pop();

        long long now = cross_now.now;      // 현재 위치
        long long cost = cross_now.cost;    // 현재까지 비용

        long long cnt = cost / M;      // 현재까지 걸린 주기를 돈 횟수
        long long cycle = cross_now.cost % M;    // 현재 해당하는 주기

        if (now == N) return cost;

        for (int i = 0; i < cross[now].size(); i++) {

            long long next = cross[now][i].now;   // 다음에 갈 위치 
            long long nc = cross[now][i].cost % M;    // 그 횡단보도의 주기순서

            if (cycle + 1 > nc) {   //  현재 사이클에선 다음으로 못감
                long long next_cost = (cnt+1) * M + nc;
                if (dist[next] <= next_cost) continue;
                dist[next] = next_cost;
                pq.push({ next, next_cost });
            }
            else {      // 현재 사이클에서 다음으로 갈 수 있음
                long long next_cost = cnt * M + nc;
                if (dist[next] <= next_cost) continue;
                dist[next] = next_cost;
                pq.push({ next, next_cost });
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    long long ans = dijkstra();

    cout << ans;

    return 0;
}