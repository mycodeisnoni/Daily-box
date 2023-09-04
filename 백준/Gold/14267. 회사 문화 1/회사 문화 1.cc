#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
int parent[100001]= {0,};        // 내 직속 상사, 상사로부터 받은 칭찬의 수치
int pray[100001] = { 0, };
struct Node {
    int num, cnt;
};
vector<Node>praying[100001];        // idx가 누구에게 얼만큼 칭찬했는가


void init() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> parent[i];
        if (parent[i] == -1) parent[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int num, cnt;
        cin >> num >> cnt;
        praying[parent[num]].push_back({ num, cnt });
    }
}

void dijkstra() {
    for (int i = 1; i <= n; i++) {
        // 1. 칭찬하기
        for (int j = 0; j < praying[i].size(); j++) {
            pray[praying[i][j].num] += praying[i][j].cnt;
        }
        // 2. 내 부모의 칭찬점수 상속
        pray[i] += pray[parent[i]];
    }
}

void printing() {
    for (int i = 1; i <= n; i++) {
        cout << pray[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    dijkstra();
    printing();
    
    return 0;
}