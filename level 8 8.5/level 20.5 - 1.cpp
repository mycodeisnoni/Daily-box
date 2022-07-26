#include <iostream>
using namespace std;

int cnt = 0;

void BBQ(int num) {

    if (cnt == 5) {
        return;
    }
    cnt++;
    BBQ(num-1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    
    BBQ(5);

    return 0;
}