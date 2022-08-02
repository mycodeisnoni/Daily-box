#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int cntNode;
    cin >> cntNode;
    int arr[10][10] = { 0, };
    for (int i = 0; i < cntNode; i++) {
        for (int j = 0; j < cntNode; j++) {
            cin >> arr[i][j];
        }
    }
    queue<int> q;
    q.push(0);
    int used[10] = { 0, };
    used[0] = 1;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        cout << now << " ";
        for (int next = 1; next < cntNode; next++)
        {
            if (arr[now][next] == 0) continue;
            if (used[next] == 1) continue;
            q.push(next);
            used[next] = 1;
        }
    }
      return 0;
}