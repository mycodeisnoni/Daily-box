#include <iostream>
using namespace std;

int N;

void init(){
    cin >> N;
}

int func() {
    int num = 1;
    while (num * 2 <= N) num *= 2;
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int ans = func();
    cout << ans;

    return 0;
}