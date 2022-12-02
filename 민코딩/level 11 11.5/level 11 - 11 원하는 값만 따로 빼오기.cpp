#include<iostream>
#include <string>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	string x[11];
	cin >> x;


	char a, b, c;
	cin >> a >> b >> c;


	int cnta = 0;
	int cntb = 0;
	int cntc = 0;

	for (int i = 0; i < stlen(x); i++) {
		if (x[i] == a)  cnta++; 
		if (x[i] == b)  cntb++;
		if (x[i] == c)  cntc++;
	}
	
	cout << a << "=" << cnta << '\n';
	cout << b << "=" << cntb << '\n';
	cout << c << "=" << cntc << '\n';

	return 0;
}
