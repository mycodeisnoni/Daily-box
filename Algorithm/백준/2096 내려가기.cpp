#include <iostream>
#include <algorithm>
using namespace std;

int N;
int nowRow[3] = { 0, };         // 입력받는 한 줄씩 기록
int maxRow[3] = { 0, };
int minRow[3] = { 0, };


void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {

        for (int j = 0; j < 3; j++) cin >> nowRow[j];       // 한줄입력

        if (i == 0) {
            for (int j = 0; j < 3; j++) {
                maxRow[j] = nowRow[j];
                minRow[j] = nowRow[j];
            }
        }
        else {

            int a = nowRow[0] + max(maxRow[0], maxRow[1]);
            int b = nowRow[1] + max(max(maxRow[0], maxRow[1]), maxRow[2]);
            int c = nowRow[2] + max(maxRow[1], maxRow[2]);

            int d = nowRow[0] + min(minRow[0], minRow[1]);
            int e = nowRow[1] + min(min(minRow[0], minRow[1]), minRow[2]);
            int f = nowRow[2] + min(minRow[1], minRow[2]);

            maxRow[0] = a;
            maxRow[1] = b;
            maxRow[2] = c;
            minRow[0] = d;
            minRow[1] = e;
            minRow[2] = f;
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();


    int maximum = max(max(maxRow[0], maxRow[1]), maxRow[2]);
    int minimum = min(min(minRow[0], minRow[1]), minRow[2]);

    cout << maximum << " " << minimum;

    return 0;
}