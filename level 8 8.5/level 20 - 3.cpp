#include <iostream>
using namespace std;

int arr[6] = { 0, };

void BBQ(int num) {
    cout << arr[num] << " ";

    if (num == 5) {
        return;
    }
    BBQ(num + 1);
    cout << arr[num] << " ";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
    }

    BBQ(0);

    return 0;
}