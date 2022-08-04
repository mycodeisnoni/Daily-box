#include <iostream>
#include <algorithm>
#include<cstring>
#include<vector>
#include <queue>
using namespace std;

struct Node {
    int from_idx;
    int to_idx;
    int cost;
};

bool operator<(Node a, Node b) 
{
    if (a.cost < b.cost) return true;
    if (a.cost > b.cost) return false;
    return false;
    
}

int arr[6][6] = { 0, };
char idx[6] = { 'A','B','C','D','E'};

int main()
{

    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    priority_queue<Node> pq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != 0) pq.push({i,j,arr[i][j]});
        }
    }
    
    for (int i = 0; i < 3; i++) {
        Node now = pq.top();
        pq.pop();
        cout << idx[now.from_idx] << "-" << idx[now.to_idx] << " " << now.cost << '\n';
    }



}