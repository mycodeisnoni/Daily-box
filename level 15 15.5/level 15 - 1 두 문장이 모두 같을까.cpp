#include<iostream>
#include <cstring>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();


	char x[7], y[7];
	cin >> x >> y;
	int cnt = 0;
	int i;
	if (strlen(x) == strlen(y)) {
		for (i = 0; i < strlen(x); i++) {
			if (x[i] != y[i]) {
				cout << "다름";
				break;
			}
		}
		if (i == strlen(x) - 1) cout << "같음";
		
	}
	else {
		cout << "다름";
	}


	return 0;
}
