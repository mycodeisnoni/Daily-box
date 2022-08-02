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

    int arr[3]={ now+1, now-1, now*2 };

        for (int i = 0; i < 3; i++) {
            int next = arr[i];
            if (next<0 || next>200000) continue;

            // next > 200000 이 아니고 2*M 이런식으로 주면
            // 목적지가 더 작은 경우 제대로 돌아가지 않아요

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