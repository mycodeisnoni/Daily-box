#include <iostream>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	string x = { 0, };
	string y = { 0, };


	cin >> x >> y;

	cout << x.size() << " " << y.size();
	

	return 0;
}