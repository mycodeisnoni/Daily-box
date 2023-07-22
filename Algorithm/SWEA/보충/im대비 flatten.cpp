#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	for (int tc = 1; tc <= 10; tc++) {
		int limit;
		cin >> limit;

		int map[1000] = { 0, };
		int maxheight = -1;
		int minheight = 101;


		for (int i = 0; i < 100; i++) {

			int height;
			cin >> height;
			map[height]++;
			if (height > maxheight) maxheight = height;
			if (height < minheight) minheight = height;

		}

		while (limit > 0)
		{


			map[maxheight]--; map[maxheight - 1]++;
			if (!map[maxheight]) maxheight--;
			map[minheight]--;
			map[minheight + 1]++;
			if (!map[minheight]) minheight++;

			limit--;

		}

		cout << "#" << tc << " " << maxheight - minheight << endl;
	}

	return 0;
}