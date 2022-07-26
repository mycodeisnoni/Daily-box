#include<iostream>
using namespace std;

void AAA(int num) {
    if (num > 2) {
        return;
    }

    for (int i = 0; i < 3; i++) {
        AAA(num + 1);
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
   
    AAA(0);

    return 0; // <- 프로그램이 정상적으로 종료됐는가?
}