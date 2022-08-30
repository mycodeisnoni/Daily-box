#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Node {

};

unordered_map <string, int[]> a;
unordered_map <int, string[]> b;

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

		}
		else if (x == "print") {
			int num;
			cin >> num;


		}
		else if (x == "whois") {
			string y;
			cin >> y;

		}

	}
	

	return 0;
}