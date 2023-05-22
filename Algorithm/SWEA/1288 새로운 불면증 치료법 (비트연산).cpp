#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int N;
int cnt;
int visited;  // 현재까지 본 숫자들을 bit로 표현한 수, 배열대신 bit사용
int total = (1 << 10) - 1; // 모든 숫자가 등장했을 때, visited

void init() {
	cin >> N;
}

bool calc(int cnt){

	// 숫자로 두면 일일이 나누고, 나머지를 기록해야하니, 문자열로 전환
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