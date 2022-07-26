#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

    int arr[8] = { 4,3,6,1,3,1,5,3 };
    int ch[10] = { 0 };


    int a;
    cin >> a;

    for (int i = 0; i < 8; i++) {
        if (arr[i] == a) {
            ch[a]++;
        }
    }

    cout << "숫자" << a << "개수는" << ch[a] << "개";




	return 0;
}