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


    int RCplus = row + col;     // row+col 값이 이 값이면 2,4번째 모퉁이
    int RCminus = row - col;    // row-col 값이 이 값이면 1,3번째 모퉁이

    for (int i = 1; i <= s; i++) {

        int nowValue = arr[row - i][col - i];   // 1번째 모퉁이부터 시작

        int nr = row - i;
        int nc = col - i;

        while (nr + nc != RCplus) {    // 2번째 모퉁이에 도착할때까지
            int next = arr[nr][nc + 1];   // 기존값 저장
            arr[nr][nc + 1] = nowValue; // 이동값 저장
            nowValue = next;
            nc++;
        }

        while (nr - nc != RCminus) {       // 3번째 모퉁이에 도착할때까지
            int next = arr[nr + 1][nc]; // 기존값 저장
            arr[nr + 1][nc] = nowValue;
            nowValue = next;
            nr++;
        }

        while (nr + nc != RCplus) {     // 4번째 모퉁이에 도착할때까지
            int next = arr[nr][nc - 1];   // 기존값 저장
            arr[nr][nc - 1] = nowValue; // 이동값 저장
            nowValue = next;
            nc--;
        }

        while (nr - nc != RCminus) {       // 1번째 모퉁이에 도착할때까지
            int next = arr[nr - 1][nc]; // 기존값 저장
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

        // 순서를 바꿀 때 마다 arr 초기화
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