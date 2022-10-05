#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int map[10][10] = { 0, };
bool cmp(int a, int b) {
	if (a > b) return true;
	return false;
}
vector <int> v;
vector <int> honeyValue;


int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		int N, M, C;
		cin >> N >> M >> C;

		memset(map, 0, sizeof(map));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		int maxrow = 0;
		int maxh = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N - M; j++) {
				int honeybox = 0;

				for (int k = 0; k < M; k++) {
					honeybox += map[i][j + k];
					v.push_back(map[i][j + k]);
				}

				if (honeybox <= C) {
					int honey = 0;
					for (int a = 0; a < v.size(); a++) {
						honey += v[a] * v[a];
						if (honey > maxh) {
							maxh = honey;
							maxrow = i;
						}
					}
					honeyValue.push_back(honey);
				}


				else {
					sort(v.begin(), v.end(), cmp);
					int honey = 0;
					int h = 0;
					int honey1 = 0;
					int h1 = 0;
					int honey2 = 0;
					int h2 = 0;

					for (int a = 0; a < v.size(); a++) {
						honey1 += v[a] * v[a];
						h1 += v[a];
						if (h1 > C) {
							honey1 -= v[a] * v[a];
							h1 -= v[a];
						}
					}
					if (M >= 1) {
						for (int a = 1; a < v.size(); a++) {
							honey2 += v[a] * v[a];
							h2 += v[a];
							if (h2 > C) {
								honey2 -= v[a] * v[a];
								h2 -= v[a];
							}
						}
					}
					honey = max(honey1, honey2);
					if (honey > maxh) {
						maxh = honey;
						maxrow = i;
					}
					honeyValue.push_back(honey);
				}
				v.clear();
			}
		}

		sort(honeyValue.begin(), honeyValue.end(), cmp);
		int maxhoney = honeyValue[0];

		honeyValue.clear();

		for (int i = 0; i < N; i++) {
			if (i == maxrow) continue;
			for (int j = 0; j <= N - M; j++) {

				int honeybox = 0;
				for (int k = 0; k < M; k++) {
					honeybox += map[i][j + k];
					v.push_back(map[i][j + k]);
				}

				if (honeybox <= C) {
					int honey = 0;
					for (int a = 0; a < v.size(); a++) {
						honey += v[a] * v[a];
					}
					honeyValue.push_back(honey);
				}

				else {
					sort(v.begin(), v.end(), cmp);
					int honey = 0;
					int h = 0;
					int honey1 = 0;
					int h1 = 0;
					int honey2 = 0;
					int h2 = 0;

					for (int a = 0; a < v.size(); a++) {
						honey1 += v[a] * v[a];
						h1 += v[a];
						if (h1 > C) {
							honey1 -= v[a] * v[a];
							h1 -= v[a];
						}
					}
					if (M >= 1) {
						for (int a = 1; a < v.size(); a++) {
							honey2 += v[a] * v[a];
							h2 += v[a];
							if (h2 > C) {
								honey2 -= v[a] * v[a];
								h2 -= v[a];
							}
						}
					}
					honey = max(honey1, honey2);
					honeyValue.push_back(honey);
				}
				v.clear();
			}
		}

		sort(honeyValue.begin(), honeyValue.end(), cmp);
		maxhoney += honeyValue[0];

		honeyValue.clear();

		cout << "#" << tc << " " << maxhoney << endl;
	}


	return 0;
}