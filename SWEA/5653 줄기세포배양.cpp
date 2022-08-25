#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <queue>

using namespace std;

struct Edge {
    int row, col, state, chlife, life;
};

struct cmp {
    bool operator()(Edge a, Edge b) {
        if (a.life < b.life) return true;
        return false;
    }
};

int arr[700][700] = { 0, };
int used[700][700] = { 0, };
queue <Edge> qNow;
queue <Edge> qNext;
priority_queue<Edge, vector<Edge>, cmp> qStart;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N, M, K;
        cin >> N >> M >> K;


        int cell = 0;
        for (int i = 320; i < N + 320; i++) {
            for (int j = 320; j < M + 320; j++) {
                cin >> arr[i][j];
                int a = arr[i][j];
                if (a)
                {
                    qStart.push({ i,j,-1,a,a });
                    cell++;
                    used[i][j] = 1;
                }
            }
        }

        while (!qStart.empty())
        {
            qNow.push(qStart.top());
            qStart.pop();
        }

        for (int i = 1; i <= K; i++) {

            while (!qNow.empty())
            {
                Edge now = qNow.front();
                qNow.pop();

                int state = now.state;
                int life = now.life;
                int chlife = now.chlife;
                int pr = now.row;
                int pc = now.col;
                used[pr][pc] = 1;
                int dr[4] = { -1,1,0,0 };
                int dc[4] = { 0,0,-1,1 };

                if (state == -1)
                {
                    chlife--;
                    if (chlife == 0) qNext.push({ pr,pc,1,life,life });
                    else qNext.push({ pr,pc,state,chlife,life });
                }


                if (state == 1)
                {
                    chlife--;
                    if (chlife == 0) cell--;
                    else qNext.push({ pr,pc,state,chlife,life });

                    for (int d = 0; d < 4; d++) {
                        int nr = pr + dr[d];
                        int nc = pc + dc[d];
                        if (used[nr][nc]) continue;
                        used[nr][nc] = 1;
                        qNext.push({ nr,nc,-1,life,life });
                        cell++;
                    }
                }
            }

            while (!qNext.empty())
            {
                qNow.push(qNext.front());
                qNext.pop();
            }
        }

        cout << "#" << tc << " " << cell << endl;
        for (int i = 0; i < 700; i++) {
            for (int j = 0; j < 700; j++) {
                arr[i][j] = 0;
                used[i][j] = 0;
            }
        }
        while (!qNow.empty())
        {
            qNow.pop(); // 까먹지마 제발.. 
        }
    }

    return 0;
}