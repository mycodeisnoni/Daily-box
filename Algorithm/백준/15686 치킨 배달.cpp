#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int map[51][51] = { 0, };
struct node {
    int row, col;
};
vector<node>chicken;
vector<node>home;
int dis[101][14] = { 0, };   // 집에서부터 치킨집들까지의 거리 기록

vector<int>nowPick;
int chickenCnt, homeCnt;
int minDis = 2e9;

void init() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                chicken.push_back({ i,j });
                chickenCnt++;
            }
            if (map[i][j] == 1) {
                home.push_back({ i,j });
                homeCnt++;
            }
        }
    }
}

void calc() {   // 집마다 모든 치킨집까지의 거리 계산
    for (int i = 0; i < home.size(); i++) {
        for (int j = 0; j < chicken.size(); j++) {
            int distance = abs(home[i].row - chicken[j].row) + abs(home[i].col - chicken[j].col);
            dis[i][j] = distance;
        }
    }
}

int func() {
    int disCnt = 0;
    for (int j = 0; j < homeCnt; j++) {
        int min_dis = 2e9;
        for (int i = 0; i < M; i++) {
            min_dis = min(dis[j][nowPick[i]], min_dis);
            // j번째 집에서 nowPick[i]번째 치킨집까지의 거리
        }
        disCnt += min_dis;
    }
    return disCnt;
}

void com(int now) { // chickenCnt 중 M개의 조합 구하기

    if (nowPick.size() == M) {
        int nowDis = func();
        if (nowDis < minDis) minDis = nowDis;
        return;
    }

    for (int i = now; i < chickenCnt; i++) {
        nowPick.push_back(i);
        com(i + 1);
        nowPick.pop_back();
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    calc();
    com(0);
    cout << minDis;

    return 0;
}