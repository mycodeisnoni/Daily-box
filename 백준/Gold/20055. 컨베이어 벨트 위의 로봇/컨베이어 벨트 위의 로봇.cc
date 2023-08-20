#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int zerocnt = 0;
struct Node {
    int heart, isrobot;     // 실제번호,현재위치, 내구도
};

vector<Node>belt;

int up = 0;
int down = 0;
int nowzero = 0;

void init() {
    cin >> N >> K;
    down = N - 1;
    for (int i = 1; i <= 2 * N; i++) {
        int cnt;
        cin >> cnt;
        if (cnt == 0) nowzero++;
        belt.push_back({ cnt, 0 });
    }
}

int func1() {

    int level = 0;

    while (1) {

        level++;
        if (nowzero >= K) return level;

        // 1. 벨트 회전
        up--;
        if (up < 0) up = 2 * N - 1;
        down--;
        if (down < 0) down = 2 * N - 1;
        if (belt[down].isrobot == 1) belt[down].isrobot = 0;

        // 2. 로봇 이동
        if (up < down) {
            for (int i = down - 1; i >= up; i--) {
                if (belt[i].isrobot == 1 && belt[i + 1].heart >= 1 && belt[i+1].isrobot == 0) {
                    belt[i].isrobot = 0;
                    belt[i + 1].isrobot = 1;
                    belt[i + 1].heart--;
                    if (i + 1 == down) belt[i + 1].isrobot = 0;
                    if (belt[i + 1].heart == 0) zerocnt++;
                    if (zerocnt == K) return level;
                }
            }
        }
        else {
            for (int i = down - 1; i >= 0; i--) {  // 0 ~ down 이동
                if (belt[i].isrobot == 1 && belt[i + 1].heart >= 1 && belt[i + 1].isrobot == 0) {
                    belt[i].isrobot = 0;
                    belt[i + 1].isrobot = 1;
                    belt[i + 1].heart--;
                    if (i + 1 == down) belt[i + 1].isrobot = 0;
                    if (belt[i + 1].heart == 0) zerocnt++;
                    if (zerocnt == K) return level;
                }
            }
            // 2*N-1 ~ 0 이동
            if (belt[2 * N - 1].isrobot == 1 && belt[0].heart >= 1 && belt[0].isrobot == 0) {
                belt[2 * N - 1].isrobot = 0;
                belt[0].isrobot = 1;
                belt[0].heart--;
                if (0 == down) belt[0].isrobot = 0;
                if (belt[0].heart == 0) zerocnt++;
                if (zerocnt == K) return level;
            }
            for (int i = 2 * N - 2; i >= up; i--) {       // up ~ 2N-1 이동
                if (belt[i].isrobot == 1 && belt[i + 1].heart >= 1 && belt[i + 1].isrobot == 0) {
                    belt[i].isrobot = 0;
                    belt[i + 1].isrobot = 1;
                    belt[i + 1].heart--;
                    if (belt[i + 1].heart == 0) zerocnt++;
                    if (zerocnt == K) return level;
                }
            }
        }

        // 3. 로봇 올리기
        if (belt[up].heart > 0 && belt[up].isrobot == 0) {
            belt[up].heart--;
            belt[up].isrobot = 1;
            if (belt[up].heart == 0) zerocnt++;
            if (zerocnt == K) return level;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int ans = func1();
    cout << ans;

    return 0;
}