#include <iostream>
#include <vector>
#include <string>
using namespace std;

string a;

int maxcnt = -2e9;
int mincnt = 2e9;

void init() {
    cin >> a;
}

void func(string x, int cnt) {

    int nowcnt = cnt;

    for (int i = 0; i < x.size(); i++) {
        if ((x[i] - '0') % 2 == 1) nowcnt++;
    }

    if (x.size() == 1) {
        if (nowcnt > maxcnt) maxcnt = nowcnt;
        if (nowcnt < mincnt) mincnt = nowcnt;
    }

    else if (x.size() == 2) {
        int a = x[0] - '0';
        int b = x[1] - '0';
        string str = std::to_string(a + b);
        func(str, nowcnt);
    }

    else if (x.size() > 2) {

        for (int i = 1; i < x.size(); i++) {
            for (int j = i+1; j < x.size(); j++) {

                int first = i;
                int second = j;

                string new1 = x.substr(0, first);
                string new2 = x.substr(first, (second - first));
                string new3 = x.substr(second, (x.size() - second));

                int a = std::stoi(new1);
                int b = std::stoi(new2);
                int c = std::stoi(new3);

                int num = a + b + c;
                string str = std::to_string(num);
                func(str, nowcnt);
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    func(a, 0);
    cout << mincnt << " " << maxcnt;
    
    return 0;


}