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

int map[1001][1001] = { 0, };

int main()
{

    int n;
    cin >> n;


    priority_queue<Node> pq;
              


}