#include<iostream>
#include <string>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();


	char sen[9] = { 'D','A','T','A','P','O','W','E','R' };

	int a, b;
	cin >> a >> b;

	char ten[9] = { 0, };
	int idx = 0;

	for (int i = a; i <= b ; i++) {
		ten[idx] = sen[i];
		idx++;
	}

	for (int i = 0; i <= b - a; i++) {
		cout << ten[i];
	}
	return 0;
}
