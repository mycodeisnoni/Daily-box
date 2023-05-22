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
//			if (used[v[node][i]]) continue;  // �̹� �湮�� ���̸� continue
//			cout << v[node][i] << " ";
//			used[v[node][i]]++;  // �湮�ߴٴ� ǥ��
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
//		sort(v[i].begin(), v[i].end());  // �չ�ȣ ��带 ���� �湮�� �� �ְ� ����
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

// ���� �ڵ忡���� �湮 ������ ������ ���� ���� ��쿡
// ���� ��ȣ�� ���� ���� ���� �湮�ϴ� ���� �������� �ʴ´�.

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
        sort(v[i].begin(), v[i].end()); // �� ������ ���� ����Ʈ�� ����
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