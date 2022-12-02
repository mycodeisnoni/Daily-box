#include<iostream>
using namespace std;

int level;

void AAA(int num) {
    cout << num;

    if (num >= level) {
        return;
    }

    for (int i = 0; i < 2; i++) {
        AAA(num + 1);
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
   
    cin >> level;
    AAA(0);

    return 0; // <- 프로그램이 정상적으로 종료됐는가?
}