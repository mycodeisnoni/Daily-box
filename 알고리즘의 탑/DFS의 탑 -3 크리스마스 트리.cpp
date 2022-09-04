#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector <int> v[1001];


void dfs1(int now) {

    // -1�� �Է��� �޾ƾ� �ذ�
    // ���� ���ٿͼ� �ڱ� �ڽŵ� �������� �ϴϱ�
    // ���� ��ȸ

}

void dfs2(int now) {

    cout << now << " ";
    for (int i = 0; i < v[now].size(); i++) {
        dfs2(v[now][i]);
    }
    return;
}


void dfs3(int now) {

    for (int i = 0; i < v[now].size(); i++) {
        dfs3(v[now][i]);
    }
    cout << now << " ";
    return;
}


int startnum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int N;
    cin >> N;
    

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (i == 0) startnum = a;
        if (b != -1) {
            v[a].push_back(b);
        }
        if (c != -1) {
            v[a].push_back(c);
        }
    }

    dfs1(startnum);
    cout << endl;
    dfs2(startnum);
    cout << endl;
    dfs3(startnum);

    return 0;
}




//#include <iostream>
//#include <vector>
//using namespace std;
//
//int N;
//vector<int> v[1003];
//
//void dfs_1(int curNum)
//{
//    // ���࿡ -1�̸� �׳� skip
//    if (curNum == -1) return;
//
//    // ���� ���� Ʈ�� Ž��
//    dfs_1(v[curNum][0]);
//
//    // ���� Ž�� ������ �ڱ� �ڽ� ���
//    cout << curNum << " ";
//
//    // ������ ���� Ʈ�� Ž��
//    dfs_1(v[curNum][1]);
//
//}
//
//void dfs_2(int curNum)
//{
//    // ���࿡ -1�̸� �׳� skip
//    if (curNum == -1) return;
//
//    // ���� Ž�� �ϱ� ���� �ڱ� �ڽ� ���
//    cout << curNum << " ";
//
//    // ���� ���� Ʈ�� Ž��
//    dfs_2(v[curNum][0]);
//
//    // ������ ���� Ʈ�� Ž��
//    dfs_2(v[curNum][1]);
//}
//
//void dfs_3(int curNum)
//{
//    // ���࿡ -1�̸� �׳� skip
//    if (curNum == -1) return;
//
//    // ���� ���� Ʈ�� Ž��
//    dfs_3(v[curNum][0]);
//
//    // ������ ���� Ʈ�� Ž��
//    dfs_3(v[curNum][1]);
//
//    // ���� ������ �� Ž���� ��, �ڱ� �ڽ� ���
//    cout << curNum << " ";
//}
//
//int main()
//{
//    // input N
//    cin >> N;
//
//    // input graph
//    for (int i = 0; i < N; i++)
//    {
//        int parent, left, right;
//        cin >> parent >> left >> right;
//
//        // 1��°�� �� �� : left, 2��°�� �� �� : right
//        v[parent].push_back(left);
//        v[parent].push_back(right);
//    }
//
//    // 1�� Ž��(���� ��ȸ)
//    dfs_1(1);
//
//    cout << endl;
//
//    // 2�� Ž��(���� ��ȸ)
//    dfs_2(1);
//
//    cout << endl;
//
//    // 3�� Ž��(���� ��ȸ)
//    dfs_3(1);
//}