#include <iostream>
using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	char arr[6] = { '$','@','D','A','9','#' };
	int i;

	for (i = 0; i < 6; i++) {
		cout << arr[i] << ':' << int(arr[i]) << "\n";
	}


	return 0;
}