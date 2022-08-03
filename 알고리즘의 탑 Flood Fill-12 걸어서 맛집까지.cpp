#include <iostream>
#include <queue>
#include<cstring>
using namespace std;

struct Node {
    int row;
    int col;
};

int map[201][201]= { 0, };
int market[10] = { 0, };


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int N, M;
    cin >> N >> M;

    queue<int>a;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] != 0 && market[map[i][j]]==0 ) {
                a.push(map[i][j]);
                market[map[i][j]] = 1;
            }
        }
    }
   
    queue<Node>q;





   

   
    return 0;
}
