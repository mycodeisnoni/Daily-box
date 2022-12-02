#include<iostream>
using namespace std;

int level, branch;
int cnt;

void AAA(int num) {

    cnt++;

    if (num >= level) {
        return;
    }

    for (int i = 0; i < branch; i++) {
        AAA(num + 1);
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
   
    cin >> branch >> level;
    AAA(0);

    cout << cnt;
    return 0; // <- 프로그램이 정상적으로 종료됐는가?
}