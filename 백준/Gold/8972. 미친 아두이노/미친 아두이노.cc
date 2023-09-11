#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R, C;
char map[101][101] = { 0, };
string x;
int dr[10] = { 0,1,1,1,0,0,0,-1,-1,-1, };
int dc[10] = { 0,-1,0,1,-1,0,1,-1,0,1, };
int row, col;
struct Node {
    int row, col;
};
int visitednow[101][101] = { 0, };
queue<Node>arduino1;
queue<Node>arduino2;

void init() {
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'I') row = i, col = j;
            if (map[i][j] == 'R') arduino1.push({ i,j });
        }
    }
    cin >> x;
}

int move_arduino() {       // 아두이노가 종수에게 가까워지기

    memset(visitednow, 0, sizeof(visitednow));

    while (!arduino1.empty()) {
        Node now_arduino = arduino1.front();
        arduino1.pop();
        int ar = now_arduino.row;
        int ac = now_arduino.col;

        int dist = 2e9;
        int idx = 0;
        for (int i = 1; i <= 9; i++) {
            int next_ar = ar + dr[i];
            int next_ac = ac + dc[i];
            if (next_ar < 1 || next_ac <1 || next_ar > R || next_ac > C) continue;
            int now = abs(next_ar - row) + abs(next_ac - col);
            if (now < dist) {
                dist = now;
                idx = i;
            }
        }
        ar += dr[idx];
        ac += dc[idx];
        if (ar == row && ac == col) return -1;
        arduino2.push({ ar, ac });
        visitednow[ar][ac]++;
    }

    while (!arduino2.empty()) {
        Node now = arduino2.front();
        if (visitednow[now.row][now.col] == 1) arduino1.push(now);    
        arduino2.pop();
    }
    return 1;
}

void robots() {
    for (int i = 0; i < x.size(); i++) {
        int num = x[i] - '0';
        row += dr[num];
        col += dc[num];
        if (move_arduino() == -1) {
            cout << "kraj " << i + 1;
            return;
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            map[i][j] = '.';
        }
    }
    map[row][col] = 'I';
    while (!arduino1.empty()) {
        Node now = arduino1.front();
        arduino1.pop();
        map[now.row][now.col] = 'R';
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    robots();
    
    return 0;
}