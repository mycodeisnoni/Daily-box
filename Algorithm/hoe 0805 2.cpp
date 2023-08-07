#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, K, Q;
string worker[8] = { "" };
struct Node {
    int day, sh, sm, eh, em;
};
vector<Node>meet;
int plan_mon[55][8] = { 0, };   // 월요일의 각 10분단위에 idx 사원이 회의중인가?
int plan_tue[55][8] = { 0, };
int plan_wed[55][8] = { 0, };
int plan_thu[55][8] = { 0, };
int plan_fri[55][8] = { 0, };

char seperator = ',';

void init() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> worker[i];
    cin >> K;
    for (int i = 0; i < K; i++) {
        string day;
        int sh, sm, eh, em;
        string work;
        cin >> day >> sh >> sm >> eh >> em >> work;

        int start_row = (sh - 9) * 6 + sm / 10;
        int end_row = (eh - 9) * 6 + em / 10 - 1;

        
        // 회의에 참여하는 사원들 정보 확인
        vector<string>now_worker;
        int left = 0;
        int right = 0;
        while (right<work.size()) {

            if (work[right] == seperator) {
                string meeter = work.substr(left, right - left);
                now_worker.push_back(meeter);
                right++;
                left = right;
            }
            else right++;
        }
        string meeter = work.substr(left, right - 1);
        now_worker.push_back(meeter);

        for (int j = 0; j < now_worker.size(); j++) {
            int start = start_row;
            for (int k = 1; k <= N; k++) {
                if (now_worker[j] == worker[k]) {
                    while (start <= end_row) {
                        if (day == "Mon") plan_mon[start][k] = 1;
                        if (day == "Tue") plan_tue[start][k] = 1;
                        if (day == "Wed") plan_wed[start][k] = 1;
                        if (day == "Thu") plan_thu[start][k] = 1;
                        if (day == "Fri") plan_fri[start][k] = 1;
                        start++;
                    }
                }
            }
        }
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        string day, work;
        cin >> day >> work;
        int maxCnt = 0;
        int used[55] = { 0, };  // 시간별 일하는 애들 기록

        vector<string>workDay;
        int left = 0;
        int right = 0;

        int daaaaaaa = -5;
        while (right < day.size()) {
            if (day[right] == seperator) {
                string working = day.substr(left, 3);
                workDay.push_back(working);
                right++;
                left = right;
            }
            else right++;
        }
        string working = day.substr(left, 3);
        workDay.push_back(working);


        // 벡터에 회의에 참여해야하는 사원들 정보 알려주기
        vector<string>now_worker;
        left = 0;
        right = 0;
        while (right < work.size()) {

            if (work[right] == seperator) {
                string meeter = work.substr(left, right - left);
                now_worker.push_back(meeter);
                right++;
                left = right;
            }
            else right++;
        }
        string meeter = work.substr(left, right - left);
        now_worker.push_back(meeter);

        for (int j = 0; j < meeter.size(); j++) {

            for (int dd = 0; dd < workDay.size(); dd++) {
                string dday = workDay[dd];

                if (dday == "Mon") {
                    for (int k = 0; k < 54; k++) {
                        if (plan_mon[k][meeter[j]-'0']) used[k] = 1;
                    }
                }
                if (dday == "Tue") {
                    for (int k = 0; k < 54; k++) {
                        if (plan_tue[k][meeter[j]-'0']) used[k] = 1;
                    }
                }
                if (dday == "Wed") {
                    for (int k = 0; k < 54; k++) {
                        if (plan_wed[k][meeter[j]-'0']) used[k] = 1;
                    }
                }
                if (dday == "Thu") {
                    for (int k = 0; k < 54; k++) {
                        if (plan_thu[k][meeter[j]-'0']) used[k] = 1;
                    }
                }
                if (dday == "Fri") {
                    for (int k = 0; k < 54; k++) {
                        if (plan_fri[k][meeter[j]-'0']) used[k] = 1;
                    }
                }
            }    
        }

        left = 0;
        right = 0;
        int cnt = 0;
        

        while (right < 54) {

            if (used[right]) {
                right++;
                left = right;
                cnt = 0;
            }

            else {
                cnt++;
                if (cnt > maxCnt) maxCnt = cnt;
                right++;
            }
        }

        cout << maxCnt * 10 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    return 0;
}