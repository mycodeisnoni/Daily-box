#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
9
1 2
1 7
2 3
3 4
3 8
4 5
4 6
8 9
*/
/*
1. 그래프 구성
  - 각 node간의 관계
2. Queue 생성
3. 시작노드 세팅
---------------준비완료

4. queue에서 node(now)를 하나 꺼냄
    ㄴ 감염 시켜나갈 예정인 node
5. now에서 갈 수 있는 node(next)들 찾기
6. next들을 queue에 추가

7. 4~6단계 반복
  (더 이상 감염이 안될때까지
   == queue가 비워질때까지)
*/
int main()
{
    int cntNode;
    cin >> cntNode;
    int arr[10][10] = { 0, }; // 인접 행렬
    for (int i = 0; i < cntNode - 1; i++)
    {
        int from, to;
        cin >> from >> to;
        arr[from][to] = 1;
    } // 1. 그래프 구성

    //// 2. Queue 생성
    queue<int> q; // queue에 넣는 정보 : node정보

    //// 3. 시작노드 세팅
    q.push(0); // 1번점이 시작점이므로 넣어줌

    ////7. 4~6단계 반복
    while(!q.empty()) // queue가 비워지지 않았다 : 감염 시켜나갈 예정인 node가 남았다.
    //{
    //    //4. queue에서 node(now)를 하나 꺼냄
        int now = q.front(); // now : 이번에 감염을 시켜나갈 node
        q.pop();

    //    // -------- 이번에 now를 들렸다.
        cout << now << " ";
    //    // --------

    //    // 5. now에서 갈 수 있는 node(next)들 찾기
        for (int next = 1; next <= 9; next++)
    //    {
            if (arr[now][next] == 0) continue; // now->next로 가지 못하면 무시

    //        // now가 next를 감염시킬 수 있다.
    //        // -------- 새로운 next라는 점을 찾았다.

    //        // 6. next들을 queue에 추가
            q.push(next);
    //    }
    //}

    //int cntNode;
    //cin >> cntNode;
    //vector<int> v[10];

    //for (int i = 0; i < cntNode - 1; i++)
    //{
    //    int from, to;
    //    cin >> from >> to;
    //    v[from].push_back(to);
    //} // 1. 그래프 구성

    //// 2. queue 생성
    //queue<int> q;

    //// 3. 시작점 세팅
    //q.push(1);

    //// 7. queue가 비워질때까지 진행
    //while (!q.empty()) {
    //    // 4. quue의 맨 앞의 now꺼내기
    //    int now = q.front();
    //    q.pop();

    //    cout << now;

    //    // 5. now에서 갈 수 있는 next찾기
    //    for (int i = 0; i < v[now].size(); i++)
    //    {
    //        int next = v[now][i];

    //        // 6. next를 queue에 추가
    //        q.push(next);
    //    }
    //}
    return 0;
}