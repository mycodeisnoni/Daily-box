#include <iostream>
using namespace std;

int N;
long long arr[100001];
long long A, B;
struct Node {
    long long a, b;
};

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

Node tp() {
    int left = 0;
    int right = N - 1;
    int target = abs(arr[left] + arr[right]);
    A = arr[left];
    B = arr[right];

    while (left < right) {
        int now = arr[left] + arr[right];
        if (abs(now) < target) {
            target = abs(now);
            A = arr[left];
            B = arr[right];
        }
        if (now < 0) left++;
        else right--;
    }
    return { A, B };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    Node ans = tp();
    cout << ans.a << " " << ans.b << "\n";
}