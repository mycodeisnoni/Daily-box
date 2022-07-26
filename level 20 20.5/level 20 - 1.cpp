#include <iostream>
using namespace std;

void BBQ(int num) {
    if (num <= 0) {
        return;
    }
    BBQ(num - 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    BBQ(5);

    return 0;
}