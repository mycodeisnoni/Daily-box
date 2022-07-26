#include<iostream>
using namespace std;

int level, branch;

void AAA(int num) {
    if (num > level) {
        return;
    }

    for (int i = 0; i < branch; i++) {
        AAA(level + 1);
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
   

    cin >> level >> branch;

    AAA(0);

    return 0; // <- 프로그램이 정상적으로 종료됐는가?
}