#include <iostream>
using namespace std;

struct Node {
	int row;
	int col;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

    int arr[3][3] = {
    {3, 5, 4},
    {1, 1, 2},
    {1, 3, 9}
    };

    int y, x;
    cin >> y >> x;

    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};
    int sum = 0;

    for (int i = 0; i < 4; i++) {
        int row = y + dr[i];
        int col = x + dc[i];
        if (col < 0 || row < 0 || col>2 || row>2) continue;
        sum += arr[row][col];
    }

    cout << sum;
	return 0;
}