#include <iostream>
#include <queue>
#include<cstring>
using namespace std;

struct Node {
    int row;
    int col;
};

int map[1001][1001] = { 0, };
int bmap[1001][1001] = { 0, };
int mem[100001] = { 0 };




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int height, width;
    cin >> height >> width;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> map[i][j];
        }
    }

    int bheight, bwidth;
    cin >> bheight >> bwidth;
    queue<int>q;

    for (int i = 0; i < bheight; i++) {
        for (int j = 0; j < bwidth; j++) {
            cin >> bmap[i][j];
            //q.push(bmap[i][j]);
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            mem[map[i][j]]++;
        }
    }

    int b = 0;
    int nb = 0;


    for (int i = 0; i < bheight; i++) {
        for (int j = 0; j < bwidth; j++) {
            b += mem[bmap[i][j]];
            mem[bmap[i][j]] = 0;
        }
    }

    nb = height * width - b;
    cout << b << "\n" << nb;


    /*int b = 0;
    int nb =0;


    while (!q.empty()) {
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (map[i][j] == q.front())
            {
                b++;
                map[i][j] = 0;
            }
        }
    }
    q.pop();
    }

    nb = height * width - b;

    cout << b << "\n" << nb;*/
    
    return 0;
}
