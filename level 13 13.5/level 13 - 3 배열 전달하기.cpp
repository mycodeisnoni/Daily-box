#include<iostream>
#include <cstring>
using namespace std;


int stringLen(char x[100]) {
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		if ( x[i] != '\0') {
			cnt++;
		}
		else break;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char x[100];
	cin >> x;
	cout << stringLen(x)<< "±ÛÀÚ";

	return 0;
}
