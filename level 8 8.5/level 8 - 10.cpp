#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int arr[3][4] = { {4,3,1,1},{3,1,2,1},{0,0,1,2} };
    int a, i, j;
    cin >> a;
    int cnt = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            if (arr[i][j] == a) {
                cnt++;
            }
        }
    }
    cout << cnt << "개 존재합니다";

        return 0;
}