#include <iostream>
using namespace std;

int a, b;

void BBQ(int a,int b) {
	cout << "��:" << a + b << endl;
	cout << "��:" << a - b << endl;
	cout << "��:" << a * b << endl;
	cout << "��:" << a / b << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> a >> b;

	BBQ(a,b);
	return 0;
}