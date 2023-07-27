#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
int arr[51][51] = { 0, };
int arrCopy[51][51] = { 0, };
struct spin {
    int r, c, s;
};
vector <spin>v;

int minAns = 2e9;

vector<int>nowOrder;
vector<vector<int>> funcOrder;

void init() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            arrCopy[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        int c, s, r = 0;
        cin >> r >> c >> s;
        v.push_back({ r,c,s });
    }
}

void makeOrder(int K) {      // dfs

    if (nowOrder.size() == K) {
        funcOrder.push_back(nowOrder);
        return;
    }

    for (int i = 0; i < K; i++) {
        bool found = false;
        for (int num : nowOrder) {
            if (num == i) {
                found = true;
                break;
            }
        }

        if (!found) {
            nowOrder.push_back(i);
            makeOrder(K);
            nowOrder.pop_back();
        }
    }
}



void func(int idx) {
    int row = v[idx].r;
    int col = v[idx].c;
    int s = v[idx].s;


    int RCplus = row + col;     // row+col ���� �� ���̸� 2,4��° ������
    int RCminus = row - col;    // row-col ���� �� ���̸� 1,3��° ������

    for (int i = 1; i <= s; i++) {

        int nowValue = arr[row - i][col - i];   // 1��° �����̺��� ����

        int nr = row - i;
        int nc = col - i;

        while (nr + nc != RCplus) {    // 2��° �����̿� �����Ҷ�����
            int next = arr[nr][nc + 1];   // ������ ����
            arr[nr][nc + 1] = nowValue; // �̵��� ����
            nowValue = next;
            nc++;
        }

        while (nr - nc != RCminus) {       // 3��° �����̿� �����Ҷ�����
            int next = arr[nr + 1][nc]; // ������ ����
            arr[nr + 1][nc] = nowValue;
            nowValue = next;
            nr++;
        }

        while (nr + nc != RCplus) {     // 4��° �����̿� �����Ҷ�����
            int next = arr[nr][nc - 1];   // ������ ����
            arr[nr][nc - 1] = nowValue; // �̵��� ����
            nowValue = next;
            nc--;
        }

        while (nr - nc != RCminus) {       // 1��° �����̿� �����Ҷ�����
            int next = arr[nr - 1][nc]; // ������ ����
            arr[nr - 1][nc] = nowValue;
            nowValue = next;
            nr--;
        }
    }
}

int calc() {
    int minRow = 2e9;
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= M; j++) {
            cnt += arr[i][j];
        }
        if (cnt < minRow) minRow = cnt;
    }
    return minRow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    makeOrder(K);
    for (int i = 0; i < funcOrder.size(); i++) {

        // ������ �ٲ� �� ���� arr �ʱ�ȭ
        for (int row = 1; row <= N; row++) {
            for (int col = 1; col <= M; col++) {
                arr[row][col] = arrCopy[row][col];
            }
        }

        for (int j = 0; j < K; j++) {
            func(funcOrder[i][j]);
        }
        int ans = calc();
        if (ans < minAns) minAns = ans;
    }


    cout << minAns;

    return 0;
}