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
    if (A.cost > B.cost) return true;       // �������� ����
    return false;
}

vector<Node>map[1001];  // �ܹ��� ���� ���� ���� ���� �迭
vector<int>dist;        // �ּҺ�� ���� ����
int resdist[1001] = { 0, };     // ��Ƽ�� ������ �ҿ�ð� ����

void init() {
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        map[start].push_back({ end, cost });
    }
}

void dijkstra(int S) {

    dist.clear();   // �Ÿ� ���� �ʱ�ȭ
    dist.resize(N + 1, INF);     // �� ����� �°� �������� + �ִ밪���� �ʱ�ȭ

    dist[S] = 0;    // S : ���۸����̹Ƿ� �����Լ� �������� 0
    priority_queue<Node>pq;
    pq.push({ S, 0 });   // ���۸����� �켱���� ť�� ����!

    while (!pq.empty()) {

        Node nowNode = pq.top();
        pq.pop();
        int now = nowNode.now;      // ���� ���� ��ȣ
        int cost = nowNode.cost;    // S���� ���� ���� �������� ��� ���

        if (cost > dist[now]) continue;     // �ּҺ�뺸�� ��θ� continue

        for (int i = 0; i < map[now].size(); i++) {     // now���� �� �� �ִ� ��� ������ ���� Ȯ��
            int next = map[now][i].now;
            int nextCost = cost + map[now][i].cost;     // ��������� ��� + ������������ �߰� ���

            if (nextCost < dist[next]) {    // �� �ּҺ���� �� ��� ����
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

    for (int i = 1; i <= N; i++) {  // �� �������� X���� ���� �ּ� ��� ���
        dijkstra(i);
        resdist[i] = dist[X];
    }

    dijkstra(X);    // X���� ������ ���ư��� ���� �ּҺ�� ���
    int maxDist = 0;
    for (int i = 1; i <= N; i++) {
        resdist[i] += dist[i];
        maxDist = max(maxDist, resdist[i]);
    }

    cout << maxDist;

    return 0;
}