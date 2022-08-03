#include <iostream>
#include <algorithm>
#include<queue>
#include<stack>
using namespace std;



bool cmp(int a, int b) {
    if (a < b) return true;
    if (a > b)return false;
    //if (a.alp < b.alp) return true;
    //if (a.alp > b.alp) return false;
    return false;
}

stack<int> s;
int arr[10000];


int main()
{
    int n;
    cin >> n;
    int x;
    int add, odd;

    cin >> add >> odd;
    s.push(add);
    s.push(odd);
   
    int de = -1;
    for (int i = 2; i < n; i++) {
        cin >> x;
        
        s.push(x);
        int top = s.top();

        if (top == add && add == odd)
        {
            s.pop();
            s.pop();
            s.pop();
            add = -1;
            odd = -1;
        }
        if (i % 2 == 0) add = x;
        else odd = x;
    }

    int size = s.size();
    for (int i = size - 1; i >= 0; i--) {
        arr[i] = s.top();
        s.pop();
    }

    sort(arr, arr + size, cmp);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
        
  

    return 0;
}