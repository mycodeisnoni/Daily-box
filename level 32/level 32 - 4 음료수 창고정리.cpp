#include <iostream>
#include <algorithm>
#include<cstring>
#include<vector>
using namespace std;

struct Node {
    int line;
    int num;
};

vector <Node> v[v.line];

bool cmp(int a, int b) {
    if (a < b) return true;
    if (a > b)return false;
    //if (a.alp < b.alp) return true;
    //if (a.alp > b.alp) return false;
    return false;
}



int main()
{
    string x[100];

    for (int i = 0; i < 5; i++) {
            v[i].push_back(x);
        }

    int a, b;
    cin >> a >> b;

    sort(v[a].begin(), v[a].end, cmp);
    sort(v[b].begin(), v[b].end, cmp);

        
    for (int i = 0; i < 5; i++) {
        cout << v[i][0] << " ";
    }
  

    return 0;
}