// 1061 �˰���

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int map[101][101] = { 0, };
int visited[101][101] = { 0, };     // �湮�ߴٸ� �ű���� �հ� �� ���� ���� ���
int visi[101][101] = { 0, };        // �湮 ���� ��� . �湮�ߴµ� ���� �� ���� �ȶվ��� ���� �����ϱ�
struct node {   // ��ġ, �μ� ���� ����
    int row, col, power;
};
queue<node>qNow;
queue<node>qNext;
int dr[4] = { 0,0,-1,1 };
int dc[4] = { 1,-1,0,0 };

void init() {
    cin >> M >> N;
    for (int i = 1; i <= N; i++) {
        string x;
        cin >> x;

        for (int j = 1; j <= M; j++) {
            map[i][j] = x[j - 1] - '0';
        }
    }
}

void bfs() {

    while (!qNow.empty()) {

        while (!qNow.empty()) {
            int row = qNow.front().row;
            int col = qNow.front().col;
            int power = qNow.front().power;
            qNow.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr<1 || nc <1 || nr>N || nc>M) continue;

                if (map[nr][nc] == 1) {      // ���� ���� ��
                    if (visi[nr][nc] != 0) {        // �湮�� ���� �ִٸ�
                        if (power + 1 >= visited[nr][nc]) continue;
                    }
                    visited[nr][nc] = power + 1;
                    visi[nr][nc] = 1;
                    qNext.push({ nr,nc,power + 1 });
                }
                else {      // ���� ���� ��
                    if (visi[nr][nc] != 0) {        // �湮�� ���� �ִٸ�
                        if (power >= visited[nr][nc]) continue;
                    }
                    visited[nr][nc] = power;
                    visi[nr][nc] = 1;
                    qNext.push({ nr,nc,power });
                }
            }
        }

        while (!qNext.empty()) {
            qNow.push(qNext.front());
            qNext.pop();
        }
    }

}







int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    qNow.push({ 1,1,0 });
    visi[1][1] = 1;
    bfs();
    cout << visited[N][M];

    return 0;
}