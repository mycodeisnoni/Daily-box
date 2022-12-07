#include<iostream>
#include <vector>
using namespace std;

int N;
int cnt1, cnt2;
int max_height;
vector<int>tree;
vector<int>need_water;


// ���� ū  ������ Ű�� ����ϰ� �� ���̵��� ���Ϳ� ����.

void init() {

	cin >> N;
	max_height = 0;

	for (int i = 0; i < N; i++) {

		int height;
		cin >> height;
		tree.push_back(height);
		if (height > max_height) max_height = height;

	}

	for (int i = 0; i < tree.size(); i++) {
		need_water.push_back(max_height - tree[i]);
	}
}


// �ʿ��� 2�� ������ 1�� ������ cnt1, cnt2�� ����
// 1�� ������ 2�� �������� ���������� cnt2 �Ѱ��� cnt1 �ΰ��� �ٲ��ִ� �۾�

int calc() {

	cnt1 = 0;
	cnt2 = 0;

	for (int i = 0; i < tree.size(); i++) {
		cnt1 += need_water[i] % 2;
		cnt2 += need_water[i] / 2;
	}

	if (cnt1 == 0 && cnt2 == 0) return 0;
	else if (cnt1 != 0 && cnt2 == 0) {
		return cnt1 * 2 - 1;
	}

	else if (cnt1 == cnt2) return cnt1 * 2;
	else if (cnt1 > cnt2) return cnt1 * 2 - 1;
	else if (cnt2 > cnt1) {
		while (cnt1 < cnt2 - 1) {
			if (cnt2 - 2 == cnt1) {
				return (cnt1 + 2) * 2 - 1;
			}
			cnt1 += 2;
			cnt2--;
		}
		return cnt2 * 2;
	}

}


int main() {

	ios_base::sync_with_stdio(false);

	cin.tie();
	cout.tie();

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		tree.clear();
		need_water.clear();
		init();
		int ans = calc();
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;

}

