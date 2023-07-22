#include <iostream>
using namespace std;

int arr1[5], arr2[5];

void PrintAll(){
    cout << arr1[5] << endl;
    cout << arr2[5];
}

int main(){
    int a,b;
    cin >> a >> b;

    for(int i=0;i<5;i++){
        arr1[i] = a;
        arr2[i] = b;
    }

    PrintAll();
}