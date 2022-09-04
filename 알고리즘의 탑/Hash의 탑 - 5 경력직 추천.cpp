#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map <string, vector<int>> a;
unordered_map <int, vector<string> > b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string x;
		cin >> x;
		if (x == "recommand") {
			int num;
			string y;
			cin >> num >> y;
			b[num].push_back(y);
			a[y].push_back(num);
			sort(a[y].begin(), a[y].end());
			cout << b[num].size() <<endl;
		}
		else if (x == "print") {
			int num;
			cin >> num;
			if (b[num].size()) {
				for (int j = 0; j < b[num].size(); j++) {
					cout << b[num][j] << " ";
				}
				cout << '\n';
			}
			else cout << "none\n";
		}
		else if (x == "whois") {
			string y;
			cin >> y;
			if (a[y].size()) {
				for (int j = 0; j < a[y].size(); j++) {
					cout << a[y][j] << " ";
				}
				cout << '\n';
			}
			else cout << "none\n";
		}
	}
	return 0;
}