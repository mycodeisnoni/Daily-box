#include <iostream>
using namespace std;

int arr[2][3] = { 0 };
int sum;

void input() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
}

void process() {
    sum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            sum += arr[i][j];
        }
    }
}

void output() {
    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    input();
    process();
    output();

    return 0;
}