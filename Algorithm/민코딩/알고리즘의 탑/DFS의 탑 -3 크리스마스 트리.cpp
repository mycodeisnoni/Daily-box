#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector <int> v[1001];


void dfs1(int now) {

    // -1을 입력을 받아야 해결
    // 왼족 갔다와서 자기 자신도 출력해줘야 하니까
    // 중위 순회

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
//    // 만약에 -1이면 그냥 skip
//    if (curNum == -1) return;
//
//    // 왼쪽 서브 트리 탐색
//    dfs_1(v[curNum][0]);
//
//    // 왼쪽 탐색 끝나면 자기 자신 출력
//    cout << curNum << " ";
//
//    // 오른쪽 서브 트리 탐색
//    dfs_1(v[curNum][1]);
//
//}
//
//void dfs_2(int curNum)
//{
//    // 만약에 -1이면 그냥 skip
//    if (curNum == -1) return;
//
//    // 왼쪽 탐색 하기 전에 자기 자신 출력
//    cout << curNum << " ";
//
//    // 왼쪽 서브 트리 탐색
//    dfs_2(v[curNum][0]);
//
//    // 오른쪽 서브 트리 탐색
//    dfs_2(v[curNum][1]);
//}
//
//void dfs_3(int curNum)
//{
//    // 만약에 -1이면 그냥 skip
//    if (curNum == -1) return;
//
//    // 왼쪽 서브 트리 탐색
//    dfs_3(v[curNum][0]);
//
//    // 오른쪽 서브 트리 탐색
//    dfs_3(v[curNum][1]);
//
//    // 왼쪽 오른쪽 다 탐색한 후, 자기 자신 출력
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
//        // 1번째로 들어간 것 : left, 2번째로 들어간 것 : right
//        v[parent].push_back(left);
//        v[parent].push_back(right);
//    }
//
//    // 1번 탐색(중위 순회)
//    dfs_1(1);
//
//    cout << endl;
//
//    // 2번 탐색(전위 순회)
//    dfs_2(1);
//
//    cout << endl;
//
//    // 3번 탐색(후위 순회)
//    dfs_3(1);
//}