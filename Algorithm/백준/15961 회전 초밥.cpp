#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, d, k, c;
vector<int>fish;
int eat[3001] = { 0, }; // 각 idx의 초밥을 몇개 먹고 있는지 확인
int cntMax;    // 초밥의 최대 종류 개수 기록

void init() {
    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; i++) {
        int nowFish;
        cin >> nowFish;
        fish.push_back(nowFish);
    }
}

int tp() {

    int left = 0;
    int right = 0;
    int fishCnt = 1;    // 현재 초밥 종류의 개수 기록
    int cnt = 1;    // 현재 연속해서 먹은 초밥 개수 기록
    eat[fish[left]] = 1;

    while (left < N) {  // left 옮겨가며 k개씩 확인

        if (cnt < k) {
            right++;
            if (right >= N) right -= N;     // N번째부터 0번째로 보내기
            if (!eat[fish[right]]) fishCnt++;     // 안먹은 초밥이면 종류를 늘려라
            eat[fish[right]]++;
            cnt++;
        }

        else if (cnt == k) {    // 연속해서 k개의 초밥을 먹은 경우

            // 쿠폰 초밥 확인
            if (!eat[c]) {  // 쿠폰 초밥을 안 먹은 경우, 먹은 종류의 개수 +1
                if (fishCnt + 1 > cntMax) cntMax = fishCnt + 1;
            }

            if (fishCnt > cntMax) cntMax = fishCnt;     // 최대 초밥종류 개수 갱신

            // left 옮기는 작업
            eat[fish[left]]--;
            if (!eat[fish[left]]) fishCnt--;      // eat[fish[left]]==0 : 해당 초밥은 먹은 적 없음
            left++;
            cnt--;
        }
    }
    return cntMax;
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int ans = tp();
    cout << ans;
    
    return 0;
}