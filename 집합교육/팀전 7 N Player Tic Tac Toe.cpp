#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int map[4][4] = { 0, };
char alp[100] = { 0, };
char alpg[100] = { 0, };
char useds[100] = { 0, };
char usedg[10000] = { 0, };

struct Node {
    char a, b;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();


    for (int i = 0; i < 3; i++) {
        string x;
        cin >> x;

        for (int j = 0; j < 3; j++) {
            map[i][j] = x[j];
        }
    }


    int solowin = 0;
    int groupwin = 0;

    int cnt2=0;
    int cnt3=0;
    char ch2;
    char ch3;
    char ch1;

    vector < char > solo;
    vector < Node > group;



    //가로 확인
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            alp[map[a][b]]++;
            alpg[map[a][b]]++;
        }

        for (char i = 'A'; i <= 'Z'; i++) {
            if (alpg[i] == 1) {
                ch1 = i;
            }
            if (alpg[i] == 2) {
                cnt2++;
                ch2 = i;
            }
            if (alp[i] == 3) {
                cnt3++;
                ch3 = i;
            }
        }
        if (cnt2) {
            if (usedg[ch1 * ch2] == 0) {
                usedg[ch1 * ch2] = 1;
                groupwin++;
                cnt2--;
            }
        }
        if (cnt3) {
            if (useds[ch3] == 0) {
                useds[ch3]++;
                solowin++;
                cnt3--;
            }
        }

        for (char i = 'A'; i <= 'Z'; i++) {
            alp[i] = 0;
            alpg[i] = 0;
        }
    }


    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            alp[map[b][a]]++;
            alpg[map[b][a]]++;
        }
        //세로 확인
        for (char i = 'A'; i <= 'Z'; i++) {
            if (alpg[i] == 1) {
                ch1 = i;
            }
            if (alpg[i] == 2) {
                cnt2++;
                ch2 = i;
            }
            if (alp[i] == 3) {
                cnt3++;
                ch3 = i;
            }
        }
        if (cnt2) {
            if (usedg[ch1 * ch2] == 0) {
                usedg[ch1 * ch2] = 1;
                groupwin++;
                cnt2--;
            }
        }
        if (cnt3) {
            if (useds[ch3] == 0) {
                useds[ch3]++;
                solowin++;
                cnt3--;
            }
        }

        for (char i = 'A'; i <= 'Z'; i++) {
            alp[i] = 0;
            alpg[i] = 0;
        }
    }


    //대각선확인
    for (int i = 0; i < 3; i++) {
        alp[map[i][i]]++;
        alpg[map[i][i]]++;
    }

    for (char i = 'A'; i <= 'Z'; i++) {
        if (alpg[i] == 1) {
            ch1 = i;
        }
        if (alpg[i] == 2) {
            cnt2++;
            ch2 = i;
        }
        if (alp[i] == 3) {
            cnt3++;
            ch3 = i;
        }
    }
    if (cnt2) {
        if (usedg[ch1 * ch2] == 0) {
            usedg[ch1 * ch2] = 1;
            groupwin++;
            cnt2--;
        }
    }
    if (cnt3) {
        if (useds[ch3] == 0) {
            useds[ch3]++;
            solowin++;
            cnt3--;
        }
    }

    for (char i = 'A'; i <= 'Z'; i++) {
        alp[i] = 0;
        alpg[i] = 0;
    }




    for (int i = 0; i < 3; i++) {
        alp[map[i][2 - i]]++;
        alpg[map[i][2 - i]]++;
    }
    for (char i = 'A'; i <= 'Z'; i++) {
        if (alpg[i] == 1) {
            ch1 = i;
        }
        if (alpg[i] == 2) {
            cnt2++;
            ch2 = i;
        }
        if (alp[i] == 3) {
            cnt3++;
            ch3 = i;
        }
    }
    if (cnt2) {
        if (usedg[ch1 * ch2] == 0) {
            usedg[ch1 * ch2] = 1;
            groupwin++;
            cnt2--;
        }
    }
    if (cnt3) {
        if (useds[ch3] == 0) {
            useds[ch3]++;
            solowin++;
            cnt3--;
        }
    }

    for (char i = 'A'; i <= 'Z'; i++) {
        alp[i] = 0;
        alpg[i] = 0;
    }

    cout << solowin << '\n' << groupwin;


    return 0;
}