#include <iostream>
#include <cstring>
using namespace std;

int N, M, R;
int map[101][101] = { 0, };
int nextmap[101][101] = { 0, };
int flag = 0;

void init() {
    cin >> N >> M >> R;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }
}

int work(int num, int flag) {

    memset(nextmap, 0, sizeof(nextmap));
    int da = 4;

    if (num == 1) {
        if (flag % 2 == 0) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    nextmap[(N + 1) - i][j] = map[i][j];
                }
            }
        }
        else {
            for (int i = 1; i <= M; i++) {
                for (int j = 1; j <= N; j++) {
                    nextmap[(M + 1) - i][j] = map[i][j];
                }
            }
        }
        
    }
    else if (num == 2) {
        if (flag % 2 == 0) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    nextmap[i][(M + 1) - j] = map[i][j];
                }
            }
        }
        else {
            for (int i = 1; i <= M; i++) {
                for (int j = 1; j <= N; j++) {
                    nextmap[i][(N + 1) - j] = map[i][j];
                }
            }
        }
    }
    else if (num == 3) {
        if (flag % 2 == 0) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    nextmap[j][(N + 1) - i] = map[i][j];
                }
            }
        }
        else {
            for (int i = 1; i <= M; i++) {
                for (int j = 1; j <= N; j++) {
                    nextmap[j][(M + 1) - i] = map[i][j];
                }
            }
        }
        flag++;
    }
    else if (num == 4) {
        if (flag % 2 == 0) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    nextmap[(M + 1) - j][i] = map[i][j];
                }
            }
        }
        else {
            for (int i = 1; i <= M; i++) {
                for (int j = 1; j <= N; j++) {
                    nextmap[(N + 1) - j][i] = map[i][j];
                }
            }
        }
        flag++;
    }
    else if (num == 5) {
        if (flag % 2 == 0) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    if (i <= (N / 2) && j <= (M / 2)) nextmap[i][j + (M / 2)] = map[i][j];
                    else if (i <= (N / 2) && j > (M / 2)) nextmap[i + (N / 2)][j] = map[i][j];
                    else if (i > (N / 2) && j <= (M / 2)) nextmap[i - (N / 2)][j] = map[i][j];
                    else if (i > (N / 2) && j > (M / 2)) nextmap[i][j - (M / 2)] = map[i][j];
                }
            }
        }
        else {
            for (int i = 1; i <= M; i++) {
                for (int j = 1; j <= N; j++) {
                    if (i <= (M / 2) && j <= (N / 2)) nextmap[i][j + (N / 2)] = map[i][j];
                    else if (i <= (M / 2) && j > (N / 2)) nextmap[i + (M / 2)][j] = map[i][j];
                    else if (i > (M / 2) && j <= (N / 2)) nextmap[i - (M / 2)][j] = map[i][j];
                    else if (i > (M / 2) && j > (N / 2)) nextmap[i][j - (N / 2)] = map[i][j];
                }
            }
        }
        
    }
    else if (num == 6) {
        if (flag % 2 == 0) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    if (i <= (N / 2) && j <= (M / 2)) nextmap[i + (N / 2)][j] = map[i][j];
                    else if (i <= (N / 2) && j > (M / 2)) nextmap[i][j - (M / 2)] = map[i][j];
                    else if (i > (N / 2) && j <= (M / 2)) nextmap[i][j + (M / 2)] = map[i][j];
                    else if (i > (N / 2) && j > (M / 2)) nextmap[i - (N / 2)][j] = map[i][j];
                }
            }
        }
        else {
            for (int i = 1; i <= M; i++) {
                for (int j = 1; j <= N; j++) {
                    if (i <= (M / 2) && j <= (N / 2)) nextmap[i + (M / 2)][j] = map[i][j];
                    else if (i <= (M / 2) && j > (N / 2)) nextmap[i][j - (N / 2)] = map[i][j];
                    else if (i > (M / 2) && j <= (N / 2)) nextmap[i][j + (N / 2)] = map[i][j];
                    else if (i > (M / 2) && j > (N / 2)) nextmap[i - (M / 2)][j] = map[i][j];
                }
            }
        }
        
    }
    memset(map, 0, sizeof(map));
    if (flag % 2 == 0) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                map[i][j] = nextmap[i][j];
            }
        }
    }
    else {
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                map[i][j] = nextmap[i][j];
            }
        }
    }
    return flag;
}

void printing(int flag) {

    if (flag % 2 == 0) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cout << map[i][j] << " ";
            }
            cout << '\n';
        }
    }
    else {
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                cout << map[i][j] << " ";
            }
            cout << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    for (int i = 0; i < R; i++) {
        int num;
        cin >> num;
        flag = work(num, flag);
    }
    printing(flag);

    return 0;
}