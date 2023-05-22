#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int row;
    int col;
};

int used[100][100] = { 0, };
int main()
{
    
    int H, W;
    cin >> H >> W;

    queue<Node>q;
    queue<Node>zzol;

    int row, col;
    cin >> row >> col;
    used[row][col] = 0;
    q.push({ row,col });

    int ansTime = 0;

    int Y, X;
    cin >> Y >> X;
    Node tar = { Y,X };

    int n,a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        zzol.push({ a,b });
        used[a][b] = -1;

    }

    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        if (now.row == tar.row && now.col == tar.col)
        {
            cout << used[now.row][now.col];
            return 0;
       }
       

        int dr[] = { 3,2,-2,-3,-3,-2,2,3};
        int dc[] = { 2,3,3,2,-2,-3,-3,-2 };

        for (int i = 0; i < 8; i++) {
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];

            if (nr < 0 || nc < 0 || nc >= W || nr >= H)
                continue;
            if (used[nr][nc] != 0) continue;
                

            /*for (int j = 0; j < n; j++)
            {
                if (zzol.empty()) continue;
                Node z = zzol.front();
                zzol.pop();
                if (now.row == z.row && now.col == z.col)
                    continue;
            }*/
            //int de = -1;
            used[nr][nc] = used[now.row][now.col] + 1;
            q.push({ nr, nc });
        }
    }

    if (used[tar.row][tar.col] == 0) cout << "-1";
    return 0;
}