#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H,K,R;
int worker = 1;
vector<vector<int>>task;
vector<int>order;
vector<int>idxCalc;

void init() {
	cin >> H >> K >> R;

	for (int i = 0; i < H; i++) {
		worker *= 2;
	}

	for (int i = 0; i < worker; i++) {
		for (int j = 0; j < K; j++) {
			int a;
			cin >> a;
			task[i].push_back(a);
		}
	}
}

// ó���� ��� �ұ�
// H�� �� ����, ���� ���� ����� �� = 2^H
// �ε��� ����
// ���� �� �߶� ��
// 0, H/2
// �ٽ� ���� �߶� 0,H/2 �ε����� ���Ѵ�
// 0 + H/4, H/2 + H/4
// �ٽ� ���� �߶�  ���� �ε����鿡 ���Ѵ�
// �� ��, ���� ��� �ε����鿡 ���� ������ �ʿ��ϴ�,
//  0 + H/8, 0 + H/4+H/8, H/2+H/8 + H/2+H/4+H/8
// �ϴ� ������ �� �����س��� ó�� ������ ������ŭ Ȯ��
// �������� �ϳĸ�, worker-1==���������� ����� �ε���


// ��ü ����(�ε���)������ �����ִ� �Լ�
void mergesort() {
	int now = worker;
	order.push_back(0);
	order.push_back(worker / 2);
	idxCalc.push_back(0);
	idxCalc.push_back(worker / 2);

	int config = 0;
	while (worker - 1 == config) {
		sort(idxCalc.begin(), idxCalc.end());
		int num = idxCalc.size();
		for (int i = 0; i < num; i++) {
			int nowidx = idxCalc[i];
			config = nowidx + now / 2;
			order.push_back(config);
			idxCalc.push_back(config);
		}	
	}
}

// ���� ó�� ���� �ϼ��� ���� ó���������
int owner() {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	init();
	mergesort();
	int ans = owner();
	cout << ans;

	return 0;
}