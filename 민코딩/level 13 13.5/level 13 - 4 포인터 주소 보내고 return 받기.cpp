#include<iostream>
#include <cstring>
using namespace std;


void ABC(int a,int b,int *sum, int *gop) {
	*sum = a + b;
	*gop = a * b;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int a, b;
	cin >> a >> b;
	int sum, gop;


	ABC(a,b,&sum, &gop);
	cout << sum << " " << gop;

	return 0;
}
