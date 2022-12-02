#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

int coin[10] = { 0, };

int max(int a, int b) {
	if (a >= b) return a;
	else return b;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int T, n;
	cin >> T >> n;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	sort(coin, coin + n);

	int now = T;
	int cnt = 0;

	for (int i = n - 1; i>= 0;  i--) {
		now = now % coin[i];
		cnt += now / con[i];
	}

	if (now == 0) cout << cnt;
	else cout << "impossible;"

	return 0;
}