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
    
    int height, width;
    cin >> height >> width;

    queue<Node>q;

    int row, col;
    cin >> row >> col;
    used[row][col] = 0;
    q.push({ row,col });

    int ansTime = 0;

    int tarRow, tarCol;
    cin >> tarRow >> tarCol;
    Node tar = { tarRow,tarCol };

    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        if (now.row == tar.row && now.col == tar.col)
        {
            cout << used[now.row][now.col];
            return 0;
       }
       

        int dr[] = { 2,1,-1,-2,-2,-1,1,2 };
        int dc[] = { 1,2,2,1,-1,-2,-2,-1 };

        for (int i = 0; i < 8; i++) {
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];

            if (nr < 0 || nc < 0 || nc >= width || nr >= height)
                continue;
            if (used[nr][nc] != 0) continue;
            used[nr][nc] = used[now.row][now.col] + 1;
            q.push({ nr, nc });
        }
    }

    return 0;
}