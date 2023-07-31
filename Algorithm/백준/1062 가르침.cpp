// ## 1062 가르침

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, K;
int alpha[27] = { 0, };     // 각 문자열마다 어떤 알파벳을 배워야하는지 기록 + 마지막에 배움직한 알파벳 정보 기록
vector<int>need[50];        // 각 idx의 문자열마다 어떤 알파벳을 배워야 읽을 수 있는지
int flag = 0;
int cnt = 0;
vector<int>avail;       // 배울 수 있는 문자열의 need 인덱스 정보 기록
vector<int>alphaAvail;  // 선택할만한 알파벳 정보 기록
vector<int>learn;       // 현재 배울 K-5개의 알파벳 기록
int maxCnt = -1;


void init() {
    cin >> N >> K;

    if (K < 5) {        // a n t i c 다섯개는 무조건 배워야 뭐라도 읽을 수 있다.
        cout << 0;
        flag = 1;
        return;
    }

    for (int i = 0; i < N; i++) {
        string x;
        cin >> x;

        for (int j = 4; j <= x.size() - 5; j++) {   // anta ~ tica 사이만
            int nowIdx = x[j] - 'a';
            if (alpha[nowIdx]) continue;        // 중복된 문자 발견 시 continue

            // a n t i c 발견 시 continue;
            if (nowIdx + 'a' == 'a') continue;
            if (nowIdx + 'a' == 'n') continue;
            if (nowIdx + 'a' == 't') continue;
            if (nowIdx + 'a' == 'i') continue;
            if (nowIdx + 'a' == 'c') continue;

            alpha[nowIdx]++;
            need[i].push_back(nowIdx);
        }
        memset(alpha, 0, sizeof(alpha));        // 추후 배울 가능성이 있는 알파벳 기록용으로 사용 예정
    }
}


void func1() {

    for (int i = 0; i < N; i++) {
        if (need[i].size() > K - 5) continue;   // 배워야하는게 배울 수 있는 알파벳 보다 많은 경우
        if (need[i].size() == 0) cnt++;     // 더 배울 단어가 없는 문자열 : 개수 바로 추가
        else {
            avail.push_back(i);
            for (int j = 0; j < need[i].size(); j++) {
                if (alpha[need[i][j]] == 0) alphaAvail.push_back(need[i][j]);
                alpha[need[i][j]]++;
            }
        }
    }
}

int checkCnt() {

    // 현재 배우겠다고 지정한 것 : learn
    // 배울 수 있는 문자열의 need 인덱스 정보 기록 : avail
    // need[i] 라는 문자열을 읽는데에 필요한 알파벳 인덱스들이 들어있다.
    int Checkcnt = 0;
    for (int i = 0; i < avail.size(); i++) {

        int flagCheck2 = 0;
        // 문자열 need[i]의 각각의 알파벳 need[i][j] 확인
        for (int j = 0; j < need[avail[i]].size(); j++) {
            int flagCheck = 0;


            for (int k = 0; k < learn.size(); k++) {
                if (need[avail[i]][j] == learn[k]) {  // 그 알파벳이 배운거면 flag세우고 break
                    flagCheck = 1;
                    break;
                }
            }
            if (flagCheck == 0) {   // 문자열 need[i]중 어떤 알파벳 need[i][j]를 못배운 상황
                flagCheck2 = 1; // 못읽는 문자열이라고 체크
                continue;
            }

        }
        if (flagCheck2 == 0) Checkcnt++;   // 잘 통과했다면, 그 문자열은 읽을 수 있단 뜻
    }
    return Checkcnt;
}



void func2(int idx) {   // alpha에 체크된 알파벳들 중 K-5개의 조합 선택 후 그 때의 읽을수 있는 문자열개수 확인

    if (learn.size() == K - 5) {
        int nowCnt = checkCnt();
        if (nowCnt > maxCnt) maxCnt = nowCnt;
        return;
    }

    if (learn.size() == alphaAvail.size()) {     // 현재 풀이에서는 모든 알파벳이 아니라 배울만한 애들로만 확인하고 있음
        int nowCnt = checkCnt();
        if (nowCnt > maxCnt) maxCnt = nowCnt;
        return;
    }

    for (int i = idx; i < alphaAvail.size(); i++) {
        learn.push_back(alphaAvail[i]);
        func2(i + 1);
        learn.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    if (flag == 1) return 0;    // 배울 수 있는게 5개보다 적으면 종료


    func1();    // 배울만한 문자열 기록 + 선택 가능한 알파벳 저장
    func2(0);

    int ans = maxCnt + cnt;

    cout << ans;

    return 0;
}