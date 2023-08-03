#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int map[21][21] = { 0, };   // 학생 기록
vector<int>like[401];

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

int mylike[4] = { 0, };

void checking(int now) {
    
    int maxLike = -1;
    int maxEmpty = -1;
    int fixRow = 1;
    int fixCol = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {

            if (map[i][j]) continue;
            int likeCnt = 0;
            int emptyCnt = 0;

            for (int d = 0; d < 4; d++) {
                int checkRow = i + dr[d];
                int checkCol = j + dc[d];
                if (checkRow < 1 || checkCol <1 || checkRow >N || checkCol>N) continue;
                if (map[checkRow][checkCol] == mylike[0]) likeCnt++;
                if (map[checkRow][checkCol] == mylike[1]) likeCnt++;
                if (map[checkRow][checkCol] == mylike[2]) likeCnt++;
                if (map[checkRow][checkCol] == mylike[3]) likeCnt++;
                if (map[checkRow][checkCol] == 0) emptyCnt++;
            }
            if (likeCnt > maxLike) {
                maxLike = likeCnt;
                maxEmpty = emptyCnt;
                fixRow = i;
                fixCol = j;
            }
            else if (likeCnt == maxLike && emptyCnt > maxEmpty) {
                maxEmpty = emptyCnt;
                fixRow = i;
                fixCol = j;
            }
        }
    }
    int de = -1;
    map[fixRow][fixCol] = now;
}

void init() {

    cin >> N;

    for (int i = 0; i < N * N; i++) {

        int now;
        memset(mylike, 0, sizeof(mylike));
        cin >> now;
        for (int j = 0; j < 4; j++) {
            cin >> mylike[j];
            like[now].push_back(mylike[j]);
        }
        checking(now); 
    }
}

int calc() {   // 만족도 계산
    int happypoint = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int likeMem = 0;
            for (int d = 0; d < 4; d++) {
                int nowRow = i + dr[d];
                int nowCol = j + dc[d];
                if (nowRow<1 || nowCol<1 || nowRow>N || nowCol>N) continue;
                if (map[nowRow][nowCol] == like[map[i][j]][0]) likeMem++;
                if (map[nowRow][nowCol] == like[map[i][j]][1]) likeMem++;
                if (map[nowRow][nowCol] == like[map[i][j]][2]) likeMem++;
                if (map[nowRow][nowCol] == like[map[i][j]][3]) likeMem++;     
            }
            if (likeMem == 1) happypoint += 1;
            else if (likeMem == 2) happypoint += 10;
            else if (likeMem == 3) happypoint += 100;
            else if (likeMem == 4) happypoint += 1000;
        }
    }
    return happypoint;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int ans = calc();

    cout << ans;

    return 0;
}