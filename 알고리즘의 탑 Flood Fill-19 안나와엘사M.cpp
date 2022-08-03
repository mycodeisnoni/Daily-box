#include <iostream>
#include <queue>
#include<cstring>
using namespace std;

#define C cin
#define F(i, st, en) for (int (i) = (st); (i) < (en); (i)++)

struct Node {
    int row;
    int col;
};

int map[6][6] = { 0, };
int usedE[6][6] = { 0, };
int usedA[6][6] = { 0, };
int used[6][6] = { 0, };



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int N;
    C >> N;
    
    string x[6];
    for (int i = 0; i < N; i++) {
        cin >> x[i];
        for (int j = 0; j < N; j++) {
            if(x[i][j]=='#') map[i][j] = 1;
        }
    }

    int row1, col1, row2, col2;
    cin >> row1 >> col1 >> row2 >> col2;

    queue<Node>anna;
    queue<Node>elsa;

    anna.push({ row1,col1 });
    elsa.push({ row2,col2 });

    usedA[row1][col1] = 1;
    usedE[row2][col2] = 1;

    while (!anna.empty()) {
        Node now = anna.front();
        anna.pop();


        for (int i = 0; i < 4; i++) {
            int dr[] = { -1,1,0,0 };
            int dc[] = { 0,0,-1,1 };

            int nr = now.row + dr[i];
            int nc = now.col + dc[i];

            if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
            if (map[nr][nc] == 1) continue;
            if (!(usedA[nr][nc]==0)) continue;

            usedA[nr][nc] = usedA[now.row][now.col] + 1;
            anna.push({ nr,nc });
        }
   }

    while (!elsa.empty()) {
        Node now = elsa.front();
        elsa.pop();

        for (int i = 0; i < 4; i++) {
            int dr[] = { -1,1,0,0 };
            int dc[] = { 0,0,-1,1 };

            int nr = now.row + dr[i];
            int nc = now.col + dc[i];

            if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
            if (map[nr][nc] == 1) continue;
            if (!(usedE[nr][nc]==0)) continue;

            usedE[nr][nc] = usedE[now.row][now.col] + 1;
            elsa.push({ nr,nc });
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (usedA[i][j] >= usedE[i][j]) used[i][j] = usedA[i][j];
            else used[i][j] = usedE[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (used[i][j] == 0) used[i][j] = 10000;
        }
    }

    int minTime = 10000;
    F(i, 0, N) {
        for (int j = 0; j < N; j++) {
            if (used[i][j] < minTime) minTime = used[i][j];
        }
    }

    cout << minTime-1;

    return 0;
}
