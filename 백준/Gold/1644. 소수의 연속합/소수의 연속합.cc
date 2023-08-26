#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int>prime;

void init() {
    cin >> N;
}

void find() {
    vector<bool>is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (long long i = 2; i <= N; i++) {
        if (is_prime[i]) {
            for (long long j = i * i; j <= N; j += i) is_prime[j] = false;
            prime.push_back(i);
        }
    }
}

int tp() {
    int left = 0;
    int right = -1;
    int cnt = 0;
    int num = 0;

    while (left < prime.size()) {

        if (num == N) {
            cnt++;
            right++;
            if (right == prime.size()) return cnt;
            num += prime[right];
        }
        else if (num < N) {
            right++;
            if (right == prime.size()) return cnt;
            num += prime[right];
        }
        else if (num > N) {
            num -= prime[left];
            left++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    find();
    int ans = tp();
    cout << ans;

    return 0;
}
