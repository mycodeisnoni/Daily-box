// ## 1062 ����ħ

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, K;
int alpha[27] = { 0, };     // �� ���ڿ����� � ���ĺ��� ������ϴ��� ��� + �������� ������� ���ĺ� ���� ���
vector<int>need[50];        // �� idx�� ���ڿ����� � ���ĺ��� ����� ���� �� �ִ���
int flag = 0;
int cnt = 0;
vector<int>avail;       // ��� �� �ִ� ���ڿ��� need �ε��� ���� ���
vector<int>alphaAvail;  // �����Ҹ��� ���ĺ� ���� ���
vector<int>learn;       // ���� ��� K-5���� ���ĺ� ���
int maxCnt = -1;


void init() {
    cin >> N >> K;

    if (K < 5) {        // a n t i c �ټ����� ������ ����� ���� ���� �� �ִ�.
        cout << 0;
        flag = 1;
        return;
    }

    for (int i = 0; i < N; i++) {
        string x;
        cin >> x;

        for (int j = 4; j <= x.size() - 5; j++) {   // anta ~ tica ���̸�
            int nowIdx = x[j] - 'a';
            if (alpha[nowIdx]) continue;        // �ߺ��� ���� �߰� �� continue

            // a n t i c �߰� �� continue;
            if (nowIdx + 'a' == 'a') continue;
            if (nowIdx + 'a' == 'n') continue;
            if (nowIdx + 'a' == 't') continue;
            if (nowIdx + 'a' == 'i') continue;
            if (nowIdx + 'a' == 'c') continue;

            alpha[nowIdx]++;
            need[i].push_back(nowIdx);
        }
        memset(alpha, 0, sizeof(alpha));        // ���� ��� ���ɼ��� �ִ� ���ĺ� ��Ͽ����� ��� ����
    }
}


void func1() {

    for (int i = 0; i < N; i++) {
        if (need[i].size() > K - 5) continue;   // ������ϴ°� ��� �� �ִ� ���ĺ� ���� ���� ���
        if (need[i].size() == 0) cnt++;     // �� ��� �ܾ ���� ���ڿ� : ���� �ٷ� �߰�
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

    // ���� ���ڴٰ� ������ �� : learn
    // ��� �� �ִ� ���ڿ��� need �ε��� ���� ��� : avail
    // need[i] ��� ���ڿ��� �дµ��� �ʿ��� ���ĺ� �ε������� ����ִ�.
    int Checkcnt = 0;
    for (int i = 0; i < avail.size(); i++) {

        int flagCheck2 = 0;
        // ���ڿ� need[i]�� ������ ���ĺ� need[i][j] Ȯ��
        for (int j = 0; j < need[avail[i]].size(); j++) {
            int flagCheck = 0;


            for (int k = 0; k < learn.size(); k++) {
                if (need[avail[i]][j] == learn[k]) {  // �� ���ĺ��� ���Ÿ� flag����� break
                    flagCheck = 1;
                    break;
                }
            }
            if (flagCheck == 0) {   // ���ڿ� need[i]�� � ���ĺ� need[i][j]�� ����� ��Ȳ
                flagCheck2 = 1; // ���д� ���ڿ��̶�� üũ
                continue;
            }

        }
        if (flagCheck2 == 0) Checkcnt++;   // �� ����ߴٸ�, �� ���ڿ��� ���� �� �ִ� ��
    }
    return Checkcnt;
}



void func2(int idx) {   // alpha�� üũ�� ���ĺ��� �� K-5���� ���� ���� �� �� ���� ������ �ִ� ���ڿ����� Ȯ��

    if (learn.size() == K - 5) {
        int nowCnt = checkCnt();
        if (nowCnt > maxCnt) maxCnt = nowCnt;
        return;
    }

    if (learn.size() == alphaAvail.size()) {     // ���� Ǯ�̿����� ��� ���ĺ��� �ƴ϶� ��︸�� �ֵ�θ� Ȯ���ϰ� ����
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
    if (flag == 1) return 0;    // ��� �� �ִ°� 5������ ������ ����


    func1();    // ��︸�� ���ڿ� ��� + ���� ������ ���ĺ� ����
    func2(0);

    int ans = maxCnt + cnt;

    cout << ans;

    return 0;
}