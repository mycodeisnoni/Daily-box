#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[101];
int used[101] = { 0, };
int used2[101] = { 0, };

bool cmp(int a, int b) {
	if (a > b) return true;
	return false;
}

void dfs(int now) {

	cout << now << " ";

	for (int i = 0; i < v[now].size(); i++) {
		if (used[v[now][i]]) continue;
		used[v[now][i]] = 1;
		dfs(v[now][i]);
	}

	return;
}

void dfs2(int now) {
	for (int i = 0; i < v[now].size(); i++) {
		if (used2[v[now][i]]) continue;
		used2[v[now][i]] = 1;
		dfs2(v[now][i]);
	}
	cout << now << " ";

	return;
}


int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int N, K;
	cin >> N >> K;

	int S;
	cin >> S;

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			sort(v[i].begin(), v[i].end(), cmp);
		}
	}

	used[S] = 1;
	used2[S] = 1;
	dfs(S);

	cout << endl;

	int de = -1;

	dfs2(S);


	return 0;
}