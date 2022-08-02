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
    } // 1. �׷��� ����

    int used[11] = { 0, };
    int coin[11] = { 0, };
    // index : node��ȣ, value : �ش� node���� �� coin�� �ʿ��Ѱ�?

    // 2. queue����
    queue<int> q;

    // 3. ������ ����
    used[0] = 1;
    q.push(0);

    // 4~6�ܰ� �ݺ�
    while (!q.empty()) {
        // 4. now������
        int now = q.front();
        q.pop();
        // 5. now->nextã��
        for (int next = 1; next < cntNode; next++)
        {
            if (arr[now][next] == 0) continue;
            if (used[next] != 0) continue; // ã�Ҵ� ����� �����Ѵٸ� ����
            // 6. next�� queue�� �߰�
            // now -> next�� ������
            coin[next] = coin[now] + arr[now][next];
            // now���� �� ��뿡 �߰������� now->next�� ���� ���� �ش��ϴ� �����
            // next���� �� ����̴�.
            used[next] = 1;
            q.push(next);
        }
    }
    int de = 1;
    for (int i = 1; i < cntNode; i++)
    {
        // i �� node�� cntCoint���� �� ���� coin�� �ʿ��� ��� : ����
        if (cntCoin < coin[i]) continue;
        if (used[i] == 0) continue; // 0���������� �� �� ���� ��� : ����
        cout << i << " ";
    }
    return 0;
}