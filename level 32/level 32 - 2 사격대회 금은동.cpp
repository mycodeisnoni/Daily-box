#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


struct NODE {
    string name;
    int  score;
    int index;
};

bool cmp(NODE n1, NODE n2) {
    if (n1.score > n2.score) return true;
    if (n1.score < n2.score) return false;

    if (n1.index > n2.index) return true;
    if (n1.index < n2.index) return false;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n; cin >> n;

    NODE arr[101];

    for (int i = 0; i < n; i++) {
        cin >> arr[i].name >> arr[i].score;
        arr[i].index = i;
        //sort(arr, arr+i,cmp)�� �ϸ� i���� �������� �����ϱ� ������
        //arr+i+1�� ������ �־�� �Ѵ�!!
        sort(arr, arr + i + 1, cmp);
        ;        for (int j = 0; j < 3; j++) {
            cout << arr[j].name << " ";
        }cout << endl;
    }


    return 0;
}
