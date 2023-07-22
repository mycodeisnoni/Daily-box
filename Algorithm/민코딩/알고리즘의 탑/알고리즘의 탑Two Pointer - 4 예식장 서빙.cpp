#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

int map[2000000] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++) {
		int N, R;
		cin >> N >> R;
		int used[201] = { 0, };
		int flag = 0;

		if (2 * R + 1 == N)
		{
			for (int j = 0; j < N; j++) {
				int menu;
				cin >> menu;
				used[menu]++;
				if (used[menu] ==3) flag = 1;
			}
			if (flag == 1) { cout << "#" << i << " NO\n"; }
			else if (!flag) { cout << "#" << i << " YES\n"; }
		}


		else {
			for (int j = 0; j < N; j++) {
				cin >> map[j];
				map[N + j] = map[j];
			}



			int left = 0;
			int right = -1;
			int wing;
			

			while (left < N)
			{
				wing = right - left + 1;
				if (wing < 2 * R + 1)
				{
					right++;
					used[map[right]]++;
					if (used[map[right]] > 2) flag++;
				}
				else if (wing == 2 * R + 1)
				{
					used[map[left]]--;
					left++;
				}

			}
			if (flag) { cout << "#" << i << " NO\n"; }
			else if (!flag) { cout << "#" << i << " YES\n"; }
		}
	}
		return 0;
	}