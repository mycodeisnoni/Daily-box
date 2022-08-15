#include <iostream>
#include <cstring>
using namespace std;

struct FileDown {
	int dn1;
	int dn2;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int a;
	int b;
	cin >> a >> b;

	FileDown{ a, b };
	int cnt = 0;
	while (a < 100 || b < 100) {

		if (a < 100) a++; 
		if (b < 100) b++;
		
		cnt++;
	}

	cout << cnt;
	return 0;
}