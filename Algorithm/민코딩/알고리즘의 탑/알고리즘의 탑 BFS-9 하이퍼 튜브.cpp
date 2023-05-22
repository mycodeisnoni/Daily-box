#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// 하이퍼튜브 도! 노드로 잡자~~

vector <int> v[101001];
int used[101001] = { 0, };
int level[101001] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    //N은 역
    //K는 하나의 하이퍼 튜브가 연결하는 역
    //M은 하이퍼 튜브 개수

    int N, K, M;
    cin >> N >> K >> M;


    //각 하이퍼튜브에 대한 연결 정보 입력받기
    for (int i = 100001; i <= M+100000; i++) {
        for (int j = 0; j < K; j++) {
        int a;
        cin >> a;
        v[i].push_back(a);
        v[a].push_back(i);
        }
    }

    queue<int>q;

    used[1] = 1;
    q.push(1);

    while (!q.empty()) {

        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            if (used[next] != 0) continue;
            used[next] = 1;
             level[next] = level[now] + 1; 
             if (next == N) break;
            q.push(next);
        }
    }

    if (level[N] == 0) cout << "-1";
    else cout << (level[N] + 1)/2+1;

    return 0;
}