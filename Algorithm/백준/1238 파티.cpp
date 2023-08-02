#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M, X;
const int INF = 2e9;

struct Node {
    int now, cost;
};

bool operator<(Node A, Node B) {
    if (A.cost > B.cost) return true;       // 내림차순 정렬
    return false;
}

vector<Node>map[1001];  // 단방향 도로 정보 저장 벡터 배열
vector<int>dist;        // 최소비용 저장 벡터
int resdist[1001] = { 0, };     // 파티에 오가는 소요시간 저장

void init() {
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        map[start].push_back({ end, cost });
    }
}

void dijkstra(int S) {

    dist.clear();   // 거리 벡터 초기화
    dist.resize(N + 1, INF);     // 맵 사이즈에 맞게 리사이즈 + 최대값으로 초기화

    dist[S] = 0;    // S : 시작마을이므로 나에게서 나까지는 0
    priority_queue<Node>pq;
    pq.push({ S, 0 });   // 시작마을을 우선순위 큐에 넣자!

    while (!pq.empty()) {

        Node nowNode = pq.top();
        pq.pop();
        int now = nowNode.now;      // 현재 마을 번호
        int cost = nowNode.cost;    // S에서 부터 현재 마을까지 드는 비용

        if (cost > dist[now]) continue;     // 최소비용보다 비싸면 continue

        for (int i = 0; i < map[now].size(); i++) {     // now에서 갈 수 있는 모든 마을에 대해 확인
            int next = map[now][i].now;
            int nextCost = cost + map[now][i].cost;     // 현재까지의 비용 + 다음마을까지 추가 비용

            if (nextCost < dist[next]) {    // 더 최소비용이 들 경우 갱신
                dist[next] = nextCost;
                pq.push({ next, nextCost });
            }
        }
    } 
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    for (int i = 1; i <= N; i++) {  // 각 마을에서 X까지 가는 최소 비용 계산
        dijkstra(i);
        resdist[i] = dist[X];
    }

    dijkstra(X);    // X에서 집으로 돌아가기 위한 최소비용 계산
    int maxDist = 0;
    for (int i = 1; i <= N; i++) {
        resdist[i] += dist[i];
        maxDist = max(maxDist, resdist[i]);
    }

    cout << maxDist;

    return 0;
}