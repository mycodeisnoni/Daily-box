//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <cstring>
//using namespace std;
//
//int N, M, StartNode;
//vector<vector<int>>v;
//int used[1001] = { 0, };
//queue <int> q;
//
//void init() {
//	cin >> N >> M >> StartNode;
//	v.resize(N + 1);
//	for (int i = 0; i < M; i++) {
//		int s, e;
//		cin >> s >> e;
//		v[s].push_back(e);
//		v[e].push_back(s);
//	}
//}
//
//void BFS() {
//	while (!q.empty()) {
//		int node = q.front();
//		q.pop();
//		for (int i = 0; i < v[node].size(); i++) {
//			if (used[v[node][i]]) continue;  // 이미 방문한 점이면 continue
//			cout << v[node][i] << " ";
//			used[v[node][i]]++;  // 방문했다는 표시
//			q.push(v[node][i]);
//		}
//	}
//	return;
//}
//
//void DFS(int Node) {
//	for (int i = 0; i < v[Node].size(); i++) {
//		if (used[v[Node][i]]) continue;
//		cout << v[Node][i] << " ";
//		used[v[Node][i]]++;
//		DFS(v[Node][i]);
//	}
//	return;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
//
//	init();
//
//	for (int i = 0; i < N; i++) {
//		sort(v[i].begin(), v[i].end());  // 앞번호 노드를 먼저 방문할 수 있게 정렬
//	}
//
//	cout << StartNode << " ";
//	used[StartNode] = 1;
//	DFS(StartNode);
//	
//
//	cout << "\n";
//	memset(used, 0, sizeof(used));
//
//	cout << StartNode << " ";
//	used[StartNode] = 1;
//	q.push(StartNode);
//	BFS();
//
//	return 0;
//}

// 위의 코드에서는 방문 가능한 정점이 여러 개인 경우에
// 정점 번호가 작은 것을 먼저 방문하는 것을 보장하지 않는다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M, StartNode;
vector<vector<int>> v;
int used[1001] = { 0, };
queue<int> q;

void init() {
    cin >> N >> M >> StartNode;
    v.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }
    for (int i = 1; i <= N; i++) {
        sort(v[i].begin(), v[i].end()); // 각 정점의 인접 리스트를 정렬
    }
}

void BFS() {
    q.push(StartNode);
    used[StartNode] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < v[node].size(); i++) {
            if (used[v[node][i]]) continue;
            cout << v[node][i] << " ";
            used[v[node][i]]++;
            q.push(v[node][i]);
        }
    }
}

void DFS(int Node) {
    for (int i = 0; i < v[Node].size(); i++) {
        if (used[v[Node][i]]) continue;
        cout << v[Node][i] << " ";
        used[v[Node][i]]++;
        DFS(v[Node][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    init();

    cout << StartNode << " ";
    used[StartNode] = 1;
    DFS(StartNode);


    cout << "\n";
    memset(used, 0, sizeof(used));

    cout << StartNode << " ";
    used[StartNode] = 1;
    q.push(StartNode);
    BFS();

    return 0;
}