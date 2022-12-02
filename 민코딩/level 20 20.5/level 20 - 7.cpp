#include <iostream>
using namespace std;

int a;

int arr[8] = { 3,7,4,1,9,4,6,2 };

void BBQ(int num) {
    cout << arr[num] << " ";
    if (num == 0) {
        return;
    }
    BBQ(num -1);
    cout << arr[num] << " ";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> a;
    BBQ(a);


    return 0;
}