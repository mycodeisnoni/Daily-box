#include <iostream>
#include <algorithm>
using namespace std;

struct Set {
    int num;
    char alp;
};

Set set[101] = { 0, };

bool cmp(Set a, Set b) {
    if (a.num < b.num) return true;
    if (a.num > b.num)return false;
    if (a.alp < b.alp) return true;
    if (a.alp > b.alp) return false;
    return false;
}

int main()
{
    int n;
    cin >> n;

 
    for (int i = 0; i < n; i++) {
        cin >> set[i].num >> set[i].alp;
    }
    sort(set, set + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << set[i].num << " " << set[i].alp << endl;
    }
    return 0;
}