#include <iostream>
using namespace std;

int cnt = 0;

void BBQ(int num) {

    if (cnt == 4) {
        return;
    }
    cnt++;
    BBQ(num + 2);
    cout << num << " ";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int a;
    cin >> a;

    BBQ(a);

    return 0;
}