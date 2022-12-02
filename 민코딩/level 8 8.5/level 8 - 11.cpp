#include <iostream>
using namespace std;



void starBox() {
    for (int i = 1; i <= 20; i += 2) {
        cout << i << " ";
    }
}

void macDoll() {
    for (char x = 'H'; x >= 'A'; x--) {
        cout << char(x) << " ";
    }
}

void copyBean() {
    for (int i = -5; i <= 5; i++) {
        cout << i << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int price;
    cin >> price;

    if (price >= 3500 && price <= 5000) {
        starBox();
    }
    else if (price >= 2500 && price < 3500) {
        macDoll();
    }
    else {
        copyBean();
    }

    return 0;
}