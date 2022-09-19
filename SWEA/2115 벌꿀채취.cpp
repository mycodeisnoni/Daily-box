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


int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int T;
	cin >> T;
	for (int tc = 1; tc <= 10; tc++) {

		int N, M, C;
		cin >> N >> M >> C;

		memset(map, 0, sizeof(map));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		vector <int> honeyValue;
		int maxrow = 0;
		int maxcol = 0;
		int maxh = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N - M; j++) {
				int honeybox = 0;

				for (int k = 0; k < M; k++) {
					honeybox += map[i][j + k];
					v.push_back(map[i][j + k]);
				}

				// 1. 우선 honeybox를 계산
				// 2. C 와 같을 경우, honeyValue == 각자를 제곱해서 더한 값
				// 3. C보다 작을 경우, honeyValue == 각자를 제곱해서 더한 값
				// 4. C보다 클 경우
				//		어차피 제곱해서 더하는거라
				//		작은 수 여러개보다, 큰 수 하나가 들어가는게 더 크다.
				//		벡터에 넣고 정렬시켜서 C보다 작을 때 까지
				//		더해볼건데, 하다가 C보다 커지면 걔는 빼주고 그 다음->
				//		이런 식으로 계산하자.


				// honeyValue를 벡터에 넣고 정렬시키자
				// 가장 큰 값 두개를 더해주면 됨

				if (honeybox <= C) {
					int honey = 0;
					for (int a = 0; a < v.size(); a++) {
						honey += v[a] * v[a];
						if (honey > maxh) {
							maxh = honey;
							maxrow = i;
							maxcol = j;
						}
					}
					honeyValue.push_back(honey);
				}

				// 문제 발견!
				// 예를 들어서, M = 2, 이고 10 9 5 가 연달아 붙어있다고 가정
				// 해당 경우엔 100 보다 81 + 25 가 더 크다!
				// 따라서 가장 큰 값이 들어가지 않는 경우도 생각을 해줘야해

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
						maxcol = j;
					}
					honeyValue.push_back(honey);
				}
				v.clear();
			}
		}

		sort(honeyValue.begin(), honeyValue.end(), cmp);
		int maxhoney = honeyValue[0];

		honeyValue.clear();


		for (int k = 0; k < M; k++) {
			map[maxrow][maxcol + k] = 0;
		}

		int de = -1;


		// 문제 발견 2 !!
		// 예를 들어서, M = 3 이고 7 4 9 6 이 연달아 붙어있다고 가정
		// 해당 경우
		// 아래의 소스코드에서는 7 4 9 과 4 9 6 이 나오게 된다.
		// 근데 벌꿀집은 단 한 번만 채집될 수 있기 때문에 조치를 취해야 함.
		// 아예 소스코드를 다시 짜야하나..?
		// // 한 번 해서 가장 큰 값을 더해주고
		// // 해당 된 벌꿀집은 전부 0으로 만들고 다시 돌리자
		// ===========================================================

		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N - M; j++) {

				if (map[i][j] == 0) continue;

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
					if (honey > maxh) {
						maxh = honey;
						maxrow = i;
						maxcol = j;
					}
					honeyValue.push_back(honey);
				}
				v.clear();
			}
		}

		sort(honeyValue.begin(), honeyValue.end(), cmp);
		maxhoney += honeyValue[0];

		honeyValue.clear();

		cout << "#" << tc << " " << maxhoney << endl;;
	}


	return 0;
}