#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char arr[6] = { "#","_","#","_","#","#" };

	for (int i = 0; i < 6; i++) {
		if (arr[i] == "#") {
			cout << "¼¥";
		}
		else(arr[i] == "_") {
			cout << "¹«";
		}
	}

	return 0;
}