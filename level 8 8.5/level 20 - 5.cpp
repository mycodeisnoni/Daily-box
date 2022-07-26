#include <iostream>
using namespace std;

char arr[5] = { 0, };

void BBQ(int num) {
    cout << arr[num];
    if (num == 4) {
        cout << "\n";
        cout << arr[num];
        return;
    }
    BBQ(num +1);
    cout << arr[num];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    BBQ(0);

    return 0;
}