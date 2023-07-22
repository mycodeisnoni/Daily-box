#include <iostream>
using namespace std;

char st[11];

void BBQ(int num) {

    if (num == 0) {
        return;
    }
    BBQ(num-1);
    for (int i = 0 ; i < num ; i++) {
        for (int j = )
            cout << st[i];
    }
    cout << 'wn';
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> st;
    int i;
    for (i = 0; i < 11; i++) {
        if (st[i] == '\n') {
            break;
        }
    }

    BBQ(i);


    return 0;
}