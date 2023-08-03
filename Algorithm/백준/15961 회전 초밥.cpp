#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, d, k, c;
vector<int>fish;
int eat[3001] = { 0, }; // �� idx�� �ʹ��� � �԰� �ִ��� Ȯ��
int cntMax;    // �ʹ��� �ִ� ���� ���� ���

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
    int fishCnt = 1;    // ���� �ʹ� ������ ���� ���
    int cnt = 1;    // ���� �����ؼ� ���� �ʹ� ���� ���
    eat[fish[left]] = 1;

    while (left < N) {  // left �Űܰ��� k���� Ȯ��

        if (cnt < k) {
            right++;
            if (right >= N) right -= N;     // N��°���� 0��°�� ������
            if (!eat[fish[right]]) fishCnt++;     // �ȸ��� �ʹ��̸� ������ �÷���
            eat[fish[right]]++;
            cnt++;
        }

        else if (cnt == k) {    // �����ؼ� k���� �ʹ��� ���� ���

            // ���� �ʹ� Ȯ��
            if (!eat[c]) {  // ���� �ʹ��� �� ���� ���, ���� ������ ���� +1
                if (fishCnt + 1 > cntMax) cntMax = fishCnt + 1;
            }

            if (fishCnt > cntMax) cntMax = fishCnt;     // �ִ� �ʹ����� ���� ����

            // left �ű�� �۾�
            eat[fish[left]]--;
            if (!eat[fish[left]]) fishCnt--;      // eat[fish[left]]==0 : �ش� �ʹ��� ���� �� ����
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