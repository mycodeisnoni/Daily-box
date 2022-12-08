#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

string x;
queue<int>q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();


	for (int tc = 1; tc <= 10; tc++) {
		int sizenow;
		cin >> sizenow;
		cin >> x;

		while (1)
		{
			int de = -1;
			int flag = 0;
			for (int i = 0;i< x.size()-1; i++) {
				if (x[i ] == x[i + 1]) {
					x.erase(i, 2);
					flag = 1;
					break;
				}
			}
			if (flag==0) {
				cout << "#" << tc << " " << x << endl;
				break;
			}
		}
	}

	return 0;
}



