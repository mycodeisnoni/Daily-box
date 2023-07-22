#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int removeNode;
vector<int>son[51];			// 나(Idx)의 자식 기록
int headNode;
int ans = 0;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int parent;
		cin >> parent;
		if (parent != -1)son[parent].push_back(i);
		else headNode = i;
	}
	cin >> removeNode;
}


void calc(int Node) {
	if (Node == removeNode) return;
	if (son[Node].size() == 0) {
		ans++;
		return;
	}
	if (son[Node].size() == 1 && son[Node][0] == removeNode) {
		ans++;
		return;
	}
	for (int i = 0; i < son[Node].size(); i++) {
		calc(son[Node][i]);
	}

	return;
}

int main() {
	init();
	calc(headNode);
	cout << ans;
	return 0;
}