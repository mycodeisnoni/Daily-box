#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
using namespace std;
bool visited[100001];
int dist[100001] = { 0, };
struct Node {
	int place, time;
};
bool operator<(Node A, Node B) {
	if (A.time > B.time) return true;
	else return false;
}
priority_queue<Node>pq;

void init() {
    cin >> n >> k;
}

void bfs() {
	
	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();
		if (now.place == k) {
			cout << dist[k];
			return;
		}
		for (int i = -1; i < 2; i++) {
			int next, nexttime;
			if (i == 0) {
				next = now.place * 2;
				nexttime = now.time;
			}
			else {
				next = now.place + i;
				nexttime = now.time + 1;
			}
			if (next < 0 || next > 100000) continue;
			if (dist[next] <= nexttime && visited[next]) continue;
			pq.push({ next, nexttime });
			visited[next] = true;
			dist[next] = nexttime;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
	pq.push({ n,0 });
	visited[n] = true;
    bfs();

    return 0;
}