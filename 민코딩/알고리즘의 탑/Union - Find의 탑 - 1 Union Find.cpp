#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int parent[1001] = { 0, };

int Find(int now) {
	if (parent[now] == now) return now;
	return parent[now] = Find(parent[now]);
}

void Union(int a, int b) {
	int pA = Find(a);
	int pB = Find(b);

	if (pA == pB) return;
	parent[pB] = pA;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int N, Q;
	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < Q; i++) {
		int a, b, c;
		cin >> a;

		if (a == 0)
		{
			cin >> b >> c;
			if (Find(b) == Find(c)) cout << "YES\n";
			else cout << "NO\n";
		}
		if (a == 1)
		{
			cin >> b >> c;
			Union(b, c);
		}
	}
	
	return 0;
}


