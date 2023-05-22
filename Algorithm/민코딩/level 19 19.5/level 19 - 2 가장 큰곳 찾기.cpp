#include <iostream>
using namespace std;

struct Node {
	int row;
	int col;
};
    int MAP[5][5] = {
    {3, 3, 5, 3, 1},
    {2, 2, 4, 2, 6},
    {4, 9, 2, 3, 4},
    {1, 1, 1, 1, 1},
    {3, 3, 5, 9, 2}
    };

int sum(int y, int x) {
    int sum = 0;
    int dr[4] = { -1,-1,1,1 };
    int dc[4] = { -1,1,-1,1 };
    for (int i = 0; i < 4; i++) {
        y = y + dr[i];
        x = x + dc[i];
        if (y < 0 || y>5 || x < 0 || x>5) continue;
        sum += MAP[y][x];
    }
    return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();


    int maxsum = 0;
    int maxrow = -1;
    int maxcol = -1;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int nowsum = sum(i, j);
            if (nowsum > maxsum) {
                maxsum = nowsum;
                maxrow = i;
                maxcol = j;
            }
        }
    }

    cout << maxrow << " " << maxcol;
	return 0;
}