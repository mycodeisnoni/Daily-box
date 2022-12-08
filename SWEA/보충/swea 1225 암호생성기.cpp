#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	for (int i = 0; i < 10; i++) {
		queue<int>q;
		int map[8] = { 0, };
		int tc;
		cin >> tc;
		int minnum = 10300;
		for (int j = 0; j < 8; j++) {
			cin >> map[j];
			//q.push(map[j]);

			if (map[j] < minnum) minnum = map[j];
		}

		int a = minnum / 15;

		int de = -1;

		if (minnum%15 == 0) a--;

		for (int j = 0; j < 8; j++) {
			map[j] -= 15 * a;
			q.push(map[j]);
		}


		int flag = 0;
		while (1)
		{
			int cnt = 1;
			while (cnt < 6)
			{
				int now = q.front();
				q.pop();

				if (now - cnt > 0) {
					q.push(now - cnt);
					cnt++;
				}
				else {
					q.push(0);
					flag = 1;
					break;
				}
			}
			if (flag == 1) break;
		}

		cout << "#" << tc << " ";
		for (int i = 0; i < 8; i++) {
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}

	return 0;
}



