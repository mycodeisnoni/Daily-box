#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int map[101][101] = { 0, };


void init() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }
}

int row_func() {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        int len1 = 1, flag = 0, len2 = 0;
        for (int j = 1; j < N; j++) {
            if (map[i][j] - map[i][j + 1] == 0) {
                if (len2 > 0) {
                    len2++;
                    if (len2 >= M) len2 = 0, len1 = 0;
                }
                else len1++;
            }
            else if (map[i][j] - map[i][j + 1] == -1) {      // 한 칸 높아짐
                if (len2 > 0) {
                    flag = 1;
                    break;
                }
                if (len1 >= M) len1 = 1;
                else {
                    flag = 1;
                    break;
                }
            }
            else if (map[i][j] - map[i][j + 1] == 1) {     // 한 칸 낮아짐
                len1 = 0;
                if (len2 > 0) {
                    flag = 1;
                    break;
                }
                len2++;
                if (len2 >= M) len2 = 0, len1 = 0;
            }
            else {      // 두 칸 이상 차이남
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            if (len2 > 0 && len2 < M) continue;
            //cout << "현재 " << i << " 열\n";
            cnt++;
        }
    }
    return cnt;
}

int col_func() {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        int len1 = 1, flag = 0, len2 = 0;

        for (int j = 1; j < N; j++) {
            if (map[j][i] - map[j+1][i] == 0) {
                if (len2 > 0) {
                    len2++;
                    if (len2 >= M) len2 = 0, len1 = 0;
                }
                else len1++;
            }
            else if (map[j][i] - map[j + 1][i] == -1) {      // 한 칸 높아짐
                if (len2 > 0) {
                    flag = 1;
                    break;
                }
                if (len1 >= M) len1 = 1;
                else {
                    flag = 1;
                    break;
                }
            }
            else if (map[j][i] - map[j + 1][i] == 1) {     // 한 칸 낮아짐
                len1 = 0;
                if (len2 > 0) {
                    flag = 1;
                    break;
                }
                len2++;
                if (len2 >= M) len2 = 0, len1 = 0;
            }
            else {      // 두 칸 이상 차이남
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            if (len2 > 0 && len2 < M) continue;
            //cout << "현재 " << i << " 행\n";
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int ans = row_func() + col_func();
    cout << ans;

    return 0;
}
