#include <iostream>
#include <queue>
#include<cstring>
using namespace std;

struct Node {
    int row;
    int col;
};

int used[8][9] = { 0, };
int map[8][9] = { 0, };
int emp[8][9] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    string x[10];

    for (int i = 0; i < 8; i++) {
            cin >> x[i];
        for (int j = 0; j < 9; j++) {
            if (x[i][j] == '#') map[i][j] = 1;
        }
    }


    queue<Node>q;
    q.push({ 0,8 });
    used[0][8] = 1;


    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        int dr[] = { -1,1,0,0 };
        int dc[] = { 0,0,-1,1 };


        for (int i = 0; i < 4; i++) {
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];

            if (nc < 0 || nr < 0 || nc >= 9 || nr >= 8) continue;
            if (used[nr][nc] != 0) continue;
            if (map[nr][nc] == 0) {

                used[nr][nc] = used[now.row][now.col] + 1;
                continue;
            }

            else { used[nr][nc] = 1;
            q.push({ nr,nc });
            }
        }

    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 9; j++) {
            if (used[i][j]==2) emp[i][j] = 1;
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 9; j++) {
            if (emp[i][j] == 1) {
                Node empFirst = { i,j };
                q.push(empFirst);
            };
        }
    }

    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        int dr[] = { -1,1,0,0 };
        int dc[] = { 0,0,-1,1 };


        for (int i = 0; i < 4; i++) {
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];

            if (nc < 0 || nr < 0 || nc >= 9 || nr >= 8) continue;
            if (emp[nr][nc] != 0) continue;
            if (used[nr][nc] != 0) continue;
            
            emp[nr][nc] = emp[now.row][now.col] + 1;
            q.push({ nr,nc });
            if (map[nr][nc] != 0) {
                cout << emp[now.row][now.col];
                return 0;
            }
        }
    }





    /*for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 9; j++) {
            cout << used[i][j] << " ";
        }cout << '\n';
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 9; j++) {
            cout << map[i][j] << " ";
        }cout << '\n';
    }

    */
    /*for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 9; j++) {
            cout << emp[i][j] << " ";
        }cout << '\n';
    }*/

    return 0;
}
