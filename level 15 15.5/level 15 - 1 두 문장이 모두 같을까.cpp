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
1. �׷��� ����
  - �� node���� ����
2. Queue ����
3. ���۳�� ����
---------------�غ�Ϸ�

4. queue���� node(now)�� �ϳ� ����
    �� ���� ���ѳ��� ������ node
5. now���� �� �� �ִ� node(next)�� ã��
6. next���� queue�� �߰�

7. 4~6�ܰ� �ݺ�
  (�� �̻� ������ �ȵɶ�����
   == queue�� �����������)
*/
int main()
{
    int cntNode;
    cin >> cntNode;
    int arr[10][10] = { 0, }; // ���� ���
    for (int i = 0; i < cntNode - 1; i++)
    {
        int from, to;
        cin >> from >> to;
        arr[from][to] = 1;
    } // 1. �׷��� ����

    //// 2. Queue ����
    queue<int> q; // queue�� �ִ� ���� : node����

    //// 3. ���۳�� ����
    q.push(0); // 1������ �������̹Ƿ� �־���

    ////7. 4~6�ܰ� �ݺ�
    while(!q.empty()) // queue�� ������� �ʾҴ� : ���� ���ѳ��� ������ node�� ���Ҵ�.
    //{
    //    //4. queue���� node(now)�� �ϳ� ����
        int now = q.front(); // now : �̹��� ������ ���ѳ��� node
        q.pop();

    //    // -------- �̹��� now�� ��ȴ�.
        cout << now << " ";
    //    // --------

    //    // 5. now���� �� �� �ִ� node(next)�� ã��
        for (int next = 1; next <= 9; next++)
    //    {
            if (arr[now][next] == 0) continue; // now->next�� ���� ���ϸ� ����

    //        // now�� next�� ������ų �� �ִ�.
    //        // -------- ���ο� next��� ���� ã�Ҵ�.

    //        // 6. next���� queue�� �߰�
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
    //} // 1. �׷��� ����

    //// 2. queue ����
    //queue<int> q;

    //// 3. ������ ����
    //q.push(1);

    //// 7. queue�� ����������� ����
    //while (!q.empty()) {
    //    // 4. quue�� �� ���� now������
    //    int now = q.front();
    //    q.pop();

    //    cout << now;

    //    // 5. now���� �� �� �ִ� nextã��
    //    for (int i = 0; i < v[now].size(); i++)
    //    {
    //        int next = v[now][i];

    //        // 6. next�� queue�� �߰�
    //        q.push(next);
    //    }
    //}
    return 0;
}