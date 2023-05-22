#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int N;
int cnt;
int visited;  // ������� �� ���ڵ��� bit�� ǥ���� ��, �迭��� bit���
int total = (1 << 10) - 1; // ��� ���ڰ� �������� ��, visited

void init() {
	cin >> N;
}

bool calc(int cnt){

	// ���ڷ� �θ� ������ ������, �������� ����ؾ��ϴ�, ���ڿ��� ��ȯ
	string x = to_string(N * cnt);
	for (int i = 0; i < x.length(); i++) {
		int num = x[i] - '0';
		visited = visited | (1 << num);
	}
	if (visited == total) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		init();
		cnt = 1;
		visited = 0;
		bool cmd = false;
		while (!cmd) {
			if (!calc(cnt)) cnt++;
			else cmd = true;
		}

		cout << "#" << tc << " " << cnt*N << "\n";
	}

	return 0;
}