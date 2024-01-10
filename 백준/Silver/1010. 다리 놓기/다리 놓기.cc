#include <iostream>
using namespace std;

int T;
int N, M;
int cnt = 0;


long long Combination(int n, int r) {
    long long first = max(n - r, r);
    long long second = min(n - r, r);
    long long value = 1;
    for (long long i = n; i > first; i--) value *= i;
    for (long long i = second; i > 1; i--) value /= i;
    return value;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        cout << Combination(M, N) << '\n';
    }
    return 0;
}