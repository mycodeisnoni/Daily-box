#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

int N, M, P;
int map[200000] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> N >> M >> P;
	int suum = 0;
	if (N == M)
	{
		for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		suum += a;
		}
		if (suum < P) { cout << 1; return 0; }
		else { cout << 0; return 0; }

	}

	for (int i = 0; i < N; i++) {
		cin >> map[i];
		map[N + i] = map[i];
	}

	int left = 0;
	int right = -1;
	int sum = 0;
	int cnt = 0;
	int num;

	

	while ( left < N)
	{
		num = right - left + 1;
		if (num < M)
		{
			right++;
			sum += map[right];
		}

		else if (num == M)
		{
			if (sum < P) cnt++;
			sum -= map[left];
			left++;
		}
	}

	cout << cnt;

	return 0;
}