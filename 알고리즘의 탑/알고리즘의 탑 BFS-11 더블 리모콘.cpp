#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//vector <int> v[100001];
int used[200001] = { 0, };


int level[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int N, M;
    cin >> N >> M;

    

    queue<int>q;
    q.push(N);
    used[N] = 1;
    if (N == M)
    {
        cout << 0;
        return 0;
    }
    while (!q.empty()) {

    int now = q.front();
    q.pop();

    int arr[4]={now/2, now+1, now-1, now*2 };
    if (N == M) {
        cout << "0";
        return 0;
    }
        for (int i = 0; i < 4; i++) {
            int next = arr[i];
            if (next<0 || next>200000) continue;
            if (used[next] == 1) continue;
            used[next] = 1;
            level[next] = level[now] + 1;
            if (next == M)
            {
                
                cout << level[M];
                return 0;

            }
            q.push(next);
        }
    }
    return 0;
}