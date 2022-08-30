#include <iostream>
#include <vector>
using namespace std;

vector <int> v[101];
int used[101] = { 0, };

void dfs(int now) {

	if (v[now].empty()) return;

	for (int i = 0; i < v[now].size(); i++) {
		if (used[v[now][i]]) continue;
		used[v[now][i]] = 1;
		dfs(v[now][i]);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int CntNode, CntEdge;
	cin >> CntNode >> CntEdge;

	for (int i = 0; i < CntEdge; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	used[1] = 1;
	dfs(1);

	int cnt = 0;
	for (int i = 2; i <= CntNode; i++) {
		if (used[i]) cnt++;
	}

	cout << cnt;


	return 0;
}