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

				// 1. �켱 honeybox�� ���
				// 2. C �� ���� ���, honeyValue == ���ڸ� �����ؼ� ���� ��
				// 3. C���� ���� ���, honeyValue == ���ڸ� �����ؼ� ���� ��
				// 4. C���� Ŭ ���
				//		������ �����ؼ� ���ϴ°Ŷ�
				//		���� �� ����������, ū �� �ϳ��� ���°� �� ũ��.
				//		���Ϳ� �ְ� ���Ľ��Ѽ� C���� ���� �� ����
				//		���غ��ǵ�, �ϴٰ� C���� Ŀ���� �´� ���ְ� �� ����->
				//		�̷� ������ �������.


				// honeyValue�� ���Ϳ� �ְ� ���Ľ�Ű��
				// ���� ū �� �ΰ��� �����ָ� ��

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

				// ���� �߰�!
				// ���� ��, M = 2, �̰� 10 9 5 �� ���޾� �پ��ִٰ� ����
				// �ش� ��쿣 100 ���� 81 + 25 �� �� ũ��!
				// ���� ���� ū ���� ���� �ʴ� ��쵵 ������ �������

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


		// ���� �߰� 2 !!
		// ���� ��, M = 3 �̰� 7 4 9 6 �� ���޾� �پ��ִٰ� ����
		// �ش� ���
		// �Ʒ��� �ҽ��ڵ忡���� 7 4 9 �� 4 9 6 �� ������ �ȴ�.
		// �ٵ� �������� �� �� ���� ä���� �� �ֱ� ������ ��ġ�� ���ؾ� ��.
		// �ƿ� �ҽ��ڵ带 �ٽ� ¥���ϳ�..?
		// // �� �� �ؼ� ���� ū ���� �����ְ�
		// // �ش� �� �������� ���� 0���� ����� �ٽ� ������
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