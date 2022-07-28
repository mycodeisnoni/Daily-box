#include <iostream>
using namespace std;

char x, y;

char getChar() {
    cin >> x >> y;
    if (x >= y) {
        return x;
    }
    else {
        return y;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    char ret = getChar();
    cout << ret;

    return 0;
}