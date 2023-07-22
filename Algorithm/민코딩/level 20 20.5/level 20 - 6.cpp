#include <iostream>
using namespace std;

int a, b;

void BBQ(int num) {
    cout << num << " ";
    if (num == b) {
        return;
    }
    BBQ(num +1);
    cout << num << " ";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> a >> b;
    BBQ(a);


    return 0;
}