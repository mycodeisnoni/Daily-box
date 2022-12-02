#include<iostream>
using namespace std;

char st[11] = { 0, };
int i;

void AAA(int num) {

        cout << num << " ";
    
    if (num == 1) {
        return;
    }

        AAA(num - 1);
        cout << num << " ";
    }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
   
    cin >> st;
    for (i = 0; i < 11; i++) {
        if (st[i] == '\0') {
            break;
        }
    }
    AAA(i);

   
    return 0; // <- 프로그램이 정상적으로 종료됐는가?
}