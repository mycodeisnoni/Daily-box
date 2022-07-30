#include<iostream>
#include <string>
using namespace std;


void moon(int a, int *x,int*y,int*z) {
	*x = a - 4;
	*y = a+ 3;
	*z = a*2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int a;
	cin >> a;
	int x, y, z;
	moon(a,&x,&y,&z);

	cout << x << " " << y << " " << z;

	return 0;
}
