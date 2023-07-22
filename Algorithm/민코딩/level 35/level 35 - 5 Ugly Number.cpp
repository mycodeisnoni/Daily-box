#include <iostream>
#include <algorithm>
#include<cstring>
#include<vector>
#include <queue>
using namespace std;

struct Node {
    int now;
    int prev;
};

bool operator<(Node a, Node b)
{
    if (a.now < b.now) return false;
    if (a.now > b.now) return true;
    return false;

}

int map[10001];

int main()
{

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    pq.push(1);
    int order = 1;
    long long prev = -1;
    while (order <= 1500) {
        long long now = pq.top();
        pq.pop();
        if (prev == now) continue;  // now에서 process 는 한번만 진행되어야한다

        // process 
        map[order] = now;
        pq.push(now * 2);
        pq.push(now * 3);
        pq.push(now * 5);
        prev = now;
        order++;
    }

    int Q;
    cin >> Q;
    int idx;
    for (int i = 0; i < Q; i++) {
        cin >> idx;
        cout << map[idx] << " ";
    }

    return 0;

}