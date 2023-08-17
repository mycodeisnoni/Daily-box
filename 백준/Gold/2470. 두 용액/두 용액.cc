#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<long long>fluid;

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long a;
        cin >> a;
        fluid.push_back(a);
    }
    sort(fluid.begin(), fluid.end());
}

struct Node {
    int left, right;
};


Node tp() {

    Node ans = { 0,N - 1 };
    int left = 0;
    int right = N-1;
    long long min = 1e18;
    
    while (left < right) {
        long long now = fluid[left] + fluid[right];

        if (abs(now) < abs(min)) {
            min = now;
            ans = { left, right };
        }
        if (now < 0) left++;
        if (now > 0) right--;
        if (now == 0) return ans;    
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    Node ans = tp();
    cout << fluid[ans.left] << " " << fluid[ans.right];
    
    return 0;
}