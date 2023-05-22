#include <iostream>
using namespace std;

int n;
int arr[4];
int level; // ÀÎµ¦½º 0~3 (ÃÑ4ÀÏ)

void BBQ(int level) {
    if (level >= 4) {
        for (int i = 0; i < 4; i++) {
        cout << arr[i];
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        arr[level] = i;

        BBQ(level + 1);
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n;

    BBQ(0);

    return 0;
}