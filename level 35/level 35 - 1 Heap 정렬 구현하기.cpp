#include <iostream>
#include <algorithm>
#include<cstring>
#include<vector>
#include <queue>
using namespace std;

//struct Node {
//    char a;
//    char b;
//};

//bool operator<(int a, int b) 
//{
//    if (t1.a < t2.a) return false;
//    if (t1.a > t2.a) return true;
//    if (t1.b);
//}

string v[51];

int main()
{

    string x;
    cin >> x;
    priority_queue<char> pq;
    
    for (int i = 0; i < x.size(); i++) {
        pq.push(x[i]);
    }

    for (int i = 0; i < x.size(); i++) {
        char a = pq.top();
        pq.pop();
        cout << a;
    }

    return 0;


}