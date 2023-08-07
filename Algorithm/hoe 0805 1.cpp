#include <iostream>
#include <vector>
using namespace std;

long long MODE = 999983;
int N, Q;
struct Node {
    long long first, second, third;
    // 이차계수, 일차계수, 상수
    // 유저번호, 입력시간, 입력OTP
};
vector<Node>user;       // i번째 유저의 generate 함수의 계수 저장

void init() {
    cin >> N;
    
    user.push_back({ 0,0,0 });  // idx맞추는 작업
    for (int i = 1; i <= N; i++) {
        long long A, B, C;
        cin >> A >> B >> C;
        user.push_back({ A,B,C });        
    }
}

void calc() {
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int flag = 0;
        long long now_user, now_time, now_otp;
        cin >> now_user >> now_time >> now_otp;

        Node now_g = user[now_user];

        for (long long k = now_time - 3; k <= now_time + 3; k++) {
            long long check_otp = 
                (((((now_g.first % MODE) * (k % MODE)) % MODE) * (k % MODE)) % MODE
                + ((now_g.second % MODE) * (k % MODE)) % MODE 
                + (now_g.third) % MODE) % MODE;
            if (check_otp == now_otp) {
                cout << "YES\n";
                flag = 1;
                break;
            }
         }
        if(flag == 0) cout << "NO\n";
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int de = -1;

    calc();

    return 0;
}