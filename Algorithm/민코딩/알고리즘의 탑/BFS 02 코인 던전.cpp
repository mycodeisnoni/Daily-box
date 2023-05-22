#include <iostream>
#include<queue>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int arr[11][11] = { 0, };

    int cntNode, cntEdge, cntCoin;
    cin >> cntNode >> cntEdge >> cntCoin;
    for (int i = 0; i < cntEdge; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from][to] = cost;
        arr[to][from] = cost;
    } // 1. 그래프 구성

    int used[11] = { 0, };
    int coin[11] = { 0, };
    // index : node번호, value : 해당 node까지 몇 coin이 필요한가?

    // 2. queue생성
    queue<int> q;

    // 3. 시작점 세팅
    used[0] = 1;
    q.push(0);

    // 4~6단계 반복
    while (!q.empty()) {
        // 4. now꺼내기
        int now = q.front();
        q.pop();
        // 5. now->next찾기
        for (int next = 1; next < cntNode; next++)
        {
            if (arr[now][next] == 0) continue;
            if (used[next] != 0) continue; // 찾았던 기록이 존재한다면 무시
            // 6. next를 queue에 추가
            // now -> next로 갔을때
            coin[next] = coin[now] + arr[now][next];
            // now까지 들어간 비용에 추가적으로 now->next로 가는 선에 해당하는 비용이
            // next까지 들어갈 비용이다.
            used[next] = 1;
            q.push(next);
        }
    }
    int de = 1;
    for (int i = 1; i < cntNode; i++)
    {
        // i 번 node가 cntCoint보다 더 많은 coin이 필요한 경우 : 무시
        if (cntCoin < coin[i]) continue;
        if (used[i] == 0) continue; // 0번에서부터 갈 수 없는 경우 : 무시
        cout << i << " ";
    }
    return 0;
}