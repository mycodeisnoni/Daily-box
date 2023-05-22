#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;



struct Node {
    int row, col;
};

struct Edge {
    int from, to, cost;
};

bool cmp(Edge a, Edge b) {
    if (a.cost < b.cost) return true;
    return false;
}

int map[51][51] = { 0, };
int parents[300];

vector <Node> info;
vector <Edge> edge;
queue<Node>q;

int Find(int now) {
    if (parents[now] == now) return now;
    return parents[now] = Find(parents[now]);
}

void Union(int a, int b) {
    int pA = Find(a);
    int pB = Find(b);
    parents[pB] = pA;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int width, height;
        cin >> width >> height;
        int NodeCnt = 0;

        for (int i = 0; i < height; i++) {
            string x;
            cin >> x;
            for (int j = 0; j < width; j++) {
                if (x[j] == '#') map[i][j] = -1; //º®
                if (x[j] == 'A' || x[j] == 'S') //Åë½Å¸Á
                {
                    NodeCnt++;
                    parents[NodeCnt] = NodeCnt;
                    info.push_back({ i,j });
                }
            }
        }

        for (int i = 0; i < info.size(); i++) {
            int used[51][51] = { 0, };
            q.push({ info[i].row,info[i].col});

            while (!q.empty()) {

                Node now = q.front();
                q.pop();
                int pr = now.row;
                int pc = now.col;

                int dr[4] = { -1,1,0,0 };
                int dc[4] = { 0,0,-1,1 };

                for (int d = 0; d < 4; d++) {
                    int nr = pr + dr[d];
                    int nc = pc + dc[d];

                    if (nr<0 || nc<0 || nr>height-2 || nc>width-2) continue;
                    if (map[nr][nc] == -1) continue;
                    if (used[nr][nc]) continue;
                    used[nr][nc] = used[pr][pc] + 1;
                    q.push({ nr,nc });
                }
            }

            for (int j = i + 1; j < info.size(); j++) {
                edge.push_back({ i, j, used[info[j].row][info[j].col] });
            }
        }
        int de = -1;
        sort(edge.begin(), edge.end(), cmp);
        

        int sum = 0;
        for (int i = 0; i < edge.size(); i++) {
            if (Find(edge[i].to) == Find(edge[i].from)) continue;
            Union(edge[i].from, edge[i].to);
            sum += edge[i].cost;
        }
        cout << sum << endl;
        info.clear();
        edge.clear();
        for (int i = 0; i < NodeCnt; i++) {
            parents[i] = 0;
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                map[i][j] = 0;
            }
        }
    }

    return 0;
}
