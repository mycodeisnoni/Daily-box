#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// ������Ʃ�� ��! ���� ����~~

vector <int> v[101001];
int used[101001] = { 0, };
int level[101001] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    //N�� ��
    //K�� �ϳ��� ������ Ʃ�갡 �����ϴ� ��
    //M�� ������ Ʃ�� ����

    int N, K, M;
    cin >> N >> K >> M;


    //�� ������Ʃ�꿡 ���� ���� ���� �Է¹ޱ�
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