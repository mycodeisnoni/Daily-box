#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int A, B, N, M;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
char d[4] = { 'E', 'N', 'W', 'S' };
int map[101][101] = { 0, };	// 현재 로봇들의 위치 기록
int flag = 0;

struct robot {
	int x, y, de;
};
struct robotOrder {
	int X, Y;
	char nowOrder;
};
robot firstarray[101] = { 0, };		// i번째 로봇의 초기 위치, 방향 기록
vector <robotOrder> orderarray;		// 명령들 기록

void init() {
	cin >> A >> B;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int  x, y = 0;
		char dx = 0;
		cin >> x >> y >> dx;

		int de = -2;
		for (int j = 0; j < 4; j++) {
			if (dx == d[j]) {
				de = j;
				continue;
			}
		}
		firstarray[i] = { x,y,de };
		map[y][x] = i;	// 현재 그 위치에 있는 로봇의 번호 맵에 기록
	}
	for (int i = 0; i < M; i++) {
		int X, Y = 0;
		char nowOrder = 0;
		cin >> X >> nowOrder >> Y;
		orderarray.push_back({ X, Y, nowOrder });
	}
}

void L(int nowrobotIdx, int repeat) {
	int realrepeat = repeat % 4;
	int nowde = firstarray[nowrobotIdx].de;
	int nextde = (nowde + realrepeat) % 4;
	firstarray[nowrobotIdx].de = nextde;
}

void R(int nowrobotIdx, int repeat) {
	int realrepeat = repeat % 4;
	int nowde = firstarray[nowrobotIdx].de;
	int nextde = nowde - realrepeat;
	if (nextde < 0) nextde += 4;
	firstarray[nowrobotIdx].de = nextde;
}

void F(int nowrobotIdx, int repeat) {
	int nowRow = firstarray[nowrobotIdx].y;
	int nowCol = firstarray[nowrobotIdx].x;
	int nowDe = firstarray[nowrobotIdx].de;

	int nr = nowRow;
	int nc = nowCol;

	for (int i = 0; i < repeat; i++) {
		int nextRow = nr + dr[nowDe];
		int nextCol = nc + dc[nowDe];
		if (map[nextRow][nextCol]) {	// 이미 해당 위치에 로봇이 있는 경우
			cout << "Robot " << nowrobotIdx << " crashes into robot " << map[nextRow][nextCol];
			flag = 1;
			return;
		}
		if (nextRow <= 0 || nextRow > B || nextCol <= 0 || nextCol > A) {	// map 벗어남	
			cout << "Robot " << nowrobotIdx << " crashes into the wall";
			flag = 1;
			return;
		}
		else {
			map[nr][nc] = 0;
			nr += dr[nowDe];
			nc += dc[nowDe];
			firstarray[nowrobotIdx].y = nr;
			firstarray[nowrobotIdx].x = nc;
			map[nr][nc] = nowrobotIdx;
		}
	}
}

void calc() {
	for (int i = 0; i < M; i++) {
		int nowrobotIdx = orderarray[i].X;
		char nowOrder = orderarray[i].nowOrder;
		int repeat = orderarray[i].Y;

		if (nowOrder == 'L') L(nowrobotIdx, repeat);
		else if (nowOrder == 'R') R(nowrobotIdx, repeat);
		else if (nowOrder == 'F') F(nowrobotIdx, repeat);

		if (flag == 1) return;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	calc();

	if (flag == 0) cout << "OK";

	return 0;
}