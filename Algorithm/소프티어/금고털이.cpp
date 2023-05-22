#include <iostream>
using namespace std;

int W, N;
int safe[10001] = { 0, };
int maxcost;

void init() {
	cin >> W >> N;
	for (int i = 0; i < N; i++) {
		int m, cost;
		cin >> m >> cost;
		safe[cost] += m;
		if (cost > maxcost) maxcost = cost;
	}
}

int thief() {
	int rest = W;
	int money = 0;
	for (int i = maxcost; i >=0 ; i--) {
		if (safe[i] == 0) continue;
		int now = safe[i];
		if (rest > now) {
			rest -= now;
			money += i * now;
		}
		else if (rest == now) {
			rest -= now;
			money += i * now;
			return money;
		}
		else {
			money += i * rest;
			return money;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	init();
	int ans = thief();
	cout << ans;

	return 0;
}