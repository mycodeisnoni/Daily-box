#include <iostream>
using namespace std;

int a;

void BBQ(int num) {
    if (num == 0) {
        return;
    }
    BBQ(num/2);
    cout << num << " ";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> a;
    BBQ(a);

    return 0;
}