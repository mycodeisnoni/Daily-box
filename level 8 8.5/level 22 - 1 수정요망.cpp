#include <iostream>
using namespace std;

char arr[3] = { 'A','B','C' };


void BBQ(int now) {
   
    if (now == 2) {
        cout << '\n';
        return;
    }
    for (int i = 0; i < 3; i++) {
        cout << arr[now] << arr[i];
        BBQ(now + 1);
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    BBQ(0);

    return 0;
}